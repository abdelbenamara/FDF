/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:22:29 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/25 21:52:54 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec3	ft_2d_projection(t_ximage ximage, int x, int y, int *z)
{
	const double	tx = ximage.xparams.theta.x * M_PI / 180;
	const double	ty = ximage.xparams.theta.y * M_PI / 180;
	const double	tz = ximage.xparams.theta.z * M_PI / 180;
	t_vec3			a;
	t_vec3			b;

	a.x = (x - ximage.xparams.width / 2) * ximage.xparams.scale.x;
	a.y = (y - ximage.xparams.height / 2) * ximage.xparams.scale.x;
	a.z = z[0] * ximage.xparams.scale.y;
	b.x = cos(ty) * (cos(tz) * a.x + sin(tz) * a.y) - sin(ty) * a.z
		+ ximage.xparams.origin.x;
	b.y = sin(tx) \
		* (sin(ty) * (cos(tz) * a.x + sin(tz) * a.y) + cos(ty) * a.z) \
		- cos(tx) * (sin(tz) * a.x - cos(tz) * a.y)
		+ ximage.xparams.origin.y;
	b.z = z[ximage.xparams.cmode];
	return (b);
}

static void	ft_plot_map(t_ximage ximage, int ***map)
{
	int		i;
	int		j;
	t_vec3	u;
	t_vec3	v;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!(map[j][i]))
				break ;
			u = ft_2d_projection(ximage, i, j, map[j][i]);
			v = u;
			if (i > 0)
				v = ft_2d_projection(ximage, i - 1, j, map[j][i - 1]);
			ft_plot_line(ximage, u, v);
			if (j > 0 && map[j - 1][i])
				v = ft_2d_projection(ximage, i, j - 1, map[j - 1][i]);
			ft_plot_line(ximage, u, v);
			++i;
		}
		++j;
	}
}

int	ft_render_frame(t_xclient *xclient)
{
	t_ximage	xbuffer;
	void		*oldimg;

	xbuffer = ft_init_ximage(xclient);
	if (!(xbuffer.img))
		return (EXIT_FAILURE);
	ft_plot_map(xbuffer, xclient->xparams.map);
	oldimg = xclient->ximage.img;
	xclient->ximage = xbuffer;
	mlx_destroy_image(xclient->mlx, oldimg);
	mlx_clear_window(xclient->mlx, xclient->win);
	mlx_put_image_to_window(xclient->mlx, \
		xclient->win, xclient->ximage.img, 0, 0);
	return (EXIT_SUCCESS);
}
