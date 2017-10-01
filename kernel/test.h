/* Copyright 2011-2016 Bas van den Berg
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NATIVE_KERNEL_TEST_H
#define NATIVE_KERNEL_TEST_H

#include <stddef.h>

#if defined _WIN32 || defined __CYGWIN__
#ifndef WIN32
#define WIN32
#endif
#endif

#ifndef WIN32
#define WEAK __attribute__ ((weak))
#else
#define WEAK
#endif

#include <inttypes.h> /* intmax_t, uintmax_t, PRI* */
#include <stddef.h> /* size_t */
#include <signal.h>
//#include <sys/resource.h>
#include "common.h"

typedef void (*SetupFunc)(void *);
typedef void (*TearDownFunc)(void *);

struct ctest {
		const char *ssname;  // suite name
		const char *ttname;  // test name
		void (*run)();
		int skip;
		
		void *data;
		SetupFunc setup;
		TearDownFunc teardown;
		
		unsigned int magic;
};

#define __FNAME(sname, tname) __ctest_##sname##_##tname##_run
#define __TNAME(sname, tname) __ctest_##sname##_##tname

#define __CTEST_MAGIC (0xdeadbeef)
#ifdef __APPLE__
#define __Test_Section __attribute__ ((used, section ("__DATA, .ctest")))
#else
#define __Test_Section __attribute__ ((used, section (".ctest")))
#endif

#define __CTEST_STRUCT(sname, tname, _skip, __data, __setup, __teardown) \
    static struct ctest __TNAME(sname, tname) __Test_Section = { \
        .ssname=#sname, \
        .ttname=#tname, \
        .run = __FNAME(sname, tname), \
        .skip = _skip, \
        .data = __data, \
        .setup = (SetupFunc)__setup,                                        \
        .teardown = (TearDownFunc)__teardown,                                \
        .magic = __CTEST_MAGIC };

#define CTEST_DATA(sname) struct sname##_data

#define CTEST_SETUP(sname) \
    void WEAK sname##_setup(struct sname##_data* data)

#define CTEST_TEARDOWN(sname) \
    void WEAK sname##_teardown(struct sname##_data* data)

#define __CTEST_INTERNAL(sname, tname, _skip) \
    void __FNAME(sname, tname)(); \
    __CTEST_STRUCT(sname, tname, _skip, NULL, NULL, NULL) \
    void __FNAME(sname, tname)()

#ifdef __APPLE__
#define SETUP_FNAME(sname) NULL
#define TEARDOWN_FNAME(sname) NULL
#else
#define SETUP_FNAME(sname) sname##_setup
#define TEARDOWN_FNAME(sname) sname##_teardown
#endif

