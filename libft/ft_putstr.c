/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:15:49 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/11 04:48:53 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(1, s, i);
}