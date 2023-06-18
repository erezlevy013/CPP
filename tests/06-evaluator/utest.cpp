#include "mu_test.h"

#include <string>
#include <climits>

#include <map>

#include "Expression.hpp"


BEGIN_TEST(check)
	
	std::map<std::string, double> vars;
	vars["x"] = 2.0;
	vars["y"]= 0.5;
	vars["z"] = 1.25;
	Expression ev(vars);
	ev.Calc("1.0 + ( 2.0 * 3.0 - 1.0 ) - 2.0");
	ASSERT_PASS();
END_TEST

TEST_SUITE("זִיַאדַּתּ אַלגַּום, לַא כַיר פִיהּ")
	TEST(check)
	
END_SUITE

