#include "Person.h"

#include <iostream>
#include <string>
#include <limits> 

/**
 * TODO:    REFINE THIS SO THAT THEY ARE NOT ENTERING IT SEQUENTIALLY BUT AS A MENU
 * FUNC:    Capture's a person's full name
 * PARAMS:  VOID
 * RETS:    VOID 
 */
void Person::setName()
{
    std::cout << "Enter a Person's First Name: ";
    std::getline(std::cin, m_FirstName);
    std::cout << "Enter a " << this->m_FirstName <<"'s last name: ";
    std::getline(std::cin, m_LastName);

    this->m_FullName = this->m_FirstName + " " + this->m_LastName;
    
    #ifdef DEBUG
        LOG(this->m_FullName);
    #endif /* DEBUG*/
}


/**
 * TODO:    REFINE THIS SO THAT THEY ARE NOT ENTERING IT SEQUENTIALLY BUT AS A MENU
 * FUNC:    Capture's a person's address
 * PARAMS:  VOID
 * RETS:    VOID 
 */
void Person::setAddress()
{
    std::string prompts[5] = {"Street Address", "City", "State", "Zip Code", "Country"};
    std::string* promptField[5] = {&this->m_StreetAddress, &this->m_City, &this->m_State, &this->m_Zip, &this->m_Country};

    for(size_t i = 0; i < 5; i++)
    {
        std::cout << "Enter " << this->m_FirstName << "'s " << prompts[i] << ": ";
        std::getline(std::cin, *promptField[i]);
    }
    this->m_Address = this->m_StreetAddress + ", " + this->m_City + ", " + this->m_State + ", " + this->m_Zip + ", " + this->m_Country; 
    #ifdef DEBUG
        LOG(this->m_Address);
    #endif /* DEBUG*/
}

/**
 * TODO:    REFINE THIS SO THAT THEY ARE NOT ENTERING IT SEQUENTIALLY BUT AS A MENU
 * FUNC:    Capture's a person's number
 * PARAMS:  VOID
 * RETS:    VOID 
 */
void Person::setNumber()
{
    std::cout << "Enter in " << this->m_FullName << "'s Phone Number: ";
    std::getline(std::cin, this->m_PhoneNumber);
    
    /**
     * TODO: ADD () and - to NUMBER IF USER DIDN'T
     * 
    */

    #ifdef DEBUG
        LOG(this->m_PhoneNumber);
    #endif /* DEBUG*/
}