/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:22:29 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/18 20:15:35 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(t_ximage ximage, int x, int y, int color)
{
	t_xparams	xparams;
	char		*pos;

	xparams = ximage.xparams;
	x += xparams.origin.x - xparams.zoom * xparams.width / 2;
	y += xparams.origin.y - xparams.zoom * xparams.height / 2;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pos = ximage.data + x * (ximage.bpp / 8) + y * ximage.lsize;
	*((unsigned int *) pos) = mlx_get_color_value(ximage.mlx, color);
}

static t_vec2	ft_get_projection(t_ximage ximage, int x, int y, int z)
{
	t_vec2		u;

	(void) z;
	u.x = x * ximage.xparams.zoom;
	u.y = y * ximage.xparams.zoom;
	return (u);
}

static void	ft_draw_line(t_ximage ximage, t_vec2 u, t_vec2 v)
{
	const int	dx = v.x - u.x;
	const int	dy = v.y - u.y;
	int			d;
	t_vec2		w;

	d = 2 * dy - dx;
	w.x = u.x;
	w.y = u.y;
	while (w.x < v.x || w.y < v.y)
	{
		ft_put_pixel(ximage, w.x, w.y, 0x00FFFFFF);
		if (d > 0)
		{
			if (w.y < v.y)
				++w.y;
			d -= 2 * dx;
		}
		d += 2 * dy;
		if (w.x < v.x)
			++w.x;
	}
}

static void	ft_draw_map(t_ximage ximage, char ***map)
{
	int		i;
	int		j;
	t_vec2	u;
	t_vec2	v;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			u = ft_get_projection(ximage, i, j, ft_atoi(map[j][i]));
			ft_put_pixel(ximage, u.x, u.y, 0x00FFFFFF);
			v = u;
			if (i > 0)
				u = ft_get_projection(ximage, i - 1, j, ft_atoi(map[j][i - 1]));
			ft_draw_line(ximage, u, v);
			if (j > 0)
				u = ft_get_projection(ximage, i, j - 1, ft_atoi(map[j - 1][i]));
			ft_draw_line(ximage, u, v);
			++i;
		}
		++j;
	}
}

int	ft_render_frame(t_xclient *xclient)
{
	t_ximage	xbuffer;
	void		*old_img;

	xbuffer = ft_init_ximage(xclient);
	if (!(xbuffer.img))
		return (EXIT_FAILURE);
	ft_draw_map(xbuffer, xclient->xparams.map);
	old_img = xclient->ximage.img;
	xclient->ximage = xbuffer;
	mlx_destroy_image(xclient->mlx, old_img);
	mlx_clear_window(xclient->mlx, xclient->win);
	mlx_put_image_to_window(xclient->mlx, \
		xclient->win, xclient->ximage.img, 0, 0);
	return (EXIT_SUCCESS);
}
