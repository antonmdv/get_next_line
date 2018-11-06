/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:05:52 by amedvede          #+#    #+#             */
/*   Updated: 2018/10/22 21:05:54 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*str;
	char	*src1;
	size_t	i;

	i = 0;
	str = dst;
	src1 = (char*)src;
	while (i < n)
	{
		str[i] = src1[i];
		i++;
	}
	return (str);
}
