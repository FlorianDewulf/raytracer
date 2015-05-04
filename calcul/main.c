/*
** main.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Tue May 15 16:00:20 2012 remi mailliet
** Last update Sat Jun  2 18:56:26 2012 florian dewulf
*/

#include	<math.h>
#include	<stdlib.h>
#include	<mlx.h>
#include	"RT.h"

static void	x_init(t_var *v)
{
  if ((v->mlx = mlx_init()) == NULL)
    exit(EXIT_FAILURE);
  v->img = mlx_new_image(v->mlx, LEN_X, LEN_Y);
  v->win = mlx_new_window(v->mlx, LEN_X, LEN_Y, "Ray-Tracer");
  v->data = mlx_get_data_addr(v->img, &v->bpp, &v->sizeline, &v->endian);
  v->pix_th[0] = 0;
  v->pix_th[1] = 0;
  v->pix_th[2] = 0;
  v->pix_th[3] = 0;
}

static int	gere_key(int keycode, t_var *var)
{
  if (keycode == 65307)
    exit(EXIT_SUCCESS);
  if (keycode == 's')
    convert_to_bmp(var);
  return (0);
}

static int	gere_expose(t_var *var)
{
  mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
  return (0);
}

static void	event(t_var *var)
{
  if (var != NULL)
    {
      mlx_expose_hook(var->win, gere_expose, var);
      mlx_key_hook(var->win, gere_key, var);
      mlx_loop(var->mlx);
    }
}

int		main(int ac, char **av)
{
  t_var		var;
  int		cren;
  int		fd;

  if (ac == 3 && comp(av[1], "-c") && check_bmp(av[2]))
    event(check_file(av[2]));
  else
    {
      x_init(&var);
      if ((fd = reduc_main(ac, av)) < 0)
	return (0);
      var.spot_list = NULL;
      if (fd == -1)
      	return (0);
      else
      	var.list = lex(&var.spot_list, fd, &var.item);
      parse(var.list, var.item);
      ((ac == 4 && comp(av[1], "-a")
	&& ((cren = atoi(av[2])) == 4 || cren == 9 || cren == 16)) ?
       (var.cren_val = cren) : (var.cren_val = 1));
      gere_thread(&var);
      event(&var);
    }
  return (0);
}
