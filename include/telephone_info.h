#ifndef INDIVIDUAL_TASK_1_TELEPHONE_INFO_H
#define INDIVIDUAL_TASK_1_TELEPHONE_INFO_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

void CreateBase(base_t* base);

void Add(base_t* base, unsigned int networkCode,
         unsigned int number, const char* nameOwner);

void DeleteBase(base_t* base);

void Sort(base_t* base);

bool IsValidNumber(telephone_t* telephone);



#endif //INDIVIDUAL_TASK_1_TELEPHONE_INFO_H
