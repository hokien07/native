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

extern "C" {
#include "../../../kernel/test.h"
};

#include "../ClassCastException/ClassCastException.hpp"

using namespace Java::Lang;

TEST (JavaLang, ClassCastExceptionConstructor) {
// Constructs a new ClassCastException with null as its detail message.
	ClassCastException classCastExceptionWithNullMessage;
	ASSERT_STR("", classCastExceptionWithNullMessage.getMessage().toString());

// Constructs a new ClassCastException with the specified detail message.
	ClassCastException classCastExceptionWithMessage = ClassCastException("ClassCastException with the specified message");
	ASSERT_STR("ClassCastException with the specified message", classCastExceptionWithMessage.getMessage().toString());
}

TEST (JavaLang, ClassCastExceptionTryCatch) {
	try {
		throw ClassCastException("Throw ClassCastException");
	}
	catch (ClassCastException ex) {
		ASSERT_STR("Throw ClassCastException", ex.getMessage().toString());
	}
}