#define __CTEST2_INTERNAL(sname, tname, _skip) \
    static struct sname##_data  __ctest_##sname##_data; \
    CTEST_SETUP(sname); \
    CTEST_TEARDOWN(sname); \
    void __FNAME(sname, tname)(struct sname##_data* data); \
    __CTEST_STRUCT(sname, tname, _skip, &__ctest_##sname##_data, SETUP_FNAME(sname), TEARDOWN_FNAME(sname)) \
    void __FNAME(sname, tname)(struct sname##_data* data)


void CTEST_LOG(const char *fmt, ...);
void CTEST_ERR(const char *fmt, ...);  // doesn't return

#define CTEST(sname, tname) __CTEST_INTERNAL(sname, tname, 0)
#define CTEST_SKIP(sname, tname) __CTEST_INTERNAL(sname, tname, 1)

#define CTEST2(sname, tname) __CTEST2_INTERNAL(sname, tname, 0)
#define CTEST2_SKIP(sname, tname) __CTEST2_INTERNAL(sname, tname, 1)


void assert_str(const char *expected, const char *actual, const char *caller, int line);
#define ASSERT_STR(expected, actual) assert_str(expected, actual, __FILE__, __LINE__)

void assert_data(const unsigned char *expected, size_t expsize,
	const unsigned char *actual, size_t realsize,
	const char *caller, int line);
#define ASSERT_DATA(expected, expsize, actual, realsize) \
    assert_data(expected, expsize, actual, realsize, __FILE__, __LINE__)

/**
 * Asserts that two intmax_t are equal.
 *
 * @param expected
 * @param actual
 */
void assertEquals(intmax_t expected, intmax_t actual);

void assert_not_equal(intmax_t expected, intmax_t actual, const char *caller, int line);
#define ASSERT_NOT_EQUAL(expected, actual) assert_not_equal(expected, actual, __FILE__, __LINE__)

void assert_not_equal_u(uintmax_t expected, uintmax_t actual, const char *caller, int line);
#define ASSERT_NOT_EQUAL_U(expected, actual) assert_not_equal_u(expected, actual, __FILE__, __LINE__)

void assert_interval(intmax_t exp1, intmax_t exp2, intmax_t actual, const char *caller, int line);
#define ASSERT_INTERVAL(exp1, exp2, actual) assert_interval(exp1, exp2, actual, __FILE__, __LINE__)

void assert_null(void *actual, const char *caller, int line);
#define ASSERT_NULL(actual) assert_null((void*)actual, __FILE__, __LINE__)

void assert_not_null(const void *actual, const char *caller, int line);
#define ASSERT_NOT_NULL(actual) assert_not_null(actual, __FILE__, __LINE__)

void assert_true(int actual, const char *caller, int line);
#define ASSERT_TRUE(actual) assert_true(actual, __FILE__, __LINE__)

void assert_false(int actual, const char *caller, int line);
#define ASSERT_FALSE(actual) assert_false(actual, __FILE__, __LINE__)

void assert_fail(const char *caller, int line);
#define ASSERT_FAIL() assert_fail(__FILE__, __LINE__)

void assert_dbl_near(double expected, double actual, int precision, const char *caller, int line);
#define ASSERT_DBL_NEAR(expected, actual) assert_dbl_near(expected, actual, 15, __FILE__, __LINE__)
#define ASSERT_DBL_NEAR_PRE(expected, actual, precision) assert_dbl_near(expected, actual, precision, __FILE__, __LINE__)

void assert_dbl_far(double expected, double actual, int precision, const char *caller, int line);
#define ASSERT_DBL_FAR(expected, actual) assert_dbl_far(expected, actual, 15, __FILE__, __LINE__)
#define ASSERT_DBL_FAR_PRE(expected, actual, precision) assert_dbl_far(expected, actual, precision, __FILE__, __LINE__)

void assert_float_near(float expected, float actual, int precision, const char *caller, int line);
#define ASSERT_FLOAT_NEAR(expected, actual) assert_float_near(expected, actual, 6, __FILE__, __LINE__)
#define ASSERT_FLOAT_NEAR_PRE(expected, actual, precision) assert_float_near(expected, actual, precision, __FILE__, __LINE__)

void assert_float_far(float expected, float actual, int precision, const char *caller, int line);
#define ASSERT_FLOAT_FAR(expected, actual) assert_float_far(expected, actual, 6, __FILE__, __LINE__)
#define ASSERT_FLOAT_FAR_PRE(expected, actual, precision) assert_float_far(expected, actual, precision, __FILE__, __LINE__)



#ifdef TESTING

#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <dlfcn.h>
#endif

static size_t ctest_errorsize;
static char* ctest_errormsg;
#define MSG_SIZE 4096
static char ctest_errorbuffer[MSG_SIZE];
static jmp_buf ctest_err;
static int color_output = 1;
static const char* suite_name;

typedef int (*filter_func)(struct ctest*);

#define ANSI_BLACK    "\033[0;30m"
#define ANSI_RED      "\033[0;31m"
#define ANSI_GREEN    "\033[0;32m"
#define ANSI_YELLOW   "\033[0;33m"
#define ANSI_BLUE     "\033[0;34m"
#define ANSI_MAGENTA  "\033[0;35m"
#define ANSI_CYAN     "\033[0;36m"
#define ANSI_GREY     "\033[0;37m"
#define ANSI_DARKGREY "\033[01;30m"
#define ANSI_BRED     "\033[01;31m"
#define ANSI_BGREEN   "\033[01;32m"
#define ANSI_BYELLOW  "\033[01;33m"
#define ANSI_BBLUE    "\033[01;34m"
#define ANSI_BMAGENTA "\033[01;35m"
#define ANSI_BCYAN    "\033[01;36m"
#define ANSI_WHITE    "\033[01;37m"
#define ANSI_NORMAL   "\033[0m"

static CTEST(suite, test) { }

inline static void vprint_errormsg(const char* const fmt, va_list ap) {
	// (v)snprintf returns the number that would have been written
    const int ret = vsnprintf(ctest_errormsg, ctest_errorsize, fmt, ap);
    if (ret < 0) {
		ctest_errormsg[0] = 0x00;
    } else {
	    const size_t size = (size_t) ret;
	    const size_t s = (ctest_errorsize <= size ? size -ctest_errorsize : size);
	    // ctest_errorsize may overflow at this point
		ctest_errorsize -= s;
		ctest_errormsg += s;
    }
}

inline static void print_errormsg(const char* const fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    vprint_errormsg(fmt, argp);
    va_end(argp);
}

static void msg_start(const char* color, const char* title) {
    if (color_output) {
	    print_errormsg("%s", color);
    }
    print_errormsg("  %s: ", title);
}

static void msg_end() {
    if (color_output) {
	    print_errormsg(ANSI_NORMAL);
    }
    print_errormsg("\n");
}

void CTEST_LOG(const char* fmt, ...)
{
    va_list argp;
    msg_start(ANSI_BLUE, "LOG");

    va_start(argp, fmt);
    vprint_errormsg(fmt, argp);
    va_end(argp);

    msg_end();
}

void CTEST_ERR(const char* fmt, ...)
{
    va_list argp;
    msg_start(ANSI_YELLOW, "\nERROR");

    va_start(argp, fmt);
    vprint_errormsg(fmt, argp);
    va_end(argp);

    msg_end();
    longjmp(ctest_err, 1);
}

void assert_str(const char* expected, const char*  actual, const char* caller, int line) {
    if ((expected == NULL && actual != NULL) ||
	(expected != NULL && actual == NULL) ||
	(expected && actual && strcmp(expected, actual) != 0)) {
	CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n", caller, line, expected, actual);
    }
}

void assert_data(const unsigned char* expected, size_t expsize,
		 const unsigned char* actual, size_t realsize,
		 const char* caller, int line) {
    size_t i;
    if (expsize != realsize) {
	CTEST_ERR("%s:%d  expected %" PRIuMAX " bytes, got %" PRIuMAX, caller, line, (uintmax_t) expsize, (uintmax_t) realsize);
    }
    for (i=0; i<expsize; i++) {
	if (expected[i] != actual[i]) {
	    CTEST_ERR("%s:%d expected 0x%02x at offset %" PRIuMAX " got 0x%02x",
		caller, line, expected[i], (uintmax_t) i, actual[i]);
	}
    }
}

void assertEquals(intmax_t expected, intmax_t actual) {
    if (expected != actual) {
	CTEST_ERR("%s:%d  expected %" PRIdMAX ", got %" PRIdMAX, __FILE__, __LINE__, expected, actual);
    }
}

void assert_not_equal(intmax_t expected, intmax_t actual, const char* caller, int line) {
    if ((expected) == (actual)) {
	CTEST_ERR("%s:%d  should not be %" PRIdMAX, caller, line, actual);
    }
}

void assert_not_equal_u(uintmax_t expected, uintmax_t actual, const char* caller, int line) {
    if ((expected) == (actual)) {
	CTEST_ERR("%s:%d  should not be %" PRIuMAX, caller, line, actual);
    }
}

void assert_interval(intmax_t exp1, intmax_t exp2, intmax_t actual, const char* caller, int line) {
    if (actual < exp1 || actual > exp2) {
	CTEST_ERR("%s:%d  expected %" PRIdMAX "-%" PRIdMAX ", got %" PRIdMAX, caller, line, exp1, exp2, actual);
    }
}

void assert_dbl_near(double expected, double actual, int precision, const char* caller, int line) {
    // max_digits = 3 + MANTISSA_DIGIT - MIN_EXPONENT = 3 + 53 - (-1023)
    char* expectedString = (char*) calloc(1079, sizeof(char));
    char* realString = (char*) calloc(1079, sizeof(char));

    // Get string type of input number
    if(expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if(actual == -0.0f && actual < 0) {
        sprintf(realString, "-%.*f", precision, actual);
    } else {
        sprintf(realString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == NULL && realString != NULL) ||
	(expectedString != NULL && realString == NULL) ||
	(expectedString && realString && strcmp(expectedString, realString) != 0)) {
	CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n", caller, line, expectedString, realString);
    }

    // Free
    free(expectedString);
    free(realString);
}

void assert_dbl_far(double expected, double actual, int precision, const char* caller, int line) {
    // max_digits = 3 + MANTISSA_DIGIT - MIN_EXPONENT = 3 + 53 - (-1023)
    char* expectedString = (char*) calloc(1079, sizeof(char));
    char* realString = (char*) calloc(1079, sizeof(char));

    // Get string type of input number
    if(expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if(actual == -0.0f && actual < 0) {
        sprintf(realString, "-%.*f", precision, actual);
    } else {
        sprintf(realString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == NULL && realString != NULL) ||
	(expectedString != NULL && realString == NULL) ||
	(expectedString && realString && strcmp(expectedString, realString) == 0)) {
	CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n", caller, line, expectedString, realString);
    }

    // Free
    free(expectedString);
    free(realString);
}

void assert_float_near(float expected, float actual, int precision, const char* caller, int line) {
    // max_digits = 3 + DBL_MANT_DIG - DBL_MIN_EXP = 3 + 24 - (-126)
    char* expectedString = (char*) calloc(153, sizeof(char));
    char* realString = (char*) calloc(153, sizeof(char));

    // Get string type of input number
    if(expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if(actual == -0.0f && actual < 0) {
        sprintf(realString, "-%.*f", precision, actual);
    } else {
        sprintf(realString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == NULL && realString != NULL) ||
	(expectedString != NULL && realString == NULL) ||
	(expectedString && realString && strcmp(expectedString, realString) != 0)) {
	CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n", caller, line, expectedString, realString);
    }

    // Free
    free(expectedString);
    free(realString);
}

void assert_float_far(float expected, float actual, int precision, const char* caller, int line) {
    // max_digits = 3 + DBL_MANT_DIG - DBL_MIN_EXP = 3 + 24 - (-126)
    char* expectedString = (char*) calloc(153, sizeof(char));
    char* realString = (char*) calloc(153, sizeof(char));

    // Get string type of input number
    if(expected == 0.0f && expected < 0) {
        sprintf(expectedString, "-%.*f", precision, expected);
    } else {
        sprintf(expectedString, "%.*f", precision, expected);
    }

    if(actual == -0.0f && actual < 0) {
        sprintf(realString, "-%.*f", precision, actual);
    } else {
        sprintf(realString, "%.*f", precision, actual);
    }

    // Compare with string type
    if ((expectedString == NULL && realString != NULL) ||
	(expectedString != NULL && realString == NULL) ||
	(expectedString && realString && strcmp(expectedString, realString) == 0)) {
	CTEST_ERR("%s:%d\nEXPECTED\n'%s'\nACTUAL \n'%s'\n", caller, line, expectedString, realString);
    }

    // Free
    free(expectedString);
    free(realString);
}


void assert_null(void* actual, const char* caller, int line) {
    if ((actual) != NULL) {
	CTEST_ERR("%s:%d  should be NULL", caller, line);
    }
}

void assert_not_null(const void* actual, const char* caller, int line) {
    if (actual == NULL) {
	CTEST_ERR("%s:%d  should not be NULL", caller, line);
    }
}

void assert_true(int actual, const char* caller, int line) {
    if ((actual) == 0) {
	CTEST_ERR("%s:%d  should be true", caller, line);
    }
}

void assert_false(int actual, const char* caller, int line) {
    if ((actual) != 0) {
	CTEST_ERR("%s:%d  should be false", caller, line);
    }
}

void assert_fail(const char* caller, int line) {
    CTEST_ERR("%s:%d  shouldn't come here", caller, line);
}


static int suite_all(struct ctest* t) {
    (void) t; // fix unused parameter warning
    return 1;
}

static int suite_filter(struct ctest* t) {
    return strncmp(suite_name, t->ssname, strlen((char *)suite_name)) == 0;
}

static uint64_t getCurrentTime() {
    struct timeval now;
    gettimeofday(&now, NULL);
    uint64_t now64 = (uint64_t) now.tv_sec;
    now64 *= 1000000;
    now64 += ((uint64_t) now.tv_usec);
    return now64;
}

static void color_print(const char* color, const char* text) {
    if (color_output)
	printf("%s%s " ANSI_NORMAL "\n", color, text);
    else
	printf("%s\n", text);
}

#ifdef __APPLE__
static void *find_symbol(struct ctest *test, const char *fname)
{
    size_t len = strlen(test->ssname) + 1 + strlen(fname);
    char *symbol_name = (char *) calloc(len + 1, sizeof(char));
    memset(symbol_name, 0, len + 1);
    snprintf(symbol_name, len + 1, "%s_%s", test->ssname, fname);

    //fprintf(stderr, ">>>> dlsym: loading %s\n", symbol_name);
    void *symbol = dlsym(RTLD_DEFAULT, symbol_name);
    if (!symbol) {
	//fprintf(stderr, ">>>> ERROR: %s\n", dlerror());
    }
    // returns NULL on error

    free(symbol_name);
    return symbol;
}
#endif

#ifdef TESTING
#ifndef __APPLE__
#include <signal.h>
#endif

static void sighandler(int signum)
{
    char msg[128];
    sprintf(msg, "[SIGNAL %d]", signum);
    color_print(ANSI_BRED, msg);
    fflush(stdout);

    /* "Unregister" the signal handler and send the signal back to the process
     * so it can terminate as expected */
    signal(signum, SIG_DFL);
    kill(getpid(), signum);
}
#endif

int ctest_main(int argc, const char *argv[])
{
    static int total = 0;
    static int num_ok = 0;
    static int num_fail = 0;
    static int num_skip = 0;
    static int index = 1;
    static filter_func filter = suite_all;

#ifdef CTEST_SEGFAULT
    signal(SIGSEGV, sighandler);
#endif

    if (argc == 2) {
	suite_name = argv[1];
	filter = suite_filter;
    }
#ifdef CTEST_NO_COLORS
    color_output = 0;
#else
    color_output = isatty(1);
#endif
    uint64_t t1 = getCurrentTime();

    struct ctest* ctest_begin = &__TNAME(suite, test);
    struct ctest* ctest_end = &__TNAME(suite, test);
    // find begin and end of section by comparing magics
    while (1) {
	struct ctest* t = ctest_begin-1;
	if (t->magic != __CTEST_MAGIC) break;
	ctest_begin--;
    }
    while (1) {
	struct ctest* t = ctest_end+1;
	if (t->magic != __CTEST_MAGIC) break;
	ctest_end++;
    }
    ctest_end++;    // end after last one

    static struct ctest* test;
    for (test = ctest_begin; test != ctest_end; test++) {
	if (test == &__TNAME(suite, test)) continue;
	if (filter(test)) total++;
    }

    for (test = ctest_begin; test != ctest_end; test++) {
	if (test == &__TNAME(suite, test)) continue;
	if (filter(test)) {
	    ctest_errorbuffer[0] = 0;
	    ctest_errorsize = MSG_SIZE-1;
	    ctest_errormsg = ctest_errorbuffer;
	    printf("TEST %d/%d %s:%s ", index, total, test->ssname, test->ttname);
	    fflush(stdout);
	    if (test->skip) {
		color_print(ANSI_BYELLOW, "[SKIPPED]");
		num_skip++;
	    } else {
		int result = setjmp(ctest_err);
		if (result == 0) {
#ifdef __APPLE__
		    if (!test->setup) {
			test->setup = (SetupFunc) find_symbol(test, "setup");
		    }
		    if (!test->teardown) {
			test->teardown = (TearDownFunc) find_symbol(test, "teardown");
		    }
#endif

		    if (test->setup) test->setup(test->data);
//                    if (test->data)
//                        test->run(test->data);
//                    else
		    test->run();
		    if (test->teardown) test->teardown(test->data);
		    // if we got here it's ok
#ifdef CTEST_COLOR_OK
		    color_print(ANSI_GREEN, "[OK]");
#else
		    color_print(ANSI_GREEN, "[OK]");
#endif
		    num_ok++;
		} else {
		    color_print(ANSI_BRED, "[FAIL]");
		    num_fail++;
		}
		if (ctest_errorsize != MSG_SIZE-1) printf("%s", ctest_errorbuffer);
	    }
	    index++;
	}
    }
    uint64_t t2 = getCurrentTime();

    const char* color = (num_fail) ? ANSI_BRED : ANSI_GREEN;
    char results[80];
    sprintf(results, "RESULTS: %d tests (%d ok, %d failed, %d skipped) ran in %" PRIu64 " ms", total, num_ok, num_fail, num_skip, (t2 - t1)/1000);
    color_print(color, results);
    return num_fail;
}

#endif

#endif//NATIVE_KERNEL_TEST_H

#define TEST CTEST