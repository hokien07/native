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

HashMap<String, Character::UnicodeBlock> Character::UnicodeBlock::map;

Character::UnicodeBlock::UnicodeBlock(const String &name) : Subset(name) {}

Character::UnicodeBlock Character::UnicodeBlock::BASIC_LATIN = UnicodeBlock("BASIC_LATIN",
                                                                            "BASIC LATIN",
                                                                            "BASICLATIN");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_1_SUPPLEMENT = UnicodeBlock("LATIN_1_SUPPLEMENT",
                                                                                   "LATIN-1 SUPPLEMENT",
                                                                                   "LATIN-1SUPPMENT");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_EXTENDED_A = UnicodeBlock("LATIN_EXTENDED_A",
                                                                                 "LATIN EXTENDED-A",
                                                                                 "LATINEXTENDED-A");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_EXTENDED_B = UnicodeBlock("LATIN_EXTENDED_B",
                                                                                 "LATIN EXTENDED-B",
                                                                                 "LATINEXTENDED-B");

Character::UnicodeBlock Character::UnicodeBlock::IPA_EXTENSIONS = UnicodeBlock("IPA_EXTENSIONS",
                                                                               "IPA EXTENSIONS",
                                                                               "IPAEXTENSIONS");

Character::UnicodeBlock Character::UnicodeBlock::SPACING_MODIFIER_LETTERS = UnicodeBlock("SPACING_MODIFIER_LETTERS",
                                                                                         "SPACING MODIFIER LETTERS",
                                                                                         "SPACINGMODIFIERLETTERS");

Character::UnicodeBlock Character::UnicodeBlock::COMBINING_DIACRITICAL_MARKS = UnicodeBlock("COMBINING_DIACRITICAL_MARKS",
                                                                                            "COMBINING DIACRITICAL MARKS",
                                                                                            "COMBININGDIACRITICALMARKS");

Character::UnicodeBlock Character::UnicodeBlock::GREEK = UnicodeBlock("GREEK", "GREEK AND COPTIC", "GREEKANDCOPTIC");

Character::UnicodeBlock Character::UnicodeBlock::CYRILLIC = UnicodeBlock("CYRILLIC");

Character::UnicodeBlock Character::UnicodeBlock::ARMENIAN = UnicodeBlock("ARMENIAN");

Character::UnicodeBlock Character::UnicodeBlock::HEBREW = UnicodeBlock("HEBREW");

Character::UnicodeBlock Character::UnicodeBlock::ARABIC = UnicodeBlock("ARABIC");

Character::UnicodeBlock Character::UnicodeBlock::DEVANAGARI = UnicodeBlock("DEVANAGARI");

Character::UnicodeBlock Character::UnicodeBlock::BENGALI = UnicodeBlock("BENGALI");

Character::UnicodeBlock Character::UnicodeBlock::GURMUKHI = UnicodeBlock("GURMUKHI");

Character::UnicodeBlock Character::UnicodeBlock::GUJARATI = UnicodeBlock("GUJARATI");

Character::UnicodeBlock Character::UnicodeBlock::ORIYA = UnicodeBlock("ORIYA");

Character::UnicodeBlock Character::UnicodeBlock::TAMIL = UnicodeBlock("TAMIL");

Character::UnicodeBlock Character::UnicodeBlock::TELUGU = UnicodeBlock("TELUGU");

Character::UnicodeBlock Character::UnicodeBlock::KANNADA = UnicodeBlock("KANNADA");

Character::UnicodeBlock Character::UnicodeBlock::MALAYALAM = UnicodeBlock("MALAYALAM");

Character::UnicodeBlock Character::UnicodeBlock::THAI = UnicodeBlock("THAI");

Character::UnicodeBlock Character::UnicodeBlock::LAO = UnicodeBlock("LAO");

Character::UnicodeBlock Character::UnicodeBlock::TIBETAN = UnicodeBlock("TIBETAN");

Character::UnicodeBlock Character::UnicodeBlock::GEORGIAN = UnicodeBlock("GEORGIAN");

Character::UnicodeBlock Character::UnicodeBlock::HANGUL_JAMO = UnicodeBlock("HANGUL_JAMO",
                                                                            "HANGUL JAMO",
                                                                            "HANGULJAMO");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_EXTENDED_ADDITIONAL = UnicodeBlock("LATIN_EXTENDED_ADDITIONAL",
                                                                                          "LATIN EXTENDED ADDITIONAL",
                                                                                          "LATINEXTENDEDADDITIONAL");

Character::UnicodeBlock Character::UnicodeBlock::GREEK_EXTENDED = UnicodeBlock("GREEK_EXTENDED",
                                                                               "GREEK EXTENDED",
                                                                               "GREEKEXTENDED");

Character::UnicodeBlock Character::UnicodeBlock::GENERAL_PUNCTUATION = UnicodeBlock("GENERAL_PUNCTUATION",
                                                                                    "GENERAL PUNCTUATION",
                                                                                    "GENERALPUNCTUATION");

Character::UnicodeBlock Character::UnicodeBlock::SUPERSCRIPTS_AND_SUBSCRIPTS = UnicodeBlock("SUPERSCRIPTS_AND_SUBSCRIPTS",
                                                                                            "SUPERSCRIPTS AND SUBSCRIPTS",
                                                                                            "SUPERSCRIPTSANDSUBSCRIPTS");

Character::UnicodeBlock Character::UnicodeBlock::CURRENCY_SYMBOLS = UnicodeBlock("CURRENCY_SYMBOLS",
                                                                                 "CURRENCY SYMBOLS",
                                                                                 "CURRENCYSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::COMBINING_MARKS_FOR_SYMBOLS = UnicodeBlock("COMBINING_MARKS_FOR_SYMBOLS",
                                                                                            "COMBINING DIACRITICAL MARKS FOR SYMBOLS",
                                                                                            "COMBININGDIACRITICALMARKSFORSYMBOLS",
                                                                                            "COMBINING MARKS FOR SYMBOLS",
                                                                                            "COMBININGMARKSFORSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::LETTERLIKE_SYMBOLS = UnicodeBlock("LETTERLIKE_SYMBOLS",
                                                                                   "LETTERLIKE SYMBOLS",
                                                                                   "LETTERLIKESYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::NUMBER_FORMS = UnicodeBlock("NUMBER_FORMS",
                                                                             "NUMBER FORMS",
                                                                             "NUMBERFORMS");

Character::UnicodeBlock Character::UnicodeBlock::ARROWS = UnicodeBlock("ARROWS");

Character::UnicodeBlock Character::UnicodeBlock::MATHEMATICAL_OPERATORS = UnicodeBlock("MATHEMATICAL_OPERATORS",
                                                                                       "MATHEMATICAL OPERATORS",
                                                                                       "MATHEMATICALOPERATORS");

