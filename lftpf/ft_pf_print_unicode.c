/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_unicode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:05:31 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/12/12 18:06:38 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_bit_size(unsigned int b)
{
	int		i;

	i = 1;
	while ((b = b >> 1))
		i++;
	return (i);
}

static void		ft_pf_pruc_mask1(unsigned int b)
{
	unsigned char	res_char;
	unsigned int	mask1;

	mask1 = 0xC080;
	res_char = (b >> 6) | (mask1 >> 8);
	write(1, &res_char, 1);
	res_char = ((b << 26) >> 26) | mask1;
	write(1, &res_char, 1);
}

static void		ft_pf_pruc_mask2(unsigned int b)
{
	unsigned char	res_char;
	unsigned int	mask2;

	mask2 = 0xE08080;
	res_char = (b >> 12) | (mask2 >> 16);
	write(1, &res_char, 1);
	res_char = (((b >> 6) << 26) >> 26) | ((mask2 << 16) >> 24);
	write(1, &res_char, 1);
	res_char = ((b << 26) >> 26) | ((mask2 << 24) >> 24);
	write(1, &res_char, 1);
}

static void		ft_pf_pruc_mask3(unsigned int b)
{
	unsigned char	res_char;
	unsigned int	mask3;

	mask3 = 0xF0808080;
	res_char = (b >> 18) | (mask3 >> 24);
	write(1, &res_char, 1);
	res_char = (((b >> 12) << 26) >> 26) | ((mask3 << 8) >> 24);
	write(1, &res_char, 1);
	res_char = (((b >> 6) << 26) >> 26) | ((mask3 << 16) >> 24);
	write(1, &res_char, 1);
	res_char = ((b << 26) >> 26) | ((mask3 << 24) >> 24);
	write(1, &res_char, 1);
}

void			ft_pf_print_unicode(unsigned int b)
{
	int				len_bits;

	len_bits = ft_bit_size(b);
	if (len_bits <= 7)
		write(1, &b, 1);
	else if (len_bits <= 11)
		ft_pf_pruc_mask1(b);
	else if (len_bits <= 16)
		ft_pf_pruc_mask2(b);
	else
		ft_pf_pruc_mask3(b);
}
