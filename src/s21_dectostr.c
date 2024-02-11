#include "s21_decimal.h"
#include <math.h>

char* dectostr(s21_decimal dec) {
    bool negative = dec.bits[3] & 0x80000000;
    int e = extract_exp(dec.bits[3]);
    char *str = utoa(0);

    str = calculate_decimal(str, dec.bits);

    return res;
}

int extract_exp(const unsigned bits) {
    unsigned mask = 1 << 16;
    int e = 0;
    int power = -1;

    while (++power <= 8) {
        e += (bits & mask) ? pow(2, power) : 0;
        mask <<= 1;
    }

    return e;
}

char *calculate_decimal(char *str, const unsigned *bits) {
    int i = 3;
    unsigned mask = 1;
    int power = 0;
    char *power_of_2 = utoa(1);
    int prev_p = 0;

    while (--i >= 0) {
        while (mask) {
            if (bits[i] & mask) {
                char *addendum = raise_power_of_2(*power_of_2, p - prev_p + 1);
                power_of_2 = addendum;
                prev_p = p;
                char *tmp = str;
                str = stradd(str, addendum);
                free(tmp);
            }
            mask <<= 1;
            ++power;
        }
        mask = 1;
    }
    free(power_of_2);

    return str;
}

char *utoa(unsigned d) {
    int i = ulen(d);
    char *str = (char *)calloc(i + 1, sizeof(char));

    do {
        str[--i] = d % 10;
        str[i] += 48;
        d /= 10;
    } while (d);

    return str;
}

int ulen(unsigned d) {
    int i = 1;
    while (d / 10) {
        ++i;
        d /= 10;
    }
    return i;
}

char *raise_power_of_2(char *str, int n) {
    while (--n) {
        char *tmp = str;
        str = stradd(str, str);
        free(tmp);
    }
    return str;
}

char *stradd(char *l_str, char *r_str) {
    int i = strlen(l_str) - 1;
    int j = strlen(r_str) - 1;
    int k = max(i, j) - 1;
    char *res = (char *)calloc(k + 1, sizeof(char));
    bool overflow = false;

    while (--k >= 0) {
        res[k] = (i >= 0 && i < l_len && j >= 0 && j < r_len ? -48 : 0) +
                 (i >= 0 && i < l_len ? l_str[i] : 0) +
                 (j >= 0 && j < r_len ? r_str[j] : 0) + overflow;
        overflow = res[k] > 57;
        res[k] -= res[k] > 57 ? 10 : 0;
        --i;
        --j;
    }
    res = overflow ? add_width(res, 1, '1', true) : res;

    return res;
}

char *add_width(char *str, int num, char value, bool right_alignment) {
    int j = s21_strlen(str);
    int i = j + num + 1;
    str = (char *)realloc(str, i * sizeof(char));

    str[--i] = '\0';
    if (right_alignment) {
        while (--i >= num) str[i] = str[i - num];
        ++i;
        while (--i >= 0) str[i] = value;
    } else {
        --j;
        while (++j < i) str[j] = value;
    }

    return str;
}