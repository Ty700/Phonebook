#include "Menu.h"
#include "Helpers.h"

#include <string>
#include <vector>

void printMenu() 
{
    CLEAR_SCREEN()

    const std::vector<std::string> menuOptions = {
        "Search for Contact",
        "Add Contact",
        "Edit Contact",
        "List All Contacts"
    };

    for (int i = 0; i < menuOptions.size(); i++)
    {
        printf("%d: %s", i + 1, menuOptions[i]);
    }
}

unsigned int userMenuSelection(){
    unsinged int userSel{0};
    printf("Enter in the corresponding option number: ");
    scanf()
}