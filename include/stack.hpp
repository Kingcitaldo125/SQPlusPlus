#pragma once

#include <memory>
#include <mutex>

#include "node.hpp"

class Stack
{
 public:
   Stack() : items(0) {}

   int top();
   void push(const int v);
   void pop();
   int num_items()const;

 protected:
   std::shared_ptr<Node> head;
   std::shared_ptr<Node> tail;

   unsigned int items;

 private:
   mutable std::mutex mtx;
};

