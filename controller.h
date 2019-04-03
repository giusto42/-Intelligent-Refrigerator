#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "product_repo.h"

typedef struct
{
	ProductRepo *repo;
} Controller;

Controller	*createController(ProductRepo *repo);
void		destroyController(Controller *ctrl);
bool		addProductCtrl(Controller *ctrl, Product *product);
bool		updateProductCtrl(Controller *ctrl, Product *product);
bool		deleteProductCtrl(Controller *ctrl, Product *product);
Product 	*findByPosCtrl(Controller *ctrl, int pos);
Product 	*findByTitleCtrl(Controller *ctrl, char *title, int *size);
Product		*findByCategoryCtrl(Controller *ctrl, char *category, int *size, Date date);
Product 	*findAndOrderByTitleCtrl(Controller *ctrl, char *substring, int *size);
void		print_ctrl(Controller *ctrl);
void		orderAscending(Product *product, int size);
int			compareRule(const void *s1, const void *s2);
void		sort(Product *product, int lenght);

#endif