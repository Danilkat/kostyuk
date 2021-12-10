#pragma once
#include <exception>
#include <string>

struct debugInfo
{
	int line;
	int pos;
};

struct InterpretException : public std::exception
{
    std::string msg;
    const char* what() const throw () {
        return msg.c_str();
    }

    InterpretException(std::string m, debugInfo i) {
        m += "\nDebugInfo = \"line='" + std::to_string(i.line) + "', pos='" + std::to_string(i.pos) + "'\";\n";
        msg = m;
    }
};