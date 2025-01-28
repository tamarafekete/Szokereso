#include "Szokereso.h"

void Szokereso::txtbolEpit(ifstream& in1, ifstream& in2) {
	char a[300];
	int i = 0;
	while (!in1.eof()) {
		in1 >> a;
		if (a[0] != '\n' && a[0] != '\0')n++;
		sor = sor + a;
		if (i == 0) h = sor.size();
		i++;
	}
	in2 >> m;
	szavak = new KMP_string[m];
	i = 0;
	while (i<n && !in2.eof()) {
		in2 >> a;
		szavak[i] = szavak[i] + a;
		i++;
	}
	tdb = new int[m] {0};
	kezd = new int* [m];
	for (int i = 0;i < m;i++) {
		kezd[i] = new int[sor.size()];
		tdb[i] = sor.search(szavak[i], kezd[i]);
	}
	char** fuggszoveg;
	fuggszoveg = new char* [h];
	int j = 0, k = 0, l = 0;
	for (int i = 0;i < h;i++) {
		fuggszoveg[i] = new char[n + 1] {0};
	}
	while (sor.s[j] != '\0') {
		if (sor.s[j] != '\n') {
			fuggszoveg[l][k] = sor.s[j];
			l++;
		}
		else {
			k++;
			l = 0;
		}
		j++;
	}
	KMP_string szoveg2;
	for (int i = 0;i < h;i++) {
		szoveg2 = szoveg2 + fuggszoveg[i];
	}
	for (int i = 0;i < m;i++) {
		j = tdb[i];
		tdb[i] += szoveg2.search(szavak[i], kezd[i] + j);
		while (j < tdb[i]) {
			int ii = kezd[i][j] % (n + 1), jj = kezd[i][j] / (n + 1);
			kezd[i][j] = ii * (h + 1) + jj;

			//kezd[i][j] = ind.s[kezd[i][j] - 1];
			j++;
		}
	}
	for (int i = 0;i < h;i++) {
		delete[]fuggszoveg[i];
	}
	delete[] fuggszoveg;
}

Szokereso::~Szokereso() {
	delete[]szavak;
	for (int i = 0;i < m;i++) {
		delete[] kezd[i];
	}
	delete[]kezd;
	delete[]tdb;
}

int Szokereso::nrOfRows() {
	return n;
}

int Szokereso::RowLength() {
	return h;
}

int Szokereso::nrOfWords() {
	return m;
}