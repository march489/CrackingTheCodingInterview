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
	virtual ~GraphNode( );

	GraphNode( std::string _name, int _data );

	bool IsOutNeighbor( GraphNode* pNeighbor ) const;
	std::string GetName( ) const;
	size_t GetOutDegree( ) const;

	void AddOutNeighbor( GraphNode* pNeighbor );
	void RemoveOutNeighbor( GraphNode* pNeighbor );

	void Print( ) const;
	static void RunTests_GraphNodes( );

	friend Graph;
	friend DiGraph;

protected:
	std::string name;
	std::unordered_set<GraphNode*> outNeighbors;
	int data;
};


#endif // !GRAPH_NODE_H
