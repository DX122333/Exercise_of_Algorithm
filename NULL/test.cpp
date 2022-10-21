#include <iostream>
//#include "priority_queue.h"
//#include "Trie.h"
//#include "withStringDeclare.h"
//#include <string>
//#include "withBitManipulationDeclare.h"
//include "withListNodeDeclare.h"
#include "analog.h"
using namespace std;

int main(void) { 
	string number = "123 4-567";
	//cout<<reformatNumber(number)<<endl;
	//traverse(res);
	string str = ".1";
	cout << isIntger(str, 0, 1);
	cout << isDouble(str, 0, 1);
	cout<<isNumber(str);
	return 0;
}