/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:22:29 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/06 23:21:48 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(t_ximage *ximage, int x, int y, int color)
{
	char	*pos;

	pos = ximage->data + (y * ximage->lsize + x * (ximage->bpp / 8));
	*((unsigned int *) pos) = color;
}

static void	ft_draw_grid(t_ximage *ximage)
{
	int	i;
	int	j;

	j = 0;
	while (j <= YSIZE / 2)
	{
		i = 0;
		if (j % 32 == 0)
			while (i <= XSIZE / 2)
				(ft_put_pixel(ximage, i, j, 0x00FFFFFF), ++i);
		while (i <= XSIZE / 2)
		{
			if (i % 32 == 0)
				ft_put_pixel(ximage, i, j, 0x00FFFFFF);
			++i;
		}
		++j;
	}
}

int	ft_render_frame(t_xclient *xclient)
{
	t_ximage	*buf;
	t_ximage	*tmp;

	buf = ft_new_ximage(xclient);
	ft_draw_grid(buf);
	tmp = xclient->ximage;
	xclient->ximage = buf;
	ft_free_ximage(tmp);
	mlx_put_image_to_window(xclient->mlx, xclient->win, \
		xclient->ximage->img, xclient->ox, xclient->oy);
	return (EXIT_SUCCESS);
}
