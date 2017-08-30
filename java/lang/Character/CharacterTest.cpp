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

TEST(JavaLang, CharacterConstructor) {
    Character character;
    ASSERT_EQUAL('\0', character.charValue());

    character = 'M';
    ASSERT_EQUAL('M', character.charValue());

    character = Character(u'ﾄ');
    ASSERT_EQUAL(u'ﾄ', character.charValue());
}

TEST(JavaLang, CharacterCharCount) {
    Character variableTestCharCount;
    int expectResult;
    int actualResult;

    // Test LATIN CAPITAL LETTER A :  UTF-32 (hex)	0x00000041 (0041)
    expectResult = 1;
    actualResult = variableTestCharCount.charCount(0x00000041);
    ASSERT_EQUAL(expectResult, actualResult);

    // Test Unicode Han Data 香 : UTF-32 (hex)	0x00009999 (9999)
    expectResult = 1;
    actualResult = variableTestCharCount.charCount(0x00009999);
    ASSERT_EQUAL(expectResult, actualResult);

    // Test LINEAR B SYLLABLE B008 A : UTF-32 (hex)	0x00010000 (10000)
    expectResult = 2;
    actualResult = variableTestCharCount.charCount(0x00010000);
    ASSERT_EQUAL(expectResult, actualResult);

    // Test AEGEAN WORD SEPARATOR LINE : UTF-32 (hex)	0x00010100 (10100)
    expectResult = 2;
    actualResult = variableTestCharCount.charCount(0x00010100);
    ASSERT_EQUAL(expectResult, actualResult);
}

