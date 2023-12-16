#include "GraphNode.h"

GraphNode::GraphNode( std::string _name, int _data )
	: name( _name ),
	neighbors( std::unordered_set<GraphNode*>( ) ),
	data( _data )
{

}

GraphNode::GraphNode( const GraphNode& in )
	: name( in.name ),
	neighbors( std::unordered_set<GraphNode*>( ) ),
	data( in.data )
{

}

GraphNode& GraphNode::operator=( const GraphNode& in )
{
	this->name = in.name;
	this->data = in.data;
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
	printf( "%p: %s (%d)\n\tneighbors: ", this, this->name.c_str( ), this->data );
	for ( auto it = this->neighbors.begin( ); it != this->neighbors.end( ); it++ )
	{
		if ( it != this->neighbors.begin( ) )
		{
			printf( ", " );
		}

		printf( "%s (%d)", ( *it )->name.c_str( ), ( *it )->data );
	}
	printf( "\n" );
}

void GraphNode::RunTests_GraphNodes( )
{
	GraphNode winter( "Winter", 12 );
	GraphNode spring( "Spring", 15 );
	GraphNode summer( "Summer", 11 );
	GraphNode fall( "Fall", 5 );

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