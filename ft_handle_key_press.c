/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:47:35 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/21 02:30:49 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_handle_rotation(int keycode, t_xclient *xclient)
{
	if (keycode == XK_w)
		ft_printf("theta.x = %d\n", ++(xclient->xparams.theta.x));
	else if (keycode == XK_s)
		ft_printf("theta.x = %d\n", --(xclient->xparams.theta.x));
	else if (keycode == XK_a)
		ft_printf("theta.z = %d\n", ++(xclient->xparams.theta.z));
	else if (keycode == XK_d)
		ft_printf("theta.z = %d\n", --(xclient->xparams.theta.z));
	else if (keycode == XK_e)
		ft_printf("theta.y = %d\n", ++(xclient->xparams.theta.y));
	else if (keycode == XK_q)
		ft_printf("theta.y = %d\n", --(xclient->xparams.theta.y));
}

int	ft_handle_key_press(int keycode, t_xclient *xclient)
{
	if (keycode == XK_r)
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
		ft_printf("scale.x = %d\n", ++(xclient->xparams.scale.x));
	else if (keycode == XK_o)
		ft_printf("scale.x = %d\n", --(xclient->xparams.scale.x));
	else if (keycode == XK_k)
		ft_printf("scale.y = %d\n", ++(xclient->xparams.scale.y));
	else if (keycode == XK_l)
		ft_printf("scale.y = %d\n", --(xclient->xparams.scale.y));
	else if (keycode == XK_Escape)
		mlx_loop_end(xclient->mlx);
	else
		ft_handle_rotation(keycode, xclient);
	return (EXIT_SUCCESS);
}
