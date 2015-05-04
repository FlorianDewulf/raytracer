/*
** color_p.c for RT in /home/david/gtk/menu/version2.0/p
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Fri May 25 17:45:39 2012 david blervaque
** Last update Fri Jun  1 22:35:20 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		create_button_for_color_p(GtkWidget **g_sph_box,
					  GtkWidget *ptr_vbox)
{
  GtkWidget     *ptr_button[3];
  GtkWidget     *ptr_HBox;

  ptr_button[0]= gtk_button_new_with_label("Info");
  ptr_button[1]= gtk_button_new_with_label("Position");
  ptr_button[2] = gtk_button_new_with_label("Add");
  ptr_HBox = gtk_hbox_new(TRUE, 0);
  gtk_box_pack_start(GTK_BOX((*g_sph_box)), ptr_HBox, TRUE, TRUE, 0);
  g_signal_connect(G_OBJECT(ptr_button[0]), "clicked",
		   G_CALLBACK(info_p), (GtkWidget*)ptr_vbox);
  g_signal_connect(G_OBJECT(ptr_button[1]), "clicked",
		   G_CALLBACK(go_to_config), (GtkWidget*)ptr_vbox);
  g_signal_connect(G_OBJECT(ptr_button[2]), "clicked",
		   G_CALLBACK(add_config), (GtkWidget*)ptr_vbox);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[0], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[1], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[2], TRUE, TRUE, 0);
}

void		color_p(GtkWidget *widget, gpointer data)
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
      create_button_for_color_p(&g_sph_box, tmp);
      g_cr_col = 1;
    }
  gtk_widget_show_all(g_sph_box);
}
