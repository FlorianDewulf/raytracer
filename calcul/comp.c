/*
** comp.c for 42sh in /home/lund/Dossier courant/42sh/func
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sat Apr 21 15:17:30 2012 florian dewulf
** Last update Sat Jun  2 19:44:42 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"RT.h"

int		comp(char *str, char *pattern)
{
  int		curs;

  curs = -1;
  if (str == NULL || pattern == NULL)
    return (0);
  if (my_strlen(str) != my_strlen(pattern))
    return (0);
  while (str[++curs] && pattern[curs])
    if (str[curs] != pattern[curs])
      return (0);
  if (!str[curs] && !pattern[curs])
    return (1);
  return (0);
}
