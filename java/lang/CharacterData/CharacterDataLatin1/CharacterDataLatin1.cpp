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
 * AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
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

#include "CharacterDataLatin1.hpp"

CharacterDataLatin1 CharacterDataLatin1::instance = CharacterDataLatin1();

Array<char16_t> CharacterDataLatin1::A_DATA = {
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800',
        u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F',
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u5800', u'\u400F', u'\u5000',
        u'\u400F', u'\u5800', u'\u400F', u'\u6000', u'\u400F', u'\u5000', u'\u400F',
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800',
        u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F',
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800',
        u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F',
        u'\u5000', u'\u400F', u'\u5000', u'\u400F', u'\u5000', u'\u400F', u'\u5800',
        u'\u400F', u'\u6000', u'\u400C', u'\u6800', u'\030', u'\u6800', u'\030',
        u'\u2800', u'\030', u'\u2800', u'\u601A', u'\u2800', u'\030', u'\u6800',
        u'\030', u'\u6800', u'\030', u'\uE800', u'\025', u'\uE800', u'\026', u'\u6800',
        u'\030', u'\u2000', u'\031', u'\u3800', u'\030', u'\u2000', u'\024', u'\u3800',
        u'\030', u'\u3800', u'\030', u'\u1800', u'\u3609', u'\u1800', u'\u3609',
        u'\u1800', u'\u3609', u'\u1800', u'\u3609', u'\u1800', u'\u3609', u'\u1800',
        u'\u3609', u'\u1800', u'\u3609', u'\u1800', u'\u3609', u'\u1800', u'\u3609',
        u'\u1800', u'\u3609', u'\u3800', u'\030', u'\u6800', u'\030', u'\uE800',
        u'\031', u'\u6800', u'\031', u'\uE800', u'\031', u'\u6800', u'\030', u'\u6800',
        u'\030', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202',
        u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202',
        u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202',
        u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202',
        u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202',
        u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\202',
        u'\u7FE1', u'\202', u'\u7FE1', u'\202', u'\u7FE1', u'\uE800', u'\025',
        u'\u6800', u'\030', u'\uE800', u'\026', u'\u6800', u'\033', u'\u6800',
        u'\u5017', u'\u6800', u'\033', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201',
        u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201',
        u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201',
        u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201',
        u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201',
        u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201',
        u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2', u'\201', u'\u7FE2',
        u'\uE800', u'\025', u'\u6800', u'\031', u'\uE800', u'\026', u'\u6800', u'\031',
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800',
        u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u5000', u'\u100F',
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800',
        u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F',
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800',
        u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F',
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800',
        u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F',
        u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800', u'\u100F', u'\u4800',
        u'\u100F', u'\u4800', u'\u100F', u'\u3800', u'\014', u'\u6800', u'\030',
        u'\u2800', u'\u601A', u'\u2800', u'\u601A', u'\u2800', u'\u601A', u'\u2800',
        u'\u601A', u'\u6800', u'\034', u'\u6800', u'\030', u'\u6800', u'\033',
        u'\u6800', u'\034', u'\000', u'\u7005', u'\uE800', u'\035', u'\u6800', u'\031',
        u'\u4800', u'\u1010', u'\u6800', u'\034', u'\u6800', u'\033', u'\u2800',
        u'\034', u'\u2800', u'\031', u'\u1800', u'\u060B', u'\u1800', u'\u060B',
        u'\u6800', u'\033', u'\u07FD', u'\u7002', u'\u6800', u'\030', u'\u6800',
        u'\030', u'\u6800', u'\033', u'\u1800', u'\u050B', u'\000', u'\u7005',
        u'\uE800', u'\036', u'\u6800', u'\u080B', u'\u6800', u'\u080B', u'\u6800',
        u'\u080B', u'\u6800', u'\030', u'\202', u'\u7001', u'\202', u'\u7001', u'\202',
        u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202',
        u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202',
        u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202',
        u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202',
        u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202',
        u'\u7001', u'\u6800', u'\031', u'\202', u'\u7001', u'\202', u'\u7001', u'\202',
        u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202', u'\u7001', u'\202',
        u'\u7001', u'\u07FD', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002',
        u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002',
        u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002',
        u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002',
        u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002',
        u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002',
        u'\201', u'\u7002', u'\u6800', u'\031', u'\201', u'\u7002', u'\201', u'\u7002',
        u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002', u'\201', u'\u7002',
        u'\201', u'\u7002', u'\u061D', u'\u7002'
};

Array<char16_t> CharacterDataLatin1::B = {
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\001', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\001', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000',
        u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000', u'\000'
};

Array<char16_t> CharacterDataLatin1::sharpsMap = {'S', 'S'};

Array<int> CharacterDataLatin1::initA() {
    Array<int> result;
    int i = 0;
    while (i < (256 * 2)) {
        int entry = A_DATA[i++] << 16;
        result.push(entry | A_DATA[i++]);
    }
    return result;
}