TEST(JavaLang, CharacterCharValue) {
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

TEST(JavaLang, CharacterCodePointAt) {
    // Create variable to test
    Array<char16_t> arrayCodePointAt;
    int actualResult;

    // Assign value to arrayCodePointAt
    arrayCodePointAt.push('a');
    arrayCodePointAt.push('l');
    arrayCodePointAt.push('w');
    arrayCodePointAt.push('a');
    arrayCodePointAt.push('y');
    arrayCodePointAt.push('s');

    // Test valid case
    actualResult = Character::codePointAt(arrayCodePointAt, 0);
    ASSERT_EQUAL('a', actualResult);

    // Test index < 0
    try {
        actualResult = Character::codePointAt(arrayCodePointAt, -1);
    }
    catch (ArrayIndexOutOfBoundsException &e) {
        ASSERT_STR("Array index out of range: -1", e.getMessage().toString());
    }

    // Valid case
    actualResult = Character::codePointAt(arrayCodePointAt, 1, 2);
    ASSERT_EQUAL('l', actualResult);

    // Index < 0
    try {
        actualResult = Character::codePointAt(arrayCodePointAt, -1, 1);
    }
    catch (ArrayIndexOutOfBoundsException &e) {
        ASSERT_STR("Array index out of range: -1", e.getMessage().toString());
    }

    // Index >= limit
    try {
        actualResult = Character::codePointAt(arrayCodePointAt, 2, 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Limit < 0
    try {
        actualResult = Character::codePointAt(arrayCodePointAt, 0, -1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Limit > arrayCodePointAt.length
    try {
        actualResult = Character::codePointAt(arrayCodePointAt, 0, arrayCodePointAt.length + 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST(JavaLang, CharacterCodePointBefore) {
    // Create variable to test
    Array<char16_t> arrayCodePointBefore;
    int actualResult;

    arrayCodePointBefore.push('a');
    arrayCodePointBefore.push('l');
    arrayCodePointBefore.push('w');
    arrayCodePointBefore.push('a');
    arrayCodePointBefore.push('y');
    arrayCodePointBefore.push('s');


    // Test valid case
    actualResult = Character::codePointBefore(arrayCodePointBefore, 2);
    ASSERT_EQUAL('l', actualResult);

    // Test index < 1
    try {
        actualResult = Character::codePointBefore(arrayCodePointBefore, 0);
    }
    catch (ArrayIndexOutOfBoundsException &e) {
        ASSERT_STR("Array index out of range: 0", e.getMessage().toString());
    }

    // Valid case
    actualResult = Character::codePointBefore(arrayCodePointBefore, 2, 1);
    ASSERT_EQUAL('l', actualResult);

    // Index <= start
    try {
        actualResult = Character::codePointBefore(arrayCodePointBefore, 2, 2);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Start < 0
    try {
        actualResult = Character::codePointBefore(arrayCodePointBefore, 0, -1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Start >= arrayCodePointBefore.length
    try {
        actualResult = Character::codePointBefore(arrayCodePointBefore, 0, arrayCodePointBefore.length);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

}

TEST(JavaLang, CharacterCodePointCount) {
    // Create variable to test
    Array<char16_t> arrayCodePointCount;
    int expectedResult;
    int actualResult;

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
    expectedResult = 5;
    actualResult = Character::codePointCount(arrayCodePointCount, 3, 5);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedResult = 4;
    actualResult = Character::codePointCount(arrayCodePointCount, 0, 5);
    ASSERT_EQUAL(expectedResult, actualResult);

    // count < 0
    try {
        actualResult = Character::codePointCount(arrayCodePointCount, 2, -1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Offset < 0
    try {
        actualResult = Character::codePointCount(arrayCodePointCount, -1, 2);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Count > length - offset
    try {
        actualResult = Character::codePointCount(arrayCodePointCount, 6, 5);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST(JavaLang, CharacterCompare) {
    // Create variable to test
    int actualResult;

    // Test equal case
    actualResult = Character::compare('a', 'a');
    ASSERT_TRUE(actualResult == 0);

    // Test charA > charB case
    actualResult = Character::compare('d', 'a');
    ASSERT_TRUE(actualResult > 0);

    // Test charA < charB case
    actualResult = Character::compare('a', 'd');
    ASSERT_TRUE(actualResult < 0);
}

TEST(JavaLang, CharacterCompareTo) {
    // Create variable to test
    Character character = 'a';
    Character anotherCharacter = 'd';
    int actualResult;

    // Test equal case
    actualResult = character.compareTo(Character('a'));
    ASSERT_TRUE(actualResult == 0);

    // Test charA > charB case
    actualResult = anotherCharacter.compareTo(character);
    ASSERT_TRUE(actualResult > 0);

    // Test charA < charB case
    actualResult = character.compareTo(anotherCharacter);
    ASSERT_TRUE(actualResult < 0);

    // Test comparable
    Comparable<Character> *comparable = &character;
    actualResult = comparable->compareTo(anotherCharacter);
    ASSERT_TRUE(actualResult < 0);
}

TEST(JavaLang, CharacterToCodePoint) {
    ASSERT_EQUAL(0x10437, Character::toCodePoint(u'\xD801', u'\xDC37'));
    ASSERT_EQUAL(0x24B62, Character::toCodePoint(u'\xD852', u'\xDF62'));
}

TEST(JavaLang, CharacterIsHighSurrogate) {
    // Test valid case
    ASSERT_TRUE(Character::isHighSurrogate(u'\xD852'));

    // Test invalid case
    ASSERT_FALSE(Character::isHighSurrogate(u'\xDF62'));
}

TEST(JavaLang, CharacterisLowSurrogate) {
    // Test valid case
    ASSERT_TRUE(Character::isLowSurrogate(u'\xDF62'));

    // Test invalid case
    ASSERT_FALSE(Character::isLowSurrogate(u'\xD852'));
}

TEST(JavaLang, CharacterIsSurrogate) {
    // Test valid case
    ASSERT_TRUE(Character::isSurrogate(u'\xD852'));
    // Test invalid case
    ASSERT_FALSE(Character::isSurrogate(u'\x0030'));
}

TEST(JavaLang, CharacterEquals) {
    // Create variable to test
    Character character = 'a';
    Character anotherCharacter = 'd';
    Character equalToCharacter = 'a';

    // Test equal case
    ASSERT_TRUE(character.equals(equalToCharacter));

    // Test not equal
    ASSERT_FALSE(character.equals(anotherCharacter));
}

TEST(JavaLang, CharacterHashCode) {
    // Character to get hashcode
    Character character = 'a';
    ASSERT_EQUAL(97, character.hashCode());

    ASSERT_EQUAL(97, Character::hashCode('a'));
}

TEST(JavaLang, CharacterOffsetByCodePoint) {
    // Create variable to test
    Array<char16_t> arrayCodePoint;
    int expectedResult;
    int actualResult;

    // Assign value to a
    arrayCodePoint.push('a');
    arrayCodePoint.push(U'\U005cd9b5'); // first way to input high/ low surrogate
    arrayCodePoint.push(u'\xdc28'); // second way to input high/ low surrogate
    arrayCodePoint.push(0xdc28); // third way to input high/ low surrogate
    arrayCodePoint.push('c');
    arrayCodePoint.push('d');
    arrayCodePoint.push('e');
    arrayCodePoint.push('f');
    arrayCodePoint.push('g');

    // Test valid case
    expectedResult = 8;
    actualResult = Character::offsetByCodePoints(arrayCodePoint,0, 9, 3, 5);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedResult = 7;
    actualResult = Character::offsetByCodePoints(arrayCodePoint, 0, 9, 1, 5);
    ASSERT_EQUAL(expectedResult, actualResult);

    expectedResult = 3;
    actualResult = Character::offsetByCodePoints(arrayCodePoint, 0, 9, 5, -2);
    ASSERT_EQUAL(expectedResult, actualResult);

    // count > charArray.length - start
    try {
        actualResult = Character::offsetByCodePoints(arrayCodePoint, 0, 10, 2, 5);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Start < 0
    try {
        actualResult = Character::offsetByCodePoints(arrayCodePoint, -1, 2, 0, 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Count < 0
    try {
        actualResult = Character::offsetByCodePoints(arrayCodePoint, 0, -1, 0, 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Index < start
    try {
        actualResult = Character::offsetByCodePoints(arrayCodePoint, 3, 5, 2, 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Index > start + count
    try {
        actualResult = Character::offsetByCodePoints(arrayCodePoint, 2, 5, 8, 0);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // codePointOffset out of range
    try {
        actualResult = Character::offsetByCodePoints(arrayCodePoint, 0, 5, 1, 4);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // codePointOffset out of range
    try {
        actualResult = Character::offsetByCodePoints(arrayCodePoint, 1, 7, 4, -3);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST(JavaLang, CharacterHighSurrogate) {
    ASSERT_EQUAL(55296, Character::highSurrogate(0x10043));

    ASSERT_EQUAL(55231, Character::highSurrogate(-1));
}

TEST(JavaLang, CharacterLowSurrogate) {
    ASSERT_EQUAL(56387, Character::lowSurrogate(0x10043));
}

TEST(JavaLang, CharacterForDigit) {
    // Digit > radix
    ASSERT_EQUAL('\0', Character::forDigit(5, 2));

    // Digit < 0
    ASSERT_EQUAL('\0', Character::forDigit(-1, 3));

    // Radix out of range
    ASSERT_EQUAL('\0', Character::forDigit(5, 1));
    ASSERT_EQUAL('\0', Character::forDigit(5, 37));

    // Digit < 10
    ASSERT_EQUAL('5', Character::forDigit(5, 10));

    // Digit >= 10
    ASSERT_EQUAL('e', Character::forDigit(14, 16));
}

TEST(JavaLang, CharacterIsValidCodePoint) {
    ASSERT_TRUE(Character::isValidCodePoint(0x0324));
    ASSERT_FALSE(Character::isValidCodePoint(0xFFFFFF));
    ASSERT_FALSE(Character::isValidCodePoint(-1));
}
