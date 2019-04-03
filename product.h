#ifndef PRODUCT_H
#define PRODUCT_H

#include "lib.h"

typedef struct Date {
	int day;
	int month;
	int year;
}	Date;

typedef struct Product {
	char	*title;
	char	*category;
	long	quantity;
	struct	Date date;
}	Product;

Product	*createProduct(char *title, char *category,
		long quantity, Date date);
void	destroyProduct(Product *product);
char	*getTitle(Product *product);
char	*getCategory(Product *product);
void	print_product(Product product);

#endif
