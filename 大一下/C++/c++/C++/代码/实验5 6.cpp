/*
#include<iostream>
using namespace std;
class myarray
{
private:
	int*alist;
	int length;
public:
	myarray();
	myarray(int leng);
	~myarray();
	void input();
	void display();
};
myarray::myarray()

{
	length = 0;
	alist = NULL;

}
myarray::myarray(int leng)
{
	cout << "construting" << endl;
	length = leng;
	alist = new int[length + 1];
}
myarray::~myarray()
{
	if (alist != NULL)
	{
		delete[]alist;
		length = 0;
		cout << "destruting" << endl;
	}

}
void myarray::input()
{
	if (alist != NULL)
	{
		cout << "输入" << length << "个数" << endl;
		for (int i = 0; i<length; i++)
		{
			cin >> alist[i];

		}
	}
}
void myarray::display()
{
	cout << "display" << endl;
	for (int i = 0; i<length; i++)
	{
		cout << alist[i] << " ";
	}
	cout << endl;
}
int main()
{
	myarray a(10);
	a.input();
	a.display();
	return 0;
}
*/



/*
#include<iostream>
using namespace std;
class myarray
{
public:
	int*alist;
	int length;
public:
	myarray();
	myarray(int leng);
	~myarray();
	void input();
	void display();
};
myarray::myarray()

{
	length = 0;
	alist = NULL;

}
myarray::myarray(int leng)
{
	cout << "construting" << endl;
	length = leng;
	alist = new int[length + 1];
}
myarray::~myarray()
{
	if (alist != NULL)
	{
		delete[]alist;
		length = 0;
		cout << "destruting" << endl;
	}

}
void myarray::input()
{
	if (alist != NULL)
	{
		cout << "input" << length << "shu" << endl;
		for (int i = 0; i<length; i++)
		{
			cin >> alist[i];

		}
	}
}
void myarray::display()
{
	cout << "display" << endl;
	for (int i = 0; i<length; i++)
	{
		cout << alist[i] << " ";
	}
	cout << endl;
}
class averarray :virtual public myarray
{
public:
	double aver;
	averarray(int n) :myarray(n)
	{
		cout << " averarray constring" << endl;
		aver = 0;
	}
	~averarray()
	{
		cout << "averarray destruing" << endl;
	}
	void getaver()
	{
		for (int i = 0; i<length; i++)
		{
			aver += alist[i];
		}
		cout << "aver=" << aver / length << endl;
	}
};
class revarray :virtual public myarray
{
public:
	revarray(int n) :myarray(n)
	{
		cout << "revarray construing" << endl;

	}
	~revarray()
	{
		cout << "revrarray destruing" << endl;
	}
	void reverse()
	{
		cout << "t o r" << endl;
		display();
		for (int i = 0; i<(length) / 2; i++)
		{
			int temp = alist[i];
			alist[i] = alist[length - 1 - i];
			alist[length - i - 1] = temp;
		}
		cout << "after reverse" << endl;
		display();
	}
	void display()
	{
		cout << "display" << endl;
		for (int i = 0; i<length; i++)
		{
			cout << alist[i] << " ";

		}
		cout << endl;
	}

};
class newarray :public averarray, public revarray
{
public:
	newarray(int n) :averarray(n), revarray(n), myarray(n)
	{
		cout << "newarray con" << endl;
	}
	~newarray()
	{
		cout << "newarray des" << endl;
	}
	void display()
	{
		cout << "display" << endl;
		for (int i = 0; i<length; i++)
		{
			cout << alist[i] << " ";

		}
		cout << endl;
	}
};
int main()
{
	myarray m(10);
	m.input();
	m.display();
	averarray a(10);
	a.input();
	a.getaver();
	revarray r(10);
	r.input();
	r.reverse();
	newarray n(10);
	n.input();
	n.display();
	return 0;
}
*/

