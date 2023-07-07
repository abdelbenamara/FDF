/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 00:17:21 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/07 02:17:21 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	***ft_lst_to_map(t_list *lst)
{
	char	***map;
	size_t	i;

	map = malloc((ft_lstsize(lst) + 1) * sizeof(int **));
	if (!map)
		return (NULL);
	i = 0;
	while (lst)
	{
		map[i] = ft_split((char *) lst->content, ' ');
		if (!(map[i]))
			return (ft_free_map(map), NULL);
		lst = lst->next;
		++i;
	}
	map[i] = NULL;
	return (map);
}

char	***ft_new_map(char *file)
{
	int		fd;
	char	*line;
	t_list	*lst;
	t_list	*tmp;
	char	***map;

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
	ft_lstclear(&lst, free);
	return (map);
}
