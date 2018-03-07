#include "fdf.h"

int		deal_key(int key, t_fdf_lst *param)
{
	mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->i, param->j, 0xFFFFFF);
	while (param->j < 500)
	{
		param->i = 0;
		while (param->i < 500)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->i, param->j, (0xFFFFFF + key));
			param->i++;
		}
		param->j++;
	}
	return (0);
}

int	main()
{
	t_fdf_lst win;
	t_fdf_lst *ptr;

	ptr = &win;
	win.i = 250;
	win.j = 250;
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 500, 500, "mlx 42");
	mlx_key_hook(win.win_ptr, deal_key, (void*)ptr);
	mlx_loop(win.mlx_ptr);
}
