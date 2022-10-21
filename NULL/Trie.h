#pragma once
/*Trie���ֻ��������ֱ��ǽ����Ͳ�ѯ��
���н����������ǰ�һ���µ��ʲ��뵽�ֵ����
��ѯ�������ǲ�ѯ���������Ƿ����ֵ����ϡ�
*/
#include<vector>
#include<string>

using namespace std;

class Trie {
private:
	/*
	ָ���ӽڵ��ָ������children��
	*/
	vector<Trie*> children;
	
	//��ʾ�ýڵ��Ƿ�Ϊ�ַ����Ľ�β
	bool isEnd;

	//����ǰ׺
	Trie* searchPrefix(string prefix) {
		Trie* node = this;
		for (char ch : prefix) {
			ch -= 'a';
			if (node->children[ch] == nullptr) {
				return nullptr;
			}
			node = node->children[ch];
		}
		return node;
	}
	
public:
	Trie() : children(26), isEnd(false) {}
	/*
	���鳤��Ϊ26����СдӢ����ĸ��������
	��ʱchildren[0] ��ӦСд��ĸa������children[25] ��ӦСд��ĸz��
	*/
	void insert(string word) {
		Trie* node = this;
		for (char ch : word) {
			ch -= 'a';
			if (node->children[ch] == nullptr) {
				node->children[ch] = new Trie();
			}
			node = node->children[ch];
		}
		node->isEnd = true;
	}

	bool search(string word) {
		Trie* node = this->searchPrefix(word);
		return node != nullptr && node->isEnd;
	}

	bool startsWith(string prefix) {
		return this->searchPrefix(prefix) != nullptr;
	}
};