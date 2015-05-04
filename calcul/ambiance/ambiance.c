/*
** ambiance.c for RT in /home/grocko_t//Documents/programation/Igraph/RT/local/calcul
** 
** Made by thomas grockowiak
** Login   <grocko_t@epitech.net>
** 
** Started on  Thu May 24 11:45:19 2012 thomas grockowiak
** Last update Sun Jun  3 23:07:11 2012 florian dewulf
*/

#include <math.h>
#include <stdlib.h>
#include "../RT.h"

void	take_normal(int type, double normal[3], double p_inter[3])
{
  if (type == 0)
    {
      normal[0] = 0;
      normal[1] = 0;
      normal[2] = 100;
    }
  else if (type == 1)
    {
      normal[0] = p_inter[0];
      normal[1] = p_inter[1];
      normal[2] = p_inter[2];
    }
  else if (type == 2)
    {
      normal[0] = p_inter[0];
      normal[1] = p_inter[1];
      normal[2] = 0;
    }
  else if (type == 3)
    {
      normal[0] = p_inter[0];
      normal[1] = p_inter[1];
      normal[2] = -0.5 * p_inter[2];
    }
}

void	modify(double oeil[3], double v_dir[3], t_var *v, int m)
{
  if (m == 0)
    {
      oeil[0] = v->oeil[0];
      oeil[1] = v->oeil[1];
      oeil[2] = v->oeil[2];
      v_dir[0] = v->v_dir[0];
      v_dir[1] = v->v_dir[1];
      v_dir[2] = v->v_dir[2];
    }
  else
    {
      v->oeil[0] = oeil[0];
      v->oeil[1] = oeil[1];
      v->oeil[2] = oeil[2];
      v->v_dir[0] = v_dir[0];
      v->v_dir[1] = v_dir[1];
      v->v_dir[2] = v_dir[2];
    }
}

int	ambiance(t_var *v)
{
  t_spot	*tmp;
  double	p_inter[3];
  int		color[3];

  color[0] = 0;
  color[1] = 0;
  color[2] = 0;
  tmp = v->spot_list;
  lumen(v, tmp, p_inter, color);
  color[0] = color[0] / 1;
  color[1] = color[1] / 1;
  color[2] = color[2] / 1;
  return (rgb_to_hex(color[0], color[1], color[2]));
}
