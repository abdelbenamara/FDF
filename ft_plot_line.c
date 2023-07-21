/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 02:28:48 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/20 19:07:05 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int i)
{
	if (i < 0)
		return (-1 * i);
	return (i);
}

static void	ft_plot_line_low(t_ximage ximage, t_vec2 u, t_vec2 v)
{
	t_vec2	d;
	int		di;
	int		yi;

	d.x = v.x - u.x;
	d.y = v.y - u.y;
	yi = 1;
	if (d.y < 0)
	{
		yi = -1;
		d.y = -d.y;
	}
	di = 2 * d.y - d.x;
	while (u.x < v.x)
	{
		ft_put_pixel(ximage, u.x, u.y, 0x00FFFFFF);
		if (di > 0)
		{
			u.y += yi;
			di += 2 * (d.y - d.x);
		}
		else
			di += 2 * d.y;
		++u.x;
	}
}

static void	ft_plot_line_high(t_ximage ximage, t_vec2 u, t_vec2 v)
{
	t_vec2	d;
	int		di;
	int		xi;

	d.x = v.x - u.x;
	d.y = v.y - u.y;
	xi = 1;
	if (d.x < 0)
	{
		xi = -1;
		d.x = -d.x;
	}
	di = 2 * d.x - d.y;
	while (u.y < v.y)
	{
		ft_put_pixel(ximage, u.x, u.y, 0x00FFFFFF);
		if (di > 0)
		{
			u.x += xi;
			di += 2 * (d.x - d.y);
		}
		else
			di += 2 * d.x;
		++u.y;
	}
}

void	ft_plot_line(t_ximage ximage, t_vec2 u, t_vec2 v)
{
	if (ft_abs(v.y - u.y) < ft_abs(v.x - u.x))
	{
		if (u.x > v.x)
			ft_plot_line_low(ximage, v, u);
		else
			ft_plot_line_low(ximage, u, v);
	}
	else
	{
		if (u.y > v.y)
			ft_plot_line_high(ximage, v, u);
		else
			ft_plot_line_high(ximage, u, v);
	}
}
