
#include <iostream>
#include "Queue.h"

using namespace std;

template<typename T>
class PriorityQueue {
private:
    struct Priority {
        int priority = 0;
        T data;

        Priority(int priority, T data) : priority(priority), data(data) {}
    };

    DoubleLink<Priority> list;
public:
    void Enqueue(int priority, T database) {
        Priority contains(priority, 0);
        int i = 0;
        if (list.isEmpty()) {
            while (priority >= contains) {
                if (i < list.getSize()) {
                    contains = list.access(i);
                    i++;
                } else {
                    break;
                }
            }
        }
        if (i > list.getSize()) {
            list.add(i, Priority(priority, database));
        } else {
            list.add(i - 1, Priority(priority, database));
        }
    }

    T Dequeue() {
        Priority contains(0, 0);
        contains = list.access(0);
        list.removeFirst();
        return contains.data;
    }

    T peek() {
        Priority contains(0, 0);
        contains = list.access(0);
        return contains.data;
    }

};