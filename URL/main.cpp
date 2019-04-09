#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
using namespace std;
const int N = 107;
const string s_int = "([0-9]+)";
const string s_str = "([0-9A-Za-z-_\.]+)";
const string s_path = "([0-9A-Za-z-_\./]+)";
string rule[N], na[N];
vector <int> p[N];  // 表示匹配项类型 1-int;2-str;3-path
int n, m;
smatch sm;
string _deal(string str, int k) {// 将"int"->s_int'... 变成正则表达式的情况
    string ans;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '<') {
            string tmp; i++;
            while (str[i] != '>')
                tmp.push_back(str[i++]);
            if (tmp == "int") { ans += s_int;  p[k].push_back(1); }
            else if (tmp == "str") { ans += s_str;  p[k].push_back(2); }
            else { ans += s_path; p[k].push_back(3); }
        }
        else  ans.push_back(str[i]);
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s1;
        cin >> s1 >> na[i];
        rule[i] = _deal(s1, i);
    }
    for (int i = 1; i <= m; i++) {
        string str; cin >> str;
        string ans = "404";
        int k = 1;
        for (; k <= n; k++) {
            regex re(rule[k]);
            if (regex_match(str,sm,re)) {
                ans = na[k];
                break;
            }
        }
        cout << ans;
        if (ans != "404")
            for (int j = 0; j < p[k].size(); j++) {
                if (p[k][j] == 1)     cout << " " <<stoi(sm[j+1]);
                else                  cout << " " << sm[j+1];
        }
        cout << "\n";
    }
    //system("pause");
    return 0;
}
