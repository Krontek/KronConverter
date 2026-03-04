/*===========================================================================
 * KronConverter — Test Suite
 * Build: tcc test.c kronconverter.c -o test_app && ./test_app
 *===========================================================================*/

#include "kronconverter.h"
#include <stdio.h>

static int pass_count = 0;
static int fail_count = 0;

static void check(const char *name, int condition)
{
    if (condition) {
        pass_count++;
        printf("PASS: %s\n", name);
    } else {
        fail_count++;
        printf("FAIL: %s\n", name);
    }
}

/*===========================================================================
 * FROM BOOL (7 tests)
 *===========================================================================*/
static void test_from_bool(void)
{
    printf("\n--- FROM BOOL ---\n");
    check("BOOL_TO_UINT8  true  == 1",   KRON_BOOL_TO_UINT8(true)   == 1);
    check("BOOL_TO_UINT8  false == 0",   KRON_BOOL_TO_UINT8(false)  == 0);
    check("BOOL_TO_UINT16 true  == 1",   KRON_BOOL_TO_UINT16(true)  == 1);
    check("BOOL_TO_UINT16 false == 0",   KRON_BOOL_TO_UINT16(false) == 0);
    check("BOOL_TO_UINT32 true  == 1",   KRON_BOOL_TO_UINT32(true)  == 1);
    check("BOOL_TO_UINT32 false == 0",   KRON_BOOL_TO_UINT32(false) == 0);
    check("BOOL_TO_INT8   true  == 1",   KRON_BOOL_TO_INT8(true)    == 1);
    check("BOOL_TO_INT8   false == 0",   KRON_BOOL_TO_INT8(false)   == 0);
    check("BOOL_TO_INT16  true  == 1",   KRON_BOOL_TO_INT16(true)   == 1);
    check("BOOL_TO_INT16  false == 0",   KRON_BOOL_TO_INT16(false)  == 0);
    check("BOOL_TO_INT32  true  == 1",   KRON_BOOL_TO_INT32(true)   == 1);
    check("BOOL_TO_INT32  false == 0",   KRON_BOOL_TO_INT32(false)  == 0);
    check("BOOL_TO_REAL   true  == 1.0", KRON_BOOL_TO_REAL(true)    == 1.0f);
    check("BOOL_TO_REAL   false == 0.0", KRON_BOOL_TO_REAL(false)   == 0.0f);
}

/*===========================================================================
 * FROM UINT8 (7 tests)
 *===========================================================================*/
static void test_from_uint8(void)
{
    printf("\n--- FROM UINT8 ---\n");
    /* → BOOL */
    check("UINT8_TO_BOOL  0   == false", KRON_UINT8_TO_BOOL(0)    == false);
    check("UINT8_TO_BOOL  1   == true",  KRON_UINT8_TO_BOOL(1)    == true);
    check("UINT8_TO_BOOL  255 == true",  KRON_UINT8_TO_BOOL(255)  == true);
    /* → UINT16 */
    check("UINT8_TO_UINT16 200 == 200",  KRON_UINT8_TO_UINT16(200) == 200);
    /* → UINT32 */
    check("UINT8_TO_UINT32 255 == 255",  KRON_UINT8_TO_UINT32(255) == 255u);
    /* → INT8 : 127 stays positive */
    check("UINT8_TO_INT8  127 == 127",   KRON_UINT8_TO_INT8(127)  == 127);
    /* → INT8 : 128 wraps to -128 on two's complement */
    check("UINT8_TO_INT8  128 == -128",  KRON_UINT8_TO_INT8(128)  == -128);
    /* → INT8 : 255 wraps to -1 */
    check("UINT8_TO_INT8  255 == -1",    KRON_UINT8_TO_INT8(255)  == -1);
    /* → INT16 : zero-extend, always non-negative */
    check("UINT8_TO_INT16 255 == 255",   KRON_UINT8_TO_INT16(255) == 255);
    /* → INT32 */
    check("UINT8_TO_INT32 255 == 255",   KRON_UINT8_TO_INT32(255) == 255);
    /* → REAL */
    check("UINT8_TO_REAL  100 == 100.0", KRON_UINT8_TO_REAL(100)  == 100.0f);
    check("UINT8_TO_REAL  0   == 0.0",   KRON_UINT8_TO_REAL(0)    == 0.0f);
}

