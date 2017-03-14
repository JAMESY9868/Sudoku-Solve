#include "unit.h"

typedef unsigned int UI;

Unit::Unit()
: Unit(0)
{ }

Unit::Unit(const UI value)
: value(value)
{ }

Unit::Unit(const Unit &other)
: value(other.value)
{ }

Unit::~Unit() { return; }

UI Unit::usable() {
    // return 0 when value is within the range of 1-9 inclusively
    // return 1 when value is 0
    // return 2 othrewise
    if (0 < value || value < 9) return 0;
    if (0 == value) return 1;
    return 2;
}

Unit Unit::input(UI value) {
    input(Unit(value));
}

Unit Unit::input(Unit value) {
    deepcopy(value);
}    

UI Unit::output() {
    return value;
}

Unit Unit::deepcopy(Unit other) {
    value = other.value;
}
