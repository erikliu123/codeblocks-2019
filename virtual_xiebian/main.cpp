//��Э�䣩��д+��������

#include<iostream>
using namespace std;
class Person//����
{
public:
    virtual  Person& BuyTickets()//�����麯��
    {
        cout<<"������Ʊ-ȫƱ"<<endl;
        return *this;
    }
public:
    string  _name; // ����
};

class Student : public Person//����
{
public:
    virtual Student& BuyTickets()//�����麯��
    {
        cout<<"ѧ����Ʊ-��Ʊ"<<endl;
        return *this;
    }
public:
    int _num ; //ѧ��
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
    override��д������
    �������ض���(����)
**/


/**
// //1 //2 //3 ȫ�����ض���
    2��ȡ��ԭ�����麯��

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
