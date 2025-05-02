#include "Person.h"
#include "Helpers.h"
#include "Phonebook.h"
#include "Menu.h"

#include <iostream>
#include <memory>

int main()
{
    auto phoneBook = std::make_unique<Phonebook>();

    while(true){
        printMenu();
        userMenuSelection();
    }
}