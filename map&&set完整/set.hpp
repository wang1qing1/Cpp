#pragma once
#include"RB_Tree.hpp"



template<class K>
class set
{
	struct SetKeyOfT
	{
		K operator()(const K& date)
		{
			return date;
		}
	};
public:

	typedef typename RBTRee<K, K, SetKeyOfT>::const_iterator iterator;
	typedef typename RBTRee<K, K, SetKeyOfT>::const_iterator const_iterator;

	iterator begin()
	{
		return _rbTree.begin();
	}

	const_iterator begin() const
	{
		return _rbTree.begin();
	}

	iterator end()
	{
		return _rbTree.end();
	}

	const_iterator end() const
	{
		return _rbTree.end();
	}

	bool insert(const K& k)
	{
		return _rbTree.insert(k).second;
	}

	void Inorder()
	{
		_rbTree.Inorder();
	}

private:
	RBTRee<K, K, SetKeyOfT> _rbTree;
};


