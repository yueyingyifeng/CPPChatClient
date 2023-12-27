#include "Message.h"
Message::Message(const string& line, Color color, Align align /*= Align::Left*/)
	: Msg(addColor(line,color,align))
{}

Message::Message(const string& line, Color fg, Color bg, Align align /*= Align::Left*/)
	: Msg(addColor(line,fg,bg,align))
{}

deque<string> Message::addColor(string line, Color color, Align align  /*= Align::Left*/)
{
	string ln;
	ln.append(color()).append(" ").append(line).append(" ").append(Color()());
	
	deque<string> result = makeContent(ln,align,9);
	result.push_front(generateCharLine());
	result.push_back(generateCharLine());

	return result;
}

deque<string> Message::addColor(string line, Color fg, Color bg, Align align  /*= Align::Left*/)
{
	string ln;
	ln.append(fg()).append(" ").append(bg()).append(" ").append(line).append(" ").append(Color()());
	deque<string> result = makeContent(ln,align, 10);
	result.push_front(generateCharLine());
	result.push_back(generateCharLine());

	return result;
}

string Message::generateCharLine(const char* l /* = " "*/)
{
	string line;
	line.append("|");
	for (int i{}; i < max_width - 2; i++)
		line.append(l);
	line.append("|");
	return line;
}