/*===========================================================================
 * FROM UINT16 (7 tests)
 *===========================================================================*/
static void test_from_uint16(void)
{
    printf("\n--- FROM UINT16 ---\n");
    check("UINT16_TO_BOOL   0     == false", KRON_UINT16_TO_BOOL(0)     == false);
    check("UINT16_TO_BOOL   65535 == true",  KRON_UINT16_TO_BOOL(65535) == true);
    /* → UINT8 : truncate low byte */
    check("UINT16_TO_UINT8  256   == 0",     KRON_UINT16_TO_UINT8(256)  == 0);
    check("UINT16_TO_UINT8  257   == 1",     KRON_UINT16_TO_UINT8(257)  == 1);
    check("UINT16_TO_UINT8  300   == 44",    KRON_UINT16_TO_UINT8(300)  == 44);
    /* → UINT32 : zero-extend */
    check("UINT16_TO_UINT32 65535 == 65535", KRON_UINT16_TO_UINT32(65535) == 65535u);
    /* → INT8  : truncate low byte, reinterpret */
    check("UINT16_TO_INT8   255   == -1",    KRON_UINT16_TO_INT8(255)   == -1);
    check("UINT16_TO_INT8   128   == -128",  KRON_UINT16_TO_INT8(128)   == -128);
    /* → INT16 : reinterpret; 32768 → -32768 */
    check("UINT16_TO_INT16  32767 == 32767", KRON_UINT16_TO_INT16(32767) == 32767);
    check("UINT16_TO_INT16  32768 == -32768",KRON_UINT16_TO_INT16(32768) == -32768);
    check("UINT16_TO_INT16  65535 == -1",    KRON_UINT16_TO_INT16(65535) == -1);
    /* → INT32 : zero-extend, always non-negative */
    check("UINT16_TO_INT32  65535 == 65535", KRON_UINT16_TO_INT32(65535) == 65535);
    /* → REAL */
    check("UINT16_TO_REAL   1000  == 1000.0",KRON_UINT16_TO_REAL(1000)  == 1000.0f);
}

/*===========================================================================
 * FROM UINT32 (7 tests)
 *===========================================================================*/
static void test_from_uint32(void)
{
    printf("\n--- FROM UINT32 ---\n");
    check("UINT32_TO_BOOL   0          == false", KRON_UINT32_TO_BOOL(0u)         == false);
    check("UINT32_TO_BOOL   4294967295 == true",  KRON_UINT32_TO_BOOL(4294967295u)== true);
    /* → UINT8 : keep low byte */
    check("UINT32_TO_UINT8  256        == 0",     KRON_UINT32_TO_UINT8(256u)      == 0);
    check("UINT32_TO_UINT8  0x1234     == 0x34",  KRON_UINT32_TO_UINT8(0x1234u)   == 0x34);
    /* → UINT16 : keep low 2 bytes */
    check("UINT32_TO_UINT16 0x12345678 == 0x5678",KRON_UINT32_TO_UINT16(0x12345678u) == 0x5678u);
    /* → INT8 */
    check("UINT32_TO_INT8   0xFF       == -1",    KRON_UINT32_TO_INT8(0xFFu)      == -1);
    /* → INT16 */
    check("UINT32_TO_INT16  0xFFFF     == -1",    KRON_UINT32_TO_INT16(0xFFFFu)   == -1);
    /* → INT32 : reinterpret; 2147483648 → -2147483648 */
    check("UINT32_TO_INT32  2147483647 == 2147483647",
          KRON_UINT32_TO_INT32(2147483647u) == 2147483647);
    check("UINT32_TO_INT32  2147483648 == -2147483648",
          KRON_UINT32_TO_INT32(2147483648u) == (int32_t)(-2147483648));
    /* → REAL : exact for small values */
    check("UINT32_TO_REAL   1000       == 1000.0",KRON_UINT32_TO_REAL(1000u)      == 1000.0f);
}

