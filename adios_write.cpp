/* 
 * ADIOS is freely available under the terms of the BSD license described
 * in the COPYING file in the top level directory of this source distribution.
 *
 * Copyright (c) 2008 - 2009.  UT-BATTELLE, LLC. All rights reserved.
 */

/* ADIOS ICEE Example
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <libgen.h>
#include "mpi.h"
#include "adios.h"
#include "adios_read.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif

#ifndef VERBOSE
#define VERBOSE 3
#endif

using namespace std;

void usage(const char *argv0)
{
    fprintf(stderr, "usage: %s\n", argv0);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "-w [ MPI | ICEE ]\n");
    fprintf(stderr, "-r [ BP | ICEE ]\n");
    exit (1);
}

int main (int argc, char ** argv) 
{
    int c;
    opterr = 0;

    string cm_host = "localhost";
    int    cm_port = 59999;
    string cm_remote_host = "localhost";
    int    cm_remote_port = 59997;
    int    is_multi_writers = 0;
    string remote_list = "";
    int    max_client = 1;
    char   initstring [256];
    int    verbose_level = VERBOSE;

    string adios_write_method = "MPI";
    enum ADIOS_READ_METHOD adios_read_method = ADIOS_READ_METHOD_BP;

    while ((c = getopt (argc, argv, "h:p:s:t:m:w:r:v:")) != -1)
    {
        switch (c)
        {
        case 'h':
            cm_host = string(optarg);
            break;
        case 'p':
            cm_port = atoi(optarg);
            break;
        case 's':
            cm_remote_host = string(optarg);
            break;
        case 't':
            cm_remote_port = atoi(optarg);
            break;
        case 'm':
            max_client = atoi(optarg);
            break;
        case 'w':
            adios_write_method = string(optarg);
            break;
        case 'r':
            if (string(optarg) == "BP") {
                adios_read_method = ADIOS_READ_METHOD_BP;
            } else if (string(optarg) == "ICEE") {
                adios_read_method = ADIOS_READ_METHOD_ICEE;
            } else {
                fprintf(stderr, "No read method: %s\n", optarg);
            }
            break;
        case 'v':
            verbose_level = atoi(optarg);
            break;
        default:
            usage(basename(argv[0]));
            break;
        }
    }

	char        filename [256];
	int         rank, size, i;
	int         NX = 10, G, O; 
	double      t[NX];
	MPI_Comm    comm = MPI_COMM_WORLD;

	/* ADIOS variables declarations for matching gwrite_temperature.ch */
	int         it;
	uint64_t    adios_groupsize, adios_totalsize;

	MPI_Init (&argc, &argv);
	MPI_Comm_rank (comm, &rank);
	MPI_Comm_size (comm, &size);

    G = NX * size;

	strcpy (filename, "adios_globaltime.bp");

    sprintf(initstring, "verbose=%d;cm_host=%s;cm_port=%d;max_client=%d;", 
            verbose_level, cm_host.c_str(), cm_port+rank, max_client);

	adios_init_noxml (comm);
    adios_allocate_buffer (ADIOS_BUFFER_ALLOC_NOW, 10);

    int64_t       m_adios_group;
    int64_t       m_adios_file;

    adios_declare_group (&m_adios_group, "restart", "", adios_flag_yes);
    adios_select_method (m_adios_group, adios_write_method.c_str(), initstring, "");

    adios_define_var (m_adios_group, "NX"
                      ,"", adios_integer
                      ,0, 0, 0);
  
    adios_define_var (m_adios_group, "G"
                      ,"", adios_integer
                      ,0, 0, 0);

    adios_define_var (m_adios_group, "O"
                      ,"", adios_integer
                      ,0, 0, 0);
    
    adios_define_var (m_adios_group, "temperature"
                      ,"", adios_double
                      ,"NX", "G", "O");

    for (it =0; it < 5; it++) 
    {

        for (i = 0; i < NX; i++)
            t[i] = rank + it + 1.0;

        adios_open (&m_adios_file, "restart", filename, "a", comm);
        adios_groupsize = 4 + 4 + 4 + NX * 8;
        adios_group_size (m_adios_file, adios_groupsize, &adios_totalsize);

        adios_write(m_adios_file, "NX", (void *) &NX);
        adios_write(m_adios_file, "G", (void *) &G);
        O = rank * NX;
        adios_write(m_adios_file, "O", (void *) &O);
        adios_write(m_adios_file, "temperature", t);

        adios_close (m_adios_file);
        MPI_Barrier (comm);
    }

	adios_finalize (rank);

	MPI_Finalize ();
	return 0;
}
