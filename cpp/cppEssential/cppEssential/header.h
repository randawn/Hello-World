#pragma warning(disable:4996)

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

void ch1_1();
void ch1_5();
void ch1_6();
void ch1_7();
void ch1_8();

void ch2_2();
inline bool ch2_3(vector<int> * p_vec)
{
	return p_vec->size() > 100 ? true : false;
}
void ch2_4();
void ch2_5();

void ch3_1();
void ch3_2();
void ch3_4();

void ch4_1();
class Stack {
public:
	bool push(const string &);
	bool pop(string &elem);
	bool peek(string &elem) const;
	bool find(const string &) const;
	int count(const string &) const;

	bool empty() const { return _stack.empty(); }
	bool full() const { return _stack.size() == _stack.max_size(); }
	int size() const { return _stack.size(); }

private:
	vector<string> _stack;
};

void ch4_4();
typedef enum {BEGIN, MEDIUM, ADVAN, PRO} e_level;
class UserProfile
{
	friend ostream& operator<<(ostream &os, const UserProfile &);
	friend istream& operator>>(istream &is, UserProfile &);
public:
	UserProfile(e_level level = BEGIN, string name = "guest");
	bool operator==(const UserProfile &) const;
	bool operator!=(const UserProfile &) const;
private:
	int m_login_rcd;
	string m_name;
	int m_log_cnt;
	int m_guess_cnt;
	int m_bingo_cnt;
	e_level m_level;
};

void ch4_5();
class Matrix
{
	friend ostream& operator<<(ostream&, Matrix &);
public:
	Matrix();
	Matrix(float flt_arr[16]);
	Matrix operator+(Matrix &);
	Matrix operator*(Matrix &);
	void operator+=(Matrix &);
	float& operator()(int row, int column);
	float operator()(int row, int column) const;
private:
	vector<vector<float> > m_2dmat;
};

