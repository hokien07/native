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

#include "../StringBuilder/StringBuilder.hpp"
#include "../NegativeArraySizeException/NegativeArraySizeException.hpp"
#include "../IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"
#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"
#include "../IllegalArgumentException/IllegalArgumentException.hpp"

using namespace Java::Lang;

StringBuilder::StringBuilder() : StringBuilder(defaultCapacity) { }

StringBuilder::StringBuilder(int capacity) {
    if (capacity < 0) {
        throw NegativeArraySizeException("Capacity is negative");
    }

    this->original = (char16_t *)calloc((size_t)capacity, sizeof(char16_t));
    this->currentLength = 0;
    this->currentCapacity = capacity;
}

StringBuilder::StringBuilder(const_string target) {
    int newCapacity = defaultCapacity + static_cast<int>(strlen(target));
    this->original = (char16_t *)calloc((size_t)newCapacity, sizeof(char16_t));
    this->ensureCapacity(newCapacity);
    this->append(target);
}

StringBuilder::StringBuilder(const String &target) {
    int newCapacity = defaultCapacity + target.length();
    this->ensureCapacity(newCapacity);
    this->append(target.toString());
}

StringBuilder::StringBuilder(const std::initializer_list<char16_t> &target) {
    int newCapacity = defaultCapacity + (int)target.size();
    this->ensureCapacity(newCapacity);
    this->append(target);
}

StringBuilder::StringBuilder(const CharSequence &charSequence) {
    int newCapaity = defaultCapacity + charSequence.length();
    this->ensureCapacity(newCapaity);
    this->append(charSequence);
}

StringBuilder::StringBuilder(const StringBuilder &target) {
    this->original = (char16_t *)calloc((size_t)target.currentCapacity, sizeof(char16_t));
    int index;
    for (index = 0; index < target.currentLength; index++) {
        this->original[index] = target.original[index];
    }
    this->currentLength = target.currentLength;
    this->currentCapacity = target.currentCapacity;
}

StringBuilder::~StringBuilder() {
    free(original);
}

StringBuilder &StringBuilder::append(const Boolean &target) {
    return this->append(target.toString());
}

StringBuilder &StringBuilder::append(boolean target) {
    return this->append(Boolean(target));
}

StringBuilder &StringBuilder::append(const Character &target) {
    return this->append(target.charValue());
}

StringBuilder &StringBuilder::append(char16_t target) {
    int newLength = this->currentLength + 1;
    this->ensureCapacity(newLength);
    this->original[this->currentLength] = target;
    this->currentLength = newLength;
    return *this;
}

StringBuilder &StringBuilder::append(char target) {
    int newLength = this->currentLength + 1;
    this->ensureCapacity(newLength);
    this->original[this->currentLength] = static_cast<char16_t>(target);
    this->currentLength = newLength;
    return *this;
}

