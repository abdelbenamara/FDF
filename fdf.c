/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 22:59:33 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/05 23:58:49 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_xclient	*xclient;

	if (ac < 2)
		return (ft_dprintf(STDERR_FILENO, USAGE), 2);
	(void) av;
	xclient = ft_new_xclient();
	if (!xclient)
		return (1);
	mlx_hook(xclient->win, \
		DestroyNotify, ButtonReleaseMask, mlx_loop_end, xclient->mlx);
	mlx_hook(xclient->win, \
		KeyPress, KeyPressMask, ft_handle_key_press, xclient);
	mlx_loop_hook(xclient->mlx, ft_render_frame, xclient);
	mlx_loop(xclient->mlx);
	return (ft_free_xclient(xclient), 0);
}
