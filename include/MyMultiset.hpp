//
// Created by 53915 on 04/12/2017.
//

#ifndef GOMOKU_MYMULTISET_HPP
#define GOMOKU_MYMULTISET_HPP

#include <set>
#include <utility>

template<class T, class U>
class MyMultiset {
public :
    using compareFunc = bool (*)(std::pair<T, U>, std::pair<T, U>);
    MyMultiset(const compareFunc *func) : std::multiset<std::pair<T, U>, compareFunc>(*func) {}

    U operator[](T key) {
        for (auto it = m_multiset.begin(); it != m_multiset.end(); it++)
            if (it->first == key)
                return it->second;
    }

    void addInList(T key, U value) {
        m_multiset.insert(std::make_pair<T, U>(key, value));
    }

    void erase(T key) {
        for (auto it = m_multiset.begin(); it != m_multiset.end(); it++) {
            if (it->first == key)
                m_multiset.erase(it);
        }
    }

    Game::Pos getFirst() {
        return *(m_multiset.begin())->first;
    }
private:
    std::multiset<std::pair<T, U>, bool *(std::pair<T, U>, std::pair<T, U>)> m_multiset;
};

#endif //GOMOKU_MYMULTISET_HPP
