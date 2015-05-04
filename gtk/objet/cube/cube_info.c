/*
** select_info.c for RT in /home/kenzo/Documents/RT/gtk/gtk/sphere
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Fri May 25 15:55:15 2012 christophe del fabbro
** Last update Fri Jun  1 22:33:06 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		create_cube_info(GtkWidget **g_sph_info)
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_spin;
  GtkWidget	*ptr_scrollbar;
  GtkWidget	*ptr_label;

  ptr_frame = gtk_frame_new("Taille du côté");
  ptr_spin = gtk_spin_button_new_with_range(0, 100, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin);
  gtk_box_pack_start(GTK_BOX((*g_sph_info)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin), "value-changed",
		   G_CALLBACK(save_info0), (GtkWidget*)ptr_spin);
  ptr_scrollbar = create_bar("Transparence", g_sph_info, &ptr_label);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(save_trans), (GtkWidget*)ptr_label);
  ptr_scrollbar = create_bar("Reflexion", g_sph_info, &ptr_label);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(save_ref), (GtkWidget*)ptr_label);
  ptr_scrollbar = create_bar("Brillance", g_sph_info, &ptr_label);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(save_brill), (GtkWidget*)ptr_label);
}

void		create_cube_button_info(GtkWidget **g_sph_info,
					GtkWidget *ptr_vbox)
{
  GtkWidget	*ptr_button[3];
  GtkWidget	*ptr_HBox;

  ptr_button[0] = gtk_button_new_with_label("Couleur");
  ptr_button[1] = gtk_button_new_with_label("Position");
  ptr_button[2] = gtk_button_new_with_label("Add");
  ptr_HBox = gtk_hbox_new(TRUE, 0);
  gtk_box_pack_start(GTK_BOX((*g_sph_info)), ptr_HBox, TRUE, TRUE, 0);
  g_signal_connect(G_OBJECT(ptr_button[0]), "clicked",
		   G_CALLBACK(color), (GtkWidget*)ptr_vbox);
  g_signal_connect(G_OBJECT(ptr_button[1]), "clicked",
		   G_CALLBACK(go_to_config), (GtkWidget*)ptr_vbox);
  g_signal_connect(G_OBJECT(ptr_button[2]), "clicked",
		   G_CALLBACK(add_config), (GtkWidget*)ptr_vbox);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[0], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[1], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[2], TRUE, TRUE, 0);
}

void		cube_info(GtkWidget *ptr_widget, gpointer data)
{
  GtkWidget	*tmp;
  static int	inf_cr;

  g_rm = 0;
  remove_or_hide_info();
  if (g_cr_inf == 0)
    {
      tmp = GTK_WIDGET(data);
      create_box(&tmp, &g_sph_info);
      create_cube_info(&g_sph_info);
      create_cube_button_info(&g_sph_info, tmp);
      g_cr_inf = 1;
    }
  gtk_widget_show_all(g_sph_info);
}
