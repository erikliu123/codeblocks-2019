#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <random>
#include <time.h>
#define MAX 10002
using namespace std;

int N;
struct COORD{
    double x;
    double y;
    bool operator <(const COORD &a){
        if(x!=a.x)
        return x<a.x;
        else return y<a.y;
    }
};

COORD T[MAX];
int small[MAX];


bool comy(int a, int b){
    return T[a].y<T[b].y;
}
double s(const COORD &a, const COORD &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}
double s(const int &a, const int &b){
    return sqrt((T[a].x-T[b].x)*(T[a].x-T[b].x)+(T[a].y-T[b].y)*(T[a].y-T[b].y));

}
//int q1,q2;
int b,b1;
double new_min=1e20;
//int k1,k2;
double distant(int first, int last, int &r1, int &r2)
{
    double d = 1e20;
    r1=first;
    r2=last;
    if(first == last) {
            return d;
    }
    else if(first+1 == last) {
            r1=first,r2=last;
            return s(first, last);
    }
    int mid = (first+last) / 2;
    int q1,q2,k1,k2;
    double d1=distant(first, mid, q1, q2);
    double d2=distant(mid+1, last, k1, k2);

    if(d1<d2){
        r1=q1; r2=q2;
    }
    else{
        r1=k1; r2=k2;
    }
    d=min(d1, d2);
    //new_min=d;
    int k=0;
    for(int i = first ; i <= last; ++i){//记录中间结点的横坐标小于d的大小
        if(fabs(T[mid].x - T[i].x) < d){
            small[k++] = i;
        }
    }
   // cout<<"dd ";
    sort(small, small+k, comy);
    for(int i = 0;  i < k ; ++i){
            for(int j = i+1; j <k && fabs(T[small[j]].y - T[small[i]].y) < d; ++j){
                    if(s(T[small[i]], T[small[j]]) < d) {
                            r1=small[i];
                            r2=small[j];
                            d=s(T[small[i]], T[small[j]]);
                    //cout<<d<<"  ";
                    }

            }

    }
    b=r1;
    b1=r2;
    //cout<<"dd1 ";
    return d;
    //for(int )

}
int main()
{
    srand((unsigned short)time(NULL));

    ofstream out("random.txt", ios::trunc);
    N=rand()%6+7;
    cout<<N<<endl;
     for(int i=0; i<N; ++i) {
        T[i].x=rand()%100-25;
        T[i].y=rand()%100-25;
        out<<setw(4)<<T[i].x<<setw(4)<<T[i].y<<endl;
     }
     out.close();
    /*cin>>N;
    for(int i=0; i<N; ++i)  cin>>T[i].x>>T[i].y;*/
    sort(T,T+N);
    for(int i=0; i<N; ++i) cout<<setw(4)<<T[i].x<<setw(4)<<T[i].y<<endl;
    int t1,t2;
    printf("rencent point's distance is %f\n", distant(0, N-1, t1, t2));
  //  for(int i=0; i<N; ++i)  cout<<T[i].x<<"  "<<T[i].y;
    cout<<setw(4)<<T[b].x<<setw(4)<<T[b].y<<endl;
    cout<<setw(4)<<T[b1].x<<setw(4)<<T[b1].y<<endl;
    return 0;
}

