#include "telephone_info.h"

void CreateBase(base_t *base) {
    if (base == NULL) {
        return;
    }
    base->capacity_ = 1;
    base->telephoneCount_ = 0;
    base->telephones = (telephone_t*)malloc(sizeof(telephone_t));
}

void Add(base_t *base, unsigned int networkCode,
         unsigned int number, const char *nameOwner) {
    if (base->capacity_ == base->telephoneCount_) {
        base->capacity_ *= 2;
        base->telephones = (telephone_t*)realloc(base->telephones, base->capacity_ * sizeof(telephone_t));
    }
    base->telephones[base->telephoneCount_].networkCode_ = networkCode;
    base->telephones[base->telephoneCount_].number_ = number;

    if (nameOwner != NULL) {
        base->telephones[base->telephoneCount_].nameOwner_ = malloc((strlen(nameOwner) + 1));
        strcpy(base->telephones[base->telephoneCount_].nameOwner_, nameOwner);
    } else {
        base->telephones[base->telephoneCount_].nameOwner_ = malloc(sizeof(char));
        strcpy(base->telephones[base->telephoneCount_].nameOwner_, (const char*)(""));
    }
    base->telephoneCount_++;
}

void DeleteBase(base_t *base) {
    if (base == NULL) {
        return;
    }

    for (unsigned int i = 0; i < base->telephoneCount_; ++i) {
        if (base->telephones[i].nameOwner_ != NULL) {
            free(base->telephones[i].nameOwner_);
        }
    }
    free(base->telephones);
}


