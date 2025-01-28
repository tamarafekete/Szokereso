#pragma once
#include <fstream>
#include "KMP_string.h"
#include <iostream>

using namespace std;


class Szokereso {
	//bool** vizszintes;
	int m=0, n=0, h=0;
public:
	int** kezd;
	int* tdb;
	KMP_string sor;
	KMP_string* szavak;
	Szokereso() {};
	void txtbolEpit(ifstream& szovegfile, ifstream& szavakfile);
	//void operator=(const Szokereso&);
	~Szokereso ();
	int nrOfRows();
	int RowLength();
	int nrOfWords();
};

