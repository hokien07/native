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

extern "C" {
#include "../../../kernel/test.h"
}

#include "../StringBuilder/StringBuilder.hpp"
#include "../NegativeArraySizeException/NegativeArraySizeException.hpp"
#include "../IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"

using namespace Java::Lang;

TEST(JavaLang, StringBuilderConstructor) {
    StringBuilder defaultStringBuilder;
    ASSERT_EQUAL(0, defaultStringBuilder.length());
    ASSERT_EQUAL(StringBuilder::defaultCapacity, defaultStringBuilder.capacity());

    StringBuilder customCapacityStringBuilder(20);
    ASSERT_EQUAL(0, customCapacityStringBuilder.length());
    ASSERT_EQUAL(20, customCapacityStringBuilder.capacity());

    try {
        StringBuilder negativeCapacityStringBuilder(-1);
    }
    catch (NegativeArraySizeException &ex) {
        ASSERT_STR("Capacity is negative", ex.getMessage().toString());
    }

    String aString = "Hello! Welcome to VietNam!";
    int aStringLength = aString.length();
    StringBuilder nullTerminatedStringStringBuilder(aString.toString());
    StringBuilder stringStringBuilder(aString);
    int newCapacity = StringBuilder::defaultCapacity + aStringLength;
    ASSERT_EQUAL(aStringLength, nullTerminatedStringStringBuilder.length());
    ASSERT_EQUAL(newCapacity, nullTerminatedStringStringBuilder.capacity());
    ASSERT_EQUAL(aStringLength, stringStringBuilder.length());
    ASSERT_EQUAL(newCapacity, stringStringBuilder.capacity());

    StringBuilder initializerListStringBuilder({u'a', u'b', u'c'});
    ASSERT_EQUAL(3, initializerListStringBuilder.length());
    ASSERT_EQUAL(StringBuilder::defaultCapacity + initializerListStringBuilder.length(), initializerListStringBuilder.capacity());

    CharSequence *charSequence = new String(u8"Hello!");
    StringBuilder charSequenceStringBuilder(*charSequence);
    ASSERT_STR(u8"Hello!", charSequenceStringBuilder.toString());
    String *charSequenceString = dynamic_cast<String *>(charSequence);
    delete charSequenceString;
}

TEST(JavaLang, StringBuilderDestructor) {
    // Destructor will be called automatically.
    StringBuilder stringBuilder;

    // Destructor will be called by delete operator.
    auto *pStringBuilder = new StringBuilder();
    delete pStringBuilder;
}

