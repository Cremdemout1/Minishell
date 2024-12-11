/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:58:00 by yohan             #+#    #+#             */
/*   Updated: 2024/11/13 17:24:23 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "printf.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_vars
{
	int		word_count;
	int		i;
	int		start;
	int		str_index;
	char	**dest;
}			t_vars;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dest, char const *src, size_t size);
size_t	ft_strlcpy(char *str1, char const *str2, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int i);
int		ft_toupper(int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *neww);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_strcmp(char *s1, char *s2);
void	ft_strcat(char *dest, char *src);
void	free_array(char **array);
char	*ft_strcpy(char *dest, char *src);
bool	ft_is_even(int n);
bool	ft_is_odd(int n);
void	ft_nl(void);
void	ft_nl_fd(int fd);
char	*get_next_line(int fd);
int		ft_split_wordcount(char **split);
char	*ft_strrem(char *str, char *to_remove);
void	ft_putchar(char c);
void	ft_putendl(char *s);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		count_strings(char **array);
char	*ft_strndup(char const *s1, int n);
char	*ft_getenv(char *str, char **env);
int		len_to_equal(char *str);
char	*ft_env_var(char *str);
int		ft_arraycmp(char **arr1, char **arr2);
int		ft_envnamecmp(char *s1, char *s2);
char	*get_next_line(int fd);
char	*gnl_ft_strjoin(char *line, char *buf);
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3);
int		ft_isalphaund(int input);
int		ft_isalnumund(int input);
void	replace_and_free(char **target, char *replacement);
void	free_and_allocate(char **target, char *replacement, bool to_free);

#endif