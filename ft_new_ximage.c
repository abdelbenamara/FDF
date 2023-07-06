/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_ximage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:34:09 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/06 23:03:04 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ximage	*ft_new_ximage(t_xclient *xclient)
{
	t_ximage	*ximage;

	ximage = malloc(sizeof(t_ximage));
	if (!ximage)
		return (NULL);
	ximage->mlx = xclient->mlx;
	ximage->img = mlx_new_image(ximage->mlx, XSIZE, YSIZE);
	if (!(ximage->img))
		return (free(ximage), NULL);
	ximage->data = mlx_get_data_addr(ximage->img, \
		&(ximage->bpp), &(ximage->lsize), &(ximage->endian));
	return (ximage);
}
