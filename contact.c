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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"


// to check if phone number is vaild
int validphone(char *num)
{
	if(strlen(num) != 10)//checking for number condition
		return 0;

	for(int i = 0;i < 10;i++)
	{
		if(!isdigit(num[i]))
		{
			return 0;
		}
	}

	return 1;
}

// to check if email is vaild
int validEmail(char *email)
{
	if(strstr(email, "@") == NULL || strstr(email, ".com") == NULL)//checking for email conditiom
	{
		return 0;
	}
  
	int isLower = 0, isDigit = 0, isSpecial = 0;

	for(int i = 0; email[i]; i++)
	{
		if(islower(email[i]))
		{
			isLower = 1;
		}

		else if(isdigit(email[i]))
		{
			isDigit = 1;
		}

		else if(ispunct(email[i]))
		{
			isSpecial = 1;
		}
	}
	return (isLower && isDigit && isSpecial);
}

//to check for duplicate name
int isDuplicateName(AddressBook *addressBook,char *name)
{
	for(int i = 0; i< addressBook -> contactCount; i++)
	{
		if(strcmp(addressBook->contacts[i].name,name) == 0 )
			{
				return 1;
			}
		}
		return 0;
}
//handling multiple matches
int isDuplicatePhone(AddressBook *addressBook, char *phone)
{
	for(int i = 0; i< addressBook -> contactCount; i++)
	{
		if(strcmp(addressBook->contacts[i].phone,phone) == 0 )
			{
				return 1;
			}
		}
		return 0;
}
//handling multiple matches
int isDuplicateEmail(AddressBook *addressBook, char *email)
{
	for(int i = 0; i< addressBook -> contactCount; i++)
	{
		if(strcmp(addressBook->contacts[i].email,email) == 0)
			{
				return 1;
			}
	}
		return 0;
}


