/*
** file_selection.c for RT in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Fri May 25 11:46:14 2012 david blervaque
** Last update Fri Jun  1 22:11:03 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"menurt.h"

static void		write_conf(int fd)
{
  t_object		*tmp;

  tmp = g_list->next;
  while (tmp != NULL)
    {
      write(fd, &(tmp->type), sizeof(tmp->type));
      write(fd, &(tmp->x), sizeof(tmp->x));
      write(fd, &(tmp->y), sizeof(tmp->y));
      write(fd, &(tmp->z), sizeof(tmp->z));
      write(fd, &(tmp->rot_x), sizeof(tmp->rot_x));
      write(fd, &(tmp->rot_y), sizeof(tmp->rot_y));
      write(fd, &(tmp->rot_z), sizeof(tmp->rot_z));
      write(fd, &(tmp->info[0]), sizeof(tmp->info[0]));
      write(fd, &(tmp->info[1]), sizeof(tmp->info[1]));
      write(fd, &(tmp->brill), sizeof(tmp->brill));
      write(fd, &(tmp->reflex), sizeof(tmp->reflex));
      write(fd, &(tmp->transp), sizeof(tmp->transp));
      write(fd, &(tmp->red), sizeof(tmp->red));
      write(fd, &(tmp->green), sizeof(tmp->green));
      write(fd, &(tmp->blue), sizeof(tmp->blue));
      tmp = tmp->next;
    }
}

void		create_file(const gchar *path_file)
{
  int		fd;

  fd = xopen(path_file);
  write_conf(fd);
}

void		recup_path(GtkWidget *widget, GtkWidget *ptr_select)
{
  const gchar	*path_file;
  GtkWidget	*ptr_dial;

  path_file = gtk_file_selection_get_filename(GTK_FILE_SELECTION(ptr_select));
  ptr_dial = gtk_message_dialog_new(GTK_WINDOW(ptr_select), GTK_DIALOG_MODAL,
				    GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
				    "Vous avez choisi :\n%s", path_file);
  gtk_dialog_run(GTK_DIALOG(ptr_dial));
  create_file(path_file);
  gtk_widget_destroy(ptr_dial);
  gtk_widget_destroy(ptr_select);
}

void		cancel_button(GtkWidget *button, GtkWidget *ptr_select)
{
  gtk_widget_destroy(ptr_select);
}

void		file_select()
{
  GtkWidget	*ptr_select;

  ptr_select = gtk_file_selection_new("Selectionnez un fichier");
  gtk_widget_show(ptr_select);
  gtk_window_set_modal(GTK_WINDOW(ptr_select), TRUE);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(ptr_select)->ok_button),
		   "clicked", G_CALLBACK(recup_path), ptr_select);
  g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(ptr_select)->cancel_button),
		   "clicked", G_CALLBACK(cancel_button) , ptr_select);
}
