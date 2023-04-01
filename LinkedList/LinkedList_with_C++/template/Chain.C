#include "Chain.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
Chain<T>::Chain(){
	first = NULL;
}

template <typename T>
void Chain<T>::insertbegin(T x)
{
  if (first) // list already exists
  {
        ChainNode<T> *tmp = new ChainNode<T>(x, 0);
        tmp->link = first;
        first = tmp;
  }
  else{
        first = new ChainNode<T>(x,0);
        curNode = first;
        }
}


template <typename T>
void Chain<T>::insertend(T x)
{
  if (first)  // list already exists
  {
        curNode = (curNode->link = new ChainNode<T>(x, 0));
  }
  else{
        first = new ChainNode<T>(x,0);
        curNode = first;
  } // empty list; creating the first node of the list
}

template <typename T>
void Chain<T>::remove(T x){
        ChainNode<T> *tmp = first;
        bool hasRemoved = false; // this is to track whether any of the element has been remvoed or not to be printout chain does not contain chainNode
        while (tmp != NULL) {
                if ( tmp->link == NULL){
                        if (tmp->data == x){
                        //      first = tmp == first ? NULL : first;
                                if (first == tmp){
                                        first = NULL;
                                        curNode = first;
                                }else{
                                        first->link = NULL;
                                        curNode = first;
                                }
                                delete tmp;
                                return;
                        }else{
                                if (!hasRemoved){
                                        cout << "Not found" << endl;
                                }
                                return;
                        }
                }else{
                        if (tmp->data == x){
                                if (tmp == first){
                                        first = tmp->link;
                                        delete tmp;
                                        tmp = first;
                                        hasRemoved = true;
                                }else{
                                        ChainNode<T> *tmp1 = tmp;
                                        tmp = tmp->link;
                                        delete tmp1;
                                        hasRemoved = true;
                                }
                        }else{

                                tmp = tmp->link;
                        }
                }
        }
}

template <typename T>
void Chain<T>::printchain()
{
        ChainNode<T> *tmp = first;

        while (tmp != NULL){
                cout << tmp->data << endl;
                tmp = tmp->link;
        }
}


template <typename T>
int Chain<T>::countNodes(){
        ChainNode<T> *tmp =  first;
        int count = 0;
        while (tmp != NULL){
                count++;
                tmp = tmp->link;
        }

        return (count);
}

//Program to reverse linked list
template <typename T>
void Chain<T>::reverseLink(){
        curNode = first;
        ChainNode<T>* prev = NULL;
        ChainNode<T>* curr = first;

        while (curr != NULL){
                ChainNode<T> *next = curr->link;
                curr->link = prev;

                prev = curr;
                curr = next;
        }
        first = prev;
}

/**
 * data = data to be inserted
 * item = item after which data will be inserted.
 */
template <typename T>
void Chain<T>::insertAfter(T data, T item){
        ChainNode<T> *tmp = first;

        while (tmp != NULL){
                if (tmp->link == NULL){
                        if (tmp->data == item){
                                ChainNode<T> *tmp1 = new ChainNode<T>(data, 0);
                                tmp->link = tmp1;
                                curNode = tmp1;
                                return;
                        }else{
                                return;
                        }
                }else{
                        if (tmp->data == item){
                                ChainNode<T> *tmp1 = new ChainNode<T>(data, 0);
                                tmp1->link = tmp->link;
                                tmp->link = tmp1;
                                tmp = tmp->link->link; //to update the tmp after a node has been inserted;
                        }else{

                                tmp = tmp->link;
                        }
                }
        }
}

template <typename T>
Chain<T>::~Chain() {              // destructor
                ChainNode<T> *tmp;
                while (first) {
                        tmp = first->link;
		        delete first;
                        first = tmp;
		}
}
