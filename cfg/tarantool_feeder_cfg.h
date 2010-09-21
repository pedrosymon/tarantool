#ifndef tarantool_cfg_CFG_H
#define tarantool_cfg_CFG_H

#include <stdio.h>
#include <sys/types.h>

/*
 * Autogenerated file, do not edit it!
 */

typedef struct tarantool_cfg {

	/* username to switch to */
	char*	username;

	/* save core on abort/assert */
	int32_t	coredump;

	/*
	 * admin port
	 * used for admin's connections
	 */
	int32_t	admin_port;

	/* Log verbosity, possible values: ERROR=1, CRIT=2, WARN=3, INFO=4(default), DEBUG=5 */
	int32_t	log_level;

	/* Size of slab arena in GiBs */
	double	slab_alloc_arena;

	/* Size of minimal allocation unit */
	int32_t	slab_alloc_minimal;

	/* Growth factor, each subsecuent unit size is factor * prev unit size */
	double	slab_alloc_factor;

	/* working directory (daemon will chdir(2) to it) */
	char*	work_dir;

	/* name of pid file */
	char*	pid_file;

	/*
	 * logger command will be executed via /bin/sh -c {}
	 * example: 'exec cronolog /var/log/taranul/%Y-%m/%Y-%m-%d/tarantool.log'
	 * example: 'exec extra/logger.pl /var/log/taranul/tarantool.log'
	 * when logger is not configured all logging going to STDERR
	 */
	char*	logger;

	/* make logging nonblocking, this potentially can loss some logging data */
	int32_t	logger_nonblock;

	/* delay between loop iteraions */
	double	io_collect_interval;

	/* do not write snapshot faster then snap_io_rate_limit MBytes/sec */
	double	snap_io_rate_limit;

	/* size of listen backlog */
	int32_t	backlog;

	/* network io readahead */
	int32_t	readahead;

	/*
	 * feed WAL to remote replicas
	 * feeder accepts it's clients on wal_feeder_bind_ipaddr:wal_feeder_bind_port
	 */
	char*	wal_feeder_bind_ipaddr;
	int32_t	wal_feeder_bind_port;

	/* Directory with WAL files to serve */
	char*	wal_feeder_dir;

	/* custom proc title is appended after normal */
	char*	custom_proc_title;
} tarantool_cfg;

int fill_default_tarantool_cfg(tarantool_cfg *c);
void parse_cfg_file_tarantool_cfg(tarantool_cfg *c, FILE *fh, int check_rdonly, int *n_accepted, int *n_skipped);

void parse_cfg_buffer_tarantool_cfg(tarantool_cfg *c, char *buffer, int check_rdonly, int *n_accepted, int *n_skipped);

typedef struct tarantool_cfg_iterator_t tarantool_cfg_iterator_t;
tarantool_cfg_iterator_t* tarantool_cfg_iterator_init();
char* tarantool_cfg_iterator_next(tarantool_cfg_iterator_t* i, tarantool_cfg *c, char **v);
#endif
