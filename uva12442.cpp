#include<iostream>
#include<string>
using namespace std;
enum Color { Black, White, Gray };
struct Email {
	int data = 0;
	Email *next;
	Email *pre;
	int d = 0;
	Color color = White;
};
int main() {
	int num, num2;
	cin >> num;
	Email *max;
	for (int i = 0; i < num; i++) {
		cin >> num2;
		Email **myHead;
		myHead = new Email*[num2 + 1];
		for (int j = 1; j <= num2; j++) {
			Email *node;
			node = new Email;
			node->data = j;
			myHead[j] = node;
		}
		for (int j = 1; j <= num2; j++) {
			int u, v;
			cin >> u >> v;
			myHead[u]->next = myHead[v];
			//myHead[v]->pre = myHead[u];
		}
		for (int j = 1; j <= num2; j++) {
			Email *currentNode;
			int time = 0;
			currentNode = myHead[j];
			while (currentNode->color == White) {
				currentNode->color = Black;
				currentNode = currentNode->next;
				time++;
			}
			myHead[j]->d = time;
			for (int k = 1; k <= num2; k++) {
				myHead[k]->color = White;
			}
		}
		max = myHead[1];
		for (int j = 2; j <= num2; j++) {
			if (max->d < myHead[j]->d) {
				max = myHead[j];
			}
		}
		cout << max->data << '\n';
	}
	system("pause");
}
	
