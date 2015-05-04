/*
** config_plan2.c for RT in /home/kenzo/Documents/RT/gtk/GTK_MENU
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Thu May 24 11:01:07 2012 christophe del fabbro
** Last update Fri Jun  1 22:34:07 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		func_signal_plan_z(GtkWidget *widget, gpointer data)
{
  GtkWidget	*tmp;
  gint		val;

  tmp = GTK_WIDGET(data);
  val = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tmp));
  g_list->x = 0;
  g_list->y = 0;
  g_list->z = val;
}

void		create_pos_plan(GtkWidget **g_ptr_vvbox)
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_spin;

  ptr_frame = gtk_frame_new("Z");
  ptr_spin = gtk_spin_button_new_with_range(-3000, 3000, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin), "value-changed",
		   G_CALLBACK(func_signal_plan_z), (GtkWidget*)ptr_spin);
}

void		create_plan_button(GtkWidget **g_ptr_vvbox, GtkWidget *ptr_vbox)
{
  GtkWidget	*ptr_button[3];
  GtkWidget	*ptr_HBox;

  ptr_button[0] = gtk_button_new_with_label("Couleur");
  ptr_button[1] = gtk_button_new_with_label("Info");
  ptr_button[2] = gtk_button_new_with_label("Add");
  ptr_HBox = gtk_hbox_new(TRUE, 0);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_HBox, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_button[0]), "clicked",
		   G_CALLBACK(color_plan), (GtkWidget*)ptr_vbox);
  g_signal_connect(GTK_OBJECT(ptr_button[1]), "clicked",
		   G_CALLBACK(plan_info), (GtkWidget*)ptr_vbox);
  g_signal_connect(GTK_OBJECT(ptr_button[2]), "clicked",
		   G_CALLBACK(add_config), (GtkWidget*)ptr_vbox);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[0], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[1], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[2], TRUE, TRUE, 0);
}

void		config_plan(GtkWidget *ptr_widget, gpointer data)
{
  GtkWidget	*tmp;

  g_rm = 1;
  g_list->type = 0;
  init_list();
  remove_or_hide_pos();
  g_cr_col = 0;
  g_cr_inf = 0;
  tmp = GTK_WIDGET(data);
  create_box(&tmp, &g_ptr_vvbox);
  create_pos_plan(&g_ptr_vvbox);
  create_plan_button(&g_ptr_vvbox, tmp);
  gtk_widget_show_all(g_ptr_vvbox);
}
