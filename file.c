/*
SUHAS BASAVARAJ
051
04 JULY 2025
AddressBook holds all contacts and the total number of contacts is stored
Feilds:
name : The contacts's full name 
phone : The contact's phone number
email : The contact's email address
AddressBook Project
*/
#include <stdio.h>
#include "file.h"
#include <string.h>

void saveContactsToFile(AddressBook *addressBook)
{
	FILE *fp = fopen("addressBook.csv", "w");
	if(fp == NULL)
	{
		printf("Error: Could not open.\n");
		return ;
	}

	fprintf(fp, "#%d\n", addressBook->contactCount);

	for(int i = 0; i < addressBook->contactCount; i++)
	{
		fprintf(fp, "%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	}

	addressBook->contactCount = 0;
	fclose(fp);

	printf("Contacts saves successfully to addressBook.csv.\n");
  
}

void loadContactsFromFile(AddressBook *addressBook)
{
	FILE *fp = fopen("addressBook.csv", "r");
	if(fp == NULL)
	{
		printf("FIle not found.Empty address Book.\n");
		addressBook->contactCount = 0;
		return ;

	}


	fscanf(fp, "#%d\n", &addressBook->contactCount);

	for(int i = 0; i < addressBook->contactCount; i++)
	{
		fscanf(fp, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
	}


	fclose(fp);

	printf("Contacts loaded Successfully.\n");

}
