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
#include "../../Lang.hpp"

namespace Java {
    namespace Lang {
        class Character : public Object {
        public:
            /**
             * The number of bits used to represent a char value in unsigned binary form, constant 16.
             */
            static const int SIZE = 16;

            /**
             * The number of bytes used to represent a char value in unsigned binary form.
             */
            static const int BYTES = SIZE / Bytes::SIZE;

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
            /**
             * Default constructor
             */
            Character();

            /**
             * Constructs a newly allocated Character object that represents the specified char value.
             *
             * @param original
             */
            Character(char16_t original);

            /**
             * Destructor
             */
            virtual ~Character();

        private:
            /**
             * Returns the code point at the given index of the char array,
             * where only array elements with index less than limit can be used.
             * If the char value at the given index in the char array is in the high-surrogate range,
             * the following index is less than the limit,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             *
             * @param charArray
             * @param index
             * @param limit
             * @throw ArrayIndexOutOfBoundsException if index out of bounds
             * @return the Unicode code point at the given index
             */
            static int codePointAtImpl(const Array<char16_t> &charArray, int index, int limit);
            /**
             * Returns the code point preceding the given index of the char array,
             * where only array elements with index greater than or equal to start can be used.
             * If the char value at (index - 1) in the char array is in the low-surrogate range,
             * (index - 2) is not less than start, and the char value at (index - 2)
             * in the char array is in the high-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at (index - 1) is returned.
             *
             * @param charArray
             * @param index
             * @param start
             * @throw ArrayIndexOutOfBoundsException if index-1 out of bounds
             * @return the Unicode code point value before the given index.
             */
            static int codePointBeforeImpl(const Array<char16_t> &charArray, int index, int start);

            /**
             * Returns the number of Unicode code points in a subarray of the char array argument.
             * The offset argument is the index of the first char of the subarray and
             * the count argument specifies the length of the subarray in chars.
             * Unpaired surrogates within the subarray count as one code point each.
             *
             * @param charArray
             * @param offset
             * @param count
             * @return the number of Unicode code points in the specified subarray
             */
            static int codePointCountImpl(const Array<char16_t> &charArray, int offset, int count);

            /**
             * Returns the index within the given char subarray that is offset
             * from the given index by codePointOffset code points.
             * The start and count arguments specify a subarray of the char array.
             * Unpaired surrogates within the text range given by index
             * and codePointOffset count as one code point each.
             *
             * @param charArray
             * @param start
             * @param count
             * @param index
             * @param codePointOffset
             * @throw IndexOutOfBoundsException if start or count is negative,
             * or if start + count is larger than the length of the given array,
             * or if index is less than start or larger then start + count,
             * or if codePointOffset is positive and the text range starting with index
             * and ending with start + count - 1 has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the text range starting with start
             * and ending with index - 1 has fewer than the absolute value of codePointOffset code points.
             * @return the index within the subarray
             */
            static int offsetByCodePointsImpl(const Array<char16_t> &charArray, int start, int count, int index, int codePointOffset);

            /**
             * Assign the char at index and index + 1 of the char array to make a surrogates
             *
             * @param codePoint
             * @param charArray
             * @param index
             */
            static void toSurrogates(int codePoint, Array<char16_t> &charArray, int index);

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using case mapping information from the SpecialCasing file in the Unicode specification.
             * If a character has no explicit uppercase mapping, then the char itself is returned in the char[].
             *
             * @param codePoint
             * @return a char array with the uppercased character
             */
            Array<char16_t> toUpperCaseCharArray(int codePoint) const;

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using information from the UnicodeData file.
             *
             * @param codePoint
             * @return either the uppercase equivalent of the character, if any,
             * or an error flag (Character.ERROR) that indicates that a 1:M char mapping exists.
             */
            static int toUpperCaseEx(int codePoint);

