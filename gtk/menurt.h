/*
** menurt.h for RT in /home/david/gtk/menu/version2.0
** 
** Made by david blervaque
** Login   <blerva_d@epitech.net>
** 
** Started on  Tue May 22 10:19:02 2012 david blervaque
** Last update Sat Jun  2 20:11:28 2012 christophe del fabbro
*/

#ifndef		__MENURT_H__
#define		__MENURT_H__

#define		WARNING_QUIT	"Voulez vous vraiment quitter ?\nAttention, les paramètres ne seront pas sauvegardés."

#define		TEAM_INFO	"Chef de groupe - dewulf_f\nmembre - lansel_k\nmembre - grocko_t\nmembre - mailli_r\nmembre - blerva_d\nmembre - delfab_c\n"
#define		VERSION_INFO	"gtk+-2.0"
#define		OTHER_INFO	"Cette interface va vous permettre de configurer les différents objets que vous souhaitez intégrer dans votre image raytracer.\nLa configuration se passe en plusieurs étapes:\n\n1) Sélectionnez l'objet souhaité dans l'onglet \"Objet\".\n\n2)\na) Pour chaque objet, la position en X, Y et Z vous est demandé.\n\nb) En cliquant sur le bouton \"Couleur\" vous pourrez configurer la couleur de l'objet en modifiant les valeurs RED, BLUE et GREEN.\n\nc) Ensuite cliquez sur le bouton \"Info\" (inexistant pout le spot).\nSelon l'objet vous aurez différentes valeurs à configurer:\n    -Rayon\n    -Côté de la base\n    -Hauteur\n    -Taille du côté\n    -Transparence\n    -Reflexion\n    -Brillance\n\nd) Une fois votre objet configuré, vous n'aurez plus qu'à cliquer sur le bouton \"Add\" pour le valider.\n\n3) Répétez l'opération pour chaque objet dont vous aurez besoin, puis cliquez sur l'onglet \"Fichier\" puis sur le bouton \"Sauvegarder\".\n\nUn fichier comprenant votre configuration sera créé et utilisable pour le binaire \"RT\"."
#define		WELCOME		"Bienvenue dans l'interface gtk+-2.0 destinée au Raytracer-promo2016.\n\nCet outil va vous permettre de configurer votre image en créant un fichier de configuration comprenant les données que vous aurez au préalable rentrées."


#define		ARE_YOU_SURE	"Etes vous sur de vouloir créer une nouvelle configuration de la scène du raytracer."

#include	<gtk/gtk.h>

GtkWidget	*g_ptr_vvbox;
GtkWidget	*g_sph_box;
GtkWidget	*g_sph_info;
int		g_rm;
int		g_cr_inf;
int		g_cr_col;

struct		s_object
{
  int		type;
  int		x;
  int		y;
  int		z;
  int		rot_x;
  int		rot_y;
  int		rot_z;
  int		info[2];
  int		brill;
  int		reflex;
  int		transp;
  int		red;
  int		green;
  int		blue;
  struct	s_object	*next;
  struct	s_object	*prev;
};

typedef	struct	s_object	t_object;

struct		s_conf_sph
{
  void		(*func)(GtkWidget *, gpointer);
};

typedef struct	s_conf_sph	t_conf_sph;

t_object	*g_list;

void		create_window(GtkWidget **);
void		create_box(GtkWidget **, GtkWidget **);
void		create_menu(GtkWidget **, GtkWidget *);
void		init_menu_item(GtkWidget **, GtkWidget *);
void		create_menu_object(GtkWidget **, GtkWidget **);
void		create_menu_about(GtkWidget **, GtkWidget *);
void		quit_rt_menu(GtkWidget *, gpointer);
void		free_list(GtkWidget *, gpointer);
char		*my_strcpy(char *);
void		version_rt_menu(GtkWidget *, gpointer);
void		team_rt_menu(GtkWidget *, gpointer);
void		other_rt_menu(GtkWidget *, gpointer);
void		*xmalloc(int);
int		my_strcmp(const char *, char *);

