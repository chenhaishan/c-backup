#include <vector>
#include <string>
#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vi = {13,21,16,24,31,19,18,65,26,32};
    BinaryHeap<int> BH(vi);
    printheap(BH);
    return 0;
}
