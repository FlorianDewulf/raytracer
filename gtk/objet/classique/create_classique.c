/*
** config_sphere.c for RT in /home/kenzo/Documents/RT/gtk/GTK_MENU
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Thu May 24 11:01:07 2012 christophe del fabbro
** Last update Fri Jun  1 22:30:24 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		create_pos(GtkWidget **g_ptr_vvbox)
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_spin[3];

  ptr_frame = gtk_frame_new("X");
  ptr_spin[0] = gtk_spin_button_new_with_range(-3000, 3000, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin[0]);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin[0]), "value-changed",
		   G_CALLBACK(func_signal_x), (GtkWidget*)ptr_spin[0]);
  ptr_frame = gtk_frame_new("Y");
  ptr_spin[1] = gtk_spin_button_new_with_range(-3000, 3000, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin[1]);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin[1]), "value-changed",
		   G_CALLBACK(func_signal_y), (GtkWidget*)ptr_spin[1]);
  ptr_frame = gtk_frame_new("Z");
  ptr_spin[2] = gtk_spin_button_new_with_range(-3000, 3000, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin[2]);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin[2]), "value-changed",
		   G_CALLBACK(func_signal_z), (GtkWidget*)ptr_spin[2]);
}

void		create_pos_rotate(GtkWidget **g_ptr_vvbox)
{
  GtkWidget	*ptr_frame;
  GtkWidget	*ptr_spin[3];

  ptr_frame = gtk_frame_new("Rotation X");
  ptr_spin[0] = gtk_spin_button_new_with_range(-360, 360, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin[0]);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin[0]), "value-changed",
		   G_CALLBACK(func_signal_rotate_x), (GtkWidget*)ptr_spin[0]);
  ptr_frame = gtk_frame_new("Rotation Y");
  ptr_spin[1] = gtk_spin_button_new_with_range(-360, 360, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin[1]);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin[1]), "value-changed",
		   G_CALLBACK(func_signal_rotate_y), (GtkWidget*)ptr_spin[1]);
  ptr_frame = gtk_frame_new("Rotation Z");
  ptr_spin[2] = gtk_spin_button_new_with_range(-360, 360, 1);
  gtk_container_add(GTK_CONTAINER(ptr_frame), ptr_spin[2]);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_frame, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_spin[2]), "value-changed",
		   G_CALLBACK(func_signal_rotate_z), (GtkWidget*)ptr_spin[2]);
}

void		create_button(GtkWidget **g_ptr_vvbox, GtkWidget *ptr_vbox)
{
  GtkWidget	*ptr_button[3];
  GtkWidget	*ptr_HBox;

  ptr_button[0] = gtk_button_new_with_label("Couleur");
  ptr_button[1] = gtk_button_new_with_label("Info");
  ptr_button[2] = gtk_button_new_with_label("Add");
  ptr_HBox = gtk_hbox_new(TRUE, 0);
  gtk_box_pack_start(GTK_BOX((*g_ptr_vvbox)), ptr_HBox, TRUE, TRUE, 0);
  g_signal_connect(GTK_OBJECT(ptr_button[0]), "clicked",
		   G_CALLBACK(color), (GtkWidget*)ptr_vbox);
  g_signal_connect(GTK_OBJECT(ptr_button[1]), "clicked",
		   G_CALLBACK(info), (GtkWidget*)ptr_vbox);
  g_signal_connect(GTK_OBJECT(ptr_button[2]), "clicked",
		   G_CALLBACK(add_config), (GtkWidget*)ptr_vbox);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[0], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[1], TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(ptr_HBox), ptr_button[2], TRUE, TRUE, 0);
}
