#include "mu_test.h"

#include <string>
#include <climits>

#include <iostream>
#include <unordered_map>
#include <functional>
#include <cmath>

#include "Token.hpp"
#include "Lexer.hpp"
#include "Exper.hpp"
#include "Number.hpp"
#include "Parser.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Div.hpp"
#include "Mul.hpp"
#include "Pow.hpp"
#include "Modulo.hpp"
#include "Var.hpp"


BEGIN_TEST(checkLexer)
	std::vector<std::string> vec = {"+", "-", "*","^"};
	Lexer l(vec);
	std::vector<Token> vecTok= l.Split("cos(3)");
	for (auto i: vecTok) {
   		std::cout << i.GetValue() <<" ,";
	}
	TRACER <<"\n";

	ASSERT_PASS();
END_TEST

BEGIN_TEST(checkParserFunc)
	std::vector<std::string> vec = {"+", "-", "*", "/", "^"};
	Lexer l(vec);
	std::vector<Token> vecTok= l.Split("cos(0)");
	std::unordered_map<std::string, std::function<double(double)>> funcs = {{"sin",sin}, {"cos",cos}};
	Parser p(funcs);
	Expr* tree = p.Parse(vecTok);

	TRACER <<"\n";
	TRACER <<tree->Value()<<"\n";
	ASSERT_PASS();
END_TEST

BEGIN_TEST(checkParser1)
	std::vector<std::string> vec = {"+", "-", "*", "/", "^"};
	Lexer l(vec);
	std::vector<Token> vecTok= l.Split("5+20*10 /40 ");
	Parser p;
	p.Parse(vecTok);
	TRACER <<"\n";

	ASSERT_PASS();
END_TEST

BEGIN_TEST(checkParser2)
	std::vector<std::string> vec = {"+", "-", "*"};
	Lexer l(vec);
	std::vector<Token> vecTok= l.Split("(1 + 2.0 * 3.0) - 1.0 * 5.0 * 5.0 ");
	Parser p;
	Expr* tree = p.Parse(vecTok);

	TRACER <<tree->Value()<<"\n";

	ASSERT_PASS();
END_TEST

BEGIN_TEST(checkParser3)
	std::vector<std::string> vec = {"+", "-", "*", "/", "^"};
	Lexer l(vec);
	std::vector<Token> vecTok= l.Split("42 - 7 * (2 + 2) ^ x");
	Parser p;
	p.Parse(vecTok);
	Expr* tree = p.Parse(vecTok);
	std::unordered_map<std::string, double> map = {{"x", 2}};
	TRACER <<tree->Value(map)<<"\n";
	TRACER <<"\n";

	ASSERT_PASS();
END_TEST

BEGIN_TEST(checkParser4)
	std::vector<std::string> vec = {"+", "-", "*", "/", "^"};
	Lexer l(vec);
	std::vector<Token> vecTok= l.Split("4 ^ 3 * 2 ^ 2");
	Parser p;
	p.Parse(vecTok);
	Expr* tree = p.Parse(vecTok);

	tree->Print();
	TRACER <<tree->Value()<<"\n";
	TRACER <<"\n";

	ASSERT_PASS();
END_TEST

TEST_SUITE("זִיַאדַּתּ אַלגַּום, לַא כַיר פִיהּ")
	TEST(checkLexer)
	TEST(checkParserFunc)
	// TEST(checkParser1)
	// TEST(checkParser2)
	// TEST(checkParser3)
	// TEST(checkParser4)
	
END_SUITE