        public:
            /**
             * Determines the number of char values needed to represent the specified character (Unicode code point).
             *
             * @param codePoint
             * @return If the specified character is equal to or greater than 0x10000,
             * then the method returns 2. Otherwise, the method returns 1.
             */
            int charCount(int codePoint) const;

            /**
             * Returns the value of this Character object.
             * @return the primitive char value represented by this object.
             */
            char16_t charValue() const;

            /**
             * Returns the code point at the given index of the CharSequence.
             * If the char value at the given index in the CharSequence is in the high-surrogate range,
             * the following index is less than the length of the CharSequence,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             * @param sequence
             * @param index
             * @throw IndexOutOfBoundsException if the value index is negative or not less than seq.length().
             * @return the Unicode code point at the given index
             */
            static int codePointAt(CharSequence &sequence, int index) ;

            /**
             * Returns the code point at the given index of the char array.
             * If the char value at the given index in the char array is in the high-surrogate range,
             * the following index is less than the length of the char array,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             *
             * @param charArray
             * @param index
             * @throw IndexOutOfBoundsException if the value index is negative
             * or not less than the length of the char array.
             * @return the Unicode code point at the given index
             */
            static int codePointAt(const Array<char16_t> &charArray, int index) ;

            /**
             * Returns the code point at the given index of the char array,
             * where only array elements with index less than limit can be used.
             * If the char value at the given index in the char array is in the high-surrogate range,
             * the following index is less than the limit,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             *
             * @param charArray
             * @param index
             * @param limit
             * @throw IndexOutOfBoundsException if the index argument is negative
             * or not less than the limit argument,
             * or if the limit argument is negative or greater than the length of the char array.
             * @return the Unicode code point at the given index
             */
            static int codePointAt(const Array<char16_t> &charArray, int index, int limit) ;

            /**
             * Returns the code point preceding the given index of the CharSequence.
             * If the char value at (index - 1) in the CharSequence is in the low-surrogate range,
             * (index - 2) is not negative, and the char value at (index - 2)
             * in the CharSequence is in the high-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at (index - 1) is returned.
             *
             * @param sequence
             * @param index
             * @throw IndexOutOfBoundsException if the index argument is less than 1
             * or greater than CharSequence.length().
             * @return the Unicode code point value before the given index.
             */
            static int codePointBefore(CharSequence &sequence, int index);

            /**
             * Returns the code point preceding the given index of the char array.
             * If the char value at (index - 1) in the char array is in the low-surrogate range,
             * (index - 2) is not negative, and the char value at (index - 2) in the char array
             * is in the high-surrogate range, then the supplementary code point corresponding
             * to this surrogate pair is returned. Otherwise, the char value at (index - 1) is returned.
             *
             * @param charArray
             * @param index
             * @throw IndexOutOfBoundsException if the index argument is less than 1
             * or greater than the length of the char array
             * @return the Unicode code point value before the given index.
             */
            static int codePointBefore(const Array<char16_t> &charArray, int index);

            /**
             * Returns the code point preceding the given index of the char array,
             * where only array elements with index greater than or equal to start can be used.
             * If the char value at (index - 1) in the char array is in the low-surrogate range,
             * (index - 2) is not less than start, and the char value at (index - 2)
             * in the char array is in the high-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at (index - 1) is returned.
             *
             * @param charArray
             * @param index
             * @param start
             * @throw IndexOutOfBoundsException if the index argument is not greater
             * than the start argument or is greater than the length of the char array,
             * or if the start argument is negative or not less than the length of the char array.
             * @return the Unicode code point value before the given index.
             */
            static int codePointBefore(const Array<char16_t> &charArray, int index, int start);

            /**
             * Returns the number of Unicode code points in a subarray of the char array argument.
             * The offset argument is the index of the first char of the subarray
             * and the count argument specifies the length of the subarray in chars.
             * Unpaired surrogates within the subarray count as one code point each.
             *
             * @param charArray
             * @param offset
             * @param count
             * @throw IndexOutOfBoundsException if offset or count is negative,
             * or if offset + count is larger than the length of the given array.
             * @return the number of Unicode code points in the specified subarray
             */
            static int codePointCount(const Array<char16_t> &charArray, int offset, int count) ;

