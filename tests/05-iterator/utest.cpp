#include "mu_test.h"

#include <string>
#include <climits>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <utility>

#include "Iter.hpp"
#include "person.hpp"

using namespace h72;

BEGIN_TEST(checkVec)
	std::vector<int> vec = {1,2,3,4,5,6,9,4,10,6,12};
	auto it = findRepating(vec);

	ASSERT_EQUAL(*it, 4);
END_TEST

BEGIN_TEST(checkList)
	std::list<int> list = {1,2,3,4,5,6,9,4,10,6,12};
	auto it = findRepating(list);

	ASSERT_EQUAL(*it, 4);
END_TEST

BEGIN_TEST(checkListString)
	std::list<std::string> list = { "aaaa", "bbbb", "aaaa"};
	auto it = findRepating(list);

	ASSERT_EQUAL(*it, "aaaa");
END_TEST

BEGIN_TEST(checkNotFoundListString)
	std::list<std::string> list = { "aaaa", "bbbb", "cccc"};
	auto it = findRepating(list);

	if(it == std::rend(list)){
		ASSERT_PASS();
	}else{
		ASSERT_FAIL(-1);
	}
END_TEST

BEGIN_TEST(checkSumVec)
	std::vector<int> vec = {1,2,3,4,5,6,9,4,10,6,12};
	auto it = calcSum(vec);

	ASSERT_EQUAL(it, 62);
END_TEST

BEGIN_TEST(checkSumList)
	std::list<int> list = {1,2,3,4,5,6,9,4,10,6,12};
	auto it = calcSum(list);

	ASSERT_EQUAL(it, 62);
END_TEST

BEGIN_TEST(checkSumListString)
	std::list<std::string> list = { "aaaa", "bbbb", "aaaa"};
	auto it = calcSum(list);

	ASSERT_EQUAL(it, "aaaabbbbaaaa");
END_TEST

BEGIN_TEST(checkProdVec)
	std::vector<int> vec = {1,2,3,4,5,6,9,4,10,6,12};
	auto it = prod(vec);

	ASSERT_EQUAL(it, 18662400);
END_TEST

BEGIN_TEST(checkProdList)
	std::list<int> list = {1,2,3,4,5,6,9,4,10,6,12};
	auto it = prod(list);

	ASSERT_EQUAL(it, 18662400);
END_TEST



struct PersonLessByAge {
	bool operator()(Person const& lhs, Person const& rhs) const noexcept { return lhs.m_age < rhs.m_age; }
};

struct PersonLessByAgeAndMass {
	bool operator()(Person const& lhs, Person const& rhs) const noexcept {
		 auto p1 = std::make_pair(lhs.m_age, lhs.m_mass);
		 auto p2 = std::make_pair(rhs.m_age, rhs.m_mass);
		 return p1 < p2;
	}
};

BEGIN_TEST(lets_set_some_persons_test)
	std::vector group = {
		Person("Erez", 82, 30),
		Person("Alex", 94, 34),
		Person("Yarden", 68.4, 23),
		Person("Alex", 94.1, 40),
		Person("Noam", 78.5, 40),
		Person("Mike", 78.5, 40),
	};

	{
		PersonLessByAge c1;
		bool isLess = c1(group[0], group[1]);
		TRACE(isLess);
		isLess = c1(group[1], group[0]);
		TRACE(isLess);

		std::set<Person> klass;
		for(auto const& p : group){
			klass.insert(p);
		}

		ASSERT_EQUAL(klass.size(), group.size());

		for(auto const& p : klass){
			TRACE(p);
		}
	}

	TRACER << "=======================\n";
	{
		//std::set<Person, PersonLessByAge> klass;
		std::set<Person, PersonLessByAgeAndMass> klass;
		for(auto const& p : group){
			klass.insert(p);
		}

		for(auto const& p : klass){
			TRACE(p);
		}
		ASSERT_EQUAL(klass.size(), 5);
	}

	ASSERT_PASS();
END_TEST

BEGIN_TEST(lets_hash_some_persons_test)
	std::vector group = {
		Person("Erez", 82, 30),
		Person("Alex", 94, 34),
		Person("Yarden", 68.4, 23),
		Person("Alex", 94.1, 40),
		Person("Noam", 78.5, 40),
		Person("Mike", 78.5, 40),
	};

	PersonHasher ph;
	auto hv = ph(group[0]);
	TRACE(hv);
	hv = ph(group[1]);
	TRACE(hv);


	std::unordered_set<Person, PersonHasher> set;
	for(auto const& p : group){
			set.insert(p);
	}
	ASSERT_EQUAL(set.size(), 6);

	std::unordered_set<Person> set2;
	for(auto const& p : group){
			set2.insert(p);
	}
	TRACE(set2.size());
END_TEST


template<typename T>
struct IsPointer {
	bool is() const { return false; }
};


template<>
struct IsPointer<Person*> {
	int is() const { return 42; }
};


template<typename T>
struct IsPointer<T*> {
	bool is() const { return true; }
};

BEGIN_TEST(is_ptr_test)
	IsPointer<int> p;

	TRACE(p.is());

	TRACE(IsPointer<Person>{}.is());

	TRACE(IsPointer<Person*>{}.is());

	TRACE(IsPointer<int*>{}.is());
	TRACE(IsPointer<long*>{}.is());
	ASSERT_PASS();

END_TEST


TEST_SUITE("זִיַאדַּתּ אַלגַּום, לַא כַיר פִיהּ")
	TEST(checkVec)
	TEST(checkList)
	TEST(checkListString)
	TEST(checkNotFoundListString)

	TEST(checkSumVec)
	TEST(checkSumList)
	TEST(checkSumListString)

	TEST(checkProdVec)
	TEST(checkProdList)

	TEST(lets_set_some_persons_test)
	TEST(lets_hash_some_persons_test)

	TEST(is_ptr_test)
END_SUITE

