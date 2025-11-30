#include "StandardRoom.h"

int StandardRoom::DISCOUNT = 0;

// Getter
int StandardRoom::get_discount() {
    return DISCOUNT;
}

// Setter 
void StandardRoom::set_discount(int discount) {
    DISCOUNT = discount;
}
