//（协变）重写+函数重载

#include<iostream>
using namespace std;
class Person//父类
{
public:
    virtual  Person& BuyTickets()//父类虚函数
    {
        cout<<"成人买票-全票"<<endl;
        return *this;
    }
public:
    string  _name; // 姓名
};

class Student : public Person//子类
{
public:
    virtual Student& BuyTickets()//子类虚函数
    {
        cout<<"学生买票-半票"<<endl;
        return *this;
    }
public:
    int _num ; //学号
};
void Fun (Person* p)
{
    p->BuyTickets();
}
void Fun (Person&p)
{
    p.BuyTickets();
}
void TestOverride ()
{
    Person p;
    Student s;
    Fun(p);
    Fun(s);

    Fun(&p);
    Fun(&s);
}
/**
    override重写结束，
    下面是重定义(隐藏)
**/


/**
// //1 //2 //3 全都是重定义
    2是取消原来的虚函数

**/
class A
{
protected:
    A(int x=2)
        :_a(x)
    {}
//public:
//  //1
//     void show()
//  {
//      cout<<"A::shou()"<<endl;
//  }

//public:
//  //2
//  virtual void show()
//  {
//      cout<<"A::shou()"<<endl;
//  }
public:
    //3
    void show(int a)
    {
        cout<<"A::shou()"<<endl;
    }
public:
    int _a;
};
class B:public A
{
public:
    B(int x=1)
        :_a(x)
    {}
//public:
//  //1
//  void show(int b)
//  {
//      cout<<"B::shou()"<<endl;
//  }
//public:
//  //2
//  void show(int a)
//  {
//      cout<<"B::shou()"<<endl;
//  }
public:
    //3
    void show(int a,int b)
    {
        cout<<"B::shou()"<<endl;
        cout<<_a<<endl;
    }
public:
    int _a;
};


int main()
{
    TestOverride();
    return 0;
}
