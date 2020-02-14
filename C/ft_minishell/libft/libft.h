/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:58:52 by arlecomt          #+#    #+#             */
/*   Updated: 2017/04/24 18:18:22 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H

# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define DEFAULT "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define TURQUOISE "\033[36m"
# define REDCOVER "\033[41m"
# define GREENCOVER "\033[42m"
# define YELLOWCOVER "\033[43m"
# define BLUECOVER "\033[44m"
# define PURPLECOVER "\033[45m"
# define UGLYBLUECOVER "\033[46m"
# define GREYCOVER "\033[47m"
# define TEST "\033[51m"

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

void					ft_init_integers(const int nb, ...);
void					ft_print_grid(char **grid);

long long				ft_abs(long long n);
int						ft_intlen(int n);
int						ft_atoi(const char *str);
int						ft_atoi_base(const char *str, int str_base);
int						ft_atoll(const char *str);
void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
char					*ft_itoa(int n);
char					*ft_realloc(char *ptr, size_t size);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_putchar(char c);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
int						ft_size_bin(wchar_t value);
void					ft_putstr(char const *s);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_freejoin(char *s1, char *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
size_t					ft_wcslen(wchar_t *s);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *big, const char *little,
						size_t len);
char					*ft_strrchr(const char *s, int c);
int						ft_strchrn(char *str, int c);
char					*ft_strtolower(char *str);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strtrim(char const *s);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content,
						size_t content_size);
void					ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst,
						void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstadd(t_list **alst, t_list *new);
int						ft_lstsize(t_list *lst);
void					ft_lstaddend(t_list **alst, t_list *new);
t_list					*ft_lstselectsort(t_list *lst, \
						int (*cmp)(void*, void*));
t_list					*ft_lstbubblesort(t_list *lst, \
						int (*cmp)(void*, void*));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct			s_ct
{
	int					fd;
	char				*r_line;
}						t_ct;

# define BUFF_SIZE 1000

int						get_next_line(const int fd, char **line);

# define FT_PRINTF_CONV "sSpdiouxXDOUcC"
# define FT_PRINTF_FLAGS "#0-+ hhhllljz"
# define FT_PRINTF_LENGTH "hhhllljz"
# define FT_PRINTF_INT "dDioOuUxX"
# define FT_PRINTF_L "DOUCS"

# define MAX_UNI 0x10FFFF

typedef struct			s_type
{
	char				flags[15];
	long long			precision;
	long long			padding;
	char				conv;
	int					base;
}						t_type;

typedef struct			s_buff
{
	char				content[BUFF_SIZE];
	int					index;
	int					ret;
}						t_buff;

int						ft_printf(const char *restrict format, ...);

int						ft_putbuffer(t_buff *buff, void *adding, size_t size);
int						ft_print_buff(t_buff *buff);
void					ft_printf_itoa(long long n, int base, char *value);

void					ft_padding(t_buff *buff, t_type *info, long long len);
void					ft_precision_int(t_buff *buff, t_type *info, \
						long long len);

void					ft_int(t_buff *buff, t_type *info, long long n);

void					ft_char(t_buff *buff, t_type *info, wchar_t c);
void					ft_charadd(t_type *info, wchar_t c, char *char_oct, \
						int *i);
void					ft_string(t_buff *buff, t_type *info, wchar_t *s);

void					ft_ptrhexa(t_buff *buff, t_type *info, \
						unsigned long p);

void					ft_percent(t_buff *buff, t_type *info);

int						ft_size_bin(int c);

#endif
