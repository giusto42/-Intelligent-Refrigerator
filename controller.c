#include "controller.h"

Controller 	*createController(ProductRepo *repo)
{
	Controller *ctrl = (Controller*) malloc(sizeof(Controller));

	ctrl->repo = repo;

	return ctrl;
}

void		destroyController(Controller *ctrl)
{
	destroyRepo(ctrl->repo);
	free(ctrl);
}

bool		addProductCtrl(Controller *ctrl, Product *product)
{
	return addProduct(ctrl->repo, product);
}

bool		updateProductCtrl(Controller *ctrl, Product *product)
{
	return updateProduct(ctrl->repo, product);
}

bool		deleteProductCtrl(Controller *ctrl, Product *product)
{
	return deleteProduct(ctrl->repo, product);
}

Product 	*findByPosCtrl(Controller *ctrl, int pos)
{
	return findByPos(pos, ctrl->repo);
}

Product 	*findByTitleCtrl(Controller *ctrl, char *title, int *size)
{
	Product *product = findByTitle(title, ctrl->repo, size);
	orderAscending(product, (*size));
	return product;
}

Product 	*findAndOrderByTitleCtrl(Controller *ctrl, char *substring, int *size)
{
	Product *product = findBySubstring(substring, ctrl->repo, size);
	sort(product, (*size));
	return product;
}

Product		*findByCategoryCtrl(Controller *ctrl, char *category, int *size, Date date)
{
	Product *product = findByCategory(category, ctrl->repo, size, date);
	return product;
}

void		print_ctrl(Controller *ctrl)
{
	print_repo(ctrl->repo);
}

void		orderAscending(Product *product, int size)
{
	Product aux;
	bool ok = true;
	while (ok)
	{
		ok = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (product[i].quantity > product[i + 1].quantity)
			{
				aux				= product[i + 1];
				product[i + 1]	= product[i];
				product[i]		= aux;
				ok = true;
			}
		}
	}
}

int			compareRule(const void *s1, const void *s2)
{
  Product *product1 = (struct Product *)s1;
  Product *product2 = (struct Product *)s2;
  int titleCompare = strcmp(product1->title, product2->title);
  if (titleCompare == 0)
    return product1->quantity - product2->quantity;
  else
    return -titleCompare;
}

void		sort(Product *product, int lenght)
{ 
	qsort(product, lenght, sizeof(Product), compareRule);
} 