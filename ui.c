#include "ui.h"
#include <unistd.h>

void	startUI(Controller *ctrl)
{
	addDumyData(ctrl);
	int 		user_input = 1;
	do
	{
		show_menu();
		printf("\nInsert the number: ");
		scanf("%d", &user_input);

		switch (user_input) 
		{
			case 0: {
				clearScreen();
				exit(0);
				break;
			}

			case 1: {
				clearScreen();
				printf("\nAddProduct\n");
				if (addProductCtrl(ctrl, read_a_product()))
					printf("\nCategory added succesfuly!\n");
				else
					printf("\nCategory added unsuccesfuly!\n");
				break;
			}
			case 2: {
				clearScreen();
				printf("\nUpdateProduct\n");
				if(updateProductCtrl(ctrl, read_a_product()))
					printf("\nCategory updated succesfuly!\n");
				else
					printf("\nCategory updated unsuccesfuly!\n");
				break;
			}
			case 3: {
				clearScreen();
				printf("\nDeleteProduct\n");
				if(deleteProductCtrl(ctrl, read_a_product()))
					printf("\nCategory updated succesfuly!\n");
				else
					printf("\nCategory updated unsuccesfuly!\n");
				break;
			}

			case 4: {
				clearScreen();
				printf("\nFindByPos\n");
				int pos = 0;
				printf("Pos: %d", pos); scanf("%d", &pos);
				print_product(*findByPosCtrl(ctrl, pos));
				break;
			}

			case 5: {
				clearScreen();
				printf("\nFindByTitle\n");
				char title[256] = "NULL";
				printf("Title: "); scanf("%s", title);
				
				int size = 0;
				Product *product = findByTitleCtrl(ctrl, title, &size);

				if (product != NULL)
				{
					for (int i = 0; i < size; i++)
						print_product(product[i]);
				}
				else
				{
					printf("We can't find the product with the name \"%s\" we have this products\n", title);
					print_repo(ctrl->repo);
				}
				break;
			}

			case 6: {
				clearScreen();
				printf("\nFindByCategory\n");
				char *category = read_category();
				Date date = read_date();

				int size = 0;
				Product *product = findByCategoryCtrl(ctrl, category, &size, date);

				if (product != NULL)
				{
					for (int i = 0; i < size; i++)
						print_product(product[i]);
				}
				else
				{
					printf("We can't find products in category with the name \"%s\" we have this products\n", category);
					print_repo(ctrl->repo);
				}
				break;
			}
			
			case 7: {
				clearScreen();
				printf("\nPrintAllProduct\n");
				print_ctrl(ctrl);
				break;
			}

			case 8: {
				clearScreen();
				printf("\nSubstring\n");
				char substring[256] = "NULL";
				printf("Title: "); scanf("%s", substring);
				
				int size = 0;
				Product *product = findAndOrderByTitleCtrl(ctrl, substring, &size);

				if (product != NULL)
				{
					for (int i = 0; i < size; i++)
						print_product(product[i]);
				}
				else
				{
					printf("We can't find the product with the name \"%s\" we have this products\n", substring);
					print_repo(ctrl->repo);
				}
				break;
			}

			default: {
				clearScreen();
				break;
			}
		}
	}while (user_input != 0);
}

void	show_menu(void)
{
	printf("\n\t\tWellcom in the fridge\n\n");
	printf("Chose what subsection you want to run:\n");
	printf("1. Add a product\n");
	printf("2. Update a product\n");
	printf("3. Delete a product\n");
	printf("4. Show the product at pos\n");
	printf("5. Show the products with title orderd by quantity\n");
	printf("6. Show the product that is in category\n");
	printf("7. Show all the product\n");
	printf("8. Show all the product with title orderd by title\n");
	printf("0. Exit\n");
}

void	clearScreen(void)
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void	addDumyData(Controller *ctrl)
{
	Date date;
	date.year = 2023;
	date.month = 2;
	date.day = 10;

	char title[] = "Title";
	char category[] = "sweets";
	date.year = 2023;
	Product *prod1 = createProduct(title, category, 12, date);

	char title1[] = "Title2";
	char category1[] = "dairy";
	date.year = 2020;
	Product *prod2 = createProduct(title1, category1, 12, date);

	char title2[] = "Title3";
	char category2[] = "meat";
	date.year = 2021;
	Product *prod3 = createProduct(title2, category2, 12, date);

	char title3[] = "Title";
	char category3[] = "fruit";
	date.year = 2020;
	Product *prod4 = createProduct(title3, category3, 5, date);

	char title4[] = "Title4";
	char category4[] = "sweets";
	date.year = 2021;
	Product *prod5 = createProduct(title4, category4, 12, date);

	char title5[] = "Title";
	char category5[] = "dairy";
	date.year = 2020;
	Product *prod6 = createProduct(title5, category5, 1, date);

	char title6[] = "Title3";
	char category6[] = "sweets";
	date.year = 2023;
	Product *prod7 = createProduct(title6, category6, 12, date);
	
	addProductCtrl(ctrl, prod1);
	addProductCtrl(ctrl, prod2);
	addProductCtrl(ctrl, prod3);
	addProductCtrl(ctrl, prod4);
	addProductCtrl(ctrl, prod5);
	addProductCtrl(ctrl, prod6);
	addProductCtrl(ctrl, prod7);
}