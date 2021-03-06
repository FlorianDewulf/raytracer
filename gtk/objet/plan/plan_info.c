/*
** plan_info.c for RT in /home/kenzo/Documents/RT/gtk/gtk/plan
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Fri May 25 17:27:41 2012 christophe del fabbro
** Last update Fri Jun  1 22:34:38 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		create_plan_info(GtkWidget **g_sph_info)
{
  GtkWidget	*ptr_scrollbar;
  GtkWidget	*ptr_label;

  ptr_scrollbar = create_bar("Transparence", g_sph_info, &ptr_label);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(save_trans), (GtkWidget*)ptr_label);
  ptr_scrollbar = create_bar("Réflexion", g_sph_info, &ptr_label);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(save_ref), (GtkWidget*)ptr_label);
  ptr_scrollbar = create_bar("Brillance", g_sph_info, &ptr_label);
  g_signal_connect(G_OBJECT(ptr_scrollbar), "value-changed",
		   G_CALLBACK(save_brill), (GtkWidget*)ptr_label);
}

void		create_plan_button_info(GtkWidget **g_sph_info,
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

void		plan_info(GtkWidget *ptr_widget, gpointer data)
{
  GtkWidget	*tmp;

  g_rm = 0;
  remove_or_hide_info();
  if (g_cr_inf == 0)
    {
      tmp = GTK_WIDGET(data);
      create_box(&tmp, &g_sph_info);
      create_plan_info(&g_sph_info);
      create_plan_button_info(&g_sph_info, tmp);
      g_cr_inf = 1;
    }
  gtk_widget_show_all(g_sph_info);
}
