#pragma once

#include "../containers.h"

namespace hegel {
template <class Key>
typename hegel::set<Key>::iterator hegel::set<Key>::begin() {
  return tree.RedBlackTree<Key>::begin();
}

template <class Key>
typename hegel::set<Key>::iterator hegel::set<Key>::end() {
  return tree.RedBlackTree<Key>::end();
}

template <class Key>
typename hegel::set<Key>::const_iterator hegel::set<Key>::cbegin() const {
  return tree.RedBlackTree<Key>::cbegin();
}

template <class Key>
typename hegel::set<Key>::const_iterator hegel::set<Key>::cend() const {
  return tree.RedBlackTree<Key>::cend();
}
}  // namespace hegel