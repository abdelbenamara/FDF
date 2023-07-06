/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:22:29 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/06 23:04:08 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(t_ximage *ximage, int x, int y, int color)
{
	char	*pos;

	pos = ximage->data + (y * ximage->lsize + x * (ximage->bpp / 8));
	*((unsigned int *) pos) = color;
}

static void	ft_draw_rectangle(t_ximage *ximage)
{
	int	i;
	int	j;

	j = YSIZE / 4;
	while (j < 3 * YSIZE / 4)
	{
		i = XSIZE / 4;
		while (i < 3 * XSIZE / 4)
			(ft_put_pixel(ximage, i, j, 0x00FFFFFF), ++i);
		++j;
	}
}

int	ft_render_frame(t_xclient *xclient)
{
	t_ximage	*buf;
	t_ximage	*tmp;

	buf = ft_new_ximage(xclient);
	ft_draw_rectangle(buf);
	tmp = xclient->ximage;
	xclient->ximage = buf;
	ft_free_ximage(tmp);
	mlx_put_image_to_window(xclient->mlx, xclient->win, \
		xclient->ximage->img, xclient->ox, xclient->oy);
	return (EXIT_SUCCESS);
}
