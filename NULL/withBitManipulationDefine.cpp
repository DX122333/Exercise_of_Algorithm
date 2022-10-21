#include "withBitManipulationDeclare.h"
#include <math.h>
#include <limits.h>
#include <iostream>
//Leetcode 29
int divide(int dividend, int divisor) {
	//int能表示的范围为-2^31~2^31-1，是不对称的，对最小值要特殊处理
	//标记dividend是否改变
	int flag = false;
	if (dividend == INT_MIN) {
		if (divisor == -1) {
			return INT_MAX;
		}else {
			flag = true;
			dividend += 1;//是最小值+1后就正数对应了
		}

	}

	if (divisor == INT_MIN) {
		if (flag) return (dividend - 1) == INT_MIN ? 1 : 0;
		return dividend == INT_MIN ? 1 : 0;

	}

	if (dividend == 0) return 0;

	int result = 0;
	int sign = -1;
	if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) sign = 1;
	int dd = abs(dividend), dr = abs(divisor);

	while (dr <= dd) {
		unsigned int temp = dr;
		//m与商的值相关

		unsigned int m = 1;
		while ((temp << 1) <= dd) {
			temp <<= 1;
			m <<= 1;
		}
		dd -= temp;
		result += m;
	}

	if (((dd + 1) % dr == 0) && (dividend - 1) == INT_MIN) result += 1;
	return sign * result;
}


