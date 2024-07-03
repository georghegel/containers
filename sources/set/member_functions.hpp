#pragma once

#include "../containers.h"

namespace hegel {
template <class T>
set<T>::set(
    std::initializer_list<typename hegel::set<T>::value_type> const& items) {
  for (const auto& elem : items) insert(elem);
}

template <class T>
set<T>::set(const set& s) {
  tree = s.tree;
}

template <class T>
set<T>::~set() {
  clear();
}
}  // namespace hegel