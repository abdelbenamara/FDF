/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:22:29 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/21 02:31:56 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec2	ft_2d_projection(t_ximage ximage, int x, int y, int z)
{
	const double	tx = ximage.xparams.theta.x * M_PI / 180;
	const double	ty = ximage.xparams.theta.y * M_PI / 180;
	const double	tz = ximage.xparams.theta.z * M_PI / 180;
	t_vec3			s;
	t_vec2			b;

	s.x = (x - ximage.xparams.width / 2) * ximage.xparams.scale.x;
	s.y = (y - ximage.xparams.height / 2) * ximage.xparams.scale.x;
	s.z = z * ximage.xparams.scale.y;
	b.x = cos(ty) * (cos(tz) * s.x + sin(tz) * s.y) - sin(ty) * s.z;
	b.y = sin(tx) * (sin(ty) * (cos(tz) * s.x + sin(tz) * s.y) + cos(ty) * s.z);
	b.y -= cos(tx) * (sin(tz) * s.x - cos(tz) * s.y);
	return (b);
}

static void	ft_plot_map(t_ximage ximage, char ***map)
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
			if (!(map[j][i]))
				break ;
			u = ft_2d_projection(ximage, i, j, ft_atoi(map[j][i]));
			v = u;
			if (i > 0)
				v = ft_2d_projection(ximage, i - 1, j, ft_atoi(map[j][i - 1]));
			ft_plot_line(ximage, u, v);
			if (j > 0 && map[j - 1][i])
				v = ft_2d_projection(ximage, i, j - 1, ft_atoi(map[j - 1][i]));
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
