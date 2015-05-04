/*
** lex.c for raytracer in /home/lund/svn/RAY/lex
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue May 29 16:10:42 2012 florian dewulf
** Last update Fri Jun  1 16:09:37 2012 remi mailliet
*/

#include	<stdlib.h>
#include	"../gtk/menurt.h"
#include	"RT.h"

void                            put_in_spot_list(t_spot **, t_object *);
void                            add_to_object_list(t_object **, t_object *);

static t_obj	put_in_tab(t_object *item)
{
  t_obj		obj;

  obj.type = item->type;
  obj.color = item->red * 65536 + item->green * 256 + item->blue;
  obj.info[0] = (double)(item->info[0]);
  obj.info[1] = (double)(item->info[1]);
  obj.brill = (double)(item->brill / 100);
  obj.pos_x = (double)(item->x);
  obj.pos_y = (double)(item->y);
  obj.pos_z = (double)(item->z);
  obj.rot_x = (double)(item->rot_x);
  obj.rot_y = (double)(item->rot_y);
  obj.rot_z = (double)(item->rot_z);
  obj.k = 0;
  return (obj);
}

static t_object	*make_list(int fd)
{
  int		ret;
  t_object	*elem;
  t_object	*list;

  ret = 1;
  list = NULL;
  while (ret)
    {
      elem = xmalloc(sizeof(t_object));
      if ((ret = read(fd, elem, 15 * sizeof(int))) <= 0)
	return (list);
      if (ret < (int)(15 * sizeof(int)))
	{
	  my_putstr("Your file is strange\n");
	  exit(EXIT_FAILURE);
	}
      elem->next = NULL;
      add_to_object_list(&list, elem);
    }
  return (list);
}

static void	mini_lex(t_spot **lum, t_object *tmp, t_obj **tab, int count)
{
  t_spot	*tmp_lum;
  t_obj		*tmp_tab;
  t_object	*list;

  tmp_lum = *lum;
  tmp_tab = *tab;
  list = tmp;
  while (count > 0)
    {
      if (list->type < 0)
	{
	  put_in_spot_list(&tmp_lum, list);
	  count--;
	}
      list = list->next;
    }
  list = tmp;
  while (list)
    {
      if (list->type >= 0)
	tmp_tab[count++] = put_in_tab(list);
      list = list->next;
    }
  *lum = tmp_lum;
  *tab = tmp_tab;
}

t_obj		*lex(t_spot **lum, int fd, int *item)
{
  t_obj		*tab;
  t_object	*tmp;
  t_object	*list;
  t_spot	*tmp_lum;
  int		limit;
  int		count;

  (limit = 0) ? (count = 0) : (count = 0);
  (tmp_lum = *lum) ? (list = make_list(fd)) : (list = make_list(fd));
  tmp = list;
  while (list)
    {
      if (list->type < 0)
	count++;
      limit++;
      list = list->next;
    }
  (limit -= count) ? (list = tmp) : (list = tmp);
  if (limit == 0)
    return (NULL);
  tab = xmalloc(limit * sizeof(t_obj));
  *item = limit;
  mini_lex(&tmp_lum, tmp, &tab, count);
  *lum = tmp_lum;
  return (tab);
}
