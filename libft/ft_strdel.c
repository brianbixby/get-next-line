/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:07:08 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/11 00:51:40 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}
