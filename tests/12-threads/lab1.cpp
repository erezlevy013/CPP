#include "mu_test.h"

#include <string>
#include <climits>
#include <iostream>
#include <thread>
#include <mutex>
#include <iterator>
#include <vector>
#include <cmath>

std::mutex key;
double sum;


double CheckCalcSum(std::vector<int> a_vec)
{
    double sum = 0;
    for(auto& ptr : a_vec){
        if(ptr != 0){
            sum += std::sin(ptr) / (ptr) + std::pow(ptr, 3.5);     
        }
    }
    return sum;
}
void CalcSum(std::vector<int>::iterator a_begin, std::vector<int>::iterator a_end)
{
    for(auto ptr = a_begin; ptr < a_end; ++ptr){
        key.lock();
            if(*ptr != 0){
                sum += std::sin(*ptr) / (*ptr) + std::pow(*ptr, 3.5);     
            }
        key.unlock();
    }
}

BEGIN_TEST(thread)
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    std::thread t1{CalcSum, vec.begin(), vec.begin() + vec.size()/4 };
    std::thread t2{CalcSum, vec.begin() + vec.size()/4 , vec.begin() + vec.size()/2};
    std::thread t3{CalcSum, vec.begin() + vec.size()/2 , vec.begin() + vec.size()*(0.75)};
    std::thread t4{CalcSum, vec.begin() + vec.size()*(0.75), vec.end()};

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout<<sum<<" == "<<CheckCalcSum(vec)<<std::endl;
    ASSERT_PASS();

END_TEST

TEST_SUITE("זִיַאדַּתּ אַלגַּום, לַא כַיר פִיהּ")
    TEST(thread)
END_SUITE

 




