/*
** calc.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Wed May 16 12:53:40 2012 remi mailliet
** Last update Mon Jun  4 14:49:45 2012 florian dewulf
*/

#include	<math.h>
#include	<stdlib.h>
#include	"RT.h"

static void	init_val(t_var *v, double x, double y)
{
  v->oeil[0] = (double)X_OEIL;
  v->oeil[1] = (double)Y_OEIL;
  v->oeil[2] = (double)Z_OEIL;
  v->rot_oeil[0] = ANG_OEILX;
  v->rot_oeil[1] = ANG_OEILY;
  v->rot_oeil[2] = ANG_OEILZ;
  v->v_dir[0] = (double)((LEN_X / 2) / tan((50.0 * M_PI) / 180.0));
  v->v_dir[1] = ((LEN_X / 2) - x);
  v->v_dir[2] = ((LEN_Y / 2) - y);
}

int		which_k(t_var *v)
{
  int		i;
  int		ret;
  double	tmp;

  i = 0;
  ret = -1;
  (v->list[i].k > 0) ? (tmp = v->list[i].k) : (tmp = SAFE);
  if (tmp != SAFE)
    ret = 0;
  while (++i < v->item)
    if (v->list[i].k > 0 && v->list[i].k < tmp)
      {
	ret = i;
	tmp = v->list[i].k;
      }
  return (ret);
}

static int	calc(t_var *v, double x, double y)
{
  int		i;
  void		(*calc_inter[OB_TYPE])(t_var*, t_obj*);
  int		color;

  init_ptr_func(calc_inter);
  color = 0;
  init_val(v, x, y);
  rotationoeil(v, 0);
  mov(calc_inter, v, 0);
  i = which_k(v);
  if (i != -1)
    {
      if (v->spot_list != NULL)
  	color = ambiance(v);
      else
  	color = v->list[i].color;
    }
  rotationoeil(v, 1);
  return ((i == -1) ? 0 : color);
}

static int	calc_aliasing(int pix[], int cren)
{
  int	 	tmp_r;
  int		tmp_g;
  int		tmp_b;
  int		r;
  int		g;
  int		b;
  int		i;

  i = -1;
  r = 0;
  g = 0;
  b = 0;
  while (++i < (cren * cren))
    {
      hex_to_rgb(pix[i], &tmp_r, &tmp_g, &tmp_b);
      r += tmp_r;
      g += tmp_g;
      b += tmp_b;
    }
  r /= (cren * cren);
  g /= (cren * cren);
  b /= (cren * cren);
  return (rgb_to_hex(r, g, b));
}

void		parse_pix_multith(t_var *var, double x, double y, t_var *data)
{
  int		pix[var->cren_val];
  double	i;
  double	j;
  int		l;
  int		cren;

  i = -1;
  l = -1;
  cren = (int)pow(var->cren_val, 0.5);
  while (++i < cren)
    {
      j = -1;
      while (++j < cren)
	pix[++l] = calc(var, (x + j / (double)cren), (y + i / (double)cren));
    }
  my_pixel_put(data, (int)x, (int)y, calc_aliasing(pix, cren));
}
