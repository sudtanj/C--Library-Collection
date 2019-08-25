#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	int a[10][10],n;
	int flag = 0;
	srand ((unsigned)time(NULL));
	cin >> n;
	
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
		a[i][j] = rand()%100+1;
		if (a[i][j] == n)
		{
			cout << "Baris ke-" << i+1 << setw(2) << " Kolom ke-" << j+1 << endl;
			flag = 1;
		}
		}
	}	
	if (flag == 0)
	{
		cout << "Tidak Ada Angka" << endl;
	}
	
	for (int i = 0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		cout << setw (4) << a[i][j] << " ";
		cout << endl;
	}
	
	system ("pause");
	return 0;
}
