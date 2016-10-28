#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include "message_floder.h"
using namespace std;

Folders::Folders(const string &str)
        :folder(str){}
Folders::Folders(const Folders &f)
    :folder(f.folder), messages(f.messages){

}

Folders & Folders::operator= (const Folders &f){
    for(auto m : messages)
        messages.erase(m);
    folder = f.folder;
    messages = f.messages;
    return *this;
}

Folders::~Folders(){}

void Folders::addMsg(Message * m){
    messages.insert(m);
}

void Folders::remMsg(Message * m){
    messages.erase(m);
}

string Folders::get_folder(){
    return folder;
}

void Folders::contained_msg(){
    for(auto f : messages){
        cout<<f->get_msg()<<endl;
    }
}


void Message::add_to_Folders(const Message &m){
    for(auto f: m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders(){
    for(auto f : this->folders)
        f->remMsg(this);
}

Message::Message(const string &str)
    :contents(str){}

Message::Message(const Message &m)
    :contents(m.contents), folders(m.folders){
    add_to_Folders(m);
}

Message& Message::operator= (const Message &m){
    remove_from_Folders();
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

Message::~Message(){
    remove_from_Folders();
}

void Message::save(Folders &f){
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folders &f){
    folders.erase(&f);
    f.remMsg(this);
}

string Message::get_msg(){
    return contents;
}

void Message::contained_fld(){
    for(auto f : folders){
        cout<<f->get_folder()<<endl;
    }
}

