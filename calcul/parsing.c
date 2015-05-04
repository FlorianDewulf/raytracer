/*
** parsing.c for raytracer in /home/lund/svn/raytracer-2016-dewulf_f/calcul
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Jun  1 21:38:24 2012 florian dewulf
** Last update Fri Jun  1 21:59:04 2012 florian dewulf
*/

#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdlib.h>
#include	"RT.h"

void		parse(t_obj *item, int nb)
{
  int		curs;

  curs = -1;
  while (++curs < nb)
    if (item[curs].type >= OB_TYPE || item[curs].color < 0 ||
	item[curs].brill < 0 || item[curs].info[0] < 0 ||
	item[curs].info[1] < 0)
      exit(EXIT_FAILURE);
}

int		reduc_main(int ac, char **av)
{
  int		fd;

  if (ac == 2)
    fd = open(av[1], O_RDWR);
  else if (ac == 4)
    fd = open(av[3], O_RDWR);
  else
    return (-1);
  return (fd);
}
