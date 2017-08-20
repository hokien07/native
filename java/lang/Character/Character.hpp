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

#ifndef NATIVE_JAVA_LANG_CHARACTER_HPP_
#define NATIVE_JAVA_LANG_CHARACTER_HPP_

#include "../CharSequence/CharSequence.hpp"

namespace Java {
    namespace Lang {
        class Character : public Object {
        public:
            static const int MIN_RADIX = 2;
            static const int MAX_RADIX = 36;
            static const char16_t MIN_VALUE = u'\u0000';
            static const char16_t MAX_VALUE = u'\uFFFF';
            static const byte UNASSIGNED = 0;
            static const byte UPPERCASE_LETTER = 1;
            static const byte LOWERCASE_LETTER = 2;
            static const byte TITLECASE_LETTER = 3;
            static const byte MODIFIER_LETTER = 4;
            static const byte OTHER_LETTER = 5;
            static const byte NON_SPACING_MARK = 6;
            static const byte ENCLOSING_MARK = 7;
            static const byte COMBINING_SPACING_MARK = 8;
            static const byte DECIMAL_DIGIT_NUMBER = 9;
            static const byte LETTER_NUMBER = 10;
            static const byte OTHER_NUMBER = 11;
            static const byte SPACE_SEPARATOR = 12;
            static const byte LINE_SEPARATOR = 13;
            static const byte PARAGRAPH_SEPARATOR = 14;
            static const byte CONTROL = 15;
            static const byte FORMAT = 16;
            static const byte PRIVATE_USE = 18;
            static const byte SURROGATE = 19;
            static const byte DASH_PUNCTUATION = 20;
            static const byte START_PUNCTUATION = 21;
            static const byte END_PUNCTUATION = 22;
            static const byte CONNECTOR_PUNCTUATION = 23;
            static const byte OTHER_PUNCTUATION = 24;
            static const byte MATH_SYMBOL = 25;
            static const byte CURRENCY_SYMBOL = 26;
            static const byte MODIFIER_SYMBOL = 27;
            static const byte OTHER_SYMBOL = 28;
            static const byte INITIAL_QUOTE_PUNCTUATION = 29;
            static const byte FINAL_QUOTE_PUNCTUATION = 30;
            static const int ERROR = 0xFFFFFFFF;
            static const char DIRECTIONALITY_UNDEFINED = -1;
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT = 0;
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT = 1;
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC = 2;
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER = 3;
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR = 4;
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR = 5;
            static const byte DIRECTIONALITY_ARABIC_NUMBER = 6;
            static const byte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR = 7;
            static const byte DIRECTIONALITY_NONSPACING_MARK = 8;
            static const byte DIRECTIONALITY_BOUNDARY_NEUTRAL = 9;
            static const byte DIRECTIONALITY_PARAGRAPH_SEPARATOR = 10;
            static const byte DIRECTIONALITY_SEGMENT_SEPARATOR = 11;
            static const byte DIRECTIONALITY_WHITESPACE = 12;
            static const byte DIRECTIONALITY_OTHER_NEUTRALS = 13;
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING = 14;
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE = 15;
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING = 16;
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE = 17;
            static const byte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT = 18;
            static const char16_t MIN_HIGH_SURROGATE = u'\xD800';
            static const char16_t MAX_HIGH_SURROGATE = u'\xDBFF';
            static const char16_t MIN_LOW_SURROGATE = u'\xDC00';
            static const char16_t MAX_LOW_SURROGATE = u'\xDFFF';
            static const char16_t MIN_SURROGATE = MIN_HIGH_SURROGATE;
            static const char16_t MAX_SURROGATE = MAX_LOW_SURROGATE;
            static const int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;
            static const int MIN_CODE_POINT = 0x000000;
            static const int MAX_CODE_POINT = 0x10FFFF;

        private:
            char16_t original;

        public:
            Character();
            Character(char16_t original);
            virtual ~Character();

        public:
            int charCount(int codePoint) const;
            char16_t charValue() const;
            int compareTo(Character anotherCharacter);

        private:
            // throws ArrayIndexOutOfBoundsException if index out of bounds
            static int codePointAtImpl(Array<char16_t> a, int index, int limit);
            // throws ArrayIndexOutOfBoundsException if index-1 out of bounds
            static int codePointBeforeImpl(Array<char16_t> a, int index, int start);
            static int codePointCountImpl(Array<char16_t> a, int offset, int count);

        public:
            static int toCodePoint(unicode high, unicode low);
            static int codePointAt(Array<char16_t> a, int index);
            static int codePointAt(Array<char16_t> a, int index, int limit);
            static int codePointBefore(Array<char16_t> a, int index);
            static int codePointBefore(Array<char16_t> a, int index, int start);
            static int codePointCount(Array<char16_t> a, int offset, int count);
            static int compare(char16_t x, char16_t y);
            static int digit(int codePoint, int radix);
            static boolean isHighSurrogate(char16_t target);
            static boolean isLowSurrogate(char16_t target);
            static boolean isSurrogate(char16_t target);

        public:
            friend std::ostream &operator<<(std::ostream &os, const Character &target);
        };  // class Character
    }  // namespace Lang
}  // namespace Java

#endif  // NATIVE_JAVA_LANG_CHARACTER_HPP_
