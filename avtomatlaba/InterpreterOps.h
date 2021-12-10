#pragma once
#include "ParserGenerator.h"

class Interpreter {
public:
	void Run();

	Interpreter(InterpretData);
private:
    int GetInt(OpsItem&);
	double GetFloat(OpsItem&);
    void SetInt(OpsItem&, int);
	void SetFloat(OpsItem&, double);
	bool IsFloat(OpsItem&);

	InterpretData input_data;
};
