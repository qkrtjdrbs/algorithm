#include <iostream>
using namespace std;

int main()
{
	int cyc, a, b, i, j, n;
	n = 0;
	cin >> cyc;
	j = cyc;
	while (1)
	{
		b = cyc % 10;
		a = cyc / 10;
<<<<<<< HEAD

		cyc = 10 * b + (b + a) %
						   10;
=======
		cyc = 10 * b + (b + a) % 10;
>>>>>>> bcbfbf89b4bff10f8ab3106396e05a364e484f01
		n++;
		if (j == cyc)
		{
			break;
		}
	}
	//실험//
	cout << n;
	return 0;
}
