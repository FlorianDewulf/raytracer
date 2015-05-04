/*
** create_box.c for RT in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 22 11:26:38 2012 david blervaque
** Last update Thu May 31 17:20:34 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../menurt.h"

void		create_box(GtkWidget **ptr_one, GtkWidget **ptr_two)
{
  GtkWidget	*tmp;
  GtkWidget	*tmp2;

  tmp2 = *ptr_one;
  tmp = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(tmp2), tmp);
  *ptr_two = tmp;
  *ptr_one = tmp2;
}
