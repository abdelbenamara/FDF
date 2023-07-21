/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:00:16 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/22 00:37:56 by abenamar         ###   ########.fr       */
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

# ifndef M_PI
#  define M_PI	3.14159265358979323846	/* pi */
# endif

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
}	t_vec3;

typedef struct s_xparams
{
	int		***map;
	size_t	width;
	size_t	height;
	int		basis;
	t_vec2	origin;
	t_vec2	scale;
	t_vec3	theta;
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

void		ft_free_tab(void **tab);
size_t		ft_tab_size(void **tab);
void		ft_free_map(int ***map);
int			ft_atoi_base(const char *nptr, const char *base);
int			***ft_new_map(char *file);

void		ft_reset_xparams(t_xparams *xparams);
t_ximage	ft_init_ximage(t_xclient *xclient);
void		ft_free_xclient(t_xclient *xclient);
t_xclient	*ft_new_xclient(int ***map);

void		ft_put_pixel(t_ximage ximage, int x, int y, int color);
void		ft_plot_line(t_ximage ximage, t_vec2 u, t_vec2 v, int color);
int			ft_render_frame(t_xclient *xclient);

int			ft_handle_key_press(int keycode, t_xclient *xclient);

#endif
