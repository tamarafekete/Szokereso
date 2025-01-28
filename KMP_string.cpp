#include "KMP_string.h"
#include <cmath>

KMP_string::KMP_string() {
	n = 0;
	max_n = 300;
	char* s = new char[max_n] {0};
}

KMP_string::KMP_string(char* s) {
	max_n = 300;
	this->s = new char[max_n] {0};
	int i;
	for (i = 0;s[i] != '\0';i++) {
		this->s[i] = s[i];
	}
	n = i;
}


KMP_string::KMP_string(const KMP_string& S) {
	max_n = S.max_n;
	n = S.n;
	s = new char[max_n] {0};
	for (int i = 0;i < n;i++) s[i] = S.s[i];
}

KMP_string::KMP_string(int number) {
	max_n = 20;
	s = new char[max_n] {0};
	int nn = number;
	n = 0;
	do {
		nn /= 10;
		n++;
	} while (nn != 0);
	nn = number;
	if (number < 0) n++;
	int i = n - 1;
	while (i >= 0) {
		s[i] = abs(nn) % 10+'0';
		nn /= 10;
		i--;
	}
	if (number < 0) s[0] = '-';
}

KMP_string::~KMP_string() {
	delete[]s;
}

int KMP_string::size() {
	return n;
}

int KMP_string::search(const KMP_string& S, int* kezd) {
	int m = 0, i = 0;
	int* T = new int[S.n];
	T[0] = 0;
	for (i = 1;i < S.n;i++) {
		if (S.s[i] == S.s[T[i - 1]]) {
			T[i] = T[i - 1] + 1;
		}
		else {
			T[i] = 0;
		}
	}
	i = 0;
	int tdb = 0;
	while (i + m < n) {
		if (i < S.n) {
			if (s[m + i] == S.s[i]) {
				i++;
			}
			else {
				if (i > 1)
					m = m + i;
				else m++;
				i = 0;
				if (T[i] > 1) {
					m -= T[i] - 1;
					i += T[i] - 1;
				}
			}
		}
		else {
			kezd[tdb] = m;
			m = m + i- T[i - 1];
			i = T[i-1];
			tdb++;
		}
	}
	return tdb;
}

KMP_string& KMP_string::operator+(const KMP_string& a) {
	KMP_string *newstring = new KMP_string;
	if (a.n + n >= max_n) {
		newstring->max_n = max_n + a.n + 50;
	}
	else newstring->max_n = max_n;
	newstring->n = n + a.n;
	newstring->s = new char[max_n] {0};
	int i = 0;
	while (i < n) {
		newstring->s[i] = s[i];
		i++;
	}
	int j = 0;
	if (i != 0) {
		newstring->s[i] = '\n';
		i++;
		j++;
		(newstring->n)++;
	}
	while (i < newstring->n) {
		newstring->s[i] = a.s[i - n-j];
		i++;
	}
	newstring->s[i] = '\0';
	return *newstring;
}

KMP_string& KMP_string::append(const KMP_string& a) {
	KMP_string* newstring = new KMP_string;
	if (a.n + n >= max_n) {
		newstring->max_n = max_n + a.n + 50;
	}
	else newstring->max_n = max_n;
	newstring->n = n + a.n;
	newstring->s = new char[max_n] {0};
	int i = 0;
	while (i < n) {
		newstring->s[i] = s[i];
		i++;
	}
	int j = 0;
	while (i < newstring->n) {
		newstring->s[i] = a.s[i - n];
		i++;
	}
	newstring->s[i] = '\0';
	return *newstring;
}

void KMP_string::deleteLastChar() {
	if (n != 0) {
		n--;
		s[n] = '\0';
	}
}

void KMP_string::clear() {
	while (n > 0) deleteLastChar();
}