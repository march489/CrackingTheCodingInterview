#include "StackNode.h"

template<typename T>
inline StackNode<T>::StackNode( T in )
	: data{ in }, pNext{ nullptr }
{

}