Character::UnicodeBlock Character::UnicodeBlock::MISCELLANEOUS_TECHNICAL = UnicodeBlock("MISCELLANEOUS_TECHNICAL",
                                                                                        "MISCELLANEOUS TECHNICAL",
                                                                                        "MISCELLANEOUSTECHNICAL");

Character::UnicodeBlock Character::UnicodeBlock::CONTROL_PICTURES = UnicodeBlock("CONTROL_PICTURES",
                                                                                 "CONTROL PICTURES",
                                                                                 "CONTROLPICTURES");

Character::UnicodeBlock Character::UnicodeBlock::OPTICAL_CHARACTER_RECOGNITION = UnicodeBlock("OPTICAL_CHARACTER_RECOGNITION",
                                                                                              "OPTICAL CHARACTER RECOGNITION",
                                                                                              "OPTICALCHARACTERRECOGNITION");

Character::UnicodeBlock Character::UnicodeBlock::ENCLOSED_ALPHANUMERICS = UnicodeBlock("ENCLOSED_ALPHANUMERICS",
                                                                                       "ENCLOSED ALPHANUMERICS",
                                                                                       "ENCLOSEDALPHANUMERICS");

Character::UnicodeBlock Character::UnicodeBlock::BOX_DRAWING = UnicodeBlock("BOX_DRAWING",
                                                                            "BOX DRAWING",
                                                                            "BOXDRAWING");
Character::UnicodeBlock Character::UnicodeBlock::BLOCK_ELEMENTS = UnicodeBlock("BLOCK_ELEMENTS",
                                                                               "BLOCK ELEMENTS",
                                                                               "BLOCKELEMENTS");

Character::UnicodeBlock Character::UnicodeBlock::GEOMETRIC_SHAPES = UnicodeBlock("GEOMETRIC_SHAPES",
                                                                                 "GEOMETRIC SHAPES",
                                                                                 "GEOMETRICSHAPES");

Character::UnicodeBlock Character::UnicodeBlock::MISCELLANEOUS_SYMBOLS = UnicodeBlock("MISCELLANEOUS_SYMBOLS",
                                                                                      "MISCELLANEOUS SYMBOLS",
                                                                                      "MISCELLANEOUSSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::DINGBATS = UnicodeBlock("DINGBATS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_SYMBOLS_AND_PUNCTUATION = UnicodeBlock("CJK_SYMBOLS_AND_PUNCTUATION",
                                                                                            "CJK SYMBOLS AND PUNCTUATION",
                                                                                            "CJKSYMBOLSANDPUNCTUATION");

Character::UnicodeBlock Character::UnicodeBlock::HIRAGANA = UnicodeBlock("HIRAGANA");

Character::UnicodeBlock Character::UnicodeBlock::KATAKANA = UnicodeBlock("KATAKANA");

Character::UnicodeBlock Character::UnicodeBlock::BOPOMOFO = UnicodeBlock("BOPOMOFO");

Character::UnicodeBlock Character::UnicodeBlock::HANGUL_COMPATIBILITY_JAMO = UnicodeBlock("HANGUL_COMPATIBILITY_JAMO",
                                                                                          "HANGUL COMPATIBILITY JAMO",
                                                                                          "HANGULCOMPATIBILITYJAMO");

Character::UnicodeBlock Character::UnicodeBlock::KANBUN = UnicodeBlock("KANBUN");

Character::UnicodeBlock Character::UnicodeBlock::ENCLOSED_CJK_LETTERS_AND_MONTHS = UnicodeBlock("ENCLOSED_CJK_LETTERS_AND_MONTHS",
                                                                                                "ENCLOSED CJK LETTERS AND MONTHS",
                                                                                                "ENCLOSEDCJKLETTERSANDMONTHS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_COMPATIBILITY = UnicodeBlock("CJK_COMPATIBILITY",
                                                                                  "CJK COMPATIBILITY",
                                                                                  "CJKCOMPATIBILITY");

Character::UnicodeBlock Character::UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS = UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS",
                                                                                       "CJK UNIFIED IDEOGRAPHS",
                                                                                       "CJKUNIFIEDIDEOGRAPHS");

Character::UnicodeBlock Character::UnicodeBlock::HANGUL_SYLLABLES = UnicodeBlock("HANGUL_SYLLABLES",
                                                                                 "HANGUL SYLLABLES",
                                                                                 "HANGULSYLLABLES");

Character::UnicodeBlock Character::UnicodeBlock::PRIVATE_USE_AREA = UnicodeBlock("PRIVATE_USE_AREA",
                                                                                 "PRIVATE USE AREA",
                                                                                 "PRIVATEUSEAREA");

Character::UnicodeBlock Character::UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS = UnicodeBlock("CJK_COMPATIBILITY_IDEOGRAPHS",
                                                                                             "CJK COMPATIBILITY IDEOGRAPHS",
                                                                                             "CJKCOMPATIBILITYIDEOGRAPHS");

Character::UnicodeBlock Character::UnicodeBlock::ALPHABETIC_PRESENTATION_FORMS = UnicodeBlock("ALPHABETIC_PRESENTATION_FORMS",
                                                                                              "ALPHABETIC PRESENTATION FORMS",
                                                                                              "ALPHABETICPRESENTATIONFORMS");

Character::UnicodeBlock Character::UnicodeBlock::ARABIC_PRESENTATION_FORMS_A = UnicodeBlock("ARABIC_PRESENTATION_FORMS_A",
                                                                                            "ARABIC PRESENTATION FORMS-A",
                                                                                            "ARABICPRESENTATIONFORMS-A");

Character::UnicodeBlock Character::UnicodeBlock::COMBINING_HALF_MARKS = UnicodeBlock("COMBINING_HALF_MARKS",
                                                                                     "COMBINING HALF MARKS",
                                                                                     "COMBININGHALFMARKS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_COMPATIBILITY_FORMS = UnicodeBlock("CJK_COMPATIBILITY_FORMS",
                                                                                        "CJK COMPATIBILITY FORMS",
                                                                                        "CJKCOMPATIBILITYFORMS");

Character::UnicodeBlock Character::UnicodeBlock::SMALL_FORM_VARIANTS = UnicodeBlock("SMALL_FORM_VARIANTS",
                                                                                    "SMALL FORM VARIANTS",
                                                                                    "SMALLFORMVARIANTS");

Character::UnicodeBlock Character::UnicodeBlock::ARABIC_PRESENTATION_FORMS_B = UnicodeBlock("ARABIC_PRESENTATION_FORMS_B",
                                                                                            "ARABIC PRESENTATION FORMS-B",
                                                                                            "ARABICPRESENTATIONFORMS-B");

Character::UnicodeBlock Character::UnicodeBlock::HALFWIDTH_AND_FULLWIDTH_FORMS = UnicodeBlock("HALFWIDTH_AND_FULLWIDTH_FORMS",
                                                                                              "HALFWIDTH AND FULLWIDTH FORMS",
                                                                                              "HALFWIDTHANDFULLWIDTHFORMS");