StringBuilder &StringBuilder::append(const Array<Character> &target) {
    int newLength = this->currentLength + target.length;
    this->ensureCapacity(newLength);
    int indexOfOriginal = this->currentLength;
    for (Character character : target) {
        this->original[indexOfOriginal] = character.charValue();
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder &StringBuilder::append(const Array<char16_t> &target) {
    int newLength = this->currentLength + target.length;
    this->ensureCapacity(newLength);
    int indexOfOriginal = this->currentLength;
    for (char16_t character: target) {
        this->original[indexOfOriginal] = character;
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder &StringBuilder::append(const Array<Character> &target, int offset, int length) {
    return this->insert(this->currentLength, target, offset, length);
}

StringBuilder &StringBuilder::append(const Array<char16_t> &target, int offset, int length) {
    return this->insert(this->currentLength, target, offset, length);
}

StringBuilder &StringBuilder::append(const CharSequence &target) {
    string targetString = target.toString();
    return this->append(targetString);
}

StringBuilder &StringBuilder::append(const CharSequence &target, int start, int end) {
    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target.toString(), targetUtf16);
    int lengthOfTarget = static_cast<int>(targetUtf16.length());
    if (start < 0 || start > end || end > lengthOfTarget) {
        throw IndexOutOfBoundsException();
    }

    int numberOfCharacter = end - start;
    int newLength = currentLength + numberOfCharacter;
    this->ensureCapacity(newLength);
    int indexOfTarget;
    int indexOfOriginal;
    for (indexOfTarget = start, indexOfOriginal = this->currentLength; indexOfTarget < end; indexOfTarget++, ++indexOfOriginal) {
        this->original[indexOfOriginal] = targetUtf16[indexOfTarget];
    }

    this->currentLength = newLength;
    return *this;
}

StringBuilder &StringBuilder::append(const std::initializer_list<char16_t> &target) {
    int newLength = this->currentLength + (int)target.size();
    this->ensureCapacity(newLength);
    int index = this->currentLength;
    std::initializer_list<char16_t>::const_iterator listIterator;
    for (listIterator = target.begin(); listIterator != target.end(); ++listIterator) {
        this->original[index] = *listIterator;
        index = index + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder &StringBuilder::append(const_string target) {
    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target, targetUtf16);
    int stringLength = static_cast<int>(targetUtf16.length());
    int newLength = this->currentLength + stringLength;
    this->ensureCapacity(newLength);
    int indexOfOriginal;
    int indexOfString = 0;
    for (indexOfOriginal = this->currentLength; indexOfOriginal < newLength; ++indexOfOriginal) {
        this->original[indexOfOriginal] = targetUtf16[indexOfString];
        indexOfString = indexOfString + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder &StringBuilder::append(const Double &target) {
    return this->append(target.toString());
}

StringBuilder &StringBuilder::append(double target) {
    return this->append(Double(target));
}

StringBuilder &StringBuilder::append(const Float &target) {
    return this->append(target.toString());
}

StringBuilder &StringBuilder::append(float target) {
    return this->append(Float(target));
}

StringBuilder &StringBuilder::append(const Integer &target) {
    return this->append(target.toString());
}

StringBuilder &StringBuilder::append(int target) {
    return this->append(Integer(target));
}

StringBuilder &StringBuilder::append(const Long &target) {
    return this->append(target.toString());
}

StringBuilder &StringBuilder::append(long target) {
    return this->append(Long(target));
}

StringBuilder &StringBuilder::append(const String &target) {
    return this->append(target.toString());
}

StringBuilder &StringBuilder::append(const StringBuffer &target) {
    return this->append(target.toString());
}

StringBuilder &StringBuilder::appendCodePoint(int codePoint) {
    if (Character::isBmpCodePoint(codePoint)) {
        return this->append(static_cast<char16_t>(codePoint));
    } else if (Character::isValidCodePoint(codePoint)) {
        this->append(Character::highSurrogate(codePoint));
        this->append(Character::lowSurrogate(codePoint));
        return *this;
    } else {
        throw IllegalArgumentException();
    }
}

int StringBuilder::capacity() const {
    return this->currentCapacity;
}

char16_t StringBuilder::charAt(int index) const {
    if (index < 0 || index >= this->currentLength) {
        throw IndexOutOfBoundsException(String::valueOf(index));
    }

    return this->original[index];
}

int StringBuilder::codePointAt(int index) const {
    if (index < 0 || index >= this->currentLength) {
        throw IndexOutOfBoundsException(String::valueOf(index));
    }

    Array<char16_t> originalArray;
    int indexOfOriginal;
    for (indexOfOriginal = 0; indexOfOriginal < this->currentLength;
         indexOfOriginal++) {
        originalArray.push(this->original[indexOfOriginal]);
    }
    int result = Character::codePointAt(originalArray, index);
    return result;
}

int StringBuilder::codePointBefore(int index) const {
    int beforeOfIndex = index - 1;
    return this->codePointAt(beforeOfIndex);
}

int StringBuilder::codePointCount(int beginIndex, int endIndex) {
    if ((beginIndex < 0) ||
        (endIndex > this->currentLength) ||
        (beginIndex > endIndex)) {
        throw IndexOutOfBoundsException();
    }

    Array<char16_t> originalArray;
    int numberOfCharacters = endIndex - beginIndex;
    int index;
    int stopIndex = beginIndex + numberOfCharacters;
    for (index = 0; index < stopIndex; index++) {
        originalArray.push(this->original[index]);
    }
    int result = Character::codePointCount(originalArray, 0, numberOfCharacters);
    return result;
}

StringBuilder StringBuilder::deleteRange(int start, int end) {
    if (start < 0) {
        throw StringIndexOutOfBoundsException(start);
    }
    if (end > this->currentLength) {
        end = this->currentLength;
    }
    if (start > end) {
        throw StringIndexOutOfBoundsException("start > end");
    }

    int lengthOfSubStringWillBeRemoved = end - start;
    char16_t *newPositionOfTail = this->original + start;
    char16_t *oldPositionOfTail = this->original + end;
    int memorySizeOfTailPart = (this->currentLength - end) * sizeof(char16_t);
    memmove(newPositionOfTail, oldPositionOfTail, (size_t)memorySizeOfTailPart);

    this->currentLength = this->currentLength - lengthOfSubStringWillBeRemoved;
    return *this;
}

StringBuilder StringBuilder::deleteCharAt(int index) {
    if (index < 0 || index >= this->currentLength) {
        throw StringIndexOutOfBoundsException(index);
    }

    char16_t *newPositionOfTail = this->original + index;
    char16_t *oldPositionOfTail = this->original + index + 1;
    int memorySizeOfTailPart = (this->currentLength - (index + 1)) * sizeof(char16_t);
    memmove(newPositionOfTail, oldPositionOfTail, (size_t)memorySizeOfTailPart);

    this->currentLength = this->currentLength - 1;
    return *this;
}

void StringBuilder::ensureCapacity(int minimumCapacity) {
    if (minimumCapacity <= 0 || minimumCapacity <= this->currentCapacity) {
        return;
    }

    int newCapacity = this->currentCapacity * 2 + 2;
    if (newCapacity < minimumCapacity) {
        newCapacity = minimumCapacity;
    }
    int numberOfBytes = newCapacity * sizeof(char16_t);
    this->original = (char16_t *)realloc(this->original, (size_t)numberOfBytes);
    this->currentCapacity = newCapacity;
}

void StringBuilder::getChars(int sourceBegin, int sourceEnd,
                             Array<Character> &target, int targetBegin) const {
    if (sourceBegin < 0) {
        throw StringIndexOutOfBoundsException(sourceBegin);
    }
    if (sourceEnd < 0 || sourceEnd > this->currentLength) {
        throw StringIndexOutOfBoundsException(sourceEnd);
    }
    if (sourceBegin > sourceEnd) {
        throw StringIndexOutOfBoundsException("sourceBegin > sourceEnd");
    }

    // TODO: copyOfRange method for Array is not implemented.
    throw UnsupportedOperationException();
}

int StringBuilder::indexOf(const String &target) const{
    return this->indexOf(target.toString());
}

int StringBuilder::indexOf(const_string target) const {
    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target, targetUtf16);
    std::u16string originalUtf16(this->original,
                                 static_cast<size_t>(this->currentLength));
    return this->stringMatches(originalUtf16, targetUtf16, 0);
}

int StringBuilder::indexOf(const String &target, int fromIndex) const {
    return this->indexOf(target.toString(), fromIndex);
}

int StringBuilder::indexOf(const_string target, int fromIndex) const {
    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target, targetUtf16);
    std::u16string originalUtf16(this->original,
                                 static_cast<size_t>(this->currentLength));
    return  this->stringMatches(originalUtf16, targetUtf16, fromIndex);
}

StringBuilder &StringBuilder::insert(int offset, boolean target) {
    return this->insert(offset, Boolean(target));
}

StringBuilder &StringBuilder::insert(int offset, const Boolean &target) {
    return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, char16_t target) {
    if (offset < 0 || offset > this->currentLength) {
        throw IndexOutOfBoundsException(String::valueOf(offset));
    }

    int newLength = this->currentLength + 1;
    this->ensureCapacity(newLength);

    char16_t *newShiftPosition = this->original + offset + 1;
    char16_t *oldShiftPosition = this->original + offset;
    int sizeOfShiftMemory = (this->currentLength - offset) * sizeof(char16_t);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
    this->original[offset] = target;
    this->currentLength = newLength;

    return *this;
}

StringBuilder &StringBuilder::insert(int offset, const Character &target) {
    return this->insert(offset, target.charValue());
}

StringBuilder &StringBuilder::insert(int offset, const Array<char16_t> &target) {
    return this->insert(offset, target, 0, target.length);
}

StringBuilder &StringBuilder::insert(int offset, const Array<Character> &target) {
    return this->insert(offset, target, 0, target.length);
}

StringBuilder &StringBuilder::insert(int index, const Array<char16_t> &target, int offset, int length) {
    if (index < 0 || index > this->currentLength) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int stopIndexOfTarget = offset + length;
    if (offset < 0 || length < 0 || stopIndexOfTarget > target.length) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int newLength = this->currentLength + length;
    this->ensureCapacity(newLength);

    char16_t *newShiftPosition = this->original + index + length;
    char16_t *oldShiftPosition = this->original + index;
    int sizeOfShiftMemory = (this->currentLength - index) * sizeof(char16_t);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
    int indexOfTarget;
    int indexOfOriginal = index;
    for (indexOfTarget = offset; indexOfTarget < stopIndexOfTarget; ++indexOfTarget) {
        this->original[indexOfOriginal] = target.get(indexOfTarget);
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;

    return *this;
}

StringBuilder &StringBuilder::insert(int index, const Array<Character> &target,
                                     int offset, int length) {
    if (index < 0 || index > this->currentLength) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int stopIndexOfTarget = offset + length;
    if (offset < 0 || length < 0 || stopIndexOfTarget > target.length) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int newLength = this->currentLength + length;
    this->ensureCapacity(newLength);

    char16_t *newShiftPosition = this->original + index + length;
    char16_t *oldShiftPosition = this->original + index;
    int sizeOfShiftMemory = (this->currentLength - index) * sizeof(char16_t);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
    int indexOfTarget;
    int indexOfOriginal = index;
    for (indexOfTarget = offset;
         indexOfTarget < stopIndexOfTarget; ++indexOfTarget) {
        this->original[indexOfOriginal] = target.get(indexOfTarget).charValue();
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;

    return *this;
}

StringBuilder &StringBuilder::insert(int destinationOffset, const CharSequence &target) {
    return this->insert(destinationOffset, target.toString());
}

StringBuilder &StringBuilder::insert(int destinationOffset, const CharSequence &target, int start, int end) {
    if (destinationOffset < 0 || destinationOffset > this->currentLength) {
        throw IndexOutOfBoundsException();
    }

    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target.toString(), targetUtf16);
    int lengthOfTarget = static_cast<int>(targetUtf16.length());
    if (start < 0 || end < 0 || start > end || end > lengthOfTarget){
        throw IndexOutOfBoundsException();
    }

    int lengthOfSubStringOfTarget = end - start;
    int newLength = this->currentLength + lengthOfSubStringOfTarget;
    this->ensureCapacity(newLength);

    char16_t *newShiftPosition =
            this->original + destinationOffset +lengthOfSubStringOfTarget;
    char16_t *oldShiftPosition =
            this->original + destinationOffset;
    int sizeOfShiftMemory =
            (this->currentLength - destinationOffset) * sizeof(char16_t);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);

    int indexOfOriginal = destinationOffset;
    int indexOfTarget;
    for (indexOfTarget = start; indexOfTarget < end; indexOfTarget++) {
        this->original[indexOfOriginal] = targetUtf16[indexOfTarget];
        indexOfOriginal = indexOfOriginal + 1;
    }

    this->currentLength = newLength;
    return *this;
}

StringBuilder &StringBuilder::insert(int offset, const Double &target) {
    return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, double target) {
    return this->insert(offset, Double(target));
}

StringBuilder &StringBuilder::insert(int offset, const Float &target) {
    return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, float target) {
    return this->insert(offset, Float(target));
}

StringBuilder &StringBuilder::insert(int offset, const Integer &target) {
    return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, int target) {
    return this->insert(offset, Integer(target));
}

StringBuilder &StringBuilder::insert(int offset, const Long &target) {
    return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, long target) {
    return this->insert(offset, Long(target));
};

StringBuilder &StringBuilder::insert(int offset, const String &target) {
    return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, const_string target) {
    if (offset < 0 || offset > this->currentLength) {
        throw StringIndexOutOfBoundsException(offset);
    }

    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target, targetUtf16);
    int targetLength = static_cast<int>(targetUtf16.length());
    int newLength = this->currentLength + targetLength;
    this->ensureCapacity(newLength);

    char16_t *newShiftPosition = this->original + offset + targetLength;
    char16_t *oldShiftPosition = this->original + offset;
    // Number of bytes of memory will be to shift = size of char type multiple
    // with number of character begin from the offset to the end.
    int sizeOfShiftMemory = (this->currentLength - offset) * sizeof(char16_t);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);

    int indexOfOriginal = offset;
    int indexOfTarget;
    for (indexOfTarget = 0; indexOfTarget < targetLength; ++indexOfTarget) {
        this->original[indexOfOriginal] = targetUtf16[indexOfTarget];
        indexOfOriginal = indexOfOriginal + 1;
    }

    this->currentLength = newLength;
    return *this;
}

int StringBuilder::lastIndexOf(const String &target) const {
    return this->lastIndexOf(target.toString());
}

int StringBuilder::lastIndexOf(const_string target) const {
    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target, targetUtf16);
    std::u16string originalUtf16(this->original,
                                 static_cast<size_t>(this->currentLength));
    return this->stringMatchesReverse(originalUtf16,
                                      targetUtf16, this->currentLength);
}

int StringBuilder::lastIndexOf(const String &target, int fromIndex) const {
    return this->lastIndexOf(target.toString(), fromIndex);
}

int StringBuilder::lastIndexOf(const_string target, int fromIndex) const {
    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target, targetUtf16);
    std::u16string originalUtf16(this->original,
                                 static_cast<size_t>(this->length()));
    return this->stringMatchesReverse(originalUtf16, targetUtf16, fromIndex);
}

