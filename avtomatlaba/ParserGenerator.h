#pragma once
#include <map>
#include <stack>
#include <vector>
#include <string>
#include "LexicalAnalyzer.h"

using namespace std;

enum class OpsItemType {
	IntVariable,
	IntNumber,
	Operation,
	Error
};

enum class OpsItemOperation {
	Read,
	Write,
	Plus,
	Minus,
	UnarMinus,
	Miltiply,
	Divide,
	Less,
	Assign,
	More,
	Equal,
	LessOrEqual,
	MoreOrEqual,
	NotEqual,
	Jump,
	JumpIfFalse,
	Index,
	Error
};

struct OpsItem {
	OpsItemType type = OpsItemType::Error;
	OpsItemOperation operation = OpsItemOperation::Error;
	string var_name;
	int int_num = 0;
	debugInfo info;

	OpsItem(string name, OpsItemType t, debugInfo i)
	{
		type = t;
		var_name = name;
		info = i;
	}

	OpsItem(OpsItemOperation op, debugInfo i)
	{
		type = OpsItemType::Operation;
		operation = op;
		info = i;
	}

	OpsItem(int number, debugInfo i)
	{
		type = OpsItemType::IntNumber;
		int_num = number;
		info = i;
	}
};

struct InterpretData
{
	vector<OpsItem> ops;
	map<string, int> int_table;
	map<string, vector<int>> massInt_table;
};

class Generator {
public:
	void Run();
	InterpretData GetData();
	Generator(vector<lexeme>);

private:
	void RecognizeNonterminal();
	void DoTask();

	enum class table {
		Int,
		MassInt,
	};

	enum class Nonterminal {
		S, // → define D begin A end
		D, // → intID | floatID | massIntPD | massFloatPD | λ
		I, // → aM
		M, // → ,aM | ;
		P, // → a[i]N
		N, // → ,a[i]N | ;
		A, // → aH = E;A | if (C) {A} KZA | while (C) {A} A | read(aH);A | write(E);A | λ
		H, // → [E] | λ
		C, // → (E)VUL | aHVUL | iVUL | fVUL
		L, // → <EZ | >EZ | == EZ | ≤EZ | ≥EZ | !=EZ
		K, // → else {A} | λ
		E, // → (E)VU | aHVU | iVU | fVU
		U, // → + TU | -TU | λ
		T, // → (E)V | aHV | iV | fV
		V, // → *FV | /FV | λ
		F, // → (E) | aH | i | f
		Z, // → λ
		Error // ошибочное состояние
	};

	enum class GeneratorTask
	{
		Empty,
		VariableId,
		IntNumber,
		Read,
		Write,
		Plus,
		Minus,
		UnarMinus,
		Multiply,
		Divide,
		Less,
		Assign,
		More,
		Equal,
		LessOrEqual,
		MoreOrEqual,
		NotEqual,
		Index,
		Task1,
		Task2,
		Task3,
		Task4,
		Task5,
		Task6,
		Task7,
		Task8,
		Task9,
		Task10,
		Task11,
	};

	struct MagazineItem
	{
		bool is_lexeme;
		lexemeType lexeme;
		Nonterminal nonterminal;

		MagazineItem(lexemeType l) {
			is_lexeme = true;
			lexeme = l;
			nonterminal = Nonterminal::Error;
		}

		MagazineItem(Nonterminal s) {
			is_lexeme = false;
			lexeme = lexemeType::Error;
			nonterminal = s;
		}
	};

	GeneratorTask current_task;
	lexeme current_lexeme;
	Nonterminal current_nonterminal;
	table current_table;
	string last_array_name;
	stack<MagazineItem> magazine;
	stack<GeneratorTask> generator;
	stack<int> marks;
	InterpretData data;

	vector<lexeme> input_data;
};

