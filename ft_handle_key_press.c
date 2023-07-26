/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:47:35 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/25 21:51:35 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_view_angle(t_xclient *xclient, int tx, int ty, int tz)
{
	xclient->xparams.theta.x = tx;
	xclient->xparams.theta.y = ty;
	xclient->xparams.theta.z = tz;
}

static void	ft_handle_rotation(int keycode, t_xclient *xclient)
{
	if (keycode == XK_w)
		++(xclient->xparams.theta.x);
	else if (keycode == XK_s)
		--(xclient->xparams.theta.x);
	else if (keycode == XK_a)
		++(xclient->xparams.theta.z);
	else if (keycode == XK_d)
		--(xclient->xparams.theta.z);
	else if (keycode == XK_e)
		++(xclient->xparams.theta.y);
	else if (keycode == XK_q)
		--(xclient->xparams.theta.y);
}

static void	ft_handle_view(int keycode, t_xclient *xclient)
{
	if (keycode == XK_1)
		xclient->xparams.cmode = 1;
	else if (keycode == XK_2)
		xclient->xparams.cmode = 2;
	else if (keycode == XK_3)
		xclient->xparams.cmode = 3;
	else if (keycode == XK_4)
		xclient->xparams.cmode = 4;
	else if (keycode == XK_5)
		ft_set_view_angle(xclient, -35, 0, -45);
	else if (keycode == XK_6)
		ft_set_view_angle(xclient, -35, 0, -135);
	else if (keycode == XK_7)
		ft_set_view_angle(xclient, -35, 0, 135);
	else if (keycode == XK_8)
		ft_set_view_angle(xclient, -35, 0, 45);
	else if (keycode == XK_9)
		ft_set_view_angle(xclient, -90, 0, 0);
	else if (keycode == XK_0)
		ft_set_view_angle(xclient, 0, 0, 0);
	else
		ft_handle_rotation(keycode, xclient);
}

int	ft_handle_key_press(int keycode, t_xclient *xclient)
{
	if (keycode == XK_Escape)
		mlx_loop_end(xclient->mlx);
	else if (keycode == XK_r)
		ft_reset_xparams(&(xclient->xparams));
	else if (keycode == XK_Up)
		xclient->xparams.origin.y -= HEIGHT / 64;
	else if (keycode == XK_Down)
		xclient->xparams.origin.y += HEIGHT / 64;
	else if (keycode == XK_Left)
		xclient->xparams.origin.x -= WIDTH / 64;
	else if (keycode == XK_Right)
		xclient->xparams.origin.x += WIDTH / 64;
	else if (keycode == XK_i)
		++(xclient->xparams.scale.x);
	else if (keycode == XK_o)
		--(xclient->xparams.scale.x);
	else if (keycode == XK_k)
		++(xclient->xparams.scale.y);
	else if (keycode == XK_l)
		--(xclient->xparams.scale.y);
	else
		ft_handle_view(keycode, xclient);
	return (EXIT_SUCCESS);
}
