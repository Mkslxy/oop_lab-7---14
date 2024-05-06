#include <iostream>
#include <memory>
#include "DoubleLink.h"

using namespace std;


int main() {
    try {
        SingleLink<int> test;
        test.addFirst(1);
        test.addLast(3);
        test.addLast(2);
        test.print();
        test.removeFirst();
        test.print();
        //test.access();
        test.getSize();
        test.isEmpty();
        test.contains(2);
        cout << endl;

        DoubleLink<float> test2;
        test2.AddFirst(2.345);
        test2.AddFirst(0.00000000001);
        test2.AddLast(5.2345);
        test2.RemoveLast();
        test2.print();
        test2.access(1);
    } catch (bool pass) {};
    return 0;
}
