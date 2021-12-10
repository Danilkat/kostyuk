#include <stdexcept>
#include "LexicalAnalyzer.h"

Analyzer::Analyzer(const string& pr_text) {
	program_text = pr_text;
	current_index = 0;
	current_info.line = 1;
	current_info.pos = 1;
}

vector<lexeme> Analyzer::GetData() {
	return data;
}

void Analyzer::Run() {
	lexeme cur_lexeme;

	while (current_index < program_text.size()) {
		while (current_index < program_text.size() && isspace(program_text[current_index])) {
			switch (program_text[current_index++]) {
			case ' ':
				++current_info.pos;
				break;
			case '\n':
				++current_info.line; current_info.pos = 1;
				break;
			case '\t':
				current_info.pos += 4;
				break;
			}
		}

		if (current_index >= program_text.size()) {
			break;
		}

		cur_lexeme = NextLexeme();
		cur_lexeme.info = current_info;

		if (cur_lexeme.lexeme_type == lexemeType::Error) {
			string msg = "Analyzer error; Unknown char with value = '" + cur_lexeme.value + "';";
			throw InterpretException(msg, cur_lexeme.info);
		}

		current_info.pos += cur_lexeme.value.size();

		data.push_back(cur_lexeme);
	}

	cur_lexeme.lexeme_type = lexemeType::Finish;
	cur_lexeme.info = current_info;
	data.push_back(cur_lexeme);
}

bool Analyzer::ischar(char ch) {
	return ch == '_' || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

lexeme Analyzer::NextLexeme() {
	char cur_ch = program_text[current_index];
	current_index++;

	lexeme result;
	result.lexeme_type = lexemeType::Error;
	result.value = cur_ch;

	if (ischar(cur_ch)) {
		result.lexeme_type = lexemeType::VarName;
		cur_ch = program_text[current_index];
		while (current_index < program_text.size() && ischar(cur_ch) || isdigit(cur_ch)) {
			result.value += cur_ch;
			current_index++;
			cur_ch = program_text[current_index];
		}
		if (result.value == "int") {
			result.lexeme_type = lexemeType::IntType;
		}
		else if (result.value == "array") {
		result.lexeme_type = lexemeType::ArrayType;
	}
		else if (result.value == "if") {
			result.lexeme_type = lexemeType::If;
		}
		else if (result.value == "else") {
			result.lexeme_type = lexemeType::Else;
		}
		else if (result.value == "while") {
			result.lexeme_type = lexemeType::While;
		}
		else if (result.value == "read") {
			result.lexeme_type = lexemeType::Read;
		}
		else if (result.value == "write") {
			result.lexeme_type = lexemeType::Write;
		}
		else if (result.value == "new") {
			result.lexeme_type = lexemeType::Allocate;
		}
	}
	else if (isdigit(cur_ch)) {
		result.lexeme_type = lexemeType::IntNum;
		cur_ch = program_text[current_index];

		while (current_index < program_text.size() && isdigit(cur_ch)) {
			result.value += cur_ch;
			current_index++;
			cur_ch = program_text[current_index];
		}

		if (current_index < program_text.size() && ischar(cur_ch)) {
			while (current_index < program_text.size() && ischar(cur_ch)) {
				result.value += cur_ch;
				++current_index;
				cur_ch = program_text[current_index];
			}
			result.lexeme_type = lexemeType::Error;
		}
	}
	else if (cur_ch == '{') {
		result.lexeme_type = lexemeType::LeftBrace;
	}
	else if (cur_ch == '}') {
		result.lexeme_type = lexemeType::RightBrace;
	}
	else if (cur_ch == '[') {
		result.lexeme_type = lexemeType::LeftSquareBracket;
	}
	else if (cur_ch == ']') {
		result.lexeme_type = lexemeType::RightSquareBracket;
	}
	else if (cur_ch == '(') {
		result.lexeme_type = lexemeType::LeftRoundBracket;
	}
	else if (cur_ch == ')') {
		result.lexeme_type = lexemeType::RightRoundBracket;
	}
	else if (cur_ch == '+') {
		result.lexeme_type = lexemeType::Plus;
	}
	else if (cur_ch == '-') {
		result.lexeme_type = lexemeType::Minus;
	}
	else if (cur_ch == '*') {
		result.lexeme_type = lexemeType::Multiply;
	}
	else if (cur_ch == '/') {
		result.lexeme_type = lexemeType::Divide;
	}
	else if (cur_ch == ';') {
		result.lexeme_type = lexemeType::Semicolon;
	}
	else if (cur_ch == ',') {
		result.lexeme_type = lexemeType::Comma;
	}
	else if (cur_ch == '<') {
		result.lexeme_type = lexemeType::Less;
		if (current_index < program_text.size() && program_text[current_index] == '=') {
			current_index++;
			result.lexeme_type = lexemeType::LessOrEqual;
			result.value = "<=";
		}
	}
	else if (cur_ch == '=') {
		result.lexeme_type = lexemeType::Assign;
		if (current_index < program_text.size() && program_text[current_index] == '=') {
			current_index++;
			result.lexeme_type = lexemeType::Equal;
			result.value = "==";
		}
	}
	else if (cur_ch == '>') {
		result.lexeme_type = lexemeType::More;
		if (current_index < program_text.size() && program_text[current_index] == '=') {
			current_index++;
			result.lexeme_type = lexemeType::MoreOrEqual;
			result.value = ">=";
		}
	}
	else if (cur_ch == '!' && current_index < program_text.size() && program_text[current_index] == '=') {
	current_index++;
		result.lexeme_type = lexemeType::NotEqual;
		result.value = "!=";
	}

	return result;
}