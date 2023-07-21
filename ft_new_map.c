/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 00:17:21 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/22 00:39:45 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_upper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		++i;
	}
	return (str);
}

static int	**ft_strs_to_tab(char **strs)
{
	int		**tab;
	size_t	i;
	char	**tmp;

	tab = malloc((ft_tab_size((void **) strs) + 1) * sizeof(int *));
	if (!tab)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		tab[i] = malloc(2 * sizeof(int));
		if (!(tab[i]))
			return (ft_free_tab((void **) tab), NULL);
		tab[i][0] = ft_atoi(strs[i]);
		tab[i][1] = 0x00FFFFFF;
		tmp = ft_split(strs[i], ',');
		if (tmp && tmp[1])
			tab[i][1] = ft_atoi_base(ft_upper(tmp[1] + 2), "0123456789ABCDEF");
		if (tmp)
			ft_free_tab((void **) tmp);
		++i;
	}
	return (tab[i] = NULL, tab);
}

static int	***ft_lst_to_map(t_list *lst)
{
	int		***map;
	char	**strs;
	size_t	i;

	map = malloc((ft_lstsize(lst) + 1) * sizeof(int **));
	if (!map)
		return (NULL);
	i = 0;
	while (lst)
	{
		map[i] = NULL;
		strs = ft_split((char *) lst->content, ' ');
		if (!strs)
			return (ft_free_map(map), NULL);
		map[i] = ft_strs_to_tab(strs);
		if (!(map[i]))
			return (ft_free_tab((void **) strs), ft_free_map(map), NULL);
		lst = lst->next;
		ft_free_tab((void **) strs);
		++i;
	}
	return (map[i] = NULL, map);
}

int	***ft_new_map(char *file)
{
	int		fd;
	char	*line;
	t_list	*lst;
	t_list	*tmp;
	int		***map;

	fd = open(file, O_RDONLY | O_NONBLOCK);
	if (fd == -1)
		return (perror(file), NULL);
	line = get_next_line(fd);
	lst = NULL;
	while (line)
	{
		tmp = ft_lstnew(line);
		if (!tmp)
			return (ft_lstclear(&lst, free), NULL);
		(ft_lstadd_back(&lst, tmp), line = get_next_line(fd));
	}
	if (close(fd) == -1)
		return (perror(file), ft_lstclear(&lst, free), NULL);
	map = ft_lst_to_map(lst);
	if (!map)
		return (ft_lstclear(&lst, free), NULL);
	return (ft_lstclear(&lst, free), map);
}
