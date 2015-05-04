/*
** info_pyramide_prisme.c for RT in /home/kenzo/Bureau/save_rt/gtk2/objet/pyramide_prisme
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Thu May 31 17:55:51 2012 christophe del fabbro
** Last update Fri Jun  1 22:44:38 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"


static GtkWidget	*create_spin(GtkWidget *ptr_frame)
{
  GtkWidget	*ptr_spin;

  ptr_spin = gtk_spin_button_new_with_range(0, 100, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin);
  return (ptr_spin);
}

void		create_info_for_p(GtkWidget **g_sph_info)
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_spin[2];
  GtkWidget	*ptr_scrollbar;
  GtkWidget	*ptr_label;

  ptr_frame = gtk_frame_new("Côté de la base");
  ptr_spin[0] = create_spin(ptr_frame);
  gtk_box_pack_start(GTK_BOX((*g_sph_info)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin[0]), "value-changed",
		   G_CALLBACK(save_info0), (GtkWidget*)ptr_spin[0]);
  ptr_frame = gtk_frame_new("Hauteur");
  ptr_spin[1] = create_spin(ptr_frame);
  gtk_box_pack_start(GTK_BOX((*g_sph_info)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin[1]), "value-changed",
		   G_CALLBACK(save_info1), (GtkWidget*)ptr_spin[1]);
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

void		create_button_info_for_p(GtkWidget **g_sph_info,
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
		   G_CALLBACK(color_p), (GtkWidget*)ptr_vbox);
  g_signal_connect(G_OBJECT(ptr_button[1]), "clicked",
		   G_CALLBACK(go_to_config), (GtkWidget*)ptr_vbox);
  g_signal_connect(G_OBJECT(ptr_button[2]), "clicked",
		   G_CALLBACK(add_config), (GtkWidget*)ptr_vbox);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[0], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[1], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[2], TRUE, TRUE, 0);
}

void		info_p(GtkWidget *ptr_widget, gpointer data)
{
  GtkWidget	*tmp;
  static int	inf_cr;

  g_rm = 0;
  remove_or_hide_info();
  if (g_cr_inf == 0)
    {
      tmp = GTK_WIDGET(data);
      create_box(&tmp, &g_sph_info);
      create_info_for_p(&g_sph_info);
      create_button_info_for_p(&g_sph_info, tmp);
      g_cr_inf = 1;
    }
  gtk_widget_show_all(g_sph_info);
}
