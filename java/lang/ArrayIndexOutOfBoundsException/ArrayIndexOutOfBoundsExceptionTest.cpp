/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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

extern "C" {
#include "../../../kernel/test.h"
};

#include "ArrayIndexOutOfBoundsException.hpp"

using namespace Java::Lang;
TEST (JavaLang, ArrayIndexOutOfBoundsExceptionConstructor) {
    // Constructs a new ArrayIndexOutOfBoundsExceptionConstructor with null as its detail message.
    ArrayIndexOutOfBoundsException arrayIndexOutOfBoundsExceptionWithNullMessage;
    ASSERT_STR("", arrayIndexOutOfBoundsExceptionWithNullMessage.getMessage().toString());

    // Constructs a new ArrayIndexOutOfBoundsExceptionConstructor with the specified detail message.
    ArrayIndexOutOfBoundsException arrayIndexOutOfBoundsExceptionWithMessage = ArrayIndexOutOfBoundsException("ArrayIndexOutOfBoundsException with the specified message");
    ASSERT_STR("ArrayIndexOutOfBoundsException with the specified message", arrayIndexOutOfBoundsExceptionWithMessage.getMessage().toString());

    // Constructs a new ArrayIndexOutOfBoundsException class with an argument indicating the illegal index.
    ArrayIndexOutOfBoundsException arrayIndexOutOfBoundsExceptionWithIllegalIndex = ArrayIndexOutOfBoundsException(999);
    ASSERT_STR("String index out of range: 999", arrayIndexOutOfBoundsExceptionWithIllegalIndex.getMessage().toString());
}

TEST(JavaLang, ArrayIndexOutOfBoundsExceptionTryCatch) {
    try {
        throw ArrayIndexOutOfBoundsException("Throw ArrayIndexOutOfBoundsException");
    } catch (ArrayIndexOutOfBoundsException &e) {
        ASSERT_STR("Throw ArrayIndexOutOfBoundsException", e.getMessage().toString());
    }
}
