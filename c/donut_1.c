//badger
#include <stdlib.h>//system()
#include <stdio.h>//printf()
#include <stdbool.h>//try,catch(),throw()
//#include <setjmp.h>
#include <string.h>//memset()
#include <math.h>//sin()
#include <windows.h>//SetConsoleTitle()

//error handling
#define try bool error=false;
#define catch(A1) ExitJmp:if(error==true)
#define throw(A1) error=true; goto ExitJmp;

//values used
const double pi = 3.141592;
const float speed = 1;
void sleep(int A1) { usleep(A1 * 100000); };

//runs when program starts
int main() {
	try {
		SetConsoleTitle("DONUT_TIME!");

		float A = 0, B = 0;
		const int size = 1760;
		float z[size];
		char b[size];
		printf("\x1b[2J");
		for (;;) {
			//if (getchar() == 0) { exit(0); }//' '
			memset(b, 32, size);
			memset(z, 0, 7040);
			for (float j = 0; j < pi * 2; j += 0.07) {
				for (float i = 0; i < pi * 2; i += 0.02) {
					float c = sin(i);
					float d = cos(j);
					float e = sin(A);
					float f = sin(j);
					float g = cos(A);
					float h = d + 2;
					float D = 1 / (c * h * e + f * g + 5);
					float l = cos(i);
					float m = cos(B);
					float n = sin(B);
					float t = c * h * g - f * e;
					int x = 40 + 30 * D * (l * h * m - t * n);
					int y = 12 + 15 * D * (l * h * n + t * m);
					int o = x + 80 * y;
					int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
					if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) { z[o] = D; b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0]; }
				}
			}
			printf("\x1b[H");
			for (int a = 0; a < size; a++) { putchar(a % 80 ? b[a] : 10); A += 0.00004; B += A / 2; }
			sleep(1 / (int)speed >> 1); system("cls");
		}
	}
	catch (A) { printf("ERROR: PROGRAM FAILED!"); throw("ERROR" + A + "!"); }
	return 0;
};