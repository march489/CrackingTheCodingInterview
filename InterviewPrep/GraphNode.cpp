#include "GraphNode.h"

GraphNode::GraphNode( std::string _name )
	: name( _name ), neighbors( std::unordered_set<GraphNode*>( ) )
{

}

GraphNode::GraphNode( const GraphNode& in )
	: name( in.name ), neighbors( std::unordered_set<GraphNode*>( ) )
{

}

GraphNode& GraphNode::operator=( const GraphNode& in )
{
	this->name = in.name;
	this->neighbors.clear( );

	return *this;
}

GraphNode::~GraphNode( )
{
	for ( auto it = this->neighbors.begin( ); it != this->neighbors.end( ); it++ )
	{
		( *it )->RemoveNeighbor( this );
	}

	this->neighbors.clear( );
}

bool GraphNode::IsNeighbor( GraphNode* pNeighbor )
{
	return this->neighbors.contains( pNeighbor );
}

std::string GraphNode::GetName( ) const
{
	return this->name;
}

size_t GraphNode::NumNeighbors( ) const
{
	return this->neighbors.size( );
}

void GraphNode::AddNeighbor( GraphNode* pNeighbor )
{
	this->neighbors.insert( pNeighbor );
}

void GraphNode::RemoveNeighbor( GraphNode* pNeighbor )
{
	this->neighbors.erase( pNeighbor );
}

void GraphNode::Print( ) const
{
	printf( "%p: %s\n\tneighbors:\n", this, this->name.c_str( ) );

	for ( auto it = this->neighbors.begin( ); it != this->neighbors.end( ); it++ )
	{
		printf( "\t\t%s\n", ( *it )->name.c_str( ) );
	}
}

void GraphNode::RunTests_GraphNodes( )
{
	GraphNode winter( "Winter" );
	GraphNode spring( "Spring" );
	GraphNode summer( "Summer" );
	GraphNode fall( "Fall" );

	// create connections
	winter.AddNeighbor( &spring );
	spring.AddNeighbor( &winter );

	winter.AddNeighbor( &summer );
	summer.AddNeighbor( &winter );

	winter.Print( );
	spring.Print( );
	summer.Print( );
	fall.Print( );
}