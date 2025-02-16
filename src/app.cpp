#include "Person.h"
#include <iostream>
#include <memory>
int main()
{
    auto newPerson = std::make_unique<Person>();
}