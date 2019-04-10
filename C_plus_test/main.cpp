#include <iostream>

using namespace std;
/***
    测试函数参数带不带const的影响
    const CSomeClass& mData
**/
class CSomeClass
{
public:

    void DisplayMember( ) {/**1.为什么const CSomeClass不行***/
        cout<<" DisplayMember( ) is called"<<endl;
    }
};
void DisplayAllData(  CSomeClass& mData )//const CSomeClass& mData
{
    mData.DisplayMember ( ) ; //编译报错
}

void test(const int *a){/**2.为什么int *a也可以，反过来不行***/
    //a=5; //ERROR
    cout<<"a="<<a<<endl;
}

void testInt(int *a){/**3. const int 传进来会导致编译错误， 就解释了为什么1是错误的，类的函数的第一个参数相当于this，为CSmeClass *const。现在传入的是const  CSmeClass的话，就和const int一样
                        不正常了***/

}
int main()
{
     CSomeClass w;
    //const CSomeClass w; /**ERROR! passing 'const CSomeClass' as 'this' argument discards qualifiers [-fpermissive]|***/
    w.DisplayMember();

    int k=4;
    test(&k);

    const int hh=4;
    testInt(&hh);
    return 0;
}
