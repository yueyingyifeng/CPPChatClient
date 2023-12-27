#include "Color.h"

Color::Color(Code c)
{
	color = Color::operator()(c);
}

Color::Color(Code fg, Code bg)
{
	string result = string(Color::operator()(fg)) + string(Color::operator()(bg,true));
	color = result.c_str();
}

const char* Color::operator()(Code c, bool isBG /*= false*/) const
{

	if (isBG)
		switch (c)
		{
		default:
		case Color::Code::Default:
			return "\033[0m";
		case Color::Code::Red:
			return "\033[41m";
		case Color::Code::Green:
			return "\033[42m";
		case Color::Code::Blue:
			return "\033[44m";
		case Color::Code::Yello:
			return "\033[43m";
		}

	switch (c)
	{
	default:
	case Color::Code::Default:
		return "\033[0m";
	case Color::Code::Red:
		return "\033[31m";
	case Color::Code::Green:
		return "\033[32m";
	case Color::Code::Blue:
		return "\033[34m";
	case Color::Code::Yello:
		return "\033[33m";
	}
}

const char* Color::operator()() const
{
	return color;
}

const char* Color::operator[](Code c) const
{
	return Color::operator()(c, true);
}
