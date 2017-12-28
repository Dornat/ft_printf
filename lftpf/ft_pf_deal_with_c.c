/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_deal_with_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:32:34 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/28 18:14:08 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_deal_with_c(t_format *all, va_list ap, unsigned int *len)
{
	char	*res;

	res = ft_pf_res_c_raw(all, ap);
	res = ft_pf_res_d_i_width(res, all);
	res = ft_pf_res_d_i_flags(res, all);
	ft_putstr(res);
	*len = *len + ft_strlen(res);
	ft_strdel(&res);
}
