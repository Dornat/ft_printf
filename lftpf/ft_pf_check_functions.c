/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_check_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:40:35 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/25 16:03:20 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_pf_check_for_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'f' || c == 'F' || c == 'e' \
	|| c == 'E' || c == 'g' || c == 'G' || c == 'x' || c == 'X' || c == 'o' \
	|| c == 's' || c == 'S' || c == 'c' || c == 'C' || c == 'p' || c == 'a' \
	|| c == 'A' || c == 'n')
		return (1);
	else
		return (0);
}

int		ft_pf_check_for_t_size(char c)
{
	if (c == 'h' || c == 'l' || c == 'L' || c == 'z' || c == 'j' || c == 'D')
		return (1);
	else
		return (0);
}

int		ft_pf_check_for_flag(char c)
{
	if (c == '\'' || c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

int		ft_pf_check_for_big_sdouxc(char c)
{
	if (c == 'S' || c == 'D' || c == 'O' || c == 'U' || c == 'X' || c == 'C')
		return (1);
	return (0);
}
