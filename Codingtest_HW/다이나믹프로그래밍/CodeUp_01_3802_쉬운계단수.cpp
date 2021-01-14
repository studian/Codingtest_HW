#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int N;


int main()
{
	cin >> N;
	string str_N = to_string(N);

	for (int i = 0; i < size(str_N); i++)
	{
		int n = atoi(&str_N[i]);
		cout << n << " ";
	}

}


