#pragma once
/*Trie两种基本操作分别是建树和查询。
其中建树操作就是把一个新单词插入到字典树里。
查询操作就是查询给定单词是否在字典树上。
*/
#include<vector>
#include<string>

using namespace std;

class Trie {
private:
	/*
	指向子节点的指针数组children。
	*/
	vector<Trie*> children;
	
	//表示该节点是否为字符串的结尾
	bool isEnd;

	//查找前缀
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
	数组长度为26，即小写英文字母的数量。
	此时children[0] 对应小写字母a，…，children[25] 对应小写字母z。
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