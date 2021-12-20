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
	Memory,
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
		S, // → intIS | arrayIS | aH=E;Q | read(aH);Q | write(E);Q | new(a, E);Q | if (C) {SQ} KZQ | while (C) {SQ} Q
		Q, // → aH = E; Q | read(aH); Q | write(E); Q | new(a, E);Q | if (C) {SQ} KZQ |  while (C)  {SQ}Q | λ
		A, // → aH = E; | read(aH); |  write(E); | new(a, E); | if (C) {SQ} KZ | while (C) {SQ}
		I, // → aM
		M, // → ,aM | ;
		H, // → [E] | λ
		C, // → (E)VUL | aHVUL | kVUL | +GVUL | -GVUL
		L, // → <EZ | >EZ | == EZ | ≤EZ | ≥EZ | !=EZ
		K, // → else {SQ} | λ
		E, // → (E)VU | aHVU | +GVU | -GVU
		U, // → +TU | -TU | λ
		T, // → (E)V | aHV | kV | +GV | -GV
		V, // → *FV | /FV | λ
		F, // → +G | -GZ | (E) | aH | k
		G, // → (E) | aH | k
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
		Memory,
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

