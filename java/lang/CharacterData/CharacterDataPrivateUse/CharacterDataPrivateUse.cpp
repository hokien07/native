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

#include "CharacterDataPrivateUse.hpp"

CharacterDataPrivateUse CharacterDataPrivateUse::instance = CharacterDataPrivateUse();

int CharacterDataPrivateUse::getProperties(int character) {
    return 0;
}

int CharacterDataPrivateUse::getType(int character) {
    if ((character & 0xFFFE) == 0xFFFE) {
        return Character::UNASSIGNED;
    }
    return Character::PRIVATE_USE;
}

boolean CharacterDataPrivateUse::isJavaIdentifierStart(int character) {
    return false;
}

boolean CharacterDataPrivateUse::isJavaIdentifierPart(int character) {
    return false;
}

boolean CharacterDataPrivateUse::isUnicodeIdentifierStart(int character) {
    return false;
}

boolean CharacterDataPrivateUse::isUnicodeIdentifierPart(int character) {
    return false;
}

boolean CharacterDataPrivateUse::isIdentifierIgnorable(int character) {
    return false;
}

int CharacterDataPrivateUse::toLowerCase(int character) {
    return character;
}

int CharacterDataPrivateUse::toUpperCase(int character) {
    return character;
}

int CharacterDataPrivateUse::toTitleCase(int character) {
    return character;
}

int CharacterDataPrivateUse::digit(int character, int radix) {
    return -1;
}

int CharacterDataPrivateUse::getNumericValue(int character) {
    return -1;
}

boolean CharacterDataPrivateUse::isWhitespace(int character) {
    return false;
}

int CharacterDataPrivateUse::getDirectionality(int character) {
    if ((character & 0xFFFE) == 0xFFFE) {
        return Character::DIRECTIONALITY_UNDEFINED;
    }
    return Character::DIRECTIONALITY_LEFT_TO_RIGHT;
}

boolean CharacterDataPrivateUse::isMirrored(int character) {
    return false;
}
