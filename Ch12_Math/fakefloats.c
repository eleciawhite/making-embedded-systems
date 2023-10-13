#include <stdio.h>
#include <stdint.h>
#include <assert.h>

struct sFakeFloat16 {
  int8_t num;
  int8_t shift;
};

struct sFakeFloat16 ff16Add (struct sFakeFloat16 a, struct sFakeFloat16 b)
{
    struct sFakeFloat16 result;
    int16_t tmp;
    if (b.shift >= a.shift)
    {
        tmp = a.num;
        tmp = tmp << (b.shift - a.shift);
        tmp = tmp + b.num;
        result.shift = b.shift;
    } else {
        tmp = b.num;
        tmp = tmp << (a.shift - b.shift);
        tmp = tmp + a.num;
        result.shift = a.shift;
    }
    while (tmp > INT8_MAX || tmp < -INT8_MAX) {
        tmp = tmp >> 1;
        result.shift--;
    }
    result.num = tmp;
    return result;
}

void ff16Print(char* note, struct sFakeFloat16 f)
{
    float ff = f.num;
    ff = ff / (1 << f.shift);
    printf("%s %d/(2^(%d)) = %0.4f\r\n", note, f.num, f.shift, ff);
}

struct sFakeFloat40 {
  int32_t num;
  int8_t shift;
} ;

struct sFakeFloat40 ff40Mult(struct sFakeFloat40 a, struct sFakeFloat40 b)
{
    struct sFakeFloat40 result;
    int64_t tmp;

    tmp = a.shift + b.shift;
    assert(tmp < INT8_MAX);
    result.shift = tmp;

    tmp = a.num;
    tmp = tmp * b.num;
    while (tmp > INT32_MAX || tmp < -INT32_MAX) {
        tmp = tmp >> 1;
        result.shift--;
    }
    result.num = tmp;
    return result;



}
void ff40Print(char* note, struct sFakeFloat40 f)
{
    float ff = f.num;
    ff = ff / (1 << f.shift);
    printf("%s %d/(2^(%d)) = %0.4f\r\n", note, f.num, f.shift, ff);
}

int main()
{
    {
        struct sFakeFloat16 a = { 99, 3 };  // 12.375,   not quite 12.345
        struct sFakeFloat16 b = {111, 5 };  //  3.46875, not quite 3.456

        struct sFakeFloat16 result = ff16Add(a, b); // hoping for 15.8438, getting 15.750
        ff16Print("a =", a);
        ff16Print("b =", b);
        ff16Print("a+b = ", result);
    }

    {
        struct sFakeFloat40 a = { 1656917852,  27 }; // 12.345
        struct sFakeFloat40 b = { 128, 8};   // 0.5
        struct sFakeFloat40 result = ff40Mult(a, b); // hoping for 6.1725

        ff40Print("a =", a);
        ff40Print("b =", b);
        ff40Print("a*b = ", result);        
    }
}


