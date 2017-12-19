#include <stdlib.h>
#include <string.h>
#include "libstr.h"

t_str		*str_alloc(size_t capacity)
{
	t_str	*nstr;

	if (!(nstr = (t_str *)malloc(sizeof(t_str))))
		return (NULL);
	nstr->length = 0;
	nstr->capacity = capacity;
	if (!(nstr->data = (char *)malloc(sizeof(char) * capacity)))
	{
		free (nstr);
		return (NULL);
	}
	bzero(nstr->data, capacity);
	return (nstr);
}

int			str_realloc(t_str *str, size_t needed)
{
	char *s;

	if (needed > str->capacity)
	{
		s = str->data;
		if (!(str->data = (char *)malloc(sizeof(char) * needed)))
			return (0);
		bzero(str->data, needed);
		memcpy(str->data, s, str->capacity);
		free(s);
		str->capacity = needed;
		return (1);
	}
	return (-1);
}

void		str_free(t_str	**str)
{
	if (*str)
	{
		if ((*str)->data)
			free((*str)->data);
		free(*str);
	}
	*str = NULL;
}

t_str		*str_new(const char *s)
{
	t_str	*nstr;
	size_t	length;

	length = strlen(s);
	if (!(nstr = str_alloc(length)))
		return (NULL);
	nstr->length = length;
	memcpy(nstr->data, s, length);
	return (nstr);
}
