#ifndef LIBSTR_H
# define LIBSTR_H

# include <stddef.h>

typedef struct		s_str
{
	char	*data;
	size_t	length;
	size_t	capacity;
}					t_str;

/*
** str_new.c
*/
t_str		*str_alloc(size_t capacity);
int			str_realloc(t_str *str, size_t needed);
void		str_free(t_str	**str);
t_str		*str_new(const char *s);
/*
** str_out.c
*/
void		str_put(t_str *str);
size_t		str_getlen(t_str *str);
size_t		str_getcap(t_str *str);
/*
** str_set.c
*/
int			str_setchar(t_str *str, const char *s);
int			str_joinchar(t_str *str, int nb, ...);
#endif
