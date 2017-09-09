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

#ifndef NATIVE_CHARACTERDATAUNDEFINED_HPP
#define NATIVE_CHARACTERDATAUNDEFINED_HPP


#include "../CharacterData.hpp"

namespace Java {
    namespace Lang {
        class CharacterDataUndefined : public virtual CharacterData {
        public:
            static CharacterDataUndefined instance;

        private:
            CharacterDataUndefined() = default;

        public:
            int getProperties(int character) override;

            int getType(int character) override;

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
        };
    }
}



#endif //NATIVE_CHARACTERDATAUNDEFINED_HPP
