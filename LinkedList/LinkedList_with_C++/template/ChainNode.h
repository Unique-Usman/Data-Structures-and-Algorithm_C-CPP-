#ifndef CHAINNODE_H
#define CHAINNODE_H


template <typename T> //T is for the data type insided the ChainNode function 
class ChainNode{
	template <typename>friend class Chain;
	public:
		ChainNode(T element, ChainNode<T> *next);
	private:
		T data;
		ChainNode<T>*link;
};

#endif 
