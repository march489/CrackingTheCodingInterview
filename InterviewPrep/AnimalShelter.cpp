#include "AnimalShelter.h"
#include <assert.h>

AnimalShelter::AnimalShelter( )
	: queue{ std::list<Animal*>( ) }
{

}

void AnimalShelter::Enqueue( Animal* pA )
{
	this->queue.push_back( pA );
}

Animal* AnimalShelter::DequeueAny( )
{
	assert( not this->queue.empty( ) );

	Animal* pAnimal = this->queue.front( );

	this->queue.pop_front( );
	return pAnimal;
}

Animal* AnimalShelter::DequeueCat( )
{
	auto iterator = this->queue.begin( );
	while ( iterator != this->queue.end( )
			&& ( **iterator ).type != Animal::Type::CAT )
	{
		iterator++;
	}

	Animal* pAnimal{ nullptr };

	if ( iterator != this->queue.end( ) )
	{
		// valid hit
		pAnimal = *iterator;
		this->queue.erase( iterator );
	}

	return pAnimal;
}

Animal* AnimalShelter::DequeueDog( )
{
	auto iterator = this->queue.begin( );
	while ( iterator != this->queue.end( )
			&& ( **iterator ).type != Animal::Type::DOG )
	{
		iterator++;
	}

	Animal* pAnimal{ nullptr };

	if ( iterator != this->queue.end( ) )
	{
		// valid hit
		pAnimal = *iterator;
		this->queue.erase( iterator );
	}

	return pAnimal;
}

const Animal& AnimalShelter::peek( ) const
{
	return *this->queue.front( );
}

bool AnimalShelter::isEmpty( ) const
{
	return this->queue.empty( );
}

size_t AnimalShelter::size( ) const
{
	return this->queue.size( );
}