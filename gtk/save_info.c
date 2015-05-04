/*
** save_info.c for RT in /home/david/save_rt/gtk
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 29 19:24:41 2012 david blervaque
** Last update Thu May 31 20:13:24 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"menurt.h"

void		save_info0(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->info[0] = val;
}

void		save_info1(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->info[1] = val;
}

void		save_trans(GtkWidget *widget, gpointer data)
{
  gchar		*lab;
  gint		val;

  val = gtk_range_get_value(GTK_RANGE(widget));
  lab = g_strdup_printf("%d", val);
  gtk_label_set_text(GTK_LABEL(data), lab);
  g_list->transp = val;
  g_free(lab);
}

void		save_ref(GtkWidget *widget, gpointer data)
{
  gchar		*lab;
  gint		val;

  val = gtk_range_get_value(GTK_RANGE(widget));
  lab = g_strdup_printf("%d", val);
  gtk_label_set_text(GTK_LABEL(data), lab);
  g_list->reflex = val;
  g_free(lab);
}

void		save_brill(GtkWidget *widget, gpointer data)
{
  gchar		*lab;
  gint		val;

  val = gtk_range_get_value(GTK_RANGE(widget));
  lab = g_strdup_printf("%d", val);
  gtk_label_set_text(GTK_LABEL(data), lab);
  g_list->brill = val;
  g_free(lab);
}
