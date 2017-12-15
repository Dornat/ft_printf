/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:41:30 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/11 19:57:25 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strrev(char *s)
{
/*
 * 	int		i;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(*s) - 1;
	while (i < len)
	{
		c = (*s)[i];
		(*s)[i] = (*s)[len];
		(*s)[len] = c;
		i++;
		len--;
	}
*/
	char	*p1;
	char	*p2;

	p1 = s;
	p2 = s + ft_strlen(s) - 1;
	while (p2 > p1)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
		p1++;
		p2--;
	}
}
