
#include "stdafx.h"
#include "header.h"

void ch5_1()
{
	StackT<int> stkt;
	Peekback_Stack<int> stkt_pb;
	for (int i = 0; i < 16; i++) {
		stkt_pb.push(i);
	}
	stkt_pb.print();
	for (int i = 0; ; i++) {
		bool bflag;
		int elem;
		bflag = stkt_pb.peekback(elem, i);
		if (!bflag)
			break;
		cout << elem << ' ';
	}
	int tmp;
	while (stkt_pb.pop(tmp)) {};
	stkt_pb.print();
}
template <typename T>
bool StackT<T>::pop(T & elem)
{
	if (empty())
		return false;
	elem = m_stk.back();
	m_stk.pop_back();
	return true;
}
template <typename T>
bool StackT<T>::peek(T & elem) const
{
	if (empty())
		return false;
	elem = m_stk.back(elem);
	return true;
}
template <typename T>
bool StackT<T>::push(const T & elem)
{
	if (full())
		return false;
	m_stk.push_back(elem);
	return true;
}
template <typename T>
void StackT<T>::print()
{
	vector<T>::const_iterator it = m_stk.cbegin();
	for (; it != m_stk.cend(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}

template <typename T>
bool Peekback_Stack<T>::peekback(T & elem, int n) const
{
	if (empty() || n < 0 || n > size()-1)
		return false;
	elem = m_stk[size()-1-n];
	return true;
}
