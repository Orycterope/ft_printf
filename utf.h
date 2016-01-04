#ifndef UTF_H
# define UTF_H
#include "libft.h"
# include <wchar.h>

long long	convert_utf(wint_t arg);
char		*convert_utf_string(wint_t *list);

#endif
