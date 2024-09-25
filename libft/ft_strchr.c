/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:23:08 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:23:09 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The  strchr()  function  returns  a  pointer to the first occurrence of the character c in the string s.
char *strchr(const char *s, int c)
{
    int cnt;
    char    character;

    cnt = 0;
    character = (char)c;
    while (s[cnt] != character && s[cnt] != '\0')
        cnt++;
    if (s[cnt] == character)
        return (s[cnt]);
    else
        return (0);
}