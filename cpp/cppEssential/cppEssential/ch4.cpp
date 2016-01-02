
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
	Matrix<float> mat0(4, 4);
	Matrix<float> mat1(flt_arr1);
	cout << mat0;
	cout << mat1;
	cout << mat0+mat1;
	cout << mat0*mat1;
	mat0 += mat0;
	cout << mat0;
}
template <typename T>
ostream& operator<<(ostream& os, const Matrix<T> &mat)
{
	os << "MATRIX:\n";
	for (vector<vector<T> >::const_iterator it = mat.m_2dmat.cbegin();
		it != mat.m_2dmat.cend(); it++)
	{
		for (vector<T>::const_iterator itt = it->cbegin(); itt != it->cend(); itt++){
			os << *itt << setw(5) << internal;
		}
		os << '\n';
	}
	return os;
}
template <typename T>
Matrix<T>::Matrix()
{
	vector<T> vec4(4, 0);
	for (int i = 0; i < 4; i++)
		m_2dmat.push_back(vec4);
}
template <typename T>
Matrix<T>::Matrix(T flt_arr[16])
	:Matrix()
{
	for (int i = 0; i < 16; i++) {
		m_2dmat[i / 4][i % 4] = flt_arr[i];
	}
}
template <typename T>
Matrix<T>::Matrix(int row, int col)
	:m_row(row),
	m_col(col)
{
	for (int i = 0; i < row; i++) {
		vector<T> vec_row(col, T());
		m_2dmat.push_back(vec_row);
	}
}
template <typename T>
Matrix<T>::~Matrix()
{
}
template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix &rh_mat)
{
	Matrix ret_mat;
	for (int i = 0; i < m_row*m_col; i++) {
		ret_mat(i / m_col, i % m_col) = (*this)(i / m_col, i % m_col) + rh_mat(i / m_col, i % m_col);
	}
	return ret_mat;
}
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &rh_mat)
{
	Matrix ret_mat;
	for (int i = 0; i < m_row*m_col; i++) {
		ret_mat(i / m_col, i % m_col) = (*this)(i / m_col, i % m_col) * rh_mat(i / m_col, i % m_col);
	}
	return ret_mat;
}
template <typename T>
void Matrix<T>::operator+=(Matrix<T> &rh_mat)
{
	for (int i = 0; i < m_row*m_col; i++) {
		(*this)(i / m_col, i % m_col) += rh_mat(i / m_col, i % m_col);
	}
}
template <typename T>
T& Matrix<T>::operator()(int row, int column)
{
	return (this->m_2dmat)[row][column];
}
template <typename T>
T Matrix<T>::operator()(int row, int column) const
{
	return (this->m_2dmat)[row][column];
}
