#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node() = delete;
	Node( const Node& ) = delete;
	Node& operator= ( const Node& ) = delete;
	~Node();

	// specialized constructor
	Node( int k );

	Node* AppendToTail( int k );

	static void DeleteList( Node* );
	static void RunTests_Node();

	// data
public:
	static int nodeCount;

	Node* pNext;
	int data;
};
#endif // !NODE_H
