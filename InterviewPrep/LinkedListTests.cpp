#include "LinkedList.h"
#include <assert.h>
#include "Node.h"
#include <iostream>


void LinkedList::RunTests_LinkedList( )
{
	std::cout << "Beginning LinkedList tests...";

	LinkedList::DeleteTest( );
	LinkedList::RemoveDupsTest( );
	LinkedList::DeleteMiddleTest( );
	LinkedList::KthToLastTest( );
	LinkedList::PartitionTest( );
	LinkedList::ReversedSumTest( );
	LinkedList::IsPalindromeTest( );

	// assert that all dynamic allocations have been freed
	assert( Node::nodeCount == 0 );

	std::cout << " all tests passed." << std::endl;
}

void LinkedList::DeleteTest( )
{
	LinkedList pList = LinkedList( );
	assert( pList.poHead == nullptr );

	pList.AppendNodeToTail( 10 );
	pList.AppendNodeToTail( 20 );
	pList.AppendNodeToTail( 30 );
	pList.AppendNodeToTail( 40 );

	// walk down the list and test
	Node* pNode = pList.poHead;

	assert( pNode );
	assert( pNode->data == 10 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 20 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 40 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 4 );

	// delete from the middle
	bool status = pList.DeleteNode( 20 );
	assert( status );

	// walk down the list and test
	pNode = pList.poHead;

	assert( pNode );
	assert( pNode->data == 10 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 40 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 3 );

	// delete from the beginning
	status = pList.DeleteNode( 10 );
	assert( status );

	// walk down the list and test
	pNode = pList.poHead;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 40 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 2 );

	// delete from the end
	status = pList.DeleteNode( 40 );
	assert( status );

	// walk down the list and test
	pNode = pList.poHead;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 1 );

	// delete the last element
	status = pList.DeleteNode( 30 );
	assert( status );

	// walk down the list and test
	pNode = pList.poHead;

	// we're at the end of the list
	assert( pNode == nullptr );

	// check we have the right number of nodes
	assert( Node::nodeCount == 0 );
}

void LinkedList::RemoveDupsTest( )
{
	LinkedList list = LinkedList( );

	list.AppendNodeToTail( 10 );
	list.AppendNodeToTail( 20 );
	list.AppendNodeToTail( 30 );
	list.AppendNodeToTail( 40 );
	list.AppendNodeToTail( 20 );
	list.AppendNodeToTail( 30 );
	list.AppendNodeToTail( 40 );
	list.AppendNodeToTail( 50 );

	assert( Node::nodeCount == 8 );

	list.RemoveDuplicates( );

	assert( Node::nodeCount == 5 );

	// walk the list
	// walk down the list and test
	Node* pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 10 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 20 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 30 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 40 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 50 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
}

void LinkedList::DeleteMiddleTest( )
{
	LinkedList list = LinkedList( );

	for ( int i = 0; i < 5; i++ )
	{
		list.AppendNodeToTail( i );
	}

	Node* pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 5 );

	list.DeleteMiddleNode( );

	pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 4 );

	list.DeleteMiddleNode( );

	pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 3 );

	list.DeleteMiddleNode( );

	pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 2 );

	// future calls should do nothing
	// because there are no middle nodes

	list.DeleteMiddleNode( );

	pNode = list.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	// we're at the end of the list
	assert( pNode == nullptr );
	assert( Node::nodeCount == 2 );
}

void LinkedList::KthToLastTest( )
{
	LinkedList list;

	for ( int i = 9; i >= 0; i-- )
	{
		list.AppendNodeToTail( i );
	}

	assert( Node::nodeCount == 10 );

	Node* pNode = nullptr;
	for ( int i = 0; i < 10; i++ )
	{
		pNode = list.KthToLast( i );
		assert( pNode );
		assert( pNode->data == i );
	}
}

