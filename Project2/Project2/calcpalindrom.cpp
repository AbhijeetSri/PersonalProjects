#include<iostream>

using namespace ::std;
int main()
{
	int T, l=0, i, sum;
	char* str;
	str = new char[20];
	cin >> T;

	while (T-- > 0)
	{
		cin >> str;
		while (str[l] != '\0'){ l++; }
		//        l = strlen(str)-1;
		l = l - 1;
		sum = 0;
		for (i = 0; i < l; i++)
		{
			sum = sum + abs(str[l] - str[i]);
			l--;
		}
		cout << sum << "\n";
	}

	return 0;
}