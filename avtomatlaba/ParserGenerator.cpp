#include <stdexcept>
#include "ParserGenerator.h"

using namespace std;

void Generator::RecognizeNonterminal() {
    switch (current_nonterminal)
    {
    case Nonterminal::S:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Assign);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Assign);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntType:
        {
            magazine.emplace(Nonterminal::S);
            magazine.emplace(Nonterminal::I);
            magazine.emplace(lexemeType::IntType);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task6);
            break;
        }
        case lexemeType::ArrayType:
        {
            magazine.emplace(Nonterminal::S);
            magazine.emplace(Nonterminal::I);
            magazine.emplace(lexemeType::ArrayType);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task7);
            break;
        }
        case lexemeType::If:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::K);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::If);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task3);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::While:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::While);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task5);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task4);
            break;
        }
        case lexemeType::Read:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Read);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Read);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Write:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Write);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Write);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Allocate:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Comma);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Allocate);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Memory); // буква m
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::Q:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Assign);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Assign);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::If:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::K);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::If);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task3);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::While:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::While);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task5);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task4);
            break;
        }
        case lexemeType::Read:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Read);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Read);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Write:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Write);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Write);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Allocate:
        {
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Comma);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Allocate);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Memory); // буква m
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::A:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Assign);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Assign);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::If:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::K);
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::If);

            generator.emplace(GeneratorTask::Task3);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::While:
        {
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::C);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::While);

            generator.emplace(GeneratorTask::Task5);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task1);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task4);
            break;
        }
        case lexemeType::Read:
        {
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Read);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Read);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Write:
        {
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Write);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Write);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Allocate:
        {
            magazine.emplace(lexemeType::Semicolon);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Comma);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::LeftRoundBracket);
            magazine.emplace(lexemeType::Allocate);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Memory); // буква m
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::I:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::M);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task8);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::M:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Semicolon:
        {
            magazine.emplace(lexemeType::Semicolon);

            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Comma:
        {
            magazine.emplace(Nonterminal::M);
            magazine.emplace(lexemeType::VarName);
            magazine.emplace(lexemeType::Comma);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task8);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::H:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::LeftSquareBracket:
        {
            magazine.emplace(lexemeType::RightSquareBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftSquareBracket);

            generator.emplace(GeneratorTask::Index);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::C:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::L);
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::UnarMinus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::L:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Less:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Less);

            generator.emplace(GeneratorTask::Less);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::More:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::More);

            generator.emplace(GeneratorTask::More);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Equal:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::Equal);

            generator.emplace(GeneratorTask::Equal);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::LessOrEqual:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LessOrEqual);

            generator.emplace(GeneratorTask::LessOrEqual);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::MoreOrEqual:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::MoreOrEqual);

            generator.emplace(GeneratorTask::MoreOrEqual);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::NotEqual:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::NotEqual);

            generator.emplace(GeneratorTask::NotEqual);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::K:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Else:
        {
            magazine.emplace(lexemeType::RightBrace);
            magazine.emplace(Nonterminal::Q);
            magazine.emplace(Nonterminal::S);
            magazine.emplace(lexemeType::LeftBrace);
            magazine.emplace(lexemeType::Else);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Task2);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::E:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::UnarMinus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::U:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::T);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Plus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::U);
            magazine.emplace(Nonterminal::T);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::Minus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::T:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::UnarMinus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::V:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::Multiply:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::F);
            magazine.emplace(lexemeType::Multiply);

            generator.emplace(GeneratorTask::Multiply);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Divide:
        {
            magazine.emplace(Nonterminal::V);
            magazine.emplace(Nonterminal::F);
            magazine.emplace(lexemeType::Divide);

            generator.emplace(GeneratorTask::Divide);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case Nonterminal::F:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Plus:
        {
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Plus);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        case lexemeType::Minus:
        {
            magazine.emplace(Nonterminal::Z);
            magazine.emplace(Nonterminal::G);
            magazine.emplace(lexemeType::Minus);

            generator.emplace(GeneratorTask::UnarMinus);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::G:
    {
        switch (current_lexeme.lexeme_type)
        {
        case lexemeType::VarName:
        {
            magazine.emplace(Nonterminal::H);
            magazine.emplace(lexemeType::VarName);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::VariableId);
            break;
        }
        case lexemeType::IntNum:
        {
            magazine.emplace(lexemeType::IntNum);

            generator.emplace(GeneratorTask::IntNumber);
            break;
        }
        case lexemeType::LeftRoundBracket:
        {
            magazine.emplace(lexemeType::RightRoundBracket);
            magazine.emplace(Nonterminal::E);
            magazine.emplace(lexemeType::LeftRoundBracket);

            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            generator.emplace(GeneratorTask::Empty);
            break;
        }
        default:
        {
            string msg = "Generator error; Unexpected lexeme;";
            throw InterpretException(msg, current_lexeme.info);
        }
        }
        break;
    }
    case Nonterminal::Z:
    {
        break;
    }
    case Nonterminal::Error:
    default:
        string msg = "Generator error; Error or unknown state;";
        throw InterpretException(msg, current_lexeme.info);
    }
}

