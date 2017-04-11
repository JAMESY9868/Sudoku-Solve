#include "Possibility.h"

py::Possibility()
: values(BOARD_SIZE, true)
{ }

py::Possibility(vui const &entries)
: py() {
    for(UI i = 0; i < entries.size(); i++)
        if(entries[i] < BOARD_SIZE)
            set(entries[i], false);
}

bool py::operator[](UI const index) const {
    return get(index);
}

bool py::get(UI const index) const noexcept {
    #define _tmp_GETTER (values[index])
    return _tmp_GETTER;
}

bool py::set(UI const index, bool const poss) noexcept {
    return _tmp_GETTER = poss;
    #undef _tmp_GETTER
}