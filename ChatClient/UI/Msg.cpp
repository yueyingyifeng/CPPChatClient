#include "Msg.h"

deque<string> Msg::makeLines(const string& line)
{
	deque<string> result;
	int m_len = line.size();
	int valid_width = max_width / 2 - 2;

	if (m_len <= valid_width) {
		result.push_back(line);
		return result;
	}
	int cur_start = 0;
	do {
		string l = line.substr(cur_start, valid_width);
		result.push_back(l);
		cur_start += valid_width;
	} while (cur_start < m_len);

	return result;
}

Msg::Msg(string line, Align align /*= Align::Left*/)
{
	content = makeContent(line,align);
}

deque<string> Msg::makeContent(string line, Align align /*= Align::Left*/, int offset /* = 0*/) {
	int m_len = line.size();
	int spaceIn{};
	deque<string> result;
	deque<string> lines = makeLines(line);

	for (string ln : lines) {

		if (align == Align::Center) {
			spaceIn = (max_width - ln.size() - 1) / 2;
		}
		else if (align == Align::Left) {
			spaceIn = 0;
		}
		else if (align == Align::Right) {
			spaceIn = (max_width - ln.size() - 2);
		}

		string l;
		l.append("|");
		for (int i = 0; i < max_width - ln.size() - 1 + offset; i++) {
			if (i == spaceIn)
				l.append(ln);
			else
				l.append(" ");
		}
		l.append("|");
		result.push_back(l);
	}
	return result;
}