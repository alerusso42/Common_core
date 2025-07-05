/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:36:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/05 15:12:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include "libft.h"
# include "other.h"
# include "mfile_gnl.h"
# include "piscine.h"

typedef long long int	t_int64;
//	BIG LIST
//	--LIBFT:

t_int64		ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int num);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
//		LIST

t_typelist	*ft_lstnew(void *content, void *type);
void		ft_lstadd_front(t_typelist **lst, t_typelist *new);
int			ft_lstsize(t_typelist *lst);
t_typelist	*ft_lstlast(t_typelist *lst);
void		ft_lstadd_back(t_typelist **lst, t_typelist *new);
void		ft_lstdelone(t_typelist *lst, void (*del)(void *));
void		ft_lstclear(t_typelist **lst, void (*del)(void *));
void		ft_lstiter(t_typelist *lst, void (*f)(void *));
t_typelist	*ft_lstmap(t_typelist *lst, void *(*f)(void *), \
void (*del)(void *));
//		PRINTF

int			fd_printf(t_fd fd, const char *str, ...);

//	--OTHER:

int			add_sign_left(char **string, char sign);
int			add_sign_right(char **string, char sign);
int			cut_string(char *string, size_t start, size_t end);
int			cut_string_realloc(char **string, size_t start, size_t end);
void		*del_pointer(void **ptr, int mode);
void		*free_matrix(char **matrix);
void		*free_three_d_matrix(char ***matrix);
int			move_sign(char **type, char **name, char *sign);
int			ft_realloc(void **content, size_t nmemb, size_t size);
char		*ft_strjoin_free(char *s1, char *s2);
void		copy_stringset(char *dest, int charset_type);
void		copy_customset(char *dest, char *charset);
int			sub_strlen(char *s, char *charset, int mode);
int			sub_strcpy(char *dest, char *src, char *charset, int mode);
int			trim_only_right(char **line, char *trimset);

#endif