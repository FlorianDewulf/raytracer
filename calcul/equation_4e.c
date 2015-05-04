/*
** equation_4e.c for RT in /home/mailli_r//Documents/Igraph/RT/calcul
** 
** Made by remi mailliet
** Login   <mailli_r@epitech.net>
** 
** Started on  Fri Jun  1 16:36:04 2012 remi mailliet
** Last update Sat Jun  2 19:54:09 2012 florian dewulf
*/

#include	<math.h>
#include	"RT.h"

double		ret_3deg(double k[], double e)
{
  int		i;
  double	ret;

  i = -1;
  ret = SAFE;
  while (++i < 3)
    if (k[i] < ret && k[i] > e)
      ret = k[i];
  if (ret == SAFE)
    return (0);
  return (ret);
}

double		equation_3deg(double a[])
{
  int		i;
  double	q;
  double	r;
  double	d;
  double	k[3];

  i = 3;
  while (i >= 0)
    a[i--] /= a[3];
  q = (pow(a[2], 2) - 3.0 * a[1]) / 9.0;
  r = (a[2] * (pow(a[2], 2) - 4.5 * a[1]) + 13.5 * a[0]) / 27.0;
  d = pow(q, 3) - pow(r, 2);
  if (d >= 0)
    {
      while (++i < 3)
	k[i] = (-2.0 * pow(q, (1 / 2)))
	  * cos((acos(r / pow(q, (3 / 2)) / 3))
		+ 2.0 * M_PI * (i / 3)) - a[2] / 3.0;
      return (ret_3deg(k, a[0]));
    }
  if (r < 0)
    return (pow((pow(-d, 1 / 2) + fabs(r)), (1 / 3))
	    + q / pow((pow(-d, 1 / 2)+ fabs(r)), (1 / 3)) - a[2] / 3.0);
  return (-pow((pow(-d, 1 / 2) + fabs(r)), (1 / 3))
	  + q / pow((pow(-d, 1 / 2) + fabs(r)), (1 / 3)) - a[2] / 3.0);
}
