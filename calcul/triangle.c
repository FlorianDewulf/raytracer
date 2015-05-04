/*
** triangle.c for RT in /home/mailli_r//Documents/Igraph/RT/calcul
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Fri Jun  1 16:12:16 2012 remi mailliet
** Last update Fri Jun  1 16:12:47 2012 remi mailliet
*/

#include	"RT.h"

double		vect_triangle(t_var *v, t_obj *o, double *a, double *b)
{
  double	x[2];
  double	y[2];
  double	z[2];
  double	d;

  x[0] = o->x[1] - o->x[0];
  y[0] = o->y[1] - o->y[0];
  z[0] = o->z[1] - o->z[0];
  x[1] = o->x[2] - o->x[0];
  y[1] = o->y[2] - o->y[0];
  z[1] = o->z[2] - o->z[0];
  d = - ((y[0] * z[1] - z[0] * y[1]) * v->v_dir[0]
	 + (z[0] * x[1] - x[0] * z[1]) * v->v_dir[1]
	 + (x[0] * y[1] - y[0] * x[1]) * v->v_dir[2]);
  *a = - (((v->oeil[1] - o->y[0]) * z[1] - (v->oeil[2] - o->z[0])
	   * y[1]) * v->v_dir[0] + ((v->oeil[2] - o->z[0]) * x[1]
				    - (v->oeil[0] - o->x[0]) * z[1]) * v->v_dir[1]
	  + ((v->oeil[0] - o->x[0]) * y[1] - (v->oeil[1] - o->y[0])
	     * x[1]) * v->v_dir[2]) / d;
  *b = - ((y[0] * (v->oeil[2] - o->z[0]) - z[0] * (v->oeil[1] - o->y[0]))
	  * v->v_dir[0] + (z[0] * (v->oeil[0] - o->x[0]) - x[0]
			   * (v->oeil[2] - o->z[0])) * v->v_dir[1]
	  + (x[0] * (v->oeil[1] - o->y[0]) - y[0]
	     * (v->oeil[0] - o->x[0])) * v->v_dir[2]) / d;
  return (d);
}

double		inter_triangle(t_var *v, t_obj *o)
{
  double	a;
  double	b;
  double	d;

  d = vect_triangle(v, o, &a, &b);
  if (a > 0 && b > 0 && (a + b) <= 1)
    return ((((o->y[1] - o->y[0]) * (o->z[2] - o->z[0])
	      - (o->z[1] - o->z[0]) * (o->y[2] - o->y[0]))
	     * (v->oeil[0] - o->x[0])
	     + ((o->z[1] - o->z[0]) * (o->x[2] - o->x[0])
		- (o->x[1] - o->x[0]) * (o->z[2] - o->z[0]))
	     * (v->oeil[1] - o->y[0])
	     + ((o->x[1] - o->x[0]) * (o->y[2] - o->y[0])
		- (o->y[1] - o->y[0]) * (o->x[2] - o->x[0]))
	     * (v->oeil[2] - o->z[0])) / d);
  return (0);
}

double		inter_para(t_var *v, t_obj *o)
{
  double	a;
  double	b;
  double	d;

  d = vect_triangle(v, o, &a, &b);
  if (a > 0 && b > 0 && a <= 1 && b <= 1)
    return ((((o->y[1] - o->y[0]) * (o->z[2] - o->z[0])
	      - (o->z[1] - o->z[0]) * (o->y[2] - o->y[0]))
	     * (v->oeil[0] - o->x[0])
	     + ((o->z[1] - o->z[0]) * (o->x[2] - o->x[0])
		- (o->x[1] - o->x[0]) * (o->z[2] - o->z[0]))
	     * (v->oeil[1] - o->y[0])
	     + ((o->x[1] - o->x[0]) * (o->y[2] - o->y[0])
		- (o->y[1] - o->y[0]) * (o->x[2] - o->x[0]))
	     * (v->oeil[2] - o->z[0])) / d);
  return (0);
}
