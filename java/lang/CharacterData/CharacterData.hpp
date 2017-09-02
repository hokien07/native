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

#ifndef NATIVE_CHARACTERDATA_HPP
#define NATIVE_CHARACTERDATA_HPP

#include "../../Lang.hpp"

namespace Java {
    namespace Lang {
        class CharacterData{

        public:
            virtual int getProperties(int character) = 0;
            virtual int getType(int character) = 0;
            virtual boolean isWhitespace(int character) = 0;
            virtual boolean isMirrored(int character) = 0;
            virtual boolean isJavaIdentifierStart(int character) = 0;
            virtual boolean isJavaIdentifierPart(int character) = 0;
            virtual boolean isUnicodeIdentifierStart(int character) = 0;
            virtual boolean isUnicodeIdentifierPart(int character) = 0;
            virtual boolean isIdentifierIgnorable(int character) = 0;
            virtual int toLowerCase(int character) = 0;
            virtual int toUpperCase(int character) = 0;
            virtual int toTitleCase(int character) = 0;
            virtual int digit(int character, int radix) = 0;
            virtual int getNumericValue(int character) = 0;
            virtual char16_t getDirectionality(int character) = 0;

            //need to implement for JSR204
            virtual int toUpperCaseEx(int character) = 0;
            virtual Array<char16_t> toUpperCaseCharArray(int character) = 0;
            virtual boolean isOtherLowercase(int character) = 0;
            virtual boolean isOtherUppercase(int character) = 0;
            virtual boolean isOtherAlphabetic(int character) = 0;
            virtual boolean isIdeographic(int character) = 0;

            // Character <= 0xff (basic latin) is handled by internal fast-path
            // to avoid initializing large tables.
            // Note: performance of this "fast-path" code may be sub-optimal
            // in negative cases for some accessors due to complicated ranges.
            // Should revisit after optimization of table initialization.

            /*static CharacterData &of(int character) {

                if (character >> 8 == 0) {     // fast-path
                    return CharacterDataLatin1.instance;
                } else {
                    switch (character >> 16) {  //plane 00-16
                        case(0):
                            return CharacterData00.instance;
                        case(1):
                            return CharacterData01.instance;
                        case(2):
                            return CharacterData02.instance;
                        case(14):
                            return CharacterData0E.instance;
                        case(15):   // Private Use
                        case(16):   // Private Use
                            return CharacterDataPrivateUse.instance;
                        default:
                            return CharacterDataUndefined.instance;
                    }
                }
            }*/
        };
    }
}
#endif //NATIVE_CHARACTERDATA_HPP
