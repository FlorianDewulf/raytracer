/*
** cube.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Tue May 29 17:57:49 2012 remi mailliet
** Last update Sat Jun  2 19:16:40 2012 florian dewulf
*/

#include	<pthread.h>
#include	<math.h>
#include	"RT.h"

pthread_mutex_t	mutex3 = PTHREAD_MUTEX_INITIALIZER;

static void	init_cube(t_obj *o, double x[], double y[], double z[])
{
  x[0] = o->info[0] / 2.0;
  y[0] = o->info[0] / 2.0;
  z[0] = - (o->info[0] / 2.0);
  x[1] = o->info[0] / 2.0;
  y[1] = o->info[0] / 2.0;
  z[1] = o->info[0] / 2.0;
  x[2] = o->info[0] / 2.0;
  y[2] = - (o->info[0] / 2.0);
  z[2] = o->info[0] / 2.0;
  x[3] = o->info[0] / 2.0;
  y[3] = - (o->info[0] / 2.0);
  z[3] = - (o->info[0] / 2.0);
  x[4] = - (o->info[0] / 2.0);
  y[4] = - (o->info[0] / 2.0);
  z[4] = - (o->info[0] / 2.0);
  x[5] = - (o->info[0] / 2.0);
  y[5] = o->info[0] / 2.0;
  z[5] = - (o->info[0] / 2.0);
  x[6] = - (o->info[0] / 2.0);
  y[6] = o->info[0] / 2.0;
  z[6] = o->info[0] / 2.0;
  x[7] = - (o->info[0] / 2.0);
  y[7] = - (o->info[0] / 2.0);
  z[7] = o->info[0] / 2.0;
}

static void	swap_point_cube(t_obj *o, double x[], double y[], double z[])
{
  static int	i;

  if (i == 0)
    {
      ((o->x[0] = x[0]) == x[0]) ? (o->y[0] = y[0]) : 1;
      ((o->z[0] = z[0]) == z[0]) ? (o->x[1] = x[1]) : 1;
      ((o->y[1] = y[1]) == y[1]) ? (o->z[1] = z[1]) : 1;
      ((o->x[2] = x[3]) == x[3]) ? (o->y[2] = y[3]) : 1;
      ((o->z[2] = z[3]) == z[3]) ? (i += 1) : 1;
    }
  else if (i == 1)
    {
      ((o->x[2] = x[5]) == x[5]) ? (o->y[2] = y[5]) : 1;
      ((o->z[2] = z[5]) == z[5]) ? (i += 1) : 1;
    }
  else if (i == 2)
    {
      ((o->x[0] = x[3]) == x[3]) ? (o->y[0] = y[3]) : 1;
      ((o->z[0] = z[3]) == z[3]) ? (o->x[1] = x[4]) : 1;
      ((o->y[1] = y[4]) == y[4]) ? (o->z[1] = z[4]) : 1;
      ((o->x[2] = x[0]) == x[0]) ? (o->y[2] = y[0]) : 1;
      o->z[2] = z[0];
      i = 0;
    }
}

static void	swap_point_cube_bis(t_obj *o, double x[],
				    double y[], double z[])
{
  static int	i;

  if (i == 0)
    {
      ((o->x[0] = x[2]) == x[2]) ? (o->y[0] = y[2]) : 1;
      ((o->z[0] = z[2]) == z[2]) ? (o->x[1] = x[7]) : 1;
      ((o->y[1] = y[7]) == y[7]) ? (o->z[1] = z[7]) : 1;
      ((o->x[2] = x[3]) == x[3]) ? (o->y[2] = y[3]) : 1;
      ((o->z[2] = z[3]) == z[3]) ? (i += 1) : 1;
    }
  else if (i == 1)
    {
      ((o->x[0] = x[1]) == x[1]) ? (o->y[0] = y[1]) : 1;
      ((o->z[0] = z[1]) == z[1]) ? (o->x[1] = x[6]) : 1;
      ((o->y[1] = y[6]) == y[6]) ? (o->z[1] = z[6]) : 1;
      ((o->x[2] = x[2]) == x[2]) ? (o->y[2] = y[2]) : 1;
      ((o->z[2] = z[2]) == z[2]) ? (i += 1) : 1;
    }
  else if (i == 2)
    {
      ((o->x[0] = x[5]) == x[5]) ? (o->x[2] = x[4]) : 1;
      ((o->y[0] = y[5]) == y[5]) ? (o->y[2] = y[4]) : 1;
      ((o->z[0] = z[5]) == z[5]) ? (o->z[2] = z[4]) : 1;
      i = 0;
    }
}

void		inter_cube(t_var *v, t_obj *o)
{
  double	x[8];
  double	y[8];
  double	z[8];
  double	tmp;
  double	d;
  int		face;
  int		i;

  face = -1;
  d = SAFE;
  i = -1;
  pthread_mutex_lock(&mutex3);
  init_cube(o, x, y, z);
  while (++i < 6)
    {
      if (i < 3)
	swap_point_cube(o, x, y, z);
      else if (i >= 3)
	swap_point_cube_bis(o, x, y, z);
      if ((tmp = inter_para(v, o)) != 0 && tmp < d)
	d = (face = i) ? tmp : tmp;
    }
  pthread_mutex_unlock(&mutex3);
  (face == -1) ? (o->k = 0) : (o->k = d);
}
