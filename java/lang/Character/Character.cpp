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
#include "../../util/Arrays/Arrays.hpp"
#include "../CharacterData/CharacterData.hpp"


// Start region: Constructor.

Character::Character() {
    this->original = u'\0';
}

Character::Character(unicode original) {
    this->original = original;
}

Character::~Character() = default;

// End region: Constructors.

// Start region: Instance methods.

int Character::charCount(int codePoint) const {
    if (codePoint >= MIN_SUPPLEMENTARY_CODE_POINT) {
        return 2;
    }
    return 1;
}

unicode Character::charValue() const {
    return this->original;
}

int Character::codePointAt(const Array<unicode> &charArray, int index){
    return codePointAtImpl(charArray, index, charArray.length);
}

int Character::compareTo(const Character &anotherCharacter) const {
    return compare(this->charValue(), anotherCharacter.charValue());
}

boolean Character::equals(const Character &object) const {
    return this->original == object.original;
}

boolean Character::equals(const Object &object) const {
    // TODO (truongchauhien): Back to this later.
    return true;
}

int Character::getType(int codePoint) {
    return 0;
}

long Character::hashCode() const {
    return Character::hashCode(this->original);
}

string Character::toString() const {
    // TODO (truongchauhien): This method return "mysterious" result.
    return string_from_int(this->original);
}

// End region: Instance methods.

// Start region: Public static methods.

int Character::codePointAt(const Array<unicode> &charArray , int index, int limit) {
    if (index >= limit || limit < 0 || limit > charArray.length) {
        throw IndexOutOfBoundsException();
    }

    return codePointAtImpl(charArray, index, limit);
}

int Character::codePointBefore(const Array<unicode> &charArray , int index) {
    return codePointBeforeImpl(charArray, index, 0);
}

int Character::codePointBefore(const Array<unicode> &charArray , int index, int start) {
    if (index <= start || start < 0 || start >= charArray.length) {
        throw IndexOutOfBoundsException();
    }
    return codePointBeforeImpl(charArray, index, start);
}

int Character::codePointCount(const Array<unicode> &charArray, int offset, int count) {
    if (count > charArray.length - offset || offset < 0 || count < 0) {
        throw IndexOutOfBoundsException();
    }
    return codePointCountImpl(charArray, offset, count);
}

int Character::compare(unicode charA, unicode charB) {
    return charA - charB;
}

int Character::digit(unicode character, int radix) {
    return Character::digit(static_cast<int>(character), radix);
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

unicode Character::forDigit(int digit, int radix){
    if ((digit >= radix) || (digit < 0)) {
        return '\0';
    }

    if ((radix < Character::MIN_RADIX) || (radix > Character::MAX_RADIX)) {
        return '\0';
    }

    if (digit < 10) {
        return (unicode)('0' + digit);
    }

    return (unicode)('a' - 10 + digit);
}

long Character::hashCode(unicode value) {
    return (int) value;
}

unicode Character::highSurrogate(int codePoint) {
    return (unicode) (((unsigned long)codePoint >> 10)
                      + (MIN_HIGH_SURROGATE - (((unsigned long)MIN_SUPPLEMENTARY_CODE_POINT) >> 10)));
}

boolean Character::isAlphabetic(int codePoint) {

}

boolean Character::isBmpCodePoint(int codePoint) {
    unsigned int highOrderBitsOfCodePoint = static_cast<unsigned int>(codePoint) >> 16;
    return (highOrderBitsOfCodePoint == 0);
}

boolean Character::isHighSurrogate(unicode character) {
    return character >= MIN_HIGH_SURROGATE && character < ( MAX_HIGH_SURROGATE + 1 );
}

boolean Character::isLowSurrogate(unicode character) {
    return character >= MIN_LOW_SURROGATE && character < ( MAX_LOW_SURROGATE + 1 );
}

boolean Character::isSurrogate(unicode target) {
    return target >= MIN_SURROGATE && target < ( MAX_SURROGATE + 1 );
}

boolean Character::isValidCodePoint(int codePoint) {
    return codePoint >= Character::MIN_CODE_POINT && codePoint <= Character::MAX_CODE_POINT;
}

unicode Character::lowSurrogate(int codePoint) {
    return (unicode) ((codePoint & 0x3ff) + MIN_LOW_SURROGATE);
}

int Character::offsetByCodePoints(const Array<unicode> &charArray,
                                  int start, int count, int index,
                                  int codePointOffset) {
    if (count > charArray.length-start || start < 0 || count < 0
        || index < start || index > start + count) {
        throw IndexOutOfBoundsException();
    }

    return offsetByCodePointsImpl(charArray, start, count, index, codePointOffset);
}

int Character::toCodePoint(unicode high, unicode low) {
    return (( high << 10 ) + low ) + ( MIN_SUPPLEMENTARY_CODE_POINT
                                       - ( MIN_HIGH_SURROGATE << 10 )
                                       - MIN_LOW_SURROGATE );
}

// End region: Public static methods.

// Start region: Operators.

std::ostream &operator<<(std::ostream &os, const Character &target) {
    os << target.charValue();
    return os;
}

// End region: Operators.

// Start region: Private static methods.

int Character::codePointAtImpl(const Array<unicode> &charArray, int index, int limit) {
    if (index < 0 || index >= charArray.length) {
        throw ArrayIndexOutOfBoundsException(index);
    }
    unicode char1 = charArray[ index ];
    if (isHighSurrogate(char1) && ++index < limit) {
        unicode char2 = charArray[ index ];
        if (isLowSurrogate(char2)) {
            return toCodePoint(char1, char2);
        }
    }
    return (int) char1;
}

int Character::codePointBeforeImpl(const Array<unicode> &charArray, int index, int start) {
    if (index < 1 || index >= charArray.length) {
        throw ArrayIndexOutOfBoundsException(index);
    }
    unicode c2 = charArray[ --index ];
    if (isLowSurrogate(c2) && index > start) {
        unicode c1 = charArray[ --index ];
        if (isHighSurrogate(c1)) {
            return toCodePoint(c1, c2);
        }
    }
    return c2;
}

int Character::codePointCountImpl(const Array<unicode> &charArray, int offset, int count) {
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

int Character::offsetByCodePointsImpl(const Array<unicode> &charArray, int start, int count, int index,
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

void Character::toSurrogates(int codePoint, Array<unicode> &charArray, int index) {
    charArray[index + 1] = Character::lowSurrogate(codePoint);
    charArray[index] = Character::highSurrogate(codePoint);
}

// End region: Private static methods.
