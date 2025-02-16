#include "Person.h"

#include <iostream>
#include <string>
#include <iomanip>

/**
 * FUNC:    Capture's a person's full name
 * PARAMS:  VOID
 * RETS:    VOID 
 */
static void setName(std::string& first, std::string& last)
{
    std::cout << "Enter a Person's First Name: ";
    std::getline(std::cin, first);
    std::cout << "Enter " << first <<"'s last name: ";
    std::getline(std::cin, last);
}

/**
 * FUNCTION:    Prints the menu for setAddress | Just a helper for setAddress
 * PARAMS:      Person's name | Peron's address information array
 * RETURNS:     VOID 
 */
static void printInformationMenu(const std::string& name, const std::string* const* personFields)
{
    static const std::string YELLOW = "\033[33m";
    static const std::string RESET  = "\033[0m";

    std::cout << name << "'s Information: " << std::endl;
    std::cout << "1. Street Address: "  << YELLOW << *personFields[0] << RESET << std::endl;
    std::cout << "2. City:           "  << YELLOW << *personFields[1] << RESET << std::endl;
    std::cout << "3. State:          "  << YELLOW << *personFields[2] << RESET << std::endl;
    std::cout << "4. Zip Code:       "  << YELLOW << *personFields[3] << RESET << std::endl;
    std::cout << "5. Country:        "  << YELLOW << *personFields[4] << RESET << std::endl;
    std::cout << "6. Phone Number:   "  << YELLOW << *personFields[5] << RESET << std::endl;
    std::cout << "7. Finish" << std::endl;
}

/**
 * FUNCTION: Function is invoked when creating a new person to add to phonebook and is responsible for the heavy lifting 
 *              of filling in the personal datas 
 * PARAMS:   Person's name and the prompt fields
 * RETURNS:  VOID
 */
static void setupInformation(const std::string& fullName, std::string* const* promptFields)
{
    int menuButton          {-1};
    const int streetButton  {1};
    const int cityButton    {2};
    const int stateButton   {3};
    const int zipButton     {4};
    const int countryButton {5};
    const int numberButton  {6};
    const int finishButton  {7};
    std::string userInput   {""};

    while(menuButton != finishButton)
    {
        CLEAR_SCREEN();
        
        printInformationMenu(fullName, promptFields);
        std::cin >> menuButton;
        std::cin.ignore(INT64_MAX, '\n');
        CLEAR_SCREEN();

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT64_MAX, '\n');
            continue;
        }

        if(menuButton < streetButton || menuButton > finishButton)
        {
            std::cout << "Invalid option." << std::endl;
            continue;
        }

        if(menuButton == finishButton)
        {
            break;
        }

        printInformationMenu(fullName, promptFields);
        std::cout << "Enter " << fullName << "'s ";
        
        switch(menuButton)
        {
            case streetButton:
                std::cout << "Street Address: ";
                break;
            
            case cityButton:
                std::cout << "City: ";
                break;
            
            case stateButton:
                std::cout << "State: ";
                break;
            
            case zipButton:
                std::cout << "Zip: ";
                break;
            
            case countryButton:
                std::cout << "Country: ";
                break;
            
            case numberButton:
                std::cout << "Phone Number: ";
                break;
                
            default:
                std::cout << "Invalid Option." << std::endl;          
        }
        std::getline(std::cin, userInput);

        if(menuButton != finishButton)
        {
            *promptFields[menuButton - 1] = userInput;
        }
    }   
}

/**
 * FUNC:    Hook that starts the process of filling in personal data
 * PARAMS:  VOID
 * RETS:    VOID 
 */
void Person::setupPerson()
{   
    setName(this->m_FirstName, this->m_LastName);
    this->m_FullName = this->m_FirstName + " " + this->m_LastName;


    std::string* promptFields[6] = {
        &this->m_StreetAddress, 
        &this->m_City, 
        &this->m_State, 
        &this->m_Zip, 
        &this->m_Country,
        &this->m_PhoneNumber,
    };

    setupInformation(this->m_FullName, promptFields);
    this->m_Address = this->m_StreetAddress + ", " + this->m_City + ", " + this->m_State + ", " + this->m_Zip + ", " + this->m_Country; 

    #ifdef DEBUG
        LOG(this->m_FullName);
    #endif /* DEBUG*/

    #ifdef DEBUG
        LOG(this->m_Address);
    #endif /* DEBUG*/
}