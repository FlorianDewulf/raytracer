/*
** xmalloc.c for  in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Thu May 24 11:22:31 2012 david blervaque
** Last update Thu May 24 11:28:43 2012 david blervaque
*/

#include	<stdlib.h>
#include	<string.h>

void		my_puterror(char *s)
{
  write(1, s, strlen(s));
  exit(-1);
}

void		*xmalloc(int size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    my_puterror("Malloc returned an error.\n");
  else
    return (ptr);
}
