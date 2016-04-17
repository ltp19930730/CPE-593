
#include <iostream>
#include <cmath>
using namespace std;

int SieveOfEratosthenes(unsigned long long int start, unsigned long long int end)
{
	if (start == 1)
		start++;
	unsigned long long int count_num = end - start+1;
	const unsigned long long int n = count_num;
	const unsigned long long int sqr_num = sqrt(end);
	bool *p_prim = new bool[sqr_num];
	bool *p_section = new bool[n];
	unsigned long long int index = count_num;
	unsigned long long int i, j, k = 0;
	
	for (i = 0; i < count_num; i++)
	{
		*(p_section + i) = true;
	}
	for (i = 0; i < sqr_num; i++)
	{
		*(p_prim + i) = true;
	}


	for (int i = 2; i <= sqr_num; i++)
	{
		if (*(p_prim + i))
		{
			if (i == 2)
			{
				j = 4;
				while (j <= sqr_num)
				{
					*(p_prim + j) = false;
					j += 2;
				}
			}
			else
			{
				for (j = i*i; j < sqr_num; j = j + 2 * i)
				{
					*(p_prim + j) = false;
				}
			}
	        k = (start / i) * i;
			for (; k <= end; k += i)
			{
				if (k >= start)
				{
					if (k == i)
						continue;
					if (*(p_section + k - start) == true)
					{
						*(p_section + k - start) = false;
						index--;
					}
				}
			}
		}

	}
   
	return index;
}

int main()
{
	
	unsigned long long int start = 0, end = 0;
	cout << "Please input the start number:" << endl;
	cin >> start;
	cout << "Please input the end number:" << endl;
	cin >> end;
  
	
	int prime_num = SieveOfEratosthenes(start, end);
	cout << "The number of prime number between them is:" << endl;
	cout << prime_num << endl;
	return 0;
}