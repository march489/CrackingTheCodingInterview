#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#include <string>

// demos
void ShiftOperationDemos( );

// utility
bool GetBit( int num, unsigned char index );
int SetBit( int num, unsigned char index );
int ClearBit( int num, unsigned char index );
bool IsF32Precise( float x );
std::string i32_to_string_binary( int x );

// problems
int Insertion( int N, int M, int startIndex, int endIndex );
std::string BinaryToString( float x );
int FlipBitToWin( int k );
std::pair<unsigned int, unsigned int> NextNumber( int n );

// tests
void InsertionTest( );
void BinaryToStringTest( );
void BinaryRepTest( );
void FlipBitToWinTest( );
void NextNumberTest( );

// big test
void RunTests_BitManipulation( );
#endif // !BIT_MANIPULATION_H
