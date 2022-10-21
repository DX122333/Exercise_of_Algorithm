#pragma once
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

/*
给定一个字符串s, 其中都是小写字母，
如果s中的子串含有的每种字符都是偶数个，称达标子串，子串要求是连续串
返回s中达标子串的最大长度
1<=s.length<=10^5
*/
int getMinDaBiaoSubStringLen(string);

