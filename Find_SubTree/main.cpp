#include <iostream>
#include <stack>
struct Node{
    char element;
    struct Node *left;
    struct Node *right;

    Node():left(nullptr), right(nullptr){}

    Node(char v, struct Node *l = nullptr, struct Node *r = nullptr)
        :element(v),left(l),right(r){}
};
typedef struct Node BT;

/*Tree 1
              +

     +                  *

a        *           +       g

       b   c       *   f

                  d e
*/

/*Tree 2
            +

        *       f

          e


*/

/*Tree 3
                *
              +
            *
           d
*/

using namespace std;

/*while root1 == root2 is true, check if root1 contains root2*/
bool ContainCheck(BT *root1, BT *root2){
    if(root2 == nullptr)return true;

    if((root1 != nullptr && root1->element == root2->element)){
        return ContainCheck(root1->left, root2->left) &&
                ContainCheck(root1->right, root2->right);
    }
    else{
        return false;
    }

}

/*find root2 in root1
  use InorderTravesel to find root1 which root1 == root2
  then use ContainCheck .
*/
bool SubTreeSearch(BT *root1, BT *root2){
    if(root1 == nullptr)
        return false;

    if(root1->element == root2->element){
        if(true == ContainCheck(root1, root2))
            return true;
    }

    if(true == SubTreeSearch(root1->left, root2))
        return true;


    if(true == SubTreeSearch(root1->right, root2))
        return true;

    return false;

}

void Handle(BT * &p){
    cout<<p->element<<' ';
}

void PreorderTraversal_NoRecurse_2(BT * root){
    stack<BT *> s;
    auto p = root;
    while(p != nullptr || !s.empty()){
        while(p != nullptr){
            Handle(p);
            s.push(p);
            p = p->left;
        }
        if(!s.empty()){
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

int main(int argc, char *argv[])
{
    BT *root1 = new BT('+',
                       new BT('+',
                              new BT('a', nullptr, nullptr),new BT('*',
                                                                   new BT('b', nullptr, nullptr), new BT('c', nullptr, nullptr))),
                       new BT('*',
                               new BT('+',
                                      new BT('*',
                                             new BT('d', nullptr, nullptr), new BT('e', nullptr, nullptr)),
                                      new BT('f', nullptr, nullptr)),
                               new BT('g', nullptr, nullptr)));

    BT *root2 = new BT('+',
                       new BT('*',
                              nullptr, new BT('e', nullptr, nullptr)),
                       new BT('f', nullptr, nullptr));

    BT *root3 = new BT('*', new BT('+', new BT('*', new BT('d', nullptr, nullptr),nullptr), nullptr), nullptr);

    cout << "PreOrderTraversal root1" <<endl;
    PreorderTraversal_NoRecurse_2(root1);
    cout << endl;

    cout << "PreOrderTraversal root2" <<endl;
    PreorderTraversal_NoRecurse_2(root2);
    cout << endl;

    cout << "check if root1 contains root2" << endl;

    if(SubTreeSearch(root1, root2))
        cout << "root1 contains root2" << endl;
    else
        cout << "root1 doesn't contains root2" << endl;

    cout << "check if root1 contains root2" << endl;

    if(SubTreeSearch(root1, root3))
        cout << "root1 contains root3" << endl;
    else
        cout << "root1 doesn't contains root3" << endl;

    return 0;
}
