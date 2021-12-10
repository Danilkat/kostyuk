#include <iostream>
#include <fstream>
#include "InterpreterOps.h"

using namespace std;

int main() {
	cout << "enter source: ";
	string file_name;
	cin >> file_name;
	ifstream pr = ifstream(file_name);
	string program_text;
	getline(pr, program_text, '\0');

	cout << "run '" + file_name +  "' program:" << endl;
	try
	{
		Analyzer textAnalyzer(program_text);
		textAnalyzer.Run();

		Generator opsGenerator(textAnalyzer.GetData());
		opsGenerator.Run();

		Interpreter opsInterpreter(opsGenerator.GetData());
		opsInterpreter.Run();
	}
	catch (const exception& ex)
	{
		cerr << ex.what() << endl;
	}
	cout << "finish '" + file_name + "' program." << endl;

	return 0;
}