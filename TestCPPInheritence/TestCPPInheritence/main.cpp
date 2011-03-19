#include <iostream>

struct A
{
	int a;
	void af()
	{
		std::cout << "Hello from A. var = " << a << std::endl;
	}
};

struct B
{
	int b;
	void bf()
	{
		std::cout << "Hello from B. var = " << b << std::endl;
	}
};

struct C : public A, public B
{
	int c;
	void cf()
	{
		std::cout << "Hello from C. vars = " << a << " " << b << " " << c << std::endl;
	}
};

void foo(B* b)
{
	b->b = 100;
}


int main()
{
	A a;
	a.a = 1;

	B b;
	b.b = 2;
	
	C c;
	c.a = 3;
	c.b = 4;
	c.c = 5;

	foo(reinterpret_cast<B*>(&c));

	std::cout << &c << " " << (B*)&c << " " << (A*)&c <<std::endl;

	//((B*)&c)->b = 7;
	//((A*)&c)->a = 8;

	a.af();
	b.bf();
	c.cf();
}

	