#include "DoubleRoom.h"

int DoubleRoom::DISCOUNT = 15; // valor por defecto

int DoubleRoom::get_discount() {
    return DISCOUNT;
}

void DoubleRoom::set_discount(int discount) {
    DoubleRoom::DISCOUNT = discount;
}

