#ifndef PRODUCT_REPO_H
#define PRODUCT_REPO_H

#include "product.h"

typedef struct ProductRepo {
	Product 	*product;
	int			length;
}	ProductRepo;

ProductRepo *createRepo();
void		destroyRepo(ProductRepo *repo);
bool		addProduct(ProductRepo *repo, Product *product);
int			findProduct(char *title, char *category, ProductRepo* repo);
Product 	*findByPos(int pos, ProductRepo *repo);
bool		updateProduct(ProductRepo *repo, Product *product);
bool		deleteProduct(ProductRepo *repo, Product *product);
Product	 	*findByTitle(char *title, ProductRepo *repo, int *size);
Product		*findByCategory(char *category, ProductRepo *repo, int *size, Date date);
Product 	*findBySubstring(char *substring, ProductRepo *repo,int *size);
void		print_repo(ProductRepo *repo);

#endif