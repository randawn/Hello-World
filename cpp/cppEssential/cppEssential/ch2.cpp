
#include "stdafx.h"
#include "header.h"

void pent_gen(vector<int> * p_vec)
{
	//if (p_vec->size() > 100)
	//	return;
	if (ch2_3(p_vec)){
		cout << "too long too cal";
		return;
	}
	for (size_t i = 0; i < p_vec->size(); i++){
		(*p_vec)[i] = i * (3 * i - 1) / 2;
	}
}
template <typename T>
void print_vec(vector<T> *p_vec)
{
	for (vector<T>::iterator it = p_vec->begin(); it != p_vec->end(); it++) {
		cout << *it << ' ';
	}
}
void ch2_2()
{
	cout << "input the len of Pentagonal seq you want to get:";
	int len;
	cin >> len;
	vector<int> p_vec(len);
	pent_gen(&p_vec);
	print_vec(&p_vec);
}

vector<int> * pent_gen_s(size_t len)
{
	static vector<int> pent_vec;
	while (pent_vec.size() < len) {
		int i = pent_vec.size();
		pent_vec.push_back(i * (3 * i - 1) / 2);
	}
	return &pent_vec;
}
template <typename T>
inline T get_n_item(vector<T> * p_vec, int n)
{
	return (*p_vec)[n];
}
void ch2_4()
{
	size_t len;
	vector<int> * p_vec;
	while (cin >> len) {
		p_vec = pent_gen_s(len);
		for (size_t i = 0; i < len; i++){
			cout << get_n_item(p_vec, i) << '\n';
		}
	}
}

template <typename T>
T max_(T a, T b) { return a > b ? a : b; }
template <typename T>
T max_(vector<T> vec) {
	if (vec.empty()) {
		return T();
	}
	T max = vec.front();
	for (vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it > max) {
			max = *it;
		}
	}
	return max;
}
template <typename T>
T max_(T * p_array, size_t size){
	T max = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (*(p_array+i) > max) {
			max = *(p_array+i);
		}
	}
	return max;
}

void ch2_5()
{
	cout << max_(1, 2) << '\n';
	cout << max_(1.0, 2.0) << '\n';
	cout << max_( "foo", "bar") << '\n';
	int int_arr[3] = { 1, 2, 3 };
	float flt_arr[3] = { 1.0, 2.0, 3.0 };
	char *p_chr_arr[3] = { "foo", "bar", "baz" };
	vector<int> vec_int(int_arr, int_arr + sizeof(int_arr) / sizeof(int_arr[0]));
	cout << max_(vec_int) << '\n';
	vector<float> vec_flt(flt_arr, flt_arr + sizeof(flt_arr) / sizeof(flt_arr[0]));
	cout << max_(vec_flt) << '\n';
	string str_arr[3] = { string(*p_chr_arr), string(*(p_chr_arr + 1)), string(*(p_chr_arr + 2)) };
	vector<string> vec_str(str_arr, str_arr + 3);
	cout << max_(vec_str) << '\n';
	cout << max_(int_arr, sizeof(int_arr) / sizeof(int_arr[0])) << '\n';
	cout << max_(flt_arr, sizeof(flt_arr) / sizeof(flt_arr[0])) << '\n';
	cout << max_(p_chr_arr, 3) << '\n';
}