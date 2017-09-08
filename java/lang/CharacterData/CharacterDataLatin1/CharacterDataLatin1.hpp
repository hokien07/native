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

//
// Created by razor on 08/09/2017.
//

#ifndef NATIVE_CHARACTERDATALATIN1_HPP
#define NATIVE_CHARACTERDATALATIN1_HPP


#include "../CharacterData.hpp"

namespace Java {
    namespace Lang {
        class CharacterDataLatin1 : public virtual CharacterData {
        private:
            // The A table has 256 entries for a total of 1024 bytes.
            static Array<int> A;

            // Data for A table
            static Array<char16_t> A_DATA;

            // The B table has 256 entries for a total of 512 bytes.
            static Array<char16_t> B;

            // sharpMap
            static Array<char16_t> sharpsMap;
        public:
            static CharacterDataLatin1 instance;

        private:
            CharacterDataLatin1() = default;

            static Array<int> initA();

        public:
            int getProperties(int character) override;

            int getPropertiesEx(int character);

            int getType(int character) override;

            boolean isOtherLowercase(int character) override;

            boolean isOtherUppercase(int character) override;

            boolean isOtherAlphabetic(int character) override;

            boolean isIdeographic(int character) override;

            boolean isJavaIdentifierStart(int character) override;

            boolean isJavaIdentifierPart(int character) override;

            boolean isUnicodeIdentifierStart(int character) override;

            boolean isUnicodeIdentifierPart(int character) override;

            boolean isIdentifierIgnorable(int character) override;

            int toLowerCase(int character) override;

            int toUpperCase(int character) override;

            int toTitleCase(int character) override;

            int digit(int character, int radix) override;

            int getNumericValue(int character) override;

            boolean isWhitespace(int character) override;

            int getDirectionality(int character) override;

            boolean isMirrored(int character) override;

            Array<char16_t> toUpperCaseCharArray(int character) override;
        };
    }
}


#endif //NATIVE_CHARACTERDATALATIN1_HPP
//int getProperties(int ch) {

//}
//
//int getPropertiesEx(int ch) {

//}
//
//boolean isOtherLowercase(int ch) {

//}
//
//boolean isOtherUppercase(int ch) {

//}
//
//boolean isOtherAlphabetic(int ch) {

//}
//
//boolean isIdeographic(int ch) {

//}
//
//int getType(int ch) {

