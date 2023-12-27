/*
* 			Author : yyyf
* 		CreateDate : 2023/12/24 12:05:06
* 	   Description ：
*/
#ifndef H_UI
#define H_UI

#include <iostream>
#include "Message.h"
#include "Input.h"


using std::cout;
using std::endl;

class UI{
public:
    void start(const string& title);
    void refresh(const Content& content);
    void refresh(const string& line);

};

#endif