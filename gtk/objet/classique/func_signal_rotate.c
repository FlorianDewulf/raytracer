/*
** func_signal_sphere_rotate.c for RT in /home/kenzo/Documents/RT/gtk/GTK_MENU
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Thu May 24 13:33:47 2012 christophe del fabbro
** Last update Thu May 31 18:28:39 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		func_signal_rotate_x(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->rot_x = val;
}

void		func_signal_rotate_y(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->rot_y = val;
}

void		func_signal_rotate_z(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->rot_z = val;
}
