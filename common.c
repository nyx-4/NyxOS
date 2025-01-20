#include "common.h"

void putchar(char ch);

void* memset(void* buf, char c, size_t n) {
    uint8_t* p = (uint8_t*)buf;
    while (n--)
        *p++ = c;
    return buf;
}

void* memcpy(void* dst, const void* src, size_t n) {
    uint8_t* d = (uint8_t*)dst;
    const uint8_t* s = (const uint8_t*)src;
    while (n--) *d++ = *s++;
    return dst;
}

char* strcpy(char* dst, const char* src) {
    char* d = dst;
    while (*src)
        *d++ = *s++;
    *d = '\0';
    return dst;
}

int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) break;
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

void printf(const char* fmt, ...) {
    va_list vargs;
    va_start(vargs, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;  // Ignore %
            int value, divisor;
            const char* s;

            switch (*fmt) {
                case '\0': putchar('%'); goto end;
                case '%': putchar('%'); break;
                case 's':
                    s = va_arg(vargs, const char*);
                    while (*s) { putchar(*s);s++; }
                    break;
                case 'd':
                    value = va_arg(vargs, int);
                    if (value < 0) { putchar('-'); value = -value; }
                    divisor = 1;

                    while (value / divisor > 9) divisor *= 10;

                    while (divisor > 0) {
                        putchar('0' + value / divisor);
                        value %= divisor;
                        divisor /= 10;
                    }

                    break;
                case'x':
                    value = va_arg(vargs, int);
                    for (int i = 7; i >= 0; i--)
                        putchar("0123456789ABCDEF"[(value >> (i * 4)) & 0xf]);
                    break;
            }
        }
        else  // If normal character
            putchar(*fmt);

        fmt++;
    }

end:
    va_end(vargs);
}