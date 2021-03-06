﻿#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(){
	//print sizes for char,short,int,long - signed and unsigned
	printf("Header\n");
	printf("\tSigned char MIN:%d\n", SCHAR_MIN);
	printf("\tSigned char MAX:%d\n", SCHAR_MAX);
	printf("\tUnSigned char MAX:%u\n", UCHAR_MAX);

	printf("\tSigned short MIN:%d\n", SHRT_MIN);
	printf("\tSigned short MAX:%d\n", SHRT_MAX);
	printf("\tUnSigned short MAX:%u\n", USHRT_MAX);

	printf("\tSigned int MIN:%d\n", INT_MIN);
	printf("\tSigned int MAX:%d\n", INT_MAX);
	printf("\tUnSigned int MAX:%u\n", UINT_MAX);

	printf("\tSigned long MIN:%ld\n", LONG_MIN);
	printf("\tSigned long MAX:%ld\n", LONG_MAX);
	printf("\tUnSigned long MAX:%lu\n", ULONG_MAX);

	printf("\tSigned float MIN:%e\n", FLT_MIN);
	printf("\tSigned float MAX:%e\n", FLT_MAX);

	printf("\tSigned double MIN:%e\n", DBL_MIN);
	printf("\tSigned double MAX:%e\n", DBL_MAX);

	printf("\nComputed\n");
	printf("\tSigned char MIN:-%.0f\n", pow(2, (sizeof(char) * 8) - 1));
	printf("\tSigned char MAX:%.0f\n", pow(2, (sizeof(char) * 8) - 1) - 1);
	printf("\tUnSigned char MAX:%.0f\n", pow(2, sizeof(char) * 8) - 1);

	printf("\tSigned short MIN:-%.0f\n", pow(2, (sizeof(short) * 8) - 1));
	printf("\tSigned short MAX:%.0f\n", pow(2, (sizeof(short) * 8) - 1) - 1);
	printf("\tUnSigned short MAX:%.0f\n", pow(2, sizeof(short) * 8) - 1);

	printf("\tSigned int MIN:-%.0f\n", pow(2, (sizeof(int) * 8) - 1));
	printf("\tSigned int MAX:%.0f\n", pow(2, (sizeof(int) * 8) - 1) - 1);
	printf("\tUnSigned int MAX:%.0f\n", pow(2, sizeof(int) * 8) - 1);

	printf("\tSigned long MIN:-%.0f\n", pow(2, (sizeof(long) * 8) - 1));
	printf("\tSigned long MAX:%.0f\n", pow(2, (sizeof(long) * 8) - 1) - 1);
	printf("\tUnSigned long MAX:%.0f\n", pow(2, sizeof(long) * 8) - 1);

	//We can use the  IEEE 754 binary type formula to find the maximum values for float\double.2^(2^(e-1)) * (1 - 2^-p).
	//e - no. of exponent bits and p-no. of mantissa bits. Now there is a bunch of stuff going on here, but the easier way to compute is this.
	//For float the range of 2^(e-1) is from -126 to 128 (since float stores the sign with a bias).
	//For double the range of 2^(e-1) is from -1022 to 1024(since double alos stores the sign with a bias).
	printf("\tSigned float MIN:%e\n", pow(2, -126)*(1 - pow(2, -24)));
	printf("\tSigned float MAX:%e\n", pow(2, 128)*(1 - pow(2, -24)));

	printf("\tSigned double MIN:%e\n", pow(2, -1022)*(1 - pow(2, -54)));
	printf("\tSigned double MAX:%e\n", pow(2, 1024)*(1 - pow(2, -54)));

	return EXIT_SUCCESS;
}
