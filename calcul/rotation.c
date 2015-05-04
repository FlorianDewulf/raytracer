/*
** test.c for rotate in /home/grocko_t//Documents/programation/Igraph/rtv1/tp_rotate
** 
** Made by thomas grockowiak
** Login   <grocko_t@epitech.net>
** 
** Started on  Fri Feb 10 15:38:43 2012 thomas grockowiak
** Last update Sun Jun  3 23:14:41 2012 florian dewulf
*/

#include	<stdlib.h>
#include	"RT.h"

void		mult_vec_mat(double *vecteur, double **matrice)
{
  int		i;
  double	resultat[3];

  resultat[0] = 0;
  resultat[1] = 0;
  resultat[2] = 0;
  i = -1;
  while (++i < 3)
    {
      resultat[0] = resultat[0] + (matrice[i][0] * vecteur[i]);
      resultat[1] = resultat[1] + (matrice[i][1] * vecteur[i]);
      resultat[2] = resultat[2] + (matrice[i][2] * vecteur[i]);
    }
  vecteur[0] = resultat[0];
  vecteur[1] = resultat[1];
  vecteur[2] = resultat[2];
  free(matrice[0]);
  free(matrice[1]);
  free(matrice[2]);
  free(matrice);
}

void		rotation_ang(double *angle, double *to_modif)
{
  double	**matrice;

  matrice = mat_x(angle[0]);
  mult_vec_mat(to_modif, matrice);
  matrice = mat_y(angle[1]);
  mult_vec_mat(to_modif, matrice);
  matrice = mat_z(angle[2]);
  mult_vec_mat(to_modif, matrice);
}

void		rotation(int i, t_var *v, t_obj *item, double *other)
{
  double	angle[3];

  if (i < 0)
    {
      angle[0] = item->rot_x * -1;
      angle[1] = item->rot_y * -1;
      angle[2] = item->rot_z * -1;
    }
  else
    {
      angle[0] = item->rot_x;
      angle[1] = item->rot_y;
      angle[2] = item->rot_z;
    }
  if (i != 0)
    {
      if (i == 1 || i == -1)
	rotation_ang(angle, v->v_dir);
      else if (i == 2 || i == -2)
	rotation_ang(angle, v->oeil);
      else if (i == 3 || i == -3)
	rotation_ang(angle, other);
    }
}

void		rotationoeil(t_var *v, int i)
{
  double	angle[3];

  if (i == 0)
    {
      angle[0] = v->rot_oeil[0];
      angle[1] = v->rot_oeil[1];
      angle[2] = v->rot_oeil[2];
    }
  else
    {
      angle[0] = -v->rot_oeil[0];
      angle[1] = -v->rot_oeil[1];
      angle[2] = -v->rot_oeil[2];
    }
  rotation_ang(angle, v->oeil);
}
