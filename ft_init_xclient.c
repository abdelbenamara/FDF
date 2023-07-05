/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_xclient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:20:24 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/05 04:20:45 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xclient	*ft_init_xclient(void)
{
	t_xclient	*xclient;

	xclient = malloc(sizeof(t_xclient));
	if (!xclient)
		return (NULL);
	xclient->mlx = NULL;
	xclient->win = NULL;
	xclient->img = NULL;
	xclient->buf = NULL;
	xclient->data_addr = NULL;
	xclient->mlx = mlx_init();
	if (!(xclient->mlx))
		return (ft_free_xclient(xclient), NULL);
	xclient->win = mlx_new_window(xclient->mlx, XSIZE, YSIZE, TITLE);
	if (!(xclient->win))
		return (ft_free_xclient(xclient), NULL);
	return (xclient);
}
