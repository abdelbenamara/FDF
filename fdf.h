/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:00:16 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/18 20:14:44 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include "mlx.h"
# include "libft.h"

# define USAGE	"Usage: fdf file.fdf\n"
# define WIDTH	1280
# define HEIGHT	720
# define TITLE	"FDF"

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_xparams
{
	char	***map;
	size_t	width;
	size_t	height;
	size_t	wpad;
	size_t	hpad;
	size_t	padding;
	size_t	zoom;
	t_vec2	origin;
}	t_xparams;

typedef struct s_ximage
{
	void		*mlx;
	void		*img;
	char		*data;
	int			bpp;
	int			lsize;
	int			endian;
	t_xparams	xparams;
}	t_ximage;

typedef struct s_xclient
{
	void		*mlx;
	void		*win;
	t_xparams	xparams;
	t_ximage	ximage;
}	t_xclient;

void		ft_free_map(char ***map);
char		***ft_new_map(char *file);
t_ximage	ft_init_ximage(t_xclient *xclient);
void		ft_free_xclient(t_xclient *xclient);
t_xclient	*ft_new_xclient(char ***map);

int			ft_render_frame(t_xclient *xclient);

int			ft_handle_key_press(int keycode, t_xclient *xclient);

#endif
