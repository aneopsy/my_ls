/*
** my_digit_manager.h for myls in /home/theis_p/my_ls/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 04:57:36 2015 THEIS Paul
** Last update Fri Nov 27 05:57:20 2015 THEIS Paul
*/

#ifndef MY_DIGIT_MANAGER_H_
# define MY_DIGIT_MANAGER_H_

# define MININT		(-2147483647 - 1)
# define MAXINT		(2147483647)

int	nbrDigit(int n);
t_max	*my_find_digit(t_my_file *files);

#endif /* !MY_DIGIT_MANAGER_H_ */
