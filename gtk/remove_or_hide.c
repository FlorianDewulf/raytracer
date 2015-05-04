/*
** remove_or_hide.c for RT in /home/david/Projet/raytracer-2016-dewulf_f/gtk
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Fri May 25 18:43:04 2012 david blervaque
** Last update Fri Jun  1 22:06:07 2012 christophe del fabbro
*/

#include	<gtk/gtk.h>
#include	<stdlib.h>
#include	"menurt.h"

void		remove_or_hide_info()
{
  if (g_ptr_vvbox != NULL)
    gtk_widget_hide(g_ptr_vvbox);
  if (g_sph_box != NULL && g_cr_col == 1)
    gtk_widget_hide(g_sph_box);
}

void		remove_or_hide_color()
{
  if (g_ptr_vvbox != NULL)
    gtk_widget_hide(g_ptr_vvbox);
  if (g_sph_info != NULL && g_cr_inf == 1)
    gtk_widget_hide(g_sph_info);
}

void		remove_or_hide_pos()
{
  if (g_rm == 1)
    {
      if (g_ptr_vvbox != NULL)
	gtk_widget_destroy(g_ptr_vvbox);
      if (g_cr_col == 1)
	gtk_widget_destroy(g_sph_box);
      if (g_cr_inf == 1)
	gtk_widget_destroy(g_sph_info);
    }
  else if (g_rm == 0)
    {
      if (g_sph_box != NULL && g_cr_col == 1)
	gtk_widget_hide(g_sph_box);
      if (g_sph_info != NULL && g_cr_inf == 1)
	gtk_widget_hide(g_sph_info);
    }
}
