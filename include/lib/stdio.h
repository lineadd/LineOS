#include <lib/va_list.h>

typedef int (*fnptr_t)(unsigned c, void **helper);

int do_printf(const char *fmt, va_list args, fnptr_t fn, void *ptr);

