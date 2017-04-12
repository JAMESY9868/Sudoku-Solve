#include "Possibility.h"

py::Possibility()
: values(BOARD_SIZE, true)
{ }

py::Possibility(vui const &entries)
: py() {
    for(UI i = 0; i < entries.size(); i++)
        if(entries[i] - 1 < BOARD_SIZE) // account for 0
            set(entries[i] - 1, false);
}

py py::operator&(py const &other) const {
    return py(*this) &= other;
}

py &py::operator&=(py const &other) {
    for(UI i = 0; i < values.size(); i++)
        set(i, get(i) && other[i]);
    return *this;
}

py::operator bool() const {
    bool res = true;
    for(UI i = 0; i < BOARD_SIZE; i++)
        res &= get(i);
    return res;
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

py py::remainPossib(vui const &row, vui const &col, vui const &box) {
    #define _tmp_CHECK_SIZE(V,S) if(V.size()!=S)throw(0u)
    #define _tmp_ARGNUM 3
    _tmp_CHECK_SIZE(row, BOARD_SIZE);
    _tmp_CHECK_SIZE(col, BOARD_SIZE);
    _tmp_CHECK_SIZE(box, BOARD_SIZE);
    return py(row) & py(col) & py(box);
}

py py::remainPossib(vvui const &rcb) {
    _tmp_CHECK_SIZE(rcb, _tmp_ARGNUM);
    return remainPossib(rcb[0], rcb[1], rcb[2]);
    #undef _tmp_ARGNUM
    #undef _tmp_CHECK_SIZE
}
