/*
** create_bar.c for RT in /home/kenzo/Bureau/gtk
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Tue May 29 16:20:34 2012 christophe del fabbro
** Last update Thu May 31 20:12:12 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../menurt.h"

GtkWidget	*create_bar(char *s, GtkWidget **g_sph_info, GtkWidget **tmp)
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_scrollbar;
  GtkWidget	*ptr_colorbox;
  GtkWidget	*ptr_label;
  GtkObject	*adjust;

  ptr_label = *tmp;
  ptr_frame = gtk_frame_new(s);
  gtk_box_pack_start(GTK_BOX(*g_sph_info), ptr_frame, FALSE, FALSE, 0);
  ptr_colorbox = gtk_vbox_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_colorbox);
  ptr_label = gtk_label_new("0");
  gtk_box_pack_start(GTK_BOX(ptr_colorbox), ptr_label, FALSE, FALSE, 0);
  adjust = gtk_adjustment_new(0, 0, 101, 1, 1, 1);
  ptr_scrollbar = gtk_hscrollbar_new(GTK_ADJUSTMENT(adjust));
  gtk_box_pack_start(GTK_BOX(ptr_colorbox), ptr_scrollbar, TRUE, TRUE, 0);
  *tmp = ptr_label;
  return (ptr_scrollbar);
}
