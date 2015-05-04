/*
** color2.c for RT in /home/kenzo/Bureau/gtk/objet/classique
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Fri Jun  1 21:59:57 2012 christophe del fabbro
** Last update Fri Jun  1 22:28:43 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		put_color(int col, GtkWidget **ptr_frame)
{
  GdkColor	color;

  color.pixel = 32;
  color.red = 0;
  color.green = 0;
  color.blue = 0;
  if (col == 1)
    color.red = 65535;
  else if (col == 2)
    color.green = 65535;
  else if (col == 3)
    color.blue = 65535;
  gtk_widget_modify_bg((*ptr_frame), GTK_STATE_NORMAL, &color);
}

void		create_red_color()
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_color;
  GtkWidget	*ptr_label;
  GtkObject	*ptr_adjust;
  GtkWidget	*ptr_scrollbar;

  ptr_frame = gtk_frame_new("Rouge");
  gtk_box_pack_start(GTK_BOX(g_sph_box), ptr_frame, TRUE, TRUE, 0);
  create_box(&ptr_frame, &ptr_color);
  ptr_label = gtk_label_new("0");
  gtk_box_pack_start(GTK_BOX(ptr_color), ptr_label, TRUE, TRUE, 0);
  ptr_adjust = gtk_adjustment_new(0, 0, 256, 1, 10, 1);
  ptr_scrollbar = gtk_hscrollbar_new(GTK_ADJUSTMENT(ptr_adjust));
  put_color(1, &ptr_frame);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(red_change), (GtkWidget*)ptr_label);
  gtk_box_pack_start(GTK_BOX(ptr_color), ptr_scrollbar, TRUE, TRUE, 0);
}

