/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:41:42 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/12 13:53:37 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// *.c
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isalpha(int nb);
int					ft_isdigit(int nb);
int					ft_isalnum(int nb);
int					ft_isascii(int nb);
int					ft_isprint(int nb);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *ptr, int value, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t size);
size_t				ft_srtlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_atoi(const char *str);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
char				*ft_strdup(char *src);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *str, int searched);
char				*ft_strrchr(const char *str, int searched);
void				*ft_memchr(const void *memblock, int searched, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int nb, int fd);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
