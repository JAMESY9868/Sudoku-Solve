#include "Possibility.h"

py::Possibility()
: values(BOARD_SIZE, true)
{ }

py::Possibility(vui const &entries)
: py() {
    for(UI i = 0; i < entries.size(); i++)
        if(entries[i] < BOARD_SIZE)
            values[entries[i]] = false;
}

bool &py::operator[](UI index) {
    return get(index);
}

bool const &operator[](UI index) {
    return get(index);
}

bool &get(UI index) noexcept {
    return values[index];
}

bool const &get(UI index) const noexcept {
    return values[index];
}

