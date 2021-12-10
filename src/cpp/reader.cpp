#include "reader.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"

// Iterates though all people in the AddressBook and prints info about them.
void ListPeople(const tutorial::AddressBook& address_book) {
  for (int i = 0; i < address_book.people_size(); i++) {
    const tutorial::Person& person = address_book.people(i);

    std::cout << "Person ID: " << person.id() << std::endl;
    std::cout << "  Name: " << person.name() << std::endl;
    if (person.has_email()) {
      std::cout << "  E-mail address: " << person.email() << std::endl;
    }

    for (int j = 0; j < person.phones_size(); j++) {
      const tutorial::Person::PhoneNumber& phone_number = person.phones(j);

      switch (phone_number.type()) {
        case tutorial::Person::MOBILE:
          std::cout << "  Mobile phone #: ";
          break;
        case tutorial::Person::HOME:
          std::cout << "  Home phone #: ";
          break;
        case tutorial::Person::WORK:
          std::cout << "  Work phone #: ";
          break;
      }
      std::cout << phone_number.number() << std::endl;
    }
  }
}