/*
** copy_list.c for raytracer in /home/seth/raytracer-2016-dewulf_f/calcul
** 
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
** 
** Started on  Thu May 31 14:55:28 2012 kevin lansel
** Last update Fri Jun  1 13:55:12 2012 florian dewulf
*/

#include	"RT.h"

static void	copy_tab(t_obj obj, t_obj *copy)
{
  copy->type = obj.type;
  copy->color = obj.color;
  copy->info[0] = obj.info[0];
  copy->info[1] = obj.info[1];
  copy->brill = obj.brill;
  copy->pos_x = obj.pos_x;
  copy->pos_y = obj.pos_y;
  copy->pos_z = obj.pos_z;
  copy->rot_x = obj.rot_x;
  copy->rot_y = obj.rot_y;
  copy->rot_z = obj.rot_z;
  copy->k = 0;
}

t_obj		*copy_list(t_obj *obj, int limit)
{
  t_obj		*copy;
  int		curse;

  copy = xmalloc(sizeof(t_obj) * limit);
  curse = 0;
  while (curse < limit)
    {
      copy_tab(obj[curse], &(copy[curse]));
      curse++;
    }
  return (copy);
}
