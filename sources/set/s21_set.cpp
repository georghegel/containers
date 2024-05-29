#include "s21_set.hpp"

template <class Key>
bool s21::set<Key>::empty() {

}

template <class Key>
std::size_t s21::set<Key>::size() {

}

template <class Key>
std::size_t s21::set<Key>::max_size() {

}

template <class Key>
void s21::set<Key>::insert_value(const Key& value) {
    tree.insert(value);
}

template <class Key>
void s21::set<Key>::clear() {

}

//template <class Key>
//std::pair<typename s21::set<Key>::iterator, bool> insert(const Key& value) {
//
//}

template <class Key>
void s21::set<Key>::erase(iterator pos) {

}

template <class Key>
void s21::set<Key>::swap(s21::set<Key>& other) {

}

template <class Key>
void s21::set<Key>::merge(s21::set<Key>& other) {

}
//
//template <class Key>
//typename s21::set<Key>::iterator find(const Key& key) {
//
//}

template <class Key>
bool s21::set<Key>::contains(const Key& key) {

}

int main() {

    s21::set<int> a;
//    a.insert();

//    s21::set<int>::iterator s = a.begin();

    for (int i = 1; i < 14; ++i)
        a.insert_value(i);

//    auto l = std::move(a);

    return 0;
}