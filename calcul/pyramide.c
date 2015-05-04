/*
** pyramide.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Mon May 28 21:43:55 2012 remi mailliet
** Last update Sat Jun  2 19:39:19 2012 florian dewulf
*/

#include	<pthread.h>
#include	<math.h>
#include	"RT.h"

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

static void	init_pyramide(t_obj *o, double x[5], double y[5], double z[5])
{
  x[0] = o->pos_x;
  y[0] = o->pos_y;
  z[0] = o->pos_z;
  x[1] = o->pos_x;
  y[1] = o->pos_y + o->info[0];
  z[1] = o->pos_z;
  x[2] = o->pos_x + (o->info[0] / 2.0);
  y[2] = o->pos_y - (o->info[0] / 3.0);
  z[2] = o->pos_z;
  x[3] = (x[1] + x[2]) / 2.0;
  y[3] = (y[1] + y[2]) / 2.0;
  z[3] = o->pos_z + o->info[1];
  x[4] = x[0] + (x[2] - x[0]) + (x[1] - x[0]);
  y[4] = y[0] + (y[2] - y[0]) + (y[1] - y[0]);
  z[4] = z[0] + (z[2] - z[0]) + (z[1] - z[0]);
  o->x[0] = x[0];
  o->y[0] = y[0];
  o->z[0] = z[0];
  o->x[1] = x[1];
  o->y[1] = y[1];
  o->z[1] = z[1];
  o->x[2] = x[2];
  o->y[2] = y[2];
  o->z[2] = z[2];
}

static double	init_calc_pyramide(t_var *v, t_obj *o)
{
  double	ret;

  if ((ret = inter_para(v, o)) != 0)
    return (ret);
  return ((double)SAFE);
}

static void	swap_point_pyramide(t_obj *o, double x[],
				    double y[], double z[])
{
  static int	i;

  if (i == 0)
    {
      ((o->x[2] = x[3]) == x[3]) ? (o->y[2] = y[3]) : 1;
      ((o->z[2] = z[3]) == z[3]) ? (i += 1) : 1;
    }
  else if (i == 1)
    {
      ((o->x[0] = x[4]) == x[4]) ? (o->y[0] = y[4]) : 1;
      ((o->z[0] = z[4]) == z[4]) ? (i += 1): 1;
    }
  else if (i == 2)
    {
      ((o->x[1] = x[2]) == x[2]) ? (o->y[1] = y[2]) : 1;
      ((o->z[1] = z[2]) == z[2]) ? (i += 1) : 1;
    }
  else if (i == 3)
    {
      ((o->x[0] = x[0]) == x[0]) ? (o->y[0] = y[0]) : 1;
      ((o->z[0] = z[0]) == z[0]) ? (i = 0) : 1;
    }
}

void		inter_pyramide(t_var *v, t_obj *o)
{
  double	x[5];
  double	y[5];
  double	z[5];
  double	tmp;
  double	d;
  int		face;
  int		i;

  face = -1;
  i = 0;
  pthread_mutex_lock(&mutex);
  init_pyramide(o, x, y, z);
  ((d = init_calc_pyramide(v, o)) != SAFE) ? (face = 0) : 1;
  while (++i < 5)
    {
      swap_point_pyramide(o, x, y, z);
      if ((tmp = inter_triangle(v, o)) != 0 && tmp < d)
	{
	  d = tmp;
	  face = i;
	}
    }
  (face == -1) ? (o->k = 0) : (o->k = d);
  pthread_mutex_unlock(&mutex);
}