            /**
             * Returns the number of Unicode code points in the text range of the specified char sequence.
             * The text range begins at the specified beginIndex and extends to the char at index endIndex - 1.
             * Thus the length (in chars) of the text range is endIndex-beginIndex.
             * Unpaired surrogates within the text range count as one code point each.
             *
             * @param sequence
             * @param beginIndex
             * @param endIndex
             * @throw IndexOutOfBoundsException if the beginIndex is negative,
             * or endIndex is larger than the length of the given sequence,
             * or beginIndex is larger than endIndex.
             * @return the number of Unicode code points in the specified text range
             */
            static int codePointCount(CharSequence &sequence, int beginIndex, int endIndex) ;

            /**
             * Compares two char values numerically.
             *
             * @param charA
             * @param charB
             * @return the value 0 if charA == charB; a value less than 0 if charA < charB;
             * and a value greater than 0 if charA > charB.
             */
            static int compare(char16_t charA, char16_t charB) ;

            /**
             * Compares two Character objects numerically.
             * @param anotherCharacter
             * @return the value 0 if the argument Character is equal to this Character;
             * a value less than 0 if this Character is numerically less than the Character argument;
             * and a value greater than 0 if this Character is numerically greater than the Character argument
             */
            int compareTo(Character anotherCharacter) const;

            /**
             * Returns the numeric value of the character in the specified radix.
             *
             * @param character
             * @param radix
             * @return the numeric value represented by the character in the specified radix.
             */
            static int digit(char16_t character, int radix) ;

            /**
             * Returns the numeric value of the specified character (Unicode code point) in the specified radix.
             *
             * @param codePoint
             * @param radix
             * @return the numeric value represented by the character in the specified radix.
             */
            static int digit(int codePoint, int radix) ;

            /**
             * Compares this object against the specified object. The result is true if and only if t
             * he argument is not null and is a Character object that represents the same char value
             * as this object.
             *
             * @param object
             * @return true if the objects are the same; false otherwise.
             */
            boolean equals(const Object &object) const;

            /**
             * Determines the character representation for a specific digit in the specified radix.
             * If the value of radix is not a valid radix,
             * or the value of digit is not a valid digit in the specified radix,
             * the null character ('\u005Cu0000') is returned.
             *
             * @param digit
             * @param radix
             * @return the char representation of the specified digit in the specified radix.
             */
            char16_t forDigit(int digit, int radix) const;

            /**
             * Returns the Unicode directionality property for the given character (Unicode code point).
             * Character directionality is used to calculate the visual ordering of text.
             *
             * @param codePoint
             * @return the directionality property of the character.
             */
            static byte getDirectionality(int codePoint) ;

            /**
             * Returns the Unicode directionality property for the given character.
             * Character directionality is used to calculate the visual ordering of text.
             *
             * @param character
             * @return the directionality property of the char value.
             */
            static byte getDirectionality(char16_t character) ;

            /**
             * Returns the Unicode name of the specified character codePoint,
             * or null if the code point is unassigned.
             * Note: if the specified character is not assigned a name by the UnicodeData file
             * (part of the Unicode Character Database maintained by the Unicode Consortium),
             * the returned name is the same as the result of expression.
             *
             * @param codePoint
             * @throw IllegalArgumentException if the specified codePoint is not a valid Unicode code point.
             * @return the Unicode name of the specified character, or null if the code point is unassigned.
             */
            static String getName(int codePoint) ;

            /**
             * Returns the int value that the specified character (Unicode code point) represents.
             *
             * @param codePoint
             * @return the numeric value of the character, as a nonnegative int value;
             * -2 if the character has a numeric value that is not a nonnegative integer;
             * -1 if the character has no numeric value.
             */
            static int getNumericValue(int codePoint) ;

