#pragma once

#include <stack>
#include <iostream>
#include <iterator>
#include <vector>


//テンプレートクラスとして定義し、std::stackを継承する
template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack<T, Container> &other) : std::stack<T, Container>(other) {}
	MutantStack &operator=(const MutantStack<T, Container> &other)
	{
		if (this == &other)
			return *this;
		std::stack<T, Container>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	//iterator型を取得
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	//reverse_iterator型を取得
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	//this->cは内部コンテナへの参照
	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const {
		return this->c.rend();
	}
};