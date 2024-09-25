/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jougarte <jougarte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:23:38 by jougarte          #+#    #+#             */
/*   Updated: 2024/09/25 15:23:39 by jougarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int strlen(char *text)
{
    int cnt;

    cnt = 0;
    while (text[cnt] != '\0')
        cnt++;
    return (cnt);
}