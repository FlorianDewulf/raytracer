/*
** prisme.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Mon May 28 20:52:21 2012 remi mailliet
** Last update Fri Jun  1 20:03:51 2012 remi mailliet
*/

#include	<pthread.h>
#include	<math.h>
#include	"RT.h"

pthread_mutex_t	mutex2 = PTHREAD_MUTEX_INITIALIZER;

static void	init_prisme(t_obj *o, double x[], double y[], double z[])
{
  x[0] = o->pos_x;
  y[0] = o->pos_y;
  z[0] = o->pos_z;
  x[1] = o->pos_x - (o->info[1] / 2.0);
  y[1] = o->pos_y;
  z[1] = o->pos_z + (o->info[1] * 0.75);
  x[2] = o->pos_x - ((o->info[0] * pow(3, 0.5) / 2.0) / 2.0);
  y[2] = o->pos_y - (o->info[0] / 2.0);
  z[2] = o->pos_z + o->info[1];
  x[3] = o->pos_x - ((o->info[0] * pow(3, 0.5) / 2.0) / 2.0);
  y[3] = o->pos_y + (o->info[0] / 2.0);
  z[3] = o->pos_z + o->info[1];
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

static void	swap_point_prisme(t_obj *o, double x[],
				  double y[], double z[])
{
  static int	i = 1;

  if (i == 1)
    {
      o->x[2] = x[3];
      o->y[2] = y[3];
      o->z[2] = z[3];
      i++;
    }
  else if (i == 2)
    {
      o->x[1] = x[2];
      o->y[1] = y[2];
      o->z[1] = z[2];
      i++;
    }
  else if (i == 3)
    {
      o->x[0] = x[1];
      o->y[0] = y[1];
      o->z[0] = z[1];
      i = 1;
    }
}

void		inter_prisme(t_var *v, t_obj *o)
{
  double	x[4];
  double	y[4];
  double	z[4];
  double	tmp;
  double	d;
  int		face;
  int		i;

  face = -1;
  d = SAFE;
  i = -1;
  pthread_mutex_lock(&mutex2);
  init_prisme(o, x, y, z);
  while (++i < 4)
    {
      if (i != 0)
	swap_point_prisme(o, x, y, z);
      if ((tmp = inter_triangle(v, o)) != 0 && tmp < d)
	{
	  d = tmp;
	  face = i;
	}
    }
  (face == -1) ? (o->k = 0) : (o->k = d);
  pthread_mutex_unlock(&mutex2);
}