            /**
             * Returns the int value that the specified Unicode character represents.
             *
             * @param character
             * @return the numeric value of the character, as a nonnegative int value;
             * -2 if the character has a numeric value that is not a nonnegative integer;
             * -1 if the character has no numeric value.
             */
            static int getNumericValue(char16_t character) ;

            /**
             * Returns a value indicating a character's general category.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the getType(int) method.
             *
             * @param character
             * @return a value of type int representing the character's general category.
             */
            static int getType(char16_t character) ;

            /**
             * Returns a value indicating a character's general category.
             *
             * @param codePoint
             * @return a value of type int representing the character's general category.
             */
            static int getType(int codePoint) ;

            /**
             * Returns a hash code for this Character; equal to the result of invoking charValue().
             *
             * @return a hash code for this Character
             */
            long hashCode() const;

            /**
             * Returns a hash code for a char value; compatible with Character.hashCode().
             *
             * @return a hash code for a char value
             */
            static long hashCode(char16_t) ;

            /**
             * Returns the leading surrogate (a high surrogate code unit) of the surrogate pair
             * representing the specified supplementary character (Unicode code point) in the UTF-16 encoding.
             * If the specified character is not a supplementary character, an unspecified char is returned.
             *
             * @param codePoint
             * @return the leading surrogate code unit used to represent the character in the UTF-16 encoding
             */
            static char16_t highSurrogate(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is an alphabet.
             *
             * @param codePoint
             * @return true if the character is a Unicode alphabet character, false otherwise.
             */
            static boolean isAlphabetic(int codePoint) ;

            /**
             * Determines whether the specified character (Unicode code point)
             * is in the Basic Multilingual Plane (BMP).
             * Such code points can be represented using a single char.
             *
             * @param codePoint
             * @return true if the specified code point is between MIN_VALUE and MAX_VALUE inclusive;
             * false otherwise.
             */
            static boolean isBmpCodePoint(int codePoint) ;

            /**
             * Determines if a character is defined in Unicode.
             * A character is defined if at least one of the following is true:
             *      - It has an entry in the UnicodeData file.
             *      - It has a value in a range defined by the UnicodeData file.
             * Note: This method cannot handle supplementary characters. To support all Unicode characters,
             * including supplementary characters, use the isDefined(int) method.
             *
             * @param character
             * @return true if the character has a defined meaning in Unicode; false otherwise.
             */
            static boolean isDefined(char16_t character) ;

            /**
             * Determines if a character is defined in Unicode.
             * A character is defined if at least one of the following is true:
             *      - It has an entry in the UnicodeData file.
             *      - It has a value in a range defined by the UnicodeData file.
             * Note: This method cannot handle supplementary characters. To support all Unicode characters,
             * including supplementary characters, use the isDefined(int) method.
             *
             * @param codePoint
             * @return true if the character has a defined meaning in Unicode; false otherwise.
             */
            static boolean isDefined(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a digit.
             *
             * @param codePoint
             * @return Determines if the specified character (Unicode code point) is a digit.
             */
            static boolean isDigit(int codePoint) ;

            /**
             * Determines if the specified character is a digit.
             *
             * @param character
             * @return true if the character is a digit; false otherwise.
             */
            static boolean isDigit(char16_t character) ;

            /**
             * Determines if the given char value is a Unicode high-surrogate
             * code unit (also known as leading-surrogate code unit).
             * Such values do not represent characters by themselves,
             * but are used in the representation of supplementary characters in the UTF-16 encoding.
             *
             * @param character
             * @return true if the char value is between MIN_HIGH_SURROGATE
             * and MAX_HIGH_SURROGATE inclusive; false otherwise.
             */
            static boolean isHighSurrogate(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point) should be regarded
             * as an ignorable character in a Java identifier or a Unicode identifier.
             *
             * @param codePoint
             * @return true if the character is an ignorable control character
             * that may be part of a Java or Unicode identifier; false otherwise.
             */
            static boolean isIdentifierIgnorable(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) should be regarded
             * as an ignorable character in a Java identifier or a Unicode identifier.
             *
             * @param character
             * @return true if the character is an ignorable control character
             * that may be part of a Java or Unicode identifier; false otherwise.
             */
            static boolean isIdentifierIgnorable(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point)
             * is a CJKV (Chinese, Japanese, Korean and Vietnamese) ideograph,
             * as defined by the Unicode Standard.
             *
             * @param codePoint
             * @return true if the character is a Unicode ideograph character, false otherwise.
             */
            static boolean isIdeographic(int codePoint) ;

            /**
             * Determines if the specified character is an ISO control character.
             * A character is considered to be an ISO control character
             * if its code is in the range '\u005Cu0000' through '\u005Cu001F'
             * or in the range '\u005Cu007F' through '\u005Cu009F'.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isISOControl(int) method.
             *
             * @param character
             * @return true if the character is an ISO control character; false otherwise.
             */
            static boolean isISOControl(char16_t character) ;

            /**
             * Determines if the specified character is an ISO control character.
             * A character is considered to be an ISO control character
             * if its code is in the range '\u005Cu0000' through '\u005Cu001F'
             * or in the range '\u005Cu007F' through '\u005Cu009F'.
             *
             * @param codePoint
             * @return true if the character is an ISO control character; false otherwise.
             */
            static boolean isISOControl(int codePoint) ;

            /**
             * Determines if the specified character may be part
             * of a Java identifier as other than the first character.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isJavaIdentifierPart(int) method.
             *
             * @param character
             * @return true if the character may be part of a Java identifier; false otherwise.
             */
            static boolean isJavaIdentifierPart(char16_t character) ;

            /**
             * Determines if the specified character may be part
             * of a Java identifier as other than the first character.
             *
             * @param codePoint
             * @return true if the character may be part of a Java identifier; false otherwise.
             */
            static boolean isJavaIdentifierPart(int codePoint) ;

            /**
             * Determines if the specified character is permissible
             * as the first character in a Java identifier.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isJavaIdentifierStart(int) method.
             *
             * @param character
             * @return true if the character may start a Java identifier; false otherwise.
             */
            static boolean isJavaIdentifierStart(char16_t character) ;

            /**
            * Determines if the specified character is permissible
            * as the first character in a Java identifier.
            *
            * @param codePoint
            * @return true if the character may start a Java identifier; false otherwise.
            */
            static boolean isJavaIdentifierStart(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a letter.
             *
             * @param codePoint
             * @return Determines if the specified character (Unicode code point) is a letter.
             */
            static boolean isLetter(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a letter.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isLetter(int) method.
             *
             * @param codePoint
             * @return Determines if the specified character (Unicode code point) is a letter.
             */
            static boolean isLetter(char16_t character) ;

            /**
             * Determines if the specified character is a letter or digit.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isLetterOrDigit(int) method.
             *
             * @param character
             * @return true if the character is a letter or digit; false otherwise.
             */
            static boolean isLetterOrDigit(char16_t character) ;

            /**
            * Determines if the specified character is a letter or digit.
            *
            * @param codePoint
            * @return true if the character is a letter or digit; false otherwise.
            */
            static boolean isLetterOrDigit(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a lowercase character.
             * A character is lowercase if its general category type, provided by getType(codePoint),
             * is LOWERCASE_LETTER, or it has contributory property Other_Lowercase as defined by the Unicode Standard.
             *
             * @param codePoint
             * @return true if the character is lowercase; false otherwise.
             */
            static boolean isLowerCase(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a lowercase character.
             * A character is lowercase if its general category type, provided by getType(codePoint),
             * is LOWERCASE_LETTER, or it has contributory property Other_Lowercase as defined by the Unicode Standard.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isLowerCase(int) method.
             *
             * @param character
             * @return true if the character is lowercase; false otherwise.
             */
            static boolean isLowerCase(char16_t character) ;

            /**
             * Determines if the given char value is a Unicode low-surrogate
             * code unit (also known as trailing-surrogate code unit).
             * Such values do not represent characters by themselves,
             * but are used in the representation of supplementary characters in the UTF-16 encoding.
             *
             * @param character
             * @return true if the char value is between MIN_LOW_SURROGATE
             * and MAX_LOW_SURROGATE inclusive; false otherwise.
             */
            static boolean isLowSurrogate(char16_t character) ;

            /**
             * Determines whether the character is mirrored according to the Unicode specification.
             * Mirrored characters should have their glyphs horizontally mirrored when displayed in text
             * that is right-to-left. For example, '\u005Cu0028' LEFT PARENTHESIS is semantically defined to
             * be an opening parenthesis. This will appear as a "(" in text that is left-to-right but as a ")"
             * in text that is right-to-left.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isMirrored(int) method.
             *
             * @param character
             * @return true if the char is mirrored, false if the char is not mirrored or is not defined.
             */
            static boolean isMirrored(char16_t character) ;

            /**
             * Determines whether the character is mirrored according to the Unicode specification.
             * Mirrored characters should have their glyphs horizontally mirrored when displayed in text
             * that is right-to-left. For example, '\u005Cu0028' LEFT PARENTHESIS is semantically defined to
             * be an opening parenthesis. This will appear as a "(" in text that is left-to-right but as a ")"
             * in text that is right-to-left.
             *
             * @param codePoint
             * @return true if the char is mirrored, false if the char is not mirrored or is not defined.
             */
            static boolean isMirrored(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a Unicode space character.
             * A character is considered to be a space character if and only if
             * it is specified to be a space character by the Unicode Standard.
             *
             * @param codePoint
             * @return true if the character is a space character; false otherwise.
             */
            static boolean isSpaceChar(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a Unicode space character.
             * A character is considered to be a space character if and only if
             * it is specified to be a space character by the Unicode Standard.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isSpaceChar(int) method.
             *
             * @param character
             * @return true if the character is a space character; false otherwise.
             */
            static boolean isSpaceChar(char16_t character) ;

            /**
             * Determines whether the specified character (Unicode code point)
             * is in the supplementary character range.
             *
             * @param codePoint
             * @return true if the specified code point is between MIN_SUPPLEMENTARY_CODE_POINT
             * and MAX_CODE_POINT inclusive; false otherwise.
             */
            static boolean isSupplementaryCodePoint(int codePoint) ;

            /**
             * Determines if the given char value is a Unicode surrogate code unit.
             * Such values do not represent characters by themselves, but are used in
             * the representation of supplementary characters in the UTF-16 encoding.
             * A char value is a surrogate code unit if and only if it is either
             * a low-surrogate code unit or a high-surrogate code unit.
             *
             * @param character
             * @return true if the char value is between MIN_SURROGATE and MAX_SURROGATE inclusive;
             * false otherwise.
             */
            static boolean isSurrogate(char16_t character) ;

            /**
             * Determines whether the specified pair of char values is a valid Unicode surrogate pair.
             *
             * @param high
             * @param low
             * @return Determines whether the specified pair of char values is a valid Unicode surrogate pair.
             */
            static boolean isSurrogatePair(char16_t high, char16_t low) ;

            /**
             * Determines if the specified character (Unicode code point) is a titlecase character.
             *
             * @param codePoint
             * @return true if the character is titlecase; false otherwise.
             */
            static boolean isTitleCase(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a titlecase character.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isTitleCase(int) method.
             *
             * @param character
             * @return true if the character is titlecase; false otherwise.
             */
            static boolean isTitleCase(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point) may be part of
             * a Unicode identifier as other than the first character.
             *
             * @param codePoint
             * @return true if the character may be part of a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierPart(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) may be part of
             * a Unicode identifier as other than the first character.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isUnicodeIdentifierPart(int) method.
             *
             * @param character
             * @return true if the character may be part of a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierPart(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point) is permissible
             * as the first character in a Unicode identifier.
             *
             * @param codePoint
             * @return true if the character may start a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierStart(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is permissible
             * as the first character in a Unicode identifier.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isUnicodeIdentifierStart(int) method.
             * @param character
             * @return true if the character may start a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierStart(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point) is an uppercase character.
             *
             * @param character
             * @return true if the character is uppercase; false otherwise.
             */
            static boolean isUpperCase(int character) ;

            /**
            * Determines if the specified character (Unicode code point) is an uppercase character.
            * Note: This method cannot handle supplementary characters.
            * To support all Unicode characters, including supplementary characters,
            * use the isUpperCase(int) method.
            *
            * @param character
            * @return true if the character is uppercase; false otherwise.
            */
            static boolean isUpperCase(char16_t character) ;

            /**
             * Determines whether the specified code point is a valid Unicode code point value.
             *
             * @param codePoint
             * @return true if the specified code point value is between MIN_CODE_POINT
             * and MAX_CODE_POINT inclusive; false otherwise.
             */
            static boolean isValidCodePoint(int codePoint) ;

            /**
             * Determines if the specified character is white space according to Java.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isWhitespace(int) method.
             *
             * @param character
             * @return true if the character is a Java whitespace character; false otherwise.
             */
            static boolean isWhitespace(char16_t character) ;

            /**
             * Determines if the specified character is white space according to Java.
             *
             * @param codePoint
             * @return true if the character is a Java whitespace character; false otherwise.
             */
            static boolean isWhitespace(int codePoint) ;

            /**
             * Returns the index within the given char sequence that is offset
             * from the given index by codePointOffset code points.
             * Unpaired surrogates within the text range given by index
             * and codePointOffset count as one code point each.
             *
             * @param sequence
             * @param index
             * @param codePointOffset
             * @throw IndexOutOfBoundsException if index is negative or larger than
             * the length of the char sequence, or if codePointOffset is positive
             * and the subsequence starting with index has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the subsequence before index has fewer than
             * the absolute value of codePointOffset code points.
             * @return the index within the char sequence
             */
            static int offsetByCodePoints(CharSequence &sequence, int index, int codePointOffset) ;

            /**
             * Returns the index within the given char subarray that is offset
             * from the given index by codePointOffset code points.
             * The start and count arguments specify a subarray of the char array.
             * Unpaired surrogates within the text range given by index
             * and codePointOffset count as one code point each.
             *
             * @param charArray
             * @param start
             * @param count
             * @param index
             * @param codePointOffset
             * @throw IndexOutOfBoundsException if start or count is negative,
             * or if start + count is larger than the length of the given array,
             * or if index is less than start or larger then start + count,
             * or if codePointOffset is positive and the text range starting with index
             * and ending with start + count - 1 has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the text range starting with start
             * and ending with index - 1 has fewer than the absolute value of codePointOffset code points.
             * @return the index within the subarray
             */
            static int offsetByCodePoints(const Array<char16_t> &charArray, int start, int count, int index, int codePointOffset) ;

            /**
             * Returns the value obtained by reversing the order of the bytes
             * in the specified char value.
             *
             * @param character
             * @return the value obtained by reversing (or, equivalently, swapping)
             * the bytes in the specified char value.
             */
            static char reverseBytes(char16_t character) ;

            /**
             * Converts the specified character (Unicode code point) to its UTF-16
             * representation stored in a char array.
             * If the specified code point is a BMP (Basic Multilingual Plane or Plane 0) value,
             * the resulting char array has the same value as codePoint.
             * If the specified code point is a supplementary code point,
             * the resulting char array has the corresponding surrogate pair.
             *
             * @param codePoint
             * @throw IllegalArgumentException if the specified codePoint
             * is not a valid Unicode code point.
             * @return a char array having codePoint's UTF-16 representation.
             */
            static const Array<char16_t> & toChars(int codePoint) ;

            /**
             * Converts the specified character (Unicode code point) to its UTF-16 representation.
             * If the specified code point is a BMP (Basic Multilingual Plane or Plane 0) value,
             * the same value is stored in dst[dstIndex], and 1 is returned.
             * If the specified code point is a supplementary character,
             * its surrogate values are stored in dst[dstIndex] (high-surrogate)
             * and dst[dstIndex+1] (low-surrogate), and 2 is returned.
             *
             * @param codePoint
             * @param destination
             * @param destinationIndex
             * @throw IllegalArgumentException if the specified codePoint
             * is not a valid Unicode code point.
             * @throw IndexOutOfBoundsException if dstIndex is negative or not less than dst.length,
             * or if dst at dstIndex doesn't have enough array element(s) to store the resulting char value(s).
             * (If dstIndex is equal to dst.length-1 and the specified codePoint is a supplementary character,
             * the high-surrogate value is not stored in dst[dstIndex].)
             * @return 1 if the code point is a BMP code point,
             * 2 if the code point is a supplementary code point.
             */
            static int toChars(int codePoint, Array<char16_t> &destination, int destinationIndex) ;

            /**
             * Converts the specified surrogate pair to its supplementary code point value.
             * This method does not validate the specified surrogate pair.
             *
             * @param high
             * @param low
             * @return the supplementary code point composed from the specified surrogate pair.
             */
            static int toCodePoint(char16_t high, char16_t low) ;

            /**
             * Converts the character (Unicode code point) argument to lowercase using
             * case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return the lowercase equivalent of the character (Unicode code point), if any;
             * otherwise, the character itself.
             */
            static int toLowerCase(int codePoint) ;

            /**
             * Converts the character (Unicode code point) argument to lowercase using
             * case mapping information from the UnicodeData file.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the toLowerCase(int) method.
             *
             * @param character
             * @return the lowercase equivalent of the character (Unicode code point), if any;
             * otherwise, the character itself.
             */
            static int toLowerCase(char16_t character) ;

            /**
             * Returns a String object representing this Character's value.
             * The result is a string of length 1 whose sole component is the primitive char value
             * represented by this Character object.
             *
             * @return a string representation of this object.
             */
            string toString() const;

            /**
             * Returns a String object representing the specified char.
             * The result is a string of length 1 consisting solely of the specified char.
             *
             * @return a string representation of the specified char.
             */
            static string toString(char16_t character) ;

            /**
             * Converts the character (Unicode code point) argument to titlecase
             * using case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return the titlecase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toTitleCase(int codePoint) ;

            /**
             * Converts the character (Unicode code point) argument to titlecase
             * using case mapping information from the UnicodeData file.
             *
             * @param character
             * @return the titlecase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toTitleCase(char16_t character) ;

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return the uppercase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toUpperCase(int codePoint) ;

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using case mapping information from the UnicodeData file.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the toUpperCase(int) method.
             *
             * @param character
             * @return the uppercase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toUpperCase(char16_t character) ;

            /**
             * Returns a Character instance representing the specified char value.
             * If a new Character instance is not required,
             * this method should generally be used in preference to the constructor Character(char),
             * as this method is likely to yield significantly better space
             * and time performance by caching frequently requested values.
             * This method will always cache values in the range '\u005Cu0000' to '\u005Cu007F',
             * inclusive, and may cache other values outside of this range.
             *
             * @param character
             * @return a Character instance representing character.
             */
            static Character valueOf(char16_t character) ;

        public:
            friend std::ostream &operator<<(std::ostream &os, const Character &target);
        };  // class Character
    }  // namespace Lang
}  // namespace Java

#endif  // NATIVE_JAVA_LANG_CHARACTER_HPP_
