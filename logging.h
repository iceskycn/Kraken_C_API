#ifndef __logging_h
#define __logging_h



#undef PDEBUG             /* undef it, just in case */
#ifdef API_DEBUG
     /* This one if debugging is on, and kernel space */
     /* This one for user space */
#    define PDEBUG(fmt, ...)	do{ \
					fprintf(stderr, "%s(): ", __FUNCTION__); \
					fprintf(stderr, fmt, ##__VA_ARGS__); \
					fprintf(stderr, "\n"); \
				} while(0)
#else
#  define PDEBUG(fmt, ...) /* not debugging: nothing */
#endif


/* SAME FOR TRACE FUNCTIONS */

#undef PTRACE             /* undef it, just in case */
#ifdef API_TRACE
     /* This one if debugging is on, and kernel space */
     /* This one for user space */
#    define PTRACE(fmt, ...)	do{ \
					fprintf(stderr, "%s(): ", __FUNCTION__); \
					fprintf(stderr, fmt, ##__VA_ARGS__); \
					fprintf(stderr, "\n"); \
				} while(0)
#else
#  define PTRACE(fmt, ...) /* not debugging: nothing */
#endif


#endif
