#ifndef NODE_H
#define NODE_H
	template <typename T>
	class node{
		T data;
		node<T>* next;
		node<T>* prev;
		public:
		node(T data):data(data){}
		template <typename>friend class chainNode;
	};
#endif
