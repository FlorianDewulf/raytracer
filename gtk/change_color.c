/*
** change_color.c for RT in /home/david/save_rt/gtk
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 29 10:49:08 2012 david blervaque
** Last update Tue May 29 12:02:14 2012 david blervaque
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"menurt.h"

void		red_change(GtkWidget *widget, gpointer data)
{
  gchar		*lab;
  gint		val;

  val = gtk_range_get_value(GTK_RANGE(widget));
  lab = g_strdup_printf("%d", val);
  gtk_label_set_text(GTK_LABEL(data), lab);
  g_list->red = val;
  g_free(lab);
}

void		green_change(GtkWidget *widget, gpointer data)
{
  gchar		*lab;
  gint		val;

  val = gtk_range_get_value(GTK_RANGE(widget));
  lab = g_strdup_printf("%d", val);
  gtk_label_set_text(GTK_LABEL(data), lab);
  g_list->green = val;
  g_free(lab);
}

void		blue_change(GtkWidget *widget, gpointer data)
{
  gchar		*lab;
  gint		val;

  val = gtk_range_get_value(GTK_RANGE(widget));
  lab = g_strdup_printf("%d", val);
  gtk_label_set_text(GTK_LABEL(data), lab);
  g_list->blue = val;
  g_free(lab);
}
