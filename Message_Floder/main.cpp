#include <iostream>
#include <memory>
#include "message_floder.h"
using namespace std;

int main(int argc, char *argv[])
{
    shared_ptr<Message> m1(new Message("ls"));
    shared_ptr<Message> m2(new Message("cd .."));

    shared_ptr<Folders> f1(new Folders("/etc"));
    shared_ptr<Folders> f2(new Folders("/home"));

    m1->save(*(f1.get()));
    m2->save(*(f2.get()));

    m1->contained_fld();
    m2->contained_fld();

    f1->contained_msg();
    f2->contained_msg();

    cout<<"after swap m1 and m2"<<endl;
    m1->swap(*(m1.get()), *(m2.get()));
    m1->contained_fld();
    f1->contained_msg();
    m2->contained_fld();
    f2->contained_msg();

    Message m3("rm -rf");
    Folders f3("/home/foo/test");
    m3.save(f3);
    m3.contained_fld();
    f3.contained_msg();

    Message m4("cal");
    Folders f4("./");
    m4.save(f4);
    m4.contained_fld();
    f4.contained_msg();


    cout<<"after swap m3 and m4"<<endl;
    m3.swap(m3, m4);
    m3.contained_fld();
    f3.contained_msg();
    m4.contained_fld();
    f4.contained_msg();
    return 0;
}
