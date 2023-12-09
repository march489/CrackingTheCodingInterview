#include "Matrix.h"
#include <assert.h>
#include <string>
#include <iostream>

Matrix::Matrix( int rows, int cols )
	: poData( nullptr ), numRows( rows ), numCols( cols )
{
	this->poData = new unsigned short[rows * cols] {0};
	assert( this->poData );
}

void Matrix::Rotate()
{
	// only call on a square matrix
	assert( this->numRows == this->numCols );

	size_t numEntries = this->numCols * this->numRows;
	unsigned short* pNewData = new unsigned short[numEntries]();
	assert( pNewData );

	for (int i = 0; i < this->numRows; i++)
	{
		for (int j = 0; j < this->numRows; j++)
		{
			size_t r = this->numRows - j - 1;
			size_t c = i;

			pNewData[r * this->numCols + c] = this->poData[i * this->numCols + j];
		}
	}

	delete[] this->poData;
	this->poData = pNewData;
}

Matrix::Matrix( const Matrix& m )
	: poData( nullptr ), numRows( m.numRows ), numCols( m.numCols )
{
	size_t numEntries = m.numRows * m.numCols;
	this->poData = new unsigned short[numEntries]();
	assert( this->poData );

	memcpy_s( this->poData,
			  numEntries * sizeof( unsigned short ),
			  m.poData,
			  numEntries * sizeof( unsigned short ) );
}

Matrix& Matrix::operator= ( const Matrix& m )
{
	if (this->poData)
	{
		delete[] this->poData;
		this->poData = nullptr;
	}

	size_t numEntries = m.numRows * m.numCols;
	this->poData = new unsigned short[numEntries]();
	assert( this->poData );

	memcpy_s( this->poData,
			  numEntries * sizeof( unsigned short ),
			  m.poData,
			  numEntries * sizeof( unsigned short ) );

	this->numCols = m.numCols;
	this->numRows = m.numRows;

	return *this;
}

Matrix::~Matrix()
{
	delete[] this->poData;
	this->poData = nullptr;
}

void Matrix::Print( const char* const name )
{
	std::cout << name << ":\n";
	for (int i = 0; i < this->numRows; i++)
	{
		for (int j = 0; j < this->numCols; j++)
		{
			//std::cout << this->poData[i * this->numCols + j] << " ";
			printf( "%2d ", this->poData[i * this->numCols + j] );
		}

		std::cout << '\n';
	}

	std::cout << '\n';
}

unsigned short Matrix::getElement( size_t row, size_t col ) const
{
	assert( row < this->numRows );
	assert( col < this->numCols );

	return this->poData[row * this->numCols + col];
}

unsigned short Matrix::setElement( size_t row, size_t col, unsigned short n )
{
	assert( row < this->numRows );
	assert( col < this->numCols );

	if (n == 0)
	{
		// update the row
		memset( &this->poData[row * this->numCols],
				0,
				this->numCols * sizeof( unsigned short ) );

		//update the column
		for (size_t r = 0; r < this->numRows; r++)
		{
			this->poData[r * this->numCols + col] = 0;
		}
	}
	else
	{
		this->poData[row * this->numCols + col] = n;
	}

	return this->poData[row * this->numCols + col];
}

