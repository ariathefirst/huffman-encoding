fndef BinaryTreeH
#define BinaryTreeH

#include <iostream>
#include <fstream>
#include <iomanip>

#include "BinaryHeap.h"
using namespace std;

class BiTreePtr {
public:
	char ch;
	int num;

	BiTreePtr *l;
	BiTreePtr *r;

	void printTree(BiTreePtr* root, char* encoding, char c, int idx, int count, int curCount);

	BiTreePtr() {
		ch = '\0';
		num = 0;
		l = NULL;
		r = NULL;
	}

	bool operator<(const BiTreePtr &rhs) const { return num < rhs.num; };
	bool operator!= (const BiTreePtr &rhs) const { return num < rhs.num; };
	friend ostream& operator<< (ostream &os, const BiTreePtr &rhs);

    ~BiTreePtr()
    {
      if(l)
        delete[] l;

      if(r)
        delete[] r;

    }

};

#endif
