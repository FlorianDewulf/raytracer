/*
** lex_list.c for lex_list in /home/lund/svn/RAY/lex
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu May 31 00:58:49 2012 florian dewulf
** Last update Fri Jun  1 16:10:53 2012 remi mailliet
*/

#include	<stdlib.h>
#include	"../gtk/menurt.h"
#include	"RT.h"

void		put_in_spot_list(t_spot **lum, t_object *list)
{
  t_spot	*elem;
  t_spot	*tmp;

  elem = xmalloc(sizeof(t_spot));
  elem->x = list->x;
  elem->y = list->y;
  elem->z = list->z;
  elem->type = 0;
  elem->rot_x = list->rot_x;
  elem->rot_y = list->rot_y;
  elem->rot_z = list->rot_z;
  elem->color = list->red * 65536 + list->green * 256 + list->blue;
  elem->power = (double)(list->brill) / 100;
  elem->next = NULL;
  elem->prev = NULL;
  if ((*lum) == NULL)
    (*lum) = elem;
  else
    {
      tmp = *lum;
      while (tmp->next)
        tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
}

void		add_to_object_list(t_object **list, t_object *elem)
{
  t_object	*tmp;

  tmp = *list;
  if (tmp == NULL)
    *list = elem;
  else
    {
      while (tmp->next)
        tmp = tmp->next;
      tmp->next = elem;
    }
}
