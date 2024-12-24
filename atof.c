#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

float atof(const char *str) {
    float result = 0.0;
    float fraction = 0.0;
    float divisor = 1.0;
    int sign = 1;
    bool is_fraction = false;

    // Skip leading whitespace
    while (isspace(*str)) {
        str++;
    }

    // Check for optional sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert digits
    while (*str) {
        if (isdigit(*str)) {
            if (is_fraction) {
                fraction = fraction * 10 + (*str - '0');
                divisor *= 10;
            } else {
                result = result * 10 + (*str - '0');
            }
        } else if (*str == '.' && !is_fraction) {
            is_fraction = true;
        } else {
            // Invalid character; stop parsing
            break;
        }
        str++;
    }

    // Combine integer and fraction parts
    result += fraction / divisor;

    return sign * result;
}

int main() {
    const char *str1 = "  -123.456hh";
    const char *str2 = "3.14159";
    const char *str3 = "+0.001";

    printf("String: '%s' => Float: %f\n", str1, atof(str1));
    printf("String: '%s' => Float: %f\n", str2, atof(str2));
    printf("String: '%s' => Float: %f\n", str3, atof(str3));

    return 0;
}
