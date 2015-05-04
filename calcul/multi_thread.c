/*
** multi_thread.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Wed May 30 18:59:23 2012 remi mailliet
** Last update Sat Jun  2 19:10:34 2012 florian dewulf
*/

#include	<mlx.h>
#include	<stdlib.h>
#include	<pthread.h>
#include	"RT.h"

static void	*filler_image_t1(void *var)
{
  int		x;
  int		y;
  t_var		tmp;
  t_var		*v;

  v = (t_var *)var;
  tmp = *((t_var *)var);
  tmp.list = copy_list(tmp.list, tmp.item);
  y = -1;
  while (++y < LEN_Y)
    {
      x = -1;
      while (++x < LEN_X / 4)
	{
	  parse_pix_multith(&tmp, (double)x, (double)y, v);
	  v->pix_th[0]++;
	}
    }
  return (0);
}

static void	*filler_image_t2(void *var)
{
  int		x;
  int		y;
  t_var		tmp;
  t_var		*v;

  v = (t_var *)var;
  tmp = *((t_var *)var);
  tmp.list = copy_list(tmp.list, tmp.item);
  y = -1;
  while (++y < LEN_Y)
    {
      x = (LEN_X / 4) - 1;
      while (++x < LEN_X / 2)
	{
	  parse_pix_multith(&tmp, (double)x, (double)y, v);
	  v->pix_th[1]++;
	}
    }
  return (0);
}

static void	*filler_image_t3(void *var)
{
  int		x;
  int		y;
  t_var		tmp;
  t_var		*v;

  v = (t_var *)var;
  tmp = *((t_var *)var);
  tmp.list = copy_list(tmp.list, tmp.item);
  y = -1;
  while (++y < LEN_Y)
    {
      x = (LEN_X / 2) - 1;
      while (++x < (LEN_X / 4) * 3)
	{
	  parse_pix_multith(&tmp, (double)x, (double)y, v);
	  v->pix_th[2]++;
	}
    }
  return (0);
}

static void	*filler_image_t4(void *var)
{
  int		x;
  int		y;
  t_var		tmp;
  t_var		*v;

  v = (t_var *)var;
  tmp = *((t_var *)var);
  tmp.list = copy_list(tmp.list, tmp.item);
  y = -1;
  while (++y < LEN_Y)
    {
      x = (LEN_X / 4) * 3 - 1;
      while (++x < LEN_X)
	{
	  parse_pix_multith(&tmp, (double)x, (double)y, v);
	  v->pix_th[3]++;
	}
    }
  return (0);
}

void		gere_thread(t_var *var)
{
  pthread_t	t1;
  pthread_t	t2;
  pthread_t	t3;
  pthread_t	t4;

  pthread_create(&t1, NULL, filler_image_t1, (void *)var);
  pthread_create(&t2, NULL, filler_image_t2, (void *)var);
  pthread_create(&t3, NULL, filler_image_t3, (void *)var);
  pthread_create(&t4, NULL, filler_image_t4, (void *)var);
  while (var->pix_th[0] + var->pix_th[1] + var->pix_th[2]
	 + var->pix_th[3] < (int)(LEN_X * LEN_Y))
    mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
}
