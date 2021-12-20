#include <stack>
#include <stdexcept>
#include <iostream>
#include "InterpreterOps.h"

using namespace std;

Interpreter::Interpreter(InterpretData data) {
	input_data = data;
}

int Interpreter::GetInt(OpsItem& item) {
	if (item.type == OpsItemType::IntNumber)
	{
		return item.int_num;
	}
	else if (input_data.int_table.count(item.var_name))
	{
		return input_data.int_table[item.var_name];
	}
	else if (input_data.massInt_table.count(item.var_name))
	{
		return input_data.massInt_table[item.var_name][item.int_num];
	}
	else
	{
		string msg = "Interpreter error; int variable or int number was expected;";
		throw InterpretException(msg, item.info);
	}
}

double Interpreter::GetFloat(OpsItem& item) {
//	if (item.type == OpsItemType::FloatNumber)
//	{
//		return item.float_num;
//	}
//	else if (input_data.float_table.count(item.var_name))
//	{
//		return input_data.float_table[item.var_name];
//	}
//	else if (input_data.massFloat_table.count(item.var_name))
//	{
//		return input_data.massFloat_table[item.var_name][item.int_num];
//	}
//	else
//	{
//		string msg = "Interpreter error; float variable or float number was expected;";
//		throw InterpretException(msg, item.info);
//	}
	return 0.0;
}

void Interpreter::SetInt(OpsItem& item, int num) {
	if (input_data.int_table.count(item.var_name))
	{
		input_data.int_table[item.var_name] = num;
	}
	else if (input_data.massInt_table.count(item.var_name))
	{
		input_data.massInt_table[item.var_name][item.int_num] = num;
	}
	else
	{
		string msg = "Interpreter error; int variable was expected;";
		throw InterpretException(msg, item.info);
	}
}

void Interpreter::AllocateMemory(OpsItem& passport, int n) {
	if (input_data.massInt_table.count(passport.var_name))
	{
		if (input_data.massInt_table[passport.var_name].size() > 0) {
			string msg = "Interpreter error; memory already initalized;";
			throw InterpretException(msg, passport.info);
		}
		else {
			input_data.massInt_table[passport.var_name].resize(n);
		}
	}
	else {
		string msg = "Interpreter error; unknown array passport;";
		throw InterpretException(msg, passport.info);
	}
};

void Interpreter::SetFloat(OpsItem& item, double num) {
//	if (input_data.float_table.count(item.var_name))
//	{
//		input_data.float_table[item.var_name] = num;
//	}
//	else if (input_data.massFloat_table.count(item.var_name))
//	{
//		input_data.massFloat_table[item.var_name][item.int_num] = num;
//	}
//	else
//	{
//		string msg = "Interpreter error; float variable was expected;";
//		throw InterpretException(msg, item.info);
//	}
}

bool Interpreter::IsFloat(OpsItem& item) {
//	return item.type == OpsItemType::FloatVariable || item.type == OpsItemType::FloatNumber;
	return false;
}

void Interpreter::Run()
{
	stack<OpsItem> magazine;
	auto& ops = input_data.ops;
	auto& int_table = input_data.int_table;
	auto& arrayInt_table = input_data.massInt_table;

	for (size_t i = 0; i < ops.size(); ++i)
	{
		switch (ops[i].type)
		{
		case OpsItemType::IntVariable:
		case OpsItemType::IntNumber:
		{
			magazine.push(ops[i]);
			break;
		}
		case OpsItemType::Operation:
		{
			switch (ops[i].operation)
			{
			case OpsItemOperation::Read:
			{
				auto a = magazine.top(); magazine.pop();
				
				int number;
				cin >> number;
				SetInt(a, number);
				
				break;
			}
			case OpsItemOperation::Write:
			{
				auto a = magazine.top(); magazine.pop();
				cout << GetInt(a) << endl;
				break;
			}
			case OpsItemOperation::Plus:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();
				int result;
				result = GetInt(a) + GetInt(b);
				magazine.emplace(result, a.info);
				break;
			}
			case OpsItemOperation::Minus:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				int result;
				result = GetInt(a) - GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::Miltiply:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				int result;
				result = GetInt(a) * GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::Divide:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				int result;
				result = GetInt(a) / GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::Less:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				bool result;
				result = GetInt(a) < GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::Assign:
			{
				// a = b;
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				SetInt(a, GetInt(b));

				break;
			}
			case OpsItemOperation::More:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				bool result;
				result = GetInt(a) > GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::Equal:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				bool result;
				result = GetInt(a) == GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::LessOrEqual:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				bool result;
				result = GetInt(a) <= GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::MoreOrEqual:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				bool result;
				result = GetInt(a) >= GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::NotEqual:
			{
				auto b = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				bool result;
				result = GetInt(a) != GetInt(b);
				magazine.emplace(result, a.info);

				break;
			}
			case OpsItemOperation::Jump:
			{
				auto metka = magazine.top(); magazine.pop();

				i = GetInt(metka) - 1;
				break;
			}
			case OpsItemOperation::JumpIfFalse:
			{
				auto metka = magazine.top(); magazine.pop();
				auto a = magazine.top(); magazine.pop();

				if (GetInt(a) == 0) {
					i = GetInt(metka) - 1;
				}
				break;
			}
			case OpsItemOperation::Index:
			{
				auto idx = magazine.top(); magazine.pop();
				auto arr = magazine.top(); magazine.pop();

				arr.int_num = GetInt(idx);

				magazine.push(arr);
				break;
			}
			case OpsItemOperation::Memory:
			{
				auto n = magazine.top(); magazine.pop();
				auto arr = magazine.top(); magazine.pop();

				AllocateMemory(arr, GetInt(n));
				magazine.push(arr);
				break;
			}
			default:
			{
				string msg = "Interpreter error; Unknown operation;";
				throw InterpretException(msg, ops[i].info);
			}
			}
			break;
		}
		default:
		{
			string msg = "Interpreter error; Unknown ops item;";
			throw InterpretException(msg, ops[i].info);
		}
		}
	}
}