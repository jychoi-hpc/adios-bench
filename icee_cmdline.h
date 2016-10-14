/** @file icee_cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.6
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef ICEE_CMDLINE_H
#define ICEE_CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef ICEE_CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define ICEE_CMDLINE_PARSER_PACKAGE "icee"
#endif

#ifndef ICEE_CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define ICEE_CMDLINE_PARSER_PACKAGE_NAME "icee"
#endif

#ifndef ICEE_CMDLINE_PARSER_VERSION
/** @brief the program version */
#define ICEE_CMDLINE_PARSER_VERSION "0.1"
#endif

/** @brief Where the command line options are stored */
struct icee_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  int client_flag;	/**< @brief Client mode (default=off).  */
  const char *client_help; /**< @brief Client mode help description.  */
  char * writemethod_arg;	/**< @brief ADIOS write method (default='POSIX1').  */
  char * writemethod_orig;	/**< @brief ADIOS write method original value given at command line.  */
  const char *writemethod_help; /**< @brief ADIOS write method help description.  */
  char * readmethod_arg;	/**< @brief ADIOS read method (default='BP').  */
  char * readmethod_orig;	/**< @brief ADIOS read method original value given at command line.  */
  const char *readmethod_help; /**< @brief ADIOS read method help description.  */
  #if defined(HAVE_LONG_LONG) || defined(HAVE_LONG_LONG_INT)
  long long int len_arg;	/**< @brief array length (default=1).  */
  #else
  long len_arg;	/**< @brief array length (default=1).  */
  #endif
  char * len_orig;	/**< @brief array length original value given at command line.  */
  const char *len_help; /**< @brief array length help description.  */
  #if defined(HAVE_LONG_LONG) || defined(HAVE_LONG_LONG_INT)
  long long int chunk_arg;	/**< @brief chunk length (default=131072).  */
  #else
  long chunk_arg;	/**< @brief chunk length (default=131072).  */
  #endif
  char * chunk_orig;	/**< @brief chunk length original value given at command line.  */
  const char *chunk_help; /**< @brief chunk length help description.  */
  float timeout_arg;	/**< @brief Timeout (default='3600').  */
  char * timeout_orig;	/**< @brief Timeout original value given at command line.  */
  const char *timeout_help; /**< @brief Timeout help description.  */
  int sleep_arg;	/**< @brief interval time (default='5').  */
  char * sleep_orig;	/**< @brief interval time original value given at command line.  */
  const char *sleep_help; /**< @brief interval time help description.  */
  int nstep_arg;	/**< @brief number of time steps (default='10').  */
  char * nstep_orig;	/**< @brief number of time steps original value given at command line.  */
  const char *nstep_help; /**< @brief number of time steps help description.  */
  char * wparam_arg;	/**< @brief write method params (default='').  */
  char * wparam_orig;	/**< @brief write method params original value given at command line.  */
  const char *wparam_help; /**< @brief write method params help description.  */
  char * rparam_arg;	/**< @brief read method params (default='').  */
  char * rparam_orig;	/**< @brief read method params original value given at command line.  */
  const char *rparam_help; /**< @brief read method params help description.  */
  char * prefix_arg;	/**< @brief prefix (default='').  */
  char * prefix_orig;	/**< @brief prefix original value given at command line.  */
  const char *prefix_help; /**< @brief prefix help description.  */
  int append_flag;	/**< @brief append (default=off).  */
  const char *append_help; /**< @brief append help description.  */
  char * filename_arg;	/**< @brief filename.  */
  char * filename_orig;	/**< @brief filename original value given at command line.  */
  const char *filename_help; /**< @brief filename help description.  */
  int mpicolor_arg;	/**< @brief MPI comm color (default='0').  */
  char * mpicolor_orig;	/**< @brief MPI comm color original value given at command line.  */
  const char *mpicolor_help; /**< @brief MPI comm color help description.  */
  char ** filelock_arg;	/**< @brief filelock name.  */
  char ** filelock_orig;	/**< @brief filelock name original value given at command line.  */
  unsigned int filelock_min; /**< @brief filelock name's minimum occurreces */
  unsigned int filelock_max; /**< @brief filelock name's maximum occurreces */
  const char *filelock_help; /**< @brief filelock name help description.  */
  int evilread_flag;	/**< @brief enable evil read (default=off).  */
  const char *evilread_help; /**< @brief enable evil read help description.  */
  int commself_flag;	/**< @brief commself (default=off).  */
  const char *commself_help; /**< @brief commself help description.  */
  int all_flag;	/**< @brief Runs all sizes, up to `length' (default=off).  */
  const char *all_help; /**< @brief Runs all sizes, up to `length' help description.  */
  #if defined(HAVE_LONG_LONG) || defined(HAVE_LONG_LONG_INT)
  long long int minlen_arg;	/**< @brief minlen (default=1).  */
  #else
  long minlen_arg;	/**< @brief minlen (default=1).  */
  #endif
  char * minlen_orig;	/**< @brief minlen original value given at command line.  */
  const char *minlen_help; /**< @brief minlen help description.  */
  int probe_flag;	/**< @brief use probe (default=off).  */
  const char *probe_help; /**< @brief use probe help description.  */
  char * host_arg;	/**< @brief local hostname (default='localhost').  */
  char * host_orig;	/**< @brief local hostname original value given at command line.  */
  const char *host_help; /**< @brief local hostname help description.  */
  int port_arg;	/**< @brief local port (default='59900').  */
  char * port_orig;	/**< @brief local port original value given at command line.  */
  const char *port_help; /**< @brief local port help description.  */
  char * remotehost_arg;	/**< @brief remote hostname (default='localhost').  */
  char * remotehost_orig;	/**< @brief remote hostname original value given at command line.  */
  const char *remotehost_help; /**< @brief remote hostname help description.  */
  int remoteport_arg;	/**< @brief remote port (default='59900').  */
  char * remoteport_orig;	/**< @brief remote port original value given at command line.  */
  const char *remoteport_help; /**< @brief remote port help description.  */
  char * method_arg;	/**< @brief EVPath method (default='TCP').  */
  char * method_orig;	/**< @brief EVPath method original value given at command line.  */
  const char *method_help; /**< @brief EVPath method help description.  */
  int verbose_arg;	/**< @brief verbosity level (default='3').  */
  char * verbose_orig;	/**< @brief verbosity level original value given at command line.  */
  const char *verbose_help; /**< @brief verbosity level help description.  */
  char * contact_arg;	/**< @brief EVPath contact string.  */
  char * contact_orig;	/**< @brief EVPath contact string original value given at command line.  */
  const char *contact_help; /**< @brief EVPath contact string help description.  */
  int passive_flag;	/**< @brief enable passive mode (default=off).  */
  const char *passive_help; /**< @brief enable passive mode help description.  */
  int nclient_arg;	/**< @brief maximum number of clients.  */
  char * nclient_orig;	/**< @brief maximum number of clients original value given at command line.  */
  const char *nclient_help; /**< @brief maximum number of clients help description.  */
  int isnative_flag;	/**< @brief use native contact (default=off).  */
  const char *isnative_help; /**< @brief use native contact help description.  */
  char * remotelist_arg;	/**< @brief remote list.  */
  char * remotelist_orig;	/**< @brief remote list original value given at command line.  */
  const char *remotelist_help; /**< @brief remote list help description.  */
  char * attrlist_arg;	/**< @brief attr list.  */
  char * attrlist_orig;	/**< @brief attr list original value given at command line.  */
  const char *attrlist_help; /**< @brief attr list help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int client_given ;	/**< @brief Whether client was given.  */
  unsigned int writemethod_given ;	/**< @brief Whether writemethod was given.  */
  unsigned int readmethod_given ;	/**< @brief Whether readmethod was given.  */
  unsigned int len_given ;	/**< @brief Whether len was given.  */
  unsigned int chunk_given ;	/**< @brief Whether chunk was given.  */
  unsigned int timeout_given ;	/**< @brief Whether timeout was given.  */
  unsigned int sleep_given ;	/**< @brief Whether sleep was given.  */
  unsigned int nstep_given ;	/**< @brief Whether nstep was given.  */
  unsigned int wparam_given ;	/**< @brief Whether wparam was given.  */
  unsigned int rparam_given ;	/**< @brief Whether rparam was given.  */
  unsigned int prefix_given ;	/**< @brief Whether prefix was given.  */
  unsigned int append_given ;	/**< @brief Whether append was given.  */
  unsigned int filename_given ;	/**< @brief Whether filename was given.  */
  unsigned int mpicolor_given ;	/**< @brief Whether mpicolor was given.  */
  unsigned int filelock_given ;	/**< @brief Whether filelock was given.  */
  unsigned int evilread_given ;	/**< @brief Whether evilread was given.  */
  unsigned int commself_given ;	/**< @brief Whether commself was given.  */
  unsigned int all_given ;	/**< @brief Whether all was given.  */
  unsigned int minlen_given ;	/**< @brief Whether minlen was given.  */
  unsigned int probe_given ;	/**< @brief Whether probe was given.  */
  unsigned int host_given ;	/**< @brief Whether host was given.  */
  unsigned int port_given ;	/**< @brief Whether port was given.  */
  unsigned int remotehost_given ;	/**< @brief Whether remotehost was given.  */
  unsigned int remoteport_given ;	/**< @brief Whether remoteport was given.  */
  unsigned int method_given ;	/**< @brief Whether method was given.  */
  unsigned int verbose_given ;	/**< @brief Whether verbose was given.  */
  unsigned int contact_given ;	/**< @brief Whether contact was given.  */
  unsigned int passive_given ;	/**< @brief Whether passive was given.  */
  unsigned int nclient_given ;	/**< @brief Whether nclient was given.  */
  unsigned int isnative_given ;	/**< @brief Whether isnative was given.  */
  unsigned int remotelist_given ;	/**< @brief Whether remotelist was given.  */
  unsigned int attrlist_given ;	/**< @brief Whether attrlist was given.  */

} ;

