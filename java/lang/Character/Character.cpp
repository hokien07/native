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

boolean Character::UnicodeBlock::operator==(const Character::UnicodeBlock &leftValue) const{
    return 0;
}

