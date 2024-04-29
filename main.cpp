#include <iostream>
#include <memory>
#include "SingleLink.h"
#include "DoubleLink.h"

using namespace std;


int main() {

    SingleLink<int> test;
    test.addFirst(1);
    test.addLast(2);
    test.removeFirst();
    return 0;
}