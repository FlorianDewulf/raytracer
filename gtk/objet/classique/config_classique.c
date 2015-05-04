/*
** config_classique.c for RT in /home/kenzo/Bureau/save_rt/gtk2/objet/classique
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Thu May 31 18:03:30 2012 christophe del fabbro
** Last update Sat Jun  2 18:47:17 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../../menurt.h"

void		config_sphere(GtkWidget *ptr_widget, gpointer data)
{
  GtkWidget	*tmp;

  g_rm = 1;
  g_list->type = 1;
  init_list();
  remove_or_hide_pos();
  g_cr_inf = 0;
  g_cr_col = 0;
  tmp = GTK_WIDGET(data);
  create_box(&tmp, &g_ptr_vvbox);
  create_pos(&g_ptr_vvbox);
  create_pos_rotate(&g_ptr_vvbox);
  create_button(&g_ptr_vvbox, tmp);
  gtk_widget_show_all(g_ptr_vvbox);
}

void		config_cylinder(GtkWidget *ptr_widget, gpointer data)
{
  GtkWidget	*tmp;

  g_rm = 1;
  g_list->type = 2;
  init_list();
  remove_or_hide_pos();
  g_cr_col = 0;
  g_cr_inf = 0;
  tmp = GTK_WIDGET(data);
  create_box(&tmp, &g_ptr_vvbox);
  create_pos(&g_ptr_vvbox);
  create_pos_rotate(&g_ptr_vvbox);
  create_button(&g_ptr_vvbox, tmp);
  gtk_widget_show_all(g_ptr_vvbox);
}

void		config_cone(GtkWidget *ptr_widget, gpointer data)
{
  GtkWidget	*tmp;

  g_rm = 1;
  g_list->type = 3;
  init_list();
  remove_or_hide_pos();
  g_cr_inf = 0;
  g_cr_col = 0;
  tmp = GTK_WIDGET(data);
  create_box(&tmp, &g_ptr_vvbox);
  create_pos(&g_ptr_vvbox);
  create_pos_rotate(&g_ptr_vvbox);
  create_button(&g_ptr_vvbox, tmp);
  gtk_widget_show_all(g_ptr_vvbox);
}
