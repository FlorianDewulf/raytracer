/*
** help_rt_menu.c for RT in /home/kenzo/Documents/RT/gtk/GTK_MENU
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Thu May 24 10:20:24 2012 christophe del fabbro
** Last update Fri Jun  1 22:12:43 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"menurt.h"

void		version_rt_menu(GtkWidget *widget, gpointer data)
{
  GtkWidget	*ptr_version;

  ptr_version = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_MODAL,
				       GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
				       VERSION_INFO);
  if (gtk_dialog_run(GTK_DIALOG(ptr_version)) == GTK_RESPONSE_OK)
    gtk_widget_destroy(ptr_version);
}

void		team_rt_menu(GtkWidget *widget, gpointer data)
{
  GtkWidget	*ptr_team;

  ptr_team = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_MODAL,
				    GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
				    TEAM_INFO);
  if (gtk_dialog_run(GTK_DIALOG(ptr_team)) == GTK_RESPONSE_OK)
    gtk_widget_destroy(ptr_team);
}

void		other_rt_menu(GtkWidget *widget, gpointer data)
{
  GtkWidget	*ptr_other;

  ptr_other = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_MODAL,
				     GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
				     OTHER_INFO);
  if (gtk_dialog_run(GTK_DIALOG(ptr_other)) == GTK_RESPONSE_OK)
    gtk_widget_destroy(ptr_other);
}
