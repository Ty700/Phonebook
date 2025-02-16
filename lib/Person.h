#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

#define LOG(msg)                                \
    std::cout   << "==========\n"               \
                << "LOG: " << msg << "\n"       \
                << "==========" << std::endl;

class Person {

public:
    
    Person(){
        setName();
        setAddress();
        setNumber();
    }

    std::string getName()   { return this->m_FullName; }
    std::string getAddress(){ return this->m_Address; }
    std::string getNumber() { return this->m_PhoneNumber; }

private:
    void setName();
    void setAddress();
    void setNumber();

    std::string m_FirstName     {""};
    std::string m_LastName      {""};
    std::string m_FullName      {""};

    std::string m_PhoneNumber   {""};

    std::string m_StreetAddress {""};
    std::string m_City          {""};
    std::string m_State         {""};
    std::string m_Zip           {""};
    std::string m_Country       {""};
    std::string m_Address       {""};
};  


#endif /* PERSON_H */