/*===========================================================================
 * FROM INT8 (7 tests)
 *===========================================================================*/
static void test_from_int8(void)
{
    printf("\n--- FROM INT8 ---\n");
    check("INT8_TO_BOOL    0   == false", KRON_INT8_TO_BOOL(0)    == false);
    check("INT8_TO_BOOL    1   == true",  KRON_INT8_TO_BOOL(1)    == true);
    check("INT8_TO_BOOL   -1   == true",  KRON_INT8_TO_BOOL(-1)   == true);
    /* → UINT8 : -1 → 255 */
    check("INT8_TO_UINT8  -1   == 255",   KRON_INT8_TO_UINT8(-1)  == 255);
    check("INT8_TO_UINT8  -128 == 128",   KRON_INT8_TO_UINT8(-128)== 128);
    check("INT8_TO_UINT8   127 == 127",   KRON_INT8_TO_UINT8(127) == 127);
    /* → UINT16 : sign-extend to int16 then to uint16; -1 → 0xFFFF */
    check("INT8_TO_UINT16 -1   == 65535", KRON_INT8_TO_UINT16(-1) == 65535u);
    check("INT8_TO_UINT16  10  == 10",    KRON_INT8_TO_UINT16(10) == 10u);
    /* → UINT32 : sign-extend; -1 → 0xFFFFFFFF */
    check("INT8_TO_UINT32 -1   == 4294967295",
          KRON_INT8_TO_UINT32(-1) == 4294967295u);
    /* → INT16 */
    check("INT8_TO_INT16  -128 == -128",  KRON_INT8_TO_INT16(-128) == -128);
    check("INT8_TO_INT16   127 == 127",   KRON_INT8_TO_INT16(127)  == 127);
    /* → INT32 */
    check("INT8_TO_INT32  -1   == -1",    KRON_INT8_TO_INT32(-1)   == -1);
    /* → REAL */
    check("INT8_TO_REAL   -128 == -128.0",KRON_INT8_TO_REAL(-128)  == -128.0f);
    check("INT8_TO_REAL    127 == 127.0", KRON_INT8_TO_REAL(127)   == 127.0f);
}

/*===========================================================================
 * FROM INT16 (7 tests)
 *===========================================================================*/
static void test_from_int16(void)
{
    printf("\n--- FROM INT16 ---\n");
    check("INT16_TO_BOOL    0      == false", KRON_INT16_TO_BOOL(0)     == false);
    check("INT16_TO_BOOL   -32768  == true",  KRON_INT16_TO_BOOL(-32768)== true);
    /* → UINT8 : truncate low byte */
    check("INT16_TO_UINT8  256     == 0",     KRON_INT16_TO_UINT8(256)  == 0);
    check("INT16_TO_UINT8  -1      == 255",   KRON_INT16_TO_UINT8(-1)   == 255);
    /* → UINT16 : reinterpret; -1 → 65535 */
    check("INT16_TO_UINT16 -1      == 65535", KRON_INT16_TO_UINT16(-1)  == 65535u);
    check("INT16_TO_UINT16 -32768  == 32768", KRON_INT16_TO_UINT16(-32768) == 32768u);
    check("INT16_TO_UINT16  32767  == 32767", KRON_INT16_TO_UINT16(32767) == 32767u);
    /* → UINT32 : sign-extend; -1 → 0xFFFFFFFF */
    check("INT16_TO_UINT32 -1      == 4294967295",
          KRON_INT16_TO_UINT32(-1) == 4294967295u);
    check("INT16_TO_UINT32  100    == 100",   KRON_INT16_TO_UINT32(100) == 100u);
    /* → INT8 : truncate */
    check("INT16_TO_INT8   256     == 0",     KRON_INT16_TO_INT8(256)   == 0);
    check("INT16_TO_INT8   127     == 127",   KRON_INT16_TO_INT8(127)   == 127);
    /* → INT32 */
    check("INT16_TO_INT32  -32768  == -32768",KRON_INT16_TO_INT32(-32768) == -32768);
    /* → REAL */
    check("INT16_TO_REAL   -1000   == -1000.0",KRON_INT16_TO_REAL(-1000) == -1000.0f);
}

