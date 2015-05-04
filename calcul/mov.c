/*
** mov.c for RT in /home/grocko_t//Documents/programation/Igraph/RT/local/calcul
** 
** Made by thomas grockowiak
** Login   <grocko_t@epitech.net>
** 
** Started on  Tue May 29 19:21:12 2012 thomas grockowiak
** Last update Sun Jun  3 22:34:37 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"RT.h"

void		mov(void (*calc_inter[])(t_var*, t_obj*), t_var *v, int a)
{
  int		i;
  double	save[3];

  i = -1;
  if (a == 0)
    while (++i < v->item)
      {
	mov1(v, &(v->list[i]), save);
	rotation(-1, v, &(v->list[i]), NULL);
	rotation(-2, v, &(v->list[i]), NULL);
	(calc_inter[v->list[i].type])(v, &v->list[i]);
	rotation(2, v, &(v->list[i]), NULL);
	rotation(1, v, &(v->list[i]), NULL);
	mov2(v, &(v->list[i]), save);
      }
  else
    while (++i < v->item)
      {
	mov1(v, &(v->list[i]), save);
	if (a == 0 || (a != 0 && a != i))
	  (calc_inter[v->list[i].type])(v, &v->list[i]);
	mov2(v, &(v->list[i]), save);
      }
}
