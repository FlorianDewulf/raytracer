/*
** my_puterror.c for raytracer in /home/lund/svn/raytracer-2016-dewulf_f
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Mon May 21 13:41:05 2012 florian dewulf
** Last update Sat Jun  2 19:56:11 2012 florian dewulf
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"RT.h"

void		*my_puterror_null(char *str)
{
  write(2, str, my_strlen(str));
  return (NULL);
}

int		my_puterror_int(char *str)
{
  write(2, str, my_strlen(str));
  return (EXIT_FAILURE);
}
