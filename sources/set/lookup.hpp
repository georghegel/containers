#pragma once

#include "../containers.h"

namespace hegel {
template <class Key>
bool hegel::set<Key>::contains(const Key &key) {
  if (tree.search(tree.getRoot(), key) != NIL) return true;
  return false;
}
}  // namespace hegel