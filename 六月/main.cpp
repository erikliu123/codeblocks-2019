#include <bits/stdc++.h>

using namespace std;
const string s_str = "\tNUM_([0-9A-Za-z-_\.]+),";
const string reset_str = "\tRESET([0-9A-Za-z-_\.]*),";
ifstream ss("test.txt");

ofstream of("comobox.txt");
smatch sm;
int main()
{
    string temp;
    while(getline(ss,temp))
    {
        regex re(s_str),re2(reset_str);
       /* if (regex_match(temp,sm,re2)){//match��ȫ��ƥ�䣬��Ҫ�������ַ�������ƥ�����regex_match("aaaAAA", regex("a*", regex::icase)) << endl;
            of<<"\tcomboBoxCmd.InsertString(NUM_"<<sm[1]<<", _T(\""<<str<<"\"));"<<endl;
           of<<"\tcomboBoxCmd.SetItemData(NUM_"<<sm[1]<<", NUM_"<<sm[1]<<");"<<endl;
            continue;
        }*/
        if (regex_match(temp,sm,re))//ƥ��һ����
        {
            string str=sm[1];
            if(str.find("TOTAL")!=std::string::npos) break;


           of<<"\tcomboBoxCmd.InsertString(NUM_"<<sm[1]<<", _T(\""<<str<<"\"));"<<endl;
           of<<"\tcomboBoxCmd.SetItemData(NUM_"<<sm[1]<<", NUM_"<<sm[1]<<");"<<endl;
           of<<endl;
        }
       // cout<<temp<<temp.length()<<endl;
    }
    of.close();

    return 0;
}
