#ifndef IS_PERMUTATION_H
#define IS_PERMUTATION_H

#include <iostream>
#include <unordered_map>

// Check Permutation : Given two strings, write a method to decide if one is a permutation of the
// other.

bool IsPermutation( const std::string a, const std::string b );
std::unordered_map<char, int> frequencies( const std::string a );

void RunTests_IsPermutation();

#endif