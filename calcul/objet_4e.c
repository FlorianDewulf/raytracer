/*
** objet_4e.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Thu May 31 18:24:34 2012 remi mailliet
** Last update Sat Jun  2 19:44:24 2012 florian dewulf
*/

#include	<math.h>
#include	"RT.h"

void		init_tore(t_var *v, t_obj *o, double a[])
{
  a[4] = pow(pow(v->v_dir[0], 2) + pow(v->v_dir[1], 2)
	     + pow(v->v_dir[2], 2), 2);
  a[3] = 4.0 * (pow(v->v_dir[0], 2)
		+ pow(v->v_dir[1], 2) + pow(v->v_dir[2], 2))
    * (v->v_dir[0] * v->oeil[0] + v->v_dir[1] * v->oeil[1]
       + v->v_dir[2] * v->oeil[2]);
  a[2] = 2.0 * (pow(v->v_dir[0], 2)
		+ pow(v->v_dir[1], 2) + pow(v->v_dir[2], 2))
    * (pow(v->oeil[0], 2) + pow(v->oeil[1], 2) + pow(v->oeil[2], 2)
       + pow(o->info[0], 2) - pow(o->info[1], 2))
    + pow(v->v_dir[0] * v->oeil[0] + v->v_dir[1] * v->oeil[1]
	  + v->v_dir[2] * v->oeil[2], 2) - 4.0 * pow(o->info[0], 2)
    * (pow(v->v_dir[0], 2) + pow(v->v_dir[2], 2));
  a[1] = 4.0 * (v->v_dir[0] * v->oeil[0] + v->v_dir[1] * v->oeil[1]
		+ v->v_dir[2] * v->oeil[2])
    * (pow(v->oeil[0], 2) + pow(v->oeil[1], 2) + pow(v->oeil[2], 2)
       + pow(o->info[0], 2) - pow(o->info[1], 2)) - 8.0 * pow(o->info[0], 2)
    * (v->v_dir[0] * v->oeil[0]
       + v->v_dir[2] * v->oeil[2]);
  a[0] = pow(pow(v->oeil[0], 2) + pow(v->oeil[1], 2) + pow(v->oeil[2], 2)
	     + pow(o->info[0], 2) - pow(o->info[1], 2), 2) -
    4.0 * pow(o->info[0], 2)
    * (pow(v->oeil[0], 2) + pow(v->oeil[2], 2));
}

void		inter_tore(t_var *v, t_obj *o)
{
  double	a[5];

  init_tore(v, o, a);
  if (a[4] == 0 && a[3] != 0)
    o->k = equation_3deg(a);
  else if (a[4] != 0)
    my_putstr("a != 0\n");
  else if (a[4] == 0 && a[3] == 0)
    my_putstr("a = 0 & b = 0\n");
}
