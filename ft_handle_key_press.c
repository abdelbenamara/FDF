/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_key_press.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:47:35 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/12 19:08:11 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_handle_key_press(int keycode, t_xclient *xclient)
{
	if (keycode == XK_w || keycode == XK_z)
		xclient->oy -= YSIZE / 100;
	else if (keycode == XK_s)
		xclient->oy += YSIZE / 100;
	else if (keycode == XK_a || keycode == XK_q)
		xclient->ox -= XSIZE / 100;
	else if (keycode == XK_d)
		xclient->ox += XSIZE / 100;
	else if (keycode == XK_Escape)
		mlx_loop_end(xclient->mlx);
	return (EXIT_SUCCESS);
}
