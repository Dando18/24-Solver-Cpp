//
// Created by Daniel Nichols on 7/17/17.
//

#ifndef INC_24_SOLVER_UTILITIES_HPP
#define INC_24_SOLVER_UTILITIES_HPP

#include "stddef.h"
#include <array>
#include <map>
#include <vector>

template<size_t N, class T>
std::array<T, N> make_array(const T &v) {
    std::array<T,N> arr;
    arr.fill(v);
    return arr;
};

template<class T, class K>
std::map<T,K> flip_map(const std::map<K,T> &m) {
    std::map<T,K> flipped;
    for (auto i=m.begin(); i!=m.end(); ++i)
        flipped[i->second] = i->first;
    return flipped;
};

template<class T, class K>
std::vector<T> map_values(const std::map<K,T> &m) {
    std::vector<T> v;
    for(auto it = m.begin(); it != m.end(); ++it) {
        v.push_back(it->second);
    }
    return v;
};

template<class T, class K>
std::vector<K> map_keys(const std::map<K,T> &m) {
    std::vector<K> v;
    for(auto it = m.begin(); it != m.end(); ++it) {
        v.push_back(it->first);
    }
    return v;
};

#endif //INC_24_SOLVER_UTILITIES_HPP


