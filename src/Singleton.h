#ifndef _SINGLETON_
#define _SINGLETON_


template<typename T>
struct An
{
	An()                                { clear(); }

	T* operator->()                     { return get0(); }
	const T* operator->() const         { return get0(); }
	void operator=(T* t)                { data = t; }

	bool isEmpty() const                { return data == 0; }
	void clear()                        { data = 0; }
	void init()                         { if (isEmpty()) reinit(); }
	void reinit()                       { anFill(*this); }

private:
	T* get0() const
	{
		const_cast<An*>(this)->init();
		return data;
	}

	T* data;
};

template<typename T>
void anFill(An<T>& a)
{
	throw std::runtime_error(std::string("Cannot find implementation for interface: ")
		+ typeid(T).name());
}

#endif