Array<int> CharacterDataLatin1::A = initA();

int CharacterDataLatin1::getProperties(int character) {
    auto offset = (char) character;
    int properties = A[offset];
    return properties;}

int CharacterDataLatin1::getPropertiesEx(int character) {
    auto offset = (char) character;
    int properties = B[offset];
    return properties;}

int CharacterDataLatin1::getType(int character) {
    int properties = getProperties(character);
    return (properties & 0x1F);
}

boolean CharacterDataLatin1::isOtherLowercase(int character) {
    int properties = getPropertiesEx(character);
    return (properties & 0x0001) != 0;}

boolean CharacterDataLatin1::isOtherUppercase(int character) {
    int properties = getPropertiesEx(character);
    return (properties & 0x0002) != 0;}

boolean CharacterDataLatin1::isOtherAlphabetic(int character) {
    int properties = getPropertiesEx(character);
    return (properties & 0x0004) != 0;
 }

boolean CharacterDataLatin1::isIdeographic(int character) {
    int properties = getPropertiesEx(character);
    return (properties & 0x0010) != 0;}

boolean CharacterDataLatin1::isJavaIdentifierStart(int character) {
    int properties = getProperties(character);
    return ((properties & 0x00007000) >= 0x00005000);}

boolean CharacterDataLatin1::isJavaIdentifierPart(int character) {
    int properties = getProperties(character);
    return ((properties & 0x00003000) != 0);
}

boolean CharacterDataLatin1::isUnicodeIdentifierStart(int character) {
    int properties = getProperties(character);
    return ((properties & 0x00007000) == 0x00007000);
}

boolean CharacterDataLatin1::isUnicodeIdentifierPart(int character) {
    int properties = getProperties(character);
    return ((properties & 0x00001000) != 0);
}

boolean CharacterDataLatin1::isIdentifierIgnorable(int character) {
    int properties = getProperties(character);
    return ((properties & 0x00007000) == 0x00001000);
}

int CharacterDataLatin1::toLowerCase(int character) {
    int mapChar = character;
    int val = getProperties(character);

    if (((val & 0x00020000) != 0) &&
        ((val & 0x07FC0000) != 0x07FC0000)) {
        int offset = val << 5 >> (5+18);
        mapChar = character + offset;
    }
    return mapChar;}

int CharacterDataLatin1::toUpperCase(int character) {
    int mapChar = character;
    int val = getProperties(character);

    if ((val & 0x00010000) != 0) {
        if ((val & 0x07FC0000) != 0x07FC0000) {
            int offset = val  << 5 >> (5+18);
            mapChar =  character - offset;
        } else if (character == 0x00B5) {
            mapChar = 0x039C;
        }
    }
    return mapChar;}

int CharacterDataLatin1::toTitleCase(int character) {
    return toUpperCase(character);
}

int CharacterDataLatin1::digit(int character, int radix) {
    int value = -1;
    if (radix >= Character::MIN_RADIX && radix <= Character::MAX_RADIX) {
        int val = getProperties(character);
        int kind = val & 0x1F;
        if (kind == Character::DECIMAL_DIGIT_NUMBER) {
            value = character + ((val & 0x3E0) >> 5) & 0x1F;
        }
        else if ((val & 0xC00) == 0x00000C00) {
            // Java supradecimal digit
            value = (character + ((val & 0x3E0) >> 5) & 0x1F) + 10;
        }
    }
    return (value < radix) ? value : -1;}

int CharacterDataLatin1::getNumericValue(int character) {
    int val = getProperties(character);
    int retValue = -1;

    switch (val & 0xC00) {
        default: // cannot occur
        case (0x00000000):         // not numeric
            retValue = -1;
            break;
        case (0x00000400):              // simple numeric
            retValue = character + ((val & 0x3E0) >> 5) & 0x1F;
            break;
        case (0x00000800)      :       // "strange" numeric
            retValue = -2;
            break;
        case (0x00000C00):           // Java supradecimal
            retValue = (character + ((val & 0x3E0) >> 5) & 0x1F) + 10;
            break;
    }
    return retValue;
}

boolean CharacterDataLatin1::isWhitespace(int character) {
    int properties = getProperties(character);
    return ((properties & 0x00007000) == 0x00004000);}

int CharacterDataLatin1::getDirectionality(int character) {
    int val = getProperties(character);
    int directionality = (byte)((val & 0x78000000) >> 27);

    if (directionality == 0xF ) {
        directionality = -1;
    }
    return directionality;
}

boolean CharacterDataLatin1::isMirrored(int character) {
    int properties = getProperties(character);
    return ((properties & 0x80000000) != 0);
}

Array<char16_t> CharacterDataLatin1::toUpperCaseCharArray(int character) {
    Array<char16_t> upperMap = {(char) character};
    if (character == 0x00DF) {
        upperMap = sharpsMap;
    }
    return upperMap;
}