Character::UnicodeBlock Character::UnicodeBlock::SPECIALS = UnicodeBlock("SPECIALS");

Character::UnicodeBlock Character::UnicodeBlock::SYRIAC = UnicodeBlock("SYRIAC");

Character::UnicodeBlock Character::UnicodeBlock::THAANA = UnicodeBlock("THAANA");

Character::UnicodeBlock Character::UnicodeBlock::SINHALA = UnicodeBlock("SINHALA");

Character::UnicodeBlock Character::UnicodeBlock::MYANMAR = UnicodeBlock("MYANMAR");

/**
 * Constant for the "Ethiopic" Unicode character block.
 * @since 1.4
 */
ETHIOPIC =
        UnicodeBlock("ETHIOPIC");

/**
 * Constant for the "Cherokee" Unicode character block.
 * @since 1.4
 */
CHEROKEE =
        UnicodeBlock("CHEROKEE");

/**
 * Constant for the "Unified Canadian Aboriginal Syllabics" Unicode character block.
 * @since 1.4
 */
UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS =
        UnicodeBlock("UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS",
                     "UNIFIED CANADIAN ABORIGINAL SYLLABICS",
                     "UNIFIEDCANADIANABORIGINALSYLLABICS");

/**
 * Constant for the "Ogham" Unicode character block.
 * @since 1.4
 */
OGHAM =
        UnicodeBlock("OGHAM");

/**
 * Constant for the "Runic" Unicode character block.
 * @since 1.4
 */
RUNIC =
        UnicodeBlock("RUNIC");

/**
 * Constant for the "Khmer" Unicode character block.
 * @since 1.4
 */
KHMER =
        UnicodeBlock("KHMER");

/**
 * Constant for the "Mongolian" Unicode character block.
 * @since 1.4
 */
MONGOLIAN =
        UnicodeBlock("MONGOLIAN");

/**
 * Constant for the "Braille Patterns" Unicode character block.
 * @since 1.4
 */
BRAILLE_PATTERNS =
        UnicodeBlock("BRAILLE_PATTERNS",
                     "BRAILLE PATTERNS",
                     "BRAILLEPATTERNS");

/**
 * Constant for the "CJK Radicals Supplement" Unicode character block.
 * @since 1.4
 */
CJK_RADICALS_SUPPLEMENT =
        UnicodeBlock("CJK_RADICALS_SUPPLEMENT",
                     "CJK RADICALS SUPPLEMENT",
                     "CJKRADICALSSUPPLEMENT");

/**
 * Constant for the "Kangxi Radicals" Unicode character block.
 * @since 1.4
 */
KANGXI_RADICALS =
        UnicodeBlock("KANGXI_RADICALS",
                     "KANGXI RADICALS",
                     "KANGXIRADICALS");

/**
 * Constant for the "Ideographic Description Characters" Unicode character block.
 * @since 1.4
 */
IDEOGRAPHIC_DESCRIPTION_CHARACTERS =
        UnicodeBlock("IDEOGRAPHIC_DESCRIPTION_CHARACTERS",
                     "IDEOGRAPHIC DESCRIPTION CHARACTERS",
                     "IDEOGRAPHICDESCRIPTIONCHARACTERS");

/**
 * Constant for the "Bopomofo Extended" Unicode character block.
 * @since 1.4
 */
BOPOMOFO_EXTENDED =
        UnicodeBlock("BOPOMOFO_EXTENDED",
                     "BOPOMOFO EXTENDED",
                     "BOPOMOFOEXTENDED");

/**
 * Constant for the "CJK Unified Ideographs Extension A" Unicode character block.
 * @since 1.4
 */
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A",
                     "CJK UNIFIED IDEOGRAPHS EXTENSION A",
                     "CJKUNIFIEDIDEOGRAPHSEXTENSIONA");

/**
 * Constant for the "Yi Syllables" Unicode character block.
 * @since 1.4
 */
YI_SYLLABLES =
        UnicodeBlock("YI_SYLLABLES",
                     "YI SYLLABLES",
                     "YISYLLABLES");

/**
 * Constant for the "Yi Radicals" Unicode character block.
 * @since 1.4
 */
YI_RADICALS =
        UnicodeBlock("YI_RADICALS",
                     "YI RADICALS",
                     "YIRADICALS");

/**
 * Constant for the "Cyrillic Supplementary" Unicode character block.
 * @since 1.5
 */
CYRILLIC_SUPPLEMENTARY =
        UnicodeBlock("CYRILLIC_SUPPLEMENTARY",
                     "CYRILLIC SUPPLEMENTARY",
                     "CYRILLICSUPPLEMENTARY",
                     "CYRILLIC SUPPLEMENT",
                     "CYRILLICSUPPLEMENT");

/**
 * Constant for the "Tagalog" Unicode character block.
 * @since 1.5
 */
TAGALOG =
        UnicodeBlock("TAGALOG");

/**
 * Constant for the "Hanunoo" Unicode character block.
 * @since 1.5
 */
HANUNOO =
        UnicodeBlock("HANUNOO");

/**
 * Constant for the "Buhid" Unicode character block.
 * @since 1.5
 */
BUHID =
        UnicodeBlock("BUHID");

/**
 * Constant for the "Tagbanwa" Unicode character block.
 * @since 1.5
 */
TAGBANWA =
        UnicodeBlock("TAGBANWA");

/**
 * Constant for the "Limbu" Unicode character block.
 * @since 1.5
 */
LIMBU =
        UnicodeBlock("LIMBU");

/**
 * Constant for the "Tai Le" Unicode character block.
 * @since 1.5
 */
TAI_LE =
        UnicodeBlock("TAI_LE",
                     "TAI LE",
                     "TAILE");

/**
 * Constant for the "Khmer Symbols" Unicode character block.
 * @since 1.5
 */
KHMER_SYMBOLS =
        UnicodeBlock("KHMER_SYMBOLS",
                     "KHMER SYMBOLS",
                     "KHMERSYMBOLS");

/**
 * Constant for the "Phonetic Extensions" Unicode character block.
 * @since 1.5
 */
PHONETIC_EXTENSIONS =
        UnicodeBlock("PHONETIC_EXTENSIONS",
                     "PHONETIC EXTENSIONS",
                     "PHONETICEXTENSIONS");

/**
 * Constant for the "Miscellaneous Mathematical Symbols-A" Unicode character block.
 * @since 1.5
 */
MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A =
        UnicodeBlock("MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A",
                     "MISCELLANEOUS MATHEMATICAL SYMBOLS-A",
                     "MISCELLANEOUSMATHEMATICALSYMBOLS-A");

/**
 * Constant for the "Supplemental Arrows-A" Unicode character block.
 * @since 1.5
 */
