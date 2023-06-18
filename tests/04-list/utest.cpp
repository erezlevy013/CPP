#include "mu_test.h"

#include <string>
#include <climits>

#include "List.hpp"

using namespace h72;

BEGIN_TEST(checkPushHead)
	List<int> list;
	int head;
	list.PushHead(5);	
	list.PushHead(4);
	list.PushHead(3);
	list.PushHead(2);
	list.PushHead(1);
	list.PopHead(head);

	ASSERT_EQUAL(head, 1);
END_TEST

BEGIN_TEST(checkPushTail)
	List<int> list;
	int tail;
	for(size_t i = 0; i < 5; ++i){
		list.PushTail(i+1);
	}
	list.PopTail(tail);

	ASSERT_EQUAL(tail, 5);
END_TEST

BEGIN_TEST(checkPopHead)
	List<int> list;
	int head;
	for(size_t i = 0; i < 5; ++i){
		list.PushTail(i+1);
	}
	for(size_t i = 0; i < 5; ++i){
		list.PopHead(head);
	}

	ASSERT_EQUAL(head, 5);
END_TEST

BEGIN_TEST(checkPopTail)
	List<int> list;
	int tail;
	for(size_t i = 0; i < 5; ++i){
		list.PushHead(i+1);
	}
	for(size_t i = 0; i < 5; ++i){
		list.PopTail(tail);
	}

	ASSERT_EQUAL(tail, 5);
END_TEST

BEGIN_TEST(checkSize)
	List<int> list;
	int size;
	for(size_t i = 0; i < 5; ++i){
		list.PushHead(i+1);
	}
	size = list.Size();

	ASSERT_EQUAL(size, 5);
END_TEST

BEGIN_TEST(checkContains)
	List<int> list;
	int flag;
	for(size_t i = 0; i < 5; ++i){
		list.PushHead(i+1);
	}
	flag = list.Contains(2);

	ASSERT_EQUAL(true, flag);
END_TEST

BEGIN_TEST(checkReverse)
	List<int> list;
	int head;
	for(size_t i = 0; i < 5; ++i){
		list.PushTail(i+1);
	}
	list.Reverse();
	list.PopHead(head);

	ASSERT_EQUAL(head, 5);
END_TEST

BEGIN_TEST(print)
	
	List<int> list;
	for(size_t i = 0; i < 5; ++i){
		list.PushTail(i+1);
	}
	std::cout << list;
	list.Reverse();
	std::cout << list;
	
	ASSERT_PASS();
END_TEST

BEGIN_TEST(checkComparTwoList)
	
	List<int> list;
	list.PushHead(1);	
	list.PushHead(2);
	list.PushHead(3);
	list.PushTail(4);

	List<int> list2;
	list2.PushHead(1);	
	list2.PushHead(2);
	list2.PushHead(3);
	list2.PushTail(4);
	
	if(list == list2){
		ASSERT_PASS();
	}else{
		ASSERT_FAIL(-1);
	}
END_TEST

BEGIN_TEST(checkCopyCtor)
	List<int> list;
	for(size_t i = 0; i < 5; ++i){
		list.PushTail(i+1);
	}
	List<int> list2;
	list2 = list;
	for(size_t i = 5; i < 10; ++i){
		list2.PushTail(i+1);
	}

	ASSERT_NOT_EQUAL(list.Size(), list2.Size());
	ASSERT_EQUAL(list.Size(), 5);
	ASSERT_EQUAL(list2.Size(), 10);
END_TEST

BEGIN_TEST(checkOperatorAssigment)
	List<int> list;
	for(size_t i = 0; i < 5; ++i){
		list.PushTail(i+1);
	}
	List<int> list2 = list;
	int head, head2;
	list.PopHead(head);
	list2.PopHead(head2);

	ASSERT_EQUAL(head, head2);
END_TEST


TEST_SUITE("זִיַאדַּתּ אַלגַּום, לַא כַיר פִיהּ")
	TEST(checkPushHead)
	TEST(checkPushTail)
	TEST(checkPopHead)
	TEST(checkPopTail)
	TEST(checkSize)
	TEST(checkContains)
	TEST(checkReverse)
	TEST(print)
	TEST(checkComparTwoList)
	TEST(checkCopyCtor)
	TEST(checkOperatorAssigment)

END_SUITE

