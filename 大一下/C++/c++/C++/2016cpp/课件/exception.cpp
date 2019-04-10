写运行结果：
1、
#include <iostream.h>
void main(void)
 {
   cout << "Start" << endl;
   try {
      cout << "Inside try block." << endl;
      throw 100;
      cout << "This will not execute.";
    }
   catch(int i) {
      cout << "Caught an exception -- value is: ";
      cout << i << endl;
    }
   cout << "End";
 }
2、
#include <iostream.h>

void XHandler(int test)
 {
    cout << "Inside XHandler, test is:" << test << endl;
    if(test) throw test;
 }
void main(void)
 {
   cout << "Start: " << endl;
   try {
      cout << "Inside try block." << endl;
      XHandler(1);
      XHandler(2);
      XHandler(0);
    }
   catch(int i) {
      cout << "Caught an exception. Value is: ";
      cout << i << endl;
    }
   cout << "End";
 }
3、
#include <iostream.h>

void XHandler(int test)
 {
   try {
      if(test) throw test;
    }
   catch(int i)
    {
      cout << "Caught exception #: " << i << endl;
    }
 }
void main(void)
 {
   cout << "Start: " << endl;
   XHandler(1);
   XHandler(2);
   XHandler(0);
   XHandler(3);
   cout << "End";
 }
4、
#include <iostream.h>
void XHandler(int test)
 {
   try 
   {
      if(test==0) throw test;
      if(test==1) throw "String";
      if(test==2) throw 123.23;
    }
   catch(int i)
    {
      cout << "Caught exception #: " << i << endl;
    }
   catch(char *str)
    {
      cout << "Caught string exception: " << str << endl;
    }
   catch(double d)
    {
      cout << "Caught exception #: " << d << endl;
    }
 }
void main(void)
 {
   cout << "Start: " << endl;
   XHandler(0);
   XHandler(1);
   XHandler(2);
   cout << "End";
 }
5、
#include <iostream.h>
void XHandler(int test) throw()
 {
   if(test==0)
     throw test;
   if(test==1)
     throw 'a';
   if(test==2)
     throw 123.23;
 }
void main(void)
 {
   cout << "Start: " << endl;
   try
    {
      XHandler(0);                  // try passing 1 and 2 for different responses
    }
   catch(int i)
    {
      cout << "Caught an integer." << endl;
    }
   catch(char c)
    {
      cout << "Caught a character." << endl;
    }
   catch(double d)
    {
      cout << "Caught a double." << endl;
    }
   cout << "End";
 }
6、
#include <iostream.h>
void XHandler(void)
 {
   try {
      throw "hello";
    }
   catch(char *) {
      cout << "Caught char * inside XHandler." << endl;
      throw;
    }
 }
void main(void)
 {
   cout << "Start: " << endl;
   try {
      XHandler();
    }
   catch(char *) 
   {
      cout << "Caught char * inside main." << endl;
    }
   cout << "End";
   
 }
7、
class Base1
{
   virtual void f(void) { /* A virtual function makes the class polymorphic */ }
};
class Base2 { };
class Derived : public Base1, public Base2 { };
void main(void) 
{
   try 
   {
      Derived d, *pd;
      Base1 *b1 = &d;
      // Perform a downcast from a Base1 to a Derived.
      if ((pd = dynamic_cast<Derived *>(b1)) != 0) 
	  {
           cout << "The resulting pointer is of type "
                << typeid(pd).name() << endl;
         }
      else throw Bad_cast();
      // Cast from the first base to the most derived class and then back
      // to another accessible base.
      Base2 *b2;
      if ((b2 = dynamic_cast<Base2 *>(b1)) != 0) 
	  {
          cout << "The resulting pointer is of type "
               << typeid(b2).name() << endl;
         }
      else throw Bad_cast();
      }
   catch (Bad_cast) 
   {
      cout << "dynamic_cast failed" << endl;
      exit(1);
      }
   catch (...) {
      cout << "Exception handling error." << endl;
      exit(1);
      }
}
8、
#include <iostream.h>
void fc()
{
try
{throw "sos";}
catch(int)
{cout<<"sos int"<<endl;}
try{
throw 1;}
catch(const char * p){cout<<"sos string"<<endl;}
}
void fb()
{
int *q=new int[100];
try{fc();}
catch(…){
delete []q;
throw;
}
}
void fa()
{
int *p=new int[100];
try{fb();}
catch(…){
delete []p;
throw;
}
}
void main()
{
try{fa();}
catch(…)
{cout<<"an error occurred while running"<<endl;}
}

