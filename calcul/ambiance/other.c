/*
** other.c for RT in /home/grocko_t//Documents/programation/Igraph/RT/local/calcul/ambiance
** 
** Made by thomas grockowiak
** Login   <grocko_t@epitech.net>
** 
** Started on  Tue May 29 17:55:27 2012 thomas grockowiak
** Last update Tue May 29 18:00:20 2012 thomas grockowiak
*/

#include <math.h>
#include <stdlib.h>
#include "../RT.h"

double	norme(double vec[3])
{
  double	result;

  result = pow(vec[0], 2.0) + pow(vec[1], 2.0) + pow(vec[2], 2.0);
  result = pow(result, 0.5);
  return (result);
}

int	len_spot(t_spot *spot)
{
  t_spot	*tmp;
  int	len;

  len = 0;
  tmp = spot;
  while (tmp->prev != NULL)
    tmp = tmp->prev;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
      len++;
    }
  return (len);
}

void	inter(double p_inter[3], double oeil[3], double v_dir[3], double k)
{
  p_inter[0] = oeil[0] + (k * v_dir[0]);
  p_inter[1] = oeil[1] + (k * v_dir[1]);
  p_inter[2] = oeil[2] + (k * v_dir[2]);
}
