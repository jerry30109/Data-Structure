#include<iostream>
#include<string>
using namespace std;
struct Sort {
	string data;
	Sort *next;
	Sort *pre;
};
struct Vec {
	string data;
	Vec *next;
	int size;
};

int main() {
	char vec[26] = {};
	Vec** myHead;
	int cont1 = 100;
	int cont = 0;
	string data1;
	myHead = new Vec*[cont1];
	while (cin >>data1) {
		if (data1 == "#")
			break;
		cont++;
		Vec *node;
		node = new Vec;
		node->data = data1;
		node->size = node->data.size();
		myHead[cont] = node;
	}
	for (int i = 1; i < cont; i++) {
		myHead[i]->next = myHead[i + 1];
	}
	int charSize = 0;
	Sort **mySort;
	mySort = new Sort*[(cont+1)*2];
	for (int i = 1; i < cont; i++) {
		for (int j = 0; j < myHead[i]->size; j++) {
			if (myHead[i]->data[j] != myHead[i]->next->data[j]) {
				Sort *str1;
				str1 = new Sort;
				str1->data = myHead[i]->data[j];
				str1->pre = str1;
				Sort *str2;
				str2 = new Sort;
				str2->data = myHead[i]->next->data[j];
				str2->next = str2;
				str2->pre = str1;
				str1->next = str2;
				mySort[charSize] = str1;
				mySort[charSize + 1] = str2;
				charSize += 2;
				break;
			}
		}
	}//建立所有大小關係
	for (int i = 0; i < charSize; i+=2) {
		cout<<mySort[i]->pre->data<<'<' << mySort[i]->data << '<' << mySort[i]->next->data << '\n';
	}
	for (int i = 0; i < charSize; i += 2) {
		for (int j = 0; j < charSize; j++) {
			if (mySort[i]->data == mySort[j]->data) {
				if (i != j) {
					
				}
			}
		}
	}
	system("pause");
}
	
