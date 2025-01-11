/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:41:25 by jougarte          #+#    #+#             */
/*   Updated: 2025/01/11 15:47:06 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int text);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int text);
int		ft_isprint(int num);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memcpy(void *destination, const void *source, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t numBytes);
void	*ft_memset(void *ptr, int value, int num);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *text);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t count);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int src);
int		ft_toupper(int src);
void	*ft_callocg(size_t count, size_t size);
char	*ft_substrg(char *s, unsigned int start, size_t len);
char	*ft_strchrg(char *s, int c);
size_t	ft_strleng(char *s);
char	*ft_strjoing(char *s1, char *s2);
size_t		ft_printf(char const *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
int		ft_printf_ptr(uintptr_t ptr);
int		ft_putnbr(int n);
int		ft_printf_unsignedint(unsigned int num);
int		ft_printf_hex(unsigned int nr, char *base);

#endif