TEST(JavaLang, StringBuilderAppend) {
    // Array of Character or char
    StringBuilder stringBuilder1;
    Array<char16_t> arrayOfChar({u'1', u'2', u'3'});
    stringBuilder1.append(arrayOfChar);
    ASSERT_STR(u8"123", stringBuilder1.toString());
    Array<Character> arrayOfCharacter({Character(u'4'), Character(u'5'), Character(u'6')});
    stringBuilder1.append(arrayOfCharacter);
    ASSERT_STR(u8"123456", stringBuilder1.toString());

    // String and string
    StringBuilder stringBuilder2;
    String aString = u8"123";
    stringBuilder2.append(aString);
    ASSERT_STR(u8"123", stringBuilder2.toString());
    stringBuilder2.append(u8"456");
    ASSERT_STR(u8"123456", stringBuilder2.toString());

    // Double and double, Float and float, Integer and int, Long and long
    StringBuilder stringBuilder3;
    stringBuilder3.append(Double(0.8));
    ASSERT_STR(u8"0.8", stringBuilder3.toString());
    stringBuilder3.append(0.8);
    ASSERT_STR(u8"0.80.8", stringBuilder3.toString());
    stringBuilder3.append(Float(0.7f));
    ASSERT_STR(u8"0.80.80.7", stringBuilder3.toString());
    stringBuilder3.append(0.7f);
    ASSERT_STR(u8"0.80.80.70.7", stringBuilder3.toString());
    stringBuilder3.append(Integer(10));
    ASSERT_STR(u8"0.80.80.70.710", stringBuilder3.toString());
    stringBuilder3.append(100);
    ASSERT_STR(u8"0.80.80.70.710100", stringBuilder3.toString());
    stringBuilder3.append(Long(1000l));
    ASSERT_STR(u8"0.80.80.70.7101001000", stringBuilder3.toString());
    stringBuilder3.append(1001L);
    ASSERT_STR(u8"0.80.80.70.71010010001001", stringBuilder3.toString());

    // Boolean and boolean
    StringBuilder stringBuilder4;
    stringBuilder4.append(Boolean(true));
    ASSERT_STR(u8"true", stringBuilder4.toString());
    stringBuilder4.append(Boolean(false));
    ASSERT_STR(u8"truefalse", stringBuilder4.toString());
    stringBuilder4.append(true);
    ASSERT_STR(u8"truefalsetrue", stringBuilder4.toString());
    stringBuilder4.append(false);
    ASSERT_STR(u8"truefalsetruefalse", stringBuilder4.toString());

    // Character and char
    StringBuilder stringBuilder5;
    stringBuilder5.append(Character(u'a'));
    stringBuilder5.append(u'b');
    ASSERT_STR(u8"ab", stringBuilder5.toString());

    // Array<Character> and Array<char>
    StringBuilder stringBuilder6("abc");
    stringBuilder6.append(Array<Character> {'1', '2', '3'}, 1, 2);
    ASSERT_STR(u8"abc23", stringBuilder6.toString());
    stringBuilder6.append(Array<char16_t> {'x', 'y', 'z'}, 0, 2);
    ASSERT_STR(u8"abc23xy", stringBuilder6.toString());

    // CharSequence
    CharSequence *charSequence = new String("Hello!");
    StringBuilder stringBuilder7("123");
    ASSERT_STR(u8"123", stringBuilder7.toString());
    stringBuilder7.append(*charSequence);
    ASSERT_STR(u8"123Hello!", stringBuilder7.toString());
    try {
        // start < 0
        stringBuilder7.append(*charSequence, -1, 3);
    }
    catch (IndexOutOfBoundsException &ex){
        ASSERT_STR(u8"", ex.getMessage().toString());
        ASSERT_STR(u8"123Hello!", stringBuilder7.toString());
    }
    try {
        // start > end
        stringBuilder7.append(*charSequence, 4, 3);
    }
    catch (IndexOutOfBoundsException &ex){
        ASSERT_STR(u8"", ex.getMessage().toString());
        ASSERT_STR(u8"123Hello!", stringBuilder7.toString());
    }
    try {
        // end > current length of StringBuilder instance.
        stringBuilder7.append(*charSequence, 4, 999);
    }
    catch (IndexOutOfBoundsException &ex){
        ASSERT_STR(u8"", ex.getMessage().toString());
        ASSERT_STR(u8"123Hello!", stringBuilder7.toString());
    }
    stringBuilder7.append(*charSequence, 1, 3);
    ASSERT_STR(u8"123Hello!el", stringBuilder7.toString());
    String *charSequenceString = dynamic_cast<String *>(charSequence);
    delete charSequenceString;
}

TEST(JavaLang, StringBuilderAppendCodePoint) {
    // TODO
}

TEST(JavaLang, StringBuilderCapacity) {
    StringBuilder stringBuilder(100);
    ASSERT_EQUAL(100, stringBuilder.capacity());
}

TEST(JavaLang, StringBuilderCharAt) {
    StringBuilder stringBuilder({u'a', u'ắ', u'ầ'});
    ASSERT_EQUAL(u'a', stringBuilder.charAt(0));
    ASSERT_EQUAL(u'ắ', stringBuilder.charAt(1));
    ASSERT_EQUAL(u'ầ', stringBuilder.charAt(2));
    try {
        stringBuilder.charAt(999);
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR("999", ex.getMessage().toString());
    }
}

TEST(JavaLang, StringBuilderCodePointAt) {
    // TODO
}

TEST(JavaLang, StringBuilderCodePointBefore) {
    // TODO
}

TEST(JavaLang, StringBuilderCodePointCount) {
    // TODO
}

