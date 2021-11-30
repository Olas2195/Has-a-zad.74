#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Zadanie74{
	ifstream we;
	ofstream wy;
	string napis;
	int numerycznych = 0;
	vector <string> hasla;
	vector <string> powtorzone;
	int kolejne_ilosc=0;
	int poprawne=0;
	
	public:
		Zadanie74();
		~Zadanie74();
		void wczytaj();
		bool zadanie1(string haslo);
		void zadanie2(string haslo);
		void zadanie3(string haslo);
		bool kolejne(char a, char b, char c, char d);
		bool zadanie4(string haslo);
};

Zadanie74::Zadanie74() {
	we.open("hasla.txt");
	wy.open("wyniki_hasla.txt");
}

void Zadanie74::wczytaj() {
	if(we.good()) {
		while(!we.eof()) {
			we>>napis;
			if(this->zadanie1(napis)) {
				numerycznych++;
			}
			this->zadanie2(napis);
			this->zadanie3(napis);
			if(this->zadanie4(napis)) {
				poprawne++;
			}
		}
		cout<<"Zadanie 1: "<<numerycznych<<"\n";
		wy<<"Zadanie 1: "<<numerycznych<<"\n";
		cout<<"Zadanie 2: \n";
		wy<<"Zadanie 2: \n";
		sort(powtorzone.begin(), powtorzone.end());
		for(int i=0; i<powtorzone.size(); i++) {
        	cout<<powtorzone[i]<<"\n";
        	wy<<powtorzone[i]<<"\n";
    	}
    	cout<<"Zadanie 3: "<<kolejne_ilosc<<"\n";
    	wy<<"Zadanie 3: "<<kolejne_ilosc<<"\n";
    	cout<<"Zadanie 4: "<<poprawne<<"\n";
    	wy<<"Zadanie 4: "<<poprawne<<"\n";
    }
}

bool Zadanie74::zadanie1(string haslo) {
	for(int i=0; i<haslo.length(); i++) {
		if(!(haslo[i]>='0' && haslo[i]<='9')) {
			return false;
		}
	}
	return true;
}

void Zadanie74::zadanie2(string haslo) {
	if(find(hasla.begin(), hasla.end(), haslo) == hasla.end()) {
		hasla.push_back(haslo);
	} else {
		powtorzone.push_back(haslo);
	}
}

void Zadanie74::zadanie3(string haslo) {
	if(haslo.length()>=4) {
		for(int i=3; i<haslo.length(); i++) {
			if(this->kolejne(haslo[i], haslo[i-1], haslo[i-2], haslo[i-3])) {
				kolejne_ilosc++;
				return;
			}
		}
	}
}

bool Zadanie74::kolejne(char a, char b, char c, char d) {
	char T[4];
	T[0] = a;
	T[1] = b;
	T[2] = c;
	T[3] = d;
	sort(T, T+4);
	if(T[0]+1==T[1] && T[0]+2==T[2] && T[0]+3==T[3]) {
		return true;
	}
	return false;
}

bool Zadanie74::zadanie4(string haslo) {
	for(int i=0; i<haslo.length(); i++) {
		if((haslo[i]>='0' && haslo[i]<='9')) {
			for(int i=0; i<haslo.length(); i++) {
				if((haslo[i]>='a' && haslo[i]<='z')) {
					for(int i=0; i<haslo.length(); i++) {
						if((haslo[i]>='A' && haslo[i]<='Z')) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

Zadanie74::~Zadanie74() {
	we.close();
	wy.close();
}

int main() {
	Zadanie74 z74;
	z74.wczytaj();
	return 0;
}
