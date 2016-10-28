#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>
#include <map>
using namespace std;

class StrVec{
private:
    //allocate element
    static allocator<string> alloc;

    /*
     * alloc
     * |1|2|3|4| | | | |
     *  e       f       c
     * */
    string *elements;
    string *first_free;
    string *cap;

    //check size and capacity
    void chk_n_alloc(){
        if(size() == capacity())
            reallocate();
    }

    //tool functions, called by construction, opeartor= , and deconstruction
    pair<string *, string *> alloc_n_copy(const string *, const string *);

    void free();//destory element and free memory
    void reallocate();//get lager capacity and copy current elements to it


public:

};

#endif // STRVEC_H
