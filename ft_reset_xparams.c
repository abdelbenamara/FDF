/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_xparams.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 01:23:18 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/21 02:30:09 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reset_xparams(t_xparams *xparams)
{
	xparams->origin.x = WIDTH / 2;
	xparams->origin.y = HEIGHT / 2;
	xparams->scale.x = xparams->basis;
	xparams->scale.y = 1;
	xparams->theta.x = -35;
	xparams->theta.y = 0;
	xparams->theta.z = -45;
}
