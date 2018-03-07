#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 4

# include <string.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct			s_fdf_lst
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					i;
	int					j;
}						t_fdf_lst;

int						get_next_line(const int fd, char **line);
#endif
