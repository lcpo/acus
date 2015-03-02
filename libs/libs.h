#ifndef __DESTRUCTOR
#include "constructor.h"
#endif

#ifdef __i386__
#include "unistd_x86.h"
#endif

#ifdef __x86_64__
#include "unistd_x64.h"
#endif
#include "type.h"
#include "arg.h"
#include "call.h"
#include "mman.h"

typedef struct sys_t{
#ifndef __NO_LIBS_CALL	
void* (*call)(void* ns,...);
#endif	
///------------------------------------------------------------	
#ifndef __NO_LIBS_OPEN	
int (*open)(char * filename, int flags, int mode);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_CLOSE
int (*close)(int fd);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_STAT
int (*stat)(char * filename, struct stat_f *buf);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_FSTAT
int (*fstat)(int fd, stat_f *buf);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_LSTAT
int (*lstat)(char * filename, struct stat_f *buf);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_BRK
int (*brk)(void* brkv);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_EXIT
int (*exit)(int error_code);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_GETPID
int (*getpid)(void);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_FORK
int (*fork)(void);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_VFORK
int (*vfork)(void);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_READ
int (*read)(int fd, char * buf, int count);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_LSEEK
int (*lseek)(int fd, int offset, int against);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_KILL
int (*kill)(int pid, int sig);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_DUP2
int (*dup2)(int oldfd, uni newfd);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_DUP
int (*dup)(int oldfd);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_ALARM
int (*alarm)(int seconds);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_PIPE
int (*pipe)(int* filedes);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_TIME
long (*time)(long tloc);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_UNLINK
int (*unlink)(char* filename);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_NANOSLEEP
int (*nanosleep)(int rqtp, int rmtp);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_READLINK
int (*readlink)(char* path, char * buf, int bufsize);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_IOCTL
int (*ioctl)(unsigned int fd, unsigned int cmd, void* arg);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SOCKET
int (*socket)(int domain, int type, int protocol);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_BIND
int (*bind)(int fd, const struct sockaddr *addr, unsigned int len);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_ACCEPT
int (*accept)(int fd, struct sockaddr *addr, unsigned int *len);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_CONNECT
int (*connect)(int fd, const struct sockaddr *addr, unsigned int len);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_LISTEN
int (*listen)(int fd, int backlog);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_GETSOCKNAME
int (*getsockname)(int fd, struct sockaddr *addr, unsigned int *len);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SETSOCKOPT
int (*setsockopt)(int fd, int level, int optname, void *optval, unsigned int optlen);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_GETSOCKOPT
int (*getsockopt)(int fd, int level, int optname, void *optval, unsigned int *optlen);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SENDTO
int (*sendto)(int fd, const void *buf, size_t len, int flags, const struct sockaddr *addr, unsigned int alen);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SEND
int (*send)(int fd, const void *buf, size_t len, int flags);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_RECVFROM
int (*recvfrom)(int fd, void *buf, int len, int flags, struct sockaddr *addr, unsigned int *alen);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_RECV
int (*recv)(int fd, void *buf, int len, int flags);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_VMSPLICE
long (*vmsplice)(int fd, iovec *iov, unsigned long nr_segs, unsigned int flags);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_TEE
long (*tee)(int fd_in, int fd_out, size_t len, unsigned int flags);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SPLICE
long (*splice)(int fd_in, long *off_in, int fd_out,long *off_out, size_t len, unsigned int flags);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SENDFILE
int (*sendfile)(int out_fd, int in_fd, long *offset, size_t count);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_WAITPID
int (*waitpid)(int pid, int *status, int options);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_WAITID
int (*waitid)(long type, long id, siginfo_t *info, int options);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_WAIT2
int (*wait2)(int pid,void *status);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_WAIT
int (*wait)(void *status);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_CLONE
int (*clone)(int (*fn)(void *), void *child_stack, long flags, void *arg);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SELECT
int (*select)(int n, fd_set *rfds, fd_set *wfds, fd_set *efds, timeval *tv);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_FCNTL
int (*fcntl)(int fd, int cmd, ...);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_EXECVE
int (*execve)(const char* filename, char * const argv[], char *const envp[]);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_WRITE
int (*write)(int fd, void* buf, size_t count);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MPROTECT
int (*mprotect)(void* start, size_t len, long prot);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MUNMAP
int (*munmap)(void *addr, size_t len);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MMAP
void *(*mmap)(void *start, size_t len, int prot, int flags, int fd, long int off);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SBRK
void *(*sbrk)(long inc);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MREMAP
void *(*mremap)(void *old_addr, size_t old_len, size_t new_len, int flags, ...);
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MADVISE
int (*madvise)(void *addr, size_t len, int advice);
#endif
///------------------------------------------------------------
}sys_t;
