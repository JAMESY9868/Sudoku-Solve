#ifndef UNIT_H
#define UNIT_H
typedef unsigned int UI;

class Unit {

    UI value;
    
    public: 
    Unit();
    Unit(UI value);
    Unit(const Unit &other);
    ~Unit();
    
    // Returns 0 if 1~9, 1 if 0, 2 if others
    UI usable();
    
    Unit input(UI value);
    Unit input(Unit value);
    UI output();
    
    Unit deepcopy(Unit other);
};

#endif
