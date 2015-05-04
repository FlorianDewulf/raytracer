/*
** create_window.c for 42 in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 22 10:40:00 2012 david blervaque
** Last update Fri Jun  1 22:28:17 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../menurt.h"

void		create_window(GtkWidget **ptr_window)
{
  GtkWidget	*tmp;
  GtkWidget	*ptr_welcome;

  tmp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(tmp), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(tmp), "RayTracer");
  gtk_window_set_default_size(GTK_WINDOW(tmp), 500, 500);
  ptr_welcome = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
				       GTK_BUTTONS_OK, WELCOME);
  if (gtk_dialog_run(GTK_DIALOG(ptr_welcome)) == GTK_RESPONSE_OK)
    gtk_widget_destroy(ptr_welcome);
  g_signal_connect(G_OBJECT(tmp), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  *ptr_window = tmp;
}
