#include "BinaryTree.h"
#include <iostream>
#include <fstream>

using namespace std;

void test(BiTreePtr* p1) {
//	cout << p1->l << endl;
	if (p1 == NULL) return;
//	cout << p1 << " p1 ch is " << p1->ch << " num is " << p1->num << endl;
	test(p1->l);
	test(p1->r);
}

void BiTreePtr::printTree(BiTreePtr* root, char* encoding, char c, int idx, int count, int curCount) {

	//cout << c << endl;
//	cout << "root->ch, root->l->ch, root->r->ch are: " << root->ch << " " << root->l->ch << " " << root->r->ch << endl;

//	cout << root<< " " << root->l << " " << root->r << " " << root->ch << endl;
	if (c == 'l') {
		encoding[++idx] = '0';
		//cout << "curCount is " << curCount << endl;

	//	cout << "c == l" << endl;

	} else if (c == 'r') {
		encoding[++idx] = '1';	

	//	cout << "c == r" << endl;
	
	}

	//cout << "encoding " << *encoding << endl;

	char l = 'l', r = 'r';

	// cout << root->l->ch << endl;

/*
	if (curCount == count) {
			return;
	}
*/
	// cout << "root->l is " << root->l << endl;
	// cout << "root is " << root << endl;

	//cout << root->l->ch << endl;
	if( root->l == NULL && root->r == NULL){

	//	cout << "anything" << endl;
		cout << root->ch << setw(5) << root->num << " ";
		for (int i = 1; i <= idx; i++) {
			cout << encoding[i];
		}
		cout << endl;
		curCount++;

	}
	//	cout << "else" << endl;
	//	cout << l << " " << r << endl;
	if (root->l != NULL) {
		printTree(root->l, encoding, l, idx, count, curCount);
	} 
	if (root->r != NULL) {
	//	cout << "root->l finished" << endl;
		printTree(root->r, encoding, r, idx, count, curCount);
	}

}

int main(int argc, char** argv){
	char *filename = argv[1];
	ifstream infile(filename);

	BinaryHeap<BiTreePtr> heap;

	int arr[256] = {0};
	char c;

	/* 
	 * read chars from file and store in an int array
	 * index will be char
	 * value at index will be the frequency
	 */ 
	while(infile.get(c)){
		if (arr[c] != 0) {
			arr[c]++;
		} else {
			arr[c] = 1;
		}
//		cout << "printing arr[" << c << "] is " << arr[c] << endl;

	}

	int count = 0;
	// store all chars in individual BiTreePtrs and insert into the heap
	for (int i = 0; i < 256; i++) {

		if (arr[i] != 0) {
			BiTreePtr* pt = new BiTreePtr();
			pt->ch = i;
			
			pt->num = arr[i];

	//		cout << pt << " " << pt->num << " " << pt->ch << endl;

			heap.insert(*pt);

			count++;
		}

	}

	//cout << "good so far" << endl;
	
	char* encoding = new char();
	while (true) {

		BiTreePtr temp1 = heap.findMin();
		BiTreePtr* p1 = new BiTreePtr();
		p1->ch = temp1.ch;
		p1->num = temp1.num;
		p1->l = temp1.l;
		p1->r = temp1.r;
	//	BiTreePtr* p1 = &temp1;

//		cout << p1 << " " << p1->ch << " " << p1->r << endl;

		heap.deleteMin();
//		cout << "before if" << endl;
		if (heap.isEmpty()) {

		//	test(p1);
	//	cout << "terminating condition reached" << endl;
		//	cout << "p1->ch, p1->l->ch, p1->r->ch are: " << p1->ch << " " << p1->l->ch << " " << p1->r->ch << endl;
			p1->printTree(p1, encoding, '\0', 0, count, 0);
		//	cout << "after p1->printTree" << endl;

			return 0;
		}
	//	cout << "if is good" << endl;

	//	BiTreePtr temp2 = heap.findMin();
	//	BiTreePtr* p2 = &temp2;

		BiTreePtr temp2 = heap.findMin();
		BiTreePtr* p2 = new BiTreePtr();
		p2->ch = temp2.ch;
		p2->num = temp2.num;
		p2->l = temp2.l;
		p2->r = temp2.r;

	//	cout << p2 << " " << p2->l << " " << p2->r << endl;

		heap.deleteMin();

/*
		BiTreePtr combined;
		combined.l = p1;
		combined.r = p2;
		combined.num = p1->num + p2->num;
		heap.insert(combined);
*/

		BiTreePtr* combined = new BiTreePtr();
		combined->r = p2;
		combined->l = p1;
		combined->num = p1->num + p2->num;
		heap.insert(*combined);

	//	cout << combined << " " << combined->l << " " << combined->r << " " << endl;

	//	cout << combined.l->ch << endl;
	//	cout << combined.l->l->ch << endl;


	}
//	cout << "while is good" << endl;

}
