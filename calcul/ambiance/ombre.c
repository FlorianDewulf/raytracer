/*
** ombre.c for RT in /home/grocko_t//Documents/programation/Igraph/RT/local/calcul/ambiance
** 
** Made by thomas grockowiak
** Login   <grocko_t@epitech.net>
** 
** Started on  Tue May 29 17:42:08 2012 thomas grockowiak
** Last update Sun Jun  3 23:20:05 2012 florian dewulf
*/

#include	<time.h>
#include	<stdlib.h>
#include	"../RT.h"

int		ombre(t_var *v, double v_lum[3], t_spot *spot, int i)
{
  double	oeil[3];
  double	v_dir[3];
  int		a;
  void		(*calc_inter[OB_TYPE])(t_var*, t_obj*);

  init_ptr_func(calc_inter);
  modify(oeil, v_dir, v, 0);
  v->oeil[0] = spot->x;
  v->oeil[1] = spot->y;
  v->oeil[2] = spot->z;
  v->v_dir[0] = -v_lum[0];
  v->v_dir[1] = -v_lum[1];
  v->v_dir[2] = -v_lum[2];
  mov(calc_inter, v, i);
  modify(oeil, v_dir, v, 1);
  a = -1;
  while (++a < v->item)
    if (v->list[a].k > 0.00001 && v->list[a].k < 1 &&
	v->list[i].k > v->list[a].k && a != i)
      return (1);
  return (0);
}

static void	init_ombre(int *save_x, int *save_y, int *save_z, t_spot *s)
{
  *save_x = s->x;
  *save_y = s->y;
  *save_z = s->z;
  s->x = *save_x - 55.0;
  s->y = *save_y - 55.0;
  s->z = *save_z - 55.0;
}

double		f_ombre(t_var *v, double v_lum[3], t_spot *s, int i)
{
  int		master;
  int		total;
  double	x_max;
  int		nb_omb;
  int		save_x;
  int		save_y;
  int		save_z;

  (total = 0) ? (master = 0) : (master = 0);
  init_ombre(&save_x, &save_y, &save_z, s);
  x_max = 55.0;
  nb_omb = 50;
  srand(time(NULL));
  while (master < (2 *x_max))
    {
      s->x = s->x + (x_max / nb_omb);
      s->x = s->y + (x_max / nb_omb);
      s->x = s->z + (x_max / nb_omb);
      total = total + ombre(v, v_lum, s, i);
      master = master + (x_max / nb_omb);
    }
  s->x = save_x;
  s->y = save_y;
  s->z = save_z;
  return ((total > 10) ? (total * (0.1 / (total / 10))) : (total * 0.1));
}
