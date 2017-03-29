Test Adios Staging
==================

This is a program to demonstrate Adios write/read with files and staging methods. 

The main executable (```adios_icee```) can work in two modes:
* server: write data (by default)
* client: read data (use -c option)

We can use staging methods in between: DATASPACES, DIMES, FLEXPATH, and ICEE methods

Main command line parameters are as follows:

```
$ adios_icee -h
Usage: adios_icee [OPTIONS]...

  -h, --help                Print help and exit
  -V, --version             Print version and exit
  -c, --client              Client mode  (default=off)
  -w, --writemethod=STRING  ADIOS write method  (default=`POSIX1')
  -r, --readmethod=STRING   ADIOS read method  (default=`BP')
  -n, --len=LONGLONG        array length  (default=`1')
      --chunk=LONGLONG      chunk length  (default=`131072')
      --timeout=FLOAT       Timeout  (default=`3600')
      --sleep=INT           interval time  (default=`5')
      --nstep=INT           number of time steps  (default=`10')
      --wparam=STRING       write method params  (default=`')
      --rparam=STRING       read method params  (default=`')
      --prefix=STRING       prefix  (default=`')
      --append              append  (default=off)
      --filename=STRING     filename
      --nostream            no stream  (default=off)
      --transform=STRING    transform  (default=`')
```

Building
--------

For details of building Adios, please refer to the Adios manual. 

To run with stagign methods, Adios needs to be configured and built with the following staging options:
```
--with-flexpath=DIR 	Location of FlexPath
--with-dataspaces=DIR   Build the DATASPACES transport method. Point to the
                        DATASPACES installation.
```

After Adios build and install, set PATH to include Adios' bin
directory for ```adios_config```.

Then, this test program can be built by:

```
$ make
```

Running
-------

### 0. With files

Let's make sure ```adios_icee``` can write and read through files:
```
$ mpirun -n 4 adios_icee -w MPI
```

Check output
```
$ bpls icee.bp
File info:
  of groups:     1
  of variables:  8
  of attributes: 0
  of meshes:     0
  time steps:    0 - 0
  file size:     4 MB
  bp version:    3
  endianness:    Little Endian
  statistics:    Min / Max / Avg / Std_dev

  long long  NX         scalar = 1
  long long  NY         scalar = 131072
  long long  G          scalar = 4
  long long  O          scalar = 0
  double     var00      {4, 131072} = null  / null  / null  / null 
  integer    size       scalar = 4
  integer    rank       scalar = 0
  double     timestamp  {4} = null  / null  / null  / null 

```

Then, run reader:
```
$ mpirun -n 4 adios_icee -r BP
```


### 1. DataSpaces and DIMES

For using DATASPACES and DIMES methods, we need to do
-. Make sure ```dataspaces_server``` is in PATH
-. Prepare dataspaces.conf
-. Run dataspaces server
-. Export information on ```conf``` file
-. Run writer and reader

```run-dataspaces.py``` is provided as a wrapper.

To test with DATASPACES (or DIMES), run:
```
./run-dataspaces.py -s 1 : \
                    -n 4 adios_icee -w DATASPACES : \
                    -n 4 adios_icee -c -r DATASPACES
```

Notes on Titan:

We need to provide an extra option ```--mpirun=aprun
```. For more details on options, use ```run-dataspaces.py -h```

Also, we need at least 3 nodes to run this example.

### 2. FlexPath

```
./run-dataspaces.py -s 1 --noserver : \
                    -n 4 adios_icee -w FLEXPATH : \
                    -n 4 adios_icee -c -r FLEXPATH
```

Checking
--------

You can see the output from the reader something like:
```
+++         timestep   seq  rank time(sec)   (MiB/s)        dT   (MiB/s) (    Check                    )
+++         -------- ----- ----- --------- --------- --------- ---------  --------- --------- ---------
+++ (8567) 1488408631.685     0     0 1.339e-02    74.700 0.000e+00       inf (    var00 1.311e+05 1.000e+00)
+++ (8568) 1488408631.684     0     1 6.300e-03   158.731 0.000e+00       inf (    var00 2.621e+05 2.000e+00)
+++ (8570) 1488408631.684     0     3 8.620e-03   116.012 0.000e+00       inf (    var00 5.243e+05 4.000e+00)
+++ (8569) 1488408631.684     0     2 1.123e-02    89.015 0.000e+00       inf (    var00 3.932e+05 3.000e+00)
                                                                                                   ^^^^^^^^^^
```

In this specific example, the last values (marked as ```^^^^^^```)
should be multiple of 1 (more precisely, it should be rank + timesteps + 1)

### 2. With ICEE

Please refer to ```README-icee.txt```
