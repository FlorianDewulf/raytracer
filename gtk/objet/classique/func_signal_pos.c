/*
** func_signal_sphere_pos.c for RT in /home/kenzo/Documents/RT/gtk/GTK_MENU
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Thu May 24 11:59:25 2012 christophe del fabbro
** Last update Thu May 31 19:30:29 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		func_signal_x(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->x = val;
}

void		func_signal_y(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->y = val;
}

void		func_signal_z(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->z = val;
}
