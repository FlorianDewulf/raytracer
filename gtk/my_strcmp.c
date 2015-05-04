/*
** my_strcmp.c<2> for minishell2 in /home/delfab_c//Documents/help/C/piscine/Jour_06
** 
** Made by christophe delfabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Thu Mar  1 18:49:45 2012 christophe delfabbro
** Last update Wed May 30 16:55:32 2012 christophe del fabbro
*/

#include	"menurt.h"

int		my_strcmp(const char *s1, char *s2)
{
  int		count;

  count = 0;
  while (s1[count] != '\0' || s2[count] != '\0')
    {
      if (s1[count] != s2[count])
	return (-1);
      count++;
    }
  if (s1[count] == '\0' && s2[count] == '\0')
    return (1);
  else
    return (-1);
}
