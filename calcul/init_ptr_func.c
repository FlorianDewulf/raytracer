/*
** init_ptr_func.c for raytracer in /home/lund/svn/raytracer-2016-dewulf_f/calcul
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Jun  1 22:53:07 2012 florian dewulf
** Last update Fri Jun  1 22:57:32 2012 florian dewulf
*/

#include	"RT.h"

void		init_ptr_func(void (*calc_inter[])(t_var *, t_obj *))
{
  calc_inter[0] = &inter_plan;
  calc_inter[1] = &inter_sphere;
  calc_inter[2] = &inter_cyl;
  calc_inter[3] = &inter_cone;
  calc_inter[4] = &inter_prisme;
  calc_inter[5] = &inter_pyramide;
  calc_inter[6] = &inter_cube;
  calc_inter[7] = &inter_tore;
}
