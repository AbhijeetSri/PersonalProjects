#include<iostream>
#include<stdint.h>
#include<stdio.h>
using namespace ::std;

//void encrypt(uint32_t* key, uint32_t* data);
//void decrypt(uint32_t* key, uint32_t* data);
int main()
{
	FILE* file = stdin;
	char* buffer = 0;
	size_t result;

	file = fopen("sampletest", "rb");
	if (file == NULL) { fputs("File error", stderr); }

	while (!feof(file))
	{
		result = fread(buffer, 32, 1, file);
		cout << result << "\n";
	}
	//fread
	return 0;
}