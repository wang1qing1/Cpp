#define _CRT_SECURE_NO_WARNINGS 1

template<class Iterator, class Ref, class Ptr>
class _reverse_iterator
{
public:
	typedef _reverse_iterator<Iterator, Ref, Ptr> Self;

	_reverse_iterator(Iterator it)
		:_it(it)
	{
	}

	Self operator++(int)
	{
		Self tmp(*this);
		_it--;
		return tmp;
	}

	Self operator++()
	{
		_it--;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_it++;
		return tmp;
	}

	Self operator--()
	{
		_it++;
		return *this;
	}

	Ref operator*()
	{
		Iterator tmp = _it;
		tmp--;
		return (*tmp);
	}

	bool operator!=(const Self& rit)
	{
		return _it != rit._it;
	}
private:
	Iterator _it;
};