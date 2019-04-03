#include "controller.h"

char	*read_category(void)
{
	char *categories[] = {"dairy", "sweets", "meat", "fruit"};
	char *category = (char *) malloc(sizeof(char) * 6);
	bool isValid = false;

	while (!isValid)
	{
		printf("Insert a category: "); scanf("%s", category);

		category[strlen(category)] = '\0';

		for (int i = 0; i < 4; i++)
			if (strcmp(categories[i], category) == 0)
			{
				isValid = true;
				break;
			}

		if (isValid == true)
			break;

		printf("Wrong category, please check if the category you insert is in this list (dairy, sweets, meat, fruit)\n");
	}
	return category;
}

Date read_date(void)
{
	struct Date date;
	int day         = 0;
	int month       = 0;
	int year        = 0;

	while (month < 1 || month > 12)
	{
		printf("Insert the month: "); scanf("%d", &month);

		if (month >= 1 && month <= 12)
			break;
		printf("Wrong month insert, insert a valid month between 1 and 12\n");	
	}

	while (true)
	{
		printf("Insert the day: "); scanf("%d", &day);

		if (month == 2)
		{
			if (day >= 1 && day <= 28)
				break;
		} 
		else 
		{

			if (day >= 1 && day <= 31)
				break;
		}
		printf("Wrong day inserted\n");
	}
	printf("Insert the year: "); scanf("%d", &year);

	date.day = day;
	date.month = month;
	date.year = year;

	return date;
}

Product	*read_a_product(void)
{
	char title[256];
	long quantity	= 0;

	printf("\nInsert a title: "); scanf("%s", title);

	char *category = read_category();

	printf("Insert the quantity: "); scanf("%ld", &quantity);

	struct Date date = read_date();

	struct Product *product = createProduct(title, category, quantity, date);

	return product;
}
