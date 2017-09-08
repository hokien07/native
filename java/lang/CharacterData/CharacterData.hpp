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

using namespace Java::Lang;

namespace Java {
    namespace Lang {

        class CharacterData {
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
            virtual int toUpperCaseEx(int character) {
                return toUpperCase(character);
            }

            virtual Array<char16_t> toUpperCaseCharArray(int character) {
                return Array<char16_t>();
            }

            virtual boolean isOtherLowercase(int character) {
                return false;
            }

            virtual boolean isOtherUppercase(int character) {
                return false;
            }

            virtual boolean isOtherAlphabetic(int character) {
                return false;
            }

            virtual boolean isIdeographic(int character) {
                return false;
            }
        };
    }
}
#endif //NATIVE_CHARACTERDATA_HPP
