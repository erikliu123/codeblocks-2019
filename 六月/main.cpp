#include <bits/stdc++.h>

using namespace std;
const string s_str = "\t(NUM_[0-9A-Za-z-_\.]+),";
const string reset_str = "\t(RESET[0-9A-Za-z-_\.]*),";

const string qt_s_str = "\tNUM_([0-9A-Za-z-_\.]+),";
const string qt_reset_str = "\tRESET([0-9A-Za-z-_\.]*),";
ifstream ss("test.txt");

ofstream of("comobox.txt");
ofstream qt("qt.txt");
smatch sm;
int main()
{
    string temp;
    while(getline(ss,temp))
    {
        regex re(s_str),re2(reset_str);
       /* if (regex_match(temp,sm,re2)){//match是全文匹配，即要求整个字符串符合匹配规则。regex_match("aaaAAA", regex("a*", regex::icase)) << endl;
            of<<"\tcomboBoxCmd.InsertString(NUM_"<<sm[1]<<", _T(\""<<str<<"\"));"<<endl;
           of<<"\tcomboBoxCmd.SetItemData(NUM_"<<sm[1]<<", NUM_"<<sm[1]<<");"<<endl;
            continue;
        }*/
        if (regex_match(temp,sm,re))//匹配一整串
        {
            string str=sm[1];
            if(str.find("TOTAL")!=std::string::npos) break;

            qt<<"<<"<<"\""<<str<<"\"";
           cout<<"\tcomboBoxCmd.InsertString(NUM_"<<sm[1]<<", _T(\""<<str<<"\"));"<<endl;
           cout<<"\tcomboBoxCmd.SetItemData(NUM_"<<sm[1]<<", NUM_"<<sm[1]<<");"<<endl;
           of<<endl;
        }
       // cout<<temp<<temp.length()<<endl;
    }
    of.close();
    qt.close();
    return 0;
}
