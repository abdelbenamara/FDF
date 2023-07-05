/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:00:16 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/05 04:23:22 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include "mlx.h"
# include "libft.h"

# define USAGE	"Usage: fdf file.fdf\n"
# define XSIZE	1280
# define YSIZE	720
# define TITLE	"FDF"

typedef struct s_xclient
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*buf;
	char	*data_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_xclient;


void		ft_free_xclient(t_xclient *xclient);
t_xclient	*ft_init_xclient(void);

#endif
