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

class Possibility {
    
    vb values;
    
    public:
    
    Possibility();
    Possibility(vui const&);
    Possibility(py const&) = default;
    
    bool operator[](UI) const;
    bool get(UI) const noexcept;
    bool set(UI, bool) noexcept;
    
    
    
};

