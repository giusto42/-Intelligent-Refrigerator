#include "product_repo.h"

ProductRepo *createRepo()
{
	ProductRepo	*repo = (ProductRepo*) malloc(sizeof(ProductRepo));
	repo->length = 0;
	repo->product = (Product*) malloc(sizeof(Product) + repo->length);

	return repo;
}

void		destroyRepo(ProductRepo *repo)
{
	destroyProduct(repo->product);
	free(repo);
}

int			findProduct(char *title, char *category, ProductRepo* repo)
{
	for (int i = 0; i < repo->length; i++)
		if ((strcmp(repo->product[i].title, title) == 0) &&
		 (strcmp(repo->product[i].category, category) == 0))
			return i;
	return -1;
}

bool		addProduct(ProductRepo *repo, Product *product)
{
	if (findProduct(product->title, product->category, repo) == -1) {
		repo->length += 1;
		Product *copy_product = realloc(repo->product, repo->length);
		repo->product = copy_product;
		repo->product[repo->length - 1] = *product;
		return true;
	}

	return false;
}

bool		updateProduct(ProductRepo *repo, Product *product)
{
	int index = findProduct(product->title, product->category, repo);
	if (index == -1) {
		if(addProduct(repo, product))
			return true;
	} else {
		if (product->quantity <= 0)
			repo->product[index].quantity += 1;
		else
			repo->product[index].quantity += product->quantity; 
		return true;
	}

	return false;
}

bool		deleteProduct(ProductRepo *repo, Product *product)
{
	int index = findProduct(product->title, product->category, repo);

	if (index == -1)
		return false;
	
	while (index < repo->length)
	{
		repo->product[index] = repo->product[index + 1];
		index++;
	}

	repo->length -= 1;

	return true;
}

Product 	*findByPos(int pos, ProductRepo *repo)
{
	if (pos < repo->length)
	{
		return &repo->product[pos];
	}
	return NULL;
}

Product	 	*findByTitle(char *title, ProductRepo *repo, int *size)
{
	Product *product = (Product*) malloc(sizeof(Product) + 1);
	int length = 0;
	for (int i = 0; i < repo->length; i++)
	{
		if (strcmp(repo->product[i].title, title) == 0)
		{
			Product *newProd = realloc(product, length + 1);
			product = newProd;
			product[length] = repo->product[i];
			length++;
		}
	}

	if (size == 0)
		return NULL;

	(*size) = length;
	return product;
}

Product 	*findByCategory(char *category, ProductRepo *repo, int *size, Date date)
{
	Product *product = (Product*) malloc(sizeof(Product) + 1);
	int length = 0;
	for (int i = 0; i < repo->length; i++)
	{
		if (strcmp(repo->product[i].category, category) == 0 &&
			repo->product[i].date.year == date.year)
		{
			Product *newProd = realloc(product, length + 1);
			product = newProd;
			product[length] = repo->product[i];
			length++;
		}
	}

	if (size == 0)
		return NULL;

	(*size) = length;
	return product;
}

Product 	*findBySubstring(char *substring, ProductRepo *repo,int *size)
{
	Product *product = (Product*) malloc(sizeof(Product) + 1);
	int length = 0;
	for (int i = 0; i < repo->length; i++)
	{
		if (strstr(repo->product[i].title, substring) != NULL)
		{
			Product *newProd = realloc(product, length + 1);
			product = newProd;
			product[length] = repo->product[i];
			length++;
		}
	}

	if (size == 0)
		return NULL;

	(*size) = length;
	return product;
}

void		print_repo(ProductRepo *repo)
{
	for (int i = 0; i < repo->length; i++)
		print_product(repo->product[i]);
}