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

#ifndef NATIVE_KERNEL_STRING_URL_HPP
#define NATIVE_KERNEL_STRING_URL_HPP

#include "../Platform.hpp"
#include "../String.hpp"
#include "../Common.hpp"

inline char charFromHex(char ch) {
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

inline char charToHex(char code) {
    static char hex[] = "0123456789abcdef";
    return hex[code & 15];
}

inline char *urlEncode(char *target) {
    char *target_index = target;
    auto result = (char *) calloc((size_t) lengthPointerChar(target) * 3 + 1, sizeof(char));
    char *result_index = result;
    while (*target_index) {
        if (isalnum(*target_index) || *target_index == '-' || *target_index == '_' || *target_index == '.' ||
            *target_index == '~') {
            *result_index++ = *target_index;
        } else if (*target_index == ' ') {
            *result_index++ = '+';
        } else {
            *result_index++ = '%', *result_index++ = charToHex(*target_index >> 4), *result_index++ = charToHex(
                    *target_index & 15);
        }
        target_index++;
    }
    *result_index = '\0';
    return result;
}

inline char *urlDecode(char *target) {
    char *target_index = target;
    auto result = (char *) calloc((size_t) lengthPointerChar(target) + 1, sizeof(char));
    char *result_index = result;
    while (*target_index) {
        if (*target_index == '%') {
            if (target_index[1] && target_index[2]) {
                *result_index++ = charFromHex(target_index[1]) << 4 | charFromHex(target_index[2]);
                target_index += 2;
            }
        } else if (*target_index == '+') {
            *result_index++ = ' ';
        } else {
            *result_index++ = *target_index;
        }
        target_index++;
    }
    *result_index = '\0';
    return result;
}

inline char *findParam(const char *name, char *params) {
    return findParam((char *) name, params);
}

inline char *findParam(char *name, char *params) {
    if (strcmp(params, "") == 0) {
        return strdup("");
    }

    char **query_pairs = stringSplit(params, "&");
    int length_pairs = lengthPointerPointerChar(query_pairs);

#ifdef LINUX
    register
#endif
    int i;
    for (i = 0; i < length_pairs; i++) {
        char **pair = stringSplit(query_pairs[i], "=");
        if (lengthPointerPointerChar(pair) == 2) {
            if (strcmp(pair[0], name) == 0) {
                char *result = strdup(pair[1]);
                freePointerPointerChar(pair);
                freePointerPointerChar(query_pairs);
                return result;
            }
        }
        freePointerPointerChar(pair);
    }

    freePointerPointerChar(query_pairs);
    return strdup("");
}

inline char *findParamFromUrl(const char *name, char *url) {
    return findParam((char*) name, url);
}

inline char *findParamFromUrl(char *name, char *url) {
    char **url_components = stringSplit(url, "?");

    if (lengthPointerPointerChar(url_components) < 2) {
        freePointerPointerChar(url_components);
        return strdup("");
    }

    char *query_url = url_components[1];
    char **query_pairs = stringSplit(query_url, (char *) "&");
    int length_pairs = lengthPointerPointerChar(query_pairs);

#ifdef LINUX
    register
#endif
    int i;
    for (i = 0; i < length_pairs; i++) {
        char **pair = stringSplit(query_pairs[i], (char *) "=");
        if (lengthPointerPointerChar(pair) == 2) {
            if (strcmp(pair[0], name) == 0) {
                char *result = strdup(pair[1]);
                freePointerPointerChar(url_components);
                freePointerPointerChar(query_pairs);
                freePointerPointerChar(pair);

                return result;
            }
        }
        freePointerPointerChar(pair);
    }

    freePointerPointerChar(url_components);
    freePointerPointerChar(query_pairs);

    return strdup("");
}

#endif