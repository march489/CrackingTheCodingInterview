#ifndef ONE_AWAY_H
#define ONE_AWAY_H

#include <iostream>

/* 
 * One Away: There are three types of edits that can be performed on strings: 
 * insert a character, remove a character, or replace a character. 
 * Given two strings, write a function to check if they are one edit (or zero edits) away. 
 */

bool OneAway( std::string a, std::string b );

void RunTests_OneAway();

#endif // !ONE_AWAY_H
