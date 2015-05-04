/*
** main.c for RT in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 22 09:54:49 2012 david blervaque
** Last update Sat Jun  2 20:19:14 2012 florian dewulf
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"menurt.h"

int		main(int ac, char **av)
{
  GtkWidget	*ptr_window;
  GtkWidget	*ptr_vbox;

  g_list = xmalloc(sizeof(t_object));
  gtk_init(&ac, &av);
  create_window(&ptr_window);
  create_box(&ptr_window, &ptr_vbox);
  create_menu(&ptr_vbox, ptr_window);
  gtk_widget_show_all(ptr_window);
  gtk_main();
  return (1);
}
