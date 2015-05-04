/*
** check_bmp.c for raytracer in /home/lund/svn/raytracer-2016-dewulf_f/calcul
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri May 25 22:10:01 2012 florian dewulf
** Last update Sat Jun  2 19:54:46 2012 florian dewulf
*/

#include	"RT.h"

int		check_bmp(char *str)
{
  int		curs;

  curs = my_strlen(str);
  if (curs <= 4)
    return (0);
  if (str[curs - 1] == 'p' && str[curs - 2] == 'm' &&
      str[curs - 3] == 'b' && str[curs - 4] == '.')
    return (1);
  my_putstr("File no valid (need *.bmp)\n");
  return (0);
}
