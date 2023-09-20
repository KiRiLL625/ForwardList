#include <iostream>
#include "ForwardList.h"
int main() {
    ForwardList<double> list;
    list.pushFront(1.433);
    list.pushFront(2.32312);
    list.pushFront(3.654);
    std::cout << list.front() << std::endl;
    std::cout << list.empty() << std::endl;
    list.popFront();
    std::cout << list.front() << std::endl;
    std::cout << "Size of 1 list: " << list.getSize() << std::endl;
    ForwardList<double> list2(std::move(list));
    std::cout << list2.front() << std::endl;
    list2.popFront();
    std::cout << list2.getSize() << std::endl;
    std::cout << list.getSize() << std::endl;
    return 0;
}
