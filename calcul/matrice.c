/*
** matrice.c for raytracer in /home/lund/svn/calcul
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Sun Jun  3 15:33:35 2012 florian dewulf
** Last update Sun Jun  3 23:13:48 2012 florian dewulf
*/

#include	<stdlib.h>
#include	<math.h>
#include	"RT.h"

double		**mat_x(double angle)
{
  double	**matrice;

  matrice = xmalloc(3 * sizeof(double *));
  matrice[0] = xmalloc(3 * sizeof(double));
  matrice[1] = xmalloc(3 * sizeof(double));
  matrice[2] = xmalloc(3 * sizeof(double));
  matrice[0][0] = 1;
  matrice[0][1] = 0;
  matrice[0][2] = 0;
  matrice[1][0] = 0;
  matrice[1][1] = cos(angle * PI_RAD);
  matrice[1][2] = -sin(angle * PI_RAD);
  matrice[2][0] = 0;
  matrice[2][1] = sin(angle * PI_RAD);
  matrice[2][2] = cos(angle * PI_RAD);
  return (matrice);
}

double		**mat_y(double angle)
{
  double	**matrice;

  matrice = xmalloc(3 * sizeof(double *));
  matrice[0] = xmalloc(3 * sizeof(double));
  matrice[1] = xmalloc(3 * sizeof(double));
  matrice[2] = xmalloc(3 * sizeof(double));
  matrice[0][0] = cos(angle * PI_RAD);
  matrice[0][1] = 0;
  matrice[0][2] = sin(angle * PI_RAD);
  matrice[1][0] = 0;
  matrice[1][1] = 1;
  matrice[1][2] = 0;
  matrice[2][0] = -sin(angle * PI_RAD);
  matrice[2][1] = 0;
  matrice[2][2] = cos(angle * PI_RAD);
  return (matrice);
}

double		**mat_z(double angle)
{
  double	**matrice;

  matrice = xmalloc(3 * sizeof(double *));
  matrice[0] = xmalloc(3 * sizeof(double));
  matrice[1] = xmalloc(3 * sizeof(double));
  matrice[2] = xmalloc(3 * sizeof(double));
  matrice[0][0] = cos(angle * PI_RAD);
  matrice[0][1] = -sin(angle * PI_RAD);
  matrice[0][2] = 0;
  matrice[1][0] = sin(angle * PI_RAD);
  matrice[1][1] = cos(angle * PI_RAD);
  matrice[1][2] = 0;
  matrice[2][0] = 0;
  matrice[2][1] = 0;
  matrice[2][2] = 1;
  return (matrice);
}
