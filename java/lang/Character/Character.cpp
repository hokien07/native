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
#include "../IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../ArrayIndexOutOfBoundsException/ArrayIndexOutOfBoundsException.hpp"

using namespace Java::Lang;

Character::Character() {
    this->original = u'\0';
}

Character::Character(char16_t original) {
    this->original = original;
}

Character::~Character() = default;

int Character::charCount(int codePoint) const {
    if (codePoint >= MIN_SUPPLEMENTARY_CODE_POINT) {
        return 2;
    }
    return 1;
}

char16_t Character::charValue() const {
    return this->original;
}

int Character::codePointAt(const Array<char16_t> &charArray, int index) {
    return codePointAtImpl(charArray, index, charArray.length);
}

int Character::codePointAt(const Array<char16_t> &charArray , int index, int limit) {
    if (index >= limit || limit < 0 || limit > charArray.length) {
        throw IndexOutOfBoundsException();
    }

    return codePointAtImpl(charArray, index, limit);
}

// throws ArrayIndexOutOfBoundsException if index out of bounds
int Character::codePointAtImpl(const Array<char16_t> &charArray, int index, int limit) {
    if (index < 0 || index >= charArray.length) {
        throw ArrayIndexOutOfBoundsException(index);
    }
    char16_t char1 = charArray[ index ];
    if (isHighSurrogate(char1) && ++index < limit) {
        char16_t char2 = charArray[ index ];
        if (isLowSurrogate(char2)) {
            return toCodePoint(char1, char2);
        }
    }
    return (int) char1;
}

int Character::codePointBefore(const Array<char16_t> &charArray , int index) {
    return codePointBeforeImpl(charArray, index, 0);
}

int Character::codePointBefore(const Array<char16_t> &charArray , int index, int start) {
    if (index <= start || start < 0 || start >= charArray.length) {
        throw IndexOutOfBoundsException();
    }
    return codePointBeforeImpl(charArray, index, start);
}

// throws ArrayIndexOutOfBoundsException if index-1 out of bounds
int Character::codePointBeforeImpl(const Array<char16_t> &charArray, int index, int start) {
    if (index < 1 || index >= charArray.length) {
        throw ArrayIndexOutOfBoundsException(index);
    }
    char16_t c2 = charArray[ --index ];
    if (isLowSurrogate(c2) && index > start) {
        char16_t c1 = charArray[ --index ];
        if (isHighSurrogate(c1)) {
            return toCodePoint(c1, c2);
        }
    }
    return c2;
}

int Character::codePointCount(const Array<char16_t> &charArray, int offset, int count) {
    if (count > charArray.length - offset || offset < 0 || count < 0) {
        throw IndexOutOfBoundsException();
    }
    return codePointCountImpl(charArray, offset, count);
}

int Character::codePointCountImpl(const Array<char16_t> &charArray, int offset, int count) {
    int endIndex = offset + count;
    int numberOfCodePoint = count;
    for (int i = offset; i < endIndex;) {
        if (isHighSurrogate(charArray[ i++ ]) && i < endIndex
            && isLowSurrogate(charArray[ i ])) {
            numberOfCodePoint--;
            i++;
        }
    }
    return numberOfCodePoint;
}

int Character::compare(char16_t charA, char16_t charB) {
    return charA - charB;
}

int Character::compareTo(const Character &anotherCharacter) const {
    return compare(this->charValue(), anotherCharacter.charValue());
}

boolean Character::isHighSurrogate(char16_t character) {
    return character >= MIN_HIGH_SURROGATE && character < ( MAX_HIGH_SURROGATE + 1 );
}

boolean Character::isLowSurrogate(char16_t character) {
    return character >= MIN_LOW_SURROGATE && character < ( MAX_LOW_SURROGATE + 1 );
}

boolean Character::isSurrogate(char16_t target) {
    return target >= MIN_SURROGATE && target < ( MAX_SURROGATE + 1 );
}

int Character::toCodePoint(char16_t high, char16_t low) {
    return (( high << 10 ) + low ) + ( MIN_SUPPLEMENTARY_CODE_POINT
                                       - ( MIN_HIGH_SURROGATE << 10 )
                                       - MIN_LOW_SURROGATE );
}

std::ostream &operator<<(std::ostream &os, const Character &target) {
    os << target.charValue();
    return os;
}

boolean Character::equals(const Character &object) const {
    return this->original == object.original;
}

long Character::hashCode() const {
    return Character::hashCode(this->original);
}

string Character::toString() const {
    return string_from_int(this->original);
}

int Character::offsetByCodePointsImpl(const Array<char16_t> &charArray, int start, int count, int index,
                                      int codePointOffset) {
    int offset = index;
    if (codePointOffset >= 0) {
        int limit = start + count;
        for (index = 0; offset < limit && index < codePointOffset; index++) {
            if (isHighSurrogate(charArray[offset++]) && offset < limit
                && isLowSurrogate(charArray[offset])) {
                offset++;
            }
        }

        if (index < codePointOffset) {
            throw IndexOutOfBoundsException();
        }
    } else {
        for (index = codePointOffset; offset > start && index < 0; index++) {
            if (isLowSurrogate(charArray[--offset]) && offset > start
                && isHighSurrogate(charArray[offset-1])) {
                offset--;
            }
        }

        if (index < 0) {
            throw IndexOutOfBoundsException();
        }
    }
    return offset;
}

long Character::hashCode(char16_t value) {
    return (int) value;
}

int
Character::offsetByCodePoints(const Array<char16_t> &charArray, int start, int count, int index,
                              int codePointOffset) {
    if (count > charArray.length-start || start < 0 || count < 0
        || index < start || index > start + count) {
        throw IndexOutOfBoundsException();
    }

    return offsetByCodePointsImpl(charArray, start, count, index, codePointOffset);
}

void Character::toSurrogates(int codePoint, Array<char16_t> &charArray, int index) {
    charArray[index + 1] = Character::lowSurrogate(codePoint);
    charArray[index] = Character::highSurrogate(codePoint);
}

char16_t Character::lowSurrogate(int codePoint) {
    return (char16_t) ((codePoint & 0x3ff) + MIN_LOW_SURROGATE);
}

char16_t Character::highSurrogate(int codePoint) {
    return (char16_t) (((unsigned long) codePoint >> 10)
                       + (MIN_HIGH_SURROGATE - (((unsigned long) MIN_SUPPLEMENTARY_CODE_POINT) >> 10)));
}

char16_t Character::forDigit(int digit, int radix){
    if ((digit >= radix) || (digit < 0)) {
        return '\0';
    }

    if ((radix < Character::MIN_RADIX) || (radix > Character::MAX_RADIX)) {
        return '\0';
    }

    if (digit < 10) {
        return (char16_t)('0' + digit);
    }

    return (char16_t)('a' - 10 + digit);
}
