/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ximage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:00:17 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/06 23:03:48 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_ximage(t_ximage *ximage)
{
	if (ximage->img)
		mlx_destroy_image(ximage->mlx, ximage->img);
	free(ximage);
}
