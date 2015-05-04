/*
** lumen.c for RT in /home/grocko_t//Documents/programation/Igraph/RT/local/calcul/ambiance
** 
** Made by thomas grockowiak
** Login   <grocko_t@epitech.net>
** 
** Started on  Tue May 29 17:49:16 2012 thomas grockowiak
** Last update Sun Jun  3 23:19:25 2012 florian dewulf
*/

#include	<stdlib.h>
#include	<math.h>
#include	"../RT.h"

int		brillance(t_spot *spot, double brill, int s_old, int i)
{
  int	s_color[3];
  int	ret;

  hex_to_rgb(spot->color, &s_color[0], &s_color[1], &s_color[2]);
  if (i == 0)
    ret = s_old * (1 - brill ) + (s_color[0] * brill);
  if (i == 1)
    ret = s_old * (1 - brill ) + (s_color[1] * brill);
  if (i == 2)
    ret = s_old * (1 - brill ) + (s_color[2] * brill);
  return (ret);
}

static void	return_normal(t_var *v, double *normal, double *save2, int i)
{
  rotation(3, v, &(v->list[i]), normal);
  rotation(3, v, &(v->list[i]), save2);
  rotation(2, v, &(v->list[i]), NULL);
  rotation(1, v, &(v->list[i]), NULL);
}

static void	reduc_cos(t_var *v, t_spot *spot, double *p_inter,
			  double *v_lum)
{
  double	save[3];
  double	save2[3];
  double	normal[3];
  int		i;
  void		(*calc_inter[OB_TYPE])(t_var *, t_obj *);

  init_ptr_func(calc_inter);
  i = which_k(v);
  mov1(v, &v->list[i], save);
  rotation(-1, v, &(v->list[i]), NULL);
  rotation(-2, v, &(v->list[i]), NULL);
  save2[0] = spot->x - v->list[i].pos_x;
  save2[1] = spot->y - v->list[i].pos_y;
  save2[2] = spot->z - v->list[i].pos_z;
  rotation(-3, v, &(v->list[i]), save2);
  inter(p_inter, v->oeil, v->v_dir, v->list[i].k);
  take_normal(v->list[i].type, normal, p_inter);
  v_lum[0] = save2[0] - p_inter[0];
  v_lum[1] = save2[1] - p_inter[1];
  v_lum[2] = save2[2] - p_inter[2];
  v_lum[3] = normal[0] * v_lum[0] + normal[1]
    * v_lum[1] + normal[2] * v_lum[2];
  v_lum[3] = v_lum[3] / (norme(normal) * norme(v_lum));
  mov2(v, &v->list[i], save);
  return_normal(v, normal, save2, i);
}

void		lumen(t_var *v, t_spot *spot,
		      double p_inter[3], int color[3])
{
  int		omb;
  double	cos;
  int		i;
  double	v_lum[4];
  int		col[3];
  void		(*calc_inter[OB_TYPE])(t_var *, t_obj *);

  init_ptr_func(calc_inter);
  reduc_cos(v, spot, p_inter, v_lum);
  i = which_k(v);
  cos = v_lum[3];
  omb = ombre(v, v_lum, spot, i);
  if (omb == 1)
    cos = cos * 0.75;
  mov(calc_inter, v, 0);
  i = which_k(v);
  (cos < 0) ? (cos = 0) : 1;
  hex_to_rgb(v->list[i].color, &col[0], &col[1], &col[2]);
  color[0] = (color[0] + brillance(spot, v->list[i].brill, col[0], 0) * cos);
  color[1] = (color[1] + brillance(spot, v->list[i].brill, col[1], 1) * cos);
  color[2] = (color[2] + brillance(spot, v->list[i].brill, col[2], 2) * cos);
  if (spot->next != NULL)
    lumen(v, spot->next, p_inter, color);
}