void LinkedList::PartitionTest( )
{
	LinkedList list1;

	list1.AppendNodeToTail( 3 );
	list1.AppendNodeToTail( 0 );
	list1.AppendNodeToTail( 5 );
	list1.AppendNodeToTail( 3 );
	list1.AppendNodeToTail( 2 );
	list1.AppendNodeToTail( 4 );
	list1.AppendNodeToTail( 8 );
	list1.AppendNodeToTail( 8 );
	list1.AppendNodeToTail( 1 );
	list1.AppendNodeToTail( 1 );
	list1.AppendNodeToTail( -2 );
	list1.AppendNodeToTail( 11 );

	assert( Node::nodeCount == 12 );

	list1.Partition( 3 );

	Node* pNode = list1.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );

	/////////////////////////////////

	LinkedList list2;

	list2.AppendNodeToTail( 3 );
	list2.AppendNodeToTail( 0 );
	list2.AppendNodeToTail( 5 );
	list2.AppendNodeToTail( 3 );
	list2.AppendNodeToTail( 2 );
	list2.AppendNodeToTail( 4 );
	list2.AppendNodeToTail( 8 );
	list2.AppendNodeToTail( 8 );
	list2.AppendNodeToTail( 1 );
	list2.AppendNodeToTail( 1 );
	list2.AppendNodeToTail( -2 );
	list2.AppendNodeToTail( 11 );

	assert( Node::nodeCount == 24 );

	list2.Partition( 8 );

	pNode = list2.poHead;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );

	/////////////////////////////////

	LinkedList list3;

	list3.AppendNodeToTail( 3 );
	list3.AppendNodeToTail( 0 );
	list3.AppendNodeToTail( 5 );
	list3.AppendNodeToTail( 3 );
	list3.AppendNodeToTail( 2 );
	list3.AppendNodeToTail( 4 );
	list3.AppendNodeToTail( 8 );
	list3.AppendNodeToTail( 8 );
	list3.AppendNodeToTail( 1 );
	list3.AppendNodeToTail( 1 );
	list3.AppendNodeToTail( -2 );
	list3.AppendNodeToTail( 11 );

	assert( Node::nodeCount == 36 );

	list3.Partition( -2 );

	pNode = list3.poHead;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );

	/////////////////////////////////

	LinkedList list4;

	list4.AppendNodeToTail( 11 );
	list4.AppendNodeToTail( 3 );
	list4.AppendNodeToTail( 0 );
	list4.AppendNodeToTail( 5 );
	list4.AppendNodeToTail( 3 );
	list4.AppendNodeToTail( 2 );
	list4.AppendNodeToTail( 4 );
	list4.AppendNodeToTail( 8 );
	list4.AppendNodeToTail( 8 );
	list4.AppendNodeToTail( 1 );
	list4.AppendNodeToTail( 1 );
	list4.AppendNodeToTail( -2 );

	assert( Node::nodeCount == 48 );

	// should do nothing
	list4.Partition( 11 );

	pNode = list4.poHead;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );

	// should do nothing
	list4.Partition( -5 );

	pNode = list4.poHead;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 5 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 3 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 8 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == -2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 11 );
	pNode = pNode->pNext;

	// we've reached the end of the list
	assert( pNode == nullptr );
}

