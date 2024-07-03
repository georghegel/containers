#pragma once

#include "../containers.h"

namespace hegel {
template <class Key, class T>
bool map<Key, T>::empty() {
  return tree.empty();
}

template <class Key, class T>
typename map<Key, T>::size_type map<Key, T>::size() {
  return tree.size();
}

template <class Key, class T>
typename map<Key, T>::size_type map<Key, T>::max_size() {
  return tree.max_size();
}
}  // namespace hegel