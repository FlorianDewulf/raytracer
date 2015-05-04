/*
** convert_to_bmp.c for raytracer in /home/lund/svn/raytracer-2016-dewulf_f
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Wed May 23 22:28:21 2012 florian dewulf
** Last update Sat Jun  2 19:58:04 2012 florian dewulf
*/

#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"RT.h"

static int	create_file()
{
  int		ret;
  char		buffer[50];
  char		*str;

  ret = -1;
  while (ret < 0)
    {
      my_putstr("Name of the file ? (Ctrl + D to quit)\n");
      ret = read(0, buffer, 49);
      if (ret == -1)
	return (-1);
      if (ret > 0)
	{
	  buffer[ret - 1] = 0;
	  str = concate(buffer, ".bmp");
	  if (access(buffer, F_OK) == -1)
	    ret = open(str, O_RDWR | O_CREAT | O_EXCL | O_NOCTTY | O_TRUNC,
		       S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	  else
	    ret = my_puterror_int("File exist already\n");
	  if (str)
	    free(str);
	}
    }
  return (ret);
}

static void	put_head_file(int fd)
{
  t_head_bmp	bmp;
  char		tmp;

  tmp = 'B';
  write(fd, &tmp, 1);
  tmp = 'M';
  write(fd, &tmp, 1);
  bmp.size_file = LEN_X * LEN_Y * 3 + 54;
  bmp.reserv = 0;
  bmp.offset = 54;
  bmp.size_head = 40;
  bmp.wight = LEN_X;
  bmp.height = LEN_Y;
  bmp.plan_pronf = 1572865;
  bmp.compression = 0;
  bmp.size_img = LEN_X * LEN_Y * 3;
  bmp.reso_x = 2835;
  bmp.reso_y = 2835;
  bmp.palette_one = 0;
  bmp.palette_two = 0;
  write(fd, &bmp, sizeof(bmp));
}

void		convert_to_bmp(t_var *ml)
{
  int		fd;

  fd = create_file();
  if (fd == 0)
    return;
  put_head_file(fd);
  print_data_bmp(ml, fd);
  if (close(fd) == -1)
    exit(my_puterror_int("Fail close\n"));
  my_putstr("Save done\n");
}
