#include "ChainNode.h"

template <typename T>
ChainNode<T>::ChainNode(T element, ChainNode<T> *next){
	data = element; link = next;
}
