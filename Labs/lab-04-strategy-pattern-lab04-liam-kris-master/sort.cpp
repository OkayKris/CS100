#include "sort.hpp"
#include "container.hpp"
#include<bits/stdc++.h>



void SSort::sort(Container* container) {
    for (int i = 0; i < container->size(); ++i) {
            int min = i;
            //cout << i << endl;
        for (int j = i; j < container->size(); ++j) {
            if (container->at(min)->evaluate() > container->at(j)->evaluate()) {
                min = j;
                //cout << "swap: " << container->at(min)->evaluate() << " " <<container->at(i)->evaluate() << endl;
                
            }
            
        }
        //cout << "Swapped" << endl;
        container->swap(i,min);
        
    }
    return;
}

void BSort::sort(Container* container) {
    for (int i = 0; i < container->size(); ++i) {
        //cout << i << endl;
        for(int j = 0; j < container->size()-1; ++j) {
            if (container->at(j)->evaluate() > container->at(j+1)->evaluate()) {
                container->swap(j,j+1);
                //cout << "swap: " <<i << " " <<j << endl;
            }
        }
    }
}