#pragma once

#include <iostream>
#include <type_traits>

inline int half(int x) {
    return x >> 1;
}

inline bool odd(int x) {
    return x & 0x1;
}


template <typename T>
void helper(T arg) {
    std::cout << ", " << arg;
}

template <typename Head, typename ...Tail>
void in(char const* name, Head h, Tail ...t) {
    std::cout << name <<"(" << std::forward<Head>(h);
    (helper(std::forward<Tail>(t)),...);
    std::cout << ")\n";
}

template <typename Result, typename Head, typename ...Tail>
void out(char const* name, Result r, Head h, Tail ...t) {
    std::cout << name <<"(" << std::forward<Head>(h);
    (helper(std::forward<Tail>(t)),...);
    std::cout << ") = " << std::forward<Result>(r) << "\n";
}


template <typename Head, typename ...Tail>
void step(char const* name, Head h, Tail ...t) {
    std::cout << name <<": " << std::forward<Head>(h);
    (helper(std::forward<Tail>(t)),...);
    std::cout << "\n";
}
