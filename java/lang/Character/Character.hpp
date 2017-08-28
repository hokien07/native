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

#ifndef NATIVE_JAVA_LANG_CHARACTER_HPP_
#define NATIVE_JAVA_LANG_CHARACTER_HPP_

#include "../CharSequence/CharSequence.hpp"
#include "../../Lang.hpp"
#include "../../util/HashMap/HashMap.hpp"

using namespace Java::Util;

namespace Java {
    namespace Lang {
        class Character : Object,
                          public virtual Comparable<Character> {
        private:
            class Subset  {
                private:
                    String name;
                    static Subset* instance;

                protected:
                    /**
                     * Constructs a new Subset instance.
                     *
                     * @param  name
                     */

                    Subset (const String &name) {
                        this->name = name;
                    }

                    Subset(){};

                public:

                    /**
                     * Return instance of Subset
                     *
                     * @return
                     */
                    static Subset *getInstance() {
                        if (instance == nullptr)
                            instance = new Subset("");
                        return instance;
                    }

                    /**
                     * Returns the name of this subset.
                     */
                    String toString() {
                        return name;
                    }
                };

            class UnicodeBlock : public Subset {
            public:
                /**
                 * Default constructor
                 */
                UnicodeBlock(){};

                /**
                 * Create a UnicodeBlock with a String
                 *
                 * @param name
                 */
                UnicodeBlock(const String &name);

                static HashMap<String, UnicodeBlock> map;

                /**
                 * Creates a UnicodeBlock with the given identifier name.
                 * This name must be the same as the block identifier.
                 */
                 UnicodeBlock(String &idName) : Subset(idName) {
                    UnicodeBlock::map.put(idName, *this);
                 }

                /**
                 * Creates a UnicodeBlock with the given identifier name and
                 * alias name.
                 */
                UnicodeBlock(String &idName, String &alias) : Subset(idName) {
                    UnicodeBlock::map.put(alias, *this);
                }

                /**
                 * Creates a UnicodeBlock with the given identifier name and
                 * alias names.
                 */
                template<typename ... Args>
                UnicodeBlock(String idName, Args ... aliases) : Subset(idName) {
                    std::initializer_list<String> paramList = {aliases...};
                    for (String alias : paramList) {
                        UnicodeBlock::map.put(alias, *this);
                    }
                }


            public:

                boolean operator==(const UnicodeBlock &leftValue) const;

                /**
                 * Constant for the "Basic Latin" Unicode character block.
                 */
                static UnicodeBlock BASIC_LATIN;

                /**
                 * Constant for the "Latin-1 Supplement" Unicode character block.
                 */
                static UnicodeBlock LATIN_1_SUPPLEMENT;

                /**
                 * Constant for the "Latin Extended-A" Unicode character block
                 */
                static UnicodeBlock LATIN_EXTENDED_A;

                /**
                 * Constant for the "Latin Extended-B" Unicode character block.
                 */
                static UnicodeBlock LATIN_EXTENDED_B;

                /**
                 * Constant for the "IPA Extensions" Unicode character block.
                 */
                static UnicodeBlock IPA_EXTENSIONS;

                /**
                 * Constant for the "Spacing Modifier Letters" Unicode character block.
                 */
                static UnicodeBlock SPACING_MODIFIER_LETTERS;

                /**
                 * Constant for the "Combining Diacritical Marks" Unicode character block.
                 */
                static UnicodeBlock COMBINING_DIACRITICAL_MARKS;

                /**
                 * Constant for the "Greek and Coptic" Unicode character block.
                 * This block was previously known as the "Greek" block
                 */
                static UnicodeBlock GREEK;

                /**
                 * Constant for the "Cyrillic" Unicode character block.
                 */
                static UnicodeBlock CYRILLIC;

                /**
                 * Constant for the "Armenian" Unicode character block.
                 */
                static UnicodeBlock ARMENIAN;

                /**
                 * Constant for the "Hebrew" Unicode character block.
                 */
                static UnicodeBlock HEBREW;

                /**
                 * Constant for the "Arabic" Unicode character block.
                 */
                static UnicodeBlock ARABIC;

                /**
                 * Constant for the "Devanagari" Unicode character block.
                 */
                static UnicodeBlock DEVANAGARI;

                /**
                 * Constant for the "Bengali" Unicode character block.
                 */
                static UnicodeBlock BENGALI;

                /**
                 * Constant for the "Gurmukhi" Unicode character block.
                 */
                static UnicodeBlock GURMUKHI;

                /**
                 * Constant for the "Gujarati" Unicode character block.
                 */
                static UnicodeBlock GUJARATI;

                /**
                 * Constant for the "Oriya" Unicode character block.
                 */
                static UnicodeBlock ORIYA;

                /**
                 * Constant for the "Tamil" Unicode character block.
                 */
                static UnicodeBlock TAMIL;

                /**
                 * Constant for the "Telugu" Unicode character block.
                 */
                static UnicodeBlock TELUGU;

                /**
                 * Constant for the "Kannada" Unicode character block.
                 */
                static UnicodeBlock KANNADA;

                /**
                 * Constant for the "Malayalam" Unicode character block.
                 */
                static UnicodeBlock MALAYALAM;

                /**
                 * Constant for the "Thai" Unicode character block.
                 */
                static UnicodeBlock THAI;

                /**
                 * Constant for the "Lao" Unicode character block.
                 */
                static UnicodeBlock LAO;

                /**
                 * Constant for the "Tibetan" Unicode character block.
                 */
                static UnicodeBlock TIBETAN;

                /**
                 * Constant for the "Georgian" Unicode character block.
                 */
                static UnicodeBlock GEORGIAN;

                /**
                 * Constant for the "Hangul Jamo" Unicode character block.
                 */
                static UnicodeBlock HANGUL_JAMO;

                /**
                 * Constant for the "Latin Extended Additional" Unicode character block.
                 */
                static UnicodeBlock LATIN_EXTENDED_ADDITIONAL;

                /**
                 * Constant for the "Greek Extended" Unicode character block.
                 */
                static UnicodeBlock GREEK_EXTENDED;

                /**
                 * Constant for the "General Punctuation" Unicode character block.
                 */
                static UnicodeBlock GENERAL_PUNCTUATION;

                /**
                 * Constant for the "Superscripts and Subscripts" Unicode character
                 * block.
                 */
                static UnicodeBlock SUPERSCRIPTS_AND_SUBSCRIPTS;

                /**
                 * Constant for the "Currency Symbols" Unicode character block.
                 */
                static UnicodeBlock CURRENCY_SYMBOLS;

                /**
                 * Constant for the "Combining Diacritical Marks for Symbols" Unicode
                 * character block.
                 * This block was previously known as "Combining Marks for Symbols".
                 */
                static UnicodeBlock COMBINING_MARKS_FOR_SYMBOLS;

                /**
                 * Constant for the "Letterlike Symbols" Unicode character block.
                 */
                static UnicodeBlock LETTERLIKE_SYMBOLS;

                /**
                 * Constant for the "Number Forms" Unicode character block.
                 */
                static UnicodeBlock NUMBER_FORMS;

                /**
                 * Constant for the "Arrows" Unicode character block.
                 */
                static UnicodeBlock ARROWS;

                /**
                 * Constant for the "Mathematical Operators" Unicode character block.
                 */
                static UnicodeBlock MATHEMATICAL_OPERATORS;

                /**
                 * Constant for the "Miscellaneous Technical" Unicode character block.
                 */
                static UnicodeBlock MISCELLANEOUS_TECHNICAL;

                /**
                 * Constant for the "Control Pictures" Unicode character block.
                 */
                static UnicodeBlock CONTROL_PICTURES;

                /**
                 * Constant for the "Optical Character Recognition" Unicode character block.
                 */
                static UnicodeBlock OPTICAL_CHARACTER_RECOGNITION;

                /**
                 * Constant for the "Enclosed Alphanumerics" Unicode character block.
                 */
                static UnicodeBlock ENCLOSED_ALPHANUMERICS;

                /**
                 * Constant for the "Box Drawing" Unicode character block.
                 */
                static UnicodeBlock BOX_DRAWING;

                /**
                 * Constant for the "Block Elements" Unicode character block.
                 */
                static UnicodeBlock BLOCK_ELEMENTS;

                /**
                 * Constant for the "Geometric Shapes" Unicode character block.
                 */
                static UnicodeBlock GEOMETRIC_SHAPES;

                /**
                 * Constant for the "Miscellaneous Symbols" Unicode character block.
                 */
                static UnicodeBlock MISCELLANEOUS_SYMBOLS;

                /**
                 * Constant for the "Dingbats" Unicode character block.
                 */
                static UnicodeBlock DINGBATS;

                /**
                 * Constant for the "CJK Symbols and Punctuation" Unicode character block.
                 */
                static UnicodeBlock CJK_SYMBOLS_AND_PUNCTUATION;

                /**
                 * Constant for the "Hiragana" Unicode character block.
                 */
                static UnicodeBlock HIRAGANA;

                /**
                 * Constant for the "Katakana" Unicode character block.
                 */
                static UnicodeBlock KATAKANA;

                /**
                 * Constant for the "Bopomofo" Unicode character block.
                 */
                static UnicodeBlock BOPOMOFO;

                /**
                 * Constant for the "Hangul Compatibility Jamo" Unicode character block.
                 */
                static UnicodeBlock HANGUL_COMPATIBILITY_JAMO;

                /**
                 * Constant for the "Kanbun" Unicode character block.
                 */
                static UnicodeBlock KANBUN;

                /**
                 * Constant for the "Enclosed CJK Letters and Months" Unicode character block.
                 */
                static UnicodeBlock ENCLOSED_CJK_LETTERS_AND_MONTHS;

                /**
                 * Constant for the "CJK Compatibility" Unicode character block.
                 */
                static UnicodeBlock CJK_COMPATIBILITY;

                /**
                 * Constant for the "CJK Unified Ideographs" Unicode character block.
                 */
                static UnicodeBlock CJK_UNIFIED_IDEOGRAPHS;

                /**
                 * Constant for the "Hangul Syllables" Unicode character block.
                 */
                static UnicodeBlock HANGUL_SYLLABLES;

                /**
                 * Constant for the "Private Use Area" Unicode character block.
                 */
                static UnicodeBlock PRIVATE_USE_AREA;

                /**
                 * Constant for the "CJK Compatibility Ideographs" Unicode character
                 * block.
                 */
                static UnicodeBlock CJK_COMPATIBILITY_IDEOGRAPHS;

                /**
                 * Constant for the "Alphabetic Presentation Forms" Unicode character block.
                 */
                static UnicodeBlock ALPHABETIC_PRESENTATION_FORMS;

                /**
                 * Constant for the "Arabic Presentation Forms-A" Unicode character
                 * block.
                 */
                static UnicodeBlock ARABIC_PRESENTATION_FORMS_A;

                /**
                 * Constant for the "Combining Half Marks" Unicode character block.
                 */
                static UnicodeBlock COMBINING_HALF_MARKS;

                /**
                 * Constant for the "CJK Compatibility Forms" Unicode character block.
                 */
                static UnicodeBlock CJK_COMPATIBILITY_FORMS;

                /**
                 * Constant for the "Small Form Variants" Unicode character block.
                 */
                static UnicodeBlock SMALL_FORM_VARIANTS;

                /**
                 * Constant for the "Arabic Presentation Forms-B" Unicode character block.
                 */
                static UnicodeBlock ARABIC_PRESENTATION_FORMS_B;

                /**
                 * Constant for the "Halfwidth and Fullwidth Forms" Unicode character
                 * block.
                 */
                static UnicodeBlock HALFWIDTH_AND_FULLWIDTH_FORMS;

                /**
                 * Constant for the "Specials" Unicode character block.
                 */
                static UnicodeBlock SPECIALS;

                /**
                 * Constant for the "Syriac" Unicode character block.
                 */
                static UnicodeBlock SYRIAC;

                /**
                 * Constant for the "Thaana" Unicode character block.
                 */
                static UnicodeBlock THAANA;

                /**
                 * Constant for the "Sinhala" Unicode character block.
                 */
                static UnicodeBlock SINHALA;

                /**
                 * Constant for the "Myanmar" Unicode character block.
                 */
                static UnicodeBlock MYANMAR;

                /**
                 * Constant for the "Ethiopic" Unicode character block.
                 */
                static UnicodeBlock ETHIOPIC;

                /**
                 * Constant for the "Cherokee" Unicode character block.
                 */
                static UnicodeBlock CHEROKEE;

                /**
                 * Constant for the "Unified Canadian Aboriginal Syllabics" Unicode character block.
                 */
                static UnicodeBlock UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS;

                /**
                 * Constant for the "Ogham" Unicode character block.
                 */
                static UnicodeBlock OGHAM;

                /**
                 * Constant for the "Runic" Unicode character block.
                 */
                static UnicodeBlock RUNIC;

                /**
                 * Constant for the "Khmer" Unicode character block.
                 */
                static UnicodeBlock KHMER;

                /**
                 * Constant for the "Mongolian" Unicode character block.
                 */
                static UnicodeBlock MONGOLIAN;

                /**
                 * Constant for the "Braille Patterns" Unicode character block.
                 */
                static UnicodeBlock BRAILLE_PATTERNS;

                /**
                 * Constant for the "CJK Radicals Supplement" Unicode character block.
                 */
                static UnicodeBlock CJK_RADICALS_SUPPLEMENT;

                /**
                 * Constant for the "Kangxi Radicals" Unicode character block.
                 */
                static UnicodeBlock KANGXI_RADICALS;

                /**
                 * Constant for the "Ideographic Description Characters" Unicode character block.
                 */
                static UnicodeBlock IDEOGRAPHIC_DESCRIPTION_CHARACTERS;

                /**
                 * Constant for the "Bopomofo Extended" Unicode character block.
                 */
                static UnicodeBlock BOPOMOFO_EXTENDED;

                /**
                 * Constant for the "CJK Unified Ideographs Extension A" Unicode character block.
                 */
                static UnicodeBlock CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A;

                /**
                 * Constant for the "Yi Syllables" Unicode character block.
                 */
                static UnicodeBlock YI_SYLLABLES;

                /**
                 * Constant for the "Yi Radicals" Unicode character block.
                 */
                static UnicodeBlock YI_RADICALS;

                /**
                 * Constant for the "Cyrillic Supplementary" Unicode character block.
                 */
                static UnicodeBlock CYRILLIC_SUPPLEMENTARY;

                /**
                 * Constant for the "Tagalog" Unicode character block.
                 */
                static UnicodeBlock TAGALOG;

                /**
                 * Constant for the "Hanunoo" Unicode character block.
                 */
                static UnicodeBlock HANUNOO;

                /**
                 * Constant for the "Buhid" Unicode character block.
                 */
                static UnicodeBlock BUHID;

                /**
                 * Constant for the "Tagbanwa" Unicode character block.
                 */
                static UnicodeBlock TAGBANWA;

                /**
                 * Constant for the "Limbu" Unicode character block.
                 */
                static UnicodeBlock LIMBU;

                /**
                 * Constant for the "Tai Le" Unicode character block.
                 */
                static UnicodeBlock TAI_LE;

                /**
                 * Constant for the "Khmer Symbols" Unicode character block.
                 */
                static UnicodeBlock KHMER_SYMBOLS;

                /**
                 * Constant for the "Phonetic Extensions" Unicode character block.
                 */
                static UnicodeBlock PHONETIC_EXTENSIONS;

                /**
                 * Constant for the "Miscellaneous Mathematical Symbols-A" Unicode character block.
                 */
                static UnicodeBlock MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A;

                /**
                 * Constant for the "Supplemental Arrows-A" Unicode character block.
                 */
                static UnicodeBlock SUPPLEMENTAL_ARROWS_A;

                /**
                 * Constant for the "Supplemental Arrows-B" Unicode character block.
                 */
                static UnicodeBlock SUPPLEMENTAL_ARROWS_B;

                /**
                 * Constant for the "Miscellaneous Mathematical Symbols-B" Unicode
                 * character block.
                 */
                static UnicodeBlock MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B;

                /**
                 * Constant for the "Supplemental Mathematical Operators" Unicode
                 * character block.
                 */
                static UnicodeBlock SUPPLEMENTAL_MATHEMATICAL_OPERATORS;

                /**
                 * Constant for the "Miscellaneous Symbols and Arrows" Unicode character
                 * block.
                 */
                static UnicodeBlock MISCELLANEOUS_SYMBOLS_AND_ARROWS;

                /**
                 * Constant for the "Katakana Phonetic Extensions" Unicode character
                 * block.
                 */
                static UnicodeBlock KATAKANA_PHONETIC_EXTENSIONS;

                /**
                 * Constant for the "Yijing Hexagram Symbols" Unicode character block.
                 */
                static UnicodeBlock YIJING_HEXAGRAM_SYMBOLS;

                /**
                 * Constant for the "Variation Selectors" Unicode character block.
                 */
                static UnicodeBlock VARIATION_SELECTORS;

                /**
                 * Constant for the "Linear B Syllabary" Unicode character block.
                 */
                static UnicodeBlock LINEAR_B_SYLLABARY;

                /**
                 * Constant for the "Linear B Ideograms" Unicode character block.
                 */
                static UnicodeBlock LINEAR_B_IDEOGRAMS;

                /**
                 * Constant for the "Aegean Numbers" Unicode character block.
                 */
                static UnicodeBlock AEGEAN_NUMBERS;

                /**
                 * Constant for the "Old Italic" Unicode character block.
                 */
                static UnicodeBlock OLD_ITALIC;

                /**
                 * Constant for the "Gothic" Unicode character block.
                 */
                static UnicodeBlock GOTHIC;

                /**
                 * Constant for the "Ugaritic" Unicode character block.
                 */
                static UnicodeBlock UGARITIC;

                /**
                 * Constant for the "Deseret" Unicode character block.
                 */
                static UnicodeBlock DESERET;

                /**
                 * Constant for the "Shavian" Unicode character block.
                 */
                static UnicodeBlock SHAVIAN;

                /**
                 * Constant for the "Osmanya" Unicode character block.
                 */
                static UnicodeBlock OSMANYA;

                /**
                 * Constant for the "Cypriot Syllabary" Unicode character block.
                 */
                static UnicodeBlock CYPRIOT_SYLLABARY;

                /**
                 * Constant for the "Byzantine Musical Symbols" Unicode character block.
                 */
                static UnicodeBlock BYZANTINE_MUSICAL_SYMBOLS;

                /**
                 * Constant for the "Musical Symbols" Unicode character block.
                 */
                static UnicodeBlock MUSICAL_SYMBOLS;

                /**
                 * Constant for the "Tai Xuan Jing Symbols" Unicode character block.
                 */
                static UnicodeBlock TAI_XUAN_JING_SYMBOLS;

                /**
                 * Constant for the "Mathematical Alphanumeric Symbols" Unicode
                 * character block.
                 */
                static UnicodeBlock MATHEMATICAL_ALPHANUMERIC_SYMBOLS;

                /**
                 * Constant for the "CJK Unified Ideographs Extension B" Unicode
                 * character block.
                 */
                static UnicodeBlock CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B;

                /**
                 * Constant for the "CJK Compatibility Ideographs Supplement" Unicode character block.
                 */
                static UnicodeBlock CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT;

                /**
                 * Constant for the "Tags" Unicode character block.
                 */
                static UnicodeBlock TAGS;

                /**
                 * Constant for the "Variation Selectors Supplement" Unicode character
                 * block.
                 */
                static UnicodeBlock VARIATION_SELECTORS_SUPPLEMENT;

                /**
                 * Constant for the "Supplementary Private Use Area-A" Unicode character
                 * block.
                 */
                static UnicodeBlock SUPPLEMENTARY_PRIVATE_USE_AREA_A;

                /**
                 * Constant for the "Supplementary Private Use Area-B" Unicode character
                 * block.
                 */
                static UnicodeBlock SUPPLEMENTARY_PRIVATE_USE_AREA_B;

                /**
                 * Constant for the "High Surrogates" Unicode character block.
                 * This block represents codepoint values in the high surrogate
                 * range: U+D800 through U+DB7F
                 */
                static UnicodeBlock HIGH_SURROGATES;

                /**
                 * Constant for the "High Private Use Surrogates" Unicode character
                 * block.
                 * This block represents codepoint values in the private use high
                 * surrogate range: U+DB80 through U+DBFF
                 */
                static UnicodeBlock HIGH_PRIVATE_USE_SURROGATES;

                /**
                 * Constant for the "Low Surrogates" Unicode character block.
                 * This block represents codepoint values in the low surrogate
                 * range: U+DC00 through U+DFFF
                 */
                static UnicodeBlock LOW_SURROGATES;

                /**
                 * Constant for the "Arabic Supplement" Unicode character block.
                 */
                static UnicodeBlock ARABIC_SUPPLEMENT;

                /**
                 * Constant for the "NKo" Unicode character block.
                 */
                static UnicodeBlock NKO;

                /**
                 * Constant for the "Samaritan" Unicode character block.
                 */
                static UnicodeBlock SAMARITAN;

                /**
                 * Constant for the "Mandaic" Unicode character block.
                 */
                static UnicodeBlock MANDAIC;

                /**
                 * Constant for the "Ethiopic Supplement" Unicode character block.
                 */
                static UnicodeBlock ETHIOPIC_SUPPLEMENT;

                /**
                 * Constant for the "Unified Canadian Aboriginal Syllabics Extended"
                 * Unicode character block.
                 */
                static UnicodeBlock UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED;

                /**
                 * Constant for the "New Tai Lue" Unicode character block.
                 */
                static UnicodeBlock NEW_TAI_LUE;

                /**
                 * Constant for the "Buginese" Unicode character block.
                 */
                static UnicodeBlock BUGINESE;

                /**
                 * Constant for the "Tai Tham" Unicode character block.
                 */
                static UnicodeBlock TAI_THAM;

                /**
                 * Constant for the "Balinese" Unicode character block.
                 */
                static UnicodeBlock BALINESE;

                /**
                 * Constant for the "Sundanese" Unicode character block.
                 */
                static UnicodeBlock SUNDANESE;

                /**
                 * Constant for the "Batak" Unicode character block.
                 */
                static UnicodeBlock BATAK;

                /**
                 * Constant for the "Lepcha" Unicode character block.
                 */
                static UnicodeBlock LEPCHA;

                /**
                 * Constant for the "Ol Chiki" Unicode character block.
                 */
                static UnicodeBlock OL_CHIKI;

                /**
                 * Constant for the "Vedic Extensions" Unicode character block.
                 */
                static UnicodeBlock VEDIC_EXTENSIONS;

                /**
                 * Constant for the "Phonetic Extensions Supplement" Unicode character
                 * block.
                 */
                static UnicodeBlock PHONETIC_EXTENSIONS_SUPPLEMENT;

                /**
                 * Constant for the "Combining Diacritical Marks Supplement" Unicode
                 * character block.
                 */
                static UnicodeBlock COMBINING_DIACRITICAL_MARKS_SUPPLEMENT;

                /**
                 * Constant for the "Glagolitic" Unicode character block.
                 */
                static UnicodeBlock GLAGOLITIC;

                /**
                 * Constant for the "Latin Extended-C" Unicode character block.
                 */
                static UnicodeBlock LATIN_EXTENDED_C;

                /**
                 * Constant for the "Coptic" Unicode character block.
                 */
                static UnicodeBlock COPTIC;

                /**
                 * Constant for the "Georgian Supplement" Unicode character block.
                 */
                static UnicodeBlock GEORGIAN_SUPPLEMENT;

                /**
                 * Constant for the "Tifinagh" Unicode character block.
                 */
                static UnicodeBlock TIFINAGH;

                /**
                 * Constant for the "Ethiopic Extended" Unicode character block.
                 */
                static UnicodeBlock ETHIOPIC_EXTENDED;

                /**
                 * Constant for the "Cyrillic Extended-A" Unicode character block.
                 */
                static UnicodeBlock CYRILLIC_EXTENDED_A;

                /**
                 * Constant for the "Supplemental Punctuation" Unicode character block.
                 */
                static UnicodeBlock SUPPLEMENTAL_PUNCTUATION;

                /**
                 * Constant for the "CJK Strokes" Unicode character block.
                 */
                static UnicodeBlock CJK_STROKES;

                /**
                 * Constant for the "Lisu" Unicode character block.
                 */
                static UnicodeBlock LISU;

                /**
                 * Constant for the "Vai" Unicode character block.
                 */
                static UnicodeBlock VAI;

                /**
                 * Constant for the "Cyrillic Extended-B" Unicode character block.
                 */
                static UnicodeBlock CYRILLIC_EXTENDED_B;

                /**
                 * Constant for the "Bamum" Unicode character block.
                 */
                static UnicodeBlock BAMUM;

                /**
                 * Constant for the "Modifier Tone Letters" Unicode character block.
                 */
                static UnicodeBlock MODIFIER_TONE_LETTERS;

                /**
                 * Constant for the "Latin Extended-D" Unicode character block.
                 */
                static UnicodeBlock LATIN_EXTENDED_D;

                /**
                 * Constant for the "Syloti Nagri" Unicode character block.
                 */
                static UnicodeBlock SYLOTI_NAGRI;

                /**
                 * Constant for the "Common Indic Number Forms" Unicode character block.
                 */
                static UnicodeBlock COMMON_INDIC_NUMBER_FORMS;

                /**
                 * Constant for the "Phags-pa" Unicode character block.
                 */
                static UnicodeBlock PHAGS_PA;

                /**
                 * Constant for the "Saurashtra" Unicode character block.
                 */
                static UnicodeBlock SAURASHTRA;

                /**
                 * Constant for the "Devanagari Extended" Unicode character block.
                 */
                static UnicodeBlock DEVANAGARI_EXTENDED;

                /**
                 * Constant for the "Kayah Li" Unicode character block.
                 */
                static UnicodeBlock KAYAH_LI;

                /**
                 * Constant for the "Rejang" Unicode character block.
                 */
                static UnicodeBlock REJANG;

                /**
                 * Constant for the "Hangul Jamo Extended-A" Unicode character block.
                 */
                static UnicodeBlock HANGUL_JAMO_EXTENDED_A;

                /**
                 * Constant for the "Javanese" Unicode character block.
                 */
                static UnicodeBlock JAVANESE;

                /**
                 * Constant for the "Cham" Unicode character block.
                 */
                static UnicodeBlock CHAM;

                /**
                 * Constant for the "Myanmar Extended-A" Unicode character block.
                 */
                static UnicodeBlock MYANMAR_EXTENDED_A;

                /**
                 * Constant for the "Tai Viet" Unicode character block.
                 */
                static UnicodeBlock TAI_VIET;

                /**
                 * Constant for the "Ethiopic Extended-A" Unicode character block.
                 */
                static UnicodeBlock ETHIOPIC_EXTENDED_A;

                /**
                 * Constant for the "Meetei Mayek" Unicode character block.
                 */
                static UnicodeBlock MEETEI_MAYEK;

                /**
                 * Constant for the "Hangul Jamo Extended-B" Unicode character block.
                 */
                static UnicodeBlock HANGUL_JAMO_EXTENDED_B;

                /**
                 * Constant for the "Vertical Forms" Unicode character block.
                 */
                static UnicodeBlock VERTICAL_FORMS;

                /**
                 * Constant for the "Ancient Greek Numbers" Unicode character block.
                 */
                static UnicodeBlock ANCIENT_GREEK_NUMBERS;

                /**
                 * Constant for the "Ancient Symbols" Unicode character block.
                 */
                static UnicodeBlock ANCIENT_SYMBOLS;

                /**
                 * Constant for the "Phaistos Disc" Unicode character block.
                 */
                static UnicodeBlock PHAISTOS_DISC ;

                /**
                 * Constant for the "Lycian" Unicode character block.
                 */
                static UnicodeBlock LYCIAN;

                /**
                 * Constant for the "Carian" Unicode character block.
                 */
                static UnicodeBlock CARIAN;

                /**
                 * Constant for the "Old Persian" Unicode character block.
                 */
                static UnicodeBlock OLD_PERSIAN;

                /**
                 * Constant for the "Imperial Aramaic" Unicode character block.
                 */
                static UnicodeBlock IMPERIAL_ARAMAIC;

                /**
                 * Constant for the "Phoenician" Unicode character block.
                 */
                static UnicodeBlock PHOENICIAN;

                /**
                 * Constant for the "Lydian" Unicode character block.
                 */
                static UnicodeBlock LYDIAN;

                /**
                 * Constant for the "Kharoshthi" Unicode character block.
                 */
                static UnicodeBlock KHAROSHTHI;

                /**
                 * Constant for the "Old South Arabian" Unicode character block.
                 */
                static UnicodeBlock OLD_SOUTH_ARABIAN;

                /**
                 * Constant for the "Avestan" Unicode character block.
                 */
                static UnicodeBlock AVESTAN;

                /**
                 * Constant for the "Inscriptional Parthian" Unicode character block.
                 */
                static UnicodeBlock INSCRIPTIONAL_PARTHIAN;

                /**
                 * Constant for the "Inscriptional Pahlavi" Unicode character block.
                 */
                static UnicodeBlock INSCRIPTIONAL_PAHLAVI;

                /**
                 * Constant for the "Old Turkic" Unicode character block.
                 */
                static UnicodeBlock OLD_TURKIC;

                /**
                 * Constant for the "Rumi Numeral Symbols" Unicode character block.
                 */
                static UnicodeBlock RUMI_NUMERAL_SYMBOLS;

                /**
                 * Constant for the "Brahmi" Unicode character block.
                 */
                static UnicodeBlock BRAHMI;

                /**
                 * Constant for the "Kaithi" Unicode character block.
                 */
                static UnicodeBlock KAITHI;

                /**
                 * Constant for the "Cuneiform" Unicode character block.
                 */
                static UnicodeBlock CUNEIFORM;

                /**
                 * Constant for the "Cuneiform Numbers and Punctuation" Unicode
                 * character block.
                 */
                static UnicodeBlock CUNEIFORM_NUMBERS_AND_PUNCTUATION;

                /**
                 * Constant for the "Egyptian Hieroglyphs" Unicode character block.
                 */
                static UnicodeBlock EGYPTIAN_HIEROGLYPHS;

                /**
                 * Constant for the "Bamum Supplement" Unicode character block.
                 */
                static UnicodeBlock BAMUM_SUPPLEMENT;

                /**
                 * Constant for the "Kana Supplement" Unicode character block.
                 */
                static UnicodeBlock KANA_SUPPLEMENT;

                /**
                 * Constant for the "Ancient Greek Musical Notation" Unicode character
                 * block.
                 */
                static UnicodeBlock ANCIENT_GREEK_MUSICAL_NOTATION;

                /**
                 * Constant for the "Counting Rod Numerals" Unicode character block.
                 */
                static UnicodeBlock COUNTING_ROD_NUMERALS;

                /**
                 * Constant for the "Mahjong Tiles" Unicode character block.
                 */
                static UnicodeBlock MAHJONG_TILES;

                /**
                 * Constant for the "Domino Tiles" Unicode character block.
                 */
                static UnicodeBlock DOMINO_TILES;

                /**
                 * Constant for the "Playing Cards" Unicode character block.
                 */
                static UnicodeBlock PLAYING_CARDS;

                /**
                 * Constant for the "Enclosed Alphanumeric Supplement" Unicode character
                 * block.
                 */
                static UnicodeBlock ENCLOSED_ALPHANUMERIC_SUPPLEMENT;

                /**
                 * Constant for the "Enclosed Ideographic Supplement" Unicode character
                 * block.
                 */
                static UnicodeBlock ENCLOSED_IDEOGRAPHIC_SUPPLEMENT;

                /**
                 * Constant for the "Miscellaneous Symbols And Pictographs" Unicode
                 * character block.
                 */
                static UnicodeBlock MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS;

                /**
                 * Constant for the "Emoticons" Unicode character block.
                 */
                static UnicodeBlock EMOTICONS;

                /**
                 * Constant for the "Transport And Map Symbols" Unicode character block.
                 */
                static UnicodeBlock TRANSPORT_AND_MAP_SYMBOLS;

                /**
                 * Constant for the "Alchemical Symbols" Unicode character block.
                 */
                static UnicodeBlock ALCHEMICAL_SYMBOLS;

                /**
                 * Constant for the "CJK Unified Ideographs Extension C" Unicode
                 * character block.
                 */
                static UnicodeBlock CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C;

                /**
                 * Constant for the "CJK Unified Ideographs Extension D" Unicode
                 * character block.
                 */
                static UnicodeBlock CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D;

                /**
                 * Constant for the "Arabic Extended-A" Unicode character block.
                 */
                static UnicodeBlock ARABIC_EXTENDED_A;

                /**
                 * Constant for the "Sundanese Supplement" Unicode character block.
                 */
                static UnicodeBlock SUNDANESE_SUPPLEMENT;

                /**
                 * Constant for the "Meetei Mayek Extensions" Unicode character block.
                 */
                static UnicodeBlock MEETEI_MAYEK_EXTENSIONS;

                /**
                 * Constant for the "Meroitic Hieroglyphs" Unicode character block.
                 */
                static UnicodeBlock MEROITIC_HIEROGLYPHS;

                /**
                 * Constant for the "Meroitic Cursive" Unicode character block.
                 */
                static UnicodeBlock MEROITIC_CURSIVE;

                /**
                 * Constant for the "Sora Sompeng" Unicode character block.
                 */
                static UnicodeBlock SORA_SOMPENG;

                /**
                 * Constant for the "Chakma" Unicode character block.
                 */
                static UnicodeBlock CHAKMA;

                /**
                 * Constant for the "Sharada" Unicode character block.
                 */
                static UnicodeBlock SHARADA;

                /**
                 * Constant for the "Takri" Unicode character block.
                 */
                static UnicodeBlock TAKRI;

                /**
                 * Constant for the "Miao" Unicode character block.
                 */
                static UnicodeBlock MIAO;

                /**
                 * Constant for the "Arabic Mathematical Alphabetic Symbols" Unicode
                 * character block.
                 */
                static UnicodeBlock ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS;
//
//            private:
//                static int blockStarts[] = {
//                        0x0000,   // 0000..007F; Basic Latin
//                        0x0080,   // 0080..00FF; Latin-1 Supplement
//                        0x0100,   // 0100..017F; Latin Extended-A
//                        0x0180,   // 0180..024F; Latin Extended-B
//                        0x0250,   // 0250..02AF; IPA Extensions
//                        0x02B0,   // 02B0..02FF; Spacing Modifier Letters
//                        0x0300,   // 0300..036F; Combining Diacritical Marks
//                        0x0370,   // 0370..03FF; Greek and Coptic
//                        0x0400,   // 0400..04FF; Cyrillic
//                        0x0500,   // 0500..052F; Cyrillic Supplement
//                        0x0530,   // 0530..058F; Armenian
//                        0x0590,   // 0590..05FF; Hebrew
//                        0x0600,   // 0600..06FF; Arabic
//                        0x0700,   // 0700..074F; Syriac
//                        0x0750,   // 0750..077F; Arabic Supplement
//                        0x0780,   // 0780..07BF; Thaana
//                        0x07C0,   // 07C0..07FF; NKo
//                        0x0800,   // 0800..083F; Samaritan
//                        0x0840,   // 0840..085F; Mandaic
//                        0x0860,   //             unassigned
//                        0x08A0,   // 08A0..08FF; Arabic Extended-A
//                        0x0900,   // 0900..097F; Devanagari
//                        0x0980,   // 0980..09FF; Bengali
//                        0x0A00,   // 0A00..0A7F; Gurmukhi
//                        0x0A80,   // 0A80..0AFF; Gujarati
//                        0x0B00,   // 0B00..0B7F; Oriya
//                        0x0B80,   // 0B80..0BFF; Tamil
//                        0x0C00,   // 0C00..0C7F; Telugu
//                        0x0C80,   // 0C80..0CFF; Kannada
//                        0x0D00,   // 0D00..0D7F; Malayalam
//                        0x0D80,   // 0D80..0DFF; Sinhala
//                        0x0E00,   // 0E00..0E7F; Thai
//                        0x0E80,   // 0E80..0EFF; Lao
//                        0x0F00,   // 0F00..0FFF; Tibetan
//                        0x1000,   // 1000..109F; Myanmar
//                        0x10A0,   // 10A0..10FF; Georgian
//                        0x1100,   // 1100..11FF; Hangul Jamo
//                        0x1200,   // 1200..137F; Ethiopic
//                        0x1380,   // 1380..139F; Ethiopic Supplement
//                        0x13A0,   // 13A0..13FF; Cherokee
//                        0x1400,   // 1400..167F; Unified Canadian Aboriginal Syllabics
//                        0x1680,   // 1680..169F; Ogham
//                        0x16A0,   // 16A0..16FF; Runic
//                        0x1700,   // 1700..171F; Tagalog
//                        0x1720,   // 1720..173F; Hanunoo
//                        0x1740,   // 1740..175F; Buhid
//                        0x1760,   // 1760..177F; Tagbanwa
//                        0x1780,   // 1780..17FF; Khmer
//                        0x1800,   // 1800..18AF; Mongolian
//                        0x18B0,   // 18B0..18FF; Unified Canadian Aboriginal Syllabics Extended
//                        0x1900,   // 1900..194F; Limbu
//                        0x1950,   // 1950..197F; Tai Le
//                        0x1980,   // 1980..19DF; New Tai Lue
//                        0x19E0,   // 19E0..19FF; Khmer Symbols
//                        0x1A00,   // 1A00..1A1F; Buginese
//                        0x1A20,   // 1A20..1AAF; Tai Tham
//                        0x1AB0,   //             unassigned
//                        0x1B00,   // 1B00..1B7F; Balinese
//                        0x1B80,   // 1B80..1BBF; Sundanese
//                        0x1BC0,   // 1BC0..1BFF; Batak
//                        0x1C00,   // 1C00..1C4F; Lepcha
//                        0x1C50,   // 1C50..1C7F; Ol Chiki
//                        0x1C80,   //             unassigned
//                        0x1CC0,   // 1CC0..1CCF; Sundanese Supplement
//                        0x1CD0,   // 1CD0..1CFF; Vedic Extensions
//                        0x1D00,   // 1D00..1D7F; Phonetic Extensions
//                        0x1D80,   // 1D80..1DBF; Phonetic Extensions Supplement
//                        0x1DC0,   // 1DC0..1DFF; Combining Diacritical Marks Supplement
//                        0x1E00,   // 1E00..1EFF; Latin Extended Additional
//                        0x1F00,   // 1F00..1FFF; Greek Extended
//                        0x2000,   // 2000..206F; General Punctuation
//                        0x2070,   // 2070..209F; Superscripts and Subscripts
//                        0x20A0,   // 20A0..20CF; Currency Symbols
//                        0x20D0,   // 20D0..20FF; Combining Diacritical Marks for Symbols
//                        0x2100,   // 2100..214F; Letterlike Symbols
//                        0x2150,   // 2150..218F; Number Forms
//                        0x2190,   // 2190..21FF; Arrows
//                        0x2200,   // 2200..22FF; Mathematical Operators
//                        0x2300,   // 2300..23FF; Miscellaneous Technical
//                        0x2400,   // 2400..243F; Control Pictures
//                        0x2440,   // 2440..245F; Optical Character Recognition
//                        0x2460,   // 2460..24FF; Enclosed Alphanumerics
//                        0x2500,   // 2500..257F; Box Drawing
//                        0x2580,   // 2580..259F; Block Elements
//                        0x25A0,   // 25A0..25FF; Geometric Shapes
//                        0x2600,   // 2600..26FF; Miscellaneous Symbols
//                        0x2700,   // 2700..27BF; Dingbats
//                        0x27C0,   // 27C0..27EF; Miscellaneous Mathematical Symbols-A
//                        0x27F0,   // 27F0..27FF; Supplemental Arrows-A
//                        0x2800,   // 2800..28FF; Braille Patterns
//                        0x2900,   // 2900..297F; Supplemental Arrows-B
//                        0x2980,   // 2980..29FF; Miscellaneous Mathematical Symbols-B
//                        0x2A00,   // 2A00..2AFF; Supplemental Mathematical Operators
//                        0x2B00,   // 2B00..2BFF; Miscellaneous Symbols and Arrows
//                        0x2C00,   // 2C00..2C5F; Glagolitic
//                        0x2C60,   // 2C60..2C7F; Latin Extended-C
//                        0x2C80,   // 2C80..2CFF; Coptic
//                        0x2D00,   // 2D00..2D2F; Georgian Supplement
//                        0x2D30,   // 2D30..2D7F; Tifinagh
//                        0x2D80,   // 2D80..2DDF; Ethiopic Extended
//                        0x2DE0,   // 2DE0..2DFF; Cyrillic Extended-A
//                        0x2E00,   // 2E00..2E7F; Supplemental Punctuation
//                        0x2E80,   // 2E80..2EFF; CJK Radicals Supplement
//                        0x2F00,   // 2F00..2FDF; Kangxi Radicals
//                        0x2FE0,   //             unassigned
//                        0x2FF0,   // 2FF0..2FFF; Ideographic Description Characters
//                        0x3000,   // 3000..303F; CJK Symbols and Punctuation
//                        0x3040,   // 3040..309F; Hiragana
//                        0x30A0,   // 30A0..30FF; Katakana
//                        0x3100,   // 3100..312F; Bopomofo
//                        0x3130,   // 3130..318F; Hangul Compatibility Jamo
//                        0x3190,   // 3190..319F; Kanbun
//                        0x31A0,   // 31A0..31BF; Bopomofo Extended
//                        0x31C0,   // 31C0..31EF; CJK Strokes
//                        0x31F0,   // 31F0..31FF; Katakana Phonetic Extensions
//                        0x3200,   // 3200..32FF; Enclosed CJK Letters and Months
//                        0x3300,   // 3300..33FF; CJK Compatibility
//                        0x3400,   // 3400..4DBF; CJK Unified Ideographs Extension A
//                        0x4DC0,   // 4DC0..4DFF; Yijing Hexagram Symbols
//                        0x4E00,   // 4E00..9FFF; CJK Unified Ideographs
//                        0xA000,   // A000..A48F; Yi Syllables
//                        0xA490,   // A490..A4CF; Yi Radicals
//                        0xA4D0,   // A4D0..A4FF; Lisu
//                        0xA500,   // A500..A63F; Vai
//                        0xA640,   // A640..A69F; Cyrillic Extended-B
//                        0xA6A0,   // A6A0..A6FF; Bamum
//                        0xA700,   // A700..A71F; Modifier Tone Letters
//                        0xA720,   // A720..A7FF; Latin Extended-D
//                        0xA800,   // A800..A82F; Syloti Nagri
//                        0xA830,   // A830..A83F; Common Indic Number Forms
//                        0xA840,   // A840..A87F; Phags-pa
//                        0xA880,   // A880..A8DF; Saurashtra
//                        0xA8E0,   // A8E0..A8FF; Devanagari Extended
//                        0xA900,   // A900..A92F; Kayah Li
//                        0xA930,   // A930..A95F; Rejang
//                        0xA960,   // A960..A97F; Hangul Jamo Extended-A
//                        0xA980,   // A980..A9DF; Javanese
//                        0xA9E0,   //             unassigned
//                        0xAA00,   // AA00..AA5F; Cham
//                        0xAA60,   // AA60..AA7F; Myanmar Extended-A
//                        0xAA80,   // AA80..AADF; Tai Viet
//                        0xAAE0,   // AAE0..AAFF; Meetei Mayek Extensions
//                        0xAB00,   // AB00..AB2F; Ethiopic Extended-A
//                        0xAB30,   //             unassigned
//                        0xABC0,   // ABC0..ABFF; Meetei Mayek
//                        0xAC00,   // AC00..D7AF; Hangul Syllables
//                        0xD7B0,   // D7B0..D7FF; Hangul Jamo Extended-B
//                        0xD800,   // D800..DB7F; High Surrogates
//                        0xDB80,   // DB80..DBFF; High Private Use Surrogates
//                        0xDC00,   // DC00..DFFF; Low Surrogates
//                        0xE000,   // E000..F8FF; Private Use Area
//                        0xF900,   // F900..FAFF; CJK Compatibility Ideographs
//                        0xFB00,   // FB00..FB4F; Alphabetic Presentation Forms
//                        0xFB50,   // FB50..FDFF; Arabic Presentation Forms-A
//                        0xFE00,   // FE00..FE0F; Variation Selectors
//                        0xFE10,   // FE10..FE1F; Vertical Forms
//                        0xFE20,   // FE20..FE2F; Combining Half Marks
//                        0xFE30,   // FE30..FE4F; CJK Compatibility Forms
//                        0xFE50,   // FE50..FE6F; Small Form Variants
//                        0xFE70,   // FE70..FEFF; Arabic Presentation Forms-B
//                        0xFF00,   // FF00..FFEF; Halfwidth and Fullwidth Forms
//                        0xFFF0,   // FFF0..FFFF; Specials
//                        0x10000,  // 10000..1007F; Linear B Syllabary
//                        0x10080,  // 10080..100FF; Linear B Ideograms
//                        0x10100,  // 10100..1013F; Aegean Numbers
//                        0x10140,  // 10140..1018F; Ancient Greek Numbers
//                        0x10190,  // 10190..101CF; Ancient Symbols
//                        0x101D0,  // 101D0..101FF; Phaistos Disc
//                        0x10200,  //               unassigned
//                        0x10280,  // 10280..1029F; Lycian
//                        0x102A0,  // 102A0..102DF; Carian
//                        0x102E0,  //               unassigned
//                        0x10300,  // 10300..1032F; Old Italic
//                        0x10330,  // 10330..1034F; Gothic
//                        0x10350,  //               unassigned
//                        0x10380,  // 10380..1039F; Ugaritic
//                        0x103A0,  // 103A0..103DF; Old Persian
//                        0x103E0,  //               unassigned
//                        0x10400,  // 10400..1044F; Deseret
//                        0x10450,  // 10450..1047F; Shavian
//                        0x10480,  // 10480..104AF; Osmanya
//                        0x104B0,  //               unassigned
//                        0x10800,  // 10800..1083F; Cypriot Syllabary
//                        0x10840,  // 10840..1085F; Imperial Aramaic
//                        0x10860,  //               unassigned
//                        0x10900,  // 10900..1091F; Phoenician
//                        0x10920,  // 10920..1093F; Lydian
//                        0x10940,  //               unassigned
//                        0x10980,  // 10980..1099F; Meroitic Hieroglyphs
//                        0x109A0,  // 109A0..109FF; Meroitic Cursive
//                        0x10A00,  // 10A00..10A5F; Kharoshthi
//                        0x10A60,  // 10A60..10A7F; Old South Arabian
//                        0x10A80,  //               unassigned
//                        0x10B00,  // 10B00..10B3F; Avestan
//                        0x10B40,  // 10B40..10B5F; Inscriptional Parthian
//                        0x10B60,  // 10B60..10B7F; Inscriptional Pahlavi
//                        0x10B80,  //               unassigned
//                        0x10C00,  // 10C00..10C4F; Old Turkic
//                        0x10C50,  //               unassigned
//                        0x10E60,  // 10E60..10E7F; Rumi Numeral Symbols
//                        0x10E80,  //               unassigned
//                        0x11000,  // 11000..1107F; Brahmi
//                        0x11080,  // 11080..110CF; Kaithi
//                        0x110D0,  // 110D0..110FF; Sora Sompeng
//                        0x11100,  // 11100..1114F; Chakma
//                        0x11150,  //               unassigned
//                        0x11180,  // 11180..111DF; Sharada
//                        0x111E0,  //               unassigned
//                        0x11680,  // 11680..116CF; Takri
//                        0x116D0,  //               unassigned
//                        0x12000,  // 12000..123FF; Cuneiform
//                        0x12400,  // 12400..1247F; Cuneiform Numbers and Punctuation
//                        0x12480,  //               unassigned
//                        0x13000,  // 13000..1342F; Egyptian Hieroglyphs
//                        0x13430,  //               unassigned
//                        0x16800,  // 16800..16A3F; Bamum Supplement
//                        0x16A40,  //               unassigned
//                        0x16F00,  // 16F00..16F9F; Miao
//                        0x16FA0,  //               unassigned
//                        0x1B000,  // 1B000..1B0FF; Kana Supplement
//                        0x1B100,  //               unassigned
//                        0x1D000,  // 1D000..1D0FF; Byzantine Musical Symbols
//                        0x1D100,  // 1D100..1D1FF; Musical Symbols
//                        0x1D200,  // 1D200..1D24F; Ancient Greek Musical Notation
//                        0x1D250,  //               unassigned
//                        0x1D300,  // 1D300..1D35F; Tai Xuan Jing Symbols
//                        0x1D360,  // 1D360..1D37F; Counting Rod Numerals
//                        0x1D380,  //               unassigned
//                        0x1D400,  // 1D400..1D7FF; Mathematical Alphanumeric Symbols
//                        0x1D800,  //               unassigned
//                        0x1EE00,  // 1EE00..1EEFF; Arabic Mathematical Alphabetic Symbols
//                        0x1EF00,  //               unassigned
//                        0x1F000,  // 1F000..1F02F; Mahjong Tiles
//                        0x1F030,  // 1F030..1F09F; Domino Tiles
//                        0x1F0A0,  // 1F0A0..1F0FF; Playing Cards
//                        0x1F100,  // 1F100..1F1FF; Enclosed Alphanumeric Supplement
//                        0x1F200,  // 1F200..1F2FF; Enclosed Ideographic Supplement
//                        0x1F300,  // 1F300..1F5FF; Miscellaneous Symbols And Pictographs
//                        0x1F600,  // 1F600..1F64F; Emoticons
//                        0x1F650,  //               unassigned
//                        0x1F680,  // 1F680..1F6FF; Transport And Map Symbols
//                        0x1F700,  // 1F700..1F77F; Alchemical Symbols
//                        0x1F780,  //               unassigned
//                        0x20000,  // 20000..2A6DF; CJK Unified Ideographs Extension B
//                        0x2A6E0,  //               unassigned
//                        0x2A700,  // 2A700..2B73F; CJK Unified Ideographs Extension C
//                        0x2B740,  // 2B740..2B81F; CJK Unified Ideographs Extension D
//                        0x2B820,  //               unassigned
//                        0x2F800,  // 2F800..2FA1F; CJK Compatibility Ideographs Supplement
//                        0x2FA20,  //               unassigned
//                        0xE0000,  // E0000..E007F; Tags
//                        0xE0080,  //               unassigned
//                        0xE0100,  // E0100..E01EF; Variation Selectors Supplement
//                        0xE01F0,  //               unassigned
//                        0xF0000,  // F0000..FFFFF; Supplementary Private Use Area-A
//                        0x100000  // 100000..10FFFF; Supplementary Private Use Area-B
//                };
//
//                private static UnicodeBlock[] blocks = {
//                        BASIC_LATIN,
//                        LATIN_1_SUPPLEMENT,
//                        LATIN_EXTENDED_A,
//                        LATIN_EXTENDED_B,
//                        IPA_EXTENSIONS,
//                        SPACING_MODIFIER_LETTERS,
//                        COMBINING_DIACRITICAL_MARKS,
//                        GREEK,
//                        CYRILLIC,
//                        CYRILLIC_SUPPLEMENTARY,
//                        ARMENIAN,
//                        HEBREW,
//                        ARABIC,
//                        SYRIAC,
//                        ARABIC_SUPPLEMENT,
//                        THAANA,
//                        NKO,
//                        SAMARITAN,
//                        MANDAIC,
//                        null,
//                        ARABIC_EXTENDED_A,
//                        DEVANAGARI,
//                        BENGALI,
//                        GURMUKHI,
//                        GUJARATI,
//                        ORIYA,
//                        TAMIL,
//                        TELUGU,
//                        KANNADA,
//                        MALAYALAM,
//                        SINHALA,
//                        THAI,
//                        LAO,
//                        TIBETAN,
//                        MYANMAR,
//                        GEORGIAN,
//                        HANGUL_JAMO,
//                        ETHIOPIC,
//                        ETHIOPIC_SUPPLEMENT,
//                        CHEROKEE,
//                        UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS,
//                        OGHAM,
//                        RUNIC,
//                        TAGALOG,
//                        HANUNOO,
//                        BUHID,
//                        TAGBANWA,
//                        KHMER,
//                        MONGOLIAN,
//                        UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED,
//                        LIMBU,
//                        TAI_LE,
//                        NEW_TAI_LUE,
//                        KHMER_SYMBOLS,
//                        BUGINESE,
//                        TAI_THAM,
//                        null,
//                        BALINESE,
//                        SUNDANESE,
//                        BATAK,
//                        LEPCHA,
//                        OL_CHIKI,
//                        null,
//                        SUNDANESE_SUPPLEMENT,
//                        VEDIC_EXTENSIONS,
//                        PHONETIC_EXTENSIONS,
//                        PHONETIC_EXTENSIONS_SUPPLEMENT,
//                        COMBINING_DIACRITICAL_MARKS_SUPPLEMENT,
//                        LATIN_EXTENDED_ADDITIONAL,
//                        GREEK_EXTENDED,
//                        GENERAL_PUNCTUATION,
//                        SUPERSCRIPTS_AND_SUBSCRIPTS,
//                        CURRENCY_SYMBOLS,
//                        COMBINING_MARKS_FOR_SYMBOLS,
//                        LETTERLIKE_SYMBOLS,
//                        NUMBER_FORMS,
//                        ARROWS,
//                        MATHEMATICAL_OPERATORS,
//                        MISCELLANEOUS_TECHNICAL,
//                        CONTROL_PICTURES,
//                        OPTICAL_CHARACTER_RECOGNITION,
//                        ENCLOSED_ALPHANUMERICS,
//                        BOX_DRAWING,
//                        BLOCK_ELEMENTS,
//                        GEOMETRIC_SHAPES,
//                        MISCELLANEOUS_SYMBOLS,
//                        DINGBATS,
//                        MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A,
//                        SUPPLEMENTAL_ARROWS_A,
//                        BRAILLE_PATTERNS,
//                        SUPPLEMENTAL_ARROWS_B,
//                        MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B,
//                        SUPPLEMENTAL_MATHEMATICAL_OPERATORS,
//                        MISCELLANEOUS_SYMBOLS_AND_ARROWS,
//                        GLAGOLITIC,
//                        LATIN_EXTENDED_C,
//                        COPTIC,
//                        GEORGIAN_SUPPLEMENT,
//                        TIFINAGH,
//                        ETHIOPIC_EXTENDED,
//                        CYRILLIC_EXTENDED_A,
//                        SUPPLEMENTAL_PUNCTUATION,
//                        CJK_RADICALS_SUPPLEMENT,
//                        KANGXI_RADICALS,
//                        null,
//                        IDEOGRAPHIC_DESCRIPTION_CHARACTERS,
//                        CJK_SYMBOLS_AND_PUNCTUATION,
//                        HIRAGANA,
//                        KATAKANA,
//                        BOPOMOFO,
//                        HANGUL_COMPATIBILITY_JAMO,
//                        KANBUN,
//                        BOPOMOFO_EXTENDED,
//                        CJK_STROKES,
//                        KATAKANA_PHONETIC_EXTENSIONS,
//                        ENCLOSED_CJK_LETTERS_AND_MONTHS,
//                        CJK_COMPATIBILITY,
//                        CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A,
//                        YIJING_HEXAGRAM_SYMBOLS,
//                        CJK_UNIFIED_IDEOGRAPHS,
//                        YI_SYLLABLES,
//                        YI_RADICALS,
//                        LISU,
//                        VAI,
//                        CYRILLIC_EXTENDED_B,
//                        BAMUM,
//                        MODIFIER_TONE_LETTERS,
//                        LATIN_EXTENDED_D,
//                        SYLOTI_NAGRI,
//                        COMMON_INDIC_NUMBER_FORMS,
//                        PHAGS_PA,
//                        SAURASHTRA,
//                        DEVANAGARI_EXTENDED,
//                        KAYAH_LI,
//                        REJANG,
//                        HANGUL_JAMO_EXTENDED_A,
//                        JAVANESE,
//                        null,
//                        CHAM,
//                        MYANMAR_EXTENDED_A,
//                        TAI_VIET,
//                        MEETEI_MAYEK_EXTENSIONS,
//                        ETHIOPIC_EXTENDED_A,
//                        null,
//                        MEETEI_MAYEK,
//                        HANGUL_SYLLABLES,
//                        HANGUL_JAMO_EXTENDED_B,
//                        HIGH_SURROGATES,
//                        HIGH_PRIVATE_USE_SURROGATES,
//                        LOW_SURROGATES,
//                        PRIVATE_USE_AREA,
//                        CJK_COMPATIBILITY_IDEOGRAPHS,
//                        ALPHABETIC_PRESENTATION_FORMS,
//                        ARABIC_PRESENTATION_FORMS_A,
//                        VARIATION_SELECTORS,
//                        VERTICAL_FORMS,
//                        COMBINING_HALF_MARKS,
//                        CJK_COMPATIBILITY_FORMS,
//                        SMALL_FORM_VARIANTS,
//                        ARABIC_PRESENTATION_FORMS_B,
//                        HALFWIDTH_AND_FULLWIDTH_FORMS,
//                        SPECIALS,
//                        LINEAR_B_SYLLABARY,
//                        LINEAR_B_IDEOGRAMS,
//                        AEGEAN_NUMBERS,
//                        ANCIENT_GREEK_NUMBERS,
//                        ANCIENT_SYMBOLS,
//                        PHAISTOS_DISC,
//                        null,
//                        LYCIAN,
//                        CARIAN,
//                        null,
//                        OLD_ITALIC,
//                        GOTHIC,
//                        null,
//                        UGARITIC,
//                        OLD_PERSIAN,
//                        null,
//                        DESERET,
//                        SHAVIAN,
//                        OSMANYA,
//                        null,
//                        CYPRIOT_SYLLABARY,
//                        IMPERIAL_ARAMAIC,
//                        null,
//                        PHOENICIAN,
//                        LYDIAN,
//                        null,
//                        MEROITIC_HIEROGLYPHS,
//                        MEROITIC_CURSIVE,
//                        KHAROSHTHI,
//                        OLD_SOUTH_ARABIAN,
//                        null,
//                        AVESTAN,
//                        INSCRIPTIONAL_PARTHIAN,
//                        INSCRIPTIONAL_PAHLAVI,
//                        null,
//                        OLD_TURKIC,
//                        null,
//                        RUMI_NUMERAL_SYMBOLS,
//                        null,
//                        BRAHMI,
//                        KAITHI,
//                        SORA_SOMPENG,
//                        CHAKMA,
//                        null,
//                        SHARADA,
//                        null,
//                        TAKRI,
//                        null,
//                        CUNEIFORM,
//                        CUNEIFORM_NUMBERS_AND_PUNCTUATION,
//                        null,
//                        EGYPTIAN_HIEROGLYPHS,
//                        null,
//                        BAMUM_SUPPLEMENT,
//                        null,
//                        MIAO,
//                        null,
//                        KANA_SUPPLEMENT,
//                        null,
//                        BYZANTINE_MUSICAL_SYMBOLS,
//                        MUSICAL_SYMBOLS,
//                        ANCIENT_GREEK_MUSICAL_NOTATION,
//                        null,
//                        TAI_XUAN_JING_SYMBOLS,
//                        COUNTING_ROD_NUMERALS,
//                        null,
//                        MATHEMATICAL_ALPHANUMERIC_SYMBOLS,
//                        null,
//                        ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS,
//                        null,
//                        MAHJONG_TILES,
//                        DOMINO_TILES,
//                        PLAYING_CARDS,
//                        ENCLOSED_ALPHANUMERIC_SUPPLEMENT,
//                        ENCLOSED_IDEOGRAPHIC_SUPPLEMENT,
//                        MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS,
//                        EMOTICONS,
//                        null,
//                        TRANSPORT_AND_MAP_SYMBOLS,
//                        ALCHEMICAL_SYMBOLS,
//                        null,
//                        CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B,
//                        null,
//                        CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C,
//                        CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D,
//                        null,
//                        CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT,
//                        null,
//                        TAGS,
//                        null,
//                        VARIATION_SELECTORS_SUPPLEMENT,
//                        null,
//                        SUPPLEMENTARY_PRIVATE_USE_AREA_A,
//                        SUPPLEMENTARY_PRIVATE_USE_AREA_B
//                };
//
//
//                /**
//                 * Returns the object representing the Unicode block containing the
//                 * given character, or {@code null} if the character is not a
//                 * member of a defined block.
//                 *
//                 * <p><b>Note:</b> This method cannot handle
//                 * <a href="Character.html#supplementary"> supplementary
//                 * characters</a>.  To support all Unicode characters, including
//                 * supplementary characters, use the {@link #of(int)} method.
//                 *
//                 * @param   c  The character in question
//                 * @return  The {@code UnicodeBlock} instance representing the
//                 *          Unicode block of which this character is a member, or
//                 *          {@code null} if the character is not a member of any
//                 *          Unicode block
//                 */
//                static UnicodeBlock of(char c) {
//                    return of((int)c);
//                }
//
//                /**
//                 * Returns the object representing the Unicode block
//                 * containing the given character (Unicode code point), or
//                 * {@code null} if the character is not a member of a
//                 * defined block.
//                 *
//                 * @param   codePoint the character (Unicode code point) in question.
//                 * @return  The {@code UnicodeBlock} instance representing the
//                 *          Unicode block of which this character is a member, or
//                 *          {@code null} if the character is not a member of any
//                 *          Unicode block
//                 * @exception IllegalArgumentException if the specified
//                 * {@code codePoint} is an invalid Unicode code point.
//                 * @see Character#isValidCodePoint(int)
//                 * @since   1.5
//                 */
//                static UnicodeBlock of(int codePoint) {
//                    if (!isValidCodePoint(codePoint)) {
//                        throw  IllegalArgumentException();
//                    }
//
//                    int top, bottom, current;
//                    bottom = 0;
//                    top = blockStarts.length;
//                    current = top/2;
//
//                    // invariant: top > current >= bottom && codePoint >= unicodeBlockStarts[bottom]
//                    while (top - bottom > 1) {
//                        if (codePoint >= blockStarts[current]) {
//                            bottom = current;
//                        } else {
//                            top = current;
//                        }
//                        current = (top + bottom) / 2;
//                    }
//                    return blocks[current];
//                }
//
//                /**
//                 * Returns the UnicodeBlock with the given name. Block
//                 * names are determined by The Unicode Standard. The file
//                 * Blocks-&lt;version&gt;.txt defines blocks for a particular
//                 * version of the standard. The {@link Character} class specifies
//                 * the version of the standard that it supports.
//                 * <p>
//                 * This method accepts block names in the following forms:
//                 * <ol>
//                 * <li> Canonical block names as defined by the Unicode Standard.
//                 * For example, the standard defines a "Basic Latin" block. Therefore, this
//                 * method accepts "Basic Latin" as a valid block name. The documentation of
//                 * each UnicodeBlock provides the canonical name.
//                 * <li>Canonical block names with all spaces removed. For example, "BasicLatin"
//                 * is a valid block name for the "Basic Latin" block.
//                 * <li>The text representation of each constant UnicodeBlock identifier.
//                 * For example, this method will return the {@link #BASIC_LATIN} block if
//                 * provided with the "BASIC_LATIN" name. This form replaces all spaces and
//                 * hyphens in the canonical name with underscores.
//                 * </ol>
//                 * Finally, character case is ignored for all of the valid block name forms.
//                 * For example, "BASIC_LATIN" and "basic_latin" are both valid block names.
//                 * The en_US locale's case mapping rules are used to provide case-insensitive
//                 * string comparisons for block name validation.
//                 * <p>
//                 * If the Unicode Standard changes block names, both the previous and
//                 * current names will be accepted.
//                 *
//                 * @param blockName A {@code UnicodeBlock} name.
//                 * @return The {@code UnicodeBlock} instance identified
//                 *         by {@code blockName}
//                 * @throws IllegalArgumentException if {@code blockName} is an
//                 *         invalid name
//                 * @throws NullPointerException if {@code blockName} is null
//                 * @since 1.5
//                 */
//                static UnicodeBlock forName(String blockName) {
//                    UnicodeBlock block = map.get(blockName.toUpperCase(Locale.US));
//                    if (block == null) {
//                        throw  IllegalArgumentException();
//                    }
//                    return block;
//                }
//            }
//
//
//            /**
//             * A family of character subsets representing the character scripts
//             * defined in the <a href="http://www.unicode.org/reports/tr24/">
//             * <i>Unicode Standard Annex #24: Script Names</i></a>. Every Unicode
//             * character is assigned to a single Unicode script, either a specific
//             * script, such as {@link Character.UnicodeScript#LATIN Latin}, or
//             * one of the following three special values,
//             * {@link Character.UnicodeScript#INHERITED Inherited},
//             * {@link Character.UnicodeScript#COMMON Common} or
//             * {@link Character.UnicodeScript#UNKNOWN Unknown}.
//             *
//             * @since 1.7
//             */
//        static enum UnicodeScript {
//                /**
//                 * Unicode script "Common".
//                 */
//                        COMMON,
//
//                /**
//                 * Unicode script "Latin".
//                 */
//                        LATIN,
//
//                /**
//                 * Unicode script "Greek".
//                 */
//                        GREEK,
//
//                /**
//                 * Unicode script "Cyrillic".
//                 */
//                        CYRILLIC,
//
//                /**
//                 * Unicode script "Armenian".
//                 */
//                        ARMENIAN,
//
//                /**
//                 * Unicode script "Hebrew".
//                 */
//                        HEBREW,
//
//                /**
//                 * Unicode script "Arabic".
//                 */
//                        ARABIC,
//
//                /**
//                 * Unicode script "Syriac".
//                 */
//                        SYRIAC,
//
//                /**
//                 * Unicode script "Thaana".
//                 */
//                        THAANA,
//
//                /**
//                 * Unicode script "Devanagari".
//                 */
//                        DEVANAGARI,
//
//                /**
//                 * Unicode script "Bengali".
//                 */
//                        BENGALI,
//
//                /**
//                 * Unicode script "Gurmukhi".
//                 */
//                        GURMUKHI,
//
//                /**
//                 * Unicode script "Gujarati".
//                 */
//                        GUJARATI,
//
//                /**
//                 * Unicode script "Oriya".
//                 */
//                        ORIYA,
//
//                /**
//                 * Unicode script "Tamil".
//                 */
//                        TAMIL,
//
//                /**
//                 * Unicode script "Telugu".
//                 */
//                        TELUGU,
//
//                /**
//                 * Unicode script "Kannada".
//                 */
//                        KANNADA,
//
//                /**
//                 * Unicode script "Malayalam".
//                 */
//                        MALAYALAM,
//
//                /**
//                 * Unicode script "Sinhala".
//                 */
//                        SINHALA,
//
//                /**
//                 * Unicode script "Thai".
//                 */
//                        THAI,
//
//                /**
//                 * Unicode script "Lao".
//                 */
//                        LAO,
//
//                /**
//                 * Unicode script "Tibetan".
//                 */
//                        TIBETAN,
//
//                /**
//                 * Unicode script "Myanmar".
//                 */
//                        MYANMAR,
//
//                /**
//                 * Unicode script "Georgian".
//                 */
//                        GEORGIAN,
//
//                /**
//                 * Unicode script "Hangul".
//                 */
//                        HANGUL,
//
//                /**
//                 * Unicode script "Ethiopic".
//                 */
//                        ETHIOPIC,
//
//                /**
//                 * Unicode script "Cherokee".
//                 */
//                        CHEROKEE,
//
//                /**
//                 * Unicode script "Canadian_Aboriginal".
//                 */
//                        CANADIAN_ABORIGINAL,
//
//                /**
//                 * Unicode script "Ogham".
//                 */
//                        OGHAM,
//
//                /**
//                 * Unicode script "Runic".
//                 */
//                        RUNIC,
//
//                /**
//                 * Unicode script "Khmer".
//                 */
//                        KHMER,
//
//                /**
//                 * Unicode script "Mongolian".
//                 */
//                        MONGOLIAN,
//
//                /**
//                 * Unicode script "Hiragana".
//                 */
//                        HIRAGANA,
//
//                /**
//                 * Unicode script "Katakana".
//                 */
//                        KATAKANA,
//
//                /**
//                 * Unicode script "Bopomofo".
//                 */
//                        BOPOMOFO,
//
//                /**
//                 * Unicode script "Han".
//                 */
//                        HAN,
//
//                /**
//                 * Unicode script "Yi".
//                 */
//                        YI,
//
//                /**
//                 * Unicode script "Old_Italic".
//                 */
//                        OLD_ITALIC,
//
//                /**
//                 * Unicode script "Gothic".
//                 */
//                        GOTHIC,
//
//                /**
//                 * Unicode script "Deseret".
//                 */
//                        DESERET,
//
//                /**
//                 * Unicode script "Inherited".
//                 */
//                        INHERITED,
//
//                /**
//                 * Unicode script "Tagalog".
//                 */
//                        TAGALOG,
//
//                /**
//                 * Unicode script "Hanunoo".
//                 */
//                        HANUNOO,
//
//                /**
//                 * Unicode script "Buhid".
//                 */
//                        BUHID,
//
//                /**
//                 * Unicode script "Tagbanwa".
//                 */
//                        TAGBANWA,
//
//                /**
//                 * Unicode script "Limbu".
//                 */
//                        LIMBU,
//
//                /**
//                 * Unicode script "Tai_Le".
//                 */
//                        TAI_LE,
//
//                /**
//                 * Unicode script "Linear_B".
//                 */
//                        LINEAR_B,
//
//                /**
//                 * Unicode script "Ugaritic".
//                 */
//                        UGARITIC,
//
//                /**
//                 * Unicode script "Shavian".
//                 */
//                        SHAVIAN,
//
//                /**
//                 * Unicode script "Osmanya".
//                 */
//                        OSMANYA,
//
//                /**
//                 * Unicode script "Cypriot".
//                 */
//                        CYPRIOT,
//
//                /**
//                 * Unicode script "Braille".
//                 */
//                        BRAILLE,
//
//                /**
//                 * Unicode script "Buginese".
//                 */
//                        BUGINESE,
//
//                /**
//                 * Unicode script "Coptic".
//                 */
//                        COPTIC,
//
//                /**
//                 * Unicode script "New_Tai_Lue".
//                 */
//                        NEW_TAI_LUE,
//
//                /**
//                 * Unicode script "Glagolitic".
//                 */
//                        GLAGOLITIC,
//
//                /**
//                 * Unicode script "Tifinagh".
//                 */
//                        TIFINAGH,
//
//                /**
//                 * Unicode script "Syloti_Nagri".
//                 */
//                        SYLOTI_NAGRI,
//
//                /**
//                 * Unicode script "Old_Persian".
//                 */
//                        OLD_PERSIAN,
//
//                /**
//                 * Unicode script "Kharoshthi".
//                 */
//                        KHAROSHTHI,
//
//                /**
//                 * Unicode script "Balinese".
//                 */
//                        BALINESE,
//
//                /**
//                 * Unicode script "Cuneiform".
//                 */
//                        CUNEIFORM,
//
//                /**
//                 * Unicode script "Phoenician".
//                 */
//                        PHOENICIAN,
//
//                /**
//                 * Unicode script "Phags_Pa".
//                 */
//                        PHAGS_PA,
//
//                /**
//                 * Unicode script "Nko".
//                 */
//                        NKO,
//
//                /**
//                 * Unicode script "Sundanese".
//                 */
//                        SUNDANESE,
//
//                /**
//                 * Unicode script "Batak".
//                 */
//                        BATAK,
//
//                /**
//                 * Unicode script "Lepcha".
//                 */
//                        LEPCHA,
//
//                /**
//                 * Unicode script "Ol_Chiki".
//                 */
//                        OL_CHIKI,
//
//                /**
//                 * Unicode script "Vai".
//                 */
//                        VAI,
//
//                /**
//                 * Unicode script "Saurashtra".
//                 */
//                        SAURASHTRA,
//
//                /**
//                 * Unicode script "Kayah_Li".
//                 */
//                        KAYAH_LI,
//
//                /**
//                 * Unicode script "Rejang".
//                 */
//                        REJANG,
//
//                /**
//                 * Unicode script "Lycian".
//                 */
//                        LYCIAN,
//
//                /**
//                 * Unicode script "Carian".
//                 */
//                        CARIAN,
//
//                /**
//                 * Unicode script "Lydian".
//                 */
//                        LYDIAN,
//
//                /**
//                 * Unicode script "Cham".
//                 */
//                        CHAM,
//
//                /**
//                 * Unicode script "Tai_Tham".
//                 */
//                        TAI_THAM,
//
//                /**
//                 * Unicode script "Tai_Viet".
//                 */
//                        TAI_VIET,
//
//                /**
//                 * Unicode script "Avestan".
//                 */
//                        AVESTAN,
//
//                /**
//                 * Unicode script "Egyptian_Hieroglyphs".
//                 */
//                        EGYPTIAN_HIEROGLYPHS,
//
//                /**
//                 * Unicode script "Samaritan".
//                 */
//                        SAMARITAN,
//
//                /**
//                 * Unicode script "Mandaic".
//                 */
//                        MANDAIC,
//
//                /**
//                 * Unicode script "Lisu".
//                 */
//                        LISU,
//
//                /**
//                 * Unicode script "Bamum".
//                 */
//                        BAMUM,
//
//                /**
//                 * Unicode script "Javanese".
//                 */
//                        JAVANESE,
//
//                /**
//                 * Unicode script "Meetei_Mayek".
//                 */
//                        MEETEI_MAYEK,
//
//                /**
//                 * Unicode script "Imperial_Aramaic".
//                 */
//                        IMPERIAL_ARAMAIC,
//
//                /**
//                 * Unicode script "Old_South_Arabian".
//                 */
//                        OLD_SOUTH_ARABIAN,
//
//                /**
//                 * Unicode script "Inscriptional_Parthian".
//                 */
//                        INSCRIPTIONAL_PARTHIAN,
//
//                /**
//                 * Unicode script "Inscriptional_Pahlavi".
//                 */
//                        INSCRIPTIONAL_PAHLAVI,
//
//                /**
//                 * Unicode script "Old_Turkic".
//                 */
//                        OLD_TURKIC,
//
//                /**
//                 * Unicode script "Brahmi".
//                 */
//                        BRAHMI,
//
//                /**
//                 * Unicode script "Kaithi".
//                 */
//                        KAITHI,
//
//                /**
//                 * Unicode script "Meroitic Hieroglyphs".
//                 */
//                        MEROITIC_HIEROGLYPHS,
//
//                /**
//                 * Unicode script "Meroitic Cursive".
//                 */
//                        MEROITIC_CURSIVE,
//
//                /**
//                 * Unicode script "Sora Sompeng".
//                 */
//                        SORA_SOMPENG,
//
//                /**
//                 * Unicode script "Chakma".
//                 */
//                        CHAKMA,
//
//                /**
//                 * Unicode script "Sharada".
//                 */
//                        SHARADA,
//
//                /**
//                 * Unicode script "Takri".
//                 */
//                        TAKRI,
//
//                /**
//                 * Unicode script "Miao".
//                 */
//                        MIAO,
//
//                /**
//                 * Unicode script "Unknown".
//                 */
//                        UNKNOWN;
//
//                private static int[] scriptStarts = {
//                        0x0000,   // 0000..0040; COMMON
//                        0x0041,   // 0041..005A; LATIN
//                        0x005B,   // 005B..0060; COMMON
//                        0x0061,   // 0061..007A; LATIN
//                        0x007B,   // 007B..00A9; COMMON
//                        0x00AA,   // 00AA..00AA; LATIN
//                        0x00AB,   // 00AB..00B9; COMMON
//                        0x00BA,   // 00BA..00BA; LATIN
//                        0x00BB,   // 00BB..00BF; COMMON
//                        0x00C0,   // 00C0..00D6; LATIN
//                        0x00D7,   // 00D7..00D7; COMMON
//                        0x00D8,   // 00D8..00F6; LATIN
//                        0x00F7,   // 00F7..00F7; COMMON
//                        0x00F8,   // 00F8..02B8; LATIN
//                        0x02B9,   // 02B9..02DF; COMMON
//                        0x02E0,   // 02E0..02E4; LATIN
//                        0x02E5,   // 02E5..02E9; COMMON
//                        0x02EA,   // 02EA..02EB; BOPOMOFO
//                        0x02EC,   // 02EC..02FF; COMMON
//                        0x0300,   // 0300..036F; INHERITED
//                        0x0370,   // 0370..0373; GREEK
//                        0x0374,   // 0374..0374; COMMON
//                        0x0375,   // 0375..037D; GREEK
//                        0x037E,   // 037E..0383; COMMON
//                        0x0384,   // 0384..0384; GREEK
//                        0x0385,   // 0385..0385; COMMON
//                        0x0386,   // 0386..0386; GREEK
//                        0x0387,   // 0387..0387; COMMON
//                        0x0388,   // 0388..03E1; GREEK
//                        0x03E2,   // 03E2..03EF; COPTIC
//                        0x03F0,   // 03F0..03FF; GREEK
//                        0x0400,   // 0400..0484; CYRILLIC
//                        0x0485,   // 0485..0486; INHERITED
//                        0x0487,   // 0487..0530; CYRILLIC
//                        0x0531,   // 0531..0588; ARMENIAN
//                        0x0589,   // 0589..0589; COMMON
//                        0x058A,   // 058A..0590; ARMENIAN
//                        0x0591,   // 0591..05FF; HEBREW
//                        0x0600,   // 0600..060B; ARABIC
//                        0x060C,   // 060C..060C; COMMON
//                        0x060D,   // 060D..061A; ARABIC
//                        0x061B,   // 061B..061D; COMMON
//                        0x061E,   // 061E..061E; ARABIC
//                        0x061F,   // 061F..061F; COMMON
//                        0x0620,   // 0620..063F; ARABIC
//                        0x0640,   // 0640..0640; COMMON
//                        0x0641,   // 0641..064A; ARABIC
//                        0x064B,   // 064B..0655; INHERITED
//                        0x0656,   // 0656..065F; ARABIC
//                        0x0660,   // 0660..0669; COMMON
//                        0x066A,   // 066A..066F; ARABIC
//                        0x0670,   // 0670..0670; INHERITED
//                        0x0671,   // 0671..06DC; ARABIC
//                        0x06DD,   // 06DD..06DD; COMMON
//                        0x06DE,   // 06DE..06FF; ARABIC
//                        0x0700,   // 0700..074F; SYRIAC
//                        0x0750,   // 0750..077F; ARABIC
//                        0x0780,   // 0780..07BF; THAANA
//                        0x07C0,   // 07C0..07FF; NKO
//                        0x0800,   // 0800..083F; SAMARITAN
//                        0x0840,   // 0840..089F; MANDAIC
//                        0x08A0,   // 08A0..08FF; ARABIC
//                        0x0900,   // 0900..0950; DEVANAGARI
//                        0x0951,   // 0951..0952; INHERITED
//                        0x0953,   // 0953..0963; DEVANAGARI
//                        0x0964,   // 0964..0965; COMMON
//                        0x0966,   // 0966..0980; DEVANAGARI
//                        0x0981,   // 0981..0A00; BENGALI
//                        0x0A01,   // 0A01..0A80; GURMUKHI
//                        0x0A81,   // 0A81..0B00; GUJARATI
//                        0x0B01,   // 0B01..0B81; ORIYA
//                        0x0B82,   // 0B82..0C00; TAMIL
//                        0x0C01,   // 0C01..0C81; TELUGU
//                        0x0C82,   // 0C82..0CF0; KANNADA
//                        0x0D02,   // 0D02..0D81; MALAYALAM
//                        0x0D82,   // 0D82..0E00; SINHALA
//                        0x0E01,   // 0E01..0E3E; THAI
//                        0x0E3F,   // 0E3F..0E3F; COMMON
//                        0x0E40,   // 0E40..0E80; THAI
//                        0x0E81,   // 0E81..0EFF; LAO
//                        0x0F00,   // 0F00..0FD4; TIBETAN
//                        0x0FD5,   // 0FD5..0FD8; COMMON
//                        0x0FD9,   // 0FD9..0FFF; TIBETAN
//                        0x1000,   // 1000..109F; MYANMAR
//                        0x10A0,   // 10A0..10FA; GEORGIAN
//                        0x10FB,   // 10FB..10FB; COMMON
//                        0x10FC,   // 10FC..10FF; GEORGIAN
//                        0x1100,   // 1100..11FF; HANGUL
//                        0x1200,   // 1200..139F; ETHIOPIC
//                        0x13A0,   // 13A0..13FF; CHEROKEE
//                        0x1400,   // 1400..167F; CANADIAN_ABORIGINAL
//                        0x1680,   // 1680..169F; OGHAM
//                        0x16A0,   // 16A0..16EA; RUNIC
//                        0x16EB,   // 16EB..16ED; COMMON
//                        0x16EE,   // 16EE..16FF; RUNIC
//                        0x1700,   // 1700..171F; TAGALOG
//                        0x1720,   // 1720..1734; HANUNOO
//                        0x1735,   // 1735..173F; COMMON
//                        0x1740,   // 1740..175F; BUHID
//                        0x1760,   // 1760..177F; TAGBANWA
//                        0x1780,   // 1780..17FF; KHMER
//                        0x1800,   // 1800..1801; MONGOLIAN
//                        0x1802,   // 1802..1803; COMMON
//                        0x1804,   // 1804..1804; MONGOLIAN
//                        0x1805,   // 1805..1805; COMMON
//                        0x1806,   // 1806..18AF; MONGOLIAN
//                        0x18B0,   // 18B0..18FF; CANADIAN_ABORIGINAL
//                        0x1900,   // 1900..194F; LIMBU
//                        0x1950,   // 1950..197F; TAI_LE
//                        0x1980,   // 1980..19DF; NEW_TAI_LUE
//                        0x19E0,   // 19E0..19FF; KHMER
//                        0x1A00,   // 1A00..1A1F; BUGINESE
//                        0x1A20,   // 1A20..1AFF; TAI_THAM
//                        0x1B00,   // 1B00..1B7F; BALINESE
//                        0x1B80,   // 1B80..1BBF; SUNDANESE
//                        0x1BC0,   // 1BC0..1BFF; BATAK
//                        0x1C00,   // 1C00..1C4F; LEPCHA
//                        0x1C50,   // 1C50..1CBF; OL_CHIKI
//                        0x1CC0,   // 1CC0..1CCF; SUNDANESE
//                        0x1CD0,   // 1CD0..1CD2; INHERITED
//                        0x1CD3,   // 1CD3..1CD3; COMMON
//                        0x1CD4,   // 1CD4..1CE0; INHERITED
//                        0x1CE1,   // 1CE1..1CE1; COMMON
//                        0x1CE2,   // 1CE2..1CE8; INHERITED
//                        0x1CE9,   // 1CE9..1CEC; COMMON
//                        0x1CED,   // 1CED..1CED; INHERITED
//                        0x1CEE,   // 1CEE..1CF3; COMMON
//                        0x1CF4,   // 1CF4..1CF4; INHERITED
//                        0x1CF5,   // 1CF5..1CFF; COMMON
//                        0x1D00,   // 1D00..1D25; LATIN
//                        0x1D26,   // 1D26..1D2A; GREEK
//                        0x1D2B,   // 1D2B..1D2B; CYRILLIC
//                        0x1D2C,   // 1D2C..1D5C; LATIN
//                        0x1D5D,   // 1D5D..1D61; GREEK
//                        0x1D62,   // 1D62..1D65; LATIN
//                        0x1D66,   // 1D66..1D6A; GREEK
//                        0x1D6B,   // 1D6B..1D77; LATIN
//                        0x1D78,   // 1D78..1D78; CYRILLIC
//                        0x1D79,   // 1D79..1DBE; LATIN
//                        0x1DBF,   // 1DBF..1DBF; GREEK
//                        0x1DC0,   // 1DC0..1DFF; INHERITED
//                        0x1E00,   // 1E00..1EFF; LATIN
//                        0x1F00,   // 1F00..1FFF; GREEK
//                        0x2000,   // 2000..200B; COMMON
//                        0x200C,   // 200C..200D; INHERITED
//                        0x200E,   // 200E..2070; COMMON
//                        0x2071,   // 2071..2073; LATIN
//                        0x2074,   // 2074..207E; COMMON
//                        0x207F,   // 207F..207F; LATIN
//                        0x2080,   // 2080..208F; COMMON
//                        0x2090,   // 2090..209F; LATIN
//                        0x20A0,   // 20A0..20CF; COMMON
//                        0x20D0,   // 20D0..20FF; INHERITED
//                        0x2100,   // 2100..2125; COMMON
//                        0x2126,   // 2126..2126; GREEK
//                        0x2127,   // 2127..2129; COMMON
//                        0x212A,   // 212A..212B; LATIN
//                        0x212C,   // 212C..2131; COMMON
//                        0x2132,   // 2132..2132; LATIN
//                        0x2133,   // 2133..214D; COMMON
//                        0x214E,   // 214E..214E; LATIN
//                        0x214F,   // 214F..215F; COMMON
//                        0x2160,   // 2160..2188; LATIN
//                        0x2189,   // 2189..27FF; COMMON
//                        0x2800,   // 2800..28FF; BRAILLE
//                        0x2900,   // 2900..2BFF; COMMON
//                        0x2C00,   // 2C00..2C5F; GLAGOLITIC
//                        0x2C60,   // 2C60..2C7F; LATIN
//                        0x2C80,   // 2C80..2CFF; COPTIC
//                        0x2D00,   // 2D00..2D2F; GEORGIAN
//                        0x2D30,   // 2D30..2D7F; TIFINAGH
//                        0x2D80,   // 2D80..2DDF; ETHIOPIC
//                        0x2DE0,   // 2DE0..2DFF; CYRILLIC
//                        0x2E00,   // 2E00..2E7F; COMMON
//                        0x2E80,   // 2E80..2FEF; HAN
//                        0x2FF0,   // 2FF0..3004; COMMON
//                        0x3005,   // 3005..3005; HAN
//                        0x3006,   // 3006..3006; COMMON
//                        0x3007,   // 3007..3007; HAN
//                        0x3008,   // 3008..3020; COMMON
//                        0x3021,   // 3021..3029; HAN
//                        0x302A,   // 302A..302D; INHERITED
//                        0x302E,   // 302E..302F; HANGUL
//                        0x3030,   // 3030..3037; COMMON
//                        0x3038,   // 3038..303B; HAN
//                        0x303C,   // 303C..3040; COMMON
//                        0x3041,   // 3041..3098; HIRAGANA
//                        0x3099,   // 3099..309A; INHERITED
//                        0x309B,   // 309B..309C; COMMON
//                        0x309D,   // 309D..309F; HIRAGANA
//                        0x30A0,   // 30A0..30A0; COMMON
//                        0x30A1,   // 30A1..30FA; KATAKANA
//                        0x30FB,   // 30FB..30FC; COMMON
//                        0x30FD,   // 30FD..3104; KATAKANA
//                        0x3105,   // 3105..3130; BOPOMOFO
//                        0x3131,   // 3131..318F; HANGUL
//                        0x3190,   // 3190..319F; COMMON
//                        0x31A0,   // 31A0..31BF; BOPOMOFO
//                        0x31C0,   // 31C0..31EF; COMMON
//                        0x31F0,   // 31F0..31FF; KATAKANA
//                        0x3200,   // 3200..321F; HANGUL
//                        0x3220,   // 3220..325F; COMMON
//                        0x3260,   // 3260..327E; HANGUL
//                        0x327F,   // 327F..32CF; COMMON
//                        0x32D0,   // 32D0..3357; KATAKANA
//                        0x3358,   // 3358..33FF; COMMON
//                        0x3400,   // 3400..4DBF; HAN
//                        0x4DC0,   // 4DC0..4DFF; COMMON
//                        0x4E00,   // 4E00..9FFF; HAN
//                        0xA000,   // A000..A4CF; YI
//                        0xA4D0,   // A4D0..A4FF; LISU
//                        0xA500,   // A500..A63F; VAI
//                        0xA640,   // A640..A69F; CYRILLIC
//                        0xA6A0,   // A6A0..A6FF; BAMUM
//                        0xA700,   // A700..A721; COMMON
//                        0xA722,   // A722..A787; LATIN
//                        0xA788,   // A788..A78A; COMMON
//                        0xA78B,   // A78B..A7FF; LATIN
//                        0xA800,   // A800..A82F; SYLOTI_NAGRI
//                        0xA830,   // A830..A83F; COMMON
//                        0xA840,   // A840..A87F; PHAGS_PA
//                        0xA880,   // A880..A8DF; SAURASHTRA
//                        0xA8E0,   // A8E0..A8FF; DEVANAGARI
//                        0xA900,   // A900..A92F; KAYAH_LI
//                        0xA930,   // A930..A95F; REJANG
//                        0xA960,   // A960..A97F; HANGUL
//                        0xA980,   // A980..A9FF; JAVANESE
//                        0xAA00,   // AA00..AA5F; CHAM
//                        0xAA60,   // AA60..AA7F; MYANMAR
//                        0xAA80,   // AA80..AADF; TAI_VIET
//                        0xAAE0,   // AAE0..AB00; MEETEI_MAYEK
//                        0xAB01,   // AB01..ABBF; ETHIOPIC
//                        0xABC0,   // ABC0..ABFF; MEETEI_MAYEK
//                        0xAC00,   // AC00..D7FB; HANGUL
//                        0xD7FC,   // D7FC..F8FF; UNKNOWN
//                        0xF900,   // F900..FAFF; HAN
//                        0xFB00,   // FB00..FB12; LATIN
//                        0xFB13,   // FB13..FB1C; ARMENIAN
//                        0xFB1D,   // FB1D..FB4F; HEBREW
//                        0xFB50,   // FB50..FD3D; ARABIC
//                        0xFD3E,   // FD3E..FD4F; COMMON
//                        0xFD50,   // FD50..FDFC; ARABIC
//                        0xFDFD,   // FDFD..FDFF; COMMON
//                        0xFE00,   // FE00..FE0F; INHERITED
//                        0xFE10,   // FE10..FE1F; COMMON
//                        0xFE20,   // FE20..FE2F; INHERITED
//                        0xFE30,   // FE30..FE6F; COMMON
//                        0xFE70,   // FE70..FEFE; ARABIC
//                        0xFEFF,   // FEFF..FF20; COMMON
//                        0xFF21,   // FF21..FF3A; LATIN
//                        0xFF3B,   // FF3B..FF40; COMMON
//                        0xFF41,   // FF41..FF5A; LATIN
//                        0xFF5B,   // FF5B..FF65; COMMON
//                        0xFF66,   // FF66..FF6F; KATAKANA
//                        0xFF70,   // FF70..FF70; COMMON
//                        0xFF71,   // FF71..FF9D; KATAKANA
//                        0xFF9E,   // FF9E..FF9F; COMMON
//                        0xFFA0,   // FFA0..FFDF; HANGUL
//                        0xFFE0,   // FFE0..FFFF; COMMON
//                        0x10000,  // 10000..100FF; LINEAR_B
//                        0x10100,  // 10100..1013F; COMMON
//                        0x10140,  // 10140..1018F; GREEK
//                        0x10190,  // 10190..101FC; COMMON
//                        0x101FD,  // 101FD..1027F; INHERITED
//                        0x10280,  // 10280..1029F; LYCIAN
//                        0x102A0,  // 102A0..102FF; CARIAN
//                        0x10300,  // 10300..1032F; OLD_ITALIC
//                        0x10330,  // 10330..1037F; GOTHIC
//                        0x10380,  // 10380..1039F; UGARITIC
//                        0x103A0,  // 103A0..103FF; OLD_PERSIAN
//                        0x10400,  // 10400..1044F; DESERET
//                        0x10450,  // 10450..1047F; SHAVIAN
//                        0x10480,  // 10480..107FF; OSMANYA
//                        0x10800,  // 10800..1083F; CYPRIOT
//                        0x10840,  // 10840..108FF; IMPERIAL_ARAMAIC
//                        0x10900,  // 10900..1091F; PHOENICIAN
//                        0x10920,  // 10920..1097F; LYDIAN
//                        0x10980,  // 10980..1099F; MEROITIC_HIEROGLYPHS
//                        0x109A0,  // 109A0..109FF; MEROITIC_CURSIVE
//                        0x10A00,  // 10A00..10A5F; KHAROSHTHI
//                        0x10A60,  // 10A60..10AFF; OLD_SOUTH_ARABIAN
//                        0x10B00,  // 10B00..10B3F; AVESTAN
//                        0x10B40,  // 10B40..10B5F; INSCRIPTIONAL_PARTHIAN
//                        0x10B60,  // 10B60..10BFF; INSCRIPTIONAL_PAHLAVI
//                        0x10C00,  // 10C00..10E5F; OLD_TURKIC
//                        0x10E60,  // 10E60..10FFF; ARABIC
//                        0x11000,  // 11000..1107F; BRAHMI
//                        0x11080,  // 11080..110CF; KAITHI
//                        0x110D0,  // 110D0..110FF; SORA_SOMPENG
//                        0x11100,  // 11100..1117F; CHAKMA
//                        0x11180,  // 11180..1167F; SHARADA
//                        0x11680,  // 11680..116CF; TAKRI
//                        0x12000,  // 12000..12FFF; CUNEIFORM
//                        0x13000,  // 13000..167FF; EGYPTIAN_HIEROGLYPHS
//                        0x16800,  // 16800..16A38; BAMUM
//                        0x16F00,  // 16F00..16F9F; MIAO
//                        0x1B000,  // 1B000..1B000; KATAKANA
//                        0x1B001,  // 1B001..1CFFF; HIRAGANA
//                        0x1D000,  // 1D000..1D166; COMMON
//                        0x1D167,  // 1D167..1D169; INHERITED
//                        0x1D16A,  // 1D16A..1D17A; COMMON
//                        0x1D17B,  // 1D17B..1D182; INHERITED
//                        0x1D183,  // 1D183..1D184; COMMON
//                        0x1D185,  // 1D185..1D18B; INHERITED
//                        0x1D18C,  // 1D18C..1D1A9; COMMON
//                        0x1D1AA,  // 1D1AA..1D1AD; INHERITED
//                        0x1D1AE,  // 1D1AE..1D1FF; COMMON
//                        0x1D200,  // 1D200..1D2FF; GREEK
//                        0x1D300,  // 1D300..1EDFF; COMMON
//                        0x1EE00,  // 1EE00..1EFFF; ARABIC
//                        0x1F000,  // 1F000..1F1FF; COMMON
//                        0x1F200,  // 1F200..1F200; HIRAGANA
//                        0x1F201,  // 1F210..1FFFF; COMMON
//                        0x20000,  // 20000..E0000; HAN
//                        0xE0001,  // E0001..E00FF; COMMON
//                        0xE0100,  // E0100..E01EF; INHERITED
//                        0xE01F0   // E01F0..10FFFF; UNKNOWN
//
//                };
//
//                private static UnicodeScript[] scripts = {
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        BOPOMOFO,
//                        COMMON,
//                        INHERITED,
//                        GREEK,
//                        COMMON,
//                        GREEK,
//                        COMMON,
//                        GREEK,
//                        COMMON,
//                        GREEK,
//                        COMMON,
//                        GREEK,
//                        COPTIC,
//                        GREEK,
//                        CYRILLIC,
//                        INHERITED,
//                        CYRILLIC,
//                        ARMENIAN,
//                        COMMON,
//                        ARMENIAN,
//                        HEBREW,
//                        ARABIC,
//                        COMMON,
//                        ARABIC,
//                        COMMON,
//                        ARABIC,
//                        COMMON,
//                        ARABIC,
//                        COMMON,
//                        ARABIC,
//                        INHERITED,
//                        ARABIC,
//                        COMMON,
//                        ARABIC,
//                        INHERITED,
//                        ARABIC,
//                        COMMON,
//                        ARABIC,
//                        SYRIAC,
//                        ARABIC,
//                        THAANA,
//                        NKO,
//                        SAMARITAN,
//                        MANDAIC,
//                        ARABIC,
//                        DEVANAGARI,
//                        INHERITED,
//                        DEVANAGARI,
//                        COMMON,
//                        DEVANAGARI,
//                        BENGALI,
//                        GURMUKHI,
//                        GUJARATI,
//                        ORIYA,
//                        TAMIL,
//                        TELUGU,
//                        KANNADA,
//                        MALAYALAM,
//                        SINHALA,
//                        THAI,
//                        COMMON,
//                        THAI,
//                        LAO,
//                        TIBETAN,
//                        COMMON,
//                        TIBETAN,
//                        MYANMAR,
//                        GEORGIAN,
//                        COMMON,
//                        GEORGIAN,
//                        HANGUL,
//                        ETHIOPIC,
//                        CHEROKEE,
//                        CANADIAN_ABORIGINAL,
//                        OGHAM,
//                        RUNIC,
//                        COMMON,
//                        RUNIC,
//                        TAGALOG,
//                        HANUNOO,
//                        COMMON,
//                        BUHID,
//                        TAGBANWA,
//                        KHMER,
//                        MONGOLIAN,
//                        COMMON,
//                        MONGOLIAN,
//                        COMMON,
//                        MONGOLIAN,
//                        CANADIAN_ABORIGINAL,
//                        LIMBU,
//                        TAI_LE,
//                        NEW_TAI_LUE,
//                        KHMER,
//                        BUGINESE,
//                        TAI_THAM,
//                        BALINESE,
//                        SUNDANESE,
//                        BATAK,
//                        LEPCHA,
//                        OL_CHIKI,
//                        SUNDANESE,
//                        INHERITED,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        LATIN,
//                        GREEK,
//                        CYRILLIC,
//                        LATIN,
//                        GREEK,
//                        LATIN,
//                        GREEK,
//                        LATIN,
//                        CYRILLIC,
//                        LATIN,
//                        GREEK,
//                        INHERITED,
//                        LATIN,
//                        GREEK,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        GREEK,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        BRAILLE,
//                        COMMON,
//                        GLAGOLITIC,
//                        LATIN,
//                        COPTIC,
//                        GEORGIAN,
//                        TIFINAGH,
//                        ETHIOPIC,
//                        CYRILLIC,
//                        COMMON,
//                        HAN,
//                        COMMON,
//                        HAN,
//                        COMMON,
//                        HAN,
//                        COMMON,
//                        HAN,
//                        INHERITED,
//                        HANGUL,
//                        COMMON,
//                        HAN,
//                        COMMON,
//                        HIRAGANA,
//                        INHERITED,
//                        COMMON,
//                        HIRAGANA,
//                        COMMON,
//                        KATAKANA,
//                        COMMON,
//                        KATAKANA,
//                        BOPOMOFO,
//                        HANGUL,
//                        COMMON,
//                        BOPOMOFO,
//                        COMMON,
//                        KATAKANA,
//                        HANGUL,
//                        COMMON,
//                        HANGUL,
//                        COMMON,
//                        KATAKANA,
//                        COMMON,
//                        HAN,
//                        COMMON,
//                        HAN,
//                        YI,
//                        LISU,
//                        VAI,
//                        CYRILLIC,
//                        BAMUM,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        SYLOTI_NAGRI,
//                        COMMON,
//                        PHAGS_PA,
//                        SAURASHTRA,
//                        DEVANAGARI,
//                        KAYAH_LI,
//                        REJANG,
//                        HANGUL,
//                        JAVANESE,
//                        CHAM,
//                        MYANMAR,
//                        TAI_VIET,
//                        MEETEI_MAYEK,
//                        ETHIOPIC,
//                        MEETEI_MAYEK,
//                        HANGUL,
//                        UNKNOWN     ,
//                        HAN,
//                        LATIN,
//                        ARMENIAN,
//                        HEBREW,
//                        ARABIC,
//                        COMMON,
//                        ARABIC,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        ARABIC,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        LATIN,
//                        COMMON,
//                        KATAKANA,
//                        COMMON,
//                        KATAKANA,
//                        COMMON,
//                        HANGUL,
//                        COMMON,
//                        LINEAR_B,
//                        COMMON,
//                        GREEK,
//                        COMMON,
//                        INHERITED,
//                        LYCIAN,
//                        CARIAN,
//                        OLD_ITALIC,
//                        GOTHIC,
//                        UGARITIC,
//                        OLD_PERSIAN,
//                        DESERET,
//                        SHAVIAN,
//                        OSMANYA,
//                        CYPRIOT,
//                        IMPERIAL_ARAMAIC,
//                        PHOENICIAN,
//                        LYDIAN,
//                        MEROITIC_HIEROGLYPHS,
//                        MEROITIC_CURSIVE,
//                        KHAROSHTHI,
//                        OLD_SOUTH_ARABIAN,
//                        AVESTAN,
//                        INSCRIPTIONAL_PARTHIAN,
//                        INSCRIPTIONAL_PAHLAVI,
//                        OLD_TURKIC,
//                        ARABIC,
//                        BRAHMI,
//                        KAITHI,
//                        SORA_SOMPENG,
//                        CHAKMA,
//                        SHARADA,
//                        TAKRI,
//                        CUNEIFORM,
//                        EGYPTIAN_HIEROGLYPHS,
//                        BAMUM,
//                        MIAO,
//                        KATAKANA,
//                        HIRAGANA,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        INHERITED,
//                        COMMON,
//                        GREEK,
//                        COMMON,
//                        ARABIC,
//                        COMMON,
//                        HIRAGANA,
//                        COMMON,
//                        HAN,
//                        COMMON,
//                        INHERITED,
//                        UNKNOWN
//                };
//
//                private static HashMap<String, Character.UnicodeScript> aliases;
//                static {
//                    aliases =  HashMap<>(128);
//                    aliases.put("ARAB", ARABIC);
//                    aliases.put("ARMI", IMPERIAL_ARAMAIC);
//                    aliases.put("ARMN", ARMENIAN);
//                    aliases.put("AVST", AVESTAN);
//                    aliases.put("BALI", BALINESE);
//                    aliases.put("BAMU", BAMUM);
//                    aliases.put("BATK", BATAK);
//                    aliases.put("BENG", BENGALI);
//                    aliases.put("BOPO", BOPOMOFO);
//                    aliases.put("BRAI", BRAILLE);
//                    aliases.put("BRAH", BRAHMI);
//                    aliases.put("BUGI", BUGINESE);
//                    aliases.put("BUHD", BUHID);
//                    aliases.put("CAKM", CHAKMA);
//                    aliases.put("CANS", CANADIAN_ABORIGINAL);
//                    aliases.put("CARI", CARIAN);
//                    aliases.put("CHAM", CHAM);
//                    aliases.put("CHER", CHEROKEE);
//                    aliases.put("COPT", COPTIC);
//                    aliases.put("CPRT", CYPRIOT);
//                    aliases.put("CYRL", CYRILLIC);
//                    aliases.put("DEVA", DEVANAGARI);
//                    aliases.put("DSRT", DESERET);
//                    aliases.put("EGYP", EGYPTIAN_HIEROGLYPHS);
//                    aliases.put("ETHI", ETHIOPIC);
//                    aliases.put("GEOR", GEORGIAN);
//                    aliases.put("GLAG", GLAGOLITIC);
//                    aliases.put("GOTH", GOTHIC);
//                    aliases.put("GREK", GREEK);
//                    aliases.put("GUJR", GUJARATI);
//                    aliases.put("GURU", GURMUKHI);
//                    aliases.put("HANG", HANGUL);
//                    aliases.put("HANI", HAN);
//                    aliases.put("HANO", HANUNOO);
//                    aliases.put("HEBR", HEBREW);
//                    aliases.put("HIRA", HIRAGANA);
//                    // it appears we don't have the KATAKANA_OR_HIRAGANA
//                    //aliases.put("HRKT", KATAKANA_OR_HIRAGANA);
//                    aliases.put("ITAL", OLD_ITALIC);
//                    aliases.put("JAVA", JAVANESE);
//                    aliases.put("KALI", KAYAH_LI);
//                    aliases.put("KANA", KATAKANA);
//                    aliases.put("KHAR", KHAROSHTHI);
//                    aliases.put("KHMR", KHMER);
//                    aliases.put("KNDA", KANNADA);
//                    aliases.put("KTHI", KAITHI);
//                    aliases.put("LANA", TAI_THAM);
//                    aliases.put("LAOO", LAO);
//                    aliases.put("LATN", LATIN);
//                    aliases.put("LEPC", LEPCHA);
//                    aliases.put("LIMB", LIMBU);
//                    aliases.put("LINB", LINEAR_B);
//                    aliases.put("LISU", LISU);
//                    aliases.put("LYCI", LYCIAN);
//                    aliases.put("LYDI", LYDIAN);
//                    aliases.put("MAND", MANDAIC);
//                    aliases.put("MERC", MEROITIC_CURSIVE);
//                    aliases.put("MERO", MEROITIC_HIEROGLYPHS);
//                    aliases.put("MLYM", MALAYALAM);
//                    aliases.put("MONG", MONGOLIAN);
//                    aliases.put("MTEI", MEETEI_MAYEK);
//                    aliases.put("MYMR", MYANMAR);
//                    aliases.put("NKOO", NKO);
//                    aliases.put("OGAM", OGHAM);
//                    aliases.put("OLCK", OL_CHIKI);
//                    aliases.put("ORKH", OLD_TURKIC);
//                    aliases.put("ORYA", ORIYA);
//                    aliases.put("OSMA", OSMANYA);
//                    aliases.put("PHAG", PHAGS_PA);
//                    aliases.put("PLRD", MIAO);
//                    aliases.put("PHLI", INSCRIPTIONAL_PAHLAVI);
//                    aliases.put("PHNX", PHOENICIAN);
//                    aliases.put("PRTI", INSCRIPTIONAL_PARTHIAN);
//                    aliases.put("RJNG", REJANG);
//                    aliases.put("RUNR", RUNIC);
//                    aliases.put("SAMR", SAMARITAN);
//                    aliases.put("SARB", OLD_SOUTH_ARABIAN);
//                    aliases.put("SAUR", SAURASHTRA);
//                    aliases.put("SHAW", SHAVIAN);
//                    aliases.put("SHRD", SHARADA);
//                    aliases.put("SINH", SINHALA);
//                    aliases.put("SORA", SORA_SOMPENG);
//                    aliases.put("SUND", SUNDANESE);
//                    aliases.put("SYLO", SYLOTI_NAGRI);
//                    aliases.put("SYRC", SYRIAC);
//                    aliases.put("TAGB", TAGBANWA);
//                    aliases.put("TALE", TAI_LE);
//                    aliases.put("TAKR", TAKRI);
//                    aliases.put("TALU", NEW_TAI_LUE);
//                    aliases.put("TAML", TAMIL);
//                    aliases.put("TAVT", TAI_VIET);
//                    aliases.put("TELU", TELUGU);
//                    aliases.put("TFNG", TIFINAGH);
//                    aliases.put("TGLG", TAGALOG);
//                    aliases.put("THAA", THAANA);
//                    aliases.put("THAI", THAI);
//                    aliases.put("TIBT", TIBETAN);
//                    aliases.put("UGAR", UGARITIC);
//                    aliases.put("VAII", VAI);
//                    aliases.put("XPEO", OLD_PERSIAN);
//                    aliases.put("XSUX", CUNEIFORM);
//                    aliases.put("YIII", YI);
//                    aliases.put("ZINH", INHERITED);
//                    aliases.put("ZYYY", COMMON);
//                    aliases.put("ZZZZ", UNKNOWN);
//                }
//
//                /**
//                 * Returns the enum constant representing the Unicode script of which
//                 * the given character (Unicode code point) is assigned to.
//                 *
//                 * @param   codePoint the character (Unicode code point) in question.
//                 * @return  The {@code UnicodeScript} constant representing the
//                 *          Unicode script of which this character is assigned to.
//                 *
//                 * @exception IllegalArgumentException if the specified
//                 * {@code codePoint} is an invalid Unicode code point.
//                 * @see Character#isValidCodePoint(int)
//                 *
//                 */
//                static UnicodeScript of(int codePoint) {
//                    if (!isValidCodePoint(codePoint))
//                        throw  IllegalArgumentException();
//                    int type = getType(codePoint);
//                    // leave SURROGATE and PRIVATE_USE for table lookup
//                    if (type == UNASSIGNED)
//                        return UNKNOWN;
//                    int index = Arrays.binarySearch(scriptStarts, codePoint);
//                    if (index < 0)
//                        index = -index - 2;
//                    return scripts[index];
//                }
//
//                /**
//                 * Returns the UnicodeScript constant with the given Unicode script
//                 * name or the script name alias. Script names and their aliases are
//                 * determined by The Unicode Standard. The files Scripts&lt;version&gt;.txt
//                 * and PropertyValueAliases&lt;version&gt;.txt define script names
//                 * and the script name aliases for a particular version of the
//                 * standard. The {@link Character} class specifies the version of
//                 * the standard that it supports.
//                 * <p>
//                 * Character case is ignored for all of the valid script names.
//                 * The en_US locale's case mapping rules are used to provide
//                 * case-insensitive string comparisons for script name validation.
//                 * <p>
//                 *
//                 * @param scriptName A {@code UnicodeScript} name.
//                 * @return The {@code UnicodeScript} constant identified
//                 *         by {@code scriptName}
//                 * @throws IllegalArgumentException if {@code scriptName} is an
//                 *         invalid name
//                 * @throws NullPointerException if {@code scriptName} is null
//                 */
//                static UnicodeScript forName(String scriptName) {
//                    scriptName = scriptName.toUpperCase(Locale.ENGLISH);
//                    //.replace(' ', '_'));
//                    UnicodeScript sc = aliases.get(scriptName);
//                    if (sc != null)
//                        return sc;
//                    return valueOf(scriptName);
//                }
            };

        public:
            /**
             * The number of bits used to represent a char value in unsigned binary form, constant 16.
             */
            static const int SIZE = 16;

            /**
             * The number of bytes used to represent a char value in unsigned binary form.
             */
            static const int BYTES = SIZE / Bytes::SIZE;

            /**
             * The minimum radix available for conversion to and from strings.
             */
            static const int MIN_RADIX = 2;

            /**
             * The maximum radix available for conversion to and from strings.
             */
            static const int MAX_RADIX = 36;

            /**
             * The constant value of this field is the smallest value of type char
             */
            static const char16_t MIN_VALUE = u'\u0000';

            /**
             * The constant value of this field is the largest value of type char
             */
            static const char16_t MAX_VALUE = u'\uFFFF';

            /**
             * General category "Cn" in the Unicode specification.
             */
            static const byte UNASSIGNED = 0;

            /**
             * General category "Lu" in the Unicode specification.
             */
            static const byte UPPERCASE_LETTER = 1;

            /**
             * General category "Ll" in the Unicode specification.
             */
            static const byte LOWERCASE_LETTER = 2;

            /**
             * General category "Lt" in the Unicode specification.
             */
            static const byte TITLECASE_LETTER = 3;

            /**
             * General category "Lm" in the Unicode specification.
             */
            static const byte MODIFIER_LETTER = 4;

            /**
             * General category "Lo" in the Unicode specification.
             */
            static const byte OTHER_LETTER = 5;

            /**
             * General category "Mn" in the Unicode specification.
             */
            static const byte NON_SPACING_MARK = 6;

            /**
             * General category "Me" in the Unicode specification.
             */
            static const byte ENCLOSING_MARK = 7;

            /**
             * General category "Mc" in the Unicode specification.
             */
            static const byte COMBINING_SPACING_MARK = 8;

            /**
             * General category "Nd" in the Unicode specification.
             */
            static const byte DECIMAL_DIGIT_NUMBER = 9;

            /**
             * General category "Nl" in the Unicode specification.
             */
            static const byte LETTER_NUMBER = 10;

            /**
             * General category "No" in the Unicode specification.
             */
            static const byte OTHER_NUMBER = 11;

            /**
             * General category "Zs" in the Unicode specification.
             */
            static const byte SPACE_SEPARATOR = 12;

            /**
             * General category "Zl" in the Unicode specification.
             */
            static const byte LINE_SEPARATOR = 13;

            /**
             * General category "Zp" in the Unicode specification.
             */
            static const byte PARAGRAPH_SEPARATOR = 14;

            /**
             * General category "Cc" in the Unicode specification.
             */
            static const byte CONTROL = 15;

            /**
             * General category "Cf" in the Unicode specification.
             */
            static const byte FORMAT = 16;

            /**
             * General category "Co" in the Unicode specification.
             */
            static const byte PRIVATE_USE = 18;

            /**
             * General category "Cs" in the Unicode specification.
             */
            static const byte SURROGATE = 19;

            /**
             * General category "Pd" in the Unicode specification.
             */
            static const byte DASH_PUNCTUATION = 20;

            /**
             * General category "Ps" in the Unicode specification.
             */
            static const byte START_PUNCTUATION = 21;

            /**
             * General category "Pe" in the Unicode specification.
             */
            static const byte END_PUNCTUATION = 22;

            /**
             * General category "Pc" in the Unicode specification.
             */
            static const byte CONNECTOR_PUNCTUATION = 23;

            /**
             * General category "Po" in the Unicode specification.
             */
            static const byte OTHER_PUNCTUATION = 24;

            /**
             * General category "Sm" in the Unicode specification.
             */
            static const byte MATH_SYMBOL = 25;

            /**
             * General category "Sc" in the Unicode specification.
             */
            static const byte CURRENCY_SYMBOL = 26;

            /**
             * General category "Sk" in the Unicode specification.
             */
            static const byte MODIFIER_SYMBOL = 27;

            /**
             * General category "So" in the Unicode specification.
             */
            static const byte OTHER_SYMBOL = 28;

            /**
             * General category "Pi" in the Unicode specification.
             */
            static const byte INITIAL_QUOTE_PUNCTUATION = 29;

            /**
             * General category "Pf" in the Unicode specification.
             */
            static const byte FINAL_QUOTE_PUNCTUATION = 30;

            /**
             * Error flag. Use int (code point) to avoid confusion with U+FFFF.
             */
            static const int ERROR = 0xFFFFFFFF;

            /**
             * Undefined bidirectional character type.
             * Undefined char values have undefined directionality in the Unicode specification.
             */
            static const char DIRECTIONALITY_UNDEFINED = -1;

            /**
             * Strong bidirectional character type "L" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT = 0;

            /**
             * Strong bidirectional character type "R" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT = 1;

            /**
             * Strong bidirectional character type "AL" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC = 2;

            /**
             * Weak bidirectional character type "EN" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER = 3;

            /**
             * Weak bidirectional character type "ES" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR = 4;

            /**
             * Weak bidirectional character type "ET" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR = 5;

            /**
             * Weak bidirectional character type "AN" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_ARABIC_NUMBER = 6;

            /**
             * Weak bidirectional character type "CS" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR = 7;

            /**
             * Weak bidirectional character type "NSM" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_NONSPACING_MARK = 8;

            /**
             * Weak bidirectional character type "BN" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_BOUNDARY_NEUTRAL = 9;

            /**
             * Neutral bidirectional character type "B" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_PARAGRAPH_SEPARATOR = 10;

            /**
             * Neutral bidirectional character type "S" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_SEGMENT_SEPARATOR = 11;

            /**
             * Neutral bidirectional character type "WS" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_WHITESPACE = 12;

            /**
             * Neutral bidirectional character type "ON" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_OTHER_NEUTRALS = 13;

            /**
             * Strong bidirectional character type "LRE" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING = 14;

            /**
             * Strong bidirectional character type "LRO" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE = 15;

            /**
             * Strong bidirectional character type "RLE" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING = 16;

            /**
             * Strong bidirectional character type "RLO" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE = 17;

            /**
             * Weak bidirectional character type "PDF" in the Unicode specification.
             */
            static const byte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT = 18;

            /**
             * The minimum value of a Unicode high-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuD800'. A high-surrogate is also known as a leading-surrogate.
             */
            static const char16_t MIN_HIGH_SURROGATE = 0xD800;

            /**
             * The maximum value of a Unicode high-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDBFF'. A high-surrogate is also known as a leading-surrogate.
             */
            static const char16_t MAX_HIGH_SURROGATE = 0xDBFF;

            /**
             * The minimum value of a Unicode low-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDC00'. A low-surrogate is also known as a trailing-surrogate.
             */
            static const char16_t MIN_LOW_SURROGATE = 0xDC00;

            /**
             * The maximum value of a Unicode low-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDFFF'. A low-surrogate is also known as a trailing-surrogate.
             */
            static const char16_t MAX_LOW_SURROGATE = 0xDFFF;

            /**
             * The minimum value of a Unicode surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuD800'.
             */
            static const char16_t MIN_SURROGATE = MIN_HIGH_SURROGATE;

            /**
             * The maximum value of a Unicode surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDFFF'.
             */
            static const char16_t MAX_SURROGATE = MAX_LOW_SURROGATE;

            /**
             * The minimum value of a Unicode supplementary code point, constant U+10000.
             */
            static const int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;

            /**
             * The minimum value of a Unicode code point, constant U+0000.
             */
            static const int MIN_CODE_POINT = 0x000000;

            /**
             * The maximum value of a Unicode code point, constant U+10FFFF.
             */
            static const int MAX_CODE_POINT = 0x10FFFF;

        private:
            char16_t original;

        public:
            /**
             * Default constructor
             */
            Character();

            /**
             * Constructs a newly allocated Character object that represents the specified char value.
             *
             * @param original
             */
            Character(char16_t original);

            /**
             * Destructor
             */
            ~Character();

        private:
            /**
             * Returns the code point at the given index of the char array,
             * where only array elements with index less than limit can be used.
             * If the char value at the given index in the char array is in the high-surrogate range,
             * the following index is less than the limit,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             *
             * @param charArray
             * @param index
             * @param limit
             * @throw ArrayIndexOutOfBoundsException if index out of bounds
             * @return the Unicode code point at the given index
             */
            static int codePointAtImpl(const Array<char16_t> &charArray, int index, int limit);
            /**
             * Returns the code point preceding the given index of the char array,
             * where only array elements with index greater than or equal to start can be used.
             * If the char value at (index - 1) in the char array is in the low-surrogate range,
             * (index - 2) is not less than start, and the char value at (index - 2)
             * in the char array is in the high-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at (index - 1) is returned.
             *
             * @param charArray
             * @param index
             * @param start
             * @throw ArrayIndexOutOfBoundsException if index-1 out of bounds
             * @return the Unicode code point value before the given index.
             */
            static int codePointBeforeImpl(const Array<char16_t> &charArray, int index, int start);

            /**
             * Returns the number of Unicode code points in a subarray of the char array argument.
             * The offset argument is the index of the first char of the subarray and
             * the count argument specifies the length of the subarray in chars.
             * Unpaired surrogates within the subarray count as one code point each.
             *
             * @param charArray
             * @param offset
             * @param count
             * @return the number of Unicode code points in the specified subarray
             */
            static int codePointCountImpl(const Array<char16_t> &charArray, int offset, int count);

            /**
             * Returns the index within the given char subarray that is offset
             * from the given index by codePointOffset code points.
             * The start and count arguments specify a subarray of the char array.
             * Unpaired surrogates within the text range given by index
             * and codePointOffset count as one code point each.
             *
             * @param charArray
             * @param start
             * @param count
             * @param index
             * @param codePointOffset
             * @throw IndexOutOfBoundsException if start or count is negative,
             * or if start + count is larger than the length of the given array,
             * or if index is less than start or larger then start + count,
             * or if codePointOffset is positive and the text range starting with index
             * and ending with start + count - 1 has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the text range starting with start
             * and ending with index - 1 has fewer than the absolute value of codePointOffset code points.
             * @return the index within the subarray
             */
            static int offsetByCodePointsImpl(const Array<char16_t> &charArray, int start, int count, int index, int codePointOffset);

            /**
             * Assign the char at index and index + 1 of the char array to make a surrogates
             *
             * @param codePoint
             * @param charArray
             * @param index
             */
            static void toSurrogates(int codePoint, Array<char16_t> &charArray, int index);

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using case mapping information from the SpecialCasing file in the Unicode specification.
             * If a character has no explicit uppercase mapping, then the char itself is returned in the char[].
             *
             * @param codePoint
             * @return a char array with the uppercased character
             */
            Array<char16_t> toUpperCaseCharArray(int codePoint) const;

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using information from the UnicodeData file.
             *
             * @param codePoint
             * @return either the uppercase equivalent of the character, if any,
             * or an error flag (Character.ERROR) that indicates that a 1:M char mapping exists.
             */
            static int toUpperCaseEx(int codePoint);

        public:
            /**
             * Determines the number of char values needed to represent the specified character (Unicode code point).
             *
             * @param codePoint
             * @return If the specified character is equal to or greater than 0x10000,
             * then the method returns 2. Otherwise, the method returns 1.
             */
            int charCount(int codePoint) const;

            /**
             * Returns the value of this Character object.
             * @return the primitive char value represented by this object.
             */
            char16_t charValue() const;

            /**
             * Returns the code point at the given index of the CharSequence.
             * If the char value at the given index in the CharSequence is in the high-surrogate range,
             * the following index is less than the length of the CharSequence,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             * @param sequence
             * @param index
             * @throw IndexOutOfBoundsException if the value index is negative or not less than seq.length().
             * @return the Unicode code point at the given index
             */
            static int codePointAt(CharSequence &sequence, int index) ;

            /**
             * Returns the code point at the given index of the char array.
             * If the char value at the given index in the char array is in the high-surrogate range,
             * the following index is less than the length of the char array,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             *
             * @param charArray
             * @param index
             * @throw IndexOutOfBoundsException if the value index is negative
             * or not less than the length of the char array.
             * @return the Unicode code point at the given index
             */
            static int codePointAt(const Array<char16_t> &charArray, int index) ;

            /**
             * Returns the code point at the given index of the char array,
             * where only array elements with index less than limit can be used.
             * If the char value at the given index in the char array is in the high-surrogate range,
             * the following index is less than the limit,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             *
             * @param charArray
             * @param index
             * @param limit
             * @throw IndexOutOfBoundsException if the index argument is negative
             * or not less than the limit argument,
             * or if the limit argument is negative or greater than the length of the char array.
             * @return the Unicode code point at the given index
             */
            static int codePointAt(const Array<char16_t> &charArray, int index, int limit) ;

            /**
             * Returns the code point preceding the given index of the CharSequence.
             * If the char value at (index - 1) in the CharSequence is in the low-surrogate range,
             * (index - 2) is not negative, and the char value at (index - 2)
             * in the CharSequence is in the high-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at (index - 1) is returned.
             *
             * @param sequence
             * @param index
             * @throw IndexOutOfBoundsException if the index argument is less than 1
             * or greater than CharSequence.length().
             * @return the Unicode code point value before the given index.
             */
            static int codePointBefore(CharSequence &sequence, int index);

            /**
             * Returns the code point preceding the given index of the char array.
             * If the char value at (index - 1) in the char array is in the low-surrogate range,
             * (index - 2) is not negative, and the char value at (index - 2) in the char array
             * is in the high-surrogate range, then the supplementary code point corresponding
             * to this surrogate pair is returned. Otherwise, the char value at (index - 1) is returned.
             *
             * @param charArray
             * @param index
             * @throw IndexOutOfBoundsException if the index argument is less than 1
             * or greater than the length of the char array
             * @return the Unicode code point value before the given index.
             */
            static int codePointBefore(const Array<char16_t> &charArray, int index);

            /**
             * Returns the code point preceding the given index of the char array,
             * where only array elements with index greater than or equal to start can be used.
             * If the char value at (index - 1) in the char array is in the low-surrogate range,
             * (index - 2) is not less than start, and the char value at (index - 2)
             * in the char array is in the high-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at (index - 1) is returned.
             *
             * @param charArray
             * @param index
             * @param start
             * @throw IndexOutOfBoundsException if the index argument is not greater
             * than the start argument or is greater than the length of the char array,
             * or if the start argument is negative or not less than the length of the char array.
             * @return the Unicode code point value before the given index.
             */
            static int codePointBefore(const Array<char16_t> &charArray, int index, int start);

            /**
             * Returns the number of Unicode code points in a subarray of the char array argument.
             * The offset argument is the index of the first char of the subarray
             * and the count argument specifies the length of the subarray in chars.
             * Unpaired surrogates within the subarray count as one code point each.
             *
             * @param charArray
             * @param offset
             * @param count
             * @throw IndexOutOfBoundsException if offset or count is negative,
             * or if offset + count is larger than the length of the given array.
             * @return the number of Unicode code points in the specified subarray
             */
            static int codePointCount(const Array<char16_t> &charArray, int offset, int count) ;

            /**
             * Returns the number of Unicode code points in the text range of the specified char sequence.
             * The text range begins at the specified beginIndex and extends to the char at index endIndex - 1.
             * Thus the length (in chars) of the text range is endIndex-beginIndex.
             * Unpaired surrogates within the text range count as one code point each.
             *
             * @param sequence
             * @param beginIndex
             * @param endIndex
             * @throw IndexOutOfBoundsException if the beginIndex is negative,
             * or endIndex is larger than the length of the given sequence,
             * or beginIndex is larger than endIndex.
             * @return the number of Unicode code points in the specified text range
             */
            static int codePointCount(CharSequence &sequence, int beginIndex, int endIndex) ;

            /**
             * Compares two char values numerically.
             *
             * @param charA
             * @param charB
             * @return the value 0 if charA == charB; a value less than 0 if charA < charB;
             * and a value greater than 0 if charA > charB.
             */
            static int compare(char16_t charA, char16_t charB) ;

            /**
             * Compares two Character objects numerically.
             * @param anotherCharacter
             * @return the value 0 if the argument Character is equal to this Character;
             * a value less than 0 if this Character is numerically less than the Character argument;
             * and a value greater than 0 if this Character is numerically greater than the Character argument
             */
            int compareTo(const Character &anotherCharacter) const;

            /**
             * Returns the numeric value of the character in the specified radix.
             *
             * @param character
             * @param radix
             * @return the numeric value represented by the character in the specified radix.
             */
            static int digit(char16_t character, int radix) ;

            /**
             * Returns the numeric value of the specified character (Unicode code point) in the specified radix.
             *
             * @param codePoint
             * @param radix
             * @return the numeric value represented by the character in the specified radix.
             */
            static int digit(int codePoint, int radix) ;

            /**
             * Compares this object against the specified object. The result is true if and only if t
             * he argument is not null and is a Character object that represents the same char value
             * as this object.
             *
             * @param object
             * @return true if the objects are the same; false otherwise.
             */
            // TODO (anhnt) instanceof return false, use Character instead.
            boolean equals(const Character &object) const;

            /**
             * Determines the character representation for a specific digit in the specified radix.
             * If the value of radix is not a valid radix,
             * or the value of digit is not a valid digit in the specified radix,
             * the null character ('\u005Cu0000') is returned.
             *
             * @param digit
             * @param radix
             * @return the char representation of the specified digit in the specified radix.
             */
            static char16_t forDigit(int digit, int radix);

            /**
             * Returns the Unicode directionality property for the given character (Unicode code point).
             * Character directionality is used to calculate the visual ordering of text.
             *
             * @param codePoint
             * @return the directionality property of the character.
             */
            static byte getDirectionality(int codePoint) ;

            /**
             * Returns the Unicode directionality property for the given character.
             * Character directionality is used to calculate the visual ordering of text.
             *
             * @param character
             * @return the directionality property of the char value.
             */
            static byte getDirectionality(char16_t character) ;

            /**
             * Returns the Unicode name of the specified character codePoint,
             * or null if the code point is unassigned.
             * Note: if the specified character is not assigned a name by the UnicodeData file
             * (part of the Unicode Character Database maintained by the Unicode Consortium),
             * the returned name is the same as the result of expression.
             *
             * @param codePoint
             * @throw IllegalArgumentException if the specified codePoint is not a valid Unicode code point.
             * @return the Unicode name of the specified character, or null if the code point is unassigned.
             */
            static String getName(int codePoint) ;

            /**
             * Returns the int value that the specified character (Unicode code point) represents.
             *
             * @param codePoint
             * @return the numeric value of the character, as a nonnegative int value;
             * -2 if the character has a numeric value that is not a nonnegative integer;
             * -1 if the character has no numeric value.
             */
            static int getNumericValue(int codePoint) ;

            /**
             * Returns the int value that the specified Unicode character represents.
             *
             * @param character
             * @return the numeric value of the character, as a nonnegative int value;
             * -2 if the character has a numeric value that is not a nonnegative integer;
             * -1 if the character has no numeric value.
             */
            static int getNumericValue(char16_t character) ;

            /**
             * Returns a value indicating a character's general category.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the getType(int) method.
             *
             * @param character
             * @return a value of type int representing the character's general category.
             */
            static int getType(char16_t character) ;

            /**
             * Returns a value indicating a character's general category.
             *
             * @param codePoint
             * @return a value of type int representing the character's general category.
             */
            static int getType(int codePoint) ;

            /**
             * Returns a hash code for this Character; equal to the result of invoking charValue().
             *
             * @return a hash code for this Character
             */
            long hashCode() const override;

            /**
             * Returns a hash code for a char value; compatible with Character.hashCode().
             *
             * @param value
             * @return a hash code for a char value
             */
            static long hashCode(char16_t value) ;

            /**
             * Returns the leading surrogate (a high surrogate code unit) of the surrogate pair
             * representing the specified supplementary character (Unicode code point) in the UTF-16 encoding.
             * If the specified character is not a supplementary character, an unspecified char is returned.
             *
             * @param codePoint
             * @return the leading surrogate code unit used to represent the character in the UTF-16 encoding
             */
            static char16_t highSurrogate(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is an alphabet.
             *
             * @param codePoint
             * @return true if the character is a Unicode alphabet character, false otherwise.
             */
            static boolean isAlphabetic(int codePoint) ;

            /**
             * Determines whether the specified character (Unicode code point)
             * is in the Basic Multilingual Plane (BMP).
             * Such code points can be represented using a single char.
             *
             * @param codePoint
             * @return true if the specified code point is between MIN_VALUE and MAX_VALUE inclusive;
             * false otherwise.
             */
            static boolean isBmpCodePoint(int codePoint) ;

            /**
             * Determines if a character is defined in Unicode.
             * A character is defined if at least one of the following is true:
             *      - It has an entry in the UnicodeData file.
             *      - It has a value in a range defined by the UnicodeData file.
             * Note: This method cannot handle supplementary characters. To support all Unicode characters,
             * including supplementary characters, use the isDefined(int) method.
             *
             * @param character
             * @return true if the character has a defined meaning in Unicode; false otherwise.
             */
            static boolean isDefined(char16_t character) ;

            /**
             * Determines if a character is defined in Unicode.
             * A character is defined if at least one of the following is true:
             *      - It has an entry in the UnicodeData file.
             *      - It has a value in a range defined by the UnicodeData file.
             * Note: This method cannot handle supplementary characters. To support all Unicode characters,
             * including supplementary characters, use the isDefined(int) method.
             *
             * @param codePoint
             * @return true if the character has a defined meaning in Unicode; false otherwise.
             */
            static boolean isDefined(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a digit.
             *
             * @param codePoint
             * @return Determines if the specified character (Unicode code point) is a digit.
             */
            static boolean isDigit(int codePoint) ;

            /**
             * Determines if the specified character is a digit.
             *
             * @param character
             * @return true if the character is a digit; false otherwise.
             */
            static boolean isDigit(char16_t character) ;

            /**
             * Determines if the given char value is a Unicode high-surrogate
             * code unit (also known as leading-surrogate code unit).
             * Such values do not represent characters by themselves,
             * but are used in the representation of supplementary characters in the UTF-16 encoding.
             *
             * @param character
             * @return true if the char value is between MIN_HIGH_SURROGATE
             * and MAX_HIGH_SURROGATE inclusive; false otherwise.
             */
            static boolean isHighSurrogate(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point) should be regarded
             * as an ignorable character in a Java identifier or a Unicode identifier.
             *
             * @param codePoint
             * @return true if the character is an ignorable control character
             * that may be part of a Java or Unicode identifier; false otherwise.
             */
            static boolean isIdentifierIgnorable(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) should be regarded
             * as an ignorable character in a Java identifier or a Unicode identifier.
             *
             * @param character
             * @return true if the character is an ignorable control character
             * that may be part of a Java or Unicode identifier; false otherwise.
             */
            static boolean isIdentifierIgnorable(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point)
             * is a CJKV (Chinese, Japanese, Korean and Vietnamese) ideograph,
             * as defined by the Unicode Standard.
             *
             * @param codePoint
             * @return true if the character is a Unicode ideograph character, false otherwise.
             */
            static boolean isIdeographic(int codePoint) ;

            /**
             * Determines if the specified character is an ISO control character.
             * A character is considered to be an ISO control character
             * if its code is in the range '\u005Cu0000' through '\u005Cu001F'
             * or in the range '\u005Cu007F' through '\u005Cu009F'.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isISOControl(int) method.
             *
             * @param character
             * @return true if the character is an ISO control character; false otherwise.
             */
            static boolean isISOControl(char16_t character) ;

            /**
             * Determines if the specified character is an ISO control character.
             * A character is considered to be an ISO control character
             * if its code is in the range '\u005Cu0000' through '\u005Cu001F'
             * or in the range '\u005Cu007F' through '\u005Cu009F'.
             *
             * @param codePoint
             * @return true if the character is an ISO control character; false otherwise.
             */
            static boolean isISOControl(int codePoint) ;

            /**
             * Determines if the specified character may be part
             * of a Java identifier as other than the first character.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isJavaIdentifierPart(int) method.
             *
             * @param character
             * @return true if the character may be part of a Java identifier; false otherwise.
             */
            static boolean isJavaIdentifierPart(char16_t character) ;

            /**
             * Determines if the specified character may be part
             * of a Java identifier as other than the first character.
             *
             * @param codePoint
             * @return true if the character may be part of a Java identifier; false otherwise.
             */
            static boolean isJavaIdentifierPart(int codePoint) ;

            /**
             * Determines if the specified character is permissible
             * as the first character in a Java identifier.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isJavaIdentifierStart(int) method.
             *
             * @param character
             * @return true if the character may start a Java identifier; false otherwise.
             */
            static boolean isJavaIdentifierStart(char16_t character) ;

            /**
            * Determines if the specified character is permissible
            * as the first character in a Java identifier.
            *
            * @param codePoint
            * @return true if the character may start a Java identifier; false otherwise.
            */
            static boolean isJavaIdentifierStart(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a letter.
             *
             * @param codePoint
             * @return Determines if the specified character (Unicode code point) is a letter.
             */
            static boolean isLetter(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a letter.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isLetter(int) method.
             *
             * @param codePoint
             * @return Determines if the specified character (Unicode code point) is a letter.
             */
            static boolean isLetter(char16_t character) ;

            /**
             * Determines if the specified character is a letter or digit.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isLetterOrDigit(int) method.
             *
             * @param character
             * @return true if the character is a letter or digit; false otherwise.
             */
            static boolean isLetterOrDigit(char16_t character) ;

            /**
            * Determines if the specified character is a letter or digit.
            *
            * @param codePoint
            * @return true if the character is a letter or digit; false otherwise.
            */
            static boolean isLetterOrDigit(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a lowercase character.
             * A character is lowercase if its general category type, provided by getType(codePoint),
             * is LOWERCASE_LETTER, or it has contributory property Other_Lowercase as defined by the Unicode Standard.
             *
             * @param codePoint
             * @return true if the character is lowercase; false otherwise.
             */
            static boolean isLowerCase(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a lowercase character.
             * A character is lowercase if its general category type, provided by getType(codePoint),
             * is LOWERCASE_LETTER, or it has contributory property Other_Lowercase as defined by the Unicode Standard.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isLowerCase(int) method.
             *
             * @param character
             * @return true if the character is lowercase; false otherwise.
             */
            static boolean isLowerCase(char16_t character) ;

            /**
             * Determines if the given char value is a Unicode low-surrogate
             * code unit (also known as trailing-surrogate code unit).
             * Such values do not represent characters by themselves,
             * but are used in the representation of supplementary characters in the UTF-16 encoding.
             *
             * @param character
             * @return true if the char value is between MIN_LOW_SURROGATE
             * and MAX_LOW_SURROGATE inclusive; false otherwise.
             */
            static boolean isLowSurrogate(char16_t character) ;

            /**
             * Determines whether the character is mirrored according to the Unicode specification.
             * Mirrored characters should have their glyphs horizontally mirrored when displayed in text
             * that is right-to-left. For example, '\u005Cu0028' LEFT PARENTHESIS is semantically defined to
             * be an opening parenthesis. This will appear as a "(" in text that is left-to-right but as a ")"
             * in text that is right-to-left.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isMirrored(int) method.
             *
             * @param character
             * @return true if the char is mirrored, false if the char is not mirrored or is not defined.
             */
            static boolean isMirrored(char16_t character) ;

            /**
             * Determines whether the character is mirrored according to the Unicode specification.
             * Mirrored characters should have their glyphs horizontally mirrored when displayed in text
             * that is right-to-left. For example, '\u005Cu0028' LEFT PARENTHESIS is semantically defined to
             * be an opening parenthesis. This will appear as a "(" in text that is left-to-right but as a ")"
             * in text that is right-to-left.
             *
             * @param codePoint
             * @return true if the char is mirrored, false if the char is not mirrored or is not defined.
             */
            static boolean isMirrored(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a Unicode space character.
             * A character is considered to be a space character if and only if
             * it is specified to be a space character by the Unicode Standard.
             *
             * @param codePoint
             * @return true if the character is a space character; false otherwise.
             */
            static boolean isSpaceChar(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a Unicode space character.
             * A character is considered to be a space character if and only if
             * it is specified to be a space character by the Unicode Standard.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isSpaceChar(int) method.
             *
             * @param character
             * @return true if the character is a space character; false otherwise.
             */
            static boolean isSpaceChar(char16_t character) ;

            /**
             * Determines whether the specified character (Unicode code point)
             * is in the supplementary character range.
             *
             * @param codePoint
             * @return true if the specified code point is between MIN_SUPPLEMENTARY_CODE_POINT
             * and MAX_CODE_POINT inclusive; false otherwise.
             */
            static boolean isSupplementaryCodePoint(int codePoint) ;

            /**
             * Determines if the given char value is a Unicode surrogate code unit.
             * Such values do not represent characters by themselves, but are used in
             * the representation of supplementary characters in the UTF-16 encoding.
             * A char value is a surrogate code unit if and only if it is either
             * a low-surrogate code unit or a high-surrogate code unit.
             *
             * @param character
             * @return true if the char value is between MIN_SURROGATE and MAX_SURROGATE inclusive;
             * false otherwise.
             */
            static boolean isSurrogate(char16_t character) ;

            /**
             * Determines whether the specified pair of char values is a valid Unicode surrogate pair.
             *
             * @param high
             * @param low
             * @return Determines whether the specified pair of char values is a valid Unicode surrogate pair.
             */
            static boolean isSurrogatePair(char16_t high, char16_t low) ;

            /**
             * Determines if the specified character (Unicode code point) is a titlecase character.
             *
             * @param codePoint
             * @return true if the character is titlecase; false otherwise.
             */
            static boolean isTitleCase(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is a titlecase character.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isTitleCase(int) method.
             *
             * @param character
             * @return true if the character is titlecase; false otherwise.
             */
            static boolean isTitleCase(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point) may be part of
             * a Unicode identifier as other than the first character.
             *
             * @param codePoint
             * @return true if the character may be part of a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierPart(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) may be part of
             * a Unicode identifier as other than the first character.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isUnicodeIdentifierPart(int) method.
             *
             * @param character
             * @return true if the character may be part of a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierPart(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point) is permissible
             * as the first character in a Unicode identifier.
             *
             * @param codePoint
             * @return true if the character may start a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierStart(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point) is permissible
             * as the first character in a Unicode identifier.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isUnicodeIdentifierStart(int) method.
             * @param character
             * @return true if the character may start a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierStart(char16_t character) ;

            /**
             * Determines if the specified character (Unicode code point) is an uppercase character.
             *
             * @param character
             * @return true if the character is uppercase; false otherwise.
             */
            static boolean isUpperCase(int character) ;

            /**
            * Determines if the specified character (Unicode code point) is an uppercase character.
            * Note: This method cannot handle supplementary characters.
            * To support all Unicode characters, including supplementary characters,
            * use the isUpperCase(int) method.
            *
            * @param character
            * @return true if the character is uppercase; false otherwise.
            */
            static boolean isUpperCase(char16_t character) ;

            /**
             * Determines whether the specified code point is a valid Unicode code point value.
             *
             * @param codePoint
             * @return true if the specified code point value is between MIN_CODE_POINT
             * and MAX_CODE_POINT inclusive; false otherwise.
             */
            static boolean isValidCodePoint(int codePoint) ;

            /**
             * Determines if the specified character is white space according to Java.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the isWhitespace(int) method.
             *
             * @param character
             * @return true if the character is a Java whitespace character; false otherwise.
             */
            static boolean isWhitespace(char16_t character) ;

            /**
             * Determines if the specified character is white space according to Java.
             *
             * @param codePoint
             * @return true if the character is a Java whitespace character; false otherwise.
             */
            static boolean isWhitespace(int codePoint) ;

            /**
             * Returns the trailing surrogate (a low surrogate code unit) of the surrogate pair
             * representing the specified supplementary character (Unicode code point) in the UTF-16 encoding.
             * If the specified character is not a supplementary character, an unspecified char is returned.
             *
             * @param codePoint
             * @return the trailing surrogate code unit used to represent the character in the UTF-16 encoding
             */
            static char16_t lowSurrogate(int codePoint);
            /**
             * Returns the index within the given char sequence that is offset
             * from the given index by codePointOffset code points.
             * Unpaired surrogates within the text range given by index
             * and codePointOffset count as one code point each.
             *
             * @param sequence
             * @param index
             * @param codePointOffset
             * @throw IndexOutOfBoundsException if index is negative or larger than
             * the length of the char sequence, or if codePointOffset is positive
             * and the subsequence starting with index has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the subsequence before index has fewer than
             * the absolute value of codePointOffset code points.
             * @return the index within the char sequence
             */
            static int offsetByCodePoints(CharSequence &sequence, int index, int codePointOffset) ;

            /**
             * Returns the index within the given char subarray that is offset
             * from the given index by codePointOffset code points.
             * The start and count arguments specify a subarray of the char array.
             * Unpaired surrogates within the text range given by index
             * and codePointOffset count as one code point each.
             *
             * @param charArray
             * @param start
             * @param count
             * @param index
             * @param codePointOffset
             * @throw IndexOutOfBoundsException if start or count is negative,
             * or if start + count is larger than the length of the given array,
             * or if index is less than start or larger then start + count,
             * or if codePointOffset is positive and the text range starting with index
             * and ending with start + count - 1 has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the text range starting with start
             * and ending with index - 1 has fewer than the absolute value of codePointOffset code points.
             * @return the index within the subarray
             */
            static int offsetByCodePoints(const Array<char16_t> &charArray, int start, int count, int index, int codePointOffset) ;

            /**
             * Returns the value obtained by reversing the order of the bytes
             * in the specified char value.
             *
             * @param character
             * @return the value obtained by reversing (or, equivalently, swapping)
             * the bytes in the specified char value.
             */
            static char reverseBytes(char16_t character) ;

            /**
             * Converts the specified character (Unicode code point) to its UTF-16
             * representation stored in a char array.
             * If the specified code point is a BMP (Basic Multilingual Plane or Plane 0) value,
             * the resulting char array has the same value as codePoint.
             * If the specified code point is a supplementary code point,
             * the resulting char array has the corresponding surrogate pair.
             *
             * @param codePoint
             * @throw IllegalArgumentException if the specified codePoint
             * is not a valid Unicode code point.
             * @return a char array having codePoint's UTF-16 representation.
             */
            static const Array<char16_t> & toChars(int codePoint) ;

            /**
             * Converts the specified character (Unicode code point) to its UTF-16 representation.
             * If the specified code point is a BMP (Basic Multilingual Plane or Plane 0) value,
             * the same value is stored in dst[dstIndex], and 1 is returned.
             * If the specified code point is a supplementary character,
             * its surrogate values are stored in dst[dstIndex] (high-surrogate)
             * and dst[dstIndex+1] (low-surrogate), and 2 is returned.
             *
             * @param codePoint
             * @param destination
             * @param destinationIndex
             * @throw IllegalArgumentException if the specified codePoint
             * is not a valid Unicode code point.
             * @throw IndexOutOfBoundsException if dstIndex is negative or not less than dst.length,
             * or if dst at dstIndex doesn't have enough array element(s) to store the resulting char value(s).
             * (If dstIndex is equal to dst.length-1 and the specified codePoint is a supplementary character,
             * the high-surrogate value is not stored in dst[dstIndex].)
             * @return 1 if the code point is a BMP code point,
             * 2 if the code point is a supplementary code point.
             */
            static int toChars(int codePoint, Array<char16_t> &destination, int destinationIndex) ;

            /**
             * Converts the specified surrogate pair to its supplementary code point value.
             * This method does not validate the specified surrogate pair.
             *
             * @param high
             * @param low
             * @return the supplementary code point composed from the specified surrogate pair.
             */
            static int toCodePoint(char16_t high, char16_t low) ;

            /**
             * Converts the character (Unicode code point) argument to lowercase using
             * case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return the lowercase equivalent of the character (Unicode code point), if any;
             * otherwise, the character itself.
             */
            static int toLowerCase(int codePoint) ;

            /**
             * Converts the character (Unicode code point) argument to lowercase using
             * case mapping information from the UnicodeData file.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the toLowerCase(int) method.
             *
             * @param character
             * @return the lowercase equivalent of the character (Unicode code point), if any;
             * otherwise, the character itself.
             */
            static int toLowerCase(char16_t character) ;

            /**
             * Returns a String object representing this Character's value.
             * The result is a string of length 1 whose sole component is the primitive char value
             * represented by this Character object.
             *
             * @return a string representation of this object.
             */
            string toString() const;

            /**
             * Returns a String object representing the specified char.
             * The result is a string of length 1 consisting solely of the specified char.
             *
             * @return a string representation of the specified char.
             */
            static string toString(char16_t character) ;

            /**
             * Converts the character (Unicode code point) argument to titlecase
             * using case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return the titlecase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toTitleCase(int codePoint) ;

            /**
             * Converts the character (Unicode code point) argument to titlecase
             * using case mapping information from the UnicodeData file.
             *
             * @param character
             * @return the titlecase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toTitleCase(char16_t character) ;

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return the uppercase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toUpperCase(int codePoint) ;

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using case mapping information from the UnicodeData file.
             * Note: This method cannot handle supplementary characters.
             * To support all Unicode characters, including supplementary characters,
             * use the toUpperCase(int) method.
             *
             * @param character
             * @return the uppercase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toUpperCase(char16_t character) ;

            /**
             * Returns a Character instance representing the specified char value.
             * If a  Character instance is not required,
             * this method should generally be used in preference to the constructor Character(char),
             * as this method is likely to yield significantly better space
             * and time performance by caching frequently requested values.
             * This method will always cache values in the range '\u005Cu0000' to '\u005Cu007F',
             * inclusive, and may cache other values outside of this range.
             *
             * @param character
             * @return a Character instance representing character.
             */
            static Character valueOf(char16_t character) ;

        public:
            friend std::ostream &operator<<(std::ostream &os, const Character &target);
        };  // class Character
    }  // namespace Lang
}  // namespace Java

#endif  // NATIVE_JAVA_LANG_CHARACTER_HPP_
