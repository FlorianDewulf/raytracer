/*
** quit_rt_menu.c for RT in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 22 16:25:48 2012 david blervaque
** Last update Fri Jun  1 22:13:14 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"menurt.h"

void		quit_rt_menu(GtkWidget *widget, gpointer data)
{
  GtkWidget	*ptr_quit;

  ptr_quit = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_MODAL,
				    GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO,
				    WARNING_QUIT);
  if (gtk_dialog_run(GTK_DIALOG(ptr_quit)) == GTK_RESPONSE_YES)
    gtk_main_quit();
  else
    gtk_widget_destroy(ptr_quit);
}
