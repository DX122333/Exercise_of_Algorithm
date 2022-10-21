#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<deque>
using namespace std;


//�º�����
//�������أ��������

template<class T>
struct Less
{
	bool operator()(const T& val1, const T& val2)
	{
		return val1 < val2;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& val1, const T& val2)
	{
		return val1 > val2;
	}
};



template<class T, class Container = vector<T>, class Compare = greater<T>>

class priorityQueue
{
public:

	//���ϵ���
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			//if (_c[parent] > _c[child])
			if (_com(_c[parent], _c[child]))
			{
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}

	void push(const T& val)
	{
		//β��+���ϵ���
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}

	//���µ���
	void shiftDown(int parent)
	{
		int child = parent * 2 + 1;

		while (child < _c.size())
		{
			if (child + 1 < _c.size() && _com(_c[child], _c[child + 1]))
			{
				child++;
			}
			if (_com(_c[parent], _c[child]))
				//if (_c[parent] > _c[child])
			{
				swap(_c[parent], _c[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}

	//ɾ���Ѷ�Ԫ��  ������βԪ�أ����µ���
	int pop()
	{
		swap(_c[0], _c[_c.size() - 1]);
		int front = _c[_c.size() - 1];
		_c.pop_back();
		shiftDown(0);
		return front;
	}

	T& top()
	{
		//return _c[0];
		return _c.front();
	}

	bool empty()
	{
		return _c.empty();
	}

	size_t size()
	{
		return _c.size();
	}

private:
	Container _c;
	Compare _com;
};
