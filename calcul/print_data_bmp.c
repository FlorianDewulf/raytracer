/*
** print_data_bmp.c for raytracer in /home/lund/svn/raytracer-2016-dewulf_f
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Thu May 24 13:41:35 2012 florian dewulf
** Last update Fri May 25 22:28:00 2012 florian dewulf
*/

#include	<unistd.h>
#include	"RT.h"

void		print_data_bmp(t_var *ml, int fd)
{
  int		begin;
  int		y;
  int		y1;
  int		tmp;

  y = LEN_Y - 1;
  while (y >= 0)
    {
      y1 = y + 1;
      begin = y * LEN_X * 4;
      while (begin < y1 * LEN_X * 4)
	{
	  tmp = ml->data[begin];
	  write(fd, &tmp, 1);
	  tmp = ml->data[begin + 1];
	  write(fd, &tmp, 1);
	  tmp = ml->data[begin + 2];
	  write(fd, &tmp, 1);
	  begin += 4;
	}
      y--;
    }
}
