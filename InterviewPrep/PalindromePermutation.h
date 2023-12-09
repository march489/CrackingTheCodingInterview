#ifndef PALINDROME_PERMUTATION_H
#define PALINDROME_PERMUTATION_H

#include <iostream>

/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. 
A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. 
*/

bool PalindromePermutation( std::string s );
void StripWhiteSpace( std::string& s );

void RunTests_PalindromePermutation();

#endif // !PALINDROME_PERMUTATION_H
