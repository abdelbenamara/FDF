/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_xclient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:19:41 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/05 04:20:02 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_xclient(t_xclient *xclient)
{
	if (!xclient->data_addr)
		free(xclient->data_addr);
	if (xclient->buf)
		mlx_destroy_image(xclient->mlx, xclient->buf);
	if (xclient->img)
		mlx_destroy_image(xclient->mlx, xclient->img);
	if (xclient->win)
		mlx_destroy_window(xclient->mlx, xclient->win);
	if (xclient->mlx)
		(mlx_destroy_display(xclient->mlx), free(xclient->mlx));
	free(xclient);
}
