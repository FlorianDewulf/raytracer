/*
** func.c for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Wed May 16 14:41:09 2012 remi mailliet
** Last update Sat Jun  2 19:56:52 2012 florian dewulf
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"RT.h"

void		my_putstr(char *str)
{
  write(1, str, strlen(str));
}

static void	my_put_nbr(int nb)
{
  int		div;
  char		res;

  div = 1;
  if (nb < 0)
    {
      write(1, "-", 1);
      nb *= -1;
    }
  while ((nb / div) >= 10)
    div *= 10;
  while (div > 0)
    {
      res = (nb / div) % 10 + '0';
      write(1, &res, 1);
      div /= 10;
    }
}

void		*xmalloc(int size)
{
  void		*r;

  if ((r = malloc(size)) == NULL)
    {
      my_putstr("Can't perform malloc.\n");
      exit(EXIT_FAILURE);
    }
  else
    return (r);
}

void		load()
{
  static int	load;
  static int	i;

  if (load == (i * (LEN_X * LEN_Y) / 10))
    {
      my_putstr("\t");
      my_put_nbr(i * 10);
      my_putstr("%");
      i++;
    }
  load++;
}

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  return (i);
}
