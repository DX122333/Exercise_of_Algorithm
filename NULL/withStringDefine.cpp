#pragma once
#include "withStringDeclare.h"

int getMinDaBiaoSubStringLen(string s) {
	//status��¼��ǰ�Ӵ���ÿ����ĸ����ż״̬
	//statusΪ32λ�������λ0��25λ���ֱ����a��z
	//�����ǰ�Ӵ��е�ĳ����ĸ����Ϊ����������status��ӦλΪ1������Ϊ0
	int status = 0;
	//record��¼ĳ��״̬�ļ�����ֵ��������λ��
	unordered_map<int, int> record;
	//û�п�ʼ����ʱ��״̬Ϊ0
	//������룬���򵱺����������0״̬������󳤶�ʱ�����
	record[0] = -1;
	//���ؽ��
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		//ͨ��1������Ӧλ����������status
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