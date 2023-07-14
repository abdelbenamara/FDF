/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:22:29 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/12 21:20:19 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(t_ximage *ximage, int x, int y, int color)
{
	char	*pos;

	pos = ximage->data + (y * ximage->lsize + x * (ximage->bpp / 8));
	*((unsigned int *) pos) = mlx_get_color_value(ximage->mlx, color);
}

static void	ft_draw_map(t_ximage *ximage, char ***map, size_t ppad)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	y = 0;
	while (map[j])
	{
		i = 0;
		x = 0;
		while (map[j][i])
		{
			if (y % ppad == 0)
				while (x < (int)(i * ppad))
					(ft_put_pixel(ximage, x, y, 0x00FFFFFF), ++x);
			else
				(ft_put_pixel(ximage, x, y, 0x00FFFFFF), x += ppad);
			++i;
		}
		if (y % ppad == 0)
			++j;
		++y;
	}
}

int	ft_render_frame(t_xclient *xclient)
{
	t_ximage		*buf;
	t_ximage		*tmp;

	buf = ft_new_ximage(xclient);
	ft_draw_map(buf, xclient->map, xclient->ppad);
	tmp = xclient->ximage;
	xclient->ximage = buf;
	ft_free_ximage(tmp);
	mlx_clear_window(xclient->mlx, xclient->win);
	mlx_put_image_to_window(xclient->mlx, xclient->win, \
		xclient->ximage->img, xclient->ox, xclient->oy);
	return (EXIT_SUCCESS);
}