void LinkedList::ReversedSumTest( )
{
	// x = 617
	LinkedList x;
	x.AppendNodeToTail( 7 );
	x.AppendNodeToTail( 1 );
	x.AppendNodeToTail( 6 );

	// y = 295
	LinkedList y;
	y.AppendNodeToTail( 5 );
	y.AppendNodeToTail( 9 );
	y.AppendNodeToTail( 2 );

	// z = 12095
	LinkedList z;
	z.AppendNodeToTail( 5 );
	z.AppendNodeToTail( 9 );
	z.AppendNodeToTail( 0 );
	z.AppendNodeToTail( 2 );
	z.AppendNodeToTail( 1 );

	// w = 423
	LinkedList w;
	w.AppendNodeToTail( 3 );
	w.AppendNodeToTail( 2 );
	w.AppendNodeToTail( 4 );

	assert( Node::nodeCount == 14 );

	////////////////////////
	////// x + y ///////////
	////////////////////////

	LinkedList xy = x.ReverseSum( y ); // 912
	Node* pNode = xy.poHead;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 9 );
	pNode = pNode->pNext;

	// end of list
	assert( pNode == nullptr );

	////////////////////////
	////// y + x ///////////
	////////////////////////

	LinkedList yx = y.ReverseSum( x ); // 912
	pNode = yx.poHead;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 9 );
	pNode = pNode->pNext;

	// end of list
	assert( pNode == nullptr );

	////////////////////////
	////// x + z ///////////
	////////////////////////

	LinkedList xz = x.ReverseSum( z ); // 12712
	pNode = xz.poHead;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 7 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	////////////////////////
	////// x + z ///////////
	////////////////////////

	LinkedList zx = z.ReverseSum( x ); // 12712
	pNode = zx.poHead;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 7 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 2 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	// end of list
	assert( pNode == nullptr );

	////////////////////////
	////// x + w ///////////
	////////////////////////

	LinkedList xw = x.ReverseSum( w ); // 1040
	pNode = xw.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	// end of list
	assert( pNode == nullptr );

	////////////////////////
	////// w + x ///////////
	////////////////////////

	LinkedList wx = w.ReverseSum( x ); // 1040
	pNode = wx.poHead;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 4 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 0 );
	pNode = pNode->pNext;

	assert( pNode );
	assert( pNode->data == 1 );
	pNode = pNode->pNext;

	// end of list
	assert( pNode == nullptr );
}

void LinkedList::IsPalindromeTest( )
{
	LinkedList A;
	A.AppendNodeToTail( 1 );
	A.AppendNodeToTail( 1 );
	A.AppendNodeToTail( 1 );
	A.AppendNodeToTail( 1 );
	A.AppendNodeToTail( 1 );
	A.AppendNodeToTail( 1 );
	A.AppendNodeToTail( 1 );
	A.AppendNodeToTail( 1 );

	// even palindrome all the same
	assert( A.IsPalindrome( ) );

	A.AppendNodeToTail( 1 );

	// odd palindrome all the same
	assert( A.IsPalindrome( ) );

	LinkedList B;
	B.AppendNodeToTail( 1 );
	B.AppendNodeToTail( 2 );
	B.AppendNodeToTail( 3 );
	B.AppendNodeToTail( 4 );
	B.AppendNodeToTail( 4 );
	B.AppendNodeToTail( 5 );
	B.AppendNodeToTail( 4 );
	B.AppendNodeToTail( 4 );
	B.AppendNodeToTail( 3 );
	B.AppendNodeToTail( 2 );
	B.AppendNodeToTail( 1 );

	assert( B.IsPalindrome( ) );

	LinkedList C;
	C.AppendNodeToTail( 1 );
	C.AppendNodeToTail( 2 );
	C.AppendNodeToTail( 3 );
	C.AppendNodeToTail( 4 );
	C.AppendNodeToTail( 4 );
	C.AppendNodeToTail( 4 );
	C.AppendNodeToTail( 4 );
	C.AppendNodeToTail( 4 );
	C.AppendNodeToTail( 3 );
	C.AppendNodeToTail( 2 );
	C.AppendNodeToTail( 1 );

	assert( C.IsPalindrome( ) );

	LinkedList D;
	D.AppendNodeToTail( 1 );
	D.AppendNodeToTail( 2 );
	D.AppendNodeToTail( 3 );
	D.AppendNodeToTail( 4 );
	D.AppendNodeToTail( 4 );
	D.AppendNodeToTail( 5 );
	D.AppendNodeToTail( 4 );
	D.AppendNodeToTail( 3 );
	D.AppendNodeToTail( 2 );
	D.AppendNodeToTail( 1 );

	assert( not D.IsPalindrome( ) );

	LinkedList E;
	
	assert( E.IsPalindrome( ) );

	LinkedList F;

	F.AppendNodeToTail( 1 );
	F.AppendNodeToTail( 2 );

	assert( not F.IsPalindrome( ) );
}