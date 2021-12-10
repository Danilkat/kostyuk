#pragma once
#include <string>
#include <vector>
#include "InterpreterException.h"

using namespace std;

enum class lexemeType
{
	VarName, //имя (идентификатор переменной)
	IntNum, //целое число без знака
	IntType, //int
	ArrayType,
	If,
	Else,
	While,
	Read,
	Write,
	Allocate, //new
	LeftBrace, //{
	RightBrace,
	LeftSquareBracket,
	RightSquareBracket,
	LeftRoundBracket,
	RightRoundBracket,
	Plus,
	Minus,
	Multiply,
	Divide,
	Semicolon,
	Comma,
	Less,
	Assign,
	More,
	Equal,
	LessOrEqual,
	MoreOrEqual,
	NotEqual,
	Finish,
	Error
};

struct lexeme
{
	lexemeType lexeme_type;
	string value;
	debugInfo info;
};

class Analyzer {
public:
	void Run();
	vector<lexeme> GetData();
	Analyzer(const string&);

private:
	lexeme NextLexeme();
	bool ischar(char ch);

	string program_text;
	int current_index;
	debugInfo current_info;
	vector<lexeme> data;
};

//text(char *) -> lex_anal(text) -> lexemes(lexeme *) -> synt_anal(lexemes) -> OPS -> interpret(OPS)