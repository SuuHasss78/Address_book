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



#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>

#define MAX_CONTACTS 100

typedef struct Contact{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

int validphone(char *num);
int validEmail(char *email);
int isDuplicateName(AddressBook *addressBook,char *name);
int isDuplicatePhone(AddressBook *addressBook, char *phone);
int isDuplicateEmail(AddressBook *addressBook,char *email);

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