SUPPLEMENTAL_ARROWS_A =
        UnicodeBlock("SUPPLEMENTAL_ARROWS_A",
                     "SUPPLEMENTAL ARROWS-A",
                     "SUPPLEMENTALARROWS-A");

/**
 * Constant for the "Supplemental Arrows-B" Unicode character block.
 * @since 1.5
 */
SUPPLEMENTAL_ARROWS_B =
        UnicodeBlock("SUPPLEMENTAL_ARROWS_B",
                     "SUPPLEMENTAL ARROWS-B",
                     "SUPPLEMENTALARROWS-B");

/**
 * Constant for the "Miscellaneous Mathematical Symbols-B" Unicode
 * character block.
 * @since 1.5
 */
MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B =
        UnicodeBlock("MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B",
                     "MISCELLANEOUS MATHEMATICAL SYMBOLS-B",
                     "MISCELLANEOUSMATHEMATICALSYMBOLS-B");

/**
 * Constant for the "Supplemental Mathematical Operators" Unicode
 * character block.
 * @since 1.5
 */
SUPPLEMENTAL_MATHEMATICAL_OPERATORS =
        UnicodeBlock("SUPPLEMENTAL_MATHEMATICAL_OPERATORS",
                     "SUPPLEMENTAL MATHEMATICAL OPERATORS",
                     "SUPPLEMENTALMATHEMATICALOPERATORS");

/**
 * Constant for the "Miscellaneous Symbols and Arrows" Unicode character
 * block.
 * @since 1.5
 */
MISCELLANEOUS_SYMBOLS_AND_ARROWS =
        UnicodeBlock("MISCELLANEOUS_SYMBOLS_AND_ARROWS",
                     "MISCELLANEOUS SYMBOLS AND ARROWS",
                     "MISCELLANEOUSSYMBOLSANDARROWS");

/**
 * Constant for the "Katakana Phonetic Extensions" Unicode character
 * block.
 * @since 1.5
 */
KATAKANA_PHONETIC_EXTENSIONS =
        UnicodeBlock("KATAKANA_PHONETIC_EXTENSIONS",
                     "KATAKANA PHONETIC EXTENSIONS",
                     "KATAKANAPHONETICEXTENSIONS");

/**
 * Constant for the "Yijing Hexagram Symbols" Unicode character block.
 * @since 1.5
 */
YIJING_HEXAGRAM_SYMBOLS =
        UnicodeBlock("YIJING_HEXAGRAM_SYMBOLS",
                     "YIJING HEXAGRAM SYMBOLS",
                     "YIJINGHEXAGRAMSYMBOLS");

/**
 * Constant for the "Variation Selectors" Unicode character block.
 * @since 1.5
 */
VARIATION_SELECTORS =
        UnicodeBlock("VARIATION_SELECTORS",
                     "VARIATION SELECTORS",
                     "VARIATIONSELECTORS");

/**
 * Constant for the "Linear B Syllabary" Unicode character block.
 * @since 1.5
 */
LINEAR_B_SYLLABARY =
        UnicodeBlock("LINEAR_B_SYLLABARY",
                     "LINEAR B SYLLABARY",
                     "LINEARBSYLLABARY");

/**
 * Constant for the "Linear B Ideograms" Unicode character block.
 * @since 1.5
 */
LINEAR_B_IDEOGRAMS =
        UnicodeBlock("LINEAR_B_IDEOGRAMS",
                     "LINEAR B IDEOGRAMS",
                     "LINEARBIDEOGRAMS");

/**
 * Constant for the "Aegean Numbers" Unicode character block.
 * @since 1.5
 */
AEGEAN_NUMBERS =
        UnicodeBlock("AEGEAN_NUMBERS",
                     "AEGEAN NUMBERS",
                     "AEGEANNUMBERS");

/**
 * Constant for the "Old Italic" Unicode character block.
 * @since 1.5
 */
OLD_ITALIC =
        UnicodeBlock("OLD_ITALIC",
                     "OLD ITALIC",
                     "OLDITALIC");

/**
 * Constant for the "Gothic" Unicode character block.
 * @since 1.5
 */
GOTHIC =
        UnicodeBlock("GOTHIC");

/**
 * Constant for the "Ugaritic" Unicode character block.
 * @since 1.5
 */
UGARITIC =
        UnicodeBlock("UGARITIC");

/**
 * Constant for the "Deseret" Unicode character block.
 * @since 1.5
 */
DESERET =
        UnicodeBlock("DESERET");

/**
 * Constant for the "Shavian" Unicode character block.
 * @since 1.5
 */
SHAVIAN =
        UnicodeBlock("SHAVIAN");

/**
 * Constant for the "Osmanya" Unicode character block.
 * @since 1.5
 */
OSMANYA =
        UnicodeBlock("OSMANYA");

/**
 * Constant for the "Cypriot Syllabary" Unicode character block.
 * @since 1.5
 */
CYPRIOT_SYLLABARY =
        UnicodeBlock("CYPRIOT_SYLLABARY",
                     "CYPRIOT SYLLABARY",
                     "CYPRIOTSYLLABARY");

/**
 * Constant for the "Byzantine Musical Symbols" Unicode character block.
 * @since 1.5
 */
BYZANTINE_MUSICAL_SYMBOLS =
        UnicodeBlock("BYZANTINE_MUSICAL_SYMBOLS",
                     "BYZANTINE MUSICAL SYMBOLS",
                     "BYZANTINEMUSICALSYMBOLS");

/**
 * Constant for the "Musical Symbols" Unicode character block.
 * @since 1.5
 */
MUSICAL_SYMBOLS =
        UnicodeBlock("MUSICAL_SYMBOLS",
                     "MUSICAL SYMBOLS",
                     "MUSICALSYMBOLS");

/**
 * Constant for the "Tai Xuan Jing Symbols" Unicode character block.
 * @since 1.5
 */
TAI_XUAN_JING_SYMBOLS =
        UnicodeBlock("TAI_XUAN_JING_SYMBOLS",
                     "TAI XUAN JING SYMBOLS",
                     "TAIXUANJINGSYMBOLS");

/**
 * Constant for the "Mathematical Alphanumeric Symbols" Unicode
 * character block.
 * @since 1.5
 */
MATHEMATICAL_ALPHANUMERIC_SYMBOLS =
        UnicodeBlock("MATHEMATICAL_ALPHANUMERIC_SYMBOLS",
                     "MATHEMATICAL ALPHANUMERIC SYMBOLS",
                     "MATHEMATICALALPHANUMERICSYMBOLS");

/**
 * Constant for the "CJK Unified Ideographs Extension B" Unicode
 * character block.
 * @since 1.5
 */
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B",
                     "CJK UNIFIED IDEOGRAPHS EXTENSION B",
                     "CJKUNIFIEDIDEOGRAPHSEXTENSIONB");

/**
 * Constant for the "CJK Compatibility Ideographs Supplement" Unicode character block.
 * @since 1.5
 */
CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT =
        UnicodeBlock("CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT",
                     "CJK COMPATIBILITY IDEOGRAPHS SUPPLEMENT",
                     "CJKCOMPATIBILITYIDEOGRAPHSSUPPLEMENT");

/**
 * Constant for the "Tags" Unicode character block.
 * @since 1.5
 */
TAGS =
        UnicodeBlock("TAGS");

/**
 * Constant for the "Variation Selectors Supplement" Unicode character
 * block.
 * @since 1.5
 */
VARIATION_SELECTORS_SUPPLEMENT =
        UnicodeBlock("VARIATION_SELECTORS_SUPPLEMENT",
                     "VARIATION SELECTORS SUPPLEMENT",
                     "VARIATIONSELECTORSSUPPLEMENT");

/**
 * Constant for the "Supplementary Private Use Area-A" Unicode character
 * block.
 * @since 1.5
 */
SUPPLEMENTARY_PRIVATE_USE_AREA_A =
        UnicodeBlock("SUPPLEMENTARY_PRIVATE_USE_AREA_A",
                     "SUPPLEMENTARY PRIVATE USE AREA-A",
                     "SUPPLEMENTARYPRIVATEUSEAREA-A");

/**
 * Constant for the "Supplementary Private Use Area-B" Unicode character
 * block.
 * @since 1.5
 */
SUPPLEMENTARY_PRIVATE_USE_AREA_B =
        UnicodeBlock("SUPPLEMENTARY_PRIVATE_USE_AREA_B",
                     "SUPPLEMENTARY PRIVATE USE AREA-B",
                     "SUPPLEMENTARYPRIVATEUSEAREA-B");

/**
 * Constant for the "High Surrogates" Unicode character block.
 * This block represents codepoint values in the high surrogate
 * range: U+D800 through U+DB7F
 *
 * @since 1.5
 */
HIGH_SURROGATES =
        UnicodeBlock("HIGH_SURROGATES",
                     "HIGH SURROGATES",
                     "HIGHSURROGATES");

/**
 * Constant for the "High Private Use Surrogates" Unicode character
 * block.
 * This block represents codepoint values in the private use high
 * surrogate range: U+DB80 through U+DBFF
 *
 * @since 1.5
 */
HIGH_PRIVATE_USE_SURROGATES =
        UnicodeBlock("HIGH_PRIVATE_USE_SURROGATES",
                     "HIGH PRIVATE USE SURROGATES",
                     "HIGHPRIVATEUSESURROGATES");

/**
 * Constant for the "Low Surrogates" Unicode character block.
 * This block represents codepoint values in the low surrogate
 * range: U+DC00 through U+DFFF
 *
 * @since 1.5
 */
LOW_SURROGATES =
        UnicodeBlock("LOW_SURROGATES",
                     "LOW SURROGATES",
                     "LOWSURROGATES");

/**
 * Constant for the "Arabic Supplement" Unicode character block.
 * @since 1.7
 */
ARABIC_SUPPLEMENT =
        UnicodeBlock("ARABIC_SUPPLEMENT",
                     "ARABIC SUPPLEMENT",
                     "ARABICSUPPLEMENT");

/**
 * Constant for the "NKo" Unicode character block.
 * @since 1.7
 */
NKO =
        UnicodeBlock("NKO");

/**
 * Constant for the "Samaritan" Unicode character block.
 * @since 1.7
 */
SAMARITAN =
        UnicodeBlock("SAMARITAN");

/**
 * Constant for the "Mandaic" Unicode character block.
 * @since 1.7
 */
MANDAIC =
        UnicodeBlock("MANDAIC");

/**
 * Constant for the "Ethiopic Supplement" Unicode character block.
 * @since 1.7
 */
ETHIOPIC_SUPPLEMENT =
        UnicodeBlock("ETHIOPIC_SUPPLEMENT",
                     "ETHIOPIC SUPPLEMENT",
                     "ETHIOPICSUPPLEMENT");

/**
 * Constant for the "Unified Canadian Aboriginal Syllabics Extended"
 * Unicode character block.
 * @since 1.7
 */
UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED =
        UnicodeBlock("UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED",
                     "UNIFIED CANADIAN ABORIGINAL SYLLABICS EXTENDED",
                     "UNIFIEDCANADIANABORIGINALSYLLABICSEXTENDED");

/**
 * Constant for the "New Tai Lue" Unicode character block.
 * @since 1.7
 */
NEW_TAI_LUE =
        UnicodeBlock("NEW_TAI_LUE",
                     "NEW TAI LUE",
                     "NEWTAILUE");

/**
 * Constant for the "Buginese" Unicode character block.
 * @since 1.7
 */
BUGINESE =
        UnicodeBlock("BUGINESE");

/**
 * Constant for the "Tai Tham" Unicode character block.
 * @since 1.7
 */
TAI_THAM =
        UnicodeBlock("TAI_THAM",
                     "TAI THAM",
                     "TAITHAM");

/**
 * Constant for the "Balinese" Unicode character block.
 * @since 1.7
 */
BALINESE =
        UnicodeBlock("BALINESE");

/**
 * Constant for the "Sundanese" Unicode character block.
 * @since 1.7
 */
SUNDANESE =
        UnicodeBlock("SUNDANESE");

/**
 * Constant for the "Batak" Unicode character block.
 * @since 1.7
 */
BATAK =
        UnicodeBlock("BATAK");

/**
 * Constant for the "Lepcha" Unicode character block.
 * @since 1.7
 */
LEPCHA =
        UnicodeBlock("LEPCHA");

/**
 * Constant for the "Ol Chiki" Unicode character block.
 * @since 1.7
 */
OL_CHIKI =
        UnicodeBlock("OL_CHIKI",
                     "OL CHIKI",
                     "OLCHIKI");

/**
 * Constant for the "Vedic Extensions" Unicode character block.
 * @since 1.7
 */
VEDIC_EXTENSIONS =
        UnicodeBlock("VEDIC_EXTENSIONS",
                     "VEDIC EXTENSIONS",
                     "VEDICEXTENSIONS");

/**
 * Constant for the "Phonetic Extensions Supplement" Unicode character
 * block.
 * @since 1.7
 */
PHONETIC_EXTENSIONS_SUPPLEMENT =
        UnicodeBlock("PHONETIC_EXTENSIONS_SUPPLEMENT",
                     "PHONETIC EXTENSIONS SUPPLEMENT",
                     "PHONETICEXTENSIONSSUPPLEMENT");

/**
 * Constant for the "Combining Diacritical Marks Supplement" Unicode
 * character block.
 * @since 1.7
 */
COMBINING_DIACRITICAL_MARKS_SUPPLEMENT =
        UnicodeBlock("COMBINING_DIACRITICAL_MARKS_SUPPLEMENT",
                     "COMBINING DIACRITICAL MARKS SUPPLEMENT",
                     "COMBININGDIACRITICALMARKSSUPPLEMENT");

