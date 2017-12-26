/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_res_o_flags_hash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:56:04 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/25 19:00:07 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_pf_res_o_flags_hash_elif(char *s, char **res)
{
	*res = ft_strnew(ft_strlen(s) + 1);
	ft_strlcat(*res + 1, s, ft_strlen(s) + 1);
	(*res)[0] = '0';
	ft_strdel(&s);
}

char			*ft_pf_res_o_flags_hash(char *s, t_format *all)
{
	char	*res;
	int		i;

	res = NULL;
	i = ft_pf_find_digit_index(s);
	if (ft_pf_find_minus(s))
		return (s);
	if (s[i] == '0' && s[i + 1] != '\0' && !(*all).precision_field_identifier)
	{
		s[i] = '0';
		return (s);
	}
	else if (s[i - 1] == ' ')
	{
		s[i - 1] = '0';
		return (s);
	}
	else if (s[i] != '0' || (s[i] == '0' && s[i + 1] == '\0') || (s[i] == '0' \
				&& (*all).precision_field_identifier))
		ft_pf_res_o_flags_hash_elif(s, &res);
	return (res);
}
