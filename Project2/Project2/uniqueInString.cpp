#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace ::std;

int check_unique_in_str(char* str);
char* reverse_str(char * st);
int main()
{
	char s[] = "abacd";
	//int res = check_unique_in_str(s);
	char * ns = reverse_str(s);
	printf("%s",ns);
	_getch();
	return 0;
}

int check_unique_in_str(char* str)
{
	unsigned int count = 0;
	int value = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		value = (int)str[i] - (int)'a';
		if ((count & (1 << value)) > 0){
			cout << "\n not unique";
			return 1;
			break;
		}
		else{
			count = count | (1 << value);
		}
	}
	
	cout << "All Unique";
	return 0;
}

char* reverse_str(char * st)
{
	char * str = st;
	int i = 0;
	char temp;
	while (str[i] != '\0')
	{
		i++;
	}
	int j = 0;
	i--;
	while (j < i)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j++;
		i--;
	}
	return str;
}