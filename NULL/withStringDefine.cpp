#pragma once
#include "withStringDeclare.h"

int getMinDaBiaoSubStringLen(string s) {
	//status记录当前子串中每个字母的奇偶状态
	//status为32位，从最低位0到25位，分别代表a到z
	//如果当前子串中的某个字母个数为奇数个，则status对应位为1，否则为0
	int status = 0;
	//record记录某个状态的及其出现的最早遍历位置
	unordered_map<int, int> record;
	//没有开始遍历时，状态为0
	//此项必须，否则当后序遍历出现0状态计算最大长度时会出错
	record[0] = -1;
	//返回结果
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		//通过1左移相应位数和异或更新status
		status ^= (1 << (s[i] - 'a'));

		if (record.find(status) != record.end()) {
			res = max(res, i - record[status]);
		}
		else {
			record[status] = i;
		}
	}
	return res;

}