/** @brief The additional parameters to pass to parser functions */
struct icee_cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure icee_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure icee_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *icee_args_info_purpose;
/** @brief the usage string of the program */
extern const char *icee_args_info_usage;
/** @brief the description string of the program */
extern const char *icee_args_info_description;
/** @brief all the lines making the help output */
extern const char *icee_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int icee_cmdline_parser (int argc, char **argv,
  struct icee_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use icee_cmdline_parser_ext() instead
 */
int icee_cmdline_parser2 (int argc, char **argv,
  struct icee_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int icee_cmdline_parser_ext (int argc, char **argv,
  struct icee_args_info *args_info,
  struct icee_cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int icee_cmdline_parser_dump(FILE *outfile,
  struct icee_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int icee_cmdline_parser_file_save(const char *filename,
  struct icee_args_info *args_info);

/**
 * Print the help
 */
void icee_cmdline_parser_print_help(void);
/**
 * Print the version
 */
void icee_cmdline_parser_print_version(void);

/**
 * Initializes all the fields a icee_cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void icee_cmdline_parser_params_init(struct icee_cmdline_parser_params *params);

/**
 * Allocates dynamically a icee_cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized icee_cmdline_parser_params structure
 */
struct icee_cmdline_parser_params *icee_cmdline_parser_params_create(void);

/**
 * Initializes the passed icee_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void icee_cmdline_parser_init (struct icee_args_info *args_info);
/**
 * Deallocates the string fields of the icee_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void icee_cmdline_parser_free (struct icee_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int icee_cmdline_parser_required (struct icee_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ICEE_CMDLINE_H */
