/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_x_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:15:03 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/27 09:54:35 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_pf_hex_for_tou(char c)
{
	if (c == 'x' || c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' \
		|| c == 'f')
		return (1);
	return (0);
}

static void		ft_pf_hex_to_upper(char **res)
{
	int		i;

	i = 0;
	while ((*res)[i])
	{
		if (ft_pf_hex_for_tou((*res)[i]))
			(*res)[i] = (*res)[i] - 32;
		i++;
	}
}

char			*ft_pf_res_x_flags(char *s, t_format *all)
{
	char	*res;

	res = s;
	if (!(*all).flag_apostrophe && !(*all).flag_minus && !(*all).flag_plus && \
	!(*all).flag_space && !(*all).flag_zero && !(*all).flag_hash && \
	!(*all).big_x)
		return (s);
	if ((*all).flag_zero)
		res = ft_pf_res_x_flags_zero(res, all);
	if ((*all).flag_hash)
		res = ft_pf_res_x_flags_hash(res, all);
	if ((*all).flag_minus)
		res = ft_pf_res_d_i_flags_minus(res, all);
	if ((*all).big_x)
		ft_pf_hex_to_upper(&res);
	return (res);
}
