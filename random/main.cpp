#include <iostream>
#include <bits/stdc++.h>
using namespace std;

ifstream in("zuowei.csv");
ofstream out("formal.txt");
vector<string> name;
bool hasPeople[100];
int main()
{
    srand(time(NULL));

    string temp;
    while(in>>temp){
            name.push_back(temp);

    }
    int coun=0;
    while(coun<name.size()){
        int random=rand()%(name.size());
        if(!hasPeople[random]){
            ++coun;
            hasPeople[random]=1;
            out<<name[random]<<endl;

        }
    }

    in.close();
    out.close();

    return 0;
}
