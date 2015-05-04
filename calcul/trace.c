/*
** trace.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Wed May 16 14:54:50 2012 remi mailliet
** Last update Fri Jun  1 15:56:19 2012 remi mailliet
*/

#include	"RT.h"

int		rgb_to_hex(int r, int g, int b)
{
  int		color;

  color = r;
  color = color << 8;
  color += g;
  color = color << 8;
  color += b;
  return (color);
}

void		hex_to_rgb(int color, int *r, int *g, int *b)
{
  *b = color & 0xFF;
  color = color >> 8;
  *g = color & 0xFF;
  color = color >> 8;
  *r = color & 0xFF;
}

void		my_pixel_put(t_var *var, int x, int y, int color)
{
  int		i;
  int		r;
  int		g;
  int		b;

  i = var->sizeline * y + x * 4;
  hex_to_rgb(color, &r, &g, &b);
  if (!(x < 0 || x > LEN_X) && !(y < 0 || y > LEN_Y))
      {
	var->data[i] = b;
	var->data[i + 1] = g;
	var->data[i + 2] = r;
	var->data[i + 3] = 0;
      }
}
