#ifndef INDIVIDUAL_TASK_1_TELEPHONE_INFO_H
#define INDIVIDUAL_TASK_1_TELEPHONE_INFO_H

#include <stdbool.h>

typedef struct TelephoneInfo {
    unsigned int networkCode_;
    unsigned int number_;
    char* nameOwner_;
} telephone_t;

typedef struct TelephoneBase {
    unsigned int telephoneCount_;
    unsigned int capacity_;
    telephone_t* telephones;
} base_t;

void createBase(base_t* base);

void add(base_t* base, const unsigned int networkCode,
         const unsigned int number, const char* nameOwner);

void deleteBase(base_t* base);

void sort(base_t* base);

bool isValidNumber(telephone_t* telephone);



#endif //INDIVIDUAL_TASK_1_TELEPHONE_INFO_H
