#include <iostream> 
using namespace std;

void diapazon(int* a, int i , int n) {
	if(i < n){
		a[i] = -40 + rand() % (60);
		cout << a[i] << " ";
		diapazon(a, i + 1, n);
	}
}
void suma(int* a, int i, int& S) {
	S += a[i];
}
void nazero(int* a, int i) {
	a[i] = 0;
}
void poshuk(int* a,int i, int n, int& S, int& q) {
	if (i <= n) {
		if (a[i] < 0) {
			suma(a , i , S);
			q += 1;
			nazero(a, i);
		}else if (a[i] % 2 == 0) {
			suma(a, i, S);
			q += 1;
			nazero(a, i);
		}
		cout << a[i] << " ";
		poshuk(a, i + 1, n, S, q);
	}
}

int main() {
	srand((unsigned)time(NULL));
	const int n = 25;
	int a[n+1];
	int S = 0, q = 0, i = 0;

	diapazon(a, i, n + 1);
	cout << endl;
	poshuk(a, i, n, S, q);
	cout << endl << "Suma = " << S << endl;
	cout << "Kilkist = " << q << endl;

	return 0;
}