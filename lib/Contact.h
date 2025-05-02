#ifndef CONTACT_H
#define CONTACT_H

#include "Person.h"

#include <memory>

class Contact {

public:
    Contact()
    {
        endOfName = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    };

    ~Contact() {};

    /* Are there name with spaces?? Do I need to allocate 27? Idk. */
    std::unique_ptr<Contact> children[26];

    void assignPersonToContactNode(std::unique_ptr<Person> personInfo);
    bool getEndOfName();
    void setEndOfName();

private:
    bool endOfName  {false};
    Person* contact {nullptr};
};

#endif /* CONTACT_H*/