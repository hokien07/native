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
        class Character : public Object,
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

                    Subset(){
                        this->name = "";
                    };

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
                };  // class Subset

            class UnicodeBlock : public Subset {

            private:
                static HashMap<String, UnicodeBlock> map;

            public:
                /**
                 * Default constructor
                 */
                UnicodeBlock() {};

                /**
                 * Create a UnicodeBlock with a String
                 *
                 * @param name
                 */
                UnicodeBlock(const String &name);

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

                /**
                 *
                 *
                 * @param leftValue
                 * @return
                 */
                boolean operator==(const UnicodeBlock &leftValue) const;

            public:
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
                static UnicodeBlock PHAISTOS_DISC;

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

            private:
                static Array<int> blockStarts;

                static Array<UnicodeBlock> blocks;

            public:
                /**
                 * Returns the object representing the Unicode block containing the
                 * given character
                 *
                 * @param character
                 * @return The UnicodeBlock instance representing the
                 * Unicode block of which this character is a member, or null
                 * if the character is not a member of any Unicode block
                 */
                static UnicodeBlock of(char character);

                /**
                 * Returns the object representing the Unicode block
                 * containing the given character
                 *
                 * @param codePoint
                 * @throw IllegalArgumentException if the specified
                 * codePoint is an invalid Unicode code point.
                 * @return Returns the object representing the Unicode block
                 * containing the given character
                 */
                static UnicodeBlock of(int codePoint);

                /**
                 * Returns the UnicodeBlock with the given name. Block
                 * names are determined by The Unicode Standard.
                 *
                 * @param blockName
                 * @throw IllegalArgumentException if the specified
                 * codePoint is an invalid Unicode code point.
                 * @return Returns the object representing the Unicode block
                 * containing the given character
                 */
                static UnicodeBlock forName(String blockName);
            };  // class UnicodeBlock

            class UnicodeScript {

                enum Script {
                    /**
                     * Unicode script "Common".
                     */
                            COMMON = 1,

                    /**
                     * Unicode script "Latin".
                     */
                            LATIN,

                    /**
                     * Unicode script "Greek".
                     */
                            GREEK,

                    /**
                     * Unicode script "Cyrillic".
                     */
                            CYRILLIC,

                    /**
                     * Unicode script "Armenian".
                     */
                            ARMENIAN,

                    /**
                     * Unicode script "Hebrew".
                     */
                            HEBREW,

                    /**
                     * Unicode script "Arabic".
                     */
                            ARABIC,

                    /**
                     * Unicode script "Syriac".
                     */
                            SYRIAC,

                    /**
                     * Unicode script "Thaana".
                     */
                            THAANA,

                    /**
                     * Unicode script "Devanagari".
                     */
                            DEVANAGARI,

                    /**
                     * Unicode script "Bengali".
                     */
                            BENGALI,

                    /**
                     * Unicode script "Gurmukhi".
                     */
                            GURMUKHI,

                    /**
                     * Unicode script "Gujarati".
                     */
                            GUJARATI,

                    /**
                     * Unicode script "Oriya".
                     */
                            ORIYA,

                    /**
                     * Unicode script "Tamil".
                     */
                            TAMIL,

                    /**
                     * Unicode script "Telugu".
                     */
                            TELUGU,

                    /**
                     * Unicode script "Kannada".
                     */
                            KANNADA,

                    /**
                     * Unicode script "Malayalam".
                     */
                            MALAYALAM,

                    /**
                     * Unicode script "Sinhala".
                     */
                            SINHALA,

                    /**
                     * Unicode script "Thai".
                     */
                            THAI,

                    /**
                     * Unicode script "Lao".
                     */
                            LAO,

                    /**
                     * Unicode script "Tibetan".
                     */
                            TIBETAN,

                    /**
                     * Unicode script "Myanmar".
                     */
                            MYANMAR,

                    /**
                     * Unicode script "Georgian".
                     */
                            GEORGIAN,

                    /**
                     * Unicode script "Hangul".
                     */
                            HANGUL,

                    /**
                     * Unicode script "Ethiopic".
                     */
                            ETHIOPIC,

                    /**
                     * Unicode script "Cherokee".
                     */
                            CHEROKEE,

                    /**
                     * Unicode script "Canadian_Aboriginal".
                     */
                            CANADIAN_ABORIGINAL,

                    /**
                     * Unicode script "Ogham".
                     */
                            OGHAM,

                    /**
                     * Unicode script "Runic".
                     */
                            RUNIC,

                    /**
                     * Unicode script "Khmer".
                     */
                            KHMER,

                    /**
                     * Unicode script "Mongolian".
                     */
                            MONGOLIAN,

                    /**
                     * Unicode script "Hiragana".
                     */
                            HIRAGANA,

                    /**
                     * Unicode script "Katakana".
                     */
                            KATAKANA,

                    /**
                     * Unicode script "Bopomofo".
                     */
                            BOPOMOFO,

                    /**
                     * Unicode script "Han".
                     */
                            HAN,

                    /**
                     * Unicode script "Yi".
                     */
                            YI,

                    /**
                     * Unicode script "Old_Italic".
                     */
                            OLD_ITALIC,

                    /**
                     * Unicode script "Gothic".
                     */
                            GOTHIC,

                    /**
                     * Unicode script "Deseret".
                     */
                            DESERET,

                    /**
                     * Unicode script "Inherited".
                     */
                            INHERITED,

                    /**
                     * Unicode script "Tagalog".
                     */
                            TAGALOG,

                    /**
                     * Unicode script "Hanunoo".
                     */
                            HANUNOO,

                    /**
                     * Unicode script "Buhid".
                     */
                            BUHID,

                    /**
                     * Unicode script "Tagbanwa".
                     */
                            TAGBANWA,

                    /**
                     * Unicode script "Limbu".
                     */
                            LIMBU,

                    /**
                     * Unicode script "Tai_Le".
                     */
                            TAI_LE,

                    /**
                     * Unicode script "Linear_B".
                     */
                            LINEAR_B,

                    /**
                     * Unicode script "Ugaritic".
                     */
                            UGARITIC,

                    /**
                     * Unicode script "Shavian".
                     */
                            SHAVIAN,

                    /**
                     * Unicode script "Osmanya".
                     */
                            OSMANYA,

                    /**
                     * Unicode script "Cypriot".
                     */
                            CYPRIOT,

                    /**
                     * Unicode script "Braille".
                     */
                            BRAILLE,

                    /**
                     * Unicode script "Buginese".
                     */
                            BUGINESE,

                    /**
                     * Unicode script "Coptic".
                     */
                            COPTIC,

                    /**
                     * Unicode script "New_Tai_Lue".
                     */
                            NEW_TAI_LUE,

                    /**
                     * Unicode script "Glagolitic".
                     */
                            GLAGOLITIC,

                    /**
                     * Unicode script "Tifinagh".
                     */
                            TIFINAGH,

                    /**
                     * Unicode script "Syloti_Nagri".
                     */
                            SYLOTI_NAGRI,

                    /**
                     * Unicode script "Old_Persian".
                     */
                            OLD_PERSIAN,

                    /**
                     * Unicode script "Kharoshthi".
                     */
                            KHAROSHTHI,

                    /**
                     * Unicode script "Balinese".
                     */
                            BALINESE,

                    /**
                     * Unicode script "Cuneiform".
                     */
                            CUNEIFORM,

                    /**
                     * Unicode script "Phoenician".
                     */
                            PHOENICIAN,

                    /**
                     * Unicode script "Phags_Pa".
                     */
                            PHAGS_PA,

                    /**
                     * Unicode script "Nko".
                     */
                            NKO,

                    /**
                     * Unicode script "Sundanese".
                     */
                            SUNDANESE,

                    /**
                     * Unicode script "Batak".
                     */
                            BATAK,

                    /**
                     * Unicode script "Lepcha".
                     */
                            LEPCHA,

                    /**
                     * Unicode script "Ol_Chiki".
                     */
                            OL_CHIKI,

                    /**
                     * Unicode script "Vai".
                     */
                            VAI,

                    /**
                     * Unicode script "Saurashtra".
                     */
                            SAURASHTRA,

                    /**
                     * Unicode script "Kayah_Li".
                     */
                            KAYAH_LI,

                    /**
                     * Unicode script "Rejang".
                     */
                            REJANG,

                    /**
                     * Unicode script "Lycian".
                     */
                            LYCIAN,

                    /**
                     * Unicode script "Carian".
                     */
                            CARIAN,

                    /**
                     * Unicode script "Lydian".
                     */
                            LYDIAN,

                    /**
                     * Unicode script "Cham".
                     */
                            CHAM,

                    /**
                     * Unicode script "Tai_Tham".
                     */
                            TAI_THAM,

                    /**
                     * Unicode script "Tai_Viet".
                     */
                            TAI_VIET,

                    /**
                     * Unicode script "Avestan".
                     */
                            AVESTAN,

                    /**
                     * Unicode script "Egyptian_Hieroglyphs".
                     */
                            EGYPTIAN_HIEROGLYPHS,

                    /**
                     * Unicode script "Samaritan".
                     */
                            SAMARITAN,

                    /**
                     * Unicode script "Mandaic".
                     */
                            MANDAIC,

                    /**
                     * Unicode script "Lisu".
                     */
                            LISU,

                    /**
                     * Unicode script "Bamum".
                     */
                            BAMUM,

                    /**
                     * Unicode script "Javanese".
                     */
                            JAVANESE,

                    /**
                     * Unicode script "Meetei_Mayek".
                     */
                            MEETEI_MAYEK,

                    /**
                     * Unicode script "Imperial_Aramaic".
                     */
                            IMPERIAL_ARAMAIC,

                    /**
                     * Unicode script "Old_South_Arabian".
                     */
                            OLD_SOUTH_ARABIAN,

                    /**
                     * Unicode script "Inscriptional_Parthian".
                     */
                            INSCRIPTIONAL_PARTHIAN,

                    /**
                     * Unicode script "Inscriptional_Pahlavi".
                     */
                            INSCRIPTIONAL_PAHLAVI,

                    /**
                     * Unicode script "Old_Turkic".
                     */
                            OLD_TURKIC,

                    /**
                     * Unicode script "Brahmi".
                     */
                            BRAHMI,

                    /**
                     * Unicode script "Kaithi".
                     */
                            KAITHI,

                    /**
                     * Unicode script "Meroitic Hieroglyphs".
                     */
                            MEROITIC_HIEROGLYPHS,

                    /**
                     * Unicode script "Meroitic Cursive".
                     */
                            MEROITIC_CURSIVE,

                    /**
                     * Unicode script "Sora Sompeng".
                     */
                            SORA_SOMPENG,

                    /**
                     * Unicode script "Chakma".
                     */
                            CHAKMA,

                    /**
                     * Unicode script "Sharada".
                     */
                            SHARADA,

                    /**
                     * Unicode script "Takri".
                     */
                            TAKRI,

                    /**
                     * Unicode script "Miao".
                     */
                            MIAO,

                    /**
                     * Unicode script "Unknown".
                     */
                            UNKNOWN,
                    /**
                     * Unicode script "default", for uninitallized script
                     */
                            DEFAULT
                };  // class UnicodeScript

            private:
                static HashMap<String, UnicodeScript> aliases;

            public:
                Script unicodeScript;

            public:
                UnicodeScript();

                UnicodeScript(Script script);

                UnicodeScript(String scriptName);

                boolean operator==(const UnicodeScript &otherUnicodeScript) const;

                static HashMap<String, UnicodeScript> aliasesInit();

                static Array<int> scriptStarts;

                static Array<UnicodeScript> scripts;

                static Array<String> scriptNames;

                /**
                 * Returns the enum constant representing the Unicode Script of which
                 * the given character (Unicode code point) is assigned to.
                 *
                 * @param codePoint
                 * @return The UnicodeScript constant representing the
                 * Unicode Script of which this character is assigned to.
                 */
                //static UnicodeScript of(int codePoint);

                /**
                 * Returns the UnicodeScript constant with the given UnicodeScript
                 * name or the UnicodeScript name alias. Script names and their aliases are
                 * determined by The Unicode Standard.
                 *
                 * @param scriptName
                 * @throw IllegalArgumentException if scriptName is an
                 *         invalid name
                 * @return Returns the Script constant with the given Unicode Script
                 * name or the Script name alias.
                 */
                static UnicodeScript forName(String scriptName);
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
            static const unicode MIN_VALUE = u'\u0000';

            /**
             * The constant value of this field is the largest value of type char
             */
            static const unicode MAX_VALUE = u'\uFFFF';

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
            static const unicode MIN_HIGH_SURROGATE = 0xD800;

            /**
             * The maximum value of a Unicode high-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDBFF'. A high-surrogate is also known as a leading-surrogate.
             */
            static const unicode MAX_HIGH_SURROGATE = 0xDBFF;

            /**
             * The minimum value of a Unicode low-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDC00'. A low-surrogate is also known as a trailing-surrogate.
             */
            static const unicode MIN_LOW_SURROGATE = 0xDC00;

            /**
             * The maximum value of a Unicode low-surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDFFF'. A low-surrogate is also known as a trailing-surrogate.
             */
            static const unicode MAX_LOW_SURROGATE = 0xDFFF;

            /**
             * The minimum value of a Unicode surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuD800'.
             */
            static const unicode MIN_SURROGATE = MIN_HIGH_SURROGATE;

            /**
             * The maximum value of a Unicode surrogate code unit in the UTF-16 encoding,
             * constant '\u005CuDFFF'.
             */
            static const unicode MAX_SURROGATE = MAX_LOW_SURROGATE;

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
            unicode original;

        public:
            /**
             * Default constructor.
             */
            Character();

            /**
             * Constructs a newly allocated Character object that
             * represents the specified char value.
             *
             * @param original
             */
            Character(unicode original);

            /**
             * Destructor.
             */
            virtual ~Character();

        public:
            /**
             * Determines the number of char values needed to represent
             * the specified character (Unicode code point).
             *
             * @param codePoint
             * @return int
             */
            int charCount(int codePoint) const;

            /**
             * Returns the value of this Character object.
             *
             * @return unicode
             */
            unicode charValue() const;

            /**
             *
             * @param anotherCharacter
             * @return
             */
            int compareTo(const Character &anotherCharacter) const;

            /**
             *
             * @param object
             * @return
             */
            boolean equals(const Character &object) const;

            /**
             *
             * @param codePoint
             * @return
             */
            static int getType(int codePoint);

            /**
             *
             * @return
             */
            long hashCode() const override;

            /**
             * Returns a String object representing this Character's value.
             *
             * @return string
             */
            string toString() const;

        public:
            /**
             * Returns the code point at the given index of the CharSequence.
             *
             * @param sequence
             * @param index
             * @return int
             * @throw IndexOutOfBoundsException - if the value index is negative
             * or not less than length of sequence.
             */
            static int codePointAt(CharSequence &sequence, int index) ;

            /**
             * Returns the code point at the given index of the char array.
             *
             * @param charArray
             * @param index
             * @return int
             * @throw IndexOutOfBoundsException - if the value index is negative
             * or not less than the length of the char array.
             */
            static int codePointAt(const Array<unicode> &charArray, int index) ;

            /**
             * Returns the code point at the given index of the char array,
             * where only array elements with index less than limit can be used.
             *
             * @param charArray
             * @param index
             * @param limit
             * @return int
             * @throw IndexOutOfBoundsException - if the index argument is negative
             * or not less than the limit argument, or if the limit argument is negative
             * or greater than the length of the char array.
             */
            static int codePointAt(const Array<unicode> &charArray, int index, int limit) ;

            /**
             * Returns the code point preceding the given index of the CharSequence.
             *
             * @param sequence
             * @param index
             * @return int
             * @throw IndexOutOfBoundsException - if the index argument is less than 1
             * or greater length of sequence.
             */
            static int codePointBefore(CharSequence &sequence, int index);

            /**
             * Returns the code point preceding the given index of the char array.
             *
             * @param charArray
             * @param index
             * @return int
             * @throw IndexOutOfBoundsException - if the index argument is less than 1
             * or greater than the length of the char array.
             */
            static int codePointBefore(const Array<unicode> &charArray, int index);

            /**
             * Returns the code point preceding the given index of the char array,
             * where only array elements with index greater than or equal to start
             * can be used.
             *
             * @param charArray
             * @param index
             * @param start
             * @return int
             * @throw IndexOutOfBoundsException - if the index argument is not greater
             * than the start argument or is greater than the length of the char array,
             * or if the start argument is negative or not less than the length of the char array.
             */
            static int codePointBefore(const Array<unicode> &charArray, int index, int start);

            /**
             * Returns the number of Unicode code points in a subarray of the char array argument.
             *
             * @param charArray
             * @param offset
             * @param count
             * @return int
             * @throw IndexOutOfBoundsException - if offset or count is negative,
             * or if offset + count is larger than the length of the given array.
             */
            static int codePointCount(const Array<unicode> &charArray, int offset, int count) ;

            /**
             * Returns the number of Unicode code points in the text range of the
             * specified char sequence.
             *
             * @param sequence
             * @param beginIndex
             * @param endIndex
             * @return int
             * @throw IndexOutOfBoundsException - if the beginIndex is negative,
             * or endIndex is larger than the length of the given sequence,
             * or beginIndex is larger than endIndex.
             */
            static int codePointCount(CharSequence &sequence, int beginIndex, int endIndex) ;

            /**
             * Compares two char values numerically.
             *
             * @param charA
             * @param charB
             * @return int
             * = 0 if charA == charB;
             * < 0 if charA < charB;
             * > 0 if charA > charB.
             */
            static int compare(unicode charA, unicode charB);

            /**
             *
             * @param digit
             * @param radix
             * @return
             */
            static unicode forDigit(int digit, int radix);

            /**
             *
             * @param codePoint
             * @return
             */
            static byte getDirectionality(int codePoint);

            /**
              *
              * @param character
              * @param radix
              * @return
              */
            static int digit(unicode character, int radix);

            /**
             *
             * @param codePoint
             * @param radix
             * @return
             */
            static int digit(int codePoint, int radix);

            /**
             *
             * @param character
             * @return
             */
            static byte getDirectionality(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static String getName(int codePoint);

            /**
             *
             * @param codePoint
             * @return
             */
            static int getNumericValue(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static int getNumericValue(unicode character);

            /**
             *
             * @param character
             * @return
             */
            static int getType(unicode character);

            /**
             *
             * @param value
             * @return
             */
            static long hashCode(unicode value);

            /**
             *
             * @param codePoint
             * @return
             */
            static unicode highSurrogate(int codePoint);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isAlphabetic(int codePoint);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isBmpCodePoint(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isDefined(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isDefined(int codePoint);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isDigit(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isDigit(unicode character);

            /**
             *
             * @param character
             * @return
             */
            static boolean isHighSurrogate(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isIdentifierIgnorable(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isIdentifierIgnorable(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isIdeographic(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isISOControl(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isISOControl(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isJavaIdentifierPart(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isJavaIdentifierPart(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isJavaIdentifierStart(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isJavaIdentifierStart(int codePoint);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isLetter(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isLetter(unicode character);

            /**
             *
             * @param character
             * @return
             */
            static boolean isLetterOrDigit(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isLetterOrDigit(int codePoint);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isLowerCase(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isLowerCase(unicode character);

            /**
             *
             * @param character
             * @return
             */
            static boolean isLowSurrogate(unicode character);

            /**
             *
             * @param character
             * @return
             */
            static boolean isMirrored(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isMirrored(int codePoint);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isSpaceChar(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isSpaceChar(unicode character);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isSupplementaryCodePoint(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isSurrogate(unicode character);

            /**
             *
             * @param high
             * @param low
             * @return
             */
            static boolean isSurrogatePair(unicode high, unicode low);

            /**
             *
             * @param codePoint
             * @return
             */
            static boolean isTitleCase(int codePoint);

            /**
             *
             * @param character
             * @return
             */
            static boolean isTitleCase(unicode character);

            /**
             * Determines if the specified character may be part of a Unicode identifier
             * as other than the first character.
             *
             * @param character
             * @return boolean
             */
            static boolean isUnicodeIdentifierPart(unicode character);

            /**
             * Determines if the specified character (Unicode code point)
             * may be part of a Unicode identifier as other than the first character.
             *
             * @param codePoint
             * @return boolean
             */
            static boolean isUnicodeIdentifierPart(int codePoint);

            /**
             * Determines if the specified character is permissible
             * as the first character in a Unicode identifier.
             *
             * @param character
             * @return boolean
             */
            static boolean isUnicodeIdentifierStart(unicode character) ;

            /**
             * Determines if the specified character (Unicode code point)
             * is permissible as the first character in a Unicode identifier.
             *
             * @param codePoint
             * @return true if the character may start a Unicode identifier; false otherwise.
             */
            static boolean isUnicodeIdentifierStart(int codePoint) ;

            /**
             * Determines if the specified character (Unicode code point)
             * is an uppercase character.
             *
             * @param character
             * @return true if the character is uppercase; false otherwise.
             */
            static boolean isUpperCase(int character) ;

            /**
             * Determines if the specified character is an uppercase character.
             *
             * @param character
             * @return boolean
             */
            static boolean isUpperCase(unicode character);

            /**
             * Determines whether the specified code point is a valid
             * Unicode code point value.
             *
             * @param codePoint
             * @return boolean
             */
            static boolean isValidCodePoint(int codePoint);

            /**
             * Determines if the specified character is white space according to Java.
             *
             * @param character
             * @return boolean
             */
            static boolean isWhitespace(unicode character);

            /**
             * Determines if the specified character (Unicode code point)
             * is white space according to Java.
             *
             * @param codePoint
             * @return boolean
             */
            static boolean isWhitespace(int codePoint);

            /**
             * Returns the trailing surrogate
             * (a low surrogate code unit) of the surrogate pair representing
             * the specified supplementary character (Unicode code point)
             * in the UTF-16 encoding.
             *
             * @param codePoint
             * @return unicode
             */
            static unicode lowSurrogate(int codePoint);

            /**
             *
             * @param sequence
             * @param index
             * @param codePointOffset
             * @return int
             * @throw IndexOutOfBoundsException - if index is negative or larger than
             * the length of the char sequence, or if codePointOffset is positive and
             * the subsequence starting with index has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the subsequence before index has
             * fewer than the absolute value of codePointOffset code points.
             */
            static int offsetByCodePoints(CharSequence &sequence,
                                          int index, int codePointOffset);

            /**
             * Returns the index within the given char subarray that is offset
             * from the given index by codePointOffset code points.
             *
             * @param charArray
             * @param start
             * @param count
             * @param index
             * @param codePointOffset
             * @return int
             * @throw IndexOutOfBoundsException - if start or count is negative,
             * or if start + count is larger than the length of the given array,
             * or if index is less than start or larger then start + count,
             * or if codePointOffset is positive and the text range starting
             * with index and ending with start + count - 1 has fewer than
             * codePointOffset code points, or if codePointOffset is negative
             * and the text range starting with start and ending with index - 1
             * has fewer than the absolute value of codePointOffset code points.
             */
            static int offsetByCodePoints(const Array<unicode> &charArray,
                                          int start, int count, int index,
                                          int codePointOffset);

            /**
             * Returns the value obtained by reversing the order of the bytes in
             * the specified char value.
             *
             * @param character
             * @return unicode
             */
            static unicode reverseBytes(unicode character);

            /**
             * Converts the specified character (Unicode code point) to its UTF-16
             * representation stored in a char array.
             *
             * @param codePoint
             * @return int
             */
            static const Array<unicode> & toChars(int codePoint);

            /**
             * Converts the specified character (Unicode code point) to its UTF-16
             * representation.
             *
             * @param codePoint
             * @param destination
             * @param destinationIndex
             * @return int
             */
            static int toChars(int codePoint, Array<unicode> &destination,
                               int destinationIndex);

            /**
             * Converts the specified surrogate pair to its supplementary code point value.
             *
             * @param high
             * @param low
             * @return int
             */
            static int toCodePoint(unicode high, unicode low);

            /**
             * Converts the character (Unicode code point) argument to lowercase
             * using case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return int
             */
            static int toLowerCase(int codePoint);

            /**
             * Converts the character argument to lowercase using case mapping information from the UnicodeData file.
             *
             * @param character
             * @return int
             */
            static int toLowerCase(unicode character);

            /**
             * Returns a String object representing the specified char.
             *
             * @return string
             */
            static string toString(unicode character);

            /**
             * Converts the character (Unicode code point) argument to titlecase
             * using case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return int
             */
            static int toTitleCase(int codePoint);

            /**
             * Converts the character argument to titlecase using case mapping
             * information from the UnicodeData file.
             *
             * @param character
             * @return int
             */
            static int toTitleCase(unicode character);

            /**
             * Converts the character (Unicode code point) argument to uppercase
             * using case mapping information from the UnicodeData file.
             *
             * @param codePoint
             * @return the uppercase equivalent of the character, if any;
             * otherwise, the character itself.
             */
            static int toUpperCase(int codePoint);

            /**
             * Converts the character argument to uppercase using case mapping
             * information from the UnicodeData file.
             *
             * @param character
             * @return int
             */
            static int toUpperCase(unicode character);

            /**
             * Returns a Character instance representing the specified char value.
             *
             * @param character
             * @return Character
             */
            static Character valueOf(unicode character);

        public:
            /**
             * Stream insertion operator
             *
             * @param os
             * @param target
             * @return standard output stream
             */
            friend std::ostream &operator<<(std::ostream &os, const Character &target);

        private:
            /**
             *
             * @param charArray
             * @param index
             * @param limit
             * @return
             */
            static int codePointAtImpl(const Array<unicode> &charArray, int index, int limit);

            /**
             *
             * @param charArray
             * @param index
             * @param start
             * @return
             */
            static int codePointBeforeImpl(const Array<unicode> &charArray, int index, int start);

            /**
             *
             * @param charArray
             * @param offset
             * @param count
             * @return
             */
            static int codePointCountImpl(const Array<unicode> &charArray, int offset, int count);

            /**
             *
             * @param charArray
             * @param start
             * @param count
             * @param index
             * @param codePointOffset
             * @return
             */
            static int offsetByCodePointsImpl(const Array<unicode> &charArray, int start, int count, int index, int codePointOffset);

            /**
             *
             * @param codePoint
             * @param charArray
             * @param index
             */
            static void toSurrogates(int codePoint, Array<unicode> &charArray, int index);

            /**
             *
             * @param codePoint
             * @return
             */
            Array<unicode> toUpperCaseCharArray(int codePoint) const;

            /**
             *
             * @param codePoint
             * @return
             */
            static int toUpperCaseEx(int codePoint);
        };  // class Character
    }  // namespace Lang
}  // namespace Java

#endif  // NATIVE_JAVA_LANG_CHARACTER_HPP_
