//
// Created by 53915 on 04/12/2017.
//

#ifndef GOMOKU_MYMULTISET_HPP
#define GOMOKU_MYMULTISET_HPP

#include <iostream>
#include <set>
#include <utility>

template<class T, class U>
class MyMultiset {
public :
    using compareFunc = bool (*)(std::pair<T, U>, std::pair<T, U>);
    //MyMultiset(const compareFunc func) : std::multiset<std::pair<T, U>, compareFunc>(func) {}
    MyMultiset(const std::multiset<std::pair<T, U>, compareFunc> &&multiset) : m_multiset(multiset) {}

    U operator[](T key) {
        for (auto it = m_multiset.begin(); it != m_multiset.end(); it++)
            if (it->first == key)
                return it->second;
    }

    void addInList(T key, U value) {
        m_multiset.insert(std::pair<T, U>(key, value));
    }

    void erase(T key) {
        for (auto it = m_multiset.begin(); it != m_multiset.end(); it++) {
            if (key == it->first) {
                m_multiset.erase(it);
                break ;
            }
        }
    }

    const Game::Pos &getFirst() const {
        return (m_multiset.begin())->first;
    }

    const Game::Pos &getLast() const {
        return (m_multiset.end()->first);
    }

    void removeAll() {
        while (!m_multiset.empty())
            m_multiset.erase(*m_multiset.begin());
    }

    void print() {
        for (auto it = m_multiset.begin(); it != m_multiset.end(); it++)
            std::cerr << it->first << " -> " << it->second << std::endl;
    }
private:
    std::multiset<std::pair<T, U>, compareFunc> m_multiset;
};

#endif //GOMOKU_MYMULTISET_HPP
