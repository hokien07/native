/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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

extern "C" {
#include "../../../kernel/test.h"
}

#include "Short.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

TEST (JavaLang, ShortConstructor) {
    //Test Short::Short()
    Short shortConstructorNoneParameter;
    ASSERT_EQUAL(0, shortConstructorNoneParameter.shortValue());
    ASSERT_STR((string) "0", shortConstructorNoneParameter.toString());

    //Test Short::Short(String stringInput)
    Short shortConstructorStringParameter((String) "69");
    ASSERT_EQUAL(69, shortConstructorStringParameter.shortValue());
    ASSERT_STR((string) "69", shortConstructorNoneParameter.toString());

    //Test Short::Short(const Short &short)
    Short shortConstructorShortParameter = 69;
    ASSERT_STR(69, shortConstructorShortParameter.shortValue());
    ASSERT_STR((string) "69", shortConstructorShortParameter.toString());
}

TEST (JavaLang, ShortComparision) {
    //Give a valid number of make a comparision
    Short validNumberComparision = 10;
    Short targetNumberComparision;

    // Test validNumber is equal targetNumber
    targetNumberComparision = 10;
    ASSERT_TRUE(validNumberComparision == targetNumberComparision);

    //Test validNumber is not equal targetNumber
    targetNumberComparision = 11;
    ASSERT_TRUE(validNumberComparision != targetNumberComparision);

    //Test validNumber is less than targetNumber
    targetNumberComparision = 20;
    ASSERT_TRUE(validNumberComparision < targetNumberComparision);

    //Test validNumber is equal or less than targetNumber;
    targetNumberComparision = 21;
    ASSERT_TRUE(validNumberComparision <= targetNumberComparision);

    //Test validNumber is greater than targetNumber
    targetNumberComparision = 15;
    ASSERT_TRUE(validNumberComparision > targetNumberComparision);

    //Test validNumber is equal or greater than targetNumber
    targetNumberComparision = 13;
    ASSERT_TRUE(validNumberComparision >= targetNumberComparision);

}

TEST (JavaLang, ShortOperator) {
    //Create variable
    Short validNumberOperator = 2;
    Short targetNumberOperator = 3;
    Short expectedResult;
    Short actualResult;

    //Make a summation
    expectedResult = 5;
    actualResult = validNumberOperator + targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    expectedResult = 5;
    actualResult += validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    //Make a subtraction
    expectedResult = -1;
    actualResult = validNumberOperator - targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    expectedResult = -3;
    actualResult -= validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    //Make a multiplication
    expectedResult = 6;
    actualResult = validNumberOperator * targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    expectedResult = 12;
    actualResult *= validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    //Make a division
    expectedResult = 0;
    actualResult = validNumberOperator / targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    try {
        actualResult = validNumberOperator / 0;
    }
    catch(ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }

    expectedResult = 5;
    actualResult = 10;
    actualResult /= validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    try {
        actualResult /= 0;
    }
    catch(ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }

    //Make a modulo
    expectedResult = 2;
    actualResult = validNumberOperator % targetNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    try {
        actualResult = validNumberOperator % 0;
    }
    catch(ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }

    expectedResult = 1;
    actualResult = 3;
    actualResult %= validNumberOperator;
    ASSERT_EQUAL(expectedResult.shortValue(), actualResult.shortValue());

    try {
        actualResult /= 0;
    }
    catch(ArithmeticException &e) {
        ASSERT_STR("Divide by zero", e.getMessage().toString());
    }
}

TEST (JavaLang, ShortCompareTo) {
    // Give Short value to compare with target
    Short validValueCompareTo = 10;
    Short lessThanValueCompareTo = 9;
    Short equalValueCompareTo = 10;
    Short greaterValueCompareTo = 11;

    //Return 1 if validValue is greater than lessThanValue
    ASSERT_EQUAL(1, validValueCompareTo.compareTo(lessThanValueCompareTo));

    //Return 0 if validValue is greater than equalValue
    ASSERT_EQUAL(0, validValueCompareTo.compareTo(equalValueCompareTo));

    //Return -1 if validValue is less than greaterThanValue
    ASSERT_EQUAL(-1, validValueCompareTo.compareTo(greaterValueCompareTo));

    //TODO
}

TEST (JavaLang, ShortCharValue) {
    Short zeroShortCharValue = 0;
    Short oneShortCharValue = 1;
    Short positiveShortCharValue = 15;
    Short maxShortCharValue;
    Short minShortCharValue;

    //Make a comparison between expected result and the real result
    char expectedResultCharValue = '0';
    char realResultCharValue = zeroShortCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    //Make a comparison between expected result and the real result
    expectedResultCharValue = '1';
    realResultCharValue = oneShortCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '1';
    realResultCharValue = positiveShortCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);
}

TEST (JavaLang, ShortStringValue) {
    Short zeroShortStringValue = 0;
    Short oneShortStringValue = 1;
    Short positiveShortStringValue = 15;
    Short maxShortStringValue;
    Short minShortStringValue;

    //Make a comparison between expected result and the real result
    string expectedResultStringValue = (string) "0";
    string realResultStringValue = zeroShortStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    //Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "1";
    realResultStringValue = oneShortStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    //Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "15";
    realResultStringValue = positiveShortStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);
}

