#include<iostream>
#include<string>

using namespace std;

//动物类
class Animal{
protected:
	string name ;
	int shoutNum ;

public:
	Animal(string ); //含参构造函数	
	Animal();         //构造函数
	void setName(string ); //设置名字
    int getShutNum() {return shoutNum; }; //读取动物叫声数
	void setShoutNum(int ); //设置动物叫声数
	};

Animal ::Animal(string name){
	setName(name);
	setShoutNum(3);
}

Animal ::Animal(){
	setName("无名");
	setShoutNum(3);
}

void Animal::setName(string name){
	this->name = name;
}

void Animal::setShoutNum(int shoutNum){
	this->shoutNum = shoutNum;
}


class Cat : Animal{
public:
	Cat(string );
	Cat();
	string Shout(); //猫叫
};

Cat::Cat(string name):Animal(name){}

Cat::Cat():Animal(){}

string Cat::Shout(){
	string result = "";
	for(int i = 0; i < shoutNum; i++)
		result += "喵";
	return "我的名字叫 " + name + " " + result;

}


class Dog : Animal{
public:
	Dog(string );
	Dog();
	string Shout(); //狗叫
};

Dog::Dog(string name):Animal(name){}

Dog::Dog():Animal(){}

string Dog::Shout(){
	string result = "";
	for(int i = 0; i < shoutNum; i++)
		result += "汪";
	return "我的名字叫 " + name + " " + result;

}

int main(){
    Cat c("花花");
	cout<<c.Shout()<<endl;
	Dog d;
	cout<<d.Shout()<<endl;
	return 0;
}

