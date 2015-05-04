/*
** inter.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Wed May 16 17:32:33 2012 remi mailliet
** Last update Fri Jun  1 16:12:48 2012 remi mailliet
*/

#include	<math.h>
#include	"RT.h"

void		inter_plan(t_var *v, t_obj *o)
{
  o->k = - (v->oeil[2] / v->v_dir[2]);
  if (o->k >= 0)
    return;
  else
    o->k = 0;
}

double		k_secdegre(double a, double b, double d)
{
  double	k1;
  double	k2;

  k1 = (-b - pow(d, 0.5)) / (2.0 * a);
  k2 = (-b + pow(d, 0.5)) / (2.0 * a);
  if (k1 > 0 && k1 < k2)
    return (k1);
  return (k2);
}

void		inter_sphere(t_var *v, t_obj *o)
{
  double	a;
  double	b;
  double	c;
  double	d;

  a = pow(v->v_dir[0], 2) + pow(v->v_dir[1], 2) + pow(v->v_dir[2], 2);
  b = 2.0 * ((v->oeil[0] * v->v_dir[0]) + (v->oeil[1] * v->v_dir[1])
	     + (v->oeil[2] * v->v_dir[2]));
  c = pow(v->oeil[0], 2) + pow(v->oeil[1], 2) + pow(v->oeil[2], 2)
    - pow(o->info[0], 2);
  d = pow(b, 2) - (4.0 * a * c);
  if (d >= 0)
    {
      if (d == 0)
	o->k = (-b) / (2.0 * a);
      else
      	o->k = k_secdegre(a, b, d);
    }
  else
    o->k = 0;
}

void		inter_cyl(t_var *v, t_obj *o)
{
  double	a;
  double	b;
  double	c;
  double	d;

  a = pow(v->v_dir[0], 2) + pow(v->v_dir[1], 2);
  b = 2.0 * ((v->oeil[0] * v->v_dir[0]) + (v->oeil[1] * v->v_dir[1]));
  c = pow(v->oeil[0], 2) + pow(v->oeil[1], 2) - pow(o->info[0], 2);
  d = pow(b, 2) - (4.0 * a * c);
  if (d >= 0)
    {
      if (d == 0)
	o->k = (-b) / (2.0 * a);
      else
	o->k = k_secdegre(a, b, d);
    }
  else
    o->k = 0;
}

void		inter_cone(t_var *v, t_obj *o)
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	rad;

  rad = (o->info[0] * M_PI) / 180.0;
  rad = pow(tan(rad), 2);
  a = pow(v->v_dir[0], 2) + pow(v->v_dir[1], 2) - (pow(v->v_dir[2], 2) * rad);
  b = 2.0 * ((v->oeil[0] * v->v_dir[0]) + (v->oeil[1] * v->v_dir[1])
	     - ((v->oeil[2] * v->v_dir[2]) * rad));
  c = pow(v->oeil[0], 2) + pow(v->oeil[1], 2) - (pow(v->oeil[2], 2) * rad);
  d = pow(b, 2) - (4.0 * a * c);
  if (d >= 0)
    {
      if (d == 0)
	o->k = (-b) / (2.0 * a);
      else
	o->k = k_secdegre(a, b, d);
    }
  else
    o->k = 0;
}