//}
//
//boolean isJavaIdentifierStart(int ch) {
//    int props = getProperties(ch);
//    return ((props & 0x00007000) >= 0x00005000);
//}
//
//boolean isJavaIdentifierPart(int ch) {
//    int props = getProperties(ch);
//    return ((props & 0x00003000) != 0);
//}
//
//boolean isUnicodeIdentifierStart(int ch) {
//    int props = getProperties(ch);
//    return ((props & 0x00007000) == 0x00007000);
//}
//
//boolean isUnicodeIdentifierPart(int ch) {
//    int props = getProperties(ch);
//    return ((props & 0x00001000) != 0);
//}
//
//boolean isIdentifierIgnorable(int ch) {
//    int props = getProperties(ch);
//    return ((props & 0x00007000) == 0x00001000);
//}
//
//int toLowerCase(int ch) {
//    int mapChar = ch;
//    int val = getProperties(ch);
//
//    if (((val & 0x00020000) != 0) &&
//        ((val & 0x07FC0000) != 0x07FC0000)) {
//        int offset = val << 5 >> (5+18);
//        mapChar = ch + offset;
//    }
//    return mapChar;
//}
//
//int toUpperCase(int ch) {
//    int mapChar = ch;
//    int val = getProperties(ch);
//
//    if ((val & 0x00010000) != 0) {
//        if ((val & 0x07FC0000) != 0x07FC0000) {
//            int offset = val  << 5 >> (5+18);
//            mapChar =  ch - offset;
//        } else if (ch == 0x00B5) {
//            mapChar = 0x039C;
//        }
//    }
//    return mapChar;
//}
//
//int toTitleCase(int ch) {
//    return toUpperCase(ch);
//}
//
//int digit(int ch, int radix) {
//    int value = -1;
//    if (radix >= Character.MIN_RADIX && radix <= Character.MAX_RADIX) {
//        int val = getProperties(ch);
//        int kind = val & 0x1F;
//        if (kind == Character.DECIMAL_DIGIT_NUMBER) {
//            value = ch + ((val & 0x3E0) >> 5) & 0x1F;
//        }
//        else if ((val & 0xC00) == 0x00000C00) {
//            // Java supradecimal digit
//            value = (ch + ((val & 0x3E0) >> 5) & 0x1F) + 10;
//        }
//    }
//    return (value < radix) ? value : -1;
//}
//
//int getNumericValue(int ch) {
//    int val = getProperties(ch);
//    int retval = -1;
//
//    switch (val & 0xC00) {
//        default: // cannot occur
//        case (0x00000000):         // not numeric
//            retval = -1;
//            break;
//        case (0x00000400):              // simple numeric
//            retval = ch + ((val & 0x3E0) >> 5) & 0x1F;
//            break;
//        case (0x00000800)      :       // "strange" numeric
//            retval = -2;
//            break;
//        case (0x00000C00):           // Java supradecimal
//            retval = (ch + ((val & 0x3E0) >> 5) & 0x1F) + 10;
//            break;
//    }
//    return retval;
//}
//
//boolean isWhitespace(int ch) {
//    int props = getProperties(ch);
//    return ((props & 0x00007000) == 0x00004000);
//}
//
//byte getDirectionality(int ch) {
//    int val = getProperties(ch);
//    byte directionality = (byte)((val & 0x78000000) >> 27);
//
//    if (directionality == 0xF ) {
//        directionality = -1;
//    }
//    return directionality;
//}
//
//boolean isMirrored(int ch) {
//    int props = getProperties(ch);
//    return ((props & 0x80000000) != 0);
//}
//
//int toUpperCaseEx(int ch) {
//    int mapChar = ch;
//    int val = getProperties(ch);
//
//    if ((val & 0x00010000) != 0) {
//        if ((val & 0x07FC0000) != 0x07FC0000) {
//            int offset = val  << 5 >> (5+18);
//            mapChar =  ch - offset;
//        }
//        else {
//            switch(ch) {
//                // map overflow characters
//                case 0x00B5 : mapChar = 0x039C; break;
//                default       : mapChar = Character.ERROR; break;
//            }
//        }
//    }
//    return mapChar;
//}
//
//static char[] sharpsMap = new char[] {'S', 'S'};
//
//char[] toUpperCaseCharArray(int ch) {
//    char[] upperMap = {(char)ch};
//    if (ch == 0x00DF) {
//        upperMap = sharpsMap;
//    }
//    return upperMap;
//}
//
//static final CharacterDataLatin1 instance = new CharacterDataLatin1();
//private CharacterDataLatin1() {};
//
//// The following tables and code generated using:
//// java GenerateCharacter -template /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/jdk/make/data/characterdata/CharacterDataLatin1.java.template -spec /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/jdk/make/data/unicodedata/UnicodeData.txt -specialcasing /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/jdk/make/data/unicodedata/SpecialCasing.txt -proplist /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/jdk/make/data/unicodedata/PropList.txt -o /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/build/linux-amd64/jdk/gensrc/java/lang/CharacterDataLatin1.java -string -usecharforbyte -latin1 8
//
//static final int A[] = new int[256];
//static final String A_DATA =
//
//
//static final char B[] = (

//
//// In all, the character property tables require 1024 bytes.
//
//static {
//{ // THIS CODE WAS AUTOMATICALLY CREATED BY GenerateCharacter:
//char[] data = A_DATA.toCharArray();
//assert (data.length == (256 * 2));
//int i = 0, j = 0;
//while (i < (256 * 2)) {
//int entry = data[i++] << 16;
//A[j++] = entry | data[i++];
//}
//}
//
//}