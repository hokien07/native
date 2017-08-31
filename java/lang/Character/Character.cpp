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
#include "../IllegalArgumentException/IllegalArgumentException.hpp"
#include "../../util/Arrays/Arrays.hpp"

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

boolean Character::isBmpCodePoint(int codePoint) {
    unsigned int highOrderBitsOfCodePoint = static_cast<unsigned int>(codePoint) >> 16;
    return (highOrderBitsOfCodePoint == 0);
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

boolean Character::isValidCodePoint(int codePoint) {
    return codePoint >= Character::MIN_CODE_POINT && codePoint <= Character::MAX_CODE_POINT;
}

int Character::getType(int codePoint) {
    return 0;
}

HashMap<String, Character::UnicodeBlock> Character::UnicodeBlock::map;

Character::UnicodeBlock::UnicodeBlock(const String &name) : Subset(name) {}

Character::UnicodeBlock Character::UnicodeBlock::BASIC_LATIN =
        UnicodeBlock("BASIC_LATIN",
                     "BASIC LATIN",
                     "BASICLATIN");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_1_SUPPLEMENT  =
        UnicodeBlock("LATIN_1_SUPPLEMENT",
                     "LATIN-1 SUPPLEMENT",
                     "LATIN-1SUPPMENT");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_EXTENDED_A  =
        UnicodeBlock("LATIN_EXTENDED_A",
                     "LATIN EXTENDED-A",
                     "LATINEXTENDED-A");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_EXTENDED_B =
        UnicodeBlock("LATIN_EXTENDED_B",
                     "LATIN EXTENDED-B",
                     "LATINEXTENDED-B");

Character::UnicodeBlock Character::UnicodeBlock::IPA_EXTENSIONS  =
        UnicodeBlock("IPA_EXTENSIONS",
                     "IPA EXTENSIONS",
                     "IPAEXTENSIONS");

Character::UnicodeBlock Character::UnicodeBlock::SPACING_MODIFIER_LETTERS  =
        UnicodeBlock("SPACING_MODIFIER_LETTERS",
                     "SPACING MODIFIER LETTERS",
                     "SPACINGMODIFIERLETTERS");

Character::UnicodeBlock Character::UnicodeBlock::COMBINING_DIACRITICAL_MARKS =
        UnicodeBlock("COMBINING_DIACRITICAL_MARKS",
                     "COMBINING DIACRITICAL MARKS",
                     "COMBININGDIACRITICALMARKS");

Character::UnicodeBlock Character::UnicodeBlock::GREEK =
        UnicodeBlock("GREEK", 
                     "GREEK AND COPTIC",
                     "GREEKANDCOPTIC");

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

Character::UnicodeBlock Character::UnicodeBlock::HANGUL_JAMO  =
        UnicodeBlock("HANGUL_JAMO",
                     "HANGUL JAMO",
                     "HANGULJAMO");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_EXTENDED_ADDITIONAL =
        UnicodeBlock("LATIN_EXTENDED_ADDITIONAL",
                     "LATIN EXTENDED ADDITIONAL",
                     "LATINEXTENDEDADDITIONAL");

Character::UnicodeBlock Character::UnicodeBlock::GREEK_EXTENDED  =
        UnicodeBlock("GREEK_EXTENDED",
                     "GREEK EXTENDED",
                     "GREEKEXTENDED");

Character::UnicodeBlock Character::UnicodeBlock::GENERAL_PUNCTUATION  =
        UnicodeBlock("GENERAL_PUNCTUATION",
                     "GENERAL PUNCTUATION",
                     "GENERALPUNCTUATION");

Character::UnicodeBlock Character::UnicodeBlock::SUPERSCRIPTS_AND_SUBSCRIPTS  =
        UnicodeBlock("SUPERSCRIPTS_AND_SUBSCRIPTS",
                     "SUPERSCRIPTS AND SUBSCRIPTS",
                     "SUPERSCRIPTSANDSUBSCRIPTS");

Character::UnicodeBlock Character::UnicodeBlock::CURRENCY_SYMBOLS =
        UnicodeBlock("CURRENCY_SYMBOLS",
                     "CURRENCY SYMBOLS",
                     "CURRENCYSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::COMBINING_MARKS_FOR_SYMBOLS  =
        UnicodeBlock("COMBINING_MARKS_FOR_SYMBOLS",
                     "COMBINING DIACRITICAL MARKS FOR SYMBOLS",
                     "COMBININGDIACRITICALMARKSFORSYMBOLS",
                     "COMBINING MARKS FOR SYMBOLS",
                     "COMBININGMARKSFORSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::LETTERLIKE_SYMBOLS  =
        UnicodeBlock("LETTERLIKE_SYMBOLS",
                     "LETTERLIKE SYMBOLS",
                     "LETTERLIKESYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::NUMBER_FORMS =
        UnicodeBlock("NUMBER_FORMS",
                     "NUMBER FORMS",
                     "NUMBERFORMS");

Character::UnicodeBlock Character::UnicodeBlock::ARROWS = UnicodeBlock("ARROWS");

Character::UnicodeBlock Character::UnicodeBlock::MATHEMATICAL_OPERATORS  =
        UnicodeBlock("MATHEMATICAL_OPERATORS",
                     "MATHEMATICAL OPERATORS",
                     "MATHEMATICALOPERATORS");

Character::UnicodeBlock Character::UnicodeBlock::MISCELLANEOUS_TECHNICAL  =
        UnicodeBlock("MISCELLANEOUS_TECHNICAL",
                     "MISCELLANEOUS TECHNICAL",
                     "MISCELLANEOUSTECHNICAL");

Character::UnicodeBlock Character::UnicodeBlock::CONTROL_PICTURES  =
        UnicodeBlock("CONTROL_PICTURES",
                     "CONTROL PICTURES",
                     "CONTROLPICTURES");

Character::UnicodeBlock Character::UnicodeBlock::OPTICAL_CHARACTER_RECOGNITION  =
        UnicodeBlock("OPTICAL_CHARACTER_RECOGNITION",
                     "OPTICAL CHARACTER RECOGNITION",
                     "OPTICALCHARACTERRECOGNITION");

Character::UnicodeBlock Character::UnicodeBlock::ENCLOSED_ALPHANUMERICS  =
        UnicodeBlock("ENCLOSED_ALPHANUMERICS",
                     "ENCLOSED ALPHANUMERICS",
                     "ENCLOSEDALPHANUMERICS");

Character::UnicodeBlock Character::UnicodeBlock::BOX_DRAWING =
        UnicodeBlock("BOX_DRAWING",
                     "BOX DRAWING",
                     "BOXDRAWING");

Character::UnicodeBlock Character::UnicodeBlock::BLOCK_ELEMENTS  =
        UnicodeBlock("BLOCK_ELEMENTS",
                     "BLOCK ELEMENTS",
                     "BLOCKELEMENTS");

Character::UnicodeBlock Character::UnicodeBlock::GEOMETRIC_SHAPES  =
        UnicodeBlock("GEOMETRIC_SHAPES",
                     "GEOMETRIC SHAPES",
                     "GEOMETRICSHAPES");

Character::UnicodeBlock Character::UnicodeBlock::MISCELLANEOUS_SYMBOLS  =
        UnicodeBlock("MISCELLANEOUS_SYMBOLS",
                     "MISCELLANEOUS SYMBOLS",
                     "MISCELLANEOUSSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::DINGBATS = UnicodeBlock("DINGBATS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_SYMBOLS_AND_PUNCTUATION  =
        UnicodeBlock("CJK_SYMBOLS_AND_PUNCTUATION",
                     "CJK SYMBOLS AND PUNCTUATION",
                     "CJKSYMBOLSANDPUNCTUATION");

Character::UnicodeBlock Character::UnicodeBlock::HIRAGANA = UnicodeBlock("HIRAGANA");

Character::UnicodeBlock Character::UnicodeBlock::KATAKANA = UnicodeBlock("KATAKANA");

Character::UnicodeBlock Character::UnicodeBlock::BOPOMOFO = UnicodeBlock("BOPOMOFO");

Character::UnicodeBlock Character::UnicodeBlock::HANGUL_COMPATIBILITY_JAMO  =
        UnicodeBlock("HANGUL_COMPATIBILITY_JAMO",
                     "HANGUL COMPATIBILITY JAMO",
                     "HANGULCOMPATIBILITYJAMO");

Character::UnicodeBlock Character::UnicodeBlock::KANBUN = UnicodeBlock("KANBUN");

Character::UnicodeBlock Character::UnicodeBlock::ENCLOSED_CJK_LETTERS_AND_MONTHS =
        UnicodeBlock("ENCLOSED_CJK_LETTERS_AND_MONTHS",
                     "ENCLOSED CJK LETTERS AND MONTHS",
                     "ENCLOSEDCJKLETTERSANDMONTHS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_COMPATIBILITY  =
        UnicodeBlock("CJK_COMPATIBILITY",
                     "CJK COMPATIBILITY",
                     "CJKCOMPATIBILITY");

Character::UnicodeBlock Character::UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS  =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS",
                     "CJK UNIFIED IDEOGRAPHS",
                     "CJKUNIFIEDIDEOGRAPHS");

Character::UnicodeBlock Character::UnicodeBlock::HANGUL_SYLLABLES  =
        UnicodeBlock("HANGUL_SYLLABLES",
                     "HANGUL SYLLABLES",
                     "HANGULSYLLABLES");

Character::UnicodeBlock Character::UnicodeBlock::PRIVATE_USE_AREA  =
        UnicodeBlock("PRIVATE_USE_AREA",
                     "PRIVATE USE AREA",
                     "PRIVATEUSEAREA");

Character::UnicodeBlock Character::UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS =
        UnicodeBlock("CJK_COMPATIBILITY_IDEOGRAPHS",
                     "CJK COMPATIBILITY IDEOGRAPHS",
                     "CJKCOMPATIBILITYIDEOGRAPHS");

Character::UnicodeBlock Character::UnicodeBlock::ALPHABETIC_PRESENTATION_FORMS  =
        UnicodeBlock("ALPHABETIC_PRESENTATION_FORMS",
                     "ALPHABETIC PRESENTATION FORMS",
                     "ALPHABETICPRESENTATIONFORMS");

Character::UnicodeBlock Character::UnicodeBlock::ARABIC_PRESENTATION_FORMS_A  =
        UnicodeBlock("ARABIC_PRESENTATION_FORMS_A",
                     "ARABIC PRESENTATION FORMS-A",
                     "ARABICPRESENTATIONFORMS-A");

Character::UnicodeBlock Character::UnicodeBlock::COMBINING_HALF_MARKS  =
        UnicodeBlock("COMBINING_HALF_MARKS",
                     "COMBINING HALF MARKS",
                     "COMBININGHALFMARKS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_COMPATIBILITY_FORMS  =
        UnicodeBlock("CJK_COMPATIBILITY_FORMS",
                     "CJK COMPATIBILITY FORMS",
                     "CJKCOMPATIBILITYFORMS");

Character::UnicodeBlock Character::UnicodeBlock::SMALL_FORM_VARIANTS  =
        UnicodeBlock("SMALL_FORM_VARIANTS",
                     "SMALL FORM VARIANTS",
                     "SMALLFORMVARIANTS");

Character::UnicodeBlock Character::UnicodeBlock::ARABIC_PRESENTATION_FORMS_B =
        UnicodeBlock("ARABIC_PRESENTATION_FORMS_B",
                     "ARABIC PRESENTATION FORMS-B",
                     "ARABICPRESENTATIONFORMS-B");

Character::UnicodeBlock Character::UnicodeBlock::HALFWIDTH_AND_FULLWIDTH_FORMS  =
        UnicodeBlock("HALFWIDTH_AND_FULLWIDTH_FORMS",
                     "HALFWIDTH AND FULLWIDTH FORMS",
                     "HALFWIDTHANDFULLWIDTHFORMS");

Character::UnicodeBlock Character::UnicodeBlock::SPECIALS = UnicodeBlock("SPECIALS");

Character::UnicodeBlock Character::UnicodeBlock::SYRIAC = UnicodeBlock("SYRIAC");

Character::UnicodeBlock Character::UnicodeBlock::THAANA = UnicodeBlock("THAANA");

Character::UnicodeBlock Character::UnicodeBlock::SINHALA = UnicodeBlock("SINHALA");

Character::UnicodeBlock Character::UnicodeBlock::MYANMAR = UnicodeBlock("MYANMAR");


Character::UnicodeBlock Character::UnicodeBlock::ETHIOPIC = UnicodeBlock("ETHIOPIC");

Character::UnicodeBlock Character::UnicodeBlock::CHEROKEE = UnicodeBlock("CHEROKEE");

Character::UnicodeBlock Character::UnicodeBlock::UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS  =
        UnicodeBlock("UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS",
                     "UNIFIED CANADIAN ABORIGINAL SYLLABICS",
                     "UNIFIEDCANADIANABORIGINALSYLLABICS");

Character::UnicodeBlock Character::UnicodeBlock::OGHAM = UnicodeBlock("OGHAM");

Character::UnicodeBlock Character::UnicodeBlock::RUNIC = UnicodeBlock("RUNIC");

Character::UnicodeBlock Character::UnicodeBlock::KHMER = UnicodeBlock("KHMER");

Character::UnicodeBlock Character::UnicodeBlock::MONGOLIAN = UnicodeBlock("MONGOLIAN");

Character::UnicodeBlock Character::UnicodeBlock::BRAILLE_PATTERNS  =
        UnicodeBlock("BRAILLE_PATTERNS",
                     "BRAILLE PATTERNS",
                     "BRAILLEPATTERNS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_RADICALS_SUPPLEMENT  =
        UnicodeBlock("CJK_RADICALS_SUPPLEMENT", 
                     "CJK RADICALS SUPPLEMENT",
                     "CJKRADICALSSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::KANGXI_RADICALS  =
        UnicodeBlock("KANGXI_RADICALS",
                     "KANGXI RADICALS",
                     "KANGXIRADICALS");

Character::UnicodeBlock Character::UnicodeBlock::IDEOGRAPHIC_DESCRIPTION_CHARACTERS  =
        UnicodeBlock("IDEOGRAPHIC_DESCRIPTION_CHARACTERS",
                     "IDEOGRAPHIC DESCRIPTION CHARACTERS",
                     "IDEOGRAPHICDESCRIPTIONCHARACTERS");

Character::UnicodeBlock Character::UnicodeBlock::BOPOMOFO_EXTENDED  =
        UnicodeBlock("BOPOMOFO_EXTENDED",
                     "BOPOMOFO EXTENDED",
                     "BOPOMOFOEXTENDED");

Character::UnicodeBlock Character::UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A  =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A",
                     "CJK UNIFIED IDEOGRAPHS EXTENSION A",
                     "CJKUNIFIEDIDEOGRAPHSEXTENSIONA");

Character::UnicodeBlock Character::UnicodeBlock::YI_SYLLABLES  =
        UnicodeBlock("YI_SYLLABLES",
                     "YI SYLLABLES",
                     "YISYLLABLES");

Character::UnicodeBlock Character::UnicodeBlock::YI_RADICALS  =
        UnicodeBlock("YI_RADICALS",
                     "YI RADICALS",
                     "YIRADICALS");

Character::UnicodeBlock Character::UnicodeBlock::CYRILLIC_SUPPLEMENTARY = 
        UnicodeBlock("CYRILLIC_SUPPLEMENTARY",
                     "CYRILLIC SUPPLEMENTARY",
                     "CYRILLICSUPPLEMENTARY",
                     "CYRILLIC SUPPLEMENT",
                     "CYRILLICSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::TAGALOG = UnicodeBlock("TAGALOG");

Character::UnicodeBlock Character::UnicodeBlock::HANUNOO = UnicodeBlock("HANUNOO");

Character::UnicodeBlock Character::UnicodeBlock::BUHID = UnicodeBlock("BUHID");

Character::UnicodeBlock Character::UnicodeBlock::TAGBANWA = UnicodeBlock("TAGBANWA");

Character::UnicodeBlock Character::UnicodeBlock::LIMBU = UnicodeBlock("LIMBU");

Character::UnicodeBlock Character::UnicodeBlock::TAI_LE = UnicodeBlock("TAI_LE",
                                                                       "TAI LE",
                                                                       "TAILE");

Character::UnicodeBlock Character::UnicodeBlock::KHMER_SYMBOLS = 
        UnicodeBlock("KHMER_SYMBOLS",
                     "KHMER SYMBOLS",
                     "KHMERSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::PHONETIC_EXTENSIONS =
        UnicodeBlock("PHONETIC_EXTENSIONS",
                     "PHONETIC EXTENSIONS",
                     "PHONETICEXTENSIONS");

Character::UnicodeBlock Character::UnicodeBlock::MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A = 
        UnicodeBlock("MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A",
                     "MISCELLANEOUS MATHEMATICAL SYMBOLS-A",
                     "MISCELLANEOUSMATHEMATICALSYMBOLS-A");

Character::UnicodeBlock Character::UnicodeBlock::SUPPLEMENTAL_ARROWS_A = 
        UnicodeBlock("SUPPLEMENTAL_ARROWS_A",
                     "SUPPLEMENTAL ARROWS-A",
                     "SUPPLEMENTALARROWS-A");

Character::UnicodeBlock Character::UnicodeBlock::SUPPLEMENTAL_ARROWS_B =
        UnicodeBlock("SUPPLEMENTAL_ARROWS_B",
                     "SUPPLEMENTAL ARROWS-B",
                     "SUPPLEMENTALARROWS-B");

Character::UnicodeBlock Character::UnicodeBlock::MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B =
        UnicodeBlock("MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B",
                     "MISCELLANEOUS MATHEMATICAL SYMBOLS-B",
                     "MISCELLANEOUSMATHEMATICALSYMBOLS-B");


Character::UnicodeBlock Character::UnicodeBlock::SUPPLEMENTAL_MATHEMATICAL_OPERATORS =
        UnicodeBlock("SUPPLEMENTAL_MATHEMATICAL_OPERATORS",
                     "SUPPLEMENTAL MATHEMATICAL OPERATORS",
                     "SUPPLEMENTALMATHEMATICALOPERATORS");

Character::UnicodeBlock Character::UnicodeBlock::MISCELLANEOUS_SYMBOLS_AND_ARROWS =
        UnicodeBlock("MISCELLANEOUS_SYMBOLS_AND_ARROWS",
                     "MISCELLANEOUS SYMBOLS AND ARROWS",
                     "MISCELLANEOUSSYMBOLSANDARROWS");

Character::UnicodeBlock Character::UnicodeBlock::KATAKANA_PHONETIC_EXTENSIONS =
        UnicodeBlock("KATAKANA_PHONETIC_EXTENSIONS",
                     "KATAKANA PHONETIC EXTENSIONS",
                     "KATAKANAPHONETICEXTENSIONS");

Character::UnicodeBlock Character::UnicodeBlock::YIJING_HEXAGRAM_SYMBOLS =
        UnicodeBlock("YIJING_HEXAGRAM_SYMBOLS",
                     "YIJING HEXAGRAM SYMBOLS",
                     "YIJINGHEXAGRAMSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::VARIATION_SELECTORS =
        UnicodeBlock("VARIATION_SELECTORS",
                     "VARIATION SELECTORS",
                     "VARIATIONSELECTORS");

Character::UnicodeBlock Character::UnicodeBlock::LINEAR_B_SYLLABARY =
        UnicodeBlock("LINEAR_B_SYLLABARY",
                     "LINEAR B SYLLABARY",
                     "LINEARBSYLLABARY");

Character::UnicodeBlock Character::UnicodeBlock::LINEAR_B_IDEOGRAMS =
        UnicodeBlock("LINEAR_B_IDEOGRAMS",
                     "LINEAR B IDEOGRAMS",
                     "LINEARBIDEOGRAMS");

Character::UnicodeBlock Character::UnicodeBlock::AEGEAN_NUMBERS =
        UnicodeBlock("AEGEAN_NUMBERS",
                     "AEGEAN NUMBERS",
                     "AEGEANNUMBERS");

Character::UnicodeBlock Character::UnicodeBlock::OLD_ITALIC =
        UnicodeBlock("OLD_ITALIC",
                     "OLD ITALIC",
                     "OLDITALIC");

Character::UnicodeBlock Character::UnicodeBlock::GOTHIC = UnicodeBlock("GOTHIC");

Character::UnicodeBlock Character::UnicodeBlock::UGARITIC = UnicodeBlock("UGARITIC");

Character::UnicodeBlock Character::UnicodeBlock::DESERET = UnicodeBlock("DESERET");

Character::UnicodeBlock Character::UnicodeBlock::SHAVIAN = UnicodeBlock("SHAVIAN");

Character::UnicodeBlock Character::UnicodeBlock::OSMANYA = UnicodeBlock("OSMANYA");

Character::UnicodeBlock Character::UnicodeBlock::CYPRIOT_SYLLABARY =
        UnicodeBlock("CYPRIOT_SYLLABARY",
                     "CYPRIOT SYLLABARY",
                     "CYPRIOTSYLLABARY");

Character::UnicodeBlock Character::UnicodeBlock::BYZANTINE_MUSICAL_SYMBOLS =
        UnicodeBlock("BYZANTINE_MUSICAL_SYMBOLS",
                     "BYZANTINE MUSICAL SYMBOLS",
                     "BYZANTINEMUSICALSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::MUSICAL_SYMBOLS =
        UnicodeBlock("MUSICAL_SYMBOLS",
                     "MUSICAL SYMBOLS",
                     "MUSICALSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::TAI_XUAN_JING_SYMBOLS =
        UnicodeBlock("TAI_XUAN_JING_SYMBOLS",
                     "TAI XUAN JING SYMBOLS",
                     "TAIXUANJINGSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::MATHEMATICAL_ALPHANUMERIC_SYMBOLS =
        UnicodeBlock("MATHEMATICAL_ALPHANUMERIC_SYMBOLS",
                     "MATHEMATICAL ALPHANUMERIC SYMBOLS",
                     "MATHEMATICALALPHANUMERICSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B",
                     "CJK UNIFIED IDEOGRAPHS EXTENSION B",
                     "CJKUNIFIEDIDEOGRAPHSEXTENSIONB");

Character::UnicodeBlock Character::UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT =
        UnicodeBlock("CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT",
                     "CJK COMPATIBILITY IDEOGRAPHS SUPPLEMENT",
                     "CJKCOMPATIBILITYIDEOGRAPHSSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::TAGS = UnicodeBlock("TAGS");

Character::UnicodeBlock Character::UnicodeBlock::VARIATION_SELECTORS_SUPPLEMENT =
        UnicodeBlock("VARIATION_SELECTORS_SUPPLEMENT",
                     "VARIATION SELECTORS SUPPLEMENT",
                     "VARIATIONSELECTORSSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::SUPPLEMENTARY_PRIVATE_USE_AREA_A =
        UnicodeBlock("SUPPLEMENTARY_PRIVATE_USE_AREA_A",
                     "SUPPLEMENTARY PRIVATE USE AREA-A",
                     "SUPPLEMENTARYPRIVATEUSEAREA-A");

Character::UnicodeBlock Character::UnicodeBlock::SUPPLEMENTARY_PRIVATE_USE_AREA_B =
        UnicodeBlock("SUPPLEMENTARY_PRIVATE_USE_AREA_B",
                     "SUPPLEMENTARY PRIVATE USE AREA-B",
                     "SUPPLEMENTARYPRIVATEUSEAREA-B");

Character::UnicodeBlock Character::UnicodeBlock::HIGH_SURROGATES =
        UnicodeBlock("HIGH_SURROGATES",
                     "HIGH SURROGATES",
                     "HIGHSURROGATES");

Character::UnicodeBlock Character::UnicodeBlock::HIGH_PRIVATE_USE_SURROGATES =
        UnicodeBlock("HIGH_PRIVATE_USE_SURROGATES",
                     "HIGH PRIVATE USE SURROGATES",
                     "HIGHPRIVATEUSESURROGATES");

Character::UnicodeBlock Character::UnicodeBlock::LOW_SURROGATES =
        UnicodeBlock("LOW_SURROGATES",
                     "LOW SURROGATES",
                     "LOWSURROGATES");

Character::UnicodeBlock Character::UnicodeBlock::ARABIC_SUPPLEMENT =
        UnicodeBlock("ARABIC_SUPPLEMENT",
                     "ARABIC SUPPLEMENT",
                     "ARABICSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::NKO = UnicodeBlock("NKO");

Character::UnicodeBlock Character::UnicodeBlock::SAMARITAN = UnicodeBlock("SAMARITAN");

Character::UnicodeBlock Character::UnicodeBlock::MANDAIC = UnicodeBlock("MANDAIC");

Character::UnicodeBlock Character::UnicodeBlock::ETHIOPIC_SUPPLEMENT =
        UnicodeBlock("ETHIOPIC_SUPPLEMENT",
                     "ETHIOPIC SUPPLEMENT",
                     "ETHIOPICSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED =
        UnicodeBlock("UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED",
                     "UNIFIED CANADIAN ABORIGINAL SYLLABICS EXTENDED",
                     "UNIFIEDCANADIANABORIGINALSYLLABICSEXTENDED");

Character::UnicodeBlock Character::UnicodeBlock::NEW_TAI_LUE =
        UnicodeBlock("NEW_TAI_LUE",
                     "NEW TAI LUE",
                     "NEWTAILUE");

Character::UnicodeBlock Character::UnicodeBlock::BUGINESE = UnicodeBlock("BUGINESE");

Character::UnicodeBlock Character::UnicodeBlock::TAI_THAM =
        UnicodeBlock("TAI_THAM",
                     "TAI THAM",
                     "TAITHAM");

Character::UnicodeBlock Character::UnicodeBlock::BALINESE = UnicodeBlock("BALINESE");

Character::UnicodeBlock Character::UnicodeBlock::SUNDANESE = UnicodeBlock("SUNDANESE");

Character::UnicodeBlock Character::UnicodeBlock::BATAK = UnicodeBlock("BATAK");

Character::UnicodeBlock Character::UnicodeBlock::LEPCHA = UnicodeBlock("LEPCHA");

Character::UnicodeBlock Character::UnicodeBlock::OL_CHIKI =
        UnicodeBlock("OL_CHIKI",
                     "OL CHIKI",
                     "OLCHIKI");

Character::UnicodeBlock Character::UnicodeBlock::VEDIC_EXTENSIONS =
        UnicodeBlock("VEDIC_EXTENSIONS",
                     "VEDIC EXTENSIONS",
                     "VEDICEXTENSIONS");

Character::UnicodeBlock Character::UnicodeBlock::PHONETIC_EXTENSIONS_SUPPLEMENT =
        UnicodeBlock("PHONETIC_EXTENSIONS_SUPPLEMENT",
                     "PHONETIC EXTENSIONS SUPPLEMENT",
                     "PHONETICEXTENSIONSSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::COMBINING_DIACRITICAL_MARKS_SUPPLEMENT =
        UnicodeBlock("COMBINING_DIACRITICAL_MARKS_SUPPLEMENT",
                     "COMBINING DIACRITICAL MARKS SUPPLEMENT",
                     "COMBININGDIACRITICALMARKSSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::GLAGOLITIC = UnicodeBlock("GLAGOLITIC");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_EXTENDED_C =
        UnicodeBlock("LATIN_EXTENDED_C",
                     "LATIN EXTENDED-C",
                     "LATINEXTENDED-C");

Character::UnicodeBlock Character::UnicodeBlock::COPTIC = UnicodeBlock("COPTIC");

Character::UnicodeBlock Character::UnicodeBlock::GEORGIAN_SUPPLEMENT =
        UnicodeBlock("GEORGIAN_SUPPLEMENT",
                     "GEORGIAN SUPPLEMENT",
                     "GEORGIANSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::TIFINAGH = UnicodeBlock("TIFINAGH");

Character::UnicodeBlock Character::UnicodeBlock::ETHIOPIC_EXTENDED =
        UnicodeBlock("ETHIOPIC_EXTENDED",
                     "ETHIOPIC EXTENDED",
                     "ETHIOPICEXTENDED");

Character::UnicodeBlock Character::UnicodeBlock::CYRILLIC_EXTENDED_A =
        UnicodeBlock("CYRILLIC_EXTENDED_A",
                     "CYRILLIC EXTENDED-A",
                     "CYRILLICEXTENDED-A");

Character::UnicodeBlock Character::UnicodeBlock::SUPPLEMENTAL_PUNCTUATION =
        UnicodeBlock("SUPPLEMENTAL_PUNCTUATION",
                     "SUPPLEMENTAL PUNCTUATION",
                     "SUPPLEMENTALPUNCTUATION");

Character::UnicodeBlock Character::UnicodeBlock::CJK_STROKES =
        UnicodeBlock("CJK_STROKES",
                     "CJK STROKES",
                     "CJKSTROKES");

Character::UnicodeBlock Character::UnicodeBlock::LISU = UnicodeBlock("LISU");

Character::UnicodeBlock Character::UnicodeBlock::VAI = UnicodeBlock("VAI");

Character::UnicodeBlock Character::UnicodeBlock::CYRILLIC_EXTENDED_B =
        UnicodeBlock("CYRILLIC_EXTENDED_B",
                     "CYRILLIC EXTENDED-B",
                     "CYRILLICEXTENDED-B");

Character::UnicodeBlock Character::UnicodeBlock::BAMUM =
        UnicodeBlock("BAMUM");

Character::UnicodeBlock Character::UnicodeBlock::MODIFIER_TONE_LETTERS =
        UnicodeBlock("MODIFIER_TONE_LETTERS",
                     "MODIFIER TONE LETTERS",
                     "MODIFIERTONELETTERS");

Character::UnicodeBlock Character::UnicodeBlock::LATIN_EXTENDED_D =
        UnicodeBlock("LATIN_EXTENDED_D",
                     "LATIN EXTENDED-D",
                     "LATINEXTENDED-D");

Character::UnicodeBlock Character::UnicodeBlock::SYLOTI_NAGRI =
        UnicodeBlock("SYLOTI_NAGRI",
                     "SYLOTI NAGRI",
                     "SYLOTINAGRI");

Character::UnicodeBlock Character::UnicodeBlock::COMMON_INDIC_NUMBER_FORMS =
        UnicodeBlock("COMMON_INDIC_NUMBER_FORMS",
                     "COMMON INDIC NUMBER FORMS",
                     "COMMONINDICNUMBERFORMS");

Character::UnicodeBlock Character::UnicodeBlock::PHAGS_PA =
        UnicodeBlock("PHAGS_PA",
                     "PHAGS-PA");

Character::UnicodeBlock Character::UnicodeBlock::SAURASHTRA =
        UnicodeBlock("SAURASHTRA");

Character::UnicodeBlock Character::UnicodeBlock::DEVANAGARI_EXTENDED =
        UnicodeBlock("DEVANAGARI_EXTENDED",
                     "DEVANAGARI EXTENDED",
                     "DEVANAGARIEXTENDED");

Character::UnicodeBlock Character::UnicodeBlock::KAYAH_LI =
        UnicodeBlock("KAYAH_LI",
                     "KAYAH LI",
                     "KAYAHLI");

Character::UnicodeBlock Character::UnicodeBlock::REJANG = UnicodeBlock("REJANG");

Character::UnicodeBlock Character::UnicodeBlock::HANGUL_JAMO_EXTENDED_A =
        UnicodeBlock("HANGUL_JAMO_EXTENDED_A",
                     "HANGUL JAMO EXTENDED-A",
                     "HANGULJAMOEXTENDED-A");

Character::UnicodeBlock Character::UnicodeBlock::JAVANESE = UnicodeBlock("JAVANESE");

Character::UnicodeBlock Character::UnicodeBlock::CHAM = UnicodeBlock("CHAM");

Character::UnicodeBlock Character::UnicodeBlock::MYANMAR_EXTENDED_A =
        UnicodeBlock("MYANMAR_EXTENDED_A",
                     "MYANMAR EXTENDED-A",
                     "MYANMAREXTENDED-A");

Character::UnicodeBlock Character::UnicodeBlock::TAI_VIET =
        UnicodeBlock("TAI_VIET",
                     "TAI VIET",
                     "TAIVIET");

Character::UnicodeBlock Character::UnicodeBlock::ETHIOPIC_EXTENDED_A =
        UnicodeBlock("ETHIOPIC_EXTENDED_A",
                     "ETHIOPIC EXTENDED-A",
                     "ETHIOPICEXTENDED-A");

Character::UnicodeBlock Character::UnicodeBlock::MEETEI_MAYEK =
        UnicodeBlock("MEETEI_MAYEK",
                     "MEETEI MAYEK",
                     "MEETEIMAYEK");

Character::UnicodeBlock Character::UnicodeBlock::HANGUL_JAMO_EXTENDED_B =
        UnicodeBlock("HANGUL_JAMO_EXTENDED_B",
                     "HANGUL JAMO EXTENDED-B",
                     "HANGULJAMOEXTENDED-B");

Character::UnicodeBlock Character::UnicodeBlock::VERTICAL_FORMS =
        UnicodeBlock("VERTICAL_FORMS",
                     "VERTICAL FORMS",
                     "VERTICALFORMS");

Character::UnicodeBlock Character::UnicodeBlock::ANCIENT_GREEK_NUMBERS =
        UnicodeBlock("ANCIENT_GREEK_NUMBERS",
                     "ANCIENT GREEK NUMBERS",
                     "ANCIENTGREEKNUMBERS");

Character::UnicodeBlock Character::UnicodeBlock::ANCIENT_SYMBOLS =
        UnicodeBlock("ANCIENT_SYMBOLS",
                     "ANCIENT SYMBOLS",
                     "ANCIENTSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::PHAISTOS_DISC =
        UnicodeBlock("PHAISTOS_DISC",
                     "PHAISTOS DISC",
                     "PHAISTOSDISC");

Character::UnicodeBlock Character::UnicodeBlock::LYCIAN = UnicodeBlock("LYCIAN");

Character::UnicodeBlock Character::UnicodeBlock::CARIAN = UnicodeBlock("CARIAN");

Character::UnicodeBlock Character::UnicodeBlock::OLD_PERSIAN =
        UnicodeBlock("OLD_PERSIAN",
                     "OLD PERSIAN",
                     "OLDPERSIAN");

Character::UnicodeBlock Character::UnicodeBlock::IMPERIAL_ARAMAIC =
        UnicodeBlock("IMPERIAL_ARAMAIC",
                     "IMPERIAL ARAMAIC",
                     "IMPERIALARAMAIC");

Character::UnicodeBlock Character::UnicodeBlock::PHOENICIAN = UnicodeBlock("PHOENICIAN");

Character::UnicodeBlock Character::UnicodeBlock::LYDIAN = UnicodeBlock("LYDIAN");

Character::UnicodeBlock Character::UnicodeBlock::KHAROSHTHI = UnicodeBlock("KHAROSHTHI");

Character::UnicodeBlock Character::UnicodeBlock::OLD_SOUTH_ARABIAN =
        UnicodeBlock("OLD_SOUTH_ARABIAN",
                     "OLD SOUTH ARABIAN",
                     "OLDSOUTHARABIAN");

Character::UnicodeBlock Character::UnicodeBlock::AVESTAN = UnicodeBlock("AVESTAN");

Character::UnicodeBlock Character::UnicodeBlock::INSCRIPTIONAL_PARTHIAN =
        UnicodeBlock("INSCRIPTIONAL_PARTHIAN",
                     "INSCRIPTIONAL PARTHIAN",
                     "INSCRIPTIONALPARTHIAN");

Character::UnicodeBlock Character::UnicodeBlock::INSCRIPTIONAL_PAHLAVI =
        UnicodeBlock("INSCRIPTIONAL_PAHLAVI",
                     "INSCRIPTIONAL PAHLAVI",
                     "INSCRIPTIONALPAHLAVI");

Character::UnicodeBlock Character::UnicodeBlock::OLD_TURKIC =
        UnicodeBlock("OLD_TURKIC",
                     "OLD TURKIC",
                     "OLDTURKIC");

Character::UnicodeBlock Character::UnicodeBlock::RUMI_NUMERAL_SYMBOLS =
        UnicodeBlock("RUMI_NUMERAL_SYMBOLS",
                     "RUMI NUMERAL SYMBOLS",
                     "RUMINUMERALSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::BRAHMI = UnicodeBlock("BRAHMI");

Character::UnicodeBlock Character::UnicodeBlock::KAITHI = UnicodeBlock("KAITHI");

Character::UnicodeBlock Character::UnicodeBlock::CUNEIFORM = UnicodeBlock("CUNEIFORM");

Character::UnicodeBlock Character::UnicodeBlock::CUNEIFORM_NUMBERS_AND_PUNCTUATION =
        UnicodeBlock("CUNEIFORM_NUMBERS_AND_PUNCTUATION",
                     "CUNEIFORM NUMBERS AND PUNCTUATION",
                     "CUNEIFORMNUMBERSANDPUNCTUATION");

Character::UnicodeBlock Character::UnicodeBlock::EGYPTIAN_HIEROGLYPHS =
        UnicodeBlock("EGYPTIAN_HIEROGLYPHS",
                     "EGYPTIAN HIEROGLYPHS",
                     "EGYPTIANHIEROGLYPHS");

Character::UnicodeBlock Character::UnicodeBlock::BAMUM_SUPPLEMENT =
        UnicodeBlock("BAMUM_SUPPLEMENT",
                     "BAMUM SUPPLEMENT",
                     "BAMUMSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::KANA_SUPPLEMENT =
        UnicodeBlock("KANA_SUPPLEMENT",
                     "KANA SUPPLEMENT",
                     "KANASUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::ANCIENT_GREEK_MUSICAL_NOTATION =
        UnicodeBlock("ANCIENT_GREEK_MUSICAL_NOTATION",
                     "ANCIENT GREEK MUSICAL NOTATION",
                     "ANCIENTGREEKMUSICALNOTATION");

Character::UnicodeBlock Character::UnicodeBlock::COUNTING_ROD_NUMERALS =
        UnicodeBlock("COUNTING_ROD_NUMERALS",
                     "COUNTING ROD NUMERALS",
                     "COUNTINGRODNUMERALS");

Character::UnicodeBlock Character::UnicodeBlock::MAHJONG_TILES =
        UnicodeBlock("MAHJONG_TILES",
                     "MAHJONG TILES",
                     "MAHJONGTILES");

Character::UnicodeBlock Character::UnicodeBlock::DOMINO_TILES =
        UnicodeBlock("DOMINO_TILES",
                     "DOMINO TILES",
                     "DOMINOTILES");

Character::UnicodeBlock Character::UnicodeBlock::PLAYING_CARDS =
        UnicodeBlock("PLAYING_CARDS",
                     "PLAYING CARDS",
                     "PLAYINGCARDS");

Character::UnicodeBlock Character::UnicodeBlock::ENCLOSED_ALPHANUMERIC_SUPPLEMENT =
        UnicodeBlock("ENCLOSED_ALPHANUMERIC_SUPPLEMENT",
                     "ENCLOSED ALPHANUMERIC SUPPLEMENT",
                     "ENCLOSEDALPHANUMERICSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::ENCLOSED_IDEOGRAPHIC_SUPPLEMENT =
        UnicodeBlock("ENCLOSED_IDEOGRAPHIC_SUPPLEMENT",
                     "ENCLOSED IDEOGRAPHIC SUPPLEMENT",
                     "ENCLOSEDIDEOGRAPHICSUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS =
        UnicodeBlock("MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS",
                     "MISCELLANEOUS SYMBOLS AND PICTOGRAPHS",
                     "MISCELLANEOUSSYMBOLSANDPICTOGRAPHS");

Character::UnicodeBlock Character::UnicodeBlock::EMOTICONS =
        UnicodeBlock("EMOTICONS");

Character::UnicodeBlock Character::UnicodeBlock::TRANSPORT_AND_MAP_SYMBOLS =
        UnicodeBlock("TRANSPORT_AND_MAP_SYMBOLS",
                     "TRANSPORT AND MAP SYMBOLS",
                     "TRANSPORTANDMAPSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::ALCHEMICAL_SYMBOLS =
        UnicodeBlock("ALCHEMICAL_SYMBOLS",
                     "ALCHEMICAL SYMBOLS",
                     "ALCHEMICALSYMBOLS");

Character::UnicodeBlock Character::UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C",
                     "CJK UNIFIED IDEOGRAPHS EXTENSION C",
                     "CJKUNIFIEDIDEOGRAPHSEXTENSIONC");

Character::UnicodeBlock Character::UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D =
        UnicodeBlock("CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D",
                     "CJK UNIFIED IDEOGRAPHS EXTENSION D",
                     "CJKUNIFIEDIDEOGRAPHSEXTENSIOND");

Character::UnicodeBlock Character::UnicodeBlock::ARABIC_EXTENDED_A =
        UnicodeBlock("ARABIC_EXTENDED_A",
                     "ARABIC EXTENDED-A",
                     "ARABICEXTENDED-A");

Character::UnicodeBlock Character::UnicodeBlock::SUNDANESE_SUPPLEMENT =
        UnicodeBlock("SUNDANESE_SUPPLEMENT",
                     "SUNDANESE SUPPLEMENT",
                     "SUNDANESESUPPLEMENT");

Character::UnicodeBlock Character::UnicodeBlock::MEETEI_MAYEK_EXTENSIONS =
        UnicodeBlock("MEETEI_MAYEK_EXTENSIONS",
                     "MEETEI MAYEK EXTENSIONS",
                     "MEETEIMAYEKEXTENSIONS");

Character::UnicodeBlock Character::UnicodeBlock::MEROITIC_HIEROGLYPHS =
        UnicodeBlock("MEROITIC_HIEROGLYPHS",
                     "MEROITIC HIEROGLYPHS",
                     "MEROITICHIEROGLYPHS");

Character::UnicodeBlock Character::UnicodeBlock::MEROITIC_CURSIVE =
        UnicodeBlock("MEROITIC_CURSIVE",
                     "MEROITIC CURSIVE",
                     "MEROITICCURSIVE");

Character::UnicodeBlock Character::UnicodeBlock::SORA_SOMPENG =
        UnicodeBlock("SORA_SOMPENG",
                     "SORA SOMPENG",
                     "SORASOMPENG");

Character::UnicodeBlock Character::UnicodeBlock::CHAKMA =
        UnicodeBlock("CHAKMA");

Character::UnicodeBlock Character::UnicodeBlock::SHARADA =
        UnicodeBlock("SHARADA");

Character::UnicodeBlock Character::UnicodeBlock::TAKRI =
        UnicodeBlock("TAKRI");

Character::UnicodeBlock Character::UnicodeBlock::MIAO =
        UnicodeBlock("MIAO");

Character::UnicodeBlock Character::UnicodeBlock::ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS =
        UnicodeBlock("ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS",
                     "ARABIC MATHEMATICAL ALPHABETIC SYMBOLS",
                     "ARABICMATHEMATICALALPHABETICSYMBOLS");
Array<int> Character::UnicodeBlock::blockStarts = {
        0x0000,   // 0000..007F; Basic Latin
        0x0080,   // 0080..00FF; Latin-1 Supplement
        0x0100,   // 0100..017F; Latin Extended-A
        0x0180,   // 0180..024F; Latin Extended-B
        0x0250,   // 0250..02AF; IPA Extensions
        0x02B0,   // 02B0..02FF; Spacing Modifier Letters
        0x0300,   // 0300..036F; Combining Diacritical Marks
        0x0370,   // 0370..03FF; Greek and Coptic
        0x0400,   // 0400..04FF; Cyrillic
        0x0500,   // 0500..052F; Cyrillic Supplement
        0x0530,   // 0530..058F; Armenian
        0x0590,   // 0590..05FF; Hebrew
        0x0600,   // 0600..06FF; Arabic
        0x0700,   // 0700..074F; Syriac
        0x0750,   // 0750..077F; Arabic Supplement
        0x0780,   // 0780..07BF; Thaana
        0x07C0,   // 07C0..07FF; NKo
        0x0800,   // 0800..083F; Samaritan
        0x0840,   // 0840..085F; Mandaic
        0x0860,   //             unassigned
        0x08A0,   // 08A0..08FF; Arabic Extended-A
        0x0900,   // 0900..097F; Devanagari
        0x0980,   // 0980..09FF; Bengali
        0x0A00,   // 0A00..0A7F; Gurmukhi
        0x0A80,   // 0A80..0AFF; Gujarati
        0x0B00,   // 0B00..0B7F; Oriya
        0x0B80,   // 0B80..0BFF; Tamil
        0x0C00,   // 0C00..0C7F; Telugu
        0x0C80,   // 0C80..0CFF; Kannada
        0x0D00,   // 0D00..0D7F; Malayalam
        0x0D80,   // 0D80..0DFF; Sinhala
        0x0E00,   // 0E00..0E7F; Thai
        0x0E80,   // 0E80..0EFF; Lao
        0x0F00,   // 0F00..0FFF; Tibetan
        0x1000,   // 1000..109F; Myanmar
        0x10A0,   // 10A0..10FF; Georgian
        0x1100,   // 1100..11FF; Hangul Jamo
        0x1200,   // 1200..137F; Ethiopic
        0x1380,   // 1380..139F; Ethiopic Supplement
        0x13A0,   // 13A0..13FF; Cherokee
        0x1400,   // 1400..167F; Unified Canadian Aboriginal Syllabics
        0x1680,   // 1680..169F; Ogham
        0x16A0,   // 16A0..16FF; Runic
        0x1700,   // 1700..171F; Tagalog
        0x1720,   // 1720..173F; Hanunoo
        0x1740,   // 1740..175F; Buhid
        0x1760,   // 1760..177F; Tagbanwa
        0x1780,   // 1780..17FF; Khmer
        0x1800,   // 1800..18AF; Mongolian
        0x18B0,   // 18B0..18FF; Unified Canadian Aboriginal Syllabics Extended
        0x1900,   // 1900..194F; Limbu
        0x1950,   // 1950..197F; Tai Le
        0x1980,   // 1980..19DF; New Tai Lue
        0x19E0,   // 19E0..19FF; Khmer Symbols
        0x1A00,   // 1A00..1A1F; Buginese
        0x1A20,   // 1A20..1AAF; Tai Tham
        0x1AB0,   //             unassigned
        0x1B00,   // 1B00..1B7F; Balinese
        0x1B80,   // 1B80..1BBF; Sundanese
        0x1BC0,   // 1BC0..1BFF; Batak
        0x1C00,   // 1C00..1C4F; Lepcha
        0x1C50,   // 1C50..1C7F; Ol Chiki
        0x1C80,   //             unassigned
        0x1CC0,   // 1CC0..1CCF; Sundanese Supplement
        0x1CD0,   // 1CD0..1CFF; Vedic Extensions
        0x1D00,   // 1D00..1D7F; Phonetic Extensions
        0x1D80,   // 1D80..1DBF; Phonetic Extensions Supplement
        0x1DC0,   // 1DC0..1DFF; Combining Diacritical Marks Supplement
        0x1E00,   // 1E00..1EFF; Latin Extended Additional
        0x1F00,   // 1F00..1FFF; Greek Extended
        0x2000,   // 2000..206F; General Punctuation
        0x2070,   // 2070..209F; Superscripts and Subscripts
        0x20A0,   // 20A0..20CF; Currency Symbols
        0x20D0,   // 20D0..20FF; Combining Diacritical Marks for Symbols
        0x2100,   // 2100..214F; Letterlike Symbols
        0x2150,   // 2150..218F; Number Forms
        0x2190,   // 2190..21FF; Arrows
        0x2200,   // 2200..22FF; Mathematical Operators
        0x2300,   // 2300..23FF; Miscellaneous Technical
        0x2400,   // 2400..243F; Control Pictures
        0x2440,   // 2440..245F; Optical Character Recognition
        0x2460,   // 2460..24FF; Enclosed Alphanumerics
        0x2500,   // 2500..257F; Box Drawing
        0x2580,   // 2580..259F; Block Elements
        0x25A0,   // 25A0..25FF; Geometric Shapes
        0x2600,   // 2600..26FF; Miscellaneous Symbols
        0x2700,   // 2700..27BF; Dingbats
        0x27C0,   // 27C0..27EF; Miscellaneous Mathematical Symbols-A
        0x27F0,   // 27F0..27FF; Supplemental Arrows-A
        0x2800,   // 2800..28FF; Braille Patterns
        0x2900,   // 2900..297F; Supplemental Arrows-B
        0x2980,   // 2980..29FF; Miscellaneous Mathematical Symbols-B
        0x2A00,   // 2A00..2AFF; Supplemental Mathematical Operators
        0x2B00,   // 2B00..2BFF; Miscellaneous Symbols and Arrows
        0x2C00,   // 2C00..2C5F; Glagolitic
        0x2C60,   // 2C60..2C7F; Latin Extended-C
        0x2C80,   // 2C80..2CFF; Coptic
        0x2D00,   // 2D00..2D2F; Georgian Supplement
        0x2D30,   // 2D30..2D7F; Tifinagh
        0x2D80,   // 2D80..2DDF; Ethiopic Extended
        0x2DE0,   // 2DE0..2DFF; Cyrillic Extended-A
        0x2E00,   // 2E00..2E7F; Supplemental Punctuation
        0x2E80,   // 2E80..2EFF; CJK Radicals Supplement
        0x2F00,   // 2F00..2FDF; Kangxi Radicals
        0x2FE0,   //             unassigned
        0x2FF0,   // 2FF0..2FFF; Ideographic Description Characters
        0x3000,   // 3000..303F; CJK Symbols and Punctuation
        0x3040,   // 3040..309F; Hiragana
        0x30A0,   // 30A0..30FF; Katakana
        0x3100,   // 3100..312F; Bopomofo
        0x3130,   // 3130..318F; Hangul Compatibility Jamo
        0x3190,   // 3190..319F; Kanbun
        0x31A0,   // 31A0..31BF; Bopomofo Extended
        0x31C0,   // 31C0..31EF; CJK Strokes
        0x31F0,   // 31F0..31FF; Katakana Phonetic Extensions
        0x3200,   // 3200..32FF; Enclosed CJK Letters and Months
        0x3300,   // 3300..33FF; CJK Compatibility
        0x3400,   // 3400..4DBF; CJK Unified Ideographs Extension A
        0x4DC0,   // 4DC0..4DFF; Yijing Hexagram Symbols
        0x4E00,   // 4E00..9FFF; CJK Unified Ideographs
        0xA000,   // A000..A48F; Yi Syllables
        0xA490,   // A490..A4CF; Yi Radicals
        0xA4D0,   // A4D0..A4FF; Lisu
        0xA500,   // A500..A63F; Vai
        0xA640,   // A640..A69F; Cyrillic Extended-B
        0xA6A0,   // A6A0..A6FF; Bamum
        0xA700,   // A700..A71F; Modifier Tone Letters
        0xA720,   // A720..A7FF; Latin Extended-D
        0xA800,   // A800..A82F; Syloti Nagri
        0xA830,   // A830..A83F; Common Indic Number Forms
        0xA840,   // A840..A87F; Phags-pa
        0xA880,   // A880..A8DF; Saurashtra
        0xA8E0,   // A8E0..A8FF; Devanagari Extended
        0xA900,   // A900..A92F; Kayah Li
        0xA930,   // A930..A95F; Rejang
        0xA960,   // A960..A97F; Hangul Jamo Extended-A
        0xA980,   // A980..A9DF; Javanese
        0xA9E0,   //             unassigned
        0xAA00,   // AA00..AA5F; Cham
        0xAA60,   // AA60..AA7F; Myanmar Extended-A
        0xAA80,   // AA80..AADF; Tai Viet
        0xAAE0,   // AAE0..AAFF; Meetei Mayek Extensions
        0xAB00,   // AB00..AB2F; Ethiopic Extended-A
        0xAB30,   //             unassigned
        0xABC0,   // ABC0..ABFF; Meetei Mayek
        0xAC00,   // AC00..D7AF; Hangul Syllables
        0xD7B0,   // D7B0..D7FF; Hangul Jamo Extended-B
        0xD800,   // D800..DB7F; High Surrogates
        0xDB80,   // DB80..DBFF; High Private Use Surrogates
        0xDC00,   // DC00..DFFF; Low Surrogates
        0xE000,   // E000..F8FF; Private Use Area
        0xF900,   // F900..FAFF; CJK Compatibility Ideographs
        0xFB00,   // FB00..FB4F; Alphabetic Presentation Forms
        0xFB50,   // FB50..FDFF; Arabic Presentation Forms-A
        0xFE00,   // FE00..FE0F; Variation Selectors
        0xFE10,   // FE10..FE1F; Vertical Forms
        0xFE20,   // FE20..FE2F; Combining Half Marks
        0xFE30,   // FE30..FE4F; CJK Compatibility Forms
        0xFE50,   // FE50..FE6F; Small Form Variants
        0xFE70,   // FE70..FEFF; Arabic Presentation Forms-B
        0xFF00,   // FF00..FFEF; Halfwidth and Fullwidth Forms
        0xFFF0,   // FFF0..FFFF; Specials
        0x10000,  // 10000..1007F; Linear B Syllabary
        0x10080,  // 10080..100FF; Linear B Ideograms
        0x10100,  // 10100..1013F; Aegean Numbers
        0x10140,  // 10140..1018F; Ancient Greek Numbers
        0x10190,  // 10190..101CF; Ancient Symbols
        0x101D0,  // 101D0..101FF; Phaistos Disc
        0x10200,  //               unassigned
        0x10280,  // 10280..1029F; Lycian
        0x102A0,  // 102A0..102DF; Carian
        0x102E0,  //               unassigned
        0x10300,  // 10300..1032F; Old Italic
        0x10330,  // 10330..1034F; Gothic
        0x10350,  //               unassigned
        0x10380,  // 10380..1039F; Ugaritic
        0x103A0,  // 103A0..103DF; Old Persian
        0x103E0,  //               unassigned
        0x10400,  // 10400..1044F; Deseret
        0x10450,  // 10450..1047F; Shavian
        0x10480,  // 10480..104AF; Osmanya
        0x104B0,  //               unassigned
        0x10800,  // 10800..1083F; Cypriot Syllabary
        0x10840,  // 10840..1085F; Imperial Aramaic
        0x10860,  //               unassigned
        0x10900,  // 10900..1091F; Phoenician
        0x10920,  // 10920..1093F; Lydian
        0x10940,  //               unassigned
        0x10980,  // 10980..1099F; Meroitic Hieroglyphs
        0x109A0,  // 109A0..109FF; Meroitic Cursive
        0x10A00,  // 10A00..10A5F; Kharoshthi
        0x10A60,  // 10A60..10A7F; Old South Arabian
        0x10A80,  //               unassigned
        0x10B00,  // 10B00..10B3F; Avestan
        0x10B40,  // 10B40..10B5F; Inscriptional Parthian
        0x10B60,  // 10B60..10B7F; Inscriptional Pahlavi
        0x10B80,  //               unassigned
        0x10C00,  // 10C00..10C4F; Old Turkic
        0x10C50,  //               unassigned
        0x10E60,  // 10E60..10E7F; Rumi Numeral Symbols
        0x10E80,  //               unassigned
        0x11000,  // 11000..1107F; Brahmi
        0x11080,  // 11080..110CF; Kaithi
        0x110D0,  // 110D0..110FF; Sora Sompeng
        0x11100,  // 11100..1114F; Chakma
        0x11150,  //               unassigned
        0x11180,  // 11180..111DF; Sharada
        0x111E0,  //               unassigned
        0x11680,  // 11680..116CF; Takri
        0x116D0,  //               unassigned
        0x12000,  // 12000..123FF; Cuneiform
        0x12400,  // 12400..1247F; Cuneiform Numbers and Punctuation
        0x12480,  //               unassigned
        0x13000,  // 13000..1342F; Egyptian Hieroglyphs
        0x13430,  //               unassigned
        0x16800,  // 16800..16A3F; Bamum Supplement
        0x16A40,  //               unassigned
        0x16F00,  // 16F00..16F9F; Miao
        0x16FA0,  //               unassigned
        0x1B000,  // 1B000..1B0FF; Kana Supplement
        0x1B100,  //               unassigned
        0x1D000,  // 1D000..1D0FF; Byzantine Musical Symbols
        0x1D100,  // 1D100..1D1FF; Musical Symbols
        0x1D200,  // 1D200..1D24F; Ancient Greek Musical Notation
        0x1D250,  //               unassigned
        0x1D300,  // 1D300..1D35F; Tai Xuan Jing Symbols
        0x1D360,  // 1D360..1D37F; Counting Rod Numerals
        0x1D380,  //               unassigned
        0x1D400,  // 1D400..1D7FF; Mathematical Alphanumeric Symbols
        0x1D800,  //               unassigned
        0x1EE00,  // 1EE00..1EEFF; Arabic Mathematical Alphabetic Symbols
        0x1EF00,  //               unassigned
        0x1F000,  // 1F000..1F02F; Mahjong Tiles
        0x1F030,  // 1F030..1F09F; Domino Tiles
        0x1F0A0,  // 1F0A0..1F0FF; Playing Cards
        0x1F100,  // 1F100..1F1FF; Enclosed Alphanumeric Supplement
        0x1F200,  // 1F200..1F2FF; Enclosed Ideographic Supplement
        0x1F300,  // 1F300..1F5FF; Miscellaneous Symbols And Pictographs
        0x1F600,  // 1F600..1F64F; Emoticons
        0x1F650,  //               unassigned
        0x1F680,  // 1F680..1F6FF; Transport And Map Symbols
        0x1F700,  // 1F700..1F77F; Alchemical Symbols
        0x1F780,  //               unassigned
        0x20000,  // 20000..2A6DF; CJK Unified Ideographs Extension B
        0x2A6E0,  //               unassigned
        0x2A700,  // 2A700..2B73F; CJK Unified Ideographs Extension C
        0x2B740,  // 2B740..2B81F; CJK Unified Ideographs Extension D
        0x2B820,  //               unassigned
        0x2F800,  // 2F800..2FA1F; CJK Compatibility Ideographs Supplement
        0x2FA20,  //               unassigned
        0xE0000,  // E0000..E007F; Tags
        0xE0080,  //               unassigned
        0xE0100,  // E0100..E01EF; Variation Selectors Supplement
        0xE01F0,  //               unassigned
        0xF0000,  // F0000..FFFFF; Supplementary Private Use Area-A
        0x100000  // 100000..10FFFF; Supplementary Private Use Area-B
        };

Array<Character::UnicodeBlock> Character::UnicodeBlock::blocks = {
                        BASIC_LATIN,
                        LATIN_1_SUPPLEMENT,
                        LATIN_EXTENDED_A,
                        LATIN_EXTENDED_B,
                        IPA_EXTENSIONS,
                        SPACING_MODIFIER_LETTERS,
                        COMBINING_DIACRITICAL_MARKS,
                        GREEK,
                        CYRILLIC,
                        CYRILLIC_SUPPLEMENTARY,
                        ARMENIAN,
                        HEBREW,
                        ARABIC,
                        SYRIAC,
                        ARABIC_SUPPLEMENT,
                        THAANA,
                        NKO,
                        SAMARITAN,
                        MANDAIC,
                        UnicodeBlock("null"),
                        ARABIC_EXTENDED_A,
                        DEVANAGARI,
                        BENGALI,
                        GURMUKHI,
                        GUJARATI,
                        ORIYA,
                        TAMIL,
                        TELUGU,
                        KANNADA,
                        MALAYALAM,
                        SINHALA,
                        THAI,
                        LAO,
                        TIBETAN,
                        MYANMAR,
                        GEORGIAN,
                        HANGUL_JAMO,
                        ETHIOPIC,
                        ETHIOPIC_SUPPLEMENT,
                        CHEROKEE,
                        UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS,
                        OGHAM,
                        RUNIC,
                        TAGALOG,
                        HANUNOO,
                        BUHID,
                        TAGBANWA,
                        KHMER,
                        MONGOLIAN,
                        UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED,
                        LIMBU,
                        TAI_LE,
                        NEW_TAI_LUE,
                        KHMER_SYMBOLS,
                        BUGINESE,
                        TAI_THAM,
                        UnicodeBlock("null"),
                        BALINESE,
                        SUNDANESE,
                        BATAK,
                        LEPCHA,
                        OL_CHIKI,
                        UnicodeBlock("null"),
                        SUNDANESE_SUPPLEMENT,
                        VEDIC_EXTENSIONS,
                        PHONETIC_EXTENSIONS,
                        PHONETIC_EXTENSIONS_SUPPLEMENT,
                        COMBINING_DIACRITICAL_MARKS_SUPPLEMENT,
                        LATIN_EXTENDED_ADDITIONAL,
                        GREEK_EXTENDED,
                        GENERAL_PUNCTUATION,
                        SUPERSCRIPTS_AND_SUBSCRIPTS,
                        CURRENCY_SYMBOLS,
                        COMBINING_MARKS_FOR_SYMBOLS,
                        LETTERLIKE_SYMBOLS,
                        NUMBER_FORMS,
                        ARROWS,
                        MATHEMATICAL_OPERATORS,
                        MISCELLANEOUS_TECHNICAL,
                        CONTROL_PICTURES,
                        OPTICAL_CHARACTER_RECOGNITION,
                        ENCLOSED_ALPHANUMERICS,
                        BOX_DRAWING,
                        BLOCK_ELEMENTS,
                        GEOMETRIC_SHAPES,
                        MISCELLANEOUS_SYMBOLS,
                        DINGBATS,
                        MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A,
                        SUPPLEMENTAL_ARROWS_A,
                        BRAILLE_PATTERNS,
                        SUPPLEMENTAL_ARROWS_B,
                        MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B,
                        SUPPLEMENTAL_MATHEMATICAL_OPERATORS,
                        MISCELLANEOUS_SYMBOLS_AND_ARROWS,
                        GLAGOLITIC,
                        LATIN_EXTENDED_C,
                        COPTIC,
                        GEORGIAN_SUPPLEMENT,
                        TIFINAGH,
                        ETHIOPIC_EXTENDED,
                        CYRILLIC_EXTENDED_A,
                        SUPPLEMENTAL_PUNCTUATION,
                        CJK_RADICALS_SUPPLEMENT,
                        KANGXI_RADICALS,
                        UnicodeBlock("null"),
                        IDEOGRAPHIC_DESCRIPTION_CHARACTERS,
                        CJK_SYMBOLS_AND_PUNCTUATION,
                        HIRAGANA,
                        KATAKANA,
                        BOPOMOFO,
                        HANGUL_COMPATIBILITY_JAMO,
                        KANBUN,
                        BOPOMOFO_EXTENDED,
                        CJK_STROKES,
                        KATAKANA_PHONETIC_EXTENSIONS,
                        ENCLOSED_CJK_LETTERS_AND_MONTHS,
                        CJK_COMPATIBILITY,
                        CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A,
                        YIJING_HEXAGRAM_SYMBOLS,
                        CJK_UNIFIED_IDEOGRAPHS,
                        YI_SYLLABLES,
                        YI_RADICALS,
                        LISU,
                        VAI,
                        CYRILLIC_EXTENDED_B,
                        BAMUM,
                        MODIFIER_TONE_LETTERS,
                        LATIN_EXTENDED_D,
                        SYLOTI_NAGRI,
                        COMMON_INDIC_NUMBER_FORMS,
                        PHAGS_PA,
                        SAURASHTRA,
                        DEVANAGARI_EXTENDED,
                        KAYAH_LI,
                        REJANG,
                        HANGUL_JAMO_EXTENDED_A,
                        JAVANESE,
                        UnicodeBlock("null"),
                        CHAM,
                        MYANMAR_EXTENDED_A,
                        TAI_VIET,
                        MEETEI_MAYEK_EXTENSIONS,
                        ETHIOPIC_EXTENDED_A,
                        UnicodeBlock("null"),
                        MEETEI_MAYEK,
                        HANGUL_SYLLABLES,
                        HANGUL_JAMO_EXTENDED_B,
                        HIGH_SURROGATES,
                        HIGH_PRIVATE_USE_SURROGATES,
                        LOW_SURROGATES,
                        PRIVATE_USE_AREA,
                        CJK_COMPATIBILITY_IDEOGRAPHS,
                        ALPHABETIC_PRESENTATION_FORMS,
                        ARABIC_PRESENTATION_FORMS_A,
                        VARIATION_SELECTORS,
                        VERTICAL_FORMS,
                        COMBINING_HALF_MARKS,
                        CJK_COMPATIBILITY_FORMS,
                        SMALL_FORM_VARIANTS,
                        ARABIC_PRESENTATION_FORMS_B,
                        HALFWIDTH_AND_FULLWIDTH_FORMS,
                        SPECIALS,
                        LINEAR_B_SYLLABARY,
                        LINEAR_B_IDEOGRAMS,
                        AEGEAN_NUMBERS,
                        ANCIENT_GREEK_NUMBERS,
                        ANCIENT_SYMBOLS,
                        PHAISTOS_DISC,
                        UnicodeBlock("null"),
                        LYCIAN,
                        CARIAN,
                        UnicodeBlock("null"),
                        OLD_ITALIC,
                        GOTHIC,
                        UnicodeBlock("null"),
                        UGARITIC,
                        OLD_PERSIAN,
                        UnicodeBlock("null"),
                        DESERET,
                        SHAVIAN,
                        OSMANYA,
                        UnicodeBlock("null"),
                        CYPRIOT_SYLLABARY,
                        IMPERIAL_ARAMAIC,
                        UnicodeBlock("null"),
                        PHOENICIAN,
                        LYDIAN,
                        UnicodeBlock("null"),
                        MEROITIC_HIEROGLYPHS,
                        MEROITIC_CURSIVE,
                        KHAROSHTHI,
                        OLD_SOUTH_ARABIAN,
                        UnicodeBlock("null"),
                        AVESTAN,
                        INSCRIPTIONAL_PARTHIAN,
                        INSCRIPTIONAL_PAHLAVI,
                        UnicodeBlock("null"),
                        OLD_TURKIC,
                        UnicodeBlock("null"),
                        RUMI_NUMERAL_SYMBOLS,
                        UnicodeBlock("null"),
                        BRAHMI,
                        KAITHI,
                        SORA_SOMPENG,
                        CHAKMA,
                        UnicodeBlock("null"),
                        SHARADA,
                        UnicodeBlock("null"),
                        TAKRI,
                        UnicodeBlock("null"),
                        CUNEIFORM,
                        CUNEIFORM_NUMBERS_AND_PUNCTUATION,
                        UnicodeBlock("null"),
                        EGYPTIAN_HIEROGLYPHS,
                        UnicodeBlock("null"),
                        BAMUM_SUPPLEMENT,
                        UnicodeBlock("null"),
                        MIAO,
                        UnicodeBlock("null"),
                        KANA_SUPPLEMENT,
                        UnicodeBlock("null"),
                        BYZANTINE_MUSICAL_SYMBOLS,
                        MUSICAL_SYMBOLS,
                        ANCIENT_GREEK_MUSICAL_NOTATION,
                        UnicodeBlock("null"),
                        TAI_XUAN_JING_SYMBOLS,
                        COUNTING_ROD_NUMERALS,
                        UnicodeBlock("null"),
                        MATHEMATICAL_ALPHANUMERIC_SYMBOLS,
                        UnicodeBlock("null"),
                        ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS,
                        UnicodeBlock("null"),
                        MAHJONG_TILES,
                        DOMINO_TILES,
                        PLAYING_CARDS,
                        ENCLOSED_ALPHANUMERIC_SUPPLEMENT,
                        ENCLOSED_IDEOGRAPHIC_SUPPLEMENT,
                        MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS,
                        EMOTICONS,
                        UnicodeBlock("null"),
                        TRANSPORT_AND_MAP_SYMBOLS,
                        ALCHEMICAL_SYMBOLS,
                        UnicodeBlock("null"),
                        CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B,
                        UnicodeBlock("null"),
                        CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C,
                        CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D,
                        UnicodeBlock("null"),
                        CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT,
                        UnicodeBlock("null"),
                        TAGS,
                        UnicodeBlock("null"),
                        VARIATION_SELECTORS_SUPPLEMENT,
                        UnicodeBlock("null"),
                        SUPPLEMENTARY_PRIVATE_USE_AREA_A,
                        SUPPLEMENTARY_PRIVATE_USE_AREA_B
                };



boolean Character::UnicodeBlock::operator==(const Character::UnicodeBlock &leftValue) const{
    return 0;
}

Character::UnicodeBlock Character::UnicodeBlock::of(char character) {
    return UnicodeBlock::of((int)character);
}

Character::UnicodeBlock Character::UnicodeBlock::of(int codePoint) {
    if (!Character::isValidCodePoint(codePoint)) {
        throw  IllegalArgumentException();
    }

    int top, bottom, current;
    bottom = 0;
    top = blockStarts.length;
    current = top/2;

    // invariant: top > current >= bottom && codePoint >= unicodeBlockStarts[bottom]
    while (top - bottom > 1) {
        if (codePoint >= blockStarts[current]) {
            bottom = current;
        } else {
            top = current;
        }
        current = (top + bottom) / 2;
    }
    return blocks[current];
}

Character::UnicodeBlock Character::UnicodeBlock::forName(String blockName) {
    UnicodeBlock block = map.get(blockName.toUpperCase());
    if (block.toString() == "") {
        throw  IllegalArgumentException();
    }
    return block;
}

Character::UnicodeScript::UnicodeScript() {
    this->unicodeScript = Character::UnicodeScript::Script::DEFAULT;
}

Character::UnicodeScript::UnicodeScript(Character::UnicodeScript::Script script) {
    this->unicodeScript = script;
}

Array<int> Character::UnicodeScript::scriptStarts = {
                        0x0000,   // 0000..0040; COMMON
                        0x0041,   // 0041..005A; LATIN
                        0x005B,   // 005B..0060; COMMON
                        0x0061,   // 0061..007A; LATIN
                        0x007B,   // 007B..00A9; COMMON
                        0x00AA,   // 00AA..00AA; LATIN
                        0x00AB,   // 00AB..00B9; COMMON
                        0x00BA,   // 00BA..00BA; LATIN
                        0x00BB,   // 00BB..00BF; COMMON
                        0x00C0,   // 00C0..00D6; LATIN
                        0x00D7,   // 00D7..00D7; COMMON
                        0x00D8,   // 00D8..00F6; LATIN
                        0x00F7,   // 00F7..00F7; COMMON
                        0x00F8,   // 00F8..02B8; LATIN
                        0x02B9,   // 02B9..02DF; COMMON
                        0x02E0,   // 02E0..02E4; LATIN
                        0x02E5,   // 02E5..02E9; COMMON
                        0x02EA,   // 02EA..02EB; BOPOMOFO
                        0x02EC,   // 02EC..02FF; COMMON
                        0x0300,   // 0300..036F; INHERITED
                        0x0370,   // 0370..0373; GREEK
                        0x0374,   // 0374..0374; COMMON
                        0x0375,   // 0375..037D; GREEK
                        0x037E,   // 037E..0383; COMMON
                        0x0384,   // 0384..0384; GREEK
                        0x0385,   // 0385..0385; COMMON
                        0x0386,   // 0386..0386; GREEK
                        0x0387,   // 0387..0387; COMMON
                        0x0388,   // 0388..03E1; GREEK
                        0x03E2,   // 03E2..03EF; COPTIC
                        0x03F0,   // 03F0..03FF; GREEK
                        0x0400,   // 0400..0484; CYRILLIC
                        0x0485,   // 0485..0486; INHERITED
                        0x0487,   // 0487..0530; CYRILLIC
                        0x0531,   // 0531..0588; ARMENIAN
                        0x0589,   // 0589..0589; COMMON
                        0x058A,   // 058A..0590; ARMENIAN
                        0x0591,   // 0591..05FF; HEBREW
                        0x0600,   // 0600..060B; ARABIC
                        0x060C,   // 060C..060C; COMMON
                        0x060D,   // 060D..061A; ARABIC
                        0x061B,   // 061B..061D; COMMON
                        0x061E,   // 061E..061E; ARABIC
                        0x061F,   // 061F..061F; COMMON
                        0x0620,   // 0620..063F; ARABIC
                        0x0640,   // 0640..0640; COMMON
                        0x0641,   // 0641..064A; ARABIC
                        0x064B,   // 064B..0655; INHERITED
                        0x0656,   // 0656..065F; ARABIC
                        0x0660,   // 0660..0669; COMMON
                        0x066A,   // 066A..066F; ARABIC
                        0x0670,   // 0670..0670; INHERITED
                        0x0671,   // 0671..06DC; ARABIC
                        0x06DD,   // 06DD..06DD; COMMON
                        0x06DE,   // 06DE..06FF; ARABIC
                        0x0700,   // 0700..074F; SYRIAC
                        0x0750,   // 0750..077F; ARABIC
                        0x0780,   // 0780..07BF; THAANA
                        0x07C0,   // 07C0..07FF; NKO
                        0x0800,   // 0800..083F; SAMARITAN
                        0x0840,   // 0840..089F; MANDAIC
                        0x08A0,   // 08A0..08FF; ARABIC
                        0x0900,   // 0900..0950; DEVANAGARI
                        0x0951,   // 0951..0952; INHERITED
                        0x0953,   // 0953..0963; DEVANAGARI
                        0x0964,   // 0964..0965; COMMON
                        0x0966,   // 0966..0980; DEVANAGARI
                        0x0981,   // 0981..0A00; BENGALI
                        0x0A01,   // 0A01..0A80; GURMUKHI
                        0x0A81,   // 0A81..0B00; GUJARATI
                        0x0B01,   // 0B01..0B81; ORIYA
                        0x0B82,   // 0B82..0C00; TAMIL
                        0x0C01,   // 0C01..0C81; TELUGU
                        0x0C82,   // 0C82..0CF0; KANNADA
                        0x0D02,   // 0D02..0D81; MALAYALAM
                        0x0D82,   // 0D82..0E00; SINHALA
                        0x0E01,   // 0E01..0E3E; THAI
                        0x0E3F,   // 0E3F..0E3F; COMMON
                        0x0E40,   // 0E40..0E80; THAI
                        0x0E81,   // 0E81..0EFF; LAO
                        0x0F00,   // 0F00..0FD4; TIBETAN
                        0x0FD5,   // 0FD5..0FD8; COMMON
                        0x0FD9,   // 0FD9..0FFF; TIBETAN
                        0x1000,   // 1000..109F; MYANMAR
                        0x10A0,   // 10A0..10FA; GEORGIAN
                        0x10FB,   // 10FB..10FB; COMMON
                        0x10FC,   // 10FC..10FF; GEORGIAN
                        0x1100,   // 1100..11FF; HANGUL
                        0x1200,   // 1200..139F; ETHIOPIC
                        0x13A0,   // 13A0..13FF; CHEROKEE
                        0x1400,   // 1400..167F; CANADIAN_ABORIGINAL
                        0x1680,   // 1680..169F; OGHAM
                        0x16A0,   // 16A0..16EA; RUNIC
                        0x16EB,   // 16EB..16ED; COMMON
                        0x16EE,   // 16EE..16FF; RUNIC
                        0x1700,   // 1700..171F; TAGALOG
                        0x1720,   // 1720..1734; HANUNOO
                        0x1735,   // 1735..173F; COMMON
                        0x1740,   // 1740..175F; BUHID
                        0x1760,   // 1760..177F; TAGBANWA
                        0x1780,   // 1780..17FF; KHMER
                        0x1800,   // 1800..1801; MONGOLIAN
                        0x1802,   // 1802..1803; COMMON
                        0x1804,   // 1804..1804; MONGOLIAN
                        0x1805,   // 1805..1805; COMMON
                        0x1806,   // 1806..18AF; MONGOLIAN
                        0x18B0,   // 18B0..18FF; CANADIAN_ABORIGINAL
                        0x1900,   // 1900..194F; LIMBU
                        0x1950,   // 1950..197F; TAI_LE
                        0x1980,   // 1980..19DF; NEW_TAI_LUE
                        0x19E0,   // 19E0..19FF; KHMER
                        0x1A00,   // 1A00..1A1F; BUGINESE
                        0x1A20,   // 1A20..1AFF; TAI_THAM
                        0x1B00,   // 1B00..1B7F; BALINESE
                        0x1B80,   // 1B80..1BBF; SUNDANESE
                        0x1BC0,   // 1BC0..1BFF; BATAK
                        0x1C00,   // 1C00..1C4F; LEPCHA
                        0x1C50,   // 1C50..1CBF; OL_CHIKI
                        0x1CC0,   // 1CC0..1CCF; SUNDANESE
                        0x1CD0,   // 1CD0..1CD2; INHERITED
                        0x1CD3,   // 1CD3..1CD3; COMMON
                        0x1CD4,   // 1CD4..1CE0; INHERITED
                        0x1CE1,   // 1CE1..1CE1; COMMON
                        0x1CE2,   // 1CE2..1CE8; INHERITED
                        0x1CE9,   // 1CE9..1CEC; COMMON
                        0x1CED,   // 1CED..1CED; INHERITED
                        0x1CEE,   // 1CEE..1CF3; COMMON
                        0x1CF4,   // 1CF4..1CF4; INHERITED
                        0x1CF5,   // 1CF5..1CFF; COMMON
                        0x1D00,   // 1D00..1D25; LATIN
                        0x1D26,   // 1D26..1D2A; GREEK
                        0x1D2B,   // 1D2B..1D2B; CYRILLIC
                        0x1D2C,   // 1D2C..1D5C; LATIN
                        0x1D5D,   // 1D5D..1D61; GREEK
                        0x1D62,   // 1D62..1D65; LATIN
                        0x1D66,   // 1D66..1D6A; GREEK
                        0x1D6B,   // 1D6B..1D77; LATIN
                        0x1D78,   // 1D78..1D78; CYRILLIC
                        0x1D79,   // 1D79..1DBE; LATIN
                        0x1DBF,   // 1DBF..1DBF; GREEK
                        0x1DC0,   // 1DC0..1DFF; INHERITED
                        0x1E00,   // 1E00..1EFF; LATIN
                        0x1F00,   // 1F00..1FFF; GREEK
                        0x2000,   // 2000..200B; COMMON
                        0x200C,   // 200C..200D; INHERITED
                        0x200E,   // 200E..2070; COMMON
                        0x2071,   // 2071..2073; LATIN
                        0x2074,   // 2074..207E; COMMON
                        0x207F,   // 207F..207F; LATIN
                        0x2080,   // 2080..208F; COMMON
                        0x2090,   // 2090..209F; LATIN
                        0x20A0,   // 20A0..20CF; COMMON
                        0x20D0,   // 20D0..20FF; INHERITED
                        0x2100,   // 2100..2125; COMMON
                        0x2126,   // 2126..2126; GREEK
                        0x2127,   // 2127..2129; COMMON
                        0x212A,   // 212A..212B; LATIN
                        0x212C,   // 212C..2131; COMMON
                        0x2132,   // 2132..2132; LATIN
                        0x2133,   // 2133..214D; COMMON
                        0x214E,   // 214E..214E; LATIN
                        0x214F,   // 214F..215F; COMMON
                        0x2160,   // 2160..2188; LATIN
                        0x2189,   // 2189..27FF; COMMON
                        0x2800,   // 2800..28FF; BRAILLE
                        0x2900,   // 2900..2BFF; COMMON
                        0x2C00,   // 2C00..2C5F; GLAGOLITIC
                        0x2C60,   // 2C60..2C7F; LATIN
                        0x2C80,   // 2C80..2CFF; COPTIC
                        0x2D00,   // 2D00..2D2F; GEORGIAN
                        0x2D30,   // 2D30..2D7F; TIFINAGH
                        0x2D80,   // 2D80..2DDF; ETHIOPIC
                        0x2DE0,   // 2DE0..2DFF; CYRILLIC
                        0x2E00,   // 2E00..2E7F; COMMON
                        0x2E80,   // 2E80..2FEF; HAN
                        0x2FF0,   // 2FF0..3004; COMMON
                        0x3005,   // 3005..3005; HAN
                        0x3006,   // 3006..3006; COMMON
                        0x3007,   // 3007..3007; HAN
                        0x3008,   // 3008..3020; COMMON
                        0x3021,   // 3021..3029; HAN
                        0x302A,   // 302A..302D; INHERITED
                        0x302E,   // 302E..302F; HANGUL
                        0x3030,   // 3030..3037; COMMON
                        0x3038,   // 3038..303B; HAN
                        0x303C,   // 303C..3040; COMMON
                        0x3041,   // 3041..3098; HIRAGANA
                        0x3099,   // 3099..309A; INHERITED
                        0x309B,   // 309B..309C; COMMON
                        0x309D,   // 309D..309F; HIRAGANA
                        0x30A0,   // 30A0..30A0; COMMON
                        0x30A1,   // 30A1..30FA; KATAKANA
                        0x30FB,   // 30FB..30FC; COMMON
                        0x30FD,   // 30FD..3104; KATAKANA
                        0x3105,   // 3105..3130; BOPOMOFO
                        0x3131,   // 3131..318F; HANGUL
                        0x3190,   // 3190..319F; COMMON
                        0x31A0,   // 31A0..31BF; BOPOMOFO
                        0x31C0,   // 31C0..31EF; COMMON
                        0x31F0,   // 31F0..31FF; KATAKANA
                        0x3200,   // 3200..321F; HANGUL
                        0x3220,   // 3220..325F; COMMON
                        0x3260,   // 3260..327E; HANGUL
                        0x327F,   // 327F..32CF; COMMON
                        0x32D0,   // 32D0..3357; KATAKANA
                        0x3358,   // 3358..33FF; COMMON
                        0x3400,   // 3400..4DBF; HAN
                        0x4DC0,   // 4DC0..4DFF; COMMON
                        0x4E00,   // 4E00..9FFF; HAN
                        0xA000,   // A000..A4CF; YI
                        0xA4D0,   // A4D0..A4FF; LISU
                        0xA500,   // A500..A63F; VAI
                        0xA640,   // A640..A69F; CYRILLIC
                        0xA6A0,   // A6A0..A6FF; BAMUM
                        0xA700,   // A700..A721; COMMON
                        0xA722,   // A722..A787; LATIN
                        0xA788,   // A788..A78A; COMMON
                        0xA78B,   // A78B..A7FF; LATIN
                        0xA800,   // A800..A82F; SYLOTI_NAGRI
                        0xA830,   // A830..A83F; COMMON
                        0xA840,   // A840..A87F; PHAGS_PA
                        0xA880,   // A880..A8DF; SAURASHTRA
                        0xA8E0,   // A8E0..A8FF; DEVANAGARI
                        0xA900,   // A900..A92F; KAYAH_LI
                        0xA930,   // A930..A95F; REJANG
                        0xA960,   // A960..A97F; HANGUL
                        0xA980,   // A980..A9FF; JAVANESE
                        0xAA00,   // AA00..AA5F; CHAM
                        0xAA60,   // AA60..AA7F; MYANMAR
                        0xAA80,   // AA80..AADF; TAI_VIET
                        0xAAE0,   // AAE0..AB00; MEETEI_MAYEK
                        0xAB01,   // AB01..ABBF; ETHIOPIC
                        0xABC0,   // ABC0..ABFF; MEETEI_MAYEK
                        0xAC00,   // AC00..D7FB; HANGUL
                        0xD7FC,   // D7FC..F8FF; UNKNOWN
                        0xF900,   // F900..FAFF; HAN
                        0xFB00,   // FB00..FB12; LATIN
                        0xFB13,   // FB13..FB1C; ARMENIAN
                        0xFB1D,   // FB1D..FB4F; HEBREW
                        0xFB50,   // FB50..FD3D; ARABIC
                        0xFD3E,   // FD3E..FD4F; COMMON
                        0xFD50,   // FD50..FDFC; ARABIC
                        0xFDFD,   // FDFD..FDFF; COMMON
                        0xFE00,   // FE00..FE0F; INHERITED
                        0xFE10,   // FE10..FE1F; COMMON
                        0xFE20,   // FE20..FE2F; INHERITED
                        0xFE30,   // FE30..FE6F; COMMON
                        0xFE70,   // FE70..FEFE; ARABIC
                        0xFEFF,   // FEFF..FF20; COMMON
                        0xFF21,   // FF21..FF3A; LATIN
                        0xFF3B,   // FF3B..FF40; COMMON
                        0xFF41,   // FF41..FF5A; LATIN
                        0xFF5B,   // FF5B..FF65; COMMON
                        0xFF66,   // FF66..FF6F; KATAKANA
                        0xFF70,   // FF70..FF70; COMMON
                        0xFF71,   // FF71..FF9D; KATAKANA
                        0xFF9E,   // FF9E..FF9F; COMMON
                        0xFFA0,   // FFA0..FFDF; HANGUL
                        0xFFE0,   // FFE0..FFFF; COMMON
                        0x10000,  // 10000..100FF; LINEAR_B
                        0x10100,  // 10100..1013F; COMMON
                        0x10140,  // 10140..1018F; GREEK
                        0x10190,  // 10190..101FC; COMMON
                        0x101FD,  // 101FD..1027F; INHERITED
                        0x10280,  // 10280..1029F; LYCIAN
                        0x102A0,  // 102A0..102FF; CARIAN
                        0x10300,  // 10300..1032F; OLD_ITALIC
                        0x10330,  // 10330..1037F; GOTHIC
                        0x10380,  // 10380..1039F; UGARITIC
                        0x103A0,  // 103A0..103FF; OLD_PERSIAN
                        0x10400,  // 10400..1044F; DESERET
                        0x10450,  // 10450..1047F; SHAVIAN
                        0x10480,  // 10480..107FF; OSMANYA
                        0x10800,  // 10800..1083F; CYPRIOT
                        0x10840,  // 10840..108FF; IMPERIAL_ARAMAIC
                        0x10900,  // 10900..1091F; PHOENICIAN
                        0x10920,  // 10920..1097F; LYDIAN
                        0x10980,  // 10980..1099F; MEROITIC_HIEROGLYPHS
                        0x109A0,  // 109A0..109FF; MEROITIC_CURSIVE
                        0x10A00,  // 10A00..10A5F; KHAROSHTHI
                        0x10A60,  // 10A60..10AFF; OLD_SOUTH_ARABIAN
                        0x10B00,  // 10B00..10B3F; AVESTAN
                        0x10B40,  // 10B40..10B5F; INSCRIPTIONAL_PARTHIAN
                        0x10B60,  // 10B60..10BFF; INSCRIPTIONAL_PAHLAVI
                        0x10C00,  // 10C00..10E5F; OLD_TURKIC
                        0x10E60,  // 10E60..10FFF; ARABIC
                        0x11000,  // 11000..1107F; BRAHMI
                        0x11080,  // 11080..110CF; KAITHI
                        0x110D0,  // 110D0..110FF; SORA_SOMPENG
                        0x11100,  // 11100..1117F; CHAKMA
                        0x11180,  // 11180..1167F; SHARADA
                        0x11680,  // 11680..116CF; TAKRI
                        0x12000,  // 12000..12FFF; CUNEIFORM
                        0x13000,  // 13000..167FF; EGYPTIAN_HIEROGLYPHS
                        0x16800,  // 16800..16A38; BAMUM
                        0x16F00,  // 16F00..16F9F; MIAO
                        0x1B000,  // 1B000..1B000; KATAKANA
                        0x1B001,  // 1B001..1CFFF; HIRAGANA
                        0x1D000,  // 1D000..1D166; COMMON
                        0x1D167,  // 1D167..1D169; INHERITED
                        0x1D16A,  // 1D16A..1D17A; COMMON
                        0x1D17B,  // 1D17B..1D182; INHERITED
                        0x1D183,  // 1D183..1D184; COMMON
                        0x1D185,  // 1D185..1D18B; INHERITED
                        0x1D18C,  // 1D18C..1D1A9; COMMON
                        0x1D1AA,  // 1D1AA..1D1AD; INHERITED
                        0x1D1AE,  // 1D1AE..1D1FF; COMMON
                        0x1D200,  // 1D200..1D2FF; GREEK
                        0x1D300,  // 1D300..1EDFF; COMMON
                        0x1EE00,  // 1EE00..1EFFF; ARABIC
                        0x1F000,  // 1F000..1F1FF; COMMON
                        0x1F200,  // 1F200..1F200; HIRAGANA
                        0x1F201,  // 1F210..1FFFF; COMMON
                        0x20000,  // 20000..E0000; HAN
                        0xE0001,  // E0001..E00FF; COMMON
                        0xE0100,  // E0100..E01EF; INHERITED
                        0xE01F0   // E01F0..10FFFF; UNKNOWN
                };

Array<Character::UnicodeScript> Character::UnicodeScript::scripts = {
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        BOPOMOFO,
                        COMMON,
                        INHERITED,
                        GREEK,
                        COMMON,
                        GREEK,
                        COMMON,
                        GREEK,
                        COMMON,
                        GREEK,
                        COMMON,
                        GREEK,
                        COPTIC,
                        GREEK,
                        CYRILLIC,
                        INHERITED,
                        CYRILLIC,
                        ARMENIAN,
                        COMMON,
                        ARMENIAN,
                        HEBREW,
                        ARABIC,
                        COMMON,
                        ARABIC,
                        COMMON,
                        ARABIC,
                        COMMON,
                        ARABIC,
                        COMMON,
                        ARABIC,
                        INHERITED,
                        ARABIC,
                        COMMON,
                        ARABIC,
                        INHERITED,
                        ARABIC,
                        COMMON,
                        ARABIC,
                        SYRIAC,
                        ARABIC,
                        THAANA,
                        NKO,
                        SAMARITAN,
                        MANDAIC,
                        ARABIC,
                        DEVANAGARI,
                        INHERITED,
                        DEVANAGARI,
                        COMMON,
                        DEVANAGARI,
                        BENGALI,
                        GURMUKHI,
                        GUJARATI,
                        ORIYA,
                        TAMIL,
                        TELUGU,
                        KANNADA,
                        MALAYALAM,
                        SINHALA,
                        THAI,
                        COMMON,
                        THAI,
                        LAO,
                        TIBETAN,
                        COMMON,
                        TIBETAN,
                        MYANMAR,
                        GEORGIAN,
                        COMMON,
                        GEORGIAN,
                        HANGUL,
                        ETHIOPIC,
                        CHEROKEE,
                        CANADIAN_ABORIGINAL,
                        OGHAM,
                        RUNIC,
                        COMMON,
                        RUNIC,
                        TAGALOG,
                        HANUNOO,
                        COMMON,
                        BUHID,
                        TAGBANWA,
                        KHMER,
                        MONGOLIAN,
                        COMMON,
                        MONGOLIAN,
                        COMMON,
                        MONGOLIAN,
                        CANADIAN_ABORIGINAL,
                        LIMBU,
                        TAI_LE,
                        NEW_TAI_LUE,
                        KHMER,
                        BUGINESE,
                        TAI_THAM,
                        BALINESE,
                        SUNDANESE,
                        BATAK,
                        LEPCHA,
                        OL_CHIKI,
                        SUNDANESE,
                        INHERITED,
                        COMMON,
                        INHERITED,
                        COMMON,
                        INHERITED,
                        COMMON,
                        INHERITED,
                        COMMON,
                        INHERITED,
                        COMMON,
                        LATIN,
                        GREEK,
                        CYRILLIC,
                        LATIN,
                        GREEK,
                        LATIN,
                        GREEK,
                        LATIN,
                        CYRILLIC,
                        LATIN,
                        GREEK,
                        INHERITED,
                        LATIN,
                        GREEK,
                        COMMON,
                        INHERITED,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        INHERITED,
                        COMMON,
                        GREEK,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        BRAILLE,
                        COMMON,
                        GLAGOLITIC,
                        LATIN,
                        COPTIC,
                        GEORGIAN,
                        TIFINAGH,
                        ETHIOPIC,
                        CYRILLIC,
                        COMMON,
                        HAN,
                        COMMON,
                        HAN,
                        COMMON,
                        HAN,
                        COMMON,
                        HAN,
                        INHERITED,
                        HANGUL,
                        COMMON,
                        HAN,
                        COMMON,
                        HIRAGANA,
                        INHERITED,
                        COMMON,
                        HIRAGANA,
                        COMMON,
                        KATAKANA,
                        COMMON,
                        KATAKANA,
                        BOPOMOFO,
                        HANGUL,
                        COMMON,
                        BOPOMOFO,
                        COMMON,
                        KATAKANA,
                        HANGUL,
                        COMMON,
                        HANGUL,
                        COMMON,
                        KATAKANA,
                        COMMON,
                        HAN,
                        COMMON,
                        HAN,
                        YI,
                        LISU,
                        VAI,
                        CYRILLIC,
                        BAMUM,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        SYLOTI_NAGRI,
                        COMMON,
                        PHAGS_PA,
                        SAURASHTRA,
                        DEVANAGARI,
                        KAYAH_LI,
                        REJANG,
                        HANGUL,
                        JAVANESE,
                        CHAM,
                        MYANMAR,
                        TAI_VIET,
                        MEETEI_MAYEK,
                        ETHIOPIC,
                        MEETEI_MAYEK,
                        HANGUL,
                        UNKNOWN     ,
                        HAN,
                        LATIN,
                        ARMENIAN,
                        HEBREW,
                        ARABIC,
                        COMMON,
                        ARABIC,
                        COMMON,
                        INHERITED,
                        COMMON,
                        INHERITED,
                        COMMON,
                        ARABIC,
                        COMMON,
                        LATIN,
                        COMMON,
                        LATIN,
                        COMMON,
                        KATAKANA,
                        COMMON,
                        KATAKANA,
                        COMMON,
                        HANGUL,
                        COMMON,
                        LINEAR_B,
                        COMMON,
                        GREEK,
                        COMMON,
                        INHERITED,
                        LYCIAN,
                        CARIAN,
                        OLD_ITALIC,
                        GOTHIC,
                        UGARITIC,
                        OLD_PERSIAN,
                        DESERET,
                        SHAVIAN,
                        OSMANYA,
                        CYPRIOT,
                        IMPERIAL_ARAMAIC,
                        PHOENICIAN,
                        LYDIAN,
                        MEROITIC_HIEROGLYPHS,
                        MEROITIC_CURSIVE,
                        KHAROSHTHI,
                        OLD_SOUTH_ARABIAN,
                        AVESTAN,
                        INSCRIPTIONAL_PARTHIAN,
                        INSCRIPTIONAL_PAHLAVI,
                        OLD_TURKIC,
                        ARABIC,
                        BRAHMI,
                        KAITHI,
                        SORA_SOMPENG,
                        CHAKMA,
                        SHARADA,
                        TAKRI,
                        CUNEIFORM,
                        EGYPTIAN_HIEROGLYPHS,
                        BAMUM,
                        MIAO,
                        KATAKANA,
                        HIRAGANA,
                        COMMON,
                        INHERITED,
                        COMMON,
                        INHERITED,
                        COMMON,
                        INHERITED,
                        COMMON,
                        INHERITED,
                        COMMON,
                        GREEK,
                        COMMON,
                        ARABIC,
                        COMMON,
                        HIRAGANA,
                        COMMON,
                        HAN,
                        COMMON,
                        INHERITED,
                        UNKNOWN
};

Array<String> Character::UnicodeScript::scriptNames = {
        "COMMON",
        "LATIN",
        "GREEK",
        "CYRILLIC",
        "ARMENIAN",
        "HEBREW",
        "ARABIC",
        "SYRIAC",
        "THAANA",
        "DEVANAGARI",
        "BENGALI",
        "GURMUKHI",
        "GUJARATI",
        "ORIYA",
        "TAMIL",
        "TELUGU",
        "KANNADA",
        "MALAYALAM",
        "SINHALA",
        "THAI",
        "LAO",
        "TIBETAN",
        "MYANMAR",
        "GEORGIAN",
        "HANGUL",
        "ETHIOPIC",
        "CHEROKEE",
        "CANADIAN_ABORIGINAL",
        "OGHAM",
        "RUNIC",
        "KHMER",
        "MONGOLIAN",
        "HIRAGANA",
        "KATAKANA",
        "BOPOMOFO",
        "HAN",
        "YI",
        "OLD_ITALIC",
        "GOTHIC",
        "DESERET",
        "INHERITED",
        "TAGALOG",
        "HANUNOO",
        "BUHID",
        "TAGBANWA",
        "LIMBU",
        "TAI_LE",
        "LINEAR_B",
        "UGARITIC",
        "SHAVIAN",
        "OSMANYA",
        "CYPRIOT",
        "BRAILLE",
        "BUGINESE",
        "COPTIC",
        "NEW_TAI_LUE",
        "GLAGOLITIC",
        "TIFINAGH",
        "SYLOTI_NAGRI",
        "OLD_PERSIAN",
        "KHAROSHTHI",
        "BALINESE",
        "CUNEIFORM",
        "PHOENICIAN",
        "PHAGS_PA",
        "NKO",
        "SUNDANESE",
        "BATAK",
        "LEPCHA",
        "OL_CHIKI",
        "VAI",
        "SAURASHTRA",
        "KAYAH_LI",
        "REJANG",
        "LYCIAN",
        "CARIAN",
        "LYDIAN",
        "CHAM",
        "TAI_THAM",
        "TAI_VIET",
        "AVESTAN",
        "EGYPTIAN_HIEROGLYPHS",
        "SAMARITAN",
        "MANDAIC",
        "LISU",
        "BAMUM",
        "JAVANESE",
        "MEETEI_MAYEK",
        "IMPERIAL_ARAMAIC",
        "OLD_SOUTH_ARABIAN",
        "INSCRIPTIONAL_PARTHIAN",
        "INSCRIPTIONAL_PAHLAVI",
        "OLD_TURKIC",
        "BRAHMI",
        "KAITHI",
        "MEROITIC_HIEROGLYPHS",
        "MEROITIC_CURSIVE",
        "SORA_SOMPENG",
        "CHAKMA",
        "SHARADA",
        "TAKRI",
        "MIAO",
        "UNKNOWN"
};

HashMap<String, Character::UnicodeScript> Character::UnicodeScript::aliasesInit() {
    HashMap<String, Character::UnicodeScript> aliases;
    aliases.put("ARAB", ARABIC);
    aliases.put("ARMI", IMPERIAL_ARAMAIC);
    aliases.put("ARMN", ARMENIAN);
    aliases.put("AVST", AVESTAN);
    aliases.put("BALI", BALINESE);
    aliases.put("BAMU", BAMUM);
    aliases.put("BATK", BATAK);
    aliases.put("BENG", BENGALI);
    aliases.put("BOPO", BOPOMOFO);
    aliases.put("BRAI", BRAILLE);
    aliases.put("BRAH", BRAHMI);
    aliases.put("BUGI", BUGINESE);
    aliases.put("BUHD", BUHID);
    aliases.put("CAKM", CHAKMA);
    aliases.put("CANS", CANADIAN_ABORIGINAL);
    aliases.put("CARI", CARIAN);
    aliases.put("CHAM", CHAM);
    aliases.put("CHER", CHEROKEE);
    aliases.put("COPT", COPTIC);
    aliases.put("CPRT", CYPRIOT);
    aliases.put("CYRL", CYRILLIC);
    aliases.put("DEVA", DEVANAGARI);
    aliases.put("DSRT", DESERET);
    aliases.put("EGYP", EGYPTIAN_HIEROGLYPHS);
    aliases.put("ETHI", ETHIOPIC);
    aliases.put("GEOR", GEORGIAN);
    aliases.put("GLAG", GLAGOLITIC);
    aliases.put("GOTH", GOTHIC);
    aliases.put("GREK", GREEK);
    aliases.put("GUJR", GUJARATI);
    aliases.put("GURU", GURMUKHI);
    aliases.put("HANG", HANGUL);
    aliases.put("HANI", HAN);
    aliases.put("HANO", HANUNOO);
    aliases.put("HEBR", HEBREW);
    aliases.put("HIRA", HIRAGANA);
    aliases.put("ITAL", OLD_ITALIC);
    aliases.put("JAVA", JAVANESE);
    aliases.put("KALI", KAYAH_LI);
    aliases.put("KANA", KATAKANA);
    aliases.put("KHAR", KHAROSHTHI);
    aliases.put("KHMR", KHMER);
    aliases.put("KNDA", KANNADA);
    aliases.put("KTHI", KAITHI);
    aliases.put("LANA", TAI_THAM);
    aliases.put("LAOO", LAO);
    aliases.put("LATN", LATIN);
    aliases.put("LEPC", LEPCHA);
    aliases.put("LIMB", LIMBU);
    aliases.put("LINB", LINEAR_B);
    aliases.put("LISU", LISU);
    aliases.put("LYCI", LYCIAN);
    aliases.put("LYDI", LYDIAN);
    aliases.put("MAND", MANDAIC);
    aliases.put("MERC", MEROITIC_CURSIVE);
    aliases.put("MERO", MEROITIC_HIEROGLYPHS);
    aliases.put("MLYM", MALAYALAM);
    aliases.put("MONG", MONGOLIAN);
    aliases.put("MTEI", MEETEI_MAYEK);
    aliases.put("MYMR", MYANMAR);
    aliases.put("NKOO", NKO);
    aliases.put("OGAM", OGHAM);
    aliases.put("OLCK", OL_CHIKI);
    aliases.put("ORKH", OLD_TURKIC);
    aliases.put("ORYA", ORIYA);
    aliases.put("OSMA", OSMANYA);
    aliases.put("PHAG", PHAGS_PA);
    aliases.put("PLRD", MIAO);
    aliases.put("PHLI", INSCRIPTIONAL_PAHLAVI);
    aliases.put("PHNX", PHOENICIAN);
    aliases.put("PRTI", INSCRIPTIONAL_PARTHIAN);
    aliases.put("RJNG", REJANG);
    aliases.put("RUNR", RUNIC);
    aliases.put("SAMR", SAMARITAN);
    aliases.put("SARB", OLD_SOUTH_ARABIAN);
    aliases.put("SAUR", SAURASHTRA);
    aliases.put("SHAW", SHAVIAN);
    aliases.put("SHRD", SHARADA);
    aliases.put("SINH", SINHALA);
    aliases.put("SORA", SORA_SOMPENG);
    aliases.put("SUND", SUNDANESE);
    aliases.put("SYLO", SYLOTI_NAGRI);
    aliases.put("SYRC", SYRIAC);
    aliases.put("TAGB", TAGBANWA);
    aliases.put("TALE", TAI_LE);
    aliases.put("TAKR", TAKRI);
    aliases.put("TALU", NEW_TAI_LUE);
    aliases.put("TAML", TAMIL);
    aliases.put("TAVT", TAI_VIET);
    aliases.put("TELU", TELUGU);
    aliases.put("TFNG", TIFINAGH);
    aliases.put("TGLG", TAGALOG);
    aliases.put("THAA", THAANA);
    aliases.put("THAI", THAI);
    aliases.put("TIBT", TIBETAN);
    aliases.put("UGAR", UGARITIC);
    aliases.put("VAII", VAI);
    aliases.put("XPEO", OLD_PERSIAN);
    aliases.put("XSUX", CUNEIFORM);
    aliases.put("YIII", YI);
    aliases.put("ZINH", INHERITED);
    aliases.put("ZYYY", COMMON);
    aliases.put("ZZZZ", UNKNOWN);

    return aliases;
}

HashMap<String, Character::UnicodeScript> Character::UnicodeScript::aliases = Character::UnicodeScript::aliasesInit();

boolean Character::UnicodeScript::operator==(const Character::UnicodeScript &otherUnicodeScript) const {
    return 0;
}

//Character::UnicodeScript Character::UnicodeScript::of(int codePoint)  {
//    if (!isValidCodePoint(codePoint))
//        throw IllegalArgumentException();
//    int type = Character::getType(codePoint);
//    // leave SURROGATE and PRIVATE_USE for table lookup
//    if (type == UNASSIGNED)
//        return UnicodeScript::Script::UNKNOWN;
//    int index = Arrays::binarySearch(Character::UnicodeScript::scriptStarts, codePoint, scriptStarts.length);
//    if (index < 0)
//        index = -index - 2;
//    return scripts[index];
//}

Character::UnicodeScript::UnicodeScript(String scriptName) {
    int index = Arrays::binarySearch(Character::UnicodeScript::scriptNames,
                                     scriptName, Character::UnicodeScript::scriptNames.length);

    if (index == -1) {
        throw IllegalArgumentException("No enum constant Character::UnicodeScript::" + scriptName);
    }

    *this = UnicodeScript((Character::UnicodeScript::Script) index);
}

Character::UnicodeScript Character::UnicodeScript::forName(String scriptName) {
        scriptName = scriptName.toUpperCase();
        UnicodeScript script = aliases.get(scriptName);
        if (script.unicodeScript != UnicodeScript::DEFAULT)
            return script;
        return UnicodeScript(scriptName);
}