void Matrix::MatrixTest()
{
	Matrix A( 2, 3 );
	A.poData[0] = 0;
	A.poData[1] = 1;
	A.poData[2] = 2;
	A.poData[3] = 3;
	A.poData[4] = 4;
	A.poData[5] = 5;

	A.Print( "A" );

	Matrix B( A );

	B.Print( "B" );

	assert( B.numRows == 2 );
	assert( B.numCols == 3 );

	assert( B.poData[0] == 0 );
	assert( B.poData[1] == 1 );
	assert( B.poData[2] == 2 );
	assert( B.poData[3] == 3 );
	assert( B.poData[4] == 4 );
	assert( B.poData[5] == 5 );

	Matrix C = A;

	C.Print( "C" );

	assert( C.numRows == 2 );
	assert( C.numCols == 3 );

	assert( C.poData[0] == 0 );
	assert( C.poData[1] == 1 );
	assert( C.poData[2] == 2 );
	assert( C.poData[3] == 3 );
	assert( C.poData[4] == 4 );
	assert( C.poData[5] == 5 );

	Matrix D( 4, 4 );
	D.poData[0] = 10;
	D.poData[1] = 11;
	D.poData[2] = 12;
	D.poData[3] = 13;
	D.poData[4] = 14;
	D.poData[5] = 15;
	D.poData[6] = 16;
	D.poData[7] = 17;
	D.poData[8] = 18;
	D.poData[9] = 19;
	D.poData[10] = 20;
	D.poData[11] = 21;
	D.poData[12] = 22;
	D.poData[13] = 23;
	D.poData[14] = 24;
	D.poData[15] = 25;

	D.Print( "D" );

	D.Rotate();

	D.Print( "D Rotated" );

	assert( D.poData[0] == 13 );
	assert( D.poData[1] == 17 );
	assert( D.poData[2] == 21 );
	assert( D.poData[3] == 25 );
	assert( D.poData[4] == 12 );
	assert( D.poData[5] == 16 );
	assert( D.poData[6] == 20 );
	assert( D.poData[7] == 24 );
	assert( D.poData[8] == 11 );
	assert( D.poData[9] == 15 );
	assert( D.poData[10] == 19 );
	assert( D.poData[11] == 23 );
	assert( D.poData[12] == 10 );
	assert( D.poData[13] == 14 );
	assert( D.poData[14] == 18 );
	assert( D.poData[15] == 22 );

	D.Print( "D" );

	assert( D.getElement( 0, 0 ) == 13 );
	assert( D.getElement( 0, 1 ) == 17 );
	assert( D.getElement( 0, 2 ) == 21 );
	assert( D.getElement( 0, 3 ) == 25 );
	assert( D.getElement( 1, 0 ) == 12 );
	assert( D.getElement( 1, 1 ) == 16 );
	assert( D.getElement( 1, 2 ) == 20 );
	assert( D.getElement( 1, 3 ) == 24 );
	assert( D.getElement( 2, 0 ) == 11 );
	assert( D.getElement( 2, 1 ) == 15 );
	assert( D.getElement( 2, 2 ) == 19 );
	assert( D.getElement( 2, 3 ) == 23 );
	assert( D.getElement( 3, 0 ) == 10 );
	assert( D.getElement( 3, 1 ) == 14 );
	assert( D.getElement( 3, 2 ) == 18 );
	assert( D.getElement( 3, 3 ) == 22 );

	D.setElement( 0, 0, 10 );
	D.setElement( 0, 1, 11 );
	D.setElement( 0, 2, 12 );
	D.setElement( 0, 3, 13 );
	D.setElement( 1, 0, 14 );
	D.setElement( 1, 1, 15 );
	D.setElement( 1, 2, 16 );
	D.setElement( 1, 3, 17 );
	D.setElement( 2, 0, 18 );
	D.setElement( 2, 1, 19 );
	D.setElement( 2, 2, 20 );
	D.setElement( 2, 3, 21 );
	D.setElement( 3, 0, 22 );
	D.setElement( 3, 1, 23 );
	D.setElement( 3, 2, 24 );
	D.setElement( 3, 3, 25 );

	D.Print( "D" );

	assert( D.getElement( 0, 0 ) == 10 );
	assert( D.getElement( 0, 1 ) == 11 );
	assert( D.getElement( 0, 2 ) == 12 );
	assert( D.getElement( 0, 3 ) == 13 );
	assert( D.getElement( 1, 0 ) == 14 );
	assert( D.getElement( 1, 1 ) == 15 );
	assert( D.getElement( 1, 2 ) == 16 );
	assert( D.getElement( 1, 3 ) == 17 );
	assert( D.getElement( 2, 0 ) == 18 );
	assert( D.getElement( 2, 1 ) == 19 );
	assert( D.getElement( 2, 2 ) == 20 );
	assert( D.getElement( 2, 3 ) == 21 );
	assert( D.getElement( 3, 0 ) == 22 );
	assert( D.getElement( 3, 1 ) == 23 );
	assert( D.getElement( 3, 2 ) == 24 );
	assert( D.getElement( 3, 3 ) == 25 );

	D.setElement( 1, 1, 0 );

	D.Print( "D" );

	assert( D.getElement( 0, 0 ) == 10 );
	assert( D.getElement( 0, 1 ) == 0 );
	assert( D.getElement( 0, 2 ) == 12 );
	assert( D.getElement( 0, 3 ) == 13 );
	assert( D.getElement( 1, 0 ) == 0 );
	assert( D.getElement( 1, 1 ) == 0 );
	assert( D.getElement( 1, 2 ) == 0 );
	assert( D.getElement( 1, 3 ) == 0 );
	assert( D.getElement( 2, 0 ) == 18 );
	assert( D.getElement( 2, 1 ) == 0 );
	assert( D.getElement( 2, 2 ) == 20 );
	assert( D.getElement( 2, 3 ) == 21 );
	assert( D.getElement( 3, 0 ) == 22 );
	assert( D.getElement( 3, 1 ) == 0 );
	assert( D.getElement( 3, 2 ) == 24 );
	assert( D.getElement( 3, 3 ) == 25 );

	A.Print( "A" );
	assert( A.getElement( 0, 0 ) == 0 );
	assert( A.getElement( 0, 1 ) == 1 );
	assert( A.getElement( 0, 2 ) == 2 );
	assert( A.getElement( 1, 0 ) == 3 );
	assert( A.getElement( 1, 1 ) == 4 );
	assert( A.getElement( 1, 2 ) == 5 );

	A.setElement( 0, 0 , 10 );
	A.setElement( 0, 1 , 11 );
	A.setElement( 0, 2 , 12 );
	A.setElement( 1, 0 , 13 );
	A.setElement( 1, 1 , 14 );
	A.setElement( 1, 2 , 15 );

	A.Print( "A" );

	assert( A.getElement( 0, 0 ) == 10 );
	assert( A.getElement( 0, 1 ) == 11 );
	assert( A.getElement( 0, 2 ) == 12 );
	assert( A.getElement( 1, 0 ) == 13 );
	assert( A.getElement( 1, 1 ) == 14 );
	assert( A.getElement( 1, 2 ) == 15 );

	A.setElement( 1, 1, 0 );

	A.Print( "A" );
	assert( A.getElement( 0, 0 ) == 10 );
	assert( A.getElement( 0, 1 ) == 0 );
	assert( A.getElement( 0, 2 ) == 12 );
	assert( A.getElement( 1, 0 ) == 0 );
	assert( A.getElement( 1, 1 ) == 0 );
	assert( A.getElement( 1, 2 ) == 0 );
}