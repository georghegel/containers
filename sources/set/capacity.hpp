#pragma once

#include "../containers.h"

namespace hegel {
template <class Key>
bool hegel::set<Key>::empty() {
  return tree.empty();
}

template <class Key>
std::size_t hegel::set<Key>::size() {
  return tree.size();
}

template <class Key>
typename set<Key>::size_type set<Key>::max_size() {
  return set<Key>::tree.max_size();
}
}  // namespace hegel