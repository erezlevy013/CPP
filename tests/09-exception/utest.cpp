#include "mu_test.h"

#include <string>
#include <climits>


#include "DoubleBuffer.hpp"
#include "Point.hpp"
#include "Pixel.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include "Box.hpp"

using namespace h72;

// BEGIN_TEST(bad_alloc)
// 	DoubleBuffer<int> d(100000000000);
// 	ASSERT_PASS();
// END_TEST

// BEGIN_TEST(check_Fill_and_Assignmen)
// 	DoubleBuffer<int> d1(10,10);
// 	DoubleBuffer<int> d2(10,10);
// 	d1.Fill(Side::FRONT, 1);

// 	d2 = d1;
// 	// d2.Print();

// 	ASSERT_PASS();
// END_TEST

// BEGIN_TEST(check_Fill_and_Cctor)
// 	DoubleBuffer<int> d1(10,10);
// 	d1.Fill(Side::FRONT, 1);
	
// 	DoubleBuffer<int> d2 = d1;
// 	d2 = d1;
// 	// d2.Print();

// 	ASSERT_PASS();
// END_TEST

// BEGIN_TEST(check_Clear_and_Cctor)
// 	DoubleBuffer<int> d1(10,10);
// 	d1.Fill(Side::FRONT, 1);

// 	DoubleBuffer<int> d2 = d1;
// 	d2 = d1;
// 	// d2.Print();
// 	d1.Clear(Side::FRONT);
// 	// d1.Print();
// 	ASSERT_PASS();
// END_TEST

// BEGIN_TEST(check_SwitchSides)
// 	DoubleBuffer<int> d1(10,10);
// 	d1.Fill(Side::FRONT, 1);
	
// 	// d1.Print();
// 	d1.SwitchSides();	
// 	// d1.Print();
// 	ASSERT_PASS();
// END_TEST


// BEGIN_TEST(check_Pixel)
// 	//DoubleBuffer<int> d1(10,10);
// 	Point p(1,1);
// 	Pixel pix(0,0,255);
// 	pix.DrawPixel(p);
// 	ASSERT_PASS();
// END_TEST

// BEGIN_TEST(check_Line)
// 	DoubleBuffer<Pixel> d1(5,5); 
// 	Point p1(1,1);
// 	Point p2(1,4);
// 	Pixel pix(20,20,20);
// 	d1.DrawLine(p1, p2, pix);
// 	d1.print(std::cout, Side::FRONT);
// 	ASSERT_PASS();
// END_TEST

BEGIN_TEST(draw_Row)
    Pixel pixelR(255, 0, 0);
    Pixel pixelG(0, 255, 0);
    DoubleBuffer<Pixel> db(10, 10);
    db.Fill(Side::FRONT, pixelG);
    Point start(0, 0);
    Point end(7, 0);
    Line<Pixel> lineRed(start, end, pixelR);
    lineRed.Draw(db);
    db.SaveToFile();
    ASSERT_PASS();
END_TEST

BEGIN_TEST(draw_Col)
    Pixel pixelR(255, 0, 0);
    Pixel pixelB(0, 0, 255);
    DoubleBuffer<Pixel> db(10, 10);
    db.Fill(Side::FRONT, pixelB);
    Point start(0, 0);
    Point end(0, 9);
    Line<Pixel> lineRed(start, end, pixelR);
    lineRed.Draw(db);
    db.SaveToFile();
    ASSERT_PASS();
END_TEST

BEGIN_TEST(draw_Diagonal_Left)
    Pixel pixelW(255, 255, 255);
    Pixel pixelBl(0, 0, 0);
    DoubleBuffer<Pixel> db(100, 100);
    db.Fill(Side::FRONT, pixelBl);
    Point start(0, 0);
    Point end(100, 100);
    Line<Pixel> lineWhite(start, end, pixelW);
    lineWhite.Draw(db);
    db.SaveToFile();
    ASSERT_PASS();
END_TEST

BEGIN_TEST(draw_Diagonal_Right)
    Pixel pixelWhite(255, 255, 255);
    Pixel pixelBlack(0, 0, 0);
    DoubleBuffer<Pixel> db(100, 100);
    db.Fill(Side::FRONT, pixelBlack);
    Point start(0, 100);
    Point end(100, 0);
    Line<Pixel> lineWhite(start, end, pixelWhite);
    lineWhite.Draw(db);
    db.SaveToFile();
    ASSERT_PASS();
END_TEST

BEGIN_TEST(draw_Box)
    Pixel pixelYellow(255, 255, 0);
    Pixel pixelBlack(0, 0, 0);
    Pixel pixelPink(255, 105, 180);
    Pixel pixelBlue(0, 0, 128);
    DoubleBuffer<Pixel> db(100, 100);
    db.Fill(Side::FRONT, pixelBlack);
    Point start1(0, 20);
    Point end1(30, 80);
    Box<Pixel> box(start1, end1, pixelYellow);
    box.Draw(db);
    Point start2(5, 50);
    Point end2(27, 55);
    Box<Pixel> box2(start2, end2, pixelBlue);
    box2.Draw(db);
    Point start3(5, 90);
    Point end3(60, 95);
    Box<Pixel> box3(start3, end3, pixelPink);
    box3.Draw(db);
    Point start4(35, 20);
    Point end4(65, 80);
    Box<Pixel> box4(start4, end4, pixelYellow);
    box4.Draw(db);
    Point start5(40, 50);
    Point end5(62, 55);
    Box<Pixel> box5(start5, end5, pixelBlue);
    box5.Draw(db);
    db.SaveToFile();
    ASSERT_PASS();
END_TEST

TEST_SUITE("זִיַאדַּתּ אַלגַּום, לַא כַיר פִיהּ")
	//TEST(bad_alloc)
	// TEST(check_Fill_and_Assignmen)
	// TEST(check_Fill_and_Cctor)
	// TEST(check_Clear_and_Cctor)
	// TEST(check_SwitchSides)
	// TEST(check_Pixel)
	// TEST(check_Line)
	// TEST(draw_Row)
	//TEST(draw_Col)
	// TEST(draw_Diagonal_Left)
	// TEST(draw_Diagonal_Right)
    TEST(draw_Box)
END_SUITE

