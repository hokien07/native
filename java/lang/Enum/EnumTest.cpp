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
}

#include "Enum.hpp"

using namespace Java::Lang;

TEST (JavaLang, EnumGetName) {
	// Given valid enum and name to test getName()
	Enum<int> validEnum = Enum<int>("validName", 7);
	
	String expectedValue = "validName";
	ASSERT_STR(expectedValue.toString(), validEnum.getName().toString());
}

TEST (JavaLang, EnumGetOrdinal) {
	// Given valid enum and name to test getOrdinal()
	Enum<int> validEnum = Enum<int>("validName", 18);
	
	int expectedValue = 18;
	ASSERT_EQUAL(expectedValue, validEnum.getOrdinal());
}

TEST (JavaLang, EnumToString) {
	// Given valid enum and name to test getOrdinal()
	Enum<int> validEnum = Enum<int>("validName", 18);

	ASSERT_STR("18", validEnum.toString());
}