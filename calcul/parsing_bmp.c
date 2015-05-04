/*
** parsing_bmp.c for raytracer in /home/lund/svn/RAY
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Fri May 25 13:12:42 2012 florian dewulf
** Last update Sat Jun  2 19:19:38 2012 florian dewulf
*/

#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"mlx.h"
#include	"RT.h"

static void	error_loading(char *data, int size)
{
  int		ret;

  ret = 0;
  my_putstr("Can't Load img\n");
  while (ret < size)
    data[ret++] = 0;
}

static void	print_img(char *data, char *datacpy, t_head_bmp *head)
{
  int		ret;
  int		ret2;
  int		y;
  int		y1;

  ret = 0;
  ret2 = 0;
  y = head->size_img - (head->wight * 3);
  while (y >= 0)
    {
      ret2 = y;
      y1 = y + (head->wight * 3);
      while (ret2 < y1)
	{
	  data[ret++] = datacpy[ret2++];
	  data[ret++] = datacpy[ret2++];
	  data[ret++] = datacpy[ret2++];
	  data[ret++] = 0;
	}
      y -= (head->wight * 3);
    }
}

static void	fill_data(char *data, t_head_bmp *head, int fd)
{
  char		*data_tmp;
  int		ret;

  ret = 0;
  if ((data_tmp = malloc((head->size_img) * sizeof(char))) == NULL)
    error_loading(data, head->size_img);
  else
    if ((ret = read(fd, data_tmp, head->size_img)) < head->size_img)
       error_loading(data, head->size_img);
    else
      print_img(data, data_tmp, head);
}

static t_var	*parsing_bmp(int fd)
{
  t_var		*var;
  t_head_bmp	head;
  int		ret;

  if ((var = malloc(sizeof(t_var))) == NULL)
    return (NULL);
  if ((ret = read(fd, &head, sizeof(head))) < (int)(sizeof(head)))
    return (NULL);
  if (head.wight <= 0 || head.height <= 0 ||
      head.size_img != head.wight * head.height * 3)
    return (NULL);
  if ((var->mlx = mlx_init()) == NULL)
    return (NULL);
  var->img = mlx_new_image(var->mlx, head.wight, head.height);
  var->data = mlx_get_data_addr(var->img,
				&var->bpp, &var->sizeline, &var->endian);
  fill_data(var->data, &head, fd);
  var->win = mlx_new_window(var->mlx, head.wight, head.height, "Ray-Tracer");
  return (var);
}

t_var		*check_file(char *str)
{
  char		buff[2];
  int		fd;

  fd = open(str, O_RDONLY);
  if (fd == -1)
    return (NULL);
  if (read(fd, buff, 2) < (int)(2 * sizeof(char)))
    return (NULL);
  if (buff[0] != 'B' && buff[1] != 'M')
    return (NULL);
  return (parsing_bmp(fd));
}
