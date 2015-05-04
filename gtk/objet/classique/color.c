/*
** color_sphere.c for RT in /home/david/gtk/menu/version2.0/sphere
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Fri May 25 15:03:50 2012 david blervaque
** Last update Fri Jun  1 22:29:45 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		create_green_color()
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_color;
  GtkWidget	*ptr_label;
  GtkObject	*ptr_adjust;
  GtkWidget	*ptr_scrollbar;

  ptr_frame = gtk_frame_new("Vert");
  gtk_box_pack_start(GTK_BOX(g_sph_box), ptr_frame, TRUE, TRUE, 0);
  create_box(&ptr_frame, &ptr_color);
  ptr_label = gtk_label_new("0");
  gtk_box_pack_start(GTK_BOX(ptr_color), ptr_label, TRUE, TRUE, 0);
  ptr_adjust = gtk_adjustment_new(0, 0, 256, 1, 10, 1);
  ptr_scrollbar = gtk_hscrollbar_new(GTK_ADJUSTMENT(ptr_adjust));
  put_color(2, &ptr_frame);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(green_change), (GtkWidget*)ptr_label);
  gtk_box_pack_start(GTK_BOX(ptr_color), ptr_scrollbar, TRUE, TRUE, 0);
}

void		create_blue_color()
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_color;
  GtkWidget	*ptr_label;
  GtkObject	*ptr_adjust;
  GtkWidget	*ptr_scrollbar;

  ptr_frame = gtk_frame_new("Bleu");
  gtk_box_pack_start(GTK_BOX(g_sph_box), ptr_frame, TRUE, TRUE, 0);
  create_box(&ptr_frame, &ptr_color);
  ptr_label = gtk_label_new("0");
  gtk_box_pack_start(GTK_BOX(ptr_color), ptr_label, TRUE, TRUE, 0);
  ptr_adjust = gtk_adjustment_new(0, 0, 256, 1, 10, 1);
  ptr_scrollbar = gtk_hscrollbar_new(GTK_ADJUSTMENT(ptr_adjust));
  put_color(3, &ptr_frame);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(blue_change), (GtkWidget*)ptr_label);
  gtk_box_pack_start(GTK_BOX(ptr_color), ptr_scrollbar, TRUE, TRUE, 0);
}

void		create_button_for_color(GtkWidget **g_sph_box,
					GtkWidget *ptr_vbox)
{
  GtkWidget     *ptr_button[3];
  GtkWidget     *ptr_HBox;

  ptr_button[0] = gtk_button_new_with_label("Info");
  ptr_button[1] = gtk_button_new_with_label("Position");
  ptr_button[2] = gtk_button_new_with_label("Add");
  ptr_HBox = gtk_hbox_new(TRUE, 0);
  gtk_box_pack_start(GTK_BOX((*g_sph_box)), ptr_HBox, TRUE, TRUE, 0);
  g_signal_connect(G_OBJECT(ptr_button[0]), "clicked", G_CALLBACK(info),
		   (GtkWidget*)ptr_vbox);
  g_signal_connect(G_OBJECT(ptr_button[1]), "clicked", G_CALLBACK(go_to_config),
		   (GtkWidget*)ptr_vbox);
  g_signal_connect(G_OBJECT(ptr_button[2]), "clicked", G_CALLBACK(add_config),
		   (GtkWidget*)ptr_vbox);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[0], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[1], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[2], TRUE, TRUE, 0);
}

void		change_color(GtkWidget *widget, gpointer data)
{
  GdkColor	color;

  color.pixel = 32;
  color.blue = g_list->blue * 257;
  color.green = g_list->green * 257;
  color.red = g_list->red * 257;
  gtk_widget_modify_bg(widget, GTK_STATE_NORMAL, &color);
}

void		color(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  GtkWidget	*ptr_button;

  g_rm = 0;
  remove_or_hide_color();
  if (g_cr_col == 0)
    {
      g_list->red = 0;
      g_list->blue = 0;
      g_list->green = 0;
      tmp = GTK_WIDGET(data);
      create_box(&tmp, &g_sph_box);
      create_red_color();
      create_green_color();
      create_blue_color();
      ptr_button = gtk_button_new_with_label("Voir votre couleur");
      gtk_box_pack_start(GTK_BOX(g_sph_box), ptr_button, TRUE, TRUE, 0);
      g_signal_connect(G_OBJECT(ptr_button), "clicked",
		       G_CALLBACK(change_color), NULL);
      create_button_for_color(&g_sph_box, tmp);
      g_cr_col = 1;
    }
  gtk_widget_show_all(g_sph_box);
}
