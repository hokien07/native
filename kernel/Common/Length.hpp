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

#ifndef NATIVE_COMMON_LENGTH_HPP
#define NATIVE_COMMON_LENGTH_HPP

#define P_LEN(NAME, TYPE); \
inline int lengthPointer##NAME(TYPE *target) {\
    if (target == nullptr) return 0;\
    register TYPE*pointer;\
    for (pointer = target; *pointer; ++pointer);\
    return pointer - target;\
}

// Length of pointer pointer
#define P_P_LEN(NAME, TYPE); \
inline int lengthPointerPointer##NAME(TYPE **target) {\
    if (target == nullptr) return 0;\
    register TYPE**pointer;\
    for (pointer = target; *pointer; ++pointer);\
    return pointer - target;\
}

P_LEN(Char, char);
P_LEN(Char, const char);
P_P_LEN(Char, char);

/**
 * Is string empty ?
 *
 * @param input
 * @return TRUE or FALSE
 */
inline bool isEmptyString(const char *input) {
	return lengthPointerChar(input) == 0;
}

#endif