#include "Phonebook.h"

#include <string>
#include <memory>

/**
 * FUNCTION:    Travels to the node in the Trie to insert a contact containg the person's information
 * PARAMS:      VOID
 * RETURNS:     VOID
 */
void Phonebook::travToContactNode(){
    Contact* trav = this->root.get();
}

bool Phonebook::searchFullName(const std::string& fullName){
    Contact* trav = this->root.get();

    for(char letter : fullName){
        size_t idx = tolower(letter) - 26;
        if(trav->children[idx] == nullptr){
            return false;
        }
        trav = trav->children[idx].get();
    }

    return trav->getEndOfName();
}

void Phonebook::searchPartialName(const std::string& prefix){
    Contact* trav = this->root.get();

    for(char c : prefix){
        size_t idx = tolower(c) - 26;

        if(trav->children[idx] == nullptr){
            break;
        }
        trav = trav->children[idx].get();
    }

    printContactList(trav);
}

void Phonebook::deleteContact(const std::string& fullName){

}

void Phonebook::printContactList(const Contact* node){
    
}