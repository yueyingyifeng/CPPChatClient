/*
* 			Author : yyyf
* 		CreateDate : 2023/12/24 12:13:27
* 	   Description ：
*/
#ifndef H_Color
#define H_Color

#include <string>

using std::string;

class Color
{
	const char* color;
public:
	enum class Code {
		Default, Red, Green, Blue, Yello
	};
	Color() :color("\033[0m") {}
	Color(Code c);
	Color(Code fg, Code bg);
	//��ȡ��ɫ
	const char* operator()() const;
	//��ɫ���Ƿ���Ϊ����ɫ
	const char* operator()(Code c, bool isBG = false) const;
	//��ɫ������ɫ
	const char* operator[](Code c) const;
};

#endif