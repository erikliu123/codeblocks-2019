#include <iostream>

using namespace std;
/***
    ���Ժ�������������const��Ӱ��
    const CSomeClass& mData
**/
class CSomeClass
{
public:

    void DisplayMember( ) {/**1.Ϊʲôconst CSomeClass����***/
        cout<<" DisplayMember( ) is called"<<endl;
    }
};
void DisplayAllData(  CSomeClass& mData )//const CSomeClass& mData
{
    mData.DisplayMember ( ) ; //���뱨��
}

void test(const int *a){/**2.Ϊʲôint *aҲ���ԣ�����������***/
    //a=5; //ERROR
    cout<<"a="<<a<<endl;
}

void testInt(int *a){/**3. const int �������ᵼ�±������ �ͽ�����Ϊʲô1�Ǵ���ģ���ĺ����ĵ�һ�������൱��this��ΪCSmeClass *const�����ڴ������const  CSmeClass�Ļ����ͺ�const intһ��
                        ��������***/

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
