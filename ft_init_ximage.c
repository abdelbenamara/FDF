/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ximage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:34:09 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/18 20:15:05 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ximage	ft_init_ximage(t_xclient *xclient)
{
	t_ximage	ximage;

	ximage.mlx = xclient->mlx;
	ximage.img = mlx_new_image(ximage.mlx, WIDTH, HEIGHT);
	if (!(ximage.img))
		(ft_free_xclient(xclient), exit(EXIT_FAILURE));
	ximage.data = mlx_get_data_addr(ximage.img, \
		&(ximage.bpp), &(ximage.lsize), &(ximage.endian));
	ximage.xparams = xclient->xparams;
	return (ximage);
}
