/*
* 			Author : yyyf
* 		CreateDate : 2023/12/24 12:05:46
* 	   Description ：
*/
#ifndef H_Input
#define H_Input

#include <iostream>
#include "Content.h"

using std::cout;
using std::cin;

class Input{
    string line;
public:
    Input(const string& username);
    const string& getLine();
    const string& operator()();
	static void prompt(const string& username);
};

#endif