TEST(JavaLang, StringBuilderDeleteRange) {
    StringBuilder stringBuilder(u8"Quán ăn");
    ASSERT_STR(u8"Quán ăn", stringBuilder.toString());
    try {
        // start < 0
        stringBuilder.deleteRange(-1, 3);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"Quán ăn", stringBuilder.toString());
    }
    try {
        // end < 0
        stringBuilder.deleteRange(1, -1);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"Quán ăn", stringBuilder.toString());
    }
    try {
        // start > end
        stringBuilder.deleteRange(3, 1);
    }
    catch (StringIndexOutOfBoundsException &ex){
        ASSERT_STR(u8"Quán ăn", stringBuilder.toString());
    }
    stringBuilder.deleteRange(1, 3); // valid start, valid end
    ASSERT_STR(u8"Qn ăn", stringBuilder.toString());
    stringBuilder.deleteRange(0, 0);
    ASSERT_STR(u8"Qn ăn", stringBuilder.toString());
    stringBuilder.deleteRange(0, 999);
    ASSERT_STR(u8"", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderDeleteCharAt) {
    StringBuilder stringBuilder("ừGáà nướng lu 1.5 kg");
    ASSERT_STR("ừGáà nướng lu 1.5 kg", stringBuilder.toString());
    stringBuilder.deleteCharAt(0);
    ASSERT_STR("Gáà nướng lu 1.5 kg", stringBuilder.toString());
    stringBuilder.deleteCharAt(1);
    ASSERT_STR("Gà nướng lu 1.5 kg", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderEnsureCapacity) {
    // Default capacity.
    StringBuilder stringBuilder;
    ASSERT_EQUAL(0, stringBuilder.length());
    ASSERT_EQUAL(16, stringBuilder.capacity());
    // New capacity is not positive.
    stringBuilder.ensureCapacity(-1);
    ASSERT_EQUAL(16, stringBuilder.capacity());
    stringBuilder.ensureCapacity(0);
    ASSERT_EQUAL(16, stringBuilder.capacity());
    // New capacity less than current capacity.
    stringBuilder.ensureCapacity(10);
    ASSERT_EQUAL(16, stringBuilder.capacity());
    // New capacity larger than current capacity but less than (2 * current + 2).
    stringBuilder.ensureCapacity(17);
    ASSERT_EQUAL(2 * 16 + 2, stringBuilder.capacity());
    // New capacity larger than current capacity but larger than (2 * current + 2).
    stringBuilder.ensureCapacity(100);
    ASSERT_EQUAL(100, stringBuilder.capacity());
}

TEST(JavaLang, StringBuilderGetChars) {
    // TODO
}

TEST(JavaLang, StringBuilderIndexOf) {
    StringBuilder stringBuilder("Welcome to Vietnam");
    ASSERT_EQUAL(0, stringBuilder.indexOf("Welcome"));
    ASSERT_EQUAL(0, stringBuilder.indexOf(String("Welcome")));
    ASSERT_EQUAL(11, stringBuilder.indexOf("Vietnam"));
    ASSERT_EQUAL(11, stringBuilder.indexOf(String("Vietnam")));
    ASSERT_EQUAL(-1, stringBuilder.indexOf("Hello"));
    ASSERT_EQUAL(-1, stringBuilder.indexOf(String("Hello")));
    stringBuilder.append(" Vietnam");
    ASSERT_STR("Welcome to Vietnam Vietnam", stringBuilder.toString());
    ASSERT_EQUAL(11, stringBuilder.indexOf("Vietnam", 10));
    ASSERT_EQUAL(11, stringBuilder.indexOf(String("Vietnam"), 10));
    ASSERT_EQUAL(11, stringBuilder.indexOf("Vietnam", 11));
    ASSERT_EQUAL(11, stringBuilder.indexOf(String("Vietnam"), 11));
    ASSERT_EQUAL(19, stringBuilder.indexOf("Vietnam", 12));
    ASSERT_EQUAL(19, stringBuilder.indexOf(String("Vietnam"), 12));
    ASSERT_EQUAL(-1, stringBuilder.indexOf("Vietnam", 20));
    ASSERT_EQUAL(-1, stringBuilder.indexOf(String("Vietnam"), 20));
}

TEST(JavaLang, StringBuilderInsert) {
    // String and string
    StringBuilder stringBuilder1(u8"Món:");
    ASSERT_STR(u8"Món:", stringBuilder1.toString());
    try {
        // offset is negative
        stringBuilder1.insert(-1, u8"Đà điểu nướng lu 45 kg");
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"Món:", stringBuilder1.toString());
    }
    try {
        // offset is larger than length of StringBuilder
        stringBuilder1.insert(999, u8"Đà điểu nướng lu 45 kg");
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"Món:", stringBuilder1.toString());
    }
    stringBuilder1.insert(4, u8" ");
    ASSERT_STR(u8"Món: ", stringBuilder1.toString());
    stringBuilder1.insert(5, String("Đà điểu nướng lu 45 kg"));
    ASSERT_STR(u8"Món: Đà điểu nướng lu 45 kg", stringBuilder1.toString());

    // Boolean and boolean
    StringBuilder stringBuilder2(u8"1 = 1 is ");
    stringBuilder2.insert(stringBuilder2.length(), Boolean(true));
    ASSERT_STR(u8"1 = 1 is true", stringBuilder2.toString());
    stringBuilder2.insert(0, false);
    ASSERT_STR(u8"false1 = 1 is true", stringBuilder2.toString());

    // Long and long, Integer and int
    StringBuilder stringBuilder3(u8"0");
    stringBuilder3.insert(1, 1000l);
    ASSERT_STR(u8"01000", stringBuilder3.toString());
    stringBuilder3.insert(1, Long(10l));
    ASSERT_STR(u8"0101000", stringBuilder3.toString());
    stringBuilder3.insert(0, 10);
    ASSERT_STR(u8"100101000", stringBuilder3.toString());
    stringBuilder3.insert(0, Integer(100));
    ASSERT_STR(u8"100100101000", stringBuilder3.toString());

    // Float and float, Double and double
    StringBuilder stringBuilder4(u8"abc");
    stringBuilder4.insert(1, 0.8f);
    ASSERT_STR(u8"a0.8bc", stringBuilder4.toString());
    stringBuilder4.insert(0, 0.7f);
    ASSERT_STR(u8"0.7a0.8bc", stringBuilder4.toString());
    stringBuilder4.insert(0, 0.1);
    ASSERT_STR(u8"0.10.7a0.8bc", stringBuilder4.toString());
    stringBuilder4.insert(1, Double(0.2));
    ASSERT_STR(u8"00.2.10.7a0.8bc", stringBuilder4.toString());

    // Character and char
    StringBuilder stringBuilder5(u8"abc");
    ASSERT_STR(u8"abc", stringBuilder5.toString());
    try {
        // offset < 0
        stringBuilder5.insert(-1, u'x');
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"abc", stringBuilder5.toString());
    }
    try {
        // offset > length of StringBuilder
        stringBuilder5.insert(999, u'x');
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"abc", stringBuilder5.toString());
    }
    stringBuilder5.insert(1, u'x');
    ASSERT_STR(u8"axbc", stringBuilder5.toString());
    try {
        // offset < 0
        stringBuilder5.insert(-1, Character(u'y'));
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"axbc", stringBuilder5.toString());
    }
    try {
        // offset > length of StringBuilder
        stringBuilder5.insert(999, Character(u'y'));
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"axbc", stringBuilder5.toString());
    }
    stringBuilder5.insert(1, Character(u'y'));
    ASSERT_STR(u8"ayxbc", stringBuilder5.toString());

    // Array<Character> and Array<char>
    StringBuilder stringBuilder6(u8"abc");
    stringBuilder6.insert(0, Array<char16_t>{u'1', u'2', u'3'});
    ASSERT_STR(u8"123abc", stringBuilder6.toString());
    stringBuilder6.insert(1, Array<Character> {Character('x'), Character('y'), Character('z')});
    ASSERT_STR(u8"1xyz23abc", stringBuilder6.toString());

    // Sub array of Array<Character> and Array<char>
    StringBuilder stringBuilder7(u8"abc");
    Array<char16_t> anArray1 {u'1', u'2', u'3'};
    ASSERT_STR(u8"abc", stringBuilder7.toString());
    try {
        // index < 0
        stringBuilder7.insert(-1, anArray1, 1, 2);
    }
    catch (StringIndexOutOfBoundsException &ex){
        ASSERT_STR(u8"abc", stringBuilder7.toString());
    }
    try {
        // index > currentLength
        stringBuilder7.insert(999, anArray1, 1, 2);
    }
    catch (StringIndexOutOfBoundsException &ex){
        ASSERT_STR(u8"abc", stringBuilder7.toString());
    }
    try {
        // offset < 0
        stringBuilder7.insert(1, anArray1, -1, 2);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"abc", stringBuilder7.toString());
    }
    try {
        // length < 0
        stringBuilder7.insert(1, anArray1, 1, -1);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"abc", stringBuilder7.toString());
    }
    try {
        // offset + length > lengthOfArray
        stringBuilder7.insert(1, anArray1, 1, 100);
    }
    catch (StringIndexOutOfBoundsException &ex){
        ASSERT_STR(u8"abc", stringBuilder7.toString());
    }
    stringBuilder7.insert(1, anArray1, 1, 2); // valid index, offset, length
    ASSERT_STR(u8"a23bc", stringBuilder7.toString());
    Array<Character> anArray2 {Character(u'x'), Character(u'y'), Character(u'z')};
    try {
        // index < 0
        stringBuilder7.insert(-1, anArray2 , 1, 1);
    }
    catch (StringIndexOutOfBoundsException &ex){
        ASSERT_STR(u8"a23bc", stringBuilder7.toString());
    }
    try {
        // index > currentLength
        stringBuilder7.insert(999, anArray2 , 1, 1);
    }
    catch (StringIndexOutOfBoundsException &ex){
        ASSERT_STR(u8"a23bc", stringBuilder7.toString());
    }
    try {
        // offset < 0
        stringBuilder7.insert(1, anArray2 , -1, 1);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"a23bc", stringBuilder7.toString());
    }
    try {
        // length < 0
        stringBuilder7.insert(1, anArray2 , 1, -1);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"a23bc", stringBuilder7.toString());
    }
    try {
        // offset + length > lengthOfArray
        stringBuilder7.insert(1, anArray2 , 1, 999);
    }
    catch (StringIndexOutOfBoundsException &ex){
        ASSERT_STR(u8"a23bc", stringBuilder7.toString());
    }
    stringBuilder7.insert(1, anArray2 , 1, 1); // valid index, offset, length
    ASSERT_STR(u8"ay23bc", stringBuilder7.toString());

    // CharSequence
    StringBuilder stringBuilder8(u8"abc");
    ASSERT_STR(u8"abc", stringBuilder8.toString());
    auto *charSequence = (CharSequence *)new String(u8"xyz");
    stringBuilder8.insert(1, *charSequence);
    ASSERT_STR(u8"axyzbc", stringBuilder8.toString());

    try {
        // destinationOffset < 0
        stringBuilder8.insert(-1, *charSequence, 1, 1);
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"axyzbc", stringBuilder8.toString());
    }
    try {
        // destinationOffset > length of this StringBuilder
        stringBuilder8.insert(999, *charSequence, 1, 1);
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"axyzbc", stringBuilder8.toString());
    }
    try {
        // start < 0
        stringBuilder8.insert(1, *charSequence, -1, 1);
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"axyzbc", stringBuilder8.toString());
    }
    try {
        // end < 0
        stringBuilder8.insert(1, *charSequence, 1, -1);
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"axyzbc", stringBuilder8.toString());
    }
    try {
        // start > end
        stringBuilder8.insert(1, *charSequence, 2, 1);
    }
    catch (IndexOutOfBoundsException &ex) {
        ASSERT_STR(u8"axyzbc", stringBuilder8.toString());
    }
    try {
        // end > length of target (charSequence)
        stringBuilder8.insert(1, *charSequence, 1, 999);
    }
    catch (IndexOutOfBoundsException &ex){
        ASSERT_STR(u8"axyzbc", stringBuilder8.toString());
    }
    stringBuilder8.insert(1, *charSequence, 1, 1);
    ASSERT_STR(u8"axyzbc", stringBuilder8.toString());
    stringBuilder8.insert(1, *charSequence, 1, 2);
    ASSERT_STR(u8"ayxyzbc", stringBuilder8.toString());
    stringBuilder8.insert(1, *charSequence, 1, 3);
    ASSERT_STR(u8"ayzyxyzbc", stringBuilder8.toString());
    auto *charSequenceString = dynamic_cast<String *>(charSequence); // FIXME: Must use this 'dynamic_cast' operator because CharSequence class doesn't have virtual destructor.
    delete charSequenceString;
}

TEST(JavaLang, StringBuilderLastIndexOf) {
    StringBuilder stringBuilder(u8"Welcome to Vietnam");
    ASSERT_STR(u8"Welcome to Vietnam", stringBuilder.toString());
    ASSERT_EQUAL(11, stringBuilder.lastIndexOf(u8"Vietnam"));
    ASSERT_EQUAL(11, stringBuilder.lastIndexOf(String(u8"Vietnam")));
    ASSERT_EQUAL(0, stringBuilder.lastIndexOf(u8"Welcome"));
    ASSERT_EQUAL(0, stringBuilder.lastIndexOf(String(u8"Welcome")));
    ASSERT_EQUAL(-1, stringBuilder.lastIndexOf(u8"Vietnam", 11));
    ASSERT_EQUAL(-1, stringBuilder.lastIndexOf(String(u8"Vietnam"), 11));
    ASSERT_EQUAL(-1, stringBuilder.lastIndexOf(u8"Vietnam", 12));
    ASSERT_EQUAL(-1, stringBuilder.lastIndexOf(String(u8"Vietnam"), 12));
    ASSERT_EQUAL(11, stringBuilder.lastIndexOf(u8"Vietnam", stringBuilder.length()));
    ASSERT_EQUAL(11, stringBuilder.lastIndexOf(String(u8"Vietnam"), stringBuilder.length()));
}

