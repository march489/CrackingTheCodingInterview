#include "GraphNode.h"

GraphNode::GraphNode( std::string _name, int _data )
	: name( _name ),
	outNeighbors( std::unordered_set<GraphNode*>( ) ),
	data( _data )
{

}

GraphNode::GraphNode( const GraphNode& in )
	: name( in.name ),
	outNeighbors( std::unordered_set<GraphNode*>( ) ),
	data( in.data )
{

}

GraphNode& GraphNode::operator=( const GraphNode& in )
{
	this->name = in.name;
	this->data = in.data;
	this->outNeighbors.clear( );

	return *this;
}

GraphNode::~GraphNode( )
{
	this->outNeighbors.clear( );
}

bool GraphNode::IsOutNeighbor( GraphNode* pNeighbor ) const
{
	return this->outNeighbors.contains( pNeighbor );
}

std::string GraphNode::GetName( ) const
{
	return this->name;
}

size_t GraphNode::GetOutDegree( ) const
{
	return this->outNeighbors.size( );
}

void GraphNode::AddOutNeighbor( GraphNode* pNeighbor )
{
	this->outNeighbors.insert( pNeighbor );
}

void GraphNode::RemoveOutNeighbor( GraphNode* pNeighbor )
{
	this->outNeighbors.erase( pNeighbor );
}

void GraphNode::Print( ) const
{
	printf( "%p: %s (%d)\n\tneighbors: ", this, this->name.c_str( ), this->data );
	for ( auto it = this->outNeighbors.begin( ); it != this->outNeighbors.end( ); it++ )
	{
		if ( it != this->outNeighbors.begin( ) )
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
	winter.AddOutNeighbor( &spring );
	spring.AddOutNeighbor( &winter );

	winter.AddOutNeighbor( &summer );
	summer.AddOutNeighbor( &winter );

	winter.Print( );
	spring.Print( );
	summer.Print( );
	fall.Print( );
}