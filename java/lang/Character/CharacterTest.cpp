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
}

#include "../Character/Character.hpp"
#include "../ArrayIndexOutOfBoundsException/ArrayIndexOutOfBoundsException.hpp"

using namespace Java::Lang;

TEST (JavaLang, CharacterConstructor) {
    Character character;
    ASSERT_EQUAL('\0', character.charValue());

    character = 'M';
    ASSERT_EQUAL('M', character.charValue());

    character = Character(u'ﾄ');
    ASSERT_EQUAL(u'ﾄ', character.charValue());
}

TEST (JavaLang, CharacterCharCount) {
    Character variableTestCharCount;
    int expectedResultCharCount;
    int actualResultCharCount;

    // Test LATIN CAPITAL LETTER A :  UTF-32 (hex)	0x00000041 (0041)
    expectedResultCharCount = 1;
    actualResultCharCount = variableTestCharCount.charCount(0x00000041);
    ASSERT_EQUAL(expectedResultCharCount, actualResultCharCount);

    // Test Unicode Han Data 香 : UTF-32 (hex)	0x00009999 (9999)
    expectedResultCharCount = 1;
    actualResultCharCount = variableTestCharCount.charCount(0x00009999);
    ASSERT_EQUAL(expectedResultCharCount, actualResultCharCount);

    // Test LINEAR B SYLLABLE B008 A : UTF-32 (hex)	0x00010000 (10000)
    expectedResultCharCount = 2;
    actualResultCharCount = variableTestCharCount.charCount(0x00010000);
    ASSERT_EQUAL(expectedResultCharCount, actualResultCharCount);

    // Test AEGEAN WORD SEPARATOR LINE : UTF-32 (hex)	0x00010100 (10100)
    expectedResultCharCount = 2;
    actualResultCharCount = variableTestCharCount.charCount(0x00010100);
    ASSERT_EQUAL(expectedResultCharCount, actualResultCharCount);
}

TEST (JavaLang, CharacterCharValue) {
    // Create variable to test Character::charValue().
    Character variableTestCharValue;

    // Test NULL value
    ASSERT_EQUAL('\0', variableTestCharValue.charValue());

    // Test valid case
    variableTestCharValue = 'M';
    ASSERT_EQUAL('M', variableTestCharValue.charValue());

    // Test invalid case
    variableTestCharValue = 'M';
    ASSERT_NOT_EQUAL('m', variableTestCharValue.charValue());

    // Test valid case
    variableTestCharValue = u'ﾄ';
    ASSERT_EQUAL(u'ﾄ', variableTestCharValue.charValue());
}

TEST (JavaLang, CharacterCodePointAt) {
    // Create variable to test
    Array<char16_t> arrayCodePointAt;
    int actualResultCodePointAt;

    // Assign value to arrayCodePointAt
    arrayCodePointAt.push('a');
    arrayCodePointAt.push('l');
    arrayCodePointAt.push('w');
    arrayCodePointAt.push('a');
    arrayCodePointAt.push('y');
    arrayCodePointAt.push('s');

    // Test valid case
    actualResultCodePointAt = Character::codePointAt(arrayCodePointAt, 0);
    ASSERT_EQUAL('a', actualResultCodePointAt);

    // Test index < 0
    try {
        actualResultCodePointAt = Character::codePointAt(arrayCodePointAt, -1);
    }
    catch (ArrayIndexOutOfBoundsException &e) {
        ASSERT_STR("Array index out of range: -1", e.getMessage().toString());
    }

    // Valid case
    actualResultCodePointAt = Character::codePointAt(arrayCodePointAt, 1, 2);
    ASSERT_EQUAL('l', actualResultCodePointAt);

    // Index < 0
    try {
        actualResultCodePointAt = Character::codePointAt(arrayCodePointAt, -1, 1);
    }
    catch (ArrayIndexOutOfBoundsException &e) {
        ASSERT_STR("Array index out of range: -1", e.getMessage().toString());
    }

    // Index >= limit
    try {
        actualResultCodePointAt = Character::codePointAt(arrayCodePointAt, 2, 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Limit < 0
    try {
        actualResultCodePointAt = Character::codePointAt(arrayCodePointAt, 0, -1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Limit > arrayCodePointAt.length
    try {
        actualResultCodePointAt = Character::codePointAt(arrayCodePointAt, 0, arrayCodePointAt.length + 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST (JavaLang, CharacterCodePointBefore) {
    // Create variable to test
    Array<char16_t> arrayCodePointBefore;
    int actualResultCodePointBefore;

    arrayCodePointBefore.push('a');
    arrayCodePointBefore.push('l');
    arrayCodePointBefore.push('w');
    arrayCodePointBefore.push('a');
    arrayCodePointBefore.push('y');
    arrayCodePointBefore.push('s');


    // Test valid case
    actualResultCodePointBefore = Character::codePointBefore(arrayCodePointBefore, 2);
    ASSERT_EQUAL('l', actualResultCodePointBefore);

    // Test index < 1
    try {
        actualResultCodePointBefore = Character::codePointBefore(arrayCodePointBefore, 0);
    }
    catch (ArrayIndexOutOfBoundsException &e) {
        ASSERT_STR("Array index out of range: 0", e.getMessage().toString());
    }

    // Valid case
    actualResultCodePointBefore = Character::codePointBefore(arrayCodePointBefore, 2, 1);
    ASSERT_EQUAL('l', actualResultCodePointBefore);

    // Index <= start
    try {
        actualResultCodePointBefore = Character::codePointBefore(arrayCodePointBefore, 2, 2);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Start < 0
    try {
        actualResultCodePointBefore = Character::codePointBefore(arrayCodePointBefore, 0, -1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Start >= arrayCodePointBefore.length
    try {
        actualResultCodePointBefore = Character::codePointBefore(arrayCodePointBefore, 0, arrayCodePointBefore.length);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

}

TEST (JavaLang, CharacterCodePointCount) {
    // Create variable to test
    Array<char16_t> arrayCodePointCount;
    int expectedResultCodePointCount;
    int actualResultCodePointCount;

    // Assign value to a
    arrayCodePointCount.push('a');
    arrayCodePointCount.push(U'\U005cd9b5'); // first way to input high/ low surrogate
    arrayCodePointCount.push(u'\xdc28'); // second way to input high/ low surrogate
    arrayCodePointCount.push(0xdc28); // third way to input high/ low surrogate
    arrayCodePointCount.push('c');
    arrayCodePointCount.push('d');
    arrayCodePointCount.push('e');
    arrayCodePointCount.push('f');
    arrayCodePointCount.push('g');

    // Test valid case
    expectedResultCodePointCount = 5;
    actualResultCodePointCount = Character::codePointCount(arrayCodePointCount, 3, 5);
    ASSERT_EQUAL(expectedResultCodePointCount, actualResultCodePointCount);

    expectedResultCodePointCount = 4;
    actualResultCodePointCount = Character::codePointCount(arrayCodePointCount, 0, 5);
    ASSERT_EQUAL(expectedResultCodePointCount, actualResultCodePointCount);

    // count < 0
    try {
        actualResultCodePointCount = Character::codePointCount(arrayCodePointCount, 2, -1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Offset < 0
    try {
        actualResultCodePointCount = Character::codePointCount(arrayCodePointCount, -1, 2);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Count > length - offset
    try {
        actualResultCodePointCount = Character::codePointCount(arrayCodePointCount, 6, 5);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST (JavaLang, CharacterCompare) {
    // Create variable to test
    char xCompare;
    char yCompare;
    int expectedResultCompare;
    int actualResultCompare;

    // Test valid case
    xCompare = 'd';
    yCompare = 'd';
    expectedResultCompare = 0;
    actualResultCompare = Character::compare(xCompare, yCompare);
    ASSERT_EQUAL(expectedResultCompare, actualResultCompare);

    // Test valid case
    xCompare = 'd';
    yCompare = 'a';
    expectedResultCompare = 3;
    actualResultCompare = Character::compare(xCompare, yCompare);
    ASSERT_EQUAL(expectedResultCompare, actualResultCompare);

    // Test valid case
    xCompare = 'd';
    yCompare = 'e';
    expectedResultCompare = -1;
    actualResultCompare = Character::compare(xCompare, yCompare);
    ASSERT_EQUAL(expectedResultCompare, actualResultCompare);
}

TEST (JavaLang, CharacterCompareTo) {
    // Create variable to test
    Character variableTestCompareTo;
    Character anotherCharacterCompareTo;
    int expectedResultCompareTo;
    int actualResultCompareTo;

    // Test valid case
    variableTestCompareTo = 'd';
    anotherCharacterCompareTo = 'd';
    expectedResultCompareTo = 0;
    actualResultCompareTo = variableTestCompareTo.compareTo(anotherCharacterCompareTo);
    ASSERT_EQUAL(expectedResultCompareTo, actualResultCompareTo);

    // Test valid case
    variableTestCompareTo = 'd';
    anotherCharacterCompareTo = 'a';
    expectedResultCompareTo = 3;
    actualResultCompareTo = variableTestCompareTo.compareTo(anotherCharacterCompareTo);
    ASSERT_EQUAL(expectedResultCompareTo, actualResultCompareTo);

    // Test valid case
    variableTestCompareTo = 'd';
    anotherCharacterCompareTo = 'e';
    expectedResultCompareTo = -1;
    actualResultCompareTo = variableTestCompareTo.compareTo(anotherCharacterCompareTo);
    ASSERT_EQUAL(expectedResultCompareTo, actualResultCompareTo);
}

TEST (JavaLang, CharacterToCodePoint) {
    ASSERT_EQUAL(0x10437, Character::toCodePoint(u'\xD801', u'\xDC37'));
    ASSERT_EQUAL(0x24B62, Character::toCodePoint(u'\xD852', u'\xDF62'));
}

TEST (JavaLang, CharacterIsHighSurrogate) {
    // Test valid case
    ASSERT_TRUE(Character::isHighSurrogate(u'\xD852'));

    // Test invalid case
    ASSERT_FALSE(Character::isHighSurrogate(u'\xDF62'));
}

TEST (JavaLang, CharacterisLowSurrogate) {
    // Test valid case
    ASSERT_TRUE(Character::isLowSurrogate(u'\xDF62'));

    // Test invalid case
    ASSERT_FALSE(Character::isLowSurrogate(u'\xD852'));
}

TEST (JavaLang, CharacterIsSurrogate) {
    // Test valid case
    ASSERT_TRUE(Character::isSurrogate(u'\xD852'));
    // Test invalid case
    ASSERT_FALSE(Character::isSurrogate(u'\x0030'));
}

TEST (JavaLang, CharacterDigit) {
//    //Given valid and invalid value to test with digit(char char, int radix)
//    char16_t hexValueDigit = 'b';
//    char16_t hexValue2Digit = 'd';
//    char16_t hexValue3Digit = '5';
//    char16_t wrongValueDigit = 'q';
//
//    int expectedResultDigit = 11;
//    ASSERT_EQUAL(expectedResultDigit, Character::digit(hexValueDigit, 16));
//
//    expectedResultDigit = 13;
//    ASSERT_EQUAL(expectedResultDigit, Character::digit(hexValue2Digit, 16));
//
//    expectedResultDigit = 5;
//    ASSERT_EQUAL(expectedResultDigit, Character::digit(hexValue3Digit, 16));
//
//    expectedResultDigit = -1;
//    ASSERT_EQUAL(expectedResultDigit, Character::digit(wrongValueDigit, 16));
}
