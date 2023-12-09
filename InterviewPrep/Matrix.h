#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	Matrix() = delete;
	Matrix( const Matrix& );
	Matrix& operator= ( const Matrix& );
	~Matrix();

	// specialized constructor
	Matrix( int rows, int cols );

	void Rotate();

	// test
	static void MatrixTest();
	void Print( const char* const name );

	// accessors 
	unsigned short getElement( size_t row, size_t col ) const;
	unsigned short setElement( size_t row, size_t col, unsigned short n );


	// data
private:
	unsigned short* poData;
	size_t numRows;
	size_t numCols;
};
#endif // !MATRIX_H