void Generator::DoTask() {
    switch (current_task)
    {
    case GeneratorTask::Empty:
        break;
    case GeneratorTask::VariableId:
    {
        string name = current_lexeme.value;
        if (data.int_table.count(name) ||
            data.massInt_table.count(name))
        {
            data.ops.emplace_back(name, OpsItemType::IntVariable, current_lexeme.info);
        }
        else
        {
            string msg = "Generator error; Unknown variable name = '" + name + "';";
            throw InterpretException(msg, current_lexeme.info);
        }
        
        break;
    }   
    case GeneratorTask::IntNumber:
    {
        int num = stoi(current_lexeme.value);
        data.ops.emplace_back(num, current_lexeme.info);
        break;
    }
    case GeneratorTask::Read:
        data.ops.emplace_back(OpsItemOperation::Read, current_lexeme.info);
        break;
    case GeneratorTask::Write:
        data.ops.emplace_back(OpsItemOperation::Write, current_lexeme.info);
        break;
    case GeneratorTask::Plus:
        data.ops.emplace_back(OpsItemOperation::Plus, current_lexeme.info);
        break;
    case GeneratorTask::Minus:
        data.ops.emplace_back(OpsItemOperation::Minus, current_lexeme.info);
        break;
    case GeneratorTask::UnarMinus:
        data.ops.emplace_back(OpsItemOperation::UnarMinus, current_lexeme.info);
        break;
    case GeneratorTask::Multiply:
        data.ops.emplace_back(OpsItemOperation::Miltiply, current_lexeme.info);
        break;
    case GeneratorTask::Divide:
        data.ops.emplace_back(OpsItemOperation::Divide, current_lexeme.info);
        break;
    case GeneratorTask::Less:
        data.ops.emplace_back(OpsItemOperation::Less, current_lexeme.info);
        break;
    case GeneratorTask::Assign:
        data.ops.emplace_back(OpsItemOperation::Assign, current_lexeme.info);
        break;
    case GeneratorTask::More:
        data.ops.emplace_back(OpsItemOperation::More, current_lexeme.info);
        break;
    case GeneratorTask::Equal:
        data.ops.emplace_back(OpsItemOperation::Equal, current_lexeme.info);
        break;
    case GeneratorTask::LessOrEqual:
        data.ops.emplace_back(OpsItemOperation::LessOrEqual, current_lexeme.info);
        break;
    case GeneratorTask::MoreOrEqual:
        data.ops.emplace_back(OpsItemOperation::MoreOrEqual, current_lexeme.info);
        break;
    case GeneratorTask::NotEqual:
        data.ops.emplace_back(OpsItemOperation::NotEqual, current_lexeme.info);
        break;
    case GeneratorTask::Index:
        data.ops.emplace_back(OpsItemOperation::Index, current_lexeme.info);
        break;
    case GeneratorTask::Task1:
    {
        marks.push(data.ops.size());
        data.ops.emplace_back(0, current_lexeme.info);
        data.ops.emplace_back(OpsItemOperation::JumpIfFalse, current_lexeme.info);
        break;
    }
    case GeneratorTask::Task2:
    {
        int place = marks.top(); marks.pop();
        marks.push(data.ops.size());
        data.ops.emplace_back(0, current_lexeme.info);
        data.ops.emplace_back(OpsItemOperation::Jump, current_lexeme.info);
        data.ops[place].int_num = data.ops.size();
        break;
    }
    case GeneratorTask::Task3:
    {
        int place = marks.top(); marks.pop();
        data.ops[place].int_num = data.ops.size();
        break;
    }
    case GeneratorTask::Task4:
    {
        marks.push(data.ops.size());
        break;
    }
    case GeneratorTask::Task5:
    {
        int place = marks.top(); marks.pop();
        data.ops.emplace_back(marks.top(), current_lexeme.info); marks.pop();
        data.ops.emplace_back(OpsItemOperation::Jump, current_lexeme.info);
        data.ops[place].int_num = data.ops.size();
        break;
    }
    case GeneratorTask::Task6:
    {
        current_table = table::Int;
        break;
    }
    case GeneratorTask::Task7:
    {
        current_table = table::MassInt;
        break;
    }
    case GeneratorTask::Task8:
    {
        string name = current_lexeme.value;

        if (data.int_table.count(name) ||
            data.massInt_table.count(name)) {
            string msg = "Generator error; Redefine a variable name = '" + name + "';";
            throw InterpretException(msg, current_lexeme.info);
        }
        if (current_table == table::Int) {
            data.int_table.insert({ name, 0 });
        }
        else if (current_table == table::MassInt) {
            data.massInt_table.insert({ name, vector<int>(0) });
        }

        break;
    }
    case GeneratorTask::Memory:
    {
        data.ops.emplace_back(OpsItemOperation::Memory, current_lexeme.info);
        break;
    }
    default: {
        string msg = "Generator error; Unknown generator task;";
        throw InterpretException(msg, current_lexeme.info);
    }
    }
}

void Generator::Run() {
    magazine.emplace(Nonterminal::S);
    generator.push(GeneratorTask::Empty);

    int current_lexeme_idx = 0;
    current_lexeme = input_data[current_lexeme_idx];

    while (!generator.empty() && !magazine.empty())
    {
        MagazineItem current_magazine_item = magazine.top(); magazine.pop();
        current_nonterminal = current_magazine_item.nonterminal;
        current_task = generator.top(); generator.pop();
   
        DoTask();

        if (current_magazine_item.is_lexeme) {

            if (current_lexeme.lexeme_type == lexemeType::Finish) {
                string msg = "Generator error; All lexemes are read, but magazine is not empty;";
                throw InterpretException(msg, current_lexeme.info);
            }

            if (current_magazine_item.lexeme == current_lexeme.lexeme_type) {
                current_lexeme_idx++;
                current_lexeme = input_data[current_lexeme_idx];
            }
            else {
                string msg = "Generator error; Unexpected lexeme;";
                throw InterpretException(msg, current_lexeme.info);
            }
        }
        else {
            RecognizeNonterminal();
        }
    }

    if (current_lexeme.lexeme_type != lexemeType::Finish) {
        string msg = "Generator error; There are unrecognized lexemes;";
        throw InterpretException(msg, current_lexeme.info);
    }
}

InterpretData Generator::GetData() {
    return data;
}

Generator::Generator(vector<lexeme> lexemes) {
    input_data = lexemes;
}
