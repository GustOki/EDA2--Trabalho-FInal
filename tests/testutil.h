#ifndef TESTUTIL_H
#define TESTUTIL_H

#include <stdio.h>
#include <stdlib.h>

static int tests_run    = 0;
static int tests_failed = 0;

#define CHECK(cond, msg) do { \
    tests_run++; \
    if (!(cond)) { \
        fprintf(stderr, "  FAIL [linha %d]: %s\n", __LINE__, msg); \
        tests_failed++; \
    } \
} while(0)

#define TEST_SUMMARY() do { \
    printf("%d/%d testes passaram\n", tests_run - tests_failed, tests_run); \
    return tests_failed > 0 ? 1 : 0; \
} while(0)

#endif
