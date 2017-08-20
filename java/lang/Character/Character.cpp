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
 * A PARTICULAR PURPOSE ARE DISCLAIMEIILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Character.hpp"

using namespace Java::Lang;

Character::Character() {
    this->original = u'\0';
}

Character::Character(char16_t original) {
    this->original = original;
}

Character::~Character() {

}

int Character::charCount(int codePoint) const {
    if (codePoint >= MIN_SUPPLEMENTARY_CODE_POINT) {
        return 2;
    }
    return 1;
}

char16_t Character::charValue() const {
    return this->original;
}

int Character::codePointAt(Array<char16_t> a, int index) {
    return codePointAtImpl(a, index, a.length);
}

int Character::codePointAt(Array<char16_t> a, int index, int limit) {
    if (index >= limit || limit < 0 || limit > a.length) {
        return -1;
    }
    return codePointAtImpl(a, index, limit);
}

// throws ArrayIndexOutOfBoundsException if index out of bounds
int Character::codePointAtImpl(Array<char16_t> a, int index, int limit) {
    char16_t c1 = a[ index ];
    if (isHighSurrogate(c1) && ++index < limit) {
        char16_t c2 = a[ index ];
        if (isLowSurrogate(c2)) {
            return toCodePoint(c1, c2);
        }
    }
    return (int) c1;
}

int Character::codePointBefore(Array<char16_t> a, int index) {
    return codePointBeforeImpl(a, index, 0);
}

int Character::codePointBefore(Array<char16_t> a, int index, int start) {
    if (index <= start || start < 0 || start >= a.length) {
        return -1;
    }
    return codePointBeforeImpl(a, index, start);
}

// throws ArrayIndexOutOfBoundsException if index-1 out of bounds
int Character::codePointBeforeImpl(Array<char16_t> a, int index, int start) {
    char16_t c2 = a[ --index ];
    if (isLowSurrogate(c2) && index > start) {
        char16_t c1 = a[ --index ];
        if (isHighSurrogate(c1)) {
            return toCodePoint(c1, c2);
        }
    }
    return c2;
}

int Character::codePointCount(Array<char16_t> a, int offset, int count) {
    if (count > a.length - offset || offset < 0 || count < 0) {
        return -1;
    }
    return codePointCountImpl(a, offset, count);
}

int Character::codePointCountImpl(Array<char16_t> a, int offset, int count) {
    int endIndex = offset + count;
    int n = count;
    for (int i = offset; i < endIndex;) {
        if (isHighSurrogate(a[ i++ ]) && i < endIndex
            && isLowSurrogate(a[ i ])) {
            n--;
            i++;
        }
    }
    return n;
}

int Character::compare(char16_t x, char16_t y) {
    return x - y;
}

int Character::compareTo(Character anotherCharacter) {
    return compare(this->charValue(), anotherCharacter.charValue());
}

boolean Character::isHighSurrogate(char16_t target) {
    return target >= MIN_HIGH_SURROGATE && target < ( MAX_HIGH_SURROGATE + 1 );
}

boolean Character::isLowSurrogate(char16_t target) {
    return target >= MIN_LOW_SURROGATE && target < ( MAX_LOW_SURROGATE + 1 );
}

boolean Character::isSurrogate(char16_t target) {
    return target >= MIN_SURROGATE && target < ( MAX_SURROGATE + 1 );
}

int Character::toCodePoint(unicode high, unicode low) {
    return (( high << 10 ) + low ) + ( MIN_SUPPLEMENTARY_CODE_POINT
                                       - ( MIN_HIGH_SURROGATE << 10 )
                                       - MIN_LOW_SURROGATE );
}

int Character::digit(int codePoint, int radix) {
    if (radix == 10) {
        switch (codePoint) {
            case (int) '0':
                return 0;
            case (int) '1':
                return 1;
            case (int) '2':
                return 2;
            case (int) '3':
                return 3;
            case (int) '4':
                return 4;
            case (int) '5':
                return 5;
            case (int) '6':
                return 6;
            case (int) '7':
                return 7;
            case (int) '8':
                return 8;
            case (int) '9':
                return 9;
            default:
                return -1;
        }
    }
    if (radix == 16) {
        switch (codePoint) {
            case (int) '0':
                return 0;
            case (int) '1':
                return 1;
            case (int) '2':
                return 2;
            case (int) '3':
                return 3;
            case (int) '4':
                return 4;
            case (int) '5':
                return 5;
            case (int) '6':
                return 6;
            case (int) '7':
                return 7;
            case (int) '8':
                return 8;
            case (int) '9':
                return 9;
            case (int) 'a':
                return 10;
            case (int) 'b':
                return 11;
            case (int) 'c':
                return 12;
            case (int) 'd':
                return 13;
            case (int) 'e':
                return 14;
            case (int) 'f':
                return 15;
            default:
                return -1;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Character &target) {
    os << target.charValue();
    return os;
}
