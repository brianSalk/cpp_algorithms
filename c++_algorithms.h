#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <concepts>
template <typename It, typename std::iterator_traits<It>::pointer=nullptr>
void n_partition(It beg, It end, std::initializer_list<std::function<bool(typename It::value_type)>> const& i_list) {
	auto curr_pos = beg;
	for (auto const& condition : i_list) {
		for (auto it = curr_pos; it != end; ++it) {
			if (condition(*it)) {
				auto temp = *it;
				*it = *curr_pos;
				*curr_pos = temp;
				++curr_pos;
			}
		}
	}
}
