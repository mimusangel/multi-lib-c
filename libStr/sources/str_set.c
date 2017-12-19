#include <string.h>
#include <stdarg.h>
#include "libstr.h"

int			str_setchar(t_str *str, const char *s)
{
	size_t	length;

	length = strlen(s);
	if (length > str->capacity)
	{
		if (str_realloc(str, length) != 1)
			return (0);
	}
	memcpy(str->data, s, length);
	str->length = length;
	return (1);
}

int			str_joinchar(t_str *str, int nb, ...)
{
	va_list	ap;
	char	*s;
	int		i;
	size_t	nlen;
	size_t	len;

	va_start(ap, nb);
	i = -1;
	nlen = str->length;
	while (++i < nb)
	{
		s = va_arg (ap, char *);
		nlen += strlen(s);
	}
	va_end(ap);
	if (nlen> str->capacity)
	{
		if (str_realloc(str, nlen) != 1)
			return (0);
	}
	va_start(ap, nb);
	i = -1;
	while (++i < nb)
	{
		s = va_arg (ap, char *);
		len = strlen(s);
		memcpy(str->data + str->length, s, len);
		str->length += len;
	}
	va_end(ap);
	return (1);
}
