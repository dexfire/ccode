#include <ctype.h>
#include <iostream>
#include <string>

using namespace std;

bool is_identify(string nm)
{
	char ch = nm.at(0);
	if (!(isalpha(ch) || ch == '_'))
		return false;

	for (int i = 1; i < nm.length(); i++)
	{
		ch = nm.at(i);
		if (!(ch == '_' || isdigit(ch) || isalpha(ch)))
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int n;
	char nm[50];
	while (true)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin.getline(nm, 50);
			cout << "hello" << endl;
			cout << (is_identify(nm) ? "yes" : "no") << endl;
		}
	}
	system("pause");
	return 0;
}
