/*
** init_value_info.c for RT in /home/david/Bureau/gtk
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Thu May 31 16:11:52 2012 david blervaque
** Last update Sat Jun  2 19:51:24 2012 christophe del fabbro
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"menurt.h"

void		init_list()
{
  g_list->x = 0;
  g_list->y = 0;
  g_list->z = 0;
  g_list->rot_x = 0;
  g_list->rot_y = 0;
  g_list->rot_z = 0;
  g_list->info[0] = 0;
  g_list->info[1] = 0;
  g_list->brill = 0;
  g_list->transp = 0;
  g_list->reflex = 0;
  g_list->red = 0;
  g_list->blue = 0;
  g_list->green = 0;
}
