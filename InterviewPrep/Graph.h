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
	~Graph( );

	GraphNode* AddNode( std::string name ); 
	void AddEdge( GraphNode* a, GraphNode* b );

	void RemoveNode( GraphNode* pNode );
	void RemoveEdge( GraphNode* a, GraphNode* b );

private:
	std::unordered_set<GraphNode*> nodes;
};
#endif // !GRAPH_H
