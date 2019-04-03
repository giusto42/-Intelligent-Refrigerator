#include "product.h"

Product	*createProduct(char *title, char *category,
		long quantity, Date date)
{
	Product *product = (Product*) malloc(sizeof(Product));

	product->title = (char*) malloc(sizeof(char) * (strlen(title) + 1));
	title[strlen(title)] = '\0';
	strcpy(product->title, title);

	product->category = (char*) malloc(sizeof(char) * (strlen(category) + 1));
	category[strlen(category)] = '\0';
	strcpy(product->category, category);

	product->quantity = quantity;
	product->date = date;

	return product;
}

void	destroyProduct(Product *product)
{
	free(product->title);
	free(product->category);

	free(product);
}

char	*getTitle(Product *product)
{
	return product->title;
}

char	*getCategory(Product *product)
{
	return product->category;	
}

void	print_product(Product product)
{
	printf("\nThe product is:\nTitle: %s\nCategory: %s\nQuantity: %ld\nDate: %d/%d/%d\n",
			product.title, product.category, product.quantity,
			product.date.day, product.date.month, product.date.year);
}



