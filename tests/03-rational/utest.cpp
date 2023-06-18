#include "mu_test.h"

#include <string>
#include <climits>

#include "rational.hpp"

BEGIN_TEST(equality_on_Rational_1)
	Rational r1(42);
	Rational r2(42, 1);
		
	ASSERT_EQUAL(r1, r2);
END_TEST

BEGIN_TEST(equality_on_Rational_2)
	Rational r1(1);
	Rational r2;

	ASSERT_EQUAL(r1, r2);
END_TEST

BEGIN_TEST(Check_operator_assigment_1)
	Rational r1(42);
	Rational r2(100, 2);
	r1 = r2;

	ASSERT_EQUAL(r1, r2);
END_TEST

BEGIN_TEST(Check_operator_assigment_2)
	Rational r1(33, 15);
	Rational r2(1, 2);
	Rational r3(100, 2);
	r3 = r2 = r1;

	ASSERT_EQUAL(r3, r1);
END_TEST

BEGIN_TEST(Check_operator_mul_assigment_1)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(3, 4);
	r1 *= r2;

	ASSERT_EQUAL(r3, r1);
END_TEST

BEGIN_TEST(Check_operator_mul_assigment_2)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(3, 8);
	r1 *= r2 *= r2;

	ASSERT_EQUAL(r3, r1);
END_TEST

BEGIN_TEST(Check_operator_mul_assigment_3)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(12, 2);
	r1 *= 4;

	ASSERT_EQUAL(r3, r1);
END_TEST

BEGIN_TEST(Check_operator_mul_assigment_4)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(3, 8);
	r1 *= r2 *= 2;

	ASSERT_EQUAL(r1, r1);
END_TEST

BEGIN_TEST(Check_operator_add_assigment_1)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(2, 1);
	r1 += r2;

	ASSERT_EQUAL(r3, r1);
END_TEST

BEGIN_TEST(Check_operator_add_assigment_2)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(5, 2);
	r1 += r2 += r2;

	ASSERT_EQUAL(r3, r1);
END_TEST

BEGIN_TEST(Check_operator_add_assigment_3)
	Rational r1(3, 2);
	Rational r2(11, 2);
	r1 += 4;
	
	ASSERT_EQUAL(r2, r1);
END_TEST

BEGIN_TEST(Check_operator_add_assigment_4)
	Rational r1(3, 2);
	Rational r2(1, 2);
	r1 += r2 += 2;
	
	ASSERT_EQUAL(r1, r1);
END_TEST

BEGIN_TEST(Check_operator_sub_assigment_1)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(1, 1);
	r1 -= r2;
	
	ASSERT_EQUAL(r3, r1);
END_TEST

BEGIN_TEST(Check_operator_sub_assigment_2)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(1, 4);
	Rational r4(5, 4);
	r1 -= r2 -= r3;
	
	ASSERT_EQUAL(r4, r1);
END_TEST

BEGIN_TEST(Check_operator_sub_assigment_3)
	Rational r1(3, 2);
	Rational r2(-3, 2);
	r1 -= 3;
	
	ASSERT_EQUAL(r2, r1);
END_TEST

BEGIN_TEST(Check_operator_sub_assigment_4)
	Rational r1(3, 2);
	Rational r2(8, 2);
	Rational r3(1, -2);
	r1 -= r2 -= 2;
	
	ASSERT_EQUAL(r1, r3);
END_TEST

BEGIN_TEST(Check_operator_div_assigment_1)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(3, 1);
	r1 /= r2;
	
	ASSERT_EQUAL(r3, r1);
END_TEST

BEGIN_TEST(Check_operator_div_assigment_2)
	Rational r1(3, 2);
	Rational r2(1, 2);
	Rational r3(1, 4);
	Rational r4(3, 4);
	r1 /= r2 /= r3;
	
	ASSERT_EQUAL(r4, r1);
END_TEST

BEGIN_TEST(Check_operator_div_assigment_3)
	Rational r1(3, 2);
	Rational r2(1, 2);
	r1 /= 3;
	
	ASSERT_EQUAL(r2, r1);
END_TEST

BEGIN_TEST(Check_operator_div_assigment_4)
	Rational r1(3, 2);
	Rational r2(8, 2);
	Rational r3(3, 4);
	r1 /= r2 /= 2;
	
	ASSERT_EQUAL(r1, r3);
END_TEST

BEGIN_TEST(Check_operator_subscript)
	Rational r1(3, 2);
	int x = r1[Rational::Numerator];
	int y = r1[Rational::Denom];
	
	ASSERT_EQUAL(x, 3);
	ASSERT_EQUAL(y, 2);
END_TEST

BEGIN_TEST(Check_operator_print_double)
	Rational r1(3, 2);
	double x = r1();
	
	ASSERT_EQUAL(x, 1.5);
END_TEST

BEGIN_TEST(Check_operator_reduce)
	Rational r1(800, 1000);
	Rational r2(4, 5);
	r1.Reduce();
	
	ASSERT_EQUAL(r2, r1);
END_TEST


TEST_SUITE("זִיַאדַּתּ אַלגַּום, לַא כַיר פִיהּ")
	TEST(equality_on_Rational_1)
	TEST(equality_on_Rational_2)

	TEST(Check_operator_assigment_1)
	TEST(Check_operator_assigment_2)

	TEST(Check_operator_mul_assigment_1)
	TEST(Check_operator_mul_assigment_2)
	TEST(Check_operator_mul_assigment_3)
	TEST(Check_operator_mul_assigment_4)

	TEST(Check_operator_add_assigment_1)
	TEST(Check_operator_add_assigment_2)
	TEST(Check_operator_add_assigment_3)
	TEST(Check_operator_add_assigment_4)

	TEST(Check_operator_sub_assigment_1)
	TEST(Check_operator_sub_assigment_2)
	TEST(Check_operator_sub_assigment_3)
	TEST(Check_operator_sub_assigment_4)

	TEST(Check_operator_div_assigment_1)
	TEST(Check_operator_div_assigment_2)
	TEST(Check_operator_div_assigment_3)
	TEST(Check_operator_div_assigment_4)

	TEST(Check_operator_subscript)
	TEST(Check_operator_print_double)
	TEST(Check_operator_reduce)


END_SUITE

