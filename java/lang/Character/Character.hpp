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
            /**
             * The minimum radix available for conversion to and from strings.
             */
            static const int MIN_RADIX = 2;

            /**
             * The maximum radix available for conversion to and from strings.
             */
            static const int MAX_RADIX = 36;

            /**
             * The constant value of this field is the smallest value of type char
             */
            static const char16_t MIN_VALUE = u'\u0000';

            /**
             * The constant value of this field is the largest value of type char
             */
            static const char16_t MAX_VALUE = u'\uFFFF';

            /**
             * General category "Cn" in the Unicode specification.
             */
            static const byte UNASSIGNED = 0;

            /**
             * General category "Lu" in the Unicode specification.
             */
            static const byte UPPERCASE_LETTER = 1;

            /**
             * General category "Ll" in the Unicode specification.
             */
            static const byte LOWERCASE_LETTER = 2;

            /**
             * General category "Lt" in the Unicode specification.
             */
            static const byte TITLECASE_LETTER = 3;

            /**
             * General category "Lm" in the Unicode specification.
             */
            static const byte MODIFIER_LETTER = 4;

            /**
             * General category "Lo" in the Unicode specification.
             */
            static const byte OTHER_LETTER = 5;

            /**
             * General category "Mn" in the Unicode specification.
             */
            static const byte NON_SPACING_MARK = 6;

            /**
             * General category "Me" in the Unicode specification.
             */
            static const byte ENCLOSING_MARK = 7;

            /**
             * General category "Mc" in the Unicode specification.
             */
            static const byte COMBINING_SPACING_MARK = 8;

            /**
             * General category "Nd" in the Unicode specification.
             */
            static const byte DECIMAL_DIGIT_NUMBER = 9;

            /**
             * General category "Nl" in the Unicode specification.
             */
            static const byte LETTER_NUMBER = 10;

            /**
             * General category "No" in the Unicode specification.
             */
            static const byte OTHER_NUMBER = 11;

            /**
             * General category "Zs" in the Unicode specification.
             */
            static const byte SPACE_SEPARATOR = 12;

            /**
             * General category "Zl" in the Unicode specification.
             */
            static const byte LINE_SEPARATOR = 13;

            /**
             * General category "Zp" in the Unicode specification.
             */
            static const byte PARAGRAPH_SEPARATOR = 14;

            /**
             * General category "Cc" in the Unicode specification.
             */
            static const byte CONTROL = 15;

            /**
             * General category "Cf" in the Unicode specification.
             */
            static const byte FORMAT = 16;

            /**
             * General category "Co" in the Unicode specification.
             */
            static const byte PRIVATE_USE = 18;

            /**
             * General category "Cs" in the Unicode specification.
             */
            static const byte SURROGATE = 19;

            /**
             * General category "Pd" in the Unicode specification.
             */
            static const byte DASH_PUNCTUATION = 20;

            /**
             * General category "Ps" in the Unicode specification.
             */
            static const byte START_PUNCTUATION = 21;

            /**
             * General category "Pe" in the Unicode specification.
             */
            static const byte END_PUNCTUATION = 22;

            /**
             * General category "Pc" in the Unicode specification.
             */
            static const byte CONNECTOR_PUNCTUATION = 23;

            /**
             * General category "Po" in the Unicode specification.
             */
            static const byte OTHER_PUNCTUATION = 24;

            /**
             * General category "Sm" in the Unicode specification.
             */
            static const byte MATH_SYMBOL = 25;

            /**
             * General category "Sc" in the Unicode specification.
             */
            static const byte CURRENCY_SYMBOL = 26;

            /**
             * General category "Sk" in the Unicode specification.
             */
            static const byte MODIFIER_SYMBOL = 27;

            /**
             * General category "So" in the Unicode specification.
             */
            static const byte OTHER_SYMBOL = 28;

            /**
             * General category "Pi" in the Unicode specification.
             */
            static const byte INITIAL_QUOTE_PUNCTUATION = 29;

            /**
             * General category "Pf" in the Unicode specification.
             */
            static const byte FINAL_QUOTE_PUNCTUATION = 30;

            /**
             * Error flag. Use int (code point) to avoid confusion with U+FFFF.
             */
            static const int ERROR = 0xFFFFFFFF;

            /**
             * Undefined bidirectional character type.
             * Undefined char values have undefined directionality in the Unicode specification.
             */
            static const char DIRECTIONALITY_UNDEFINED = -1;

            /**
             * Strong bidirectional character type "L" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT = 0;

            /**
             * Strong bidirectional character type "R" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT = 1;

            /**
             * Strong bidirectional character type "AL" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC = 2;

            /**
             * Weak bidirectional character type "EN" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER = 3;

            /**
             * Weak bidirectional character type "ES" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR = 4;

            /**
             * Weak bidirectional character type "ET" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR = 5;

            /**
             * Weak bidirectional character type "AN" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_ARABIC_NUMBER = 6;

            /**
             * Weak bidirectional character type "CS" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR = 7;

            /**
             * Weak bidirectional character type "NSM" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_NONSPACING_MARK = 8;

            /**
             * Weak bidirectional character type "BN" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_BOUNDARY_NEUTRAL = 9;

            /**
             * Neutral bidirectional character type "B" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_PARAGRAPH_SEPARATOR = 10;

            /**
             * Neutral bidirectional character type "S" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_SEGMENT_SEPARATOR = 11;

            /**
             * Neutral bidirectional character type "WS" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_WHITESPACE = 12;

            /**
             * Neutral bidirectional character type "ON" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_OTHER_NEUTRALS = 13;

            /**
             * Strong bidirectional character type "LRE" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING = 14;

            /**
             * Strong bidirectional character type "LRO" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE = 15;

            /**
             * Strong bidirectional character type "RLE" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING = 16;

            /**
             * Strong bidirectional character type "RLO" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE = 17;

            /**
             * Weak bidirectional character type "PDF" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT = 18;

            /**
             * The minimum value of a Unicode high-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuD800'. A high-surrogate is also known as a leading-surrogate.
             */
            static const char16_t MIN_HIGH_SURROGATE = 0xD800;

            /**
             * The maximum value of a Unicode high-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDBFF'. A high-surrogate is also known as a leading-surrogate.
             */
            static const char16_t MAX_HIGH_SURROGATE = 0xDBFF;

            /**
             * The minimum value of a Unicode low-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDC00'. A low-surrogate is also known as a trailing-surrogate.
             */
            static const char16_t MIN_LOW_SURROGATE = 0xDC00;

            /**
             * The maximum value of a Unicode low-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDFFF'. A low-surrogate is also known as a trailing-surrogate.
             */
            static const char16_t MAX_LOW_SURROGATE = 0xDFFF;

            /**
             * The minimum value of a Unicode surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuD800'.
             */
            static const char16_t MIN_SURROGATE = MIN_HIGH_SURROGATE;

            /**
             * The maximum value of a Unicode surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDFFF'.
             */
            static const char16_t MAX_SURROGATE = MAX_LOW_SURROGATE;

            /**
             * The minimum value of a Unicode supplementary code point, constant U+10000.
             */
            static const int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;

            /**
             * The minimum value of a Unicode code point, constant U+0000.
             */
            static const int MIN_CODE_POINT = 0x000000;

            /**
             * The maximum value of a Unicode code point, constant U+10FFFF.
             */
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
            static int toCodePoint(char16_t high, char16_t low);
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
