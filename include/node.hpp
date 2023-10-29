#pragma once

#include <memory>

struct Node
{
   Node() : val(-1) {}
   Node(int v) : val(v) {}

   int val;
   std::shared_ptr<Node> next;
};
