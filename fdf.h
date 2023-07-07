/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:00:16 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/07 02:11:38 by abenamar         ###   ########.fr       */
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
# define XSIZE	1280
# define YSIZE	720
# define TITLE	"FDF"

typedef struct s_ximage
{
	void	*mlx;
	void	*img;
	char	*data;
	int		bpp;
	int		lsize;
	int		endian;
}	t_ximage;

typedef struct s_xclient
{
	void		*mlx;
	void		*win;
	t_ximage	*ximage;
	char		***map;
	int			ox;
	int			oy;
}	t_xclient;

void		ft_free_map(char ***map);
char		***ft_new_map(char *file);

void		ft_free_ximage(t_ximage *ximage);
t_ximage	*ft_new_ximage(t_xclient *xclient);

void		ft_free_xclient(t_xclient *xclient);
t_xclient	*ft_new_xclient(char ***map);

int			ft_render_frame(t_xclient *xclient);

int			ft_handle_key_press(int keycode, t_xclient *xclient);

#endif
