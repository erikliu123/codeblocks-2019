#include <iostream>

using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {

        cout<<s<<"   "<<p<<endl;
        int s1=s.size(),p1=p.size();
        string temp=".*";
        if(p==temp) return true;
        if(s1==0 && p1==0) return true;
        //if(s1==0 && p1==2 && p[1]=='*') return true;
        else if(s1==0){

            if(p[1]!='*') return false;
        }
        else if(s1!=0 && (p1==0)) return false;

        if(p[p1-1]!='*' && p[p1-1]!='.'&& p[p1-1]!=s[s1-1]) return false;
        if( (s[0]==p[0]|| p[0]=='.') && (p[1]!='*')){
            return isMatch(s.substr(1,s1-1),p.substr(1,p1-1));
        }
        if(  p[1]=='*'){
            if(s1>0 && p[0]=='.')
                return  isMatch(s.substr(1,s1-1),p)          //s ?*
                    || isMatch(s,p.substr(2,p1-2));//s 除去.*，看后面的
            if(s[0]==p[0])
                return isMatch(s.substr(1,s1-1),p)          //s ?*
                    || isMatch(s.substr(1,s1-1),p.substr(2,p1-2)) || isMatch(s,p.substr(2,p1-2));
            else return isMatch(s,p.substr(2,p1-2));
        }

        //if(p[0]=='.' && p[1]!='*') return isMatch(s.substr(1,s1-1),p.substr(1,p1-1));
        return false;
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        return help(s, s.size()-1, p, p.size()-1);
    }
    bool help(string &s, int si, string &p, int pi){
        if (si == -1 && pi == -1) return true;
        if (pi == -1 ) return false;

        if(si == -1) {
            if (p[pi] == '*') return help(s, si, p, pi-2);//从最后一个字母开始看
            else return false;
        } else {
            if (s[si] == p[pi] || p[pi] == '.') {
                return help(s, si-1, p, pi-1);
            } else if (p[pi] == '*') {//如果pi=0
                if (p[pi-1] == s[si] || p[pi-1] == '.') {
                    return help(s, si-1, p, pi-2) || help(s, si-1, p, pi) || help(s, si, p, pi-2);
                } else {
                    return help(s, si, p, pi-2);
                }
            } else return false;
        }
    }
};
string ss="mississippi";
string ans="mis*is*ip*.";
int main()
{
    Solution A;
    Solution2 A2;
    int s;
    cin>>s;
    if(s==1){
      ss="aa";
      ans="a*";
    }
    else if(s==2){
        ss="aaaaaaaaaaaaab";
        ans="a*a*a*a*a*a*a*a*a*a*c";
        //cin>>ss>>ans;
    }
    cout<<A.isMatch(ss,ans)<<endl;
     cout<<A2.isMatch(ss,ans)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