void		config_sphere(GtkWidget *, gpointer);
void		config_cylinder(GtkWidget *, gpointer);
void		config_cone(GtkWidget *, gpointer);
void		config_prism(GtkWidget *, gpointer);
void		config_pyramid(GtkWidget *, gpointer);
void		config_cube(GtkWidget *, gpointer);

void		config_spot(GtkWidget *, gpointer);
void		create_spot_button(GtkWidget **, GtkWidget *);
void		create_button_for_color_spot(GtkWidget **, GtkWidget *);

void		config_plan(GtkWidget *, gpointer);
void		create_pos_plan(GtkWidget **);
void		func_signal_plan_z(GtkWidget *, gpointer);

void		file_select();
void		recup_path(GtkWidget *, GtkWidget *);
void		cancel_button(GtkWidget *, GtkWidget *);
void		init_val_list(t_object **);

void		info(GtkWidget *, gpointer);
void		info_p(GtkWidget *, gpointer);
void		create_button(GtkWidget **, GtkWidget *);
void		create_info(GtkWidget **);
void		create_button_info(GtkWidget **, GtkWidget *);
void		create_button_for_p(GtkWidget **, GtkWidget *);
void		create_info_for_p(GtkWidget **);
void		create_button_info_for_p(GtkWidget **, GtkWidget *);

void		plan_info(GtkWidget *, gpointer);
void		create_plan_info(GtkWidget **);
void		create_plan_button_info(GtkWidget **, GtkWidget *);
void		create_plan_button(GtkWidget **, GtkWidget *);
void		create_pos_plan(GtkWidget **);
void		func_signal_plan_z(GtkWidget *, gpointer);

void		cube_info(GtkWidget *, gpointer);
void		create_cube_info(GtkWidget **);
void		create_cube_button_info(GtkWidget **, GtkWidget *);
void		create_cube_button(GtkWidget **, GtkWidget *);

void		color(GtkWidget *, gpointer);
void		color_spot(GtkWidget *, gpointer);
void		color_plan(GtkWidget *, gpointer);
void		color_p(GtkWidget *, gpointer);
void		color_cube(GtkWidget *, gpointer);
void		create_spot_button(GtkWidget **, GtkWidget *);
void		create_button_for_color_spot(GtkWidget **, GtkWidget *);
void		create_button_for_color_plan(GtkWidget **, GtkWidget *);
void		create_button_for_color_p(GtkWidget **, GtkWidget *);
void		create_button_for_color_cube(GtkWidget **, GtkWidget *);

void		create_blue_color();
void		create_red_color();
void		create_green_color();
void		put_color(int, GtkWidget **);
void		change_color(GtkWidget *, gpointer);
void		create_button_for_color(GtkWidget **, GtkWidget *);
void		go_to_config(GtkWidget *, gpointer);
void		red_change(GtkWidget *, gpointer);
void		blue_change(GtkWidget *, gpointer);
void		green_change(GtkWidget *, gpointer);

GtkWidget	*create_bar(char *, GtkWidget **, GtkWidget **);
void		add_config(GtkWidget *, gpointer);
void		save_info0(GtkWidget *, gpointer);
void		save_info1(GtkWidget *, gpointer);
void		save_trans(GtkWidget *, gpointer);
void		save_ref(GtkWidget *, gpointer);
void		save_brill(GtkWidget *, gpointer);

void		func_signal_x(GtkWidget *, gpointer);
void		func_signal_y(GtkWidget *, gpointer);
void		func_signal_z(GtkWidget *, gpointer);
void		func_signal_rotate_x(GtkWidget *, gpointer);
void		func_signal_rotate_y(GtkWidget *, gpointer);
void		func_signal_rotate_z(GtkWidget *, gpointer);

#endif
