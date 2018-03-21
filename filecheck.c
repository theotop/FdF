#include "fdf.h"

int		***ft_read_map(int fd)
{
	char	*line_content;
	int 	gnl_ret;
	int		**map;
	int		**maptmp;
	int		lines;

	line_content = NULL;
	gnl_ret = 1;
	lines = 0;
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &line_content);
		if (!(map = malloc(sizeof(int*) * lines + 1)))
			ft_errorcode("malloc n'a pas pu malloquer");
		if (gnl_ret)
		{
			maptmp = map;
			free(map);
			if (!(map = malloc(sizeof(int*) * lines + 1)))
				ft_errorcode("malloc n'a pas pu malloquer");
			ft_concat_map(&map, maptmp, line_content, lines);
			lines++;
		}
		lines = gnl_ret ? lines + 1 : line;
	}
}

void ft_concat_map(int ***map, int **maptmp, char *line_content, int lines)
{
	int *new_line;

	if (!(new_line = malloc(sizeof(int) * ft_mapwidth(line_content))))
		ft_errorcode("malloc n'a pas pu malloquer");
	
}

int ft_mapwidth(char *line)
{
	int	i;
	int width;

	i = 0;
	width = 0;
	while (line[i])
	{
		if (line[i] != '\t')
		{
			while (line[i] && line[i] != '\t')
				i++;
			width++;
		}
		i++;
	}
	return (width);
}
