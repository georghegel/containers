#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include "../RedBlackTree/RedBlackTree.hpp"

namespace s21 {
  template <typename Key> class set : public RedBlackTree<Key> {
      private:
        RedBlackTree<Key> tree{};

      public:
        using key_type = Key;
        using value_type = Key;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = std::size_t;
//        using iterator = iterator<std::bidirectional_iterator_tag>;

        class iterator {
        private:
            typename RedBlackTree<value_type>::Node* nodeptr;

        public:
            explicit iterator(typename RedBlackTree<value_type>::Node* ptr = nullptr) : nodeptr(ptr){}
            value_type& operator*() const {
                return nodeptr->key;
            }
            value_type* operator->() const {
                return &nodeptr->key;
            }
            iterator& operator++() {
                nodeptr = tree.successor(nodeptr);
                return *this;
            }
            iterator operator++(int) {
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            bool operator==(const iterator& other) {
                return nodeptr == other.nodeptr;
            }
            bool operator!=(const iterator& other) {
                return *this != other;
            }
            iterator& begin() {
                return iterator(tree.minimum);
            }
            iterator& end() {
                return iterator(tree.TNIL);
            }
        };

      public:
        set() = default;
        set(std::initializer_list<value_type> const &items) {
            for (const auto& elem: items)
                this->insert_value(elem);
        }

        //COPY CONSTRUCTOR
        set(const set &s) {

        }

        // MOVE CONSTURCTOR
        set(const set &&s) noexcept {
            tree = s.tree;
            s.tree = nullptr; // actually implement TNILler method
        }

//        ~set() = default;

        // MOVE ASSIGNMENT
        s21::set<value_type>& operator=(s21::set<value_type> &&s) noexcept {
            this->tree = s.tree;
            s.tree = nullptr;
            return *this;
        }

        bool empty();
        size_type size();
        size_type max_size();

        void clear();
//        std::pair<iterator, bool> insert(const value_type& value);
        void erase(iterator pos);
        void swap(set& other);
        void merge(set& other);

//        iterator find(const Key& key);
        bool contains(const Key& key);

//        std::pair<iterator, bool> insert(const value_type& value) {
//            auto a = new Node<value_type>;
//            a->key = value;
//            auto [node, inserted] = tree.insert(a);
//            return {iterator(node), inserted};
//        }

        void insert_value(const value_type& value);
    };

};