void listContacts(AddressBook *addressBook) 
{
    /* Define the logic for print the contacts */
    //printf("%s\n", addressBook->contacts[addressBook->contactCount].name);
    if(addressBook -> contactCount == 0)
    {
	    printf("No contacts to display.\n");
	    return;
    }

    for(int i = 0; i < addressBook -> contactCount; i++)
    {
	    printf("\nContact %d:\n",i + 1);
	    printf("Name : %s\n",addressBook -> contacts[i].name);
            printf("Phone : %s\n",addressBook -> contacts[i].phone);
	    printf("Email : %s\n",addressBook -> contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
 //   populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
   	loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	if(addressBook->contactCount >= MAX_CONTACTS)
	{
		printf("Address book is full.\n");
		return;
	}

         Contact *c = &addressBook->contacts[addressBook->contactCount];

   // printf("Enter name: ");
    //scanf(" %[^\n]", c->name);

    do
    {
	    printf("Enter name: ");
	    scanf(" %[^\n]", c->name);

	    if(isDuplicateName(addressBook, c->name))//checking duplicate name
	    {
		    printf("Duplicate Name found,\n");
		    printf("Try Again.\n");
	    }

    }while (isDuplicateName(addressBook, c->name));



    do
    {
	    printf("Enter Phone: ");
            scanf(" %s", c->phone);

	   
	    if(!validphone(c -> phone))//validating phone number
	    {
		    printf("Invalid phone number.\n");
		    printf("Enter only 10 digits :\n");
	    }
	    else if(isDuplicatePhone(addressBook, c -> phone))//checking duplicate number so that its not repeated
	    {
		    printf("Opps.\n");
		    printf("Duplicate Number found\n");
		    printf("TRy Again\n");
	    }

    } while(!validphone(c->phone) || isDuplicatePhone(addressBook, c -> phone));


    printf("Phone  added successfully.\n");

    
    do
    {
	    printf("Enter email: ");
	    scanf(" %s", c->email);
	   
	    if(!validEmail(c->email))//validating email condition
	    {
		    printf("Invaild email address.\n");
		    printf("Email requires'@'  '.com' and Numbers:\n");
		    printf("EXAMPLE : harsh12@gmail.com\n");
	    }
	    else if(isDuplicateEmail(addressBook, c -> email))//checking duplicate email so that its not reoeated
	    {
		    printf("Opps.\n");
		    printf("Duplicate Email found\n");
		    printf("TRy Again\n");
	    }
	    
    } while(!validEmail(c->email) ||  isDuplicateEmail(addressBook, c -> email));
   
  
    addressBook->contactCount++;
    printf("Contact added successfully.\n");

}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
	char search[50];
	int flag = 0, opt;

	printf("Search by : \n");
	printf("1. Name\n");
	printf("2. Phone\n");
	printf("3. Email\n");
	printf("Enter your option: ");
	scanf("%d",&opt);

	printf("Enter the value to search: ");
	scanf(" %[^\n]", search);

	for(int i = 0; i < addressBook->contactCount; i++)//using for loop to list all the contacts
	{

		int  found = 0;

		switch (opt)//using switch case to list the contact with name,phone,email
		{
			case 1:
				found = (strcmp(addressBook->contacts[i].name, search) == 0);
				break;
			case 2:
				found = (strcmp(addressBook->contacts[i].phone, search) == 0);
				break;
			case 3:
				found = (strcmp(addressBook->contacts[i].email, search) == 0);
				break;
			default:
				printf("INvalid option.\n");
				return;
		}

		if(found)
		{
			flag = 1;
			printf("Match %d Found\n", i + 1);
			printf("Name : %s\n",addressBook->contacts[i].name);
	                printf("Name : %s\n",addressBook->contacts[i].phone);
	                printf("Name : %s\n",addressBook->contacts[i].email);
		}
	}

	if(!flag)
	{
		printf("Contact not found.\n");
	}
}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
	char search[50];
	int matches[50];
	int opt; // index of the final contact selected for editing
	int  searchopt, editopt;
	int count = 0;

	printf("Search contact by :\n");
	printf("1.Name\n2. Phone\n3. Email\n");
	printf("Enter your option: ");
	scanf("%d", &searchopt);

	printf("Enter the value to edit: ");
	scanf(" %[^\n]", search);

	for(int i = 0; i < addressBook->contactCount; i++)//after entering the value it will list the required contact
	{
		int match = 0;
		if(searchopt == 1 && strcmp(addressBook->contacts[i].name, search) == 0)
		{
			match = 1;
		}
		else if(searchopt == 2 && strcmp(addressBook->contacts[i].phone, search) == 0)
		{
			match = 1;
		}
        	else if(searchopt == 3 && strcmp(addressBook->contacts[i].email, search) == 0)
		{
			match = 1;
		}

		if(match)
		{
			matches[count++] = i;
		}
	}

	if(count == 0)
	{
		printf("NO contact FOund.\n");
		return;
	}
       
	if(count >  1)//using if because mulpite contact are found
		{
			printf("Muplite contacts found matching '%s':\n",search);

			for(int i = 0;i < count; i++)
			{
				int idx = matches[i];

				printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1,
						addressBook->contacts[idx].name,
						addressBook->contacts[idx].phone,
						addressBook->contacts[idx].email);
			}

	printf("Select the contact number to edit ( 1 to %d): ",count);
	scanf("%d", &opt);

         if(opt < 1 || opt > count)
	 {
		 printf("Invaild Selection.\n");
		 return;
	 }

	 opt = matches[opt - 1];// array is zero based so only (opt - 1)
		}
	else
       	{
		opt = matches[0];
	}



	printf("Editing Contact Detail:\n");
	printf("Name : %s\n",addressBook->contacts[opt].name);
	printf("Phone : %s\n",addressBook->contacts[opt].phone);
	printf("Email : %s\n",addressBook->contacts[opt].email);

        printf("Select what to edit :\n");
	printf("1.Name\n2. Phone\n3. Email\n");
	printf("Enter your option: ");
	scanf("%d", &editopt);

	switch(editopt)//using switch case to select the required input from the user
	{
		case 1:
			printf("Enter the name: ");
			scanf(" %[^\n]", addressBook->contacts[opt].name);
			break;
		case 2:
			do 
			{
				printf("Enter the new Phone: ");
				scanf(" %s",addressBook->contacts[opt].phone);

				if(!validphone(addressBook->contacts[opt].phone))
				{
					printf("Invalid phone number.\n");
					printf("Enter only 10 digits only.\n");
				}
			       	else if(isDuplicatePhone(addressBook, addressBook->contacts[opt].phone))
		    		{
				       	printf("Opps.\n");
		    			printf("Duplicate Email found\n");
		    			printf("TRy Again\n");
			       	}

			}while(!validphone(addressBook->contacts[opt].phone) || isDuplicatePhone(addressBook, addressBook->contacts[opt].phone));
			break;
		case 3:
			do
			{
				printf("Enter email: ");
				scanf(" %s", addressBook->contacts[opt].email);					

				if(!validEmail(addressBook->contacts[opt].email))
				{
					printf("Invaild email address.\n");
					printf("Email requires'@' and '.com':\n");
					printf("Example harsh12@gmail.com\n");
				}
				else if(isDuplicateEmail(addressBook, addressBook->contacts[opt].email))
				{
				       	printf("Opps.\n");
		    			printf("Duplicate Email found\n");
		    			printf("TRy Again\n");
			       	}


			}while(!validEmail(addressBook->contacts[opt].email) || isDuplicateEmail(addressBook, addressBook->contacts[opt].email));
			break;
		default:
			printf("Invalid option\n");
			return;
	}

	printf("Contact updated SUCCESSFULLY\n");
	return;

}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
	char search[50];
	int match[50];
        int flag = 0, opt;


	printf("Delete by : \n");
	printf("1. Name\n");
	printf("2. Phone\n");
	printf("3. Email\n");
	printf("Enter your option: ");
	scanf("%d",&opt);

	printf("Enter the value to Delete: ");
	scanf(" %[^\n]", search);

	for(int i = 0; i < addressBook->contactCount; i++)
	{

		int  found = 0;

		switch (opt)//using swutch case to match the value enter selected by user
		{
			case 1:
				found = (strcmp(addressBook->contacts[i].name, search) == 0);
				break;
			case 2:
				found = (strcmp(addressBook->contacts[i].phone, search) == 0);
				break;
			case 3:
				found = (strcmp(addressBook->contacts[i].email, search) == 0);
				break;
			default:
				printf("INvalid option.\n");
				return;
		}

		if(found)
		{
			match[flag++]  = i;
		}
	}

	if(flag == 0)
	{
		printf("Contact not FOund");
		return;
	}

	printf("MAtching contacts: \n");
	for(int i = 0; i < flag; i++)
	{
		int id = match[i];
		printf("%d.  Name : %s\n",i + 1,addressBook->contacts[id].name);
		printf("    Phone : %s\n",addressBook->contacts[id].phone);
		printf("    Email : %s\n", addressBook->contacts[id].email);
	}

	int choice;
	printf("Select the contact to delete (1 to %d): ",flag);
	scanf("%d",&choice);

	if(choice < 1 || choice > flag)
	{
		printf("Invalid Selection . Go back.\n");
		return;
	}

	int del = match[choice - 1];

	for(int i = del; i < addressBook->contactCount-1;i++)
	{
		addressBook->contacts[i] = addressBook->contacts[i + 1];
	}
	addressBook->contactCount--;

	printf("Contact deleted Successfully.\n");
}
