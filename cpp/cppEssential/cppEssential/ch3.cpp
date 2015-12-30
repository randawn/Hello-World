
#include "stdafx.h"
#include "header.h"

void ch3_1()
{
	ifstream in_file("ch3_1_datain.txt");
	//ofstream out_file(ch3_1_dataout.txt);

	istream_iterator<string> is(in_file);
	istream_iterator<string> eof;
	//ostream_iterator<string> os(out_file, " ");

	map<string, int> word_cnt_map;
	const set<string> ex_set = { "a", "an", "or", "the", "and", "but" };
	
	for (; is != eof; is++) {
		if (ex_set.count(*is)) {
			continue;
		}
		word_cnt_map[*is]++;
	}

	for (map<string, int>::const_iterator it = word_cnt_map.cbegin(); it != word_cnt_map.cend(); it++) {
		cout << "word:" << it->first << ' ';
		cout << "cnt:" << it->second << '\n';
	}
}

bool len_pred(string a, string b) { return a.size() < b.size() ? true : false; }
class less_than{
public:
	bool operator() (string &s1, string &s2) {
		return s1.size() < s2.size();
	}
};
void ch3_2()
{
	ifstream in_file("ch3_1_datain.txt");
	istream_iterator<string> is(in_file);
	istream_iterator<string> eof;

	vector<string> str_vec;

	copy(is, eof, back_inserter(str_vec));
	//sort(str_vec.begin(), str_vec.end(), &len_pred);
	sort(str_vec.begin(), str_vec.end(), less_than());

	for (vector<string>::const_iterator it = str_vec.cbegin(); it != str_vec.cend(); it++) {
		cout << *it << ' ';
	}
}

bool is_even(int a) { return a % 2 == 0; }
bool is_odd(int a) { return a % 2 == 1; }
void ch3_4()
{
	istream_iterator<int> is(cin);
	istream_iterator<int> eof;

	ostream_iterator<int> os_nl(cout, "\n");
	ostream_iterator<int> os_s(cout, " ");

	vector<int> int_vec;
	copy(is, eof, back_inserter(int_vec));

	copy_if(int_vec.begin(), int_vec.end(), os_nl, &is_odd);
	copy_if(int_vec.begin(), int_vec.end(), os_s, &is_even);
}
