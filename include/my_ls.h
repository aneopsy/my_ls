/*
** my_ls.h for myls in /home/theis_p/my_ls/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 02:54:13 2015 THEIS Paul
** Last update Sun Nov 29 19:03:40 2015 THEIS Paul
*/

#ifndef MY_LS_H_
# define MY_LS_H_

# define RECURSIVE	0
# define REVERSE	1
# define DIRC		2
# define LONG		3
# define TIME		4
# define GROUP		5
# define NOTSORT	6
# define OWNER		7
# define INDICATOR	8
# define ALL		9
# define INFGRP		10
# define BACKUP		11
# define SIZE		12
# define QUOTE		13

# include <time.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <errno.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>

# include "my.h"
# include "my_memutilis.h"
# include "my_file.h"
# include "my_color.h"
# include "my_date.h"
# include "my_digit_manager.h"
# include "my_display.h"
# include "my_read.h"
# include "my_checkator.h"
# include "my_path.h"
# include "my_display_l.h"
# include "my_options.h"
# include "my_sort.h"
# include "my_function.h"

#endif /* !MY_LS_H_ */
