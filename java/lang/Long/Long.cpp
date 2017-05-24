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

#include "Long.hpp"

using namespace Java::Lang;

/**
 * Integer initialization
 *
 * @param original
 */
Long::Long() {
    this->original = 0;  
}

/**
 * Integer initialization
 *
 * @param original
 */
Long::Long(long original) {
   this->original = original;
}

/**
 * Integer initialization
 *
 * @param original
 */ 
Long::Long(const Long &longnumber) {
    this->original = longnumber.original;
}

Long::~Long() {
}

/**
 * Parse integer
 *
 * @param target
 * @return Integer
 */
Long *Long::parseLong(String target) {
    return new Long(string_to_long(target.toCharArray()));
}

/**
 * Integer to String
 *
 * @return String
 */
String Long::toString() const  {
    return string_from_long(this->original);
}

/**
 * Integer to Char
 *
 * @return char
 */
char Long::charValue() const {
    return string_to_char(string_from_long(this->original));
}

/**
 * Integer to String
 *
 * @return CString
 */
string Long::stringValue() const  {
    return String::valueOf(this->original).toCharArray();
}

/**
 * Short value of Integer
 *
 * @return short
 */
short Long::shortValue() const  {
    return this->original;
}

/**
 * Integer value
 *
 * @return int
 */
int Long::intValue() const  {
    return this->original;
}

/**
 * Integer value in Long
 *
 * @return int
 */
long Long::longValue() const  {
    return this->original;
}

/**
 * Integer value in float
 *
 * @return int
 */
float Long::floatValue() const  {
    return (float) this->original;
}

/**
 * Integer value in double
 *
 * @return int
 */
double Long::doubleValue() const  {
    return (double) this->original;
}