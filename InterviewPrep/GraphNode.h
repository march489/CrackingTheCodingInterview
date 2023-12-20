#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <iostream>
#include <unordered_set>

class Graph;
class DiGraph;

class GraphNode
{
public:
	GraphNode( ) = delete;
	GraphNode( const GraphNode& in );
	GraphNode& operator=( const GraphNode& in );
	~GraphNode( );

	GraphNode( std::string _name, int _data );

	bool IsNeighbor( GraphNode* pNeighbor );
	std::string GetName( ) const;
	size_t NumNeighbors( ) const;

	void AddNeighbor( GraphNode* pNeighbor );
	void RemoveNeighbor( GraphNode* pNeighbor );

	void Print( ) const;
	static void RunTests_GraphNodes( );

	friend Graph;
	friend DiGraph;

private:
	std::string name;
	std::unordered_set<GraphNode*> neighbors;
	int data;
};
#endif // !GRAPH_NODE_H
