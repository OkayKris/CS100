#ifndef __SORT_HPP__
#define __SORT_HPP__

#include "container.hpp"

class Container;


class Sort {
    public:
        /* Constructors */
        Sort(){}

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

class SSort : public Sort {
    public:
    void sort(Container* container);
};

class BSort: public Sort {
    public:
    void sort(Container* container);
};

#endif // __SORT_HPP__