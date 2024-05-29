#pragma once

#include <iostream>
#include <memory>

#define RED 1
#define BLACK 0
#define NIL nullptr

template <class T>
struct Node {
  T key;
  bool color = BLACK;
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;
};
static int lol = 0;
template <class T>
using NodePtr = Node<T> *;

template <typename T>
class RedBlackTree {
 private:
  NodePtr<T> root;
  NodePtr<T> TNIL;

//  void initializeNULLNode(NodePtr<T> node, NodePtr<T> parent) {
//        node->key = 0;
//        node->parent = parent;
//        node->left = nullptr;
//        node->right = nullptr;
//        node->color = 0;
//  }

  RedBlackTree<T> insert_fixup(NodePtr<T> node) {
    while (node->parent->color == RED) {
      if (node->parent == node->parent->parent->left) {
        auto y = node->parent->parent->right;
        if (y->color == RED) {                              // uncle is RED
          node->parent->color = BLACK;
          y->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
        } else {
            if (node == node->parent->right) {
                node = node->parent;
                this->left_rotate(node);
            }
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            this->right_rotate(node->parent->parent);
            }
      } else {
          auto y = node->parent->parent->left;
          if (y->color == RED) {
              node->parent->color = BLACK;
              y->color = BLACK;
              node->parent->parent->color = RED;
              node = node->parent->parent;
          } else {
              if (node == node->parent->left) {
                  node = node->parent;
                  this->right_rotate(node);
              }
              node->parent->color = BLACK;
              node->parent->parent->color = RED;
              this->left_rotate(node->parent->parent);
          }
      }
    }
    root->color = BLACK;
    return *this;
  }
  void delete_fixup(NodePtr<T> node) {
    while (node != TNIL && node->color == BLACK) {
      if (node == node->parent->left) {
        auto w = node->parent->right;
        if (w->color == RED) {
          w->color = BLACK;
          node->parent->color = RED;
          this->left_rotate(node->parent);
          w = node->parent->right;
        }
        if (w->left->color == BLACK && w->right->color == BLACK) {
          w->color = RED;
          node = node->parent;
        } else if (w->right->color == BLACK) {
          w->left->color = BLACK;
          w->color = RED;
          this->right_rotate(w);
          w = node->parent->right;
          w->color = node->parent->color;
          node->parent->color = BLACK;
          w->right->color = BLACK;
          this->left_rotate(node->parent);
          node = root;
        }
      } else {
        auto w = node->parent->left;
        if (w->color == RED) {
          w->color = BLACK;
          node->parent->color = RED;
          this->right_rotate(node->parent);
          w = node->parent->left;
        }
        if (w->right->color == BLACK && w->left->color == BLACK) {
          w->color = RED;
          node = node->parent;
        } else if (w->left->color == BLACK) {
          w->right->color = BLACK;
          w->color = RED;
          this->left_rotate(w);
          w = node->parent->left;
          w->color = node->parent->color;
          node->parent->color = BLACK;
          w->left->color = BLACK;
          this->right_rotate(node->parent);
          node = root;
        }
      }
    }
    node->color = BLACK;
  }
  void delete_node(NodePtr<T> node) {
      auto y = node;
      auto x = node;
      bool y_orig_color = y->color;
      if (node->left == TNIL) {
          x = node->right;
          this->transplant(node, node->right);
      } else if (node->right == TNIL) {
          x = node->left;
          this->transplant(node, node->left);
      } else {
          y = minimum(node->right);
          y_orig_color = y->color;
          x = y->right;
          if (y->parent == node)
              x->parent = y;
          else {
              this->transplant(y, y->right);
              y->right = node->right;
              y->right->parent = y;
          }
          this->transplant(node, y);
          y->left = node->left;
          y->left->parent = y;
          y->color = node->color;
      }
      if (y_orig_color == BLACK) this->delete_fixup(x);
  }
  void transplant(NodePtr<T> u, NodePtr<T> v) {
      if (u->parent == TNIL)
          root = v;
      else if (u == u->parent->left)
          u->parent->left = v;
      else
          u->parent->right = v;
      v->parent = u->parent;
  }

  void inorderHelper(NodePtr<T> node) {
    if (node != TNIL) {
        inorderHelper(node->left);
      std::cout << node->key << std::endl;
        inorderHelper(node->right);
    }
  }

  NodePtr<T> searchTree(NodePtr<T> node, const T &key) {
    if (node == TNIL || key == node->key) return node;
    if (key < node->key) return searchTree(node->left, key);
    return searchTree(node->right, key);
  }

 public:
  RedBlackTree() {
    TNIL = new Node<T>;
    TNIL->color = BLACK;
    TNIL->left = NIL;
    TNIL->right = NIL;
    root = TNIL;
  }

//  ~RedBlackTree() {
//
//  }

  void insert(const T& key) {
      auto node = new Node<T>;
      node->key = key;
      node->parent = nullptr;
      node->left = TNIL;
      node->right = TNIL;
      node->color = RED;

      auto y = TNIL;
      auto x = root;

      while (x != TNIL) {
          y = x;
          if (node->key < x->key)
              x = x->left;
          else
              x = x->right;
      }
      node->parent = y;
      if (y == TNIL)
          root = node;
      else if (node->key < y->key)
          y->left = node;
      else
          y->right = node;
      node->left = TNIL;
      node->right = TNIL;
      node->color = RED;
      this->insert_fixup(node);
  }
  void left_rotate(NodePtr<T> node) {
      auto y = node->right;
      node->right = y->left;

      if (y->left != TNIL) y->left->parent = node;
      y->parent = node->parent;
      if (node->parent == TNIL)
          root = y;
      else if (node == node->parent->left)
          node->parent->left = y;
      else
          node->parent->right = y;
      y->left = node;
      node->parent = y;
  }
  void right_rotate(NodePtr<T> node) {
      auto y = node->left;
      node->left = y->right;

      if (y->right != TNIL) y->right->parent = node;
      y->parent = node->parent;
      if (node->parent == TNIL)
          root = y;
      else if (node == node->parent->right)
          node->parent->right = y;
      else
          node->parent->left = y;
      y->right = node;
      node->parent = y;
  }

  void inorder() { inorderHelper(root); }

  NodePtr<T> search(const T &key) {
    NodePtr<T> new_root = root;
    new_root = searchTree(new_root, key);
    return new_root;
  }
  NodePtr<T> minimum(NodePtr<T> node) {
      while (node->left != TNIL) node = node->left;
      return node;
  }
  NodePtr<T> maximum(NodePtr<T> node) {
      while (node->right != TNIL) node = node->right;
      return node;
  }

  NodePtr<T> successor(NodePtr<T> node);
  NodePtr<T> predecessor(NodePtr<T> node);

  NodePtr<T> getRoot() {
      return root;
  }
  NodePtr<T> getTNIL (){
      return TNIL;
  }
  void deleteNode(const T& key) {
      auto node = search(key);
    if (node != TNIL) {
        delete_node(node);
    }
  }
};
