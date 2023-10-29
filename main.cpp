#include <iostream>
#include "stack.hpp"

int main()
{
    Stack sk;

    sk.push(4);
    std::cout << sk.top() << "\n";
    std::cout << sk.num_items() << "\n";
    std::cout << "\n";

    sk.push(2);
    std::cout << sk.top() << "\n";
    std::cout << sk.num_items() << "\n";
    std::cout << "\n";

    sk.pop();
    std::cout << sk.top() << "\n";
    std::cout << sk.num_items() << "\n";
    std::cout << "\n";

    sk.pop();
    std::cout << sk.num_items() << "\n";
    std::cout << "\n";

    return 0;
}
