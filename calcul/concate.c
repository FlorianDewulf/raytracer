/*
** concate.c for 42sh in /home/lund/Dossier courant/42sh/func
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri Apr 20 17:59:51 2012 florian dewulf
** Last update Sat Jun  2 19:13:11 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"RT.h"

char		*concate(char *str, char *str2)
{
  char		*dest;
  int		curs;
  int		curs2;

  curs = -1;
  curs2 = 0;
  if (str == NULL || str2 == NULL)
    return (NULL);
  dest = xmalloc((my_strlen(str) + my_strlen(str2) + 1) * sizeof(char));
  while (str[++curs])
    dest[curs] = str[curs];
  while (str2[curs2])
    dest[curs++] = str2[curs2++];
  dest[curs] = '\0';
  return (dest);
}
