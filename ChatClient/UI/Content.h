/*
* 			Author : yyyf
* 		CreateDate : 2023/12/24 13:19:35
* 	   Description ：提供显示内容的基类，应用模板方法模式
*/
#ifndef H_Content
#define H_Content

#include <deque>
#include <string>


using std::deque;
using std::string;

class Content {
protected:
	deque<string> content;
public:
	static int max_width;
	Content();
	Content(const deque<string>& content) : content(content){};
	deque<string> getContent() const;
};

#endif




