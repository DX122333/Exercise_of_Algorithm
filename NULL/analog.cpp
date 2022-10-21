#include "analog.h"

string reformatNumber(string number) {
	int n = number.size();
	int end = 0;
	for (int i = 0; i < n; ++i) {
		if (number[i] == ' ' || number[i] == '-') {}
		else {
			number[end] = number[i];
			end++;
		}
	}
	string res;
	int count = 0;
	string tmp;
	for (int i = 0; i < end; ++i) {
		count++;
		tmp += number[i];
		if (count == 3) {
			res += tmp;
			res += '-';
			count = 0;
			tmp = "";
		}
	}
	res += tmp;
	if (end % 3 == 0) res.resize(res.size() - 1);
	if (end % 3 == 1) swap(res[res.size() - 2], res[res.size() - 3]);
	return res;
}
int findNthDigit(int n) {
	if (n <= 9) return n;
	//找到该位所在的数字是几位数
	int carry = 1;
	long long count = 9, size = 9;
	while (n > size) {
		n -= size;
		carry += 1;
		count *= 10;
		size = carry * count;
	}
	//找到该位所在的数字
	int start = 1, i = carry;
	while (--i) start *= 10;
	int num = start + (n - 1) / carry;
	//找到该数字对应的位并返回

	int pos = carry-(num + 1 - start)*carry + n;
	int res;
	while (pos--) {
		res = num / start;
		num = num % start;
		start = start / 10;
	}
	return res;
}
int strToInt(string str) {
	int res = 0;
	int flag = 1;
	int count = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (res == 0 && (str[i]<'0' || str[i]>'9') && (str[i] != '-')) return 0;
		if (res == 0 && str[i] == '-') {
			flag *= -1;
			continue;
		}
		if (count > 0 && (str[i]<'0' || str[i]>'9')) break;
		if (str[i] >= '0' && str[i] <= '9') {
			count++;
			res = res * 10 + str[i] - '0';
		}
	}
	res *= flag;
	return res;
}
bool isIntger(string&s, int left, int right) {
	if (left > right) return false;
	if (left == right) {
		if (s[left] > '9' || s[left] < '0') return false;
		else return true;
	}
	int flag = true;
	for (int i = left; i <= right; ++i) {
		if (i == left && (s[i] == '+' || s[i] == '-')) continue;
		if (s[i] > '9' || s[i] < '0') flag = false;
	}
	return flag;
}
bool isDouble(string&s, int left, int right) {
	if (left >= right) return false;
	int flag = false;//标记.
	int countDian = 0;
	int IndexDian = -1;
	for (int k = left; k <= right; ++k) {
		if (k == left && (s[k] == '+' || s[k] == '-')) continue;
		if (s[k] == '.') {
			IndexDian = k;
			countDian++;
			if (countDian > 1) return false;
			flag = true;
			continue;
		}
		if (s[k] > '9' || s[k] < '0') return false;
	}
	return (isIntger(s, left, IndexDian - 1)) || (isIntger(s, IndexDian + 1, right));
}
bool isNumber(string s) {
	int i = 0, j = s.size() - 1;
	int n = j;
	while (i <= j && s[i] == ' ') i++;
	while (j >= 0 && s[j] == ' ') j--;
	if (i > j) return false;
	int indexE = -1;
	int countE = 0;
	for (int k = i; k <= j; ++k) {
		if (s[k] == 'e' || s[k] == 'E') {
			indexE = k;
			countE++;
		}
	}
	if (countE > 1) return false;

	if (countE == 0) {
		return isIntger(s, i, j) || isDouble(s, i, j);
	}
	else if (countE == 1) {
		return (isIntger(s, i, indexE - 1) || isDouble(s, i, indexE - 1)) && (isIntger(s, indexE + 1, j));
	}
	return false;
}