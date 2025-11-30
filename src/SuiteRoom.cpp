#include "SuiteRoom.h"

int SuiteRoom::DISCOUNT = 15; 

// Getter 
int SuiteRoom::get_discount() {
    return DISCOUNT;
}

// Setter 
void SuiteRoom::set_discount(int discount) {
    DISCOUNT = discount;
}
