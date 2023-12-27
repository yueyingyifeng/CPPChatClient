#include "Input.h"

Input::Input(const string &username)
{
    prompt(username);
    std::getline(cin, line);
}

void Input::prompt(const string& username) {
    cout << "  " + username + "> ";
}

const string& Input::getLine()
{
    return this->line;
}

const string& Input::operator()(){
    return this->line;
}