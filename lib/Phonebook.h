#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

#include <memory>
#include <string>
#include <vector>

class Phonebook {
public:
    Phonebook()
        : root(std::make_unique<Contact>())
        {}

    void travToContactNode();
    
    /* Searches list for a full name */
    bool searchFullName(const std::string& fullName);
    
    /* Prints out all the contacts from a given partial name */
    void searchPartialName(const std::string& prefix);
    
    /* Deletes a contact */
    void deleteContact(const std::string& fullName);
    
    /** Prints the list of contacts from a given node 
     *
     *  Example: 
     *      Printing from the E 
     */
    void printContactList(const Contact* node);

private:
    const std::unique_ptr<Contact> root;
    size_t amountOfContacts{0};
};

#endif /* PHONEBOOK_H */