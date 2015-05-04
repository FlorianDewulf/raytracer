/*
** core.c for rtv1 in /home/grocko_t//Documents/programation/Igraph/rtv1/tp
** 
** Made by thomas grockowiak
** Login   <grocko_t@epitech.net>
** 
** Started on  Mon Feb  6 11:20:44 2012 thomas grockowiak
** Last update Sat Jun  2 20:55:38 2012 florian dewulf
*/

#include	"RT.h"

void		mov1(t_var *var, t_obj *obj, double *tempo)
{
  var->oeil[0] = var->oeil[0] - obj->pos_x;
  var->oeil[1] = var->oeil[1] - obj->pos_y;
  var->oeil[2] = var->oeil[2] - obj->pos_z;
  tempo[0] = obj->pos_x;
  tempo[1] = obj->pos_y;
  tempo[2] = obj->pos_z;
  obj->pos_x = 0;
  obj->pos_y = 0;
  obj->pos_z = 0;
}

void		mov2(t_var *var, t_obj *obj, double *tempo)
{
  obj->pos_x = tempo[0];
  obj->pos_y = tempo[1];
  obj->pos_z = tempo[2];
  var->oeil[0] = var->oeil[0] + obj->pos_x;
  var->oeil[1] = var->oeil[1] + obj->pos_y;
  var->oeil[2] = var->oeil[2] + obj->pos_z;
}
