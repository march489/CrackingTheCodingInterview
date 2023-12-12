#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <optional>

class Node;

class LinkedList
{
	public:
	LinkedList( );
	LinkedList( const LinkedList& );
	LinkedList& operator=( const LinkedList& );
	~LinkedList( );

	Node* AppendNodeToTail( int k );
	Node* FindNode( int k );
	void ClearList( );

	// EXERCISES
	bool DeleteNode( int k );
	void RemoveDuplicates( );
	void DeleteMiddleNode( );
	Node* KthToLast( int k ) const;
	void Partition( int k );
	LinkedList ReverseSum( const LinkedList& rhs ) const;
	bool IsPalindrome( ) const;
	bool IsPalindromeAlt( ) const;
	std::optional<Node*> Intersect( const LinkedList& otherList ) const;
	std::optional<Node*> ContainsLoop( ) const;
	//std::optional<Node*> ContainsLoopAlt( ) const;

	// TESTS
	static void RunTests_LinkedList( );
	static void DeleteTest( );
	static void RemoveDupsTest( );
	static void DeleteMiddleTest( );
	static void KthToLastTest( );
	static void PartitionTest( );
	static void ReversedSumTest( );
	static void IsPalindromeTest( );
	static void IntersectionTest( );
	static void ContainsLoopTest( );

	// data
	private:
	Node* poHead;
};

#endif // !LINKED_LIST_H
