/*
** xopen.c for 42 in /home/david/Projet/42sh/exec
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Thu Apr 26 16:44:16 2012 david blervaque
** Last update Thu May 31 10:28:31 2012 david blervaque
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"menurt.h"

int		xopen(const char *name)
{
  int		ret;

  ret = open(name, O_RDWR | O_TRUNC);
  if (ret == -1)
    ret = open(name, O_RDWR | O_CREAT | O_EXCL | O_NOCTTY | O_TRUNC,
	       S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  if (ret == -1)
    my_puterror("We can't open this file.\n");
  return (ret);
}
