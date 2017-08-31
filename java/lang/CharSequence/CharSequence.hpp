/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ArNY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef JAVA_LANG_CHAR_SEQUENCE_HPP_
#define JAVA_LANG_CHAR_SEQUENCE_HPP_

#include "../Object/Object.hpp"

typedef char16_t unicode;

namespace Java {
	namespace Lang {
		class CharSequence {
		public:
            /**
             * Returns a string containing the characters in this sequence
             * in the same order as this sequence.
             * The length of the string will be the length of this sequence.
             *
             * @return string
             */
            virtual string toString() const = 0;

            /**
             * Returns the char value at the specified index.
             *
             * @param index
             * @return char16_t
             */
            virtual unicode charAt(int index) const = 0;

            /**
             * Returns the length of this character sequence.
             * The length is the number of 16-bit chars in the sequence.
             *
             * @return int
             */
            virtual int length() const = 0;
		};  // class CharSequence
	}  // namespace Lang
}  // namespace Java

#endif  // JAVA_LANG_CHAR_SEQUENCE_HPP_
