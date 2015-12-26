
#include "stdafx.h"
#include "header.h"

void ch1_1()
{
	string user_fname, user_lname;
	cout << "Plz enter your first name:";
	cin >> user_fname;
	cout << "Plz enter your last name:";
	cin >> user_lname;
	cout << "\n"
		<< "Hello, "
		<< user_fname << ' '
		<< user_lname << ' '
		<< "... and goodbye!\n";
}

void ch1_5()
{
	char c_style_str[10] = { '\0' };
	string str_obj;
	while (c_style_str[0] == '\0' ||
		c_style_str[1] == '\0' ||
		c_style_str[2] == '\0')
	{
		cout << "C str: Enter you name:";
		cin >> c_style_str;
	}
	cout << "hello " << c_style_str << '\n';
	while (str_obj.size()<=2)
	{
		cout << "Cpp str: Enter you name";
		cin >> str_obj;
	}
	cout << "hello " << str_obj << '\n';
}

void ch1_6()
{
	int intArr[100];
	vector<int> intVec(100);
	int len = 0;
	int tmp;
	int arrSum = 0;
	int vecSum = 0;
	float arrAver = 0;
	float vecAver = 0;
	cout << "plz enter a list of num:";
	for (int i = 0; cin; i++)
	{
		cin >> tmp;
		if (tmp == '\n')
		{
			break;
		}
		intArr[i] = tmp;
		intVec[i] = tmp;
		len++;
	}
	len--;
	for (int i = 0; i < len; i++)
	{
		arrSum += intArr[i];
		vecSum += intVec[i];
	}
	arrAver = float(arrSum) / len;
	vecAver = float(vecSum) / len;
	cout << "arrSum" << arrSum << '\n'
		<< "arrAver" << arrAver << '\n'
		<< "vecSum" << vecSum << '\n'
		<< "vecAver" << vecAver << '\n';
}

void ch1_7()
{
	ifstream infile("ch1_7_datain.txt");
	ofstream outfile("ch1_7_dataout.txt");
	vector<char> ch_from_file;
	char c;
	while (!infile.bad() && infile.get(c))
	{
		ch_from_file.push_back(c);
	}
	sort(ch_from_file.begin(), ch_from_file.end());
	for (vector<char>::iterator it = ch_from_file.begin(); it != ch_from_file.end(); it++)
	{
		outfile << *it;
	}
}

void ch1_8()
{
	const char hint[][80] = {
		"Oops! Nice guess but not quite it.\n",
		"Hmm. Sorry. Wrong a sencond time.\n",
		"Ah, this is harder than it looks, isn't it?\n",
		"It must be getting pretty frustrating by now!\n",
	};
	int num_tries=0;
	cout << hint[num_tries % 4];
}
