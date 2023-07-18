/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:47:35 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/18 19:50:01 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_reset(t_xclient *xclient)
{
	xclient->xparams.zoom = xclient->xparams.padding;
	xclient->xparams.origin.x = WIDTH / 2;
	xclient->xparams.origin.y = HEIGHT / 2;
}

int	ft_handle_key_press(int keycode, t_xclient *xclient)
{
	if (keycode == XK_r)
		ft_reset(xclient);
	else if (keycode == XK_i)
		++(xclient->xparams.zoom);
	else if (keycode == XK_o && xclient->xparams.zoom > 1)
		--(xclient->xparams.zoom);
	else if (keycode == XK_w || keycode == XK_z)
		xclient->xparams.origin.y -= HEIGHT / 64;
	else if (keycode == XK_s)
		xclient->xparams.origin.y += HEIGHT / 64;
	else if (keycode == XK_a || keycode == XK_q)
		xclient->xparams.origin.x -= WIDTH / 64;
	else if (keycode == XK_d)
		xclient->xparams.origin.x += WIDTH / 64;
	else if (keycode == XK_Escape)
		mlx_loop_end(xclient->mlx);
	return (EXIT_SUCCESS);
}
