/*
** create_menu_object.c for RT in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 22 13:51:49 2012 david blervaque
** Last update Sat Jun  2 18:53:58 2012 christophe del fabbro
0*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"../menurt.h"

static GtkWidget	*create_obj_menu(char *s, GtkWidget **ptr_menu)
{
  GtkWidget		*ptr_menu_item;

  ptr_menu_item =  gtk_menu_item_new_with_label(s);
  gtk_menu_shell_append(GTK_MENU_SHELL((*ptr_menu)), ptr_menu_item);
  return (ptr_menu_item);
}

static void		create_menu_object2(GtkWidget **ptr_menu_bar,
					    GtkWidget **ptr_vbox,
					    GtkWidget **ptr_menu)
{
  GtkWidget	*ptr_menu_item;
  GtkWidget	*tmp;

  tmp = *ptr_vbox;
  ptr_menu_item = create_obj_menu("Prisme", ptr_menu);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(config_prism), (GtkWidget*)tmp);
  ptr_menu_item = create_obj_menu("Pyramide", ptr_menu);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(config_pyramid), (GtkWidget*)tmp);
  ptr_menu_item = create_obj_menu("Cube", ptr_menu);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(config_cube), (GtkWidget*)tmp);
  ptr_menu_item = create_obj_menu("Spot", ptr_menu);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(config_spot), (GtkWidget*)tmp);
}

void		create_menu_object(GtkWidget **ptr_menu_bar,
				   GtkWidget **ptr_vbox)
{
  GtkWidget	*ptr_menu_item;
  GtkWidget	*ptr_menu;
  GtkWidget	*tmp;

  tmp = *ptr_vbox;
  ptr_menu = gtk_menu_new();
  ptr_menu_item = create_obj_menu("Sphère", &ptr_menu);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(config_sphere), (GtkWidget*)tmp);
  ptr_menu_item = create_obj_menu("Cylindre", &ptr_menu);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(config_cylinder), (GtkWidget*)tmp);
  ptr_menu_item = create_obj_menu("Cone", &ptr_menu);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(config_cone), (GtkWidget*)tmp);
  ptr_menu_item = create_obj_menu("Plan", &ptr_menu);
  g_signal_connect(GTK_OBJECT(ptr_menu_item), "activate",
		   G_CALLBACK(config_plan), (GtkWidget*)tmp);
  create_menu_object2(ptr_menu_bar, ptr_vbox, &ptr_menu);
  ptr_menu_item = gtk_menu_item_new_with_label("Objet");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(ptr_menu_item), ptr_menu);
  gtk_menu_shell_append(GTK_MENU_SHELL((*ptr_menu_bar)), ptr_menu_item);
}