TEST(JavaLang, StringBuilderLength) {
    String stringBuilder(u8"Hello! I'm a String");
    ASSERT_EQUAL(19, stringBuilder.length());

    StringBuilder utf8StringBuilder(u8"Việt Nam");
    ASSERT_EQUAL(8, utf8StringBuilder.length());
}

TEST(JavaLang, StringBuilderReplace) {
    StringBuilder stringBuilder(u8"ABCXYZ");
    ASSERT_STR(u8"ABCXYZ", stringBuilder.toString());
    stringBuilder.replace(1, 2, u8"123");
    ASSERT_STR(u8"A123CXYZ", stringBuilder.toString());
    stringBuilder.replace(0, 100, String(u8"Clear!"));
    ASSERT_STR(u8"Clear!", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderReverse) {
    StringBuilder stringBuilder1(u8"ABCXYZ");
    stringBuilder1.reverse();
    ASSERT_STR(u8"ZYXCBA", stringBuilder1.toString());

    // Reverses all valid surrogate pairs are produced in reverse process.
    StringBuilder stringBuilder2(u8"\u000DC00\u000D800");
    ASSERT_STR(u8"\u000DC00\u000D800", stringBuilder2.toString());
    stringBuilder1.reverse();
    ASSERT_STR(u8"\u000DC00\u000D800", stringBuilder2.toString());
}

TEST(JavaLang, StringBuilderSetCharAt) {
    StringBuilder stringBuilder(u8"Xuxn phở");
    ASSERT_STR(u8"Xuxn phở", stringBuilder.toString());
    stringBuilder.setCharAt(0, u'Q');
    ASSERT_STR(u8"Quxn phở", stringBuilder.toString());
    stringBuilder.setCharAt(2, Character(u'á'));
    ASSERT_STR(u8"Quán phở", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderSetLength) {
    StringBuilder stringBuilder(u8"Hello! I'm a StringBuilder");
    ASSERT_STR(u8"Hello! I'm a StringBuilder", stringBuilder.toString());
    ASSERT_EQUAL(26, stringBuilder.length());
    stringBuilder.setLength(30);
    ASSERT_EQUAL(30, stringBuilder.length());
    ASSERT_STR(u8"Hello! I'm a StringBuilder", stringBuilder.toString());
    stringBuilder.setLength(6);
    ASSERT_EQUAL(6, stringBuilder.length());
    ASSERT_STR(u8"Hello!", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderSubString) {
    StringBuilder stringBuilder(u8"Hello Vietnam");
    ASSERT_STR(u8"Vietnam", stringBuilder.substring(6).toString());
    ASSERT_STR(u8"llo", stringBuilder.substring(2, 5).toString());
    try {
        stringBuilder.substring(-999);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        ASSERT_STR("String index out of range: -999", ex.getMessage().toString());
    }
}

TEST(JavaLang, StringBuilderToString) {
    String aString = u8"Hello!";
    StringBuilder stringBuilder(aString.toString());
    ASSERT_STR(aString.toString(), stringBuilder.toString());
}

TEST(JavaLang, StringBuilderTrimToSize) {
    StringBuilder stringBuilder(100);
    ASSERT_EQUAL(100, stringBuilder.capacity());
    stringBuilder.trimToSize();
    ASSERT_EQUAL(0, stringBuilder.capacity());
    stringBuilder.append(u8"123");
    stringBuilder.trimToSize();
    ASSERT_EQUAL(3, stringBuilder.capacity());
}