/**
 * Constant for the "Glagolitic" Unicode character block.
 * @since 1.7
 */
GLAGOLITIC =
        UnicodeBlock("GLAGOLITIC");

/**
 * Constant for the "Latin Extended-C" Unicode character block.
 * @since 1.7
 */
LATIN_EXTENDED_C =
        UnicodeBlock("LATIN_EXTENDED_C",
                     "LATIN EXTENDED-C",
                     "LATINEXTENDED-C");

/**
 * Constant for the "Coptic" Unicode character block.
 * @since 1.7
 */
COPTIC =
        UnicodeBlock("COPTIC");

/**
 * Constant for the "Georgian Supplement" Unicode character block.
 * @since 1.7
 */
GEORGIAN_SUPPLEMENT =
        UnicodeBlock("GEORGIAN_SUPPLEMENT",
                     "GEORGIAN SUPPLEMENT",
                     "GEORGIANSUPPLEMENT");

/**
 * Constant for the "Tifinagh" Unicode character block.
 * @since 1.7
 */
TIFINAGH =
        UnicodeBlock("TIFINAGH");

/**
 * Constant for the "Ethiopic Extended" Unicode character block.
 * @since 1.7
 */
ETHIOPIC_EXTENDED =
        UnicodeBlock("ETHIOPIC_EXTENDED",
                     "ETHIOPIC EXTENDED",
                     "ETHIOPICEXTENDED");

/**
 * Constant for the "Cyrillic Extended-A" Unicode character block.
 * @since 1.7
 */
CYRILLIC_EXTENDED_A =
        UnicodeBlock("CYRILLIC_EXTENDED_A",
                     "CYRILLIC EXTENDED-A",
                     "CYRILLICEXTENDED-A");

/**
 * Constant for the "Supplemental Punctuation" Unicode character block.
 * @since 1.7
 */
SUPPLEMENTAL_PUNCTUATION =
        UnicodeBlock("SUPPLEMENTAL_PUNCTUATION",
                     "SUPPLEMENTAL PUNCTUATION",
                     "SUPPLEMENTALPUNCTUATION");

/**
 * Constant for the "CJK Strokes" Unicode character block.
 * @since 1.7
 */
CJK_STROKES =
        UnicodeBlock("CJK_STROKES",
                     "CJK STROKES",
                     "CJKSTROKES");

/**
 * Constant for the "Lisu" Unicode character block.
 * @since 1.7
 */
LISU =
        UnicodeBlock("LISU");

/**
 * Constant for the "Vai" Unicode character block.
 * @since 1.7
 */
VAI =
        UnicodeBlock("VAI");

/**
 * Constant for the "Cyrillic Extended-B" Unicode character block.
 * @since 1.7
 */
CYRILLIC_EXTENDED_B =
        UnicodeBlock("CYRILLIC_EXTENDED_B",
                     "CYRILLIC EXTENDED-B",
                     "CYRILLICEXTENDED-B");

/**
 * Constant for the "Bamum" Unicode character block.
 * @since 1.7
 */
BAMUM =
        UnicodeBlock("BAMUM");

/**
 * Constant for the "Modifier Tone Letters" Unicode character block.
 * @since 1.7
 */
MODIFIER_TONE_LETTERS =
        UnicodeBlock("MODIFIER_TONE_LETTERS",
                     "MODIFIER TONE LETTERS",
                     "MODIFIERTONELETTERS");

/**
 * Constant for the "Latin Extended-D" Unicode character block.
 * @since 1.7
 */
LATIN_EXTENDED_D =
        UnicodeBlock("LATIN_EXTENDED_D",
                     "LATIN EXTENDED-D",
                     "LATINEXTENDED-D");

/**
 * Constant for the "Syloti Nagri" Unicode character block.
 * @since 1.7
 */
SYLOTI_NAGRI =
        UnicodeBlock("SYLOTI_NAGRI",
                     "SYLOTI NAGRI",
                     "SYLOTINAGRI");

/**
 * Constant for the "Common Indic Number Forms" Unicode character block.
 * @since 1.7
 */
COMMON_INDIC_NUMBER_FORMS =
        UnicodeBlock("COMMON_INDIC_NUMBER_FORMS",
                     "COMMON INDIC NUMBER FORMS",
                     "COMMONINDICNUMBERFORMS");

/**
 * Constant for the "Phags-pa" Unicode character block.
 * @since 1.7
 */
PHAGS_PA =
        UnicodeBlock("PHAGS_PA",
                     "PHAGS-PA");

/**
 * Constant for the "Saurashtra" Unicode character block.
 * @since 1.7
 */
SAURASHTRA =
        UnicodeBlock("SAURASHTRA");

/**
 * Constant for the "Devanagari Extended" Unicode character block.
 * @since 1.7
 */
DEVANAGARI_EXTENDED =
        UnicodeBlock("DEVANAGARI_EXTENDED",
                     "DEVANAGARI EXTENDED",
                     "DEVANAGARIEXTENDED");

/**
 * Constant for the "Kayah Li" Unicode character block.
 * @since 1.7
 */
KAYAH_LI =
        UnicodeBlock("KAYAH_LI",
                     "KAYAH LI",
                     "KAYAHLI");

/**
 * Constant for the "Rejang" Unicode character block.
 * @since 1.7
 */
REJANG =
        UnicodeBlock("REJANG");

/**
 * Constant for the "Hangul Jamo Extended-A" Unicode character block.
 * @since 1.7
 */
HANGUL_JAMO_EXTENDED_A =
        UnicodeBlock("HANGUL_JAMO_EXTENDED_A",
                     "HANGUL JAMO EXTENDED-A",
                     "HANGULJAMOEXTENDED-A");

/**
 * Constant for the "Javanese" Unicode character block.
 * @since 1.7
 */
JAVANESE =
        UnicodeBlock("JAVANESE");

/**
 * Constant for the "Cham" Unicode character block.
 * @since 1.7
 */
CHAM =
        UnicodeBlock("CHAM");

/**
 * Constant for the "Myanmar Extended-A" Unicode character block.
 * @since 1.7
 */
MYANMAR_EXTENDED_A =
        UnicodeBlock("MYANMAR_EXTENDED_A",
                     "MYANMAR EXTENDED-A",
                     "MYANMAREXTENDED-A");

/**
 * Constant for the "Tai Viet" Unicode character block.
 * @since 1.7
 */
TAI_VIET =
        UnicodeBlock("TAI_VIET",
                     "TAI VIET",
                     "TAIVIET");

/**
 * Constant for the "Ethiopic Extended-A" Unicode character block.
 * @since 1.7
 */
ETHIOPIC_EXTENDED_A =
        UnicodeBlock("ETHIOPIC_EXTENDED_A",
                     "ETHIOPIC EXTENDED-A",
                     "ETHIOPICEXTENDED-A");

