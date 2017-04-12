#pragma once

#include <vector>
using std::vector;

#include "../general/defs.h"

typedef class Possibility py;
typedef vector<py> vpy;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef unsigned int UI;
typedef vector<UI> vui;
typedef vector<vui> vvui;

class Possibility {
    
    vb values;
    
    public:
    
    Possibility();
    Possibility(vui const&); // 0 ~ 8
    Possibility(py const&) = default;
    
    py operator&(py const&) const;
    py &operator&=(py const&);
    
    operator bool() const;
    
    bool operator[](UI) const;
    bool get(UI) const noexcept;
    bool set(UI, bool) noexcept;
    
    static py remainPossib(vui const &r, vui const &c, vui const &b);
    static py remainPossib(vvui const &rcb);
    
};

