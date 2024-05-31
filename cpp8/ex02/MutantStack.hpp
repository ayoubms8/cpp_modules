#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return std::stack<T>::c.begin();
    }

    iterator end() {
        return std::stack<T>::c.end();
    }

    iterator rbegin() {
        return std::stack<T>::c.rbegin();
    }

    iterator rend() {
        return std::stack<T>::c.rend();
    }
};
