
#include "stdafx.h"
#include "header.h"

void ch4_1()
{
	Stack stk;
	stk.push("world");
	stk.push("world");
	stk.push("hello");
	
	string str;
	if (stk.find("world")) {
		cout << stk.count("world");
	}
	stk.peek(str);
	cout << str;
	stk.pop(str);
	cout << str;
	stk.pop(str);
	cout << str;
}

bool Stack::pop(string &elem)
{
	if (empty())
		return false;
	elem = _stack.back();
	_stack.pop_back();
	return true;
}

bool Stack::peek (string &elem) const
{
	if (empty())
		return false;
	elem = _stack.back();
	return true;
}

bool Stack::push(const string &elem)
{
	if (full())
		return false;
	_stack.push_back(elem);
	return true;
}

bool Stack::find(const string &elem) const
{
	for (vector<string>::const_iterator it = _stack.cbegin(); it != _stack.cend(); it++) {
		if (*it == elem)
			return true;
	}
	return false;
}

int Stack::count(const string &elem) const
{
	int ret = 0;
	for (vector<string>::const_iterator it = _stack.cbegin(); it != _stack.cend(); it++) {
		if (*it == elem)
			ret++;
	}
	return ret;
}

void ch4_3() {}
string program_name;
string version_stampprogram_name;
int version_num;
int tests_run;
int tests_passed;

void ch4_4()
{
	UserProfile userP;
	cout << userP;
}
UserProfile::UserProfile(e_level level, string name)
	:m_name(name),
	m_level(level)
{}
bool UserProfile::operator==(const UserProfile &rhs) const
{
	return this->m_name == rhs.m_name;
}
bool UserProfile::operator!=(const UserProfile &rhs) const
{
	return this->m_name != rhs.m_name;
}
ostream& operator<<(ostream &os, const UserProfile &userP)
{
	os << userP.m_name << '\n'
		<< userP.m_level << endl;
	return os;
}
istream& operator>>(istream &is, UserProfile &userP)
{
	is >> userP.m_name;
	return is;
}

void ch4_5()
{
	float flt_arr0[16];
	float flt_arr1[16];
	for (size_t i = 0; i < 16; i++)
	{
		flt_arr0[i] = float(i);
		flt_arr1[i] = float(i+1);
	}
	Matrix mat0(flt_arr0);
	Matrix mat1(flt_arr1);
	cout << mat0;
	cout << mat1;
	cout << mat0+mat1;
	cout << mat0*mat1;
	mat0 += mat0;
	cout << mat0;
}
ostream& operator<<(ostream& os, Matrix &mat)
{
	os << "MATRIX:\n";
	for (vector<vector<float> >::const_iterator it = mat.m_2dmat.cbegin();
		it != mat.m_2dmat.cend(); it++)
	{
		for (vector<float>::const_iterator itt = it->cbegin(); itt != it->cend(); itt++){
			os << *itt << setw(5) << internal;
		}
		os << '\n';
	}
	return os;
}
Matrix::Matrix()
{
	vector<float> vec4(4, 0);
	for (int i = 0; i < 4; i++)
		m_2dmat.push_back(vec4);
}
Matrix::Matrix(float flt_arr[16])
	:Matrix()
{
	for (int i = 0; i < 16; i++) {
		m_2dmat[i / 4][i % 4] = flt_arr[i];
	}
}
Matrix Matrix::operator+(Matrix &rh_mat)
{
	Matrix ret_mat;
	for (int i = 0; i < 16; i++) {
		ret_mat(i / 4, i % 4) = (*this)(i / 4, i % 4) + rh_mat(i / 4, i % 4);
	}
	return ret_mat;
}
Matrix Matrix::operator*(Matrix &rh_mat)
{
	Matrix ret_mat;
	for (int i = 0; i < 16; i++) {
		ret_mat(i / 4, i % 4) = (*this)(i / 4, i % 4) * rh_mat(i / 4, i % 4);
	}
	return ret_mat;
}
void Matrix::operator+=(Matrix &rh_mat)
{
	for (int i = 0; i < 16; i++) {
		(*this)(i / 4, i % 4) += rh_mat(i / 4, i % 4);
	}
}
float& Matrix::operator()(int row, int column)
{
	return (this->m_2dmat)[row][column];
}
float Matrix::operator()(int row, int column) const
{
	return (this->m_2dmat)[row][column];
}

