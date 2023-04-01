#ifndef CHAIN_H
#define CHAIN_H

#include "ChainNode.h"

template <typename T>
class Chain {
  private:
        ChainNode<T> *first;
        ChainNode<T> *curNode; // This is the current node which I declared myself. 
  public:
        Chain(); // constructor
        void insertbegin(T);
        void insertend(T);
        void remove(T);
        void printchain();
        int countNodes();
        void reverseLink();
        void insertAfter(T,T); // inserts a node after finding the specified data
        ~Chain(); //destructor; 
};

#endif
