#include <unistd.h>
#include "libstr.h"

void		str_put(t_str *str)
{
	write(1, str->data, str->length);
}

size_t		str_getlen(t_str *str)
{
	return (str->length);
}

size_t		str_getcap(t_str *str)
{
	return (str->capacity);
}
