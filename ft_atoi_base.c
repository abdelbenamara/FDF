/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:22:03 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/22 00:39:07 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static uint8_t	ft_is_in_base(char c, const char *base)
{
	size_t	i;

	i = 0;
	while (base[i] && c != base[i])
		++i;
	if (base[i])
		return (1);
	return (0);
}

int	ft_atoi_base(const char *nptr, const char *base)
{
	const size_t	base_len = ft_strlen(base);
	int				i;
	int				sign;
	int				nb;

	while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
		++nptr;
	i = 0;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	while (ft_is_in_base(*nptr, base))
	{
		nb = 0;
		while (base[nb] && *nptr != base[nb])
			++nb;
		i = i * base_len + nb;
		++nptr;
	}
	return (sign * i);
}
