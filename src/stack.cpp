#include "stack.hpp"

int Stack::top()
{
    std::lock_guard<std::mutex> lck(mtx);

    if(head == nullptr) return -1;
    return tail->val;
}

void Stack::push(const int v)
{
    std::lock_guard<std::mutex> lck(mtx);

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
    std::lock_guard<std::mutex> lck(mtx);

    if (head == nullptr)
    {
        return;
    }

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
        items = 0;
        return;
    }

    auto hd = head;
    while(hd->next != tail)
    {
        hd = hd->next;
    }

    hd->next = nullptr;
    tail = hd;

    --items;
}

int Stack::num_items() const
{
    std::lock_guard<std::mutex> lck(mtx);

    return items;
}
