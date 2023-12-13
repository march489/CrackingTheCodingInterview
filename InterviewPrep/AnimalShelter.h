#ifndef ANIMAL_SHELTER_H
#define ANIMAL_SHELTER_H

#include <list>
#include <iostream>

struct Animal
{
	enum class Type
	{
		CAT,
		DOG,
		UNDEFINED
	};

	Animal( ) = delete;
	Animal( std::string _name, Type _type )
		: name( _name ), type( _type )
	{
	}
	Animal( const Animal& in )
		: name( in.name ), type( in.type )
	{
	}
	Animal& operator=( const Animal& in )
	{
		this->name = in.name;
		this->type = in.type;
	}
	~Animal( ) = default;

	// data
	std::string name;
	Type type;
};

class AnimalShelter
{
public:
	AnimalShelter( );
	AnimalShelter( const AnimalShelter& ) = delete;
	AnimalShelter& operator=( const AnimalShelter& ) = delete;
	~AnimalShelter( ) = default; // we'll see

	void Enqueue( Animal* );
	Animal* DequeueCat( );
	Animal* DequeueDog( );
	Animal* DequeueAny( );

	const Animal& peek( ) const;
	bool isEmpty( ) const;
	size_t size( ) const;

private:
	std::list<Animal*> queue;
};
#endif // !ANIMAL_SHELTER_H
