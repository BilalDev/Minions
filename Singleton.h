#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton
{
public:
	static T& getInstance()
	{
		static T instance;
		return instance;
	}

private:
	T& operator= (const T&) {}
};

#endif /* !SINGLETON_H */