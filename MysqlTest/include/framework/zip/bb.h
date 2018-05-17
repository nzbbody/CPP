/* inffast.h -- header to use inffast.c
 * Copyright (C) 1995-2003 Mark Adler
 * For conditions of distribution and use, see copyright notice in zlib.h
 */

/* WARNING: this file should *not* be used by applications. It is
   part of the implementation of the compression library and is
   subject to change. Applications should only use zlib.h.
 */

#ifndef __BB_H__
#define __BB_H__

#include <errno.h>
#include <trace/trace_i.h>
#include <fcntl.h>

#ifndef ATTRIBUTE_UNUSED
#define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif /* ATTRIBUTE_UNUSED */

#define bb_default_error_retval E_ERR_FAILED
#ifndef MAX
#define	MAX(a,b) (((a)>(b))?(a):(b))
#endif

static void bb_error_d(const char *s, ...) __attribute__ ((noreturn, format (printf, 1, 2)));
static const char msg_enomem[] = "memory not existed";
static const char bb_applet_name[] = "platform";
static const char bb_msg_memory_exhausted[] = "memory exhausted";
static const char bb_msg_read_error[] = "Read Error";

static void bb_error_d(const char *s, ...);
void bb_error_msg_and_die(const char *s, ...);
void bb_perror_msg_and_die(const char *s, ...);
void bb_error_msg(const char *s, ...);
void bb_perror_msg(const char *s, ...);

void *xmalloc(size_t size);
void *xcalloc(size_t nmemb, size_t size);

int bb_xopen(const char *pathname, int flags);
void bb_xread_all(int fd, void *buf, size_t count);
unsigned char bb_xread_char(int fd);
ssize_t bb_xread(int fd, void *buf, size_t count);
ssize_t bb_full_write(int fd, const void *buf, size_t len);


#endif
