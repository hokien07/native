/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef JAVA_UTIL_HASH_MAP_EX_HPP
#define JAVA_UTIL_HASH_MAP_EX_HPP

#include "../../Lang.hpp"
#include "../Collection/Collection.hpp"

namespace Java {
    namespace Util {
        template <typename E>
        class Set
        {
        public:
            virtual int size() const = 0;
            virtual boolean isEmpty() const = 0;
            virtual boolean contains(const E &target) const = 0;
//          virtual Iterator<E> iterator() const = 0;
            virtual Array<E> toArray() const = 0;
//          virtual Array<E> toArray(const Array<E> &anArray) const = 0;
            virtual boolean add(const E &target) = 0;
            virtual boolean remove(const E &target) = 0;
            virtual boolean containsAll(const Collection<E> &target) const = 0;
            virtual boolean addAll(const Collection<E> &target) = 0;
            virtual boolean retainAll(const Collection<E> &target) = 0;
            virtual boolean removeAll(const Collection<E> &target) = 0;
            virtual void clear() = 0;
            virtual boolean equals(const Object &target) = 0;
            virtual int hashCode() const = 0;
//          virtual Spliterator<E> spliterator() const = 0;
        };

        template <typename E>
        class AbstractSet : public Set<E>
        {

        };

        template <typename K, typename V>
        class Map
        {
        public:
            int size() const = 0;
            virtual boolean isEmpty() const = 0;
            virtual boolean containsKey(const K &key) const = 0;
            virtual boolean containsValue(const V &value) const = 0;
            virtual V get(const K &key) const = 0;
            virtual V put(const K &key, const V &value) = 0;
            virtual V remove(const K &key) = 0;
            virtual void putAll(const Map<K, V> &map) = 0;
            virtual void clear() = 0;
            virtual Set<K> keySet() const = 0;
            virtual Collection<V> &values() const = 0;

            template <typename K, typename V>
            class Entry {
                virtual K getKey() const = 0;
                virtual V getValue() const = 0;
                virtual V setValue() = 0;
                virtual boolean equals(const Object &target) const = 0;
                virtual int hashCode() const = 0;
            };
        };

        template <typename K, typename V>
        class AbstractMap : public Map<K, V>
        {

        };

        template <typename K, typename V>
        class HashMap : public AbstractMap
        {
        public:
            static int DEFAULT_INITIAL_CAPACITY = 16;
            static int MAXIMUM_CAPACITY = 1073741824;
            static float DEFAULT_LOAD_FACTOR = 0.75f;
            static int TREEIFY_THRESHOLD = 8;
            static int UNTREEIFY_THRESHOLD = 6;
            static int MIN_TREEIFY_CAPACITY = 64;

            template <K, V>
            class Node : public Map::Entry<K, V>
            {
            private:
                int hash;
                K key;
                V value;
                Node<K, V> *next;
            public:
                Node(int hash, const K &key, const V &value, const Node<K, V> *next) {
                    this->hash = hash;
                    this->key = key;
                    this->value = value;
                    this->next = next;
                }

                virtual ~Node() { }

                K getKey() const {
                    return this->key;
                }

                V getValue() const {
                    return this->value;
                }

                String toString() const {
                    String result = key + "=" + value;
                }

                int hashCode() const {
                    return (intptr_t)std::addressof(&key) ^ (intptr_t)std::addressof(&value);
                }

                V setValue(const V &newValue) {
                    V oldValue = this->value;
                    this->value = newValue;
                    return oldValue;
                }

                boolean equals(const Object &target) const {

                }
            };

            template <K, V>
            class EntrySet : public AbstractSet<Map::Entry<K, V>>
            {

            };

        private:
            Node<K, V> *table = NULL;
            Set<Map<K, V>> *entrySet = NULL;
            int size = 0;
            int modCount = 0;
            int threshold = 0;
            float loadFactor = 0.0f;

        private:
            int tableSizeFor(int capacity) const {
                unsigned int n = cap - 1;
                n |= n >> 1;
                n |= n >> 2;
                n |= n >> 4;
                n |= n >> 8;
                n |= n >> 16;

                if (n < 0) {
                    return 1;
                }
                else {
                    if ( n >= MAXIMUM_CAPACITY) {
                        return MAXIMUM_CAPACITY;
                    }
                    else {
                        return n + 1;
                    }
                }

                // TODO: Change name of variables.
            }

        public:
            HashMap(int initialCapacity, float loadFactor) {
                if (initialCapacity < 0) {
                    throw "";
                    // TODO: throw IllegalArgumentException.
                }
                if (initialCapacity > MAXIMUM_CAPACITY) {
                    initialCapacity = MAXIMUM_CAPACITY;
                }
                if (loadFactor <= 0 || Double::isNan((double)loadFactor)) {
                    throw "";
                    // TODO: throw IllegalArgumentException.
                }
                this->loadFactor = loadFactor;
                this->threshold = this->tableSizeFor(initialCapacity);
            }

            HashMap(int initialCapacity) : HashMap(initialCapacity, DEFAULT_LOAD_FACTOR) {

            }

            HashMap() : HashMap(DEFAULT_INITIAL_CAPACITY, DEFAULT_LOAD_FACTOR) {

            }

            HashMap(const Map<K, V> &target) {
                // TODO
            }

            int size() const {
                return this->size;
            }

            boolean isEmpty() const {
                if (this->size != 0) {
                    return false;
                }
                return true;
            }

            V get(const K &key) const {
                Node<K, V> node;
            }
        };
    }
}

#endif // JAVA_UTIL_HASH_MAP_EX_HPP
