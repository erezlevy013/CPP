#ifndef ITER_HPP
#define ITER_HPP

#include <vector>
#include <list>
#include <algorithm>

namespace h72 {

template<typename Iter>
Iter findRepating(Iter a_rbegin, Iter a_rend);

template<typename Container>
auto findRepating(Container const& a_contain);

template<typename Iter>
auto calcSum(Iter a_begin, Iter a_end);

template<typename Container>
auto calcSum(Container const& a_contain);

template<typename Iter>
auto prod(Iter a_begin, Iter a_end);

template<typename Container>
auto prod(Container const& a_contain);

} // namespace h72

#include "detail/Iter_inl.hxx"

#endif //ITER_HPP
