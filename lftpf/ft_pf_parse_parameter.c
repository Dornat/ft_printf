/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_parameter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:07:32 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/22 17:12:31 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_pf_parse_parameter(const char **format)
{
	char	params[3];
	int		i;

	i = 0;
	while ((*format)[i] != '$')
	{
		if (ft_pf_check_for_type((*format)[i]) || (*format)[i] == '.' || \
			ft_pf_check_for_flag((*format)[i]) || \
			ft_pf_check_for_t_size((*format)[i]))
			return (0);
		params[i] = (*format)[i];
		i++;
	}
	params[i] = '\0';
	*format = *format + i + 1;
	return (ft_atoi(params));
}