int StringBuilder::length() const {
    return this->currentLength;
}

int StringBuilder::offsetByCodePoints(int index, int codePointOffset) const {
    if (index < 0 || index > this->currentLength) {
        throw IndexOutOfBoundsException();
    }


}

StringBuilder StringBuilder::replace(int start, int end, const String &target) {
    return this->replace(start, end, target.toString());
}

StringBuilder StringBuilder::replace(int start, int end, const_string target) {
    std::u16string targetUtf16;
    this->convertUtf8ToUtf16(target, targetUtf16);

    if (start < 0) {
        throw StringIndexOutOfBoundsException(start);
    }
    if (start > this->currentLength) {
        throw StringIndexOutOfBoundsException("start > length()");
    }
    if (start > end) {
        throw StringIndexOutOfBoundsException("start > end");
    }
    if (end > this->currentLength) {
        end = this->currentLength;
    }

    int lengthOfTarget = static_cast<int>(targetUtf16.length());
    int lengthOfSubStringWillBeOverwrite = end - start; // tail part of this sequence.
    int newLength = this->currentLength + lengthOfTarget - lengthOfSubStringWillBeOverwrite;
    this->ensureCapacity(newLength);

    char16_t *newPositionOfTailPart =
            this->original + end + lengthOfTarget - lengthOfSubStringWillBeOverwrite;
    char16_t *oldPositionOfTailPart = this->original + end;
    int memorySizeOfTailPart = (this->currentLength - end) * sizeof(char16_t);
    memmove(newPositionOfTailPart,
            oldPositionOfTailPart, (size_t)memorySizeOfTailPart);

    char16_t *insertPosition = this->original + start;
    int memorySizeForTarget = lengthOfTarget * sizeof(char16_t);
    memcpy(insertPosition, targetUtf16.c_str(), (size_t)memorySizeForTarget);

    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::reverse() {
    boolean hasSurrogates = false;
    int index;
    int oppositeIndex;
    int stopIndex = this->currentLength / 2;
    char16_t temp;
    for (index = 0; index < stopIndex; ++index) {
        oppositeIndex = (this->currentLength - 1) - index;
        temp = this->original[index];
        this->original[index] = this->original[oppositeIndex];
        this->original[oppositeIndex] = temp;
        if (Character::isSurrogate((this->original[index])) ||
                Character::isSurrogate(this->original[oppositeIndex])) {
            hasSurrogates = true;
        }
    }
    if (hasSurrogates) {
        this->reverseAllValidSurrogatePairs();
    }
    return *this;
}

void StringBuilder::setCharAt(int index, char16_t target) {
    if (index < 0 || index >= this->currentLength) {
        throw StringIndexOutOfBoundsException(index);
    }

    this->original[index] = target;
}

void StringBuilder::setCharAt(int index, const Character &target) {
    this->setCharAt(index, target.charValue());
}

void StringBuilder::setLength(int newLength) {
    if (newLength < 0) {
        throw IndexOutOfBoundsException(String::valueOf(newLength));
    }

    this->ensureCapacity(newLength);
    if (this->currentLength < newLength) {
        int index;
        for (index = this->currentLength; index < newLength; index++) {
            this->original[index] = '\0';
        }
    }
    this->currentLength = newLength;
}

String StringBuilder::substring(int start) const {
    return this->substring(start, this->currentLength);
}

String StringBuilder::substring(int start, int end) const {
    if (start < 0 || start > this->currentLength) {
        throw StringIndexOutOfBoundsException(start);
    }
    if (end < 0 || end > this->currentLength) {
        throw StringIndexOutOfBoundsException(end);
    }
    if (start > end) {
        throw StringIndexOutOfBoundsException(end - start);
    }

    std::u16string subStringUtf16(this->original,
                                  static_cast<size_t>(this->currentLength));
    subStringUtf16 = subStringUtf16.substr(static_cast<size_t>(start),
                                           static_cast<size_t>(end - start));
    std::string subStringUtf8;
    this->convertUtf16ToUtf8(subStringUtf16, subStringUtf8);
    return subStringUtf8.c_str();
}

string StringBuilder::toString() const {
    std::u16string copyOfOriginalWithNullTerminator(
            this->original,
            static_cast<size_t>(this->currentLength));
    std::string utf8String;
    this->convertUtf16ToUtf8(copyOfOriginalWithNullTerminator, utf8String);
    this->backupForToString = String(utf8String);
    return backupForToString.toString();
}

void StringBuilder::trimToSize() {
    if (this->currentCapacity > this->currentLength) {
        int numberOfBytesForCapacity = this->currentLength * sizeof(char16_t);
        this->original = (char16_t *)realloc(this->original,
                                             (size_t)numberOfBytesForCapacity);
        this->currentCapacity = this->currentLength;
    }
}

int *StringBuilder::initializeNextTable(const std::u16string &pattern) const{
    int lengthOfPattern = static_cast<int>(pattern.length());
    if (lengthOfPattern == 0) {
        return nullptr;
    }

    auto *nextTable =
            static_cast<int *>(calloc((size_t)lengthOfPattern, sizeof(int)));

    if (nextTable == nullptr) {
        return nullptr;
    }

    nextTable[0] = -1;
    if (lengthOfPattern == 1) {
        return nextTable;
    }
    nextTable[1] = 0;
    if (lengthOfPattern == 2) {
        return nextTable;
    }

    int position = 2;
    int lengthOfTheLongestPrefixSuffix = 0;

    while (position < lengthOfPattern) {
        if (pattern[position - 1] == pattern[lengthOfTheLongestPrefixSuffix]) {
            lengthOfTheLongestPrefixSuffix = lengthOfTheLongestPrefixSuffix + 1;
            nextTable[position] = lengthOfTheLongestPrefixSuffix;
            position = position + 1;
        }
        else if (lengthOfTheLongestPrefixSuffix > 0) {
            lengthOfTheLongestPrefixSuffix = nextTable[lengthOfTheLongestPrefixSuffix];
        }
        else {
            nextTable[position] = 0;
            position = position + 1;
        }
    }

    return nextTable;
}

int StringBuilder::stringMatches(const std::u16string &target,
                                 const std::u16string &pattern, int startIndex) const {
    int lengthOfPattern = static_cast<int>(pattern.length());
    int lengthOfTarget = static_cast<int>(target.length());

    if (startIndex > lengthOfTarget) {
        if (lengthOfPattern == 0) {
            return lengthOfTarget;
        }
        return -1;
    }

    if (startIndex < 0) {
        startIndex = 0;
    }

    // Empty string always matches.
    if (lengthOfPattern == 0) {
        return startIndex;
    }

    // KMP algorithm.
    int *nextTable = this->initializeNextTable(target);
    if (nextTable == nullptr) {
        return -1;
    }

    int position = 0;
    while (startIndex + position < lengthOfTarget) {
        if (pattern[position] == target[startIndex + position]) {
            if (position == lengthOfPattern - 1) {
                free(nextTable);
                return startIndex;
            }
            position = position + 1;
        }
        else {
            if (nextTable[position] > -1) {
                startIndex = startIndex + position;
                position = nextTable[position];
            }
            else {
                startIndex = startIndex + 1;
                position = 0;
            }
        }
    }

    free(nextTable);
    return -1;
}

int StringBuilder::stringMatchesReverse(const std::u16string &target,
                                        const std::u16string &pattern, int startIndex) const {
    int lengthOfPattern = static_cast<int>(pattern.length());
    int lengthOfTarget =  static_cast<int>(target.length());

    if (startIndex < 0) {
        return -1;
    }

    int rightIndex = lengthOfTarget - lengthOfPattern;
    if (startIndex < rightIndex) {
        startIndex = rightIndex;
    }

    // Empty string always matches.
    if (lengthOfPattern == 0) {
        return startIndex;
    }

    // KMP algorithm.
    int *nextTable = this->initializeNextTable(pattern);
    if (nextTable == nullptr) {
        return -1;
    }

    int position = 0;
    while (startIndex - position >= 0) {
        if (pattern[lengthOfPattern - position - 1] == target[startIndex - position]) {
            if (position == lengthOfPattern - 1) {
                free(nextTable);
                return startIndex - lengthOfPattern + 1;
            }
            position = position + 1;
        }
        else {
            if (nextTable[position]> -1) {
                startIndex = startIndex - position;
                position = nextTable[position];
            }
            else {
                startIndex = startIndex - 1;
                position = 0;
            }
        }
    }

    free(nextTable);
    return - 1;
}

void StringBuilder::reverseAllValidSurrogatePairs() {
    int stopIndex = this->currentLength - 1;
    int index;
    char16_t ch1;
    char16_t ch2;
    for (index = 0; index < stopIndex; index++) {
        ch2 = this->original[index];
        if (Character::isLowSurrogate(ch2)) {
            ch1 = this->original[index + 1];
            if (Character::isHighSurrogate(ch1)) {
                this->original[index] = ch1;
                index = index + 1;
                this->original[index] = ch2;
            }
        }
    }
}

void StringBuilder::convertUtf8ToUtf16(const std::string &utf8String,
                                       std::u16string &utf16String) {
    int rawLength = static_cast<int>(utf8String.length());
    int index = 0;
    int codePoint;
    int numberOfTrailingBytes;
    char16_t highSurrogate;
    char16_t lowSurrogate;
    while (index < rawLength) {
        if (!isFirstByte(utf8String[index])) {
            // Invalid byte sequences.
            return;
        }
        numberOfTrailingBytes =
                getNumberOfTrailingBytesAfterFirstByte(utf8String[index]);
        switch (numberOfTrailingBytes) {
            case 0:
                codePoint = utf8String[index];
                break;
            case 1:
                codePoint = utf8String[index] & 0b00011111;
                break;
            case 2:
                codePoint = utf8String[index] & 0b00001111;
                break;
            case 3:
                codePoint = utf8String[index] & 0b00000111;
                break;
            default:
                // Invalid byte sequences.
                return;
        }
        index = index + 1;

        int trailingByteIndex = 0;
        while (trailingByteIndex < numberOfTrailingBytes) {
            if (index >= rawLength) {
                // Invalid byte sequences.
                return;
            }
            codePoint = codePoint << 6;
            codePoint = codePoint + (utf8String[index] & 0b00111111);
            trailingByteIndex = trailingByteIndex + 1;
            index = index + 1;
        }

        if (codePoint < 0xFFFF) {
            utf16String.push_back(static_cast<char16_t>(codePoint));
        } else {
            codePoint = codePoint - 0x10000;
            highSurrogate =
                    static_cast<char16_t>((static_cast<unsigned int>(codePoint) >> 10) + 0xD800);
            lowSurrogate =
                    static_cast<char16_t>((static_cast<unsigned int>(codePoint) & 0x3FF) + 0xDC00);
            utf16String.push_back(highSurrogate);
            utf16String.push_back(lowSurrogate);
        }
    }
}

void StringBuilder::convertUtf16ToUtf8(const std::u16string &utf16String,
                                       std::string &utf8String) {
    int rawLength = static_cast<int>(utf16String.length());
    int index = 0;
    int codePoint;
    char16_t highSurrogate;
    char16_t lowSurrogate;
    int numberOfBytes;
    char byte1;
    char byte2;
    char byte3;
    char byte4;
    while (index < rawLength) {
        if (Character::isSurrogate(utf16String[index])) {
            highSurrogate = utf16String[index];
            index = index + 1;
            if (index >= rawLength) {
                return;
            }
            lowSurrogate = utf16String[index];
            if (!Character::isHighSurrogate(highSurrogate)) {
                return;
            }
            if (!Character::isLowSurrogate(lowSurrogate)) {
                return;
            }
            codePoint = (lowSurrogate - 0xDC00) & 0x3FF;
            codePoint = codePoint | ((highSurrogate - 0xD800) << 10);
        } else {
            codePoint = utf16String[index];
        }
        index = index + 1;

        // Changes unicode code point to UTF-8 encoded bytes.
        if (codePoint >= 0x0000 && codePoint <= 0x007F) {
            numberOfBytes = 1;
        } else if (codePoint >= 0x0080 && codePoint <= 0x07FF) {
            numberOfBytes = 2;
        } else if (codePoint >= 0x0800 && codePoint <= 0xFFFF) {
            numberOfBytes = 3;
        } else if (codePoint >= 0x10000 && codePoint <= 0x10FFFF) {
            numberOfBytes = 4;
        } else {
            numberOfBytes = -1;
        }

        switch (numberOfBytes) {
            case 1:
                byte1 = static_cast<char>(0b00000000 | (codePoint        & 0b01111111));
                utf8String.push_back(byte1);
                break;
            case 2:
                byte1 = static_cast<char>(0b11000000 | ((codePoint >> 6) & 0b00011111));
                byte2 = static_cast<char>(0b10000000 | (codePoint        & 0b00111111));
                utf8String.push_back(byte1);
                utf8String.push_back(byte2);
                break;
            case 3:
                byte1 = static_cast<char>(0b11100000 | ((codePoint >> 12) & 0b00001111));
                byte2 = static_cast<char>(0b10000000 | ((codePoint >> 6)  & 0b00111111));
                byte3 = static_cast<char>(0b10000000 | (codePoint         & 0b00111111));
                utf8String.push_back(byte1);
                utf8String.push_back(byte2);
                utf8String.push_back(byte3);
                break;
            case 4:
                byte1 = static_cast<char>(0b11110000 | ((codePoint >> 18) & 0b00000111));
                byte2 = static_cast<char>(0b10000000 | ((codePoint >> 12) & 0b00111111));
                byte3 = static_cast<char>(0b10000000 | ((codePoint >> 6)  & 0b00111111));
                byte4 = static_cast<char>(0b10000000 | ( codePoint        & 0b00111111));
                utf8String.push_back(byte1);
                utf8String.push_back(byte2);
                utf8String.push_back(byte3);
                utf8String.push_back(byte4);
                break;
            default:
                return;
        }  // end switch
    }  // end while
}

int StringBuilder::getUtf8StringLength(const std::string &utf8String) {
    int rawLength = static_cast<int>(utf8String.length());
    int length = 0;
    int index;
    for (index = 0; index < rawLength; ++index) {
        if (isFirstByte(utf8String[index])) {
            length = length + 1;
        }
    }
    return length;
}

boolean StringBuilder::isFirstByte(char target) {
    return (target & 0b11000000) != 0b10000000;
}

int StringBuilder::getNumberOfTrailingBytesAfterFirstByte(char firstByte) {
    if ((firstByte & 0b10000000) == 0b00000000) {
        return 0;
    }

    if ((firstByte & 0b11100000) == 0b11000000) {
        return 1;
    }

    if ((firstByte & 0b11110000) == 0b11100000) {
        return 2;
    }

    if ((firstByte & 0b11111000) == 0b11110000) {
        return 3;
    }

    // Not first byte.
    return -1;
}
