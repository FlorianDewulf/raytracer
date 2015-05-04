/*
** add_config.c for RT in /home/david/save_rt/gtk
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 29 16:43:14 2012 david blervaque
** Last update Fri Jun  1 22:07:58 2012 christophe del fabbro
*/

#include		<gtk/gtk.h>
#include		<stdlib.h>
#include		"menurt.h"

static void            remp_new_elem(t_object *new_elem, t_object *tmp)
{
  new_elem->type = tmp->type;
  new_elem->x = tmp->x;
  new_elem->y = tmp->y;
  new_elem->z = tmp->z;
  new_elem->rot_x = tmp->rot_x;
  new_elem->rot_y = tmp->rot_y;
  new_elem->rot_z = tmp->rot_z;
  new_elem->info[0] = tmp->info[0];
  new_elem->info[1] = tmp->info[1];
  new_elem->brill = tmp->brill;
  new_elem->reflex = tmp->reflex;
  new_elem->transp = tmp->transp;
  new_elem->red = tmp->red;
  new_elem->green = tmp->green;
  new_elem->blue = tmp->blue;
  new_elem->next = NULL;
}

void		add_config(GtkWidget *widget, gpointer data)
{
  t_object	*new_elem;
  t_object	*ptr;
  GtkWidget	*ptr_window;
  GtkWidget	*ptr_info;

  new_elem = xmalloc(sizeof(t_object));
  remp_new_elem(new_elem, g_list);
  if (g_list->next == NULL)
    {
      init_list();
      g_list->next = new_elem;
    }
  else
    {
      ptr = g_list->next;
      new_elem->next = ptr;
      init_list();
      g_list->next = new_elem;
    }
  ptr_window = gtk_widget_get_toplevel(GTK_WIDGET(data));
  ptr_info = gtk_message_dialog_new(GTK_WINDOW(ptr_window), GTK_DIALOG_MODAL,
				    GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
				    "Votre objet a été sauvegardé.");
  gtk_dialog_run(GTK_DIALOG(ptr_info));
  gtk_widget_destroy(ptr_info);
}
