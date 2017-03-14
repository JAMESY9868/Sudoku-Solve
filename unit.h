#ifndef UNIT_H
#define UNIT_H

class Unit {

    unsigned int value;
    
    // Returns 0 if 1~9, 1 if 0, 2 if others
    unsigned int usable();
    
    Unit input(int value);
    Unit input(Unit value);
    int output();
    
    Unit deepcopy(Unit other);
    
    public: 
    Unit();
    Unit(int value);
    ~Unit();

};

#endif
