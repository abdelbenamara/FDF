/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:59:33 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/05 04:20:54 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_new_xclient_buffer(t_xclient *xclient)
{
	xclient->buf = mlx_new_image(xclient->mlx, XSIZE, YSIZE);
	if (!(xclient->buf))
		return (ft_free_xclient(xclient));
	xclient->data_addr = mlx_get_data_addr(xclient->buf, \
		&(xclient->bits_per_pixel), &(xclient->line_size), &(xclient->endian));
	if (!(xclient->data_addr))
		return (ft_free_xclient(xclient));
}

static void	ft_put_pixel(t_xclient *xclient, int x, int y, int color)
{
	char	*pos;

	pos = xclient->data_addr;
	pos += (y * xclient->line_size + x * (xclient->bits_per_pixel / 8));
	*((unsigned int *) pos) = color;
}

static void	ft_render_image(t_xclient *xclient)
{
	void	*tmp;

	tmp = xclient->img;
	xclient->img = xclient->buf;
	mlx_put_image_to_window(xclient->mlx, xclient->win, xclient->img, 0, 0);
	if (tmp)
		free(tmp);
}

static int	ft_close_window(int keycode, t_xclient *xclient)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(xclient->mlx);
		xclient->data_addr = NULL;
		xclient->buf = NULL;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_xclient	*xclient;

	if (ac < 2)
		return (ft_dprintf(STDERR_FILENO, USAGE), 2);
	(void) av;
	xclient = ft_init_xclient();
	if (!xclient)
		return (1);
	ft_new_xclient_buffer(xclient);
	if (!xclient)
		return (1);
	ft_put_pixel(xclient, 5, 5, 0x00FF0000);
	ft_render_image(xclient);
	mlx_hook(xclient->win, KeyPress, KeyPressMask, ft_close_window, xclient);
	mlx_loop(xclient->mlx);
	return (ft_free_xclient(xclient), 0);
}
