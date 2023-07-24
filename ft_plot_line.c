/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 02:28:48 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/24 09:57:16 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_color(uint8_t low, t_vec3 u, t_vec3 v, t_vec2 d)
{
	int	n;
	int	r;
	int	g;
	int	b;

	n = 32;
	if (low)
		while (v.x - u.x < n * d.x / 32)
			--n;
	else
		while (v.y - u.y < n * d.y / 32)
			--n;
	r = ((v.z >> 16) & 0xFF) - ((u.z >> 16) & 0xFF);
	r = ((v.z >> 16) & 0xFF) - n * r / 32;
	g = ((v.z >> 8) & 0xFF) - ((u.z >> 8) & 0xFF);
	g = ((v.z >> 8) & 0xFF) - n * g / 32;
	b = (v.z & 0xFF) - (u.z & 0xFF);
	b = (v.z & 0xFF) - n * b / 32;
	return (r << 16 | g << 8 | b);
}

static void	ft_plot_line_low(t_ximage ximage, t_vec3 u, t_vec3 v)
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
		ft_put_pixel(ximage, u.x, u.y, ft_get_color(1, u, v, d));
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

static void	ft_plot_line_high(t_ximage ximage, t_vec3 u, t_vec3 v)
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
		ft_put_pixel(ximage, u.x, u.y, ft_get_color(0, u, v, d));
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

void	ft_plot_line(t_ximage ximage, t_vec3 u, t_vec3 v)
{
	int	dx;
	int	dy;

	dx = v.x - u.x;
	if (dx < 0)
		dx = -dx;
	dy = v.y - u.y;
	if (dy < 0)
		dy = -dy;
	if (dy < dx)
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
