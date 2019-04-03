#ifndef UI_H
#define UI_H

#include "controller.h"

void	startUI(Controller *ctrl);
void	show_menu(void);
void	clearScreen(void);
Product	*read_a_product(void);
char	*read_category(void);
Date	read_date(void);
void	addDumyData(Controller *ctrl);

#endif