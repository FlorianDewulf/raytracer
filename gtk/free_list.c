/*
** free_list.c for RT in /home/david/Projet/raytracer-2016-dewulf_f/gtk
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Fri Jun  1 10:14:55 2012 david blervaque
** Last update Fri Jun  1 22:11:59 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"menurt.h"

static void		free_maill()
{
  g_list = NULL;
  g_list = xmalloc(sizeof(t_object));
  init_list();
  g_list->next = NULL;
}

void		free_list(GtkWidget *widget, gpointer data)
{
  GtkWidget	*ptr_ask;

  ptr_ask = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_MODAL,
				   GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO,
				   ARE_YOU_SURE);
  if (gtk_dialog_run(GTK_DIALOG(ptr_ask)) == GTK_RESPONSE_YES)
    {
      free_maill();
      gtk_widget_destroy(ptr_ask);
    }
  else
    gtk_widget_destroy(ptr_ask);
}
