#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <string.h>
#include <string>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>
#include "base.hpp"



using namespace std;

class Iterator {
    protected:
        Base* self_ptr;
        Base* curr_ptr;

    public:
        Iterator() {}
        Iterator(Base* ptr) { this->self_ptr = ptr; }

        /* Sets up the iterator to start at the beginning of traversal */
        virtual void first() = 0;
        
        /* Move onto the next element */
        virtual void next() = 0;
    
        /* Returns if you have finished iterating through all elements */
        virtual bool is_done() = 0;

        /* Return the element the iterator is currently at */
        virtual Base* current() {return curr_ptr;}
};

class BinaryIterator : public Iterator {
    
    public:
    BinaryIterator() {}
    BinaryIterator(Base* ptr) { this->self_ptr = ptr; }
    virtual void first() {curr_ptr = self_ptr;}
    virtual void next() {
        if(curr_ptr == self_ptr) {
            curr_ptr = self_ptr->get_left();
        } else if(curr_ptr == self_ptr->get_left()) {
            curr_ptr = self_ptr->get_right();
        } else {
            curr_ptr = nullptr;
        }
    } 
    virtual bool is_done() {return (curr_ptr == nullptr);}
    virtual Base* current() {return this->curr_ptr;}
};

class UnaryIterator : public Iterator {
    public:
    UnaryIterator() {}
    UnaryIterator(Base* in) {self_ptr = in;}
    virtual void first() {curr_ptr = self_ptr;}
    virtual void next() {
        if(curr_ptr == self_ptr) curr_ptr = self_ptr->get_left();
        else curr_ptr = nullptr;
    }
    virtual bool is_done() {return (curr_ptr == nullptr);}
    virtual Base* current() {return this->curr_ptr;}
};

class NullIterator : public Iterator {
    public:
    NullIterator() {}
    NullIterator(Base * ptr) {self_ptr = ptr; curr_ptr = nullptr;}
    virtual void first() {}
    virtual void next() {}
    virtual bool is_done() { return true; }
    virtual Base* current() { return this->curr_ptr; }
};

class PreorderIterator : public Iterator {
    
    stack<Iterator*> st;
    public:
    PreorderIterator() {}
    PreorderIterator(Base * ptr) {self_ptr = ptr; curr_ptr = nullptr;}
    virtual void first() {
        while(!st.empty()) {
            st.pop();
        }
        //cout <<"Done: "<< self_ptr->stringify() << endl;
        //Iterator* test = self_ptr->create_iterator();
        //test->first();
        //cout <<"Done2: "<< test->current()->stringify() << endl;
        st.push(self_ptr->create_iterator());
        st.top()->first();
        st.top()->next();
    
    }
    virtual void next() {
        
        //cout << st.size() << endl;
        if(!is_done() && !st.top()->is_done()) {
           // cout << "top" << endl;
           
            Iterator* it = st.top()->current()->create_iterator();
            it->first();
            it->next();
            
            st.push(it);
            //cout << "outtup" << endl;
        }

        while(!is_done() && st.top()->is_done()) {
            //cout << "sdf" <<st.size() << endl;
            st.pop();
            //cout << "sdf" <<st.size() << endl;
            if(!is_done()) {
               // cout << "next" << endl;
                st.top()->next();
                //cout << "nex" << endl;
            }
            // cout << st.size() << endl; 
        }

	}

            // Create an iterator for the current() of the iterator on the top of the stack
    // Initialize the iterator and push it onto the stack. As long as the top iterator 
    // on the stack is_done, pop it off the stack and then advance whatever iterator is
    // now on top of the stack
    virtual bool is_done() { 
        if (st.empty()) return true;
        return false;
        
    }
    virtual Base* current() { 
    	if (!this->st.empty()) {
    	    //cout << "asdf" << endl;
    		return this->st.top()->current();
    	} else {
    	    cout <<"CURRENT RETURN NULL" << endl;
    		return nullptr;
    	}

    }
    private:
};



#endif