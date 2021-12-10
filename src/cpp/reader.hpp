#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED

#include "addressbook.pb.h"

#ifdef __cplusplus
extern "C" {
#endif

void ListPeople(const tutorial::AddressBook& address_book);

#ifdef __cplusplus
}
#endif

#endif
