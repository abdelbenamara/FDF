/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 02:46:40 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/21 20:08:46 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_ximage ximage, int x, int y, int color)
{
	char	*pos;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pos = ximage.data + x * (ximage.bpp / 8) + y * ximage.lsize;
	*((unsigned int *) pos) = mlx_get_color_value(ximage.mlx, color);
}
