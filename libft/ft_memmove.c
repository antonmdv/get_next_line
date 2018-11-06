/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:06:04 by amedvede          #+#    #+#             */
/*   Updated: 2018/10/22 21:06:05 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptr_src;
	char	*ptr_dest;

	i = -1;
	ptr_src = (char *)src;
	ptr_dest = (char *)dst;
	if (ptr_src < ptr_dest)
		while ((int)(--len) >= 0)
			*(ptr_dest + len) = *(ptr_src + len);
	else
		while (++i < len)
			*(ptr_dest + i) = *(ptr_src + i);
	return (dst);
}