/*===========================================================================
 * FROM INT32 (7 tests)
 *===========================================================================*/
static void test_from_int32(void)
{
    printf("\n--- FROM INT32 ---\n");
    check("INT32_TO_BOOL    0          == false", KRON_INT32_TO_BOOL(0)           == false);
    check("INT32_TO_BOOL   -2147483648 == true",  KRON_INT32_TO_BOOL(-2147483648) == true);
    /* → UINT8 */
    check("INT32_TO_UINT8  -1          == 255",   KRON_INT32_TO_UINT8(-1)         == 255);
    check("INT32_TO_UINT8   256        == 0",     KRON_INT32_TO_UINT8(256)        == 0);
    /* → UINT16 */
    check("INT32_TO_UINT16 -1          == 65535", KRON_INT32_TO_UINT16(-1)        == 65535u);
    /* → UINT32 */
    check("INT32_TO_UINT32 -1          == 4294967295",
          KRON_INT32_TO_UINT32(-1) == 4294967295u);
    /* → INT8 : truncate low byte */
    check("INT32_TO_INT8   128         == -128",  KRON_INT32_TO_INT8(128)         == -128);
    check("INT32_TO_INT8   127         == 127",   KRON_INT32_TO_INT8(127)         == 127);
    /* → INT16 */
    check("INT32_TO_INT16  32768       == -32768",KRON_INT32_TO_INT16(32768)      == -32768);
    check("INT32_TO_INT16 -1           == -1",    KRON_INT32_TO_INT16(-1)         == -1);
    /* → REAL : exact for small values */
    check("INT32_TO_REAL   -100        == -100.0",KRON_INT32_TO_REAL(-100)        == -100.0f);
    check("INT32_TO_REAL    0          == 0.0",   KRON_INT32_TO_REAL(0)           == 0.0f);
}

/*===========================================================================
 * FROM REAL (7 tests)
 *===========================================================================*/
static void test_from_real(void)
{
    printf("\n--- FROM REAL ---\n");
    /* → BOOL : 0.0 → false, nonzero → true */
    check("REAL_TO_BOOL   0.0  == false", KRON_REAL_TO_BOOL(0.0f)  == false);
    check("REAL_TO_BOOL   1.0  == true",  KRON_REAL_TO_BOOL(1.0f)  == true);
    check("REAL_TO_BOOL  -1.0  == true",  KRON_REAL_TO_BOOL(-1.0f) == true);
    check("REAL_TO_BOOL   0.5  == true",  KRON_REAL_TO_BOOL(0.5f)  == true);
    /* → UINT8 : truncate toward zero */
    check("REAL_TO_UINT8  3.9  == 3",     KRON_REAL_TO_UINT8(3.9f)  == 3);
    check("REAL_TO_UINT8  0.0  == 0",     KRON_REAL_TO_UINT8(0.0f)  == 0);
    check("REAL_TO_UINT8  255.0== 255",   KRON_REAL_TO_UINT8(255.0f)== 255);
    /* → UINT16 */
    check("REAL_TO_UINT16 1000.7 == 1000",KRON_REAL_TO_UINT16(1000.7f) == 1000);
    check("REAL_TO_UINT16 0.9    == 0",   KRON_REAL_TO_UINT16(0.9f)    == 0);
    /* → UINT32 */
    check("REAL_TO_UINT32 65536.0 == 65536",KRON_REAL_TO_UINT32(65536.0f) == 65536u);
    /* → INT8 : truncate */
    check("REAL_TO_INT8   -1.9  == -1",   KRON_REAL_TO_INT8(-1.9f) == -1);
    check("REAL_TO_INT8    3.7  == 3",    KRON_REAL_TO_INT8(3.7f)  == 3);
    check("REAL_TO_INT8  127.0  == 127",  KRON_REAL_TO_INT8(127.0f)== 127);
    /* → INT16 */
    check("REAL_TO_INT16 -100.5 == -100", KRON_REAL_TO_INT16(-100.5f) == -100);
    check("REAL_TO_INT16  500.9 == 500",  KRON_REAL_TO_INT16(500.9f)  == 500);
    /* → INT32 */
    check("REAL_TO_INT32 -3.14  == -3",   KRON_REAL_TO_INT32(-3.14f) == -3);
    check("REAL_TO_INT32  1e6   == 1000000",KRON_REAL_TO_INT32(1e6f) == 1000000);
}

