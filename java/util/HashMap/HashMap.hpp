/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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

#ifndef NATIVE_JAVA_UTIL_HASH_MAP_HPP
#define NATIVE_JAVA_UTIL_HASH_MAP_HPP

#include "../../Lang.hpp"

namespace Java {
    namespace Util {
        template <typename K, typename V>
        class HashMap {
        private:
            std::map<K, V> hashMap;
        public:
            HashMap();
            ~HashMap();

            V get(K key);
            void put(K key, V value);
            boolean putAll(HashMap<K, V> map); //TODO: implement this later
            boolean containsKey(K key);
            boolean containsValue(V value);

            void clear();
            boolean remove(K key);
            boolean remove(K key, V value);
            void removeAll();

            boolean isEmpty();
            int size();
        };

        template<typename K, typename V>
        HashMap<K, V>::HashMap() {
        };

        template<typename K, typename V>
        HashMap<K, V>::~HashMap() {
        }

        template<typename K, typename V>
        V HashMap<K, V>::get(K key) {
            V value = hashMap[key];
            return value;
        }

        template<typename K, typename V>
        void HashMap<K, V>::put(K key, V value) {
            hashMap.insert(std::make_pair(key, value));
        }

        template<typename K, typename V>
        boolean HashMap<K,V>::containsKey(K key) {
            if (NULL != hashMap[key]) {
                return true;
            }
            return false;
        }

        template<typename K, typename V>
        boolean HashMap<K,V>::containsValue(V value) {
            for (auto const &ent1 : hashMap) {
                if (ent1.second == value) {
                    return true;
                }
            }
            return false;
        }

        template<typename K, typename V>
        void HashMap<K,V>::clear() {
            hashMap.clear();
        }

        template<typename K, typename V>
        boolean HashMap<K,V>::remove(K key) {
            if (NULL != hashMap[key]) {
                hashMap.erase(key);
                return true;
            }

            return false;
        }

        template<typename K, typename V>
        boolean HashMap<K,V>::remove(K key, V value) {
            if (NULL != hashMap[key] && value == hashMap[key]) {
                hashMap.erase(key);
                return true;
            }

            return false;
        }

        template<typename K, typename V>
        void HashMap<K,V>::removeAll() {
            hashMap.clear();
        }

        template<typename K, typename V>
        boolean HashMap<K,V>::isEmpty() {
            return (hashMap.size() == 0);
        }

        template<typename K, typename V>
        int HashMap<K,V>::size() {
            return hashMap.size();
        }


    }
}

#endif//NATIVE_JAVA_UTIL_HASH_MAP_HPP
