#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef double (*meower_t)(double);

void meow(meower_t meower, const char *word, double x_min, double x_max, double x_step,
    double y_min, double y_max, double y_step) {
	size_t len = strlen(word);
	for (double x = x_min; x <= x_max; x += x_step) {
		double y_val = meower(x);
		for (double y = y_min; y <= y_max; y += y_step) {
			if ((y_val > 0 && 0 <= y && y <= y_val) || (y_val < 0 && 0 >= y && y >= y_val)) {
				uint32_t index = y > 0 ? y / y_step : -y / y_step;
				fputc(word[index % len], stdout);
			} else {
				fputc(' ', stdout);
			}
		}
		fputc('\n', stdout);
	}
}

double normal(double x) {
	return exp(-(x * x));
}

double bigO(double x) {
	return x * log2(x);
}

int main(void) {
	meow(tan, "meow ", -M_PI, M_PI, M_PI / 12, -5.0, 5.0, 0.5);
	return 0;
}
