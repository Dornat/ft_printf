/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:25:25 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/26 16:25:49 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			ft_count_bits(unsigned long long dec)
{
	int		i;

	i = 1;
	while ((dec = dec >> 1))
		i++;
	return (i);
}
