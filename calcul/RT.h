/*
** RT.h for RT in /home/mailli_r//Documents/Igraph/RT
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Tue May 15 16:42:11 2012 remi mailliet
** Last update Mon Jun  4 14:21:02 2012 florian dewulf
*/

#ifndef				__RT_H__
#define				__RT_H__

#define				LEN_X		800.0
#define				LEN_Y		600.0

#define				X_OEIL		-800
#define				Y_OEIL		0
#define				Z_OEIL		300

#define				ANG_OEILX	0
#define				ANG_OEILY	0
#define				ANG_OEILZ	0

#define				NB_OB		4

#define				POW(x)		(x = (x * x))

#define				SAFE		pow(10, 308)
#define				PI_RAD		0.017453293

struct			 	s_obj
{
  int				type;
  int				color;
  double			info[2];
  double			brill;
  double			pos_x;
  double			pos_y;
  double			pos_z;
  double			rot_x;
  double			rot_y;
  double			rot_z;
  double			k;
  double			x[3];
  double			y[3];
  double			z[3];
};

struct				s_spot
{
  int				x;
  int				y;
  int				z;
  int				type;
  double			rot_x;
  double			rot_y;
  double			rot_z;
  int				color;
  double			power;
  struct s_spot			*next;
  struct s_spot			*prev;
};

struct				s_var
{
  void				*mlx;
  void				*img;
  void				*win;
  char				*data;
  int				bpp;
  int				sizeline;
  int				endian;
  double			oeil[3];
  double			rot_oeil[3];
  double			v_dir[3];
  struct s_obj			*list;
  struct s_spot			*spot_list;
  int				cren_val;
  int				pix_th[4];
  int				item;
};

struct				s_head_bmp
{
  int				size_file;
  int				reserv;
  int				offset;
  int				size_head;
  int				wight;
  int				height;
  int				plan_pronf;
  int				compression;
  int				size_img;
  int				reso_x;
  int				reso_y;
  int				palette_one;
  int				palette_two;
};

typedef struct	s_obj		t_obj;
typedef struct	s_spot		t_spot;
typedef struct	s_var		t_var;
typedef struct	s_head_bmp	t_head_bmp;

enum type {
  PLAN,
  SPH,
  CYL,
  CONE,
  PRISME,
  PYRAMIDE,
  CUBE,
  TORE,
  OB_TYPE
};

void				toast(t_var*);

/*
** multi_thread.c
*/

void				gere_thread(t_var*);

/*
** ambiance.c
*/

void				take_normal(int, double[], double[]);
void				modify(double[], double[], t_var*, int);
int				ambiance(t_var*);

/*
** ombre.c
*/

int				ombre(t_var*, double[], t_spot*, int);
double				f_ombre(t_var*, double[], t_spot*, int);

/*
** lumen.c
*/

int				brillance(t_spot*, double, int, int);
void				lumen(t_var*, t_spot*, double[], int[]);

/*
** other.c
*/

double				norme(double[]);
int				len_spot(t_spot*);
void				inter(double[], double[], double[], double);

/*
** mov.c
*/
void				mov(void (*[])(t_var*, t_obj*), t_var*, int);

/*
** rotation.c
*/

void				mult_vec_mat(double *, double **);
void				rotation_ang(double *, double *);
void				rotation(int, t_var *, t_obj *, double *);
void				rotationoeil(t_var *, int);

/*
** matrice.c
*/

double				**mat_x(double);
double				**mat_y(double);
double				**mat_z(double);

/*
** inter.c
*/

double				k_secdegre(double, double, double);
void				inter_plan(t_var*, t_obj*);
void				inter_sphere(t_var*, t_obj*);
void				inter_cyl(t_var*, t_obj*);
void				inter_cone(t_var*, t_obj*);
double				inter_triangle(t_var*, t_obj*);
double				inter_para(t_var*, t_obj*);
void				inter_prisme(t_var*, t_obj*);
void				inter_pyramide(t_var*, t_obj*);
void				inter_cube(t_var*, t_obj*);
void				inter_tore(t_var*, t_obj*);

/*
** calc.c
*/

void				parse_pix_multith(t_var*, double, double, t_var*);
int				which_k(t_var*);

/*
** trace.c
*/

int				rgb_to_hex(int, int, int);
void				hex_to_rgb(int, int*, int*, int*);
void				my_pixel_put(t_var*, int, int, int);

/*
** func.c
*/

void				my_putstr(char*);
void				*xmalloc(int);
void				load(void);
int				my_strlen(char *);

/*
** main.c
*/

int				main(int, char **);

/*
** convert_to_bmp.c
*/

void				convert_to_bmp(t_var *);

/*
** print_data_bmp.c
*/

void				print_data_bmp(t_var *, int);

/*
** concate.c
*/

char				*concate(char *, char *);

/*
** my_puterror.c
*/

void				*my_puterror_null(char *);
int				my_puterror_int(char *);

/*
** check_file.c
*/

int				check_bmp(char *);

/*
** parsing_bmp.c
*/

t_var				*check_file(char *);

/*
** comp.c
*/

int				comp(char *, char *);

/*
** lex.c
*/

t_obj				*lex(t_spot **, int, int *);

/*
** copy_list.c
*/

t_obj				*copy_list(t_obj *, int);

/*
** init_ptr_func.c
*/

void				init_ptr_func(void (*[])(t_var *, t_obj *));

/*
** parsing.c
*/

void				parse(t_obj *, int);
int				reduc_main(int, char **);

/*
** translation.c
*/

void				mov1(t_var *, t_obj *, double *);
void				mov2(t_var *, t_obj *, double *);

/*
** equation_4e.c
*/

double				equation_3deg(double *);
double				ret_3deg(double *, double);

#endif
