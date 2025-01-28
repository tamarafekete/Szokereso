#pragma once

class KMP_string {
	int n;
	int max_n=50;
public:
	char* s;
	KMP_string();
	KMP_string(char* s);
	KMP_string(const KMP_string&);
	KMP_string(int);
	~KMP_string();
	int size();
	int search(const KMP_string&, int*);
	KMP_string& operator+(const KMP_string&);
	KMP_string& append(const KMP_string&);
	void deleteLastChar();
	void clear();
};

