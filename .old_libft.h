/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axaidan <axaidan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:28:50 by axaidan           #+#    #+#             */
/*   Updated: 2020/12/16 15:42:26 by axaidan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define BUFFER_SIZE 1024

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *elem, void (*del)(void*));
void			ft_lstclear(t_list **lst, void(*del)(void *));
void			ft_lstiter(t_list *lst, void(*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

typedef struct	s_conv
{
	int				i;
	unsigned int	u;
	unsigned char	c;
	char			*str;
	void			*ptr;
	double			d;
	int				width;
	int				preci;
	int				f_zero;
	int				f_zero_f;
	int				f_minus;
	char			*sub;
}				t_conv;

char			*zero_pad_int(t_conv conv);
int				print_int(t_conv conv, va_list args);
char			*utoa(unsigned int n);
int				print_unsigned_int(t_conv conv, va_list args);

int				print_char(t_conv conv, va_list args, char c);

int				print_str(t_conv conv, va_list args);

char			*utox(unsigned int n, char c);
int				print_hexa(t_conv conv, va_list args, char c);

char			*ltox(unsigned long n, char c);
int				print_addr(t_conv conv, va_list args);

t_conv			init_struct(void);
int				putchar_ret(char c);
int				putstr_ret(char *s);
void			ft_putchar_fd(char c, int fd);
int				ft_printf(const char *fmt, ...);

int				get_relevant(long double d, int afterpoint);
double			roundup_p_zero(double d);
char			*roundup_str(char **str, int i);
int				zero_is_signed(long double lf);
char			*ftoa(double d, int afterpoint);
int				print_double(t_conv conv, va_list args);

int				get_next_line(int fd, char **line);

#endif