/**
 * Constant for the "Meetei Mayek" Unicode character block.
 * @since 1.7
 */
MEETEI_MAYEK =
        UnicodeBlock("MEETEI_MAYEK",
                     "MEETEI MAYEK",
                     "MEETEIMAYEK");

/**
 * Constant for the "Hangul Jamo Extended-B" Unicode character block.
 * @since 1.7
 */
HANGUL_JAMO_EXTENDED_B =
        UnicodeBlock("HANGUL_JAMO_EXTENDED_B",
                     "HANGUL JAMO EXTENDED-B",
                     "HANGULJAMOEXTENDED-B");

/**
 * Constant for the "Vertical Forms" Unicode character block.
 * @since 1.7
 */
VERTICAL_FORMS =
        UnicodeBlock("VERTICAL_FORMS",
                     "VERTICAL FORMS",
                     "VERTICALFORMS");

/**
 * Constant for the "Ancient Greek Numbers" Unicode character block.
 * @since 1.7
 */
ANCIENT_GREEK_NUMBERS =
        UnicodeBlock("ANCIENT_GREEK_NUMBERS",
                     "ANCIENT GREEK NUMBERS",
                     "ANCIENTGREEKNUMBERS");

/**
 * Constant for the "Ancient Symbols" Unicode character block.
 * @since 1.7
 */
ANCIENT_SYMBOLS =
        UnicodeBlock("ANCIENT_SYMBOLS",
                     "ANCIENT SYMBOLS",
                     "ANCIENTSYMBOLS");

/**
 * Constant for the "Phaistos Disc" Unicode character block.
 * @since 1.7
 */
PHAISTOS_DISC =
        UnicodeBlock("PHAISTOS_DISC",
                     "PHAISTOS DISC",
                     "PHAISTOSDISC");

/**
 * Constant for the "Lycian" Unicode character block.
 * @since 1.7
 */
LYCIAN =
        UnicodeBlock("LYCIAN");

/**
 * Constant for the "Carian" Unicode character block.
 * @since 1.7
 */
CARIAN =
        UnicodeBlock("CARIAN");

/**
 * Constant for the "Old Persian" Unicode character block.
 * @since 1.7
 */
OLD_PERSIAN =
        UnicodeBlock("OLD_PERSIAN",
                     "OLD PERSIAN",
                     "OLDPERSIAN");

/**
 * Constant for the "Imperial Aramaic" Unicode character block.
 * @since 1.7
 */
IMPERIAL_ARAMAIC =
        UnicodeBlock("IMPERIAL_ARAMAIC",
                     "IMPERIAL ARAMAIC",
                     "IMPERIALARAMAIC");

/**
 * Constant for the "Phoenician" Unicode character block.
 * @since 1.7
 */
PHOENICIAN =
        UnicodeBlock("PHOENICIAN");

/**
 * Constant for the "Lydian" Unicode character block.
 * @since 1.7
 */
LYDIAN =
        UnicodeBlock("LYDIAN");

/**
 * Constant for the "Kharoshthi" Unicode character block.
 * @since 1.7
 */
KHAROSHTHI =
        UnicodeBlock("KHAROSHTHI");

/**
 * Constant for the "Old South Arabian" Unicode character block.
 * @since 1.7
 */
OLD_SOUTH_ARABIAN =
        UnicodeBlock("OLD_SOUTH_ARABIAN",
                     "OLD SOUTH ARABIAN",
                     "OLDSOUTHARABIAN");

/**
 * Constant for the "Avestan" Unicode character block.
 * @since 1.7
 */
AVESTAN =
        UnicodeBlock("AVESTAN");

/**
 * Constant for the "Inscriptional Parthian" Unicode character block.
 * @since 1.7
 */
INSCRIPTIONAL_PARTHIAN =
        UnicodeBlock("INSCRIPTIONAL_PARTHIAN",
                     "INSCRIPTIONAL PARTHIAN",
                     "INSCRIPTIONALPARTHIAN");

/**
 * Constant for the "Inscriptional Pahlavi" Unicode character block.
 * @since 1.7
 */
INSCRIPTIONAL_PAHLAVI =
        UnicodeBlock("INSCRIPTIONAL_PAHLAVI",
                     "INSCRIPTIONAL PAHLAVI",
                     "INSCRIPTIONALPAHLAVI");

/**
 * Constant for the "Old Turkic" Unicode character block.
 * @since 1.7
 */
OLD_TURKIC =
        UnicodeBlock("OLD_TURKIC",
                     "OLD TURKIC",
                     "OLDTURKIC");

/**
 * Constant for the "Rumi Numeral Symbols" Unicode character block.
 * @since 1.7
 */
RUMI_NUMERAL_SYMBOLS =
        UnicodeBlock("RUMI_NUMERAL_SYMBOLS",
                     "RUMI NUMERAL SYMBOLS",
                     "RUMINUMERALSYMBOLS");

/**
 * Constant for the "Brahmi" Unicode character block.
 * @since 1.7
 */
BRAHMI =
        UnicodeBlock("BRAHMI");

/**
 * Constant for the "Kaithi" Unicode character block.
 * @since 1.7
 */
KAITHI =
        UnicodeBlock("KAITHI");

/**
 * Constant for the "Cuneiform" Unicode character block.
 * @since 1.7
 */
CUNEIFORM =
        UnicodeBlock("CUNEIFORM");

/**
 * Constant for the "Cuneiform Numbers and Punctuation" Unicode
 * character block.
 * @since 1.7
 */
CUNEIFORM_NUMBERS_AND_PUNCTUATION =
        UnicodeBlock("CUNEIFORM_NUMBERS_AND_PUNCTUATION",
                     "CUNEIFORM NUMBERS AND PUNCTUATION",
                     "CUNEIFORMNUMBERSANDPUNCTUATION");

/**
 * Constant for the "Egyptian Hieroglyphs" Unicode character block.
 * @since 1.7
 */
EGYPTIAN_HIEROGLYPHS =
        UnicodeBlock("EGYPTIAN_HIEROGLYPHS",
                     "EGYPTIAN HIEROGLYPHS",
                     "EGYPTIANHIEROGLYPHS");

/**
 * Constant for the "Bamum Supplement" Unicode character block.
 * @since 1.7
 */
BAMUM_SUPPLEMENT =
        UnicodeBlock("BAMUM_SUPPLEMENT",
                     "BAMUM SUPPLEMENT",
                     "BAMUMSUPPLEMENT");

/**
 * Constant for the "Kana Supplement" Unicode character block.
 * @since 1.7
 */
KANA_SUPPLEMENT =
        UnicodeBlock("KANA_SUPPLEMENT",
                     "KANA SUPPLEMENT",
                     "KANASUPPLEMENT");

/**
 * Constant for the "Ancient Greek Musical Notation" Unicode character
 * block.
 * @since 1.7
 */
