#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_set>
#include <iostream>

class GraphNode;

class Graph
{
public:
	Graph( );
	Graph( const Graph& ) = delete;
	Graph& operator=( const Graph& ) = delete;
	virtual ~Graph( );

	GraphNode* AddNode( std::string name, int data );
	virtual void AddEdge( GraphNode* a, GraphNode* b );

	void RemoveNode( GraphNode* pNode );
	virtual void RemoveEdge( GraphNode* a, GraphNode* b );

	void SetRoot( GraphNode* a );
	GraphNode* GetRoot( ) const;

	// searches 
	void ForEach_DepthFirst( void ( GraphNode::* fptr )( void ) const );
	void ForEach_BreadthFirst( void( GraphNode::* fptr )( void ) const );

	std::vector<GraphNode*>* FindShortestPath( GraphNode* pStart, GraphNode* pFinish );

	void Print( const char* const pName ) const;
	static void RunTests_GraphBasics( );

private:
	void privForEach_DFS( void( GraphNode::* fptr )( void ) const,
						  GraphNode* pNode,
						  std::unordered_set<GraphNode*>& visitedNodes );

protected:
	std::unordered_set<GraphNode*> nodes;
	GraphNode* pRoot;
};
#endif // !GRAPH_H
