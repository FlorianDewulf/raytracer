/*
** create_menu.c for RT in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 22 11:40:23 2012 david blervaque
** Last update Fri Jun  1 22:15:32 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../menurt.h"

void		init_item_menu(GtkWidget **ptr_menu_bar, GtkWidget *ptr_window)
{
  GtkWidget	*ptr_menu;
  GtkWidget	*ptr_menu_item;

  ptr_menu = gtk_menu_new();
  ptr_menu_item = gtk_menu_item_new_with_label("Nouveau");
  gtk_menu_shell_append(GTK_MENU_SHELL(ptr_menu), ptr_menu_item);
  g_signal_connect(G_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(free_list), NULL);
  ptr_menu_item = gtk_menu_item_new_with_label("Sauvegarder");
  gtk_menu_shell_append(GTK_MENU_SHELL(ptr_menu), ptr_menu_item);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(file_select), NULL);
  ptr_menu_item = gtk_menu_item_new_with_label("Quitter");
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(quit_rt_menu), (GtkWidget*)ptr_window);
  gtk_menu_shell_append(GTK_MENU_SHELL(ptr_menu), ptr_menu_item);
  ptr_menu_item = gtk_menu_item_new_with_label("Fichier");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(ptr_menu_item), ptr_menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(*ptr_menu_bar), ptr_menu_item);
}

void		create_menu(GtkWidget **ptr_vbox, GtkWidget *ptr_window)
{
  GtkWidget	*ptr_menu_bar;

  ptr_menu_bar = gtk_menu_bar_new();
  init_item_menu(&ptr_menu_bar, ptr_window);
  create_menu_object(&ptr_menu_bar, ptr_vbox);
  create_menu_about(&ptr_menu_bar, ptr_window);
  gtk_box_pack_start(GTK_BOX((*ptr_vbox)), ptr_menu_bar, FALSE, FALSE, 0);
}
