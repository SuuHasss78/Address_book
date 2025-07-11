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



#ifndef FILE_H
#define FILE_H

#include "contact.h"

void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
