#include "ChapterFour.h"
#include "BinaryHeap.h"
#include "GraphNode.h"
#include "Graph.h"
#include "BinaryTree.h"
#include "DiGraph.h"

void RunTests_ChapterFour( )
{
	BinaryHeap::RunTests_BinaryHeap( );
	GraphNode::RunTests_GraphNodes( );
	Graph::RunTests_GraphBasics( );
	BinaryTree::RunTests_BinaryTree( );
	DiGraph::RunTests_DiGraph( );
}