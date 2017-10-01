///**
// * Copyright 2017 Food Tiny Project. All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are met:
// *
// * Redistributions of source code must retain the above copyright
// * notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above
// * copyright notice, this list of conditions and the following disclaimer
// * in the documentation and/or other materials provided with the
// * distribution.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */
//
//extern "C" {
//#include "../../../kernel/test.h"
//}
//
//#include "Date.hpp"
//
//using namespace Java::Util;
//
//TEST(JavaUtil, DateConstructor) {
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);
//
//    // Create variable to test
//    Date date;
//
//    // Test Date(). This class return since 1900
//    assertEquals(currentTime->tm_year + 1900, date.getYear());
//
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(8, date.getHours());
//    assertEquals(01, date.getMinutes());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(8, date.getHours());
//    assertEquals(01, date.getMinutes());
//    assertEquals(13, date.getSeconds());
//
//    // Test Date(long date)
//    date = Date(1498042091);  // 2017
//    assertEquals(2017, date.getYear());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    assertEquals(sameDate.getYear(), date.getYear());
//    assertEquals(sameDate.getMonth(), date.getMonth());
//    assertEquals(sameDate.getDate(), date.getDate());
//    assertEquals(sameDate.getHours(), date.getHours());
//    assertEquals(sameDate.getMinutes(), date.getMinutes());
//    assertEquals(sameDate.getSeconds(), date.getSeconds());
//
//    // Test Date::Date(String inputString)
//    // Create variable to test
//    String expected;
//
//    Date   actualDate;
//    String actualString;
//    String actualFormat;
//    String actual;
//    String localZone;
//
//    tzset();
//    extern char *tzname[2];
//    String zone = (string) tzname[0];
//
//#ifdef LINUX
//    if (actualDate.getTimezoneOffset() == 0) {
//        localZone = "UTC";
//    } else {
//        localZone = "LMT";
//    }
//#endif
//
//#ifdef WINDOWS
//    if (actualDate.getTimezoneOffset() == 0) {
//        localZone = "GMT";
//    } else {
//        localZone = "LMT";
//    }
//#endif
//
//    // Valid case
//    expected     = "Thu Jan 09 12:35:34 " + zone + (string) " 2014";
//    actualString = "Thu Jan 9 and 2014 12:35:34";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Short date pattern. (en-US)
//    expected     = "Mon Feb 13 00:00:00 " + zone + (string) " 2017";
//    actualString = "02/13/17";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Short date pattern. (en-US)
//    expected     = "Mon Feb 13 00:00:00 " + zone + (string) " 2017";
//    actualString = "02/13/2017";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Long date pattern. (en-US)
//    expected     = "Mon Jun 15 00:00:00 " + zone + (string) " 2009";
//    actualString = "Monday, June 15, 2009";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Full date/time pattern (short time). (en-US)
//    expected     = "Mon Jun 15 13:45:00 " + zone + (string) " 2009";
//    actualString = "Monday, June 15, 2009 1:45 PM";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Full date/time pattern (long time). (en-US)
//    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
//    actualString = "Monday, June 15, 2009 1:45:30 PM";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // General date/time pattern (short time). (en-US)
//    expected     = "Mon Jun 15 01:45:30 " + zone + (string) " 2009";
//    actualString = "6/15/2009 1:45:30";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // General date/time pattern (short time). (en-US)
//    expected     = "Mon Jun 15 01:45:30 " + zone + (string) " 2009";
//    actualString = "6/15/2009 1:45:30";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // General date/time pattern (short time). (en-US)
//    expected     = "Mon Jun 15 13:45:00 " + zone + (string) " 2009";
//    actualString = "6/15/2009 1:45 PM";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // General date/time pattern (long time). (en-US)
//    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
//    actualString = "6/15/2009 1:45:30 PM";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Month/day pattern.(en-US)
//    expected     = "Fri Jun 15 00:00:00 " + localZone + (string) " 1900";
//    actualString = "June 15";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // RFC1123 pattern.
//    expected     = "Mon Jun 15 20:45:30 " + zone + (string) " 2009";
//    actualString = "Mon, 15 Jun 2009 20:45:30 GMT";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Short time pattern. (en-US)
//    expected     = "Sun Dec 31 13:45:00 " + localZone + (string) " 1899";
//    actualString = "1:45 PM";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Long time pattern. (en-US)
//    expected     = "Sun Dec 31 13:45:30 " + localZone + (string) " 1899";
//    actualString = "1:45:30 PM";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Universal sortable date/time pattern. With a DateTime value:
//    expected     = "Mon Jun 15 13:45:30 " + zone + (string) " 2009";
//    actualString = "2009-06-15 13:45:30Z";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Universal full date/time pattern. (en-US)
//    expected     = "Mon Jun 15 20:45:30 " + zone + (string) " 2009";
//    actualString = "Monday, June 15, 2009 8:45:30 PM";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Year month pattern. (en-US)
//    expected     = "Sun May 31 00:00:00 " + zone + (string) " 2009";
//    actualString = "June, 2009";
//    actualDate = Date(actualString);
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//}
//
//TEST(JavaUtil, DateSetYear) {
//    // Create variable to test
//    Date date;
//
//    date.setYear(1900);
//    assertEquals(1900, date.getYear());
//
//    date.setYear(3000);
//    assertEquals(3000, date.getYear());
//
//    date.setYear(1889);
//    assertEquals(3789, date.getYear());
//
//    date.setYear(-1);
//    assertEquals(1899, date.getYear());
//
//    date.setYear(-900);
//    assertEquals(1000, date.getYear());
//
//    date.setYear(0);
//    assertEquals(1900, date.getYear());
//}
//
//TEST(JavaUtil, DateGetYear) {
//    // Create variable to test
//    Date date;
//
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);
//    assertEquals(currentTime->tm_year + 1900, date.getYear());
//
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    assertEquals(2017, date.getYear());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    assertEquals(2017, date.getYear());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(2017, date.getYear());
//
//    // Test Date(long date)
//    Date tempDate = Date(2017, 02, 13, 8, 01, 13);
//    date = Date(tempDate.getTime());
//    assertEquals(2017, date.getYear());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    assertEquals(2017, sameDate.getYear());
//}
//
//TEST(JavaUtil, DateSetMonth) {
//    // Create variable to test
//    Date expected;
//    Date actual;
//
//    // Set month = 12 => Year+= 1 , month = 0.
//    expected = Date(2018, 0, 13, 10, 01, 13);
//    actual 	 = Date(2017, 1, 13, 10, 01, 13);
//    actual.setMonth(12);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 33 => Year+= 2, month = 9.
//    expected = Date(2019, 9, 13, 10, 01, 13);
//    actual 	 = Date(2017, 1, 13, 10, 01, 13);
//    actual.setMonth(33);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 0
//    expected = Date(2017, 0, 13, 10, 01, 13);
//    actual 	 = Date(2017, 1, 13, 10, 01, 13);
//    actual.setMonth(0);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = -1 => Year-= 1, month = 11.
//    expected = Date(2016, 11, 13, 10, 01, 13);
//    actual 	 = Date(2017, 1, 13, 10, 01, 13);
//    actual.setMonth(-1);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = -12 => Year-= 1, month = 0.
//    expected = Date(2016, 0, 13, 10, 01, 13);
//    actual 	 = Date(2017, 1, 13, 10, 01, 13);
//    actual.setMonth(-12);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = -33 => Year-= 3, month = 3.
//    expected = Date(2014, 3, 13, 10, 01, 13);
//    actual 	 = Date(2017, 1, 13, 10, 01, 13);
//    actual.setMonth(-33);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//}
//
//TEST(JavaUtil, DateGetMonth) {
//    // Create variable to test
//    Date date;
//
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);
//    assertEquals(currentTime->tm_mon, date.getMonth());
//
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    assertEquals(02, date.getMonth());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    assertEquals(02, date.getMonth());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(02, date.getMonth());
//
//    // Test Date(long date)
//    Date tempDate = Date(2017, 02, 13, 8, 01, 13);
//    date = Date(tempDate.getTime());
//    assertEquals(02, date.getMonth());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    assertEquals(02, sameDate.getMonth());
//}
//
//TEST(JavaUtil, DateSetDate) {
//    // Create variable to test
//    Date expected;
//    Date actual;
//
//    // Set month = 3, date = -1 => month = 2, date = 30
//    expected = Date(2017, 2, 30, 10, 01, 13);
//    actual 	 = Date(2017, 3, 1, 10, 01, 13);
//    actual.setDate(-1);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 6, date = -75 => month = 3, date = 16
//    expected = Date(2017, 3, 16, 10, 01, 13);
//    actual 	 = Date(2017, 6, 1, 10, 01, 13);
//    actual.setDate(-75);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 3, date = 0 => month = 2, date = 31
//    expected = Date(2017, 2, 31, 10, 01, 13);
//    actual 	 = Date(2017, 3, 1, 10, 01, 13);
//    actual.setDate(0);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 2, date = 0 => month = 1, date = 28
//    expected = Date(2017, 1, 28, 10, 01, 13);
//    actual 	 = Date(2017, 2, 1, 10, 01, 13);
//    actual.setDate(0);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 5, date = 32 => month = 6, date = 2
//    expected = Date(2017, 6, 2, 10, 01, 13);
//    actual 	 = Date(2017, 5, 1, 10, 01, 13);
//    actual.setDate(32);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//}
//
//TEST(JavaUtil, DateGetDate) {
//    // Create variable to test
//    Date date;
//
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);;
//    assertEquals(currentTime->tm_mday, date.getDate());
//
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    assertEquals(13, date.getDate());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    assertEquals(13, date.getDate());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(13, date.getDate());
//
//    // Test Date(long date)
//    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
//    date = Date(tempDate.getTime());
//    assertEquals(13, date.getDate());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    assertEquals(13, sameDate.getDate());
//}
//
//TEST(JavaUtil, DateSetHours) {
//    // Create variable to test
//    Date expected;
//    Date actual;
//
//    // Set hour = -1 => date -= 1, hour = 23
//    expected = Date(2017, 2, 12, 23, 01, 13);
//    actual 	 = Date(2017, 2, 13, 1, 01, 13);
//    actual.setHours(-1);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set hour = -58 => date -= 3, hour = 14
//    expected = Date(2017, 2, 10, 14, 01, 13);
//    actual 	 = Date(2017, 2, 13, 1, 01, 13);
//    actual.setHours(-58);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set hour = 0
//    expected = Date(2017, 2, 13, 0, 01, 13);
//    actual 	 = Date(2017, 2, 13, 1, 01, 13);
//    actual.setHours(0);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set hour = 24. Day += 1, hour = 0
//    expected = Date(2017, 2, 14, 0, 01, 13);
//    actual 	 = Date(2017, 2, 13, 1, 01, 13);
//    actual.setHours(24);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set hour = 49. Day += 2, hour = 1
//    expected = Date(2017, 2, 15, 1, 01, 13);
//    actual 	 = Date(2017, 2, 13, 1, 01, 13);
//    actual.setHours(49);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//}
//
//TEST(JavaUtil, DateGetHour) {
//    // Create variable to test
//    Date date;
//
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);
//    assertEquals(currentTime->tm_hour, date.getHours());
//
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    assertEquals(0, date.getHours());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    assertEquals(8, date.getHours());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(8, date.getHours());
//
//    // Test Date(long date)
//    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
//    date = Date(tempDate.getTime());
//    assertEquals(8, date.getHours());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    assertEquals(8, sameDate.getHours());
//}
//
//TEST(JavaUtil, DateSetMinutes) {
//    // Create variable to test
//    Date expected;
//    Date actual;
//
//    // Set minute = -1 => hour -= 1, minute = 59
//    expected = Date(2017, 2, 13, 9, 59, 13);
//    actual 	 = Date(2017, 2, 13, 10, 1, 13);
//    actual.setMinutes(-1);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = 0
//    expected = Date(2017, 2, 13, 10, 0, 13);
//    actual 	 = Date(2017, 2, 13, 10, 1, 13);
//    actual.setMinutes(0);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = 60 => hour += 1, minute = 0
//    expected = Date(2017, 2, 13, 11, 00, 13);
//    actual 	 = Date(2017, 2, 13, 10, 1, 13);
//    actual.setMinutes(60);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = 150 => hour += 2, minute = 30
//    expected = Date(2017, 2, 13, 12, 30, 13);
//    actual 	 = Date(2017, 2, 13, 10, 1, 13);
//    actual.setMinutes(150);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//}
//
//TEST(JavaUtil, DateGetMinutes) {
//    // Create variable to test
//    Date date;
//
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);
//    assertEquals(currentTime->tm_min, date.getMinutes());
//
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    assertEquals(0, date.getMinutes());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    assertEquals(01, date.getMinutes());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(01, date.getMinutes());
//
//    // Test Date(long date)
//    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
//    date = Date(tempDate.getTime());
//    assertEquals(01, date.getMinutes());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    assertEquals(01, sameDate.getMinutes());
//}
//
//TEST(JavaUtil, DateSetSeconds) {
//    // Create variable to test
//    Date expected;
//    Date actual;
//
//    // Set second = -1 => minute -= 1, second = 59
//    expected = Date(2017, 2, 13, 10, 00, 59);
//    actual   = Date(2017, 2, 13, 10, 01, 1);
//    actual.setSeconds(-1);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = 0
//    expected = Date(2017, 2, 13, 10, 01, 0);
//    actual   = Date(2017, 2, 13, 10, 01, 1);
//    actual.setSeconds(0);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set second = 60 => minute += 1, second = 0
//    expected = Date(2017, 2, 13, 10, 02, 00);
//    actual   = Date(2017, 2, 13, 10, 01, 1);
//    actual.setSeconds(60);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set second = 150 => minute += 2, second = 30
//    expected = Date(2017, 2, 13, 10, 03, 30);
//    actual   = Date(2017, 2, 13, 10, 01, 1);
//    actual.setSeconds(150);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//}
//
//TEST(JavaUtil, DateGetSeconds) {
//    // Create variable to test
//    Date date;
//
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);
//    assertEquals(currentTime->tm_sec, date.getSeconds());
//
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    assertEquals(0, date.getSeconds());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    assertEquals(0, date.getSeconds());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(13, date.getSeconds());
//
//    // Test Date(long date)
//    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
//    date = Date(tempDate.getTime());
//    assertEquals(13, date.getSeconds());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    assertEquals(13, sameDate.getSeconds());
//}
//
//TEST(JavaUtil, DateGetTime) {
//    // Create variable to test
//    Date date;
//
//    // Test the current local time
//    long now = time(nullptr);
//    assertEquals(now, date.getTime());
//}
//
//TEST(JavaUtil, DateSetTime) {
//    // Create variable to test
//    Date tempDate;
//    Date date;
//    long tempTime;
//
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);
//    date.setTime(now);
//    assertEquals(currentTime->tm_year + 1900, date.getYear());
//    assertEquals(currentTime->tm_mon, date.getMonth());
//    assertEquals(currentTime->tm_mday, date.getDate());
//    assertEquals(currentTime->tm_hour, date.getHours());
//    assertEquals(currentTime->tm_min, date.getMinutes());
//    assertEquals(currentTime->tm_sec, date.getSeconds());
//
//    // Test Date(int year, int month, int date)
//    tempDate = Date(2017, 02, 13);
//    tempTime = tempDate.getTime();
//    date.setTime(tempTime);
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(0, date.getHours());
//    assertEquals(0, date.getMinutes());
//    assertEquals(0, date.getSeconds());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    tempDate = Date(2017, 02, 13, 8, 01);
//    tempTime = tempDate.getTime();
//    date.setTime(tempTime);
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(8, date.getHours());
//    assertEquals(01, date.getMinutes());
//    assertEquals(0, date.getSeconds());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    tempDate = Date(2017, 02, 13, 8, 01, 13);
//    tempTime = tempDate.getTime();
//    date.setTime(tempTime);
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(8, date.getHours());
//    assertEquals(01, date.getMinutes());
//    assertEquals(13, date.getSeconds());
//
//    // Test Date(long date)
//    tempDate = Date(2017, 2, 13, 8, 1, 13);
//    tempTime = tempDate.getTime();
//    date.setTime(tempTime);
//    assertEquals(2017, date.getYear());
//    assertEquals(2, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(8, date.getHours());
//    assertEquals(1, date.getMinutes());
//    assertEquals(13, date.getSeconds());
//
//    // Test Date sameDate = date;
//    tempDate = Date(2017, 02, 13, 8, 01, 13);
//    tempTime = tempDate.getTime();
//    date.setTime(tempTime);
//    Date sameDate = date;
//    assertEquals(2017, sameDate.getYear());
//    assertEquals(02, sameDate.getMonth());
//    assertEquals(13, sameDate.getDate());
//    assertEquals(8, sameDate.getHours());
//    assertEquals(01, sameDate.getMinutes());
//    assertEquals(13, sameDate.getSeconds());
//}
//
//TEST(JavaUtil, DateGetDay) {
//    // Create variable to test
//    Date date;
//
//    // Test Sun - value 0
//    date = Date(2017, 8, 17, 8, 01, 13);
//    assertEquals(0, date.getDay());
//
//    // Test Mon - value 1
//    date = Date(2017, 8, 18, 8, 01, 13);
//    assertEquals(1, date.getDay());
//
//    // Test Tue - value 2
//    date = Date(2017, 8, 19, 8, 01, 13);
//    assertEquals(2, date.getDay());
//
//    // Test Wed - value 3
//    date = Date(2017, 8, 13, 8, 01, 13);
//    assertEquals(3, date.getDay());
//
//    // Test Thu - value 4
//    date = Date(2017, 8, 14, 8, 01, 13);
//    assertEquals(4, date.getDay());
//
//    // Test Fri - value 5
//    date = Date(2017, 8, 15, 8, 01, 13);
//    assertEquals(5, date.getDay());
//
//    // Test Sar - value 6
//    date = Date(2017, 8, 16, 8, 01, 13);
//    assertEquals(6, date.getDay());
//}
//
//TEST(JavaUtil, DateAfter) {
//    // Create variable to test
//    Date date;
//    Date tempDate = Date(2017, 8, 10, 8, 01, 13);;
//
//    // Test case TRUE
//    date = Date(2017, 8, 11, 8, 01, 13);
//    assertTrue(date.after(tempDate));
//
//    date = Date(2017, 9, 13, 8, 01, 13);
//    assertTrue(date.after(tempDate));
//
//    date = Date(2018, 8, 14, 8, 01, 13);
//    assertTrue(date.after(tempDate));
//
//    // Test case FALSE
//    date = Date(2017, 8, 10, 8, 01, 13);
//    assertFalse(date.after(tempDate));
//
//    date = Date(2017, 7, 5, 8, 01, 13);
//    assertFalse(date.after(tempDate));
//
//    date = Date(2016, 8, 5, 8, 01, 13);
//    assertFalse(date.after(tempDate));
//}
//
//TEST(JavaUtil, DateBefore) {
//    // Create variable to test
//    Date date;
//    Date tempDate = Date(2017, 8, 10, 8, 01, 13);;
//
//    // Test case TRUE
//    date = Date(2017, 8, 6, 8, 01, 13);
//    assertTrue(date.before(tempDate));
//
//    date = Date(2017, 7, 5, 8, 01, 13);
//    assertTrue(date.before(tempDate));
//
//    date = Date(2016, 8, 5, 8, 01, 13);
//    assertTrue(date.before(tempDate));
//
//    // Test case FALSE
//    date = Date(2017, 8, 10, 8, 01, 13);
//    assertFalse(date.before(tempDate));
//
//    date = Date(2017, 9, 13, 8, 01, 13);
//    assertFalse(date.before(tempDate));
//
//    date = Date(2018, 8, 14, 8, 01, 13);
//    assertFalse(date.before(tempDate));
//}
//
//TEST(JavaUtil, DateClone) {
//    // Create variable to test
//    Date tempDate;
//    Date date;
//    long tempTime;
//
//    // Get the current local time
//    long now = time(nullptr);
//    tm tempCurrentTime;
//    tm *currentTime = localtime_r(&now, &tempCurrentTime);
//    date = tempDate.clone();
//    assertEquals(currentTime->tm_year + 1900, date.getYear());
//    assertEquals(currentTime->tm_mon, date.getMonth());
//    assertEquals(currentTime->tm_mday, date.getDate());
//    assertEquals(currentTime->tm_hour, date.getHours());
//    assertEquals(currentTime->tm_min, date.getMinutes());
//    assertEquals(currentTime->tm_sec, date.getSeconds());
//
//    // Test Date(int year, int month, int date)
//    tempDate = Date(2017, 02, 13);
//    date = tempDate.clone();
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(0, date.getHours());
//    assertEquals(0, date.getMinutes());
//    assertEquals(0, date.getSeconds());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    tempDate = Date(2017, 02, 13, 8, 01);
//    date = tempDate.clone();
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(8, date.getHours());
//    assertEquals(01, date.getMinutes());
//    assertEquals(0, date.getSeconds());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    tempDate = Date(2017, 02, 13, 8, 01, 13);
//    date = tempDate.clone();
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(8, date.getHours());
//    assertEquals(01, date.getMinutes());
//    assertEquals(13, date.getSeconds());
//
//    // Test Date(long date)
//    Date temp = Date(2017, 02, 13, 8, 01, 13);
//    tempDate = Date(temp.getTime());
//    date = tempDate.clone();
//    assertEquals(2017, date.getYear());
//    assertEquals(02, date.getMonth());
//    assertEquals(13, date.getDate());
//    assertEquals(8, date.getHours());
//    assertEquals(01, date.getMinutes());
//    assertEquals(13, date.getSeconds());
//
//    // Test Date sameDate = date;
//    tempDate = Date(2017, 02, 13, 8, 01, 13);
//    date = tempDate.clone();
//    Date sameDate = date;
//    assertEquals(2017, sameDate.getYear());
//    assertEquals(02, sameDate.getMonth());
//    assertEquals(13, sameDate.getDate());
//    assertEquals(8, sameDate.getHours());
//    assertEquals(01, sameDate.getMinutes());
//    assertEquals(13, sameDate.getSeconds());
//}
//
//TEST(JavaUtil, DateCompareTo) {
//    // Create variable to test
//    Date date;
//    Date temp = Date(2017, 02, 13, 8, 01, 13);
//
//    date = Date(2017, 02, 12, 8, 01, 13);
//    assertEquals(-1, date.compareTo(temp));
//
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(0, date.compareTo(temp));
//
//    date = Date(2017, 02, 14, 8, 01, 13);
//    assertEquals(1, date.compareTo(temp));
//}
//
//TEST(JavaUtil, DateHashCode) {
//    Date date = Date(2017, 02, 14, 8, 01, 13);
//    long expected = date.getTime();
//    long actual = date.hashCode();
//    assertEquals(expected, actual);
//}
//
//TEST(JavaUtil, DateGetTimezoneOffset) {
//    // Create variable to test
//    Date date;
//    int expectedResult;
//
//    // Test System time zone
//    long now = time(nullptr);
//    tm tempLocalTimer = {0};
//    tm *localTimer = localtime_r(&now, &tempLocalTimer);
//    expectedResult = static_cast<int> (- localTimer->tm_gmtoff / 60);
//
//    assertEquals(expectedResult, date.getTimezoneOffset());
//
//    // Test Date(int year, int month, int date)
//    date = Date(2017, 02, 13);
//    assertEquals(expectedResult, date.getTimezoneOffset());
//
//    // Test Date(int year, int month, int date, int hrs, int min)
//    date = Date(2017, 02, 13, 8, 01);
//    assertEquals(expectedResult, date.getTimezoneOffset());
//
//    // Test Date(int year, int month, int date, int hrs, int min, int sec)
//    date = Date(2017, 02, 13, 8, 01, 13);
//    assertEquals(expectedResult, date.getTimezoneOffset());
//
//    // Test Date(long date)
//    Date tempDate = Date(2017, -28, 13, 8, 01, 13);
//    date = Date(tempDate.getTime());
//    assertEquals(expectedResult, date.getTimezoneOffset());
//
//    // Test Date sameDate = date;
//    date = Date(2017, 02, 13, 8, 01, 13);
//    Date sameDate = date;
//    assertEquals(expectedResult, date.getTimezoneOffset());
//}
//
//TEST(JavaUtil, DateToLocaleString) {
//    // Create variable to test
//    Date actualDate;
//    string expected;
//    String actual;
//
//    // Valid case
//    actualDate = Date(117, 2, 13, 10, 01, 13);
//    expected = (string) "Mar 13, 2017 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = 12 => Year+= 1 , month = 0.
//    actualDate = Date(117, 12, 13, 10, 01, 13);
//    expected = (string) "Jan 13, 2018 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = 33 => Year+= 2, month = 9.
//    actualDate = Date(117, 33, 13, 10, 01, 13);
//    expected = (string) "Oct 13, 2019 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = 0
//    actualDate = Date(117, 0, 13, 10, 01, 13);
//    expected = (string) "Jan 13, 2017 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = -1 => Year-= 1, month = 11.
//    actualDate = Date(117, -1, 13, 10, 01, 13);
//    expected = (string) "Dec 13, 2016 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = -12 => Year-= 1, month = 0.
//    actualDate = Date(117, -12, 13, 10, 01, 13);
//    expected = (string) "Jan 13, 2016 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = -33 => Year-= 3, month = 3.
//    actualDate = Date(117, -33, 13, 10, 01, 13);
//    expected = (string) "Apr 13, 2014 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = 3, date = -1 => month = 2, date = 30
//    actualDate = Date(117, 3, -1, 10, 01, 13);
//    expected = (string) "Mar 30, 2017 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = 6, date = -75 => month = 3, date = 16
//    actualDate = Date(117, 6, -75, 10, 01, 13);
//    expected = (string) "Apr 16, 2017 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = 3, date = 0 => month = 2, date = 31
//    actualDate = Date(117, 3, 0, 10, 01, 13);
//    expected = (string) "Mar 31, 2017 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = 2, date = 0 => month = 1, date = 28
//    actualDate = Date(117, 2, 0, 10, 01, 13);
//    expected = (string) "Feb 28, 2017 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set month = 5, date = 32 => month = 6, date = 2
//    actualDate = Date(117, 5, 32, 10, 01, 13);
//    expected = (string) "Jul 02, 2017 10:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set hour = -1 => day -= 1, hour = 11 PM
//    actualDate = Date(117, 2, 13, -1, 01, 13);
//    expected = (string) "Mar 12, 2017 11:01:13 PM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set hour = 0
//    actualDate = Date(117, 2, 13, 0, 01, 13);
//    expected = (string) "Mar 13, 2017 12:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set hour = 24. Day += 1, hour = 0
//    actualDate = Date(117, 2, 13, 24, 01, 13);
//    expected = (string) "Mar 14, 2017 12:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set hour = 49. Day += 2, hour = 1
//    actualDate = Date(117, 2, 13, 49, 01, 13);
//    expected = (string) "Mar 15, 2017 01:01:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set minute = -1 => hour -= 1, minute = 59
//    actualDate = Date(117, 2, 13, 10, -1, 13);
//    expected = (string) "Mar 13, 2017 09:59:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set minute = 0
//    actualDate = Date(117, 2, 13, 10, 0, 13);
//    expected = (string) "Mar 13, 2017 10:00:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set minute = 60 => hour += 1, minute = 0
//    actualDate = Date(117, 2, 13, 10, 60, 13);
//    expected = (string) "Mar 13, 2017 11:00:13 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set minute = 150 => hour += 2, minute = 30
//    actualDate = Date(117, 2, 13, 10, 150, 13);
//    expected = (string) "Mar 13, 2017 12:30:13 PM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set second = -1 => minute -= 1, second = 59
//    actualDate = Date(117, 2, 13, 10, 01, -1);
//    expected = (string) "Mar 13, 2017 10:00:59 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set minute = 0
//    actualDate = Date(117, 2, 13, 10, 01, 0);
//    expected = (string) "Mar 13, 2017 10:01:00 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set second = 60 => minute += 1, second = 0
//    actualDate = Date(117, 2, 13, 10, 01, 60);
//    expected = (string) "Mar 13, 2017 10:02:00 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//
//    // Set second = 150 => minute += 2, second = 30
//    actualDate = Date(117, 2, 13, 10, 01, 150);
//    expected = (string) "Mar 13, 2017 10:03:30 AM";
//    actual = actualDate.toLocaleString();
//    ASSERT_STR(expected, actual.toString());
//}
//
//TEST(JavaUtil, DateUTC) {
//    // Create variable to test
//    Date expected = Date();
//    String expectedString;
//    Date actual = Date();
//    long timeActual;
//    long timeChange;
//
//    // Valid case
//    expected 	= Date(2017, 2, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set year = 3000
//    expected 	= Date(3000, 2, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(3000, 2, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set year = 1889
//    expected 	= Date(1889, 2, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(1889, 2, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 12 => Year+= 1 , month = 0.
//    expected 	= Date(2018, 0, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 12, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 33 => Year+= 2, month = 9.
//    expected 	= Date(2019, 9, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 33, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 0
//    expected 	= Date(2017, 0, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 0, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = -1 => Year-= 1, month = 11.
//    expected 	= Date(2016, 11, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, -1, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = -12 => Year-= 1, month = 0.
//    expected 	= Date(2016, 0, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, -12, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = -33 => Year-= 3, month = 3.
//    expected 	= Date(2014, 3, 13, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, -33, 13, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 3, date = -1 => month = 2, date = 30
//    expected 	= Date(2017, 2, 30, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 3, -1, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 6, date = -75 => month = 3, date = 16
//    expected 	= Date(2017, 3, 16, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 6, -75, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 3, date = 0 => month = 2, date = 31
//    expected 	= Date(2017, 2, 31, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 3, 0, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 2, date = 0 => month = 1, date = 28
//    expected 	= Date(2017, 1, 28, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 2, 0, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set month = 5, date = 32 => month = 6, date = 2
//    expected 	= Date(2017, 6, 2, 10, 01, 13);
//    timeActual 	= Date::UTC(2017, 5, 32, 10, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set hour = -1 => day -= 1, hour = 23
//    expected 	= Date(2017, 2, 12, 23, 01, 13);
//    timeActual 	= Date::UTC(2017, 2, 13, -1, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//
//    // Set hour = 0
//    expected 	= Date(2017, 2, 13, 0, 01, 13);
//    timeActual  = Date::UTC(2017, 2, 13, 0, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set hour = 24. Day += 1, hour = 0
//    expected 	= Date(2017, 2, 14, 0, 01, 13);
//    timeActual 	= Date::UTC(2017, 2, 13, 24, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set hour = 49. Day += 2, hour = 1
//    expected 	= Date(2017, 2, 15, 1, 01, 13);
//    timeActual 	= Date::UTC(2017, 2, 13, 49, 01, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = -1 => hour -= 1, minute = 59
//    expected 	= Date(2017, 2, 13, 9, 59, 13);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, -1, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = 0
//    expected 	= Date(2017, 2, 13, 10, 0, 13);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, 0, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = 60 => hour += 1, minute = 0
//    expected 	= Date(2017, 2, 13, 11, 00, 13);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, 60, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = 150 => hour += 2, minute = 30
//    expected 	= Date(2017, 2, 13, 12, 30, 13);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, 150, 13);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set second = -1 => minute -= 1, second = 59
//    expected 	= Date(2017, 2, 13, 10, 00, 59);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, -1);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set minute = 0
//    expected 	= Date(2017, 2, 13, 10, 01, 0);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 0);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set second = 60 => minute += 1, second = 0
//    expected 	= Date(2017, 2, 13, 10, 02, 00);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 60);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//
//    // Set second = 150 => minute += 2, second = 30
//    expected 	= Date(2017, 2, 13, 10, 03, 30);
//    timeActual 	= Date::UTC(2017, 2, 13, 10, 01, 150);
//    actual = Date(timeActual);
//    timeChange = expected.getTime() + expected.getTimezoneOffset() * 60;
//    expected.setTime(timeChange);
//    assertEquals(expected.getYear(), actual.getYear());
//    assertEquals(expected.getMonth(), actual.getMonth());
//    assertEquals(expected.getDate(), actual.getDate());
//    assertEquals(expected.getHours(), actual.getHours());
//    assertEquals(expected.getMinutes(), actual.getMinutes());
//    assertEquals(expected.getSeconds(), actual.getSeconds());
//}
//
//TEST(JavaUtil, DateToString) {
//    // Create variable to test
//    Date actualDate = Date();
//    String expected;
//    String actual;
//
////    tzset();
//    tzset();
//    extern char *tzname[2];
//    String zone = (string) tzname[0];
//
//    // Valid case
//    actualDate = Date(117, 2, 13, 10, 01, 13);
//    expected = "Mon Mar 13 10:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//
//    // Set month = 12 => Year+= 1 , month = 0.
//    actualDate = Date(117, 12, 13, 10, 01, 13);
//    expected = "Sat Jan 13 10:01:13 " + zone + (string) " 2018";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = 33 => Year+= 2, month = 9.
//    actualDate = Date(117, 33, 13, 10, 01, 13);
//    expected = "Sun Oct 13 10:01:13 " + zone + (string) " 2019";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = 0
//    actualDate = Date(117, 0, 13, 10, 01, 13);
//    expected = "Fri Jan 13 10:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = -1 => Year-= 1, month = 11.
//    actualDate = Date(117, -1, 13, 10, 01, 13);
//    expected = "Tue Dec 13 10:01:13 " + zone + (string) " 2016";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = -12 => Year-= 1, month = 0.
//    actualDate = Date(117, -12, 13, 10, 01, 13);
//    expected = "Wed Jan 13 10:01:13 " + zone + (string) " 2016";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = -33 => Year-= 3, month = 3.
//    actualDate = Date(117, -33, 13, 10, 01, 13);
//    expected = "Sun Apr 13 10:01:13 " + zone + (string) " 2014";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = 3, date = -1 => month = 2, date = 30
//    actualDate = Date(117, 3, -1, 10, 01, 13);
//    expected = "Thu Mar 30 10:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = 6, date = -75 => month = 3, date = 16
//    actualDate = Date(117, 6, -75, 10, 01, 13);
//    expected = "Sun Apr 16 10:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = 3, date = 0 => month = 2, date = 31
//    actualDate = Date(117, 3, 0, 10, 01, 13);
//    expected = "Fri Mar 31 10:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = 2, date = 0 => month = 1, date = 28
//    actualDate = Date(117, 2, 0, 10, 01, 13);
//    expected = "Tue Feb 28 10:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set month = 5, date = 32 => month = 6, date = 2
//    actualDate = Date(117, 5, 32, 10, 01, 13);
//    expected = "Sun Jul 02 10:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set hour = -1 => day -= 1, hour = 11 PM
//    actualDate = Date(117, 2, 13, -1, 01, 13);
//    expected = "Sun Mar 12 23:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set hour = 0
//    actualDate = Date(117, 2, 13, 0, 01, 13);
//    expected = "Mon Mar 13 00:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set hour = 24. Day += 1, hour = 0
//    actualDate = Date(117, 2, 13, 24, 01, 13);
//    expected = "Tue Mar 14 00:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set hour = 49. Day += 2, hour = 1
//    actualDate = Date(117, 2, 13, 49, 01, 13);
//    expected = "Wed Mar 15 01:01:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set minute = -1 => hour -= 1, minute = 59
//    actualDate = Date(117, 2, 13, 10, -1, 13);
//    expected = "Mon Mar 13 09:59:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set minute = 0
//    actualDate = Date(117, 2, 13, 10, 0, 13);
//    expected = "Mon Mar 13 10:00:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set minute = 60 => hour += 1, minute = 0
//    actualDate = Date(117, 2, 13, 10, 60, 13);
//    expected = "Mon Mar 13 11:00:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set minute = 150 => hour += 2, minute = 30
//    actualDate = Date(117, 2, 13, 10, 150, 13);
//    expected = "Mon Mar 13 12:30:13 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set second = -1 => minute -= 1, second = 59
//    actualDate = Date(117, 2, 13, 10, 01, -1);
//    expected = "Mon Mar 13 10:00:59 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set minute = 0
//    actualDate = Date(117, 2, 13, 10, 01, 0);
//    expected = "Mon Mar 13 10:01:00 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set second = 60 => minute += 1, second = 0
//    actualDate = Date(117, 2, 13, 10, 01, 60);
//    expected = "Mon Mar 13 10:02:00 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//
//    // Set second = 150 => minute += 2, second = 30
//    actualDate = Date(117, 2, 13, 10, 01, 150);
//    expected = "Mon Mar 13 10:03:30 " + zone + (string) " 2017";
//    actual = actualDate.toString();
//    ASSERT_STR(expected.toString(), actual.toString());
//}
//
//TEST(JavaUtil, DateToGMTString) {
//    Date expectedDate = Date(2017, 2, 13, 10, 01, 13);
//    String actualString = expectedDate.toGMTString();
//    long actualTime = Date::parse(actualString);
//    Date actualDate = Date(actualTime);
//
//    long timeChange = expectedDate.getTime()
//                      + expectedDate.getTimezoneOffset() * 60;
//    expectedDate.setTime(timeChange);
//
//    String expected = expectedDate.toString();
//    String actual = actualDate.toString();
//
//    ASSERT_STR(expected.toString(), actual.toString());
//}