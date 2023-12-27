/*
* 			Author : yyyf
* 		CreateDate : 2023/12/24 12:16:12
* 	   Description ：
*/
#ifndef H_Msg
#define H_Msg

#include "Content.h"

class Msg
	: public Content {
public:
	enum class Align {
		Left, Right, Center
	};
	Msg(const deque<string>& content) : Content(content){};
	Msg(string line, Align align = Align::Left);
protected:
	//�������Ĳ��ֱ�ɶ���
	deque<string> makeLines(const string& line);
	deque<string> makeContent(string line, Align align = Align::Left, int offset = 0);
};



#endif