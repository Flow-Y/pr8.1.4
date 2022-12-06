#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s)
{
	int pos = 0;
	char* t;
	while (t = strchr(s + pos, 'n'))
	{
		pos = t - s + 1;
		if (s[pos + 1] == 'o')
			cout << "i: " << pos << endl;;
	}
	return 0;
}
char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, 'n'))
	{
		if (s[p - s + 4] % 4)
		{
			pos2 = p - s + 4;
			strncat(t, s + pos1, pos2 - pos1 - 4);
			strcat(t, "**");
			pos1 = pos2;
		}
		else
		{
			pos2 = p - s + 1;
			strncat(t, s + pos1, pos2 - pos1);
			pos1 = pos2;
		}
	}
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	Count(str);
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string: " << dest << endl;
	return 0;
}