/*
#include <iostream>
#include<string.h>

using namespace std;

class String {
protected:
	char pi[256];
public:
	String(char* const p)
	{
		strcpy(pi, p);
	}
	int getLength()
	{
		return strlen(pi);
	}
	char * getContent()
	{
		return pi;
	}
};
class editstring :public String
{
public:
	editstring(char* const p);
	void insert(int k, char c)
	{
		for (int i = strlen(pi) + 1; i>k; i--)
			pi[i] = pi[i - 1];
		pi[k] = c;
	}
	void insert(int k, char const *p)
	{
		for (unsigned int i = strlen(pi) + strlen(p); i >= (k + strlen(p)); i--)
			pi[i] = pi[i - strlen(p)];
		for (unsigned int j = 0; j<strlen(p); j++)
			pi[k + j] = p[j];
	}
	void change(int k, char c)
	{
		pi[k] = c;
	}
	void delet(int k)
	{
		for (unsigned int i = k; i<strlen(pi); i++)
			pi[i] = pi[i + 1];
	}
};
editstring::editstring(char * const p) :String(p)
{
}
int main()
{
	editstring s("abc");
	cout << "content:" << s.getContent() << " length:" << s.getLength() << endl;
	s.insert(2, "2");
	cout << "content:" << s.getContent() << " length:" << s.getLength() << endl;
	s.insert(2, "def");
	cout << "content:" << s.getContent() << " length:" << s.getLength() << endl;
	s.change(2, 'A');
	cout << "content:" << s.getContent() << " length:" << s.getLength() << endl;
	s.delet(2);
	cout << "content:" << s.getContent() << " length:" << s.getLength() << endl;
	return 0;
}
*/





#include <iostream>
using namespace std;
class shape
{
public:
	virtual double getarea() = 0;
	virtual double getvolume() = 0;
	virtual void printshape() = 0;
	virtual void printdimension() = 0;
	virtual int dimension() = 0;
};
class twodimensionalshape :public shape
{
public:
	virtual double getarea() = 0;
	virtual void printshape() = 0;
	double getvolume() { return 0; }
	void printdimension() { cout << "Twodimensional shape" << endl; }
	int dimension() { return 2; }
};
class threedimensionalshape :public shape
{
public:
	virtual double getarea() = 0;
	virtual void printshape() = 0;
	virtual double getvolume() = 0;
	void printdimension() { cout << "Threedimensional shape" << endl; }
	int dimension() { return 3; }
};
//二维形状
class circle :public twodimensionalshape
{
private:
	double r;     //私有为半径
public:
	circle(double i) :r(i) {};
	double getarea() { return r*r*3.14; };
	void printshape() { cout << "Circle" << endl; };

};
class triangle :public twodimensionalshape
{
private:
	double a;    //私有为底和高
	double h;    //高
public:
	triangle(double i, double j) :a(i), h(j) {};
	double getarea() { return a*h / 2; };
	void printshape() { cout << "Triangle" << endl; };
};
class square :public twodimensionalshape
{
private:
	double l; //边长
public:
	square(double a) :l(a) {};
	double getarea() { return l*l; };
	void printshape() { cout << "Triangle" << endl; };
};
//三维形状
class sphere :public threedimensionalshape
{
private:
	double r; //球类半径
public:
	sphere(double a) :r(a) { };
	double getarea() { return r*r * 4 * 3.14; };
	double getvolume() { return (4 * 3.14*r*r*r) / 3; };
	void printshape() { cout << "Sphere" << endl; };
};
class cube :public threedimensionalshape
{
private:
	double l; //正方体类棱长
public:
	cube(double a) :l(a) {};
	double  getarea() { return l*l * 6; };
	double getvolume() { return l*l*l; };
	void printshape() { cout << "Cube" << endl; };
};
void point(shape& p)
{
	int i = p.dimension();
	cout << "Dimension:";
	p.printdimension();
	cout << "Shape:";
	p.printshape();
	if (i == 2)
	{
		cout << "Area=" << p.getarea() << endl;
	}
	else
	{
		cout << "Area=" << p.getarea() << endl;
		cout << "Volume=" << p.getvolume() << endl;
	}
}
int main()
{
	int i;
	shape* p[5];
	circle cir(1.0);
	triangle tri(2.0, 3.0);
	square squ(4.0);
	sphere sph(6.0);
	cube cub(7.0);
	p[0] = &cir;
	p[1] = &tri;
	p[2] = &squ;
	p[3] = &sph;
	p[4] = &cub;
	for (i = 0; i<5; i++)
		point(*p[i]);
	return 0;


}





