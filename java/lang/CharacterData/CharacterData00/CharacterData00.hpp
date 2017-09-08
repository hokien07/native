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
// Created by razor on 01/09/2017.
//

#ifndef NATIVE_CHARACTERDATA00_HPP
#define NATIVE_CHARACTERDATA00_HPP

#include "../../../Lang.hpp"
#include "../CharacterData.hpp"

namespace Java {
    namespace Lang {
        class CharacterData00 : public virtual CharacterData {
        private:
            // The following tables and code generated using:
            // java GenerateCharacter -plane 0 -template /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/jdk/make/data/characterdata/CharacterData00.java.template -spec /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/jdk/make/data/unicodedata/UnicodeData.txt -specialcasing /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/jdk/make/data/unicodedata/SpecialCasing.txt -proplist /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/jdk/make/data/unicodedata/PropList.txt -o /HUDSON3/workspace/8-2-build-linux-amd64/jdk8u144/9417/build/linux-amd64/jdk/gensrc/java/lang/CharacterData00.java -string -usecharforbyte 11 4 1
            // In all, the character property tables require 19144 bytes.
            static char16_t charMap [][2][3];
            //// The X table has 2048 entries for a total of 4096 bytes.
            //
            static Array<char16_t> X;
            //            // The Y table has 5664 entries for a total of 11328 bytes.
            //
            static Array<char16_t> Y;

            // The A table has 930 entries for a total of 3720 bytes.
            static Array<int> A;

            static Array<char16_t> A_DATA;

            // The B table has 930 entries for a total of 1860 bytes.
            static Array<char16_t> B;
        public:
            static CharacterData00 instance;

        private:
            CharacterData00() = default;



            /**
             * Finds the character in the uppercase mapping table.
             *
             * @param character
             * @return the index location ch in the table or -1 if not found
             */
            int findInCharMap(int character);

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

            int toUpperCaseEx(int character) override;

            Array<char16_t> toUpperCaseCharArray(int character) override;
        };
    }
}


#endif //NATIVE_CHARACTERDATA00_HPP


