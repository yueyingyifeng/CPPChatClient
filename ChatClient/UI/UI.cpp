#include "UI.h"


void UI::start(const string &title)
{
    string top_line;
    top_line.append("+");
    for(int i{}; i < Content::max_width - 2; i++)
        top_line.append("-");
    top_line.append("+");
    
    Msg t(title,Msg::Align::Center);
    Message bottom("");
    string bottom_line = bottom.generateCharLine("=");

    cout << top_line << endl
         << t.getContent().at(0) << endl
         << bottom_line << endl;
}

void UI::refresh(const Content &content)
{
    for(const string& line : content.getContent())
        cout << line << endl;
}

void UI::refresh(const string &line)
{
    cout << line << endl;
}
