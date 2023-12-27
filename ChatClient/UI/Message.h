/*
* 			Author : yyyf
* 		CreateDate : 2023/12/24 12:16:04
* 	   Description ：
*/
#ifndef H_Message
#define H_Message

#include "Msg.h"
#include "Color.h"

class Message :
    public Msg
{
protected:
	//���ɿ���
public:
    Message(const string& line, Color color = Color(), Align align = Align::Left);
	Message(const string& line, Color fg,Color bg, Align align = Align::Left);

	static string generateCharLine(const char* l = " ");

private:
	deque<string> addColor(string line, Color color, Align align = Align::Left);
	deque<string> addColor(string line, Color fg, Color bg, Align align = Align::Left);
}; 

#endif