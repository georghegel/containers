#include "RedBlackTree.hpp"
#include "../set/s21_set.hpp"

template <class T>
NodePtr<T> RedBlackTree<T>::successor(NodePtr<T> node) {
  if (node->right != TNIL) return minimum(node->right);
  auto y = node->parent;
  while (y != TNIL && node == y->right) {
    node = y;
    y = y->parent;
  }
  return y;
}

template <class T>
NodePtr<T> RedBlackTree<T>::predecessor(NodePtr<T> node) {
  if (node->left != TNIL) return minimum(node->left);
  auto y = node->parent;
  while (y != TNIL && node == y->left) {
    node = y;
    y = y->parent;
  }
  return y;
}

//int main() {
//  RedBlackTree<int> tree{};
//
//    tree.insert(1);
//    tree.insert(2);
//    tree.insert(3);
//    tree.insert(4);
//    std::cout << tree.getRoot()->key << std::endl;
//    tree.deleteNode(1);
////    tree.deleteNode(b);
////    tree.deleteNode(c);
////    tree.deleteNode(d);
////    delete a;
////    delete b;
////    delete c;
////    delete d;
//
//  return 0;
//}
