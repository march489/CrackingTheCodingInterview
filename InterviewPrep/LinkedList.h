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
	bool DeleteNode( int k );
	void ClearList();

	void RemoveDuplicates();

	static void RunTests_LinkedList();
	static void DeleteTest();
	static void RemoveDupsTest();

	// data
private:
	Node* poHead;
};

#endif // !LINKED_LIST_H
