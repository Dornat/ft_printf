/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:31:34 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/09 12:26:15 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	return (0);
}
