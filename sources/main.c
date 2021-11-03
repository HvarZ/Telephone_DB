#include <telephone_info.h>

int main() {
    base_t base;
    CreateBase(&base);
    printf("Enter a numbers: network code (without +), number, and owner's name\n");
    FillBase(&base);
    Print(&base);
    DeleteBase(&base);
}


