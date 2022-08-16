/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:46:33 by julmuntz          #+#    #+#             */
/*   Updated: 2022/07/11 19:15:36 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert_base(int n, int base)
{
	if (n == 0 || base == 10)
		return (n);
	return ((n % base) + 10 * ft_convert_base(n / base, base));
}
