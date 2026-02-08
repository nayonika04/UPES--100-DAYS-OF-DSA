#include <stdio.h>
double power(double base, int exp) {
    if (exp == 0) {
        return 1;
    }
    // If the exponent is positive, multiply the base by the result of the recursive call with exp-1
    else if (exp > 0) {
        return base * power(base, exp - 1);
    }
    // If the exponent is negative, compute 1 / (base^(-exp))
    else {
        return 1.0 / (base * power(base, -exp - 1));
    }
}

int main() {
    double base;
    int exp;
    double result;

    // Prompt for input
    printf("Enter two space-separated integers a and b: ");
    if (scanf("%lf %d", &base, &exp) != 2) {
        printf("Invalid input. Please enter two numbers.\n");
        return 1;
    }

    // Calculate the power
    result = power(base, exp);

    // Print the result with appropriate formatting
    // For integer results (like 2^5), format as int. Otherwise, format as double.
    if (exp >= 0 && base == (int)base && result == (int)result) {
        printf("Output: %d\n", (int)result);
    } else {
        printf("Output: %.4f\n", result);
    }

    return 0;
}
