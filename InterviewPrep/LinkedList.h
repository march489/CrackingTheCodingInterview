#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node;

class LinkedList
{
public:
	LinkedList();
	LinkedList( const LinkedList& ) = delete;
	LinkedList& operator=( const LinkedList& ) = delete;
	~LinkedList();

	Node* AppendNodeToTail( int k );
	Node* FindNode( int k );
	void ClearList();

	bool DeleteNode(int k);
	void RemoveDuplicates();
	void DeleteMiddleNode();

	static void RunTests_LinkedList();
	static void DeleteTest();
	static void RemoveDupsTest();
	static void DeleteMiddleTest();

	// data
private:
	Node* poHead;
};

#endif // !LINKED_LIST_H
