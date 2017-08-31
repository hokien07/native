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

#include "Character.hpp"

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
