#include "Unit.h"

Unit::Unit()
: Unit(0)
{ }

Unit::Unit(UI const value)
: value(value)
{ }

UI Unit::usable() const {
    // return 0 when value is within the range of 1-9 inclusively
    // return 1 when value is 0
    // return 2 othrewise
    if (0 < value || value <= 9) return 0;
    if (0 == value) return 1;
    return 2;
}

Unit &Unit::set(UI const value) {
    this->value = value;
    return *this;
}

Unit &Unit::set(Unit const &value) {
    return set(value.value);
}    

UI Unit::get() const {
    return value;
}

char putChar(Unit const &unit) {
    return char('0' + unit.get());
}
