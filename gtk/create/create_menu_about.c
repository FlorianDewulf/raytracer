/*
** main.c for RT in /home/kenzo/Documents/gtk
** 
** Made by christophe del fabbro
** Login   <delfab_c@epitech.net>
** 
** Started on  Tue May 22 14:25:08 2012 christophe del fabbro
** Last update Fri Jun  1 22:14:39 2012 christophe del fabbro
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"../menurt.h"

void		create_menu_about(GtkWidget **ptr_menu_bar,
				  GtkWidget *ptr_window)
{
  GtkWidget	*ptr_menu;
  GtkWidget	*ptr_menu_item;
  GtkWidget	*tmp;

  ptr_menu = gtk_menu_new();
  ptr_menu_item = gtk_menu_item_new_with_label("Version");
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(version_rt_menu), (GtkWidget*)ptr_window);
  gtk_menu_shell_append(GTK_MENU_SHELL(ptr_menu), ptr_menu_item);
  ptr_menu_item = gtk_menu_item_new_with_label("Team");
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(team_rt_menu), (GtkWidget*)ptr_window);
  gtk_menu_shell_append(GTK_MENU_SHELL(ptr_menu), ptr_menu_item);
  ptr_menu_item = gtk_menu_item_new_with_label("Aide");
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(other_rt_menu), (GtkWidget*)ptr_window);
  gtk_menu_shell_append(GTK_MENU_SHELL(ptr_menu), ptr_menu_item);
  ptr_menu_item = gtk_menu_item_new_with_label("?");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(ptr_menu_item), ptr_menu);
  gtk_menu_shell_append(GTK_MENU_SHELL((*ptr_menu_bar)), ptr_menu_item);
}
