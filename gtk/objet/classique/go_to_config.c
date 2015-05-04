/*
** go_to_congig.c for RT in /home/david/save_rt/gtk/sphere
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Sat May 26 15:16:52 2012 david blervaque
** Last update Fri Jun  1 22:02:05 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		go_to_config(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;

  g_rm = 0;
  remove_or_hide_pos();
  gtk_widget_show_all(g_ptr_vvbox);
}