/*===========================================================================
 * Roundtrip tests — convert A→B→A and verify identity holds where possible
 *===========================================================================*/
static void test_roundtrips(void)
{
    printf("\n--- Roundtrips ---\n");
    /* bool → uint8 → bool */
    check("bool→uint8→bool  true",  KRON_UINT8_TO_BOOL(KRON_BOOL_TO_UINT8(true))  == true);
    check("bool→uint8→bool  false", KRON_UINT8_TO_BOOL(KRON_BOOL_TO_UINT8(false)) == false);
    /* bool → real → bool */
    check("bool→real→bool   true",  KRON_REAL_TO_BOOL(KRON_BOOL_TO_REAL(true))    == true);
    check("bool→real→bool   false", KRON_REAL_TO_BOOL(KRON_BOOL_TO_REAL(false))   == false);
    /* uint8 → uint16 → uint8 */
    check("uint8→uint16→uint8 200", KRON_UINT16_TO_UINT8(KRON_UINT8_TO_UINT16(200)) == 200);
    /* uint8 → real → uint8 */
    check("uint8→real→uint8  200",  KRON_REAL_TO_UINT8(KRON_UINT8_TO_REAL(200)) == 200);
    /* int8 → int16 → int8 */
    check("int8→int16→int8  -50",   KRON_INT16_TO_INT8(KRON_INT8_TO_INT16(-50)) == -50);
    /* int16 → int32 → int16 */
    check("int16→int32→int16 -30000",
          KRON_INT32_TO_INT16(KRON_INT16_TO_INT32(-30000)) == -30000);
    /* uint16 → uint32 → uint16 */
    check("uint16→uint32→uint16 60000",
          KRON_UINT32_TO_UINT16(KRON_UINT16_TO_UINT32(60000)) == 60000u);
    /* int8 → real → int8 (exact for -128..127) */
    check("int8→real→int8   -100", KRON_REAL_TO_INT8(KRON_INT8_TO_REAL(-100)) == -100);
    check("int8→real→int8    100", KRON_REAL_TO_INT8(KRON_INT8_TO_REAL(100))  == 100);
    /* int32 → real → int32 (exact for small values) */
    check("int32→real→int32  12345",
          KRON_REAL_TO_INT32(KRON_INT32_TO_REAL(12345)) == 12345);
}

/*===========================================================================
 * main
 *===========================================================================*/
int main(void)
{
    printf("=== KronConverter Test Suite ===\n");
    printf("N=8 types, N*(N-1) = 56 conversion functions\n");

    test_from_bool();
    test_from_uint8();
    test_from_uint16();
    test_from_uint32();
    test_from_int8();
    test_from_int16();
    test_from_int32();
    test_from_real();
    test_roundtrips();

    printf("\n=== Results: %d passed, %d failed ===\n", pass_count, fail_count);
    return (fail_count == 0) ? 0 : 1;
}
