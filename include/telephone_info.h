#ifndef INDIVIDUAL_TASK_1_TELEPHONE_INFO_H
#define INDIVIDUAL_TASK_1_TELEPHONE_INFO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TelephoneInfo {
  unsigned long networkCode_;
  unsigned long number_;
  char *nameOwner_;
} telephone_t;

typedef struct TelephoneBase {
  unsigned long telephoneCount_;
  unsigned long capacity_;
  telephone_t *telephones_;
} base_t;

void CreateBase(base_t *base);

void Add(base_t *base, unsigned long networkCode, unsigned long number,
         const char *nameOwner);

void FillBase(base_t *base);

void Print(base_t *base);

void DeleteBase(base_t *base);

void Sort(base_t *base);

bool IsValidNumber(unsigned long networkCode, unsigned long number);

#endif  // INDIVIDUAL_TASK_1_TELEPHONE_INFO_H
