#ifndef MESSAGE_Folder_H
#define MESSAGE_Folder_H

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Message;

class Folders{
private:
    string folder;
    set<Message *> messages;
public:
    explicit Folders(const string &str = "");
    Folders(const Folders &f);
    Folders & operator= (const Folders &f);
    ~Folders();

    void addMsg(Message * m);
    void remMsg(Message * m);


    string get_folder();
    void contained_msg();
};


class Message{
    friend class Folders;
private:
    string contents;
    set<Folders *> folders;
    void add_to_Folders(const Message &m);

    void remove_from_Folders();
public:
    explicit Message(const string &str = "");

    Message(const Message &m);

    Message& operator= (const Message &m);

    ~Message();

    void save(Folders &f);

    void remove(Folders &);

    void swap(Message &lhs, Message &rhs){
        using std::swap;
        for(auto f : lhs.folders)
            f->remMsg(&lhs);
        for(auto f : rhs.folders)
            f->remMsg(&rhs);

        swap(lhs.folders, rhs.folders);
        swap(lhs.contents, rhs.contents);

        for(auto f : lhs.folders)
            f->addMsg(&lhs);
        for(auto f : lhs.folders)
            f->addMsg(&rhs);
    }

    void swap(Message *lhs, Message *rhs){
        using std::swap;
        for(auto f : lhs->folders){
            f->remMsg(lhs);
        }
        for(auto f : rhs->folders)
            f->remMsg(rhs);

        swap(lhs->folders, rhs->folders);
        swap(lhs->contents, rhs->contents);

        for(auto f : lhs->folders)
            f->addMsg(lhs);
        for(auto f : rhs->folders)
            f->addMsg(rhs);
    }

    string get_msg();
    void contained_fld();
};

#endif // MESSAGE_Folder_H
