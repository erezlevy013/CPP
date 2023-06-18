#include <unordered_set>

#include "../Iter.hpp"

namespace h72 {

template<typename Iter>
Iter findRepating(Iter a_rbegin, Iter a_rend)
{
    using T = typename Iter::value_type;
    //std::unordered_set<T, hash<T>> dict;
    std::unordered_set<T> dict;
    Iter temp = a_rend;
    while( a_rbegin != a_rend){
        if(dict.count(*a_rbegin) == 0){
            dict.insert(*a_rbegin);
        }else{
            temp = a_rbegin;
        }
        ++a_rbegin;
    }
    return temp;
}

template<typename Container>
auto findRepating(Container const& a_contain)
{
        return findRepating(std::rbegin(a_contain), std::rend(a_contain));
}

template<typename Iter>
auto calcSum(Iter a_begin, Iter a_end)
{
    auto sum = *a_begin;
    ++a_begin;
    while( a_begin != a_end){
        sum += *a_begin;
        ++a_begin;
    }
    return sum;
}

template<typename Container>
auto calcSum(Container const& a_contain)
{
    return calcSum(std::begin(a_contain), std::end(a_contain));
}

template<typename Iter>
auto prod(Iter a_begin, Iter a_end)
{
    auto sum = *a_begin;
    ++a_begin;
    while( a_begin != a_end){
        sum *= *a_begin;
        ++a_begin;
    }
    return sum;
}

template<typename Container>
auto prod(Container const& a_contain)
{
    return prod(std::begin(a_contain), std::end(a_contain));
}


}