ANCIENT_GREEK_MUSICAL_NOTATION =
        UnicodeBlock("ANCIENT_GREEK_MUSICAL_NOTATION",
                     "ANCIENT GREEK MUSICAL NOTATION",
                     "ANCIENTGREEKMUSICALNOTATION");

/**
 * Constant for the "Counting Rod Numerals" Unicode character block.
 * @since 1.7
 */
COUNTING_ROD_NUMERALS =
        UnicodeBlock("COUNTING_ROD_NUMERALS",
                     "COUNTING ROD NUMERALS",
                     "COUNTINGRODNUMERALS");

/**
 * Constant for the "Mahjong Tiles" Unicode character block.
 * @since 1.7
 */
MAHJONG_TILES =
        UnicodeBlock("MAHJONG_TILES",
                     "MAHJONG TILES",
                     "MAHJONGTILES");

/**
 * Constant for the "Domino Tiles" Unicode character block.
 * @since 1.7
 */
DOMINO_TILES =
        UnicodeBlock("DOMINO_TILES",
                     "DOMINO TILES",
                     "DOMINOTILES");

/**
 * Constant for the "Playing Cards" Unicode character block.
 * @since 1.7
 */
PLAYING_CARDS =
        UnicodeBlock("PLAYING_CARDS",
                     "PLAYING CARDS",
                     "PLAYINGCARDS");

/**
 * Constant for the "Enclosed Alphanumeric Supplement" Unicode character
 * block.
 * @since 1.7
 */
ENCLOSED_ALPHANUMERIC_SUPPLEMENT =
        UnicodeBlock("ENCLOSED_ALPHANUMERIC_SUPPLEMENT",
                     "ENCLOSED ALPHANUMERIC SUPPLEMENT",
                     "ENCLOSEDALPHANUMERICSUPPLEMENT");

/**
 * Constant for the "Enclosed Ideographic Supplement" Unicode character
 * block.
 * @since 1.7
 */
ENCLOSED_IDEOGRAPHIC_SUPPLEMENT =
        UnicodeBlock("ENCLOSED_IDEOGRAPHIC_SUPPLEMENT",
                     "ENCLOSED IDEOGRAPHIC SUPPLEMENT",
                     "ENCLOSEDIDEOGRAPHICSUPPLEMENT");

/**
 * Constant for the "Miscellaneous Symbols And Pictographs" Unicode
 * character block.
 * @since 1.7
 */
MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS =
        UnicodeBlock("MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS",
                     "MISCELLANEOUS SYMBOLS AND PICTOGRAPHS",
                     "MISCELLANEOUSSYMBOLSANDPICTOGRAPHS");

/**
 * Constant for the "Emoticons" Unicode character block.
 * @since 1.7
 */
EMOTICONS =
        UnicodeBlock("EMOTICONS");

/**
 * Constant for the "Transport And Map Symbols" Unicode character block.
 * @since 1.7
 */
TRANSPORT_AND_MAP_SYMBOLS =
        UnicodeBlock("TRANSPORT_AND_MAP_SYMBOLS",
                     "TRANSPORT AND MAP SYMBOLS",
                     "TRANSPORTANDMAPSYMBOLS");

/**
 * Constant for the "Alchemical Symbols" Unicode character block.
 * @since 1.7
 */
ALCHEMICAL_SYMBOLS =
        UnicodeBlock("ALCHEMICAL_SYMBOLS",
                     "ALCHEMICAL SYMBOLS",
                     "ALCHEMICALSYMBOLS");

/**
 * Constant for the "CJK Unified Ideographs Extension C" Unicode
 * character block.
 * @since 1.7
 */
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C",
                     "CJK UNIFIED IDEOGRAPHS EXTENSION C",
                     "CJKUNIFIEDIDEOGRAPHSEXTENSIONC");

/**
 * Constant for the "CJK Unified Ideographs Extension D" Unicode
 * character block.
 * @since 1.7
 */
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D",
                     "CJK UNIFIED IDEOGRAPHS EXTENSION D",
                     "CJKUNIFIEDIDEOGRAPHSEXTENSIOND");

/**
 * Constant for the "Arabic Extended-A" Unicode character block.
 * @since 1.8
 */
ARABIC_EXTENDED_A =
        UnicodeBlock("ARABIC_EXTENDED_A",
                     "ARABIC EXTENDED-A",
                     "ARABICEXTENDED-A");

/**
 * Constant for the "Sundanese Supplement" Unicode character block.
 * @since 1.8
 */
SUNDANESE_SUPPLEMENT =
        UnicodeBlock("SUNDANESE_SUPPLEMENT",
                     "SUNDANESE SUPPLEMENT",
                     "SUNDANESESUPPLEMENT");

/**
 * Constant for the "Meetei Mayek Extensions" Unicode character block.
 * @since 1.8
 */
MEETEI_MAYEK_EXTENSIONS =
        UnicodeBlock("MEETEI_MAYEK_EXTENSIONS",
                     "MEETEI MAYEK EXTENSIONS",
                     "MEETEIMAYEKEXTENSIONS");

/**
 * Constant for the "Meroitic Hieroglyphs" Unicode character block.
 * @since 1.8
 */
MEROITIC_HIEROGLYPHS =
        UnicodeBlock("MEROITIC_HIEROGLYPHS",
                     "MEROITIC HIEROGLYPHS",
                     "MEROITICHIEROGLYPHS");

/**
 * Constant for the "Meroitic Cursive" Unicode character block.
 * @since 1.8
 */
MEROITIC_CURSIVE =
        UnicodeBlock("MEROITIC_CURSIVE",
                     "MEROITIC CURSIVE",
                     "MEROITICCURSIVE");

/**
 * Constant for the "Sora Sompeng" Unicode character block.
 * @since 1.8
 */
SORA_SOMPENG =
        UnicodeBlock("SORA_SOMPENG",
                     "SORA SOMPENG",
                     "SORASOMPENG");

/**
 * Constant for the "Chakma" Unicode character block.
 * @since 1.8
 */
CHAKMA =
        UnicodeBlock("CHAKMA");

/**
 * Constant for the "Sharada" Unicode character block.
 * @since 1.8
 */
SHARADA =
        UnicodeBlock("SHARADA");

/**
 * Constant for the "Takri" Unicode character block.
 * @since 1.8
 */
TAKRI =
        UnicodeBlock("TAKRI");

/**
 * Constant for the "Miao" Unicode character block.
 * @since 1.8
 */
MIAO =
        UnicodeBlock("MIAO");

/**
 * Constant for the "Arabic Mathematical Alphabetic Symbols" Unicode
 * character block.
 * @since 1.8
 */
ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS =
        UnicodeBlock("ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS",
                     "ARABIC MATHEMATICAL ALPHABETIC SYMBOLS",
                     "ARABICMATHEMATICALALPHABETICSYMBOLS");
boolean Character::UnicodeBlock::operator==(const Character::UnicodeBlock &leftValue) const{
    return 0;
}

