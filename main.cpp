#include <iostream>
#include <memory>
//#include <vector>

struct Node
{
    Node() : val(-1) {}
    Node(int v) : val(v) {}

    int val;
    std::shared_ptr<Node> next;
};

struct Stack
{
    Stack() : items(0) {}

    int top();
    void push(const int v);
    void pop();

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

    unsigned int items;
};

int Stack::top()
{
    if(head == nullptr) return -1;
    return tail->val;
}

void Stack::push(const int v)
{
    if (head == nullptr)
    {
        head = std::make_shared<Node>(v);
        tail = head;
        ++items;
        return;
    }

    auto xnode = std::make_shared<Node>(v);
    tail->next = xnode;
    tail = xnode;

    ++items;
}

void Stack::pop()
{
    std::cout << "top of pop" << std::endl;
    if (head == nullptr)
    {
        std::cout << "head == nullptr" << std::endl;
        return;
    }

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
        items = 0;
        return;
    }

    std::cout << "pop while" << std::endl;
    auto hd = head;
    while(hd->next != tail)
    {
        hd = hd->next;
    }

    hd->next = nullptr;
    tail = hd;

    std::cout << "head " << head->val << std::endl;
    std::cout << "tail " << tail->val << std::endl;

    --items;
}

int main()
{
    Stack sk;

    sk.push(4);
    std::cout << sk.top() << "\n";
    std::cout << sk.items << "\n";
    std::cout << "\n";

    sk.push(2);
    std::cout << sk.top() << "\n";
    std::cout << sk.items << "\n";
    std::cout << "\n";

    sk.pop();
    std::cout << sk.top() << "\n";
    std::cout << sk.items << "\n";
    std::cout << "\n";

    sk.pop();
    std::cout << sk.items << "\n";
    std::cout << "\n";

    return 0;
}
