//#include <iostream>
#include <bits/stdc++.h>
#define MODS 1000000007
using namespace std;
/**
���ǰ�һ������Ϊ��Ȥ�ģ����ҽ����� ����
1. ��������ֻ����0, 1, 2, 3�������ĸ����ֶ����ֹ�����һ�Ρ� ����
2. ���е�0�����������е�1֮ǰ�������е�2�����������е�3֮ǰ�� ����
3. ���λ���ֲ�Ϊ0��

*/
int ans=0;
int pos[5]={-1,-1,0,-1};
int counts[5];
int N;
/**
    *DFS is a poor way when N is bigger than 25
    *but can gain some points
*/
void DFS(int len){
    if(len==N){
        int flag=1;
        for(int i=0;i<4;++i){
            if(counts[i]==0){
                flag=0;
                break;
            }
        }
        if(flag) ++ans;
        if(ans>=1000000007) ans=0;
        return ;
    }
    for(int i=0;i<4;++i){
        if(i==1 || (i==3)){
            counts[i]++;
            DFS(len+1);
            counts[i]--;
        }
        else if(i==0 && (counts[1]==0)){
            counts[i]++;
            DFS(len+1);
            counts[i]--;
        }
        else if(i==2 && (counts[3]==0)){
            counts[i]++;
            DFS(len+1);
            counts[i]--;
        }
    }
}
/**
    *DP is not easy to think, more experience is needed ��2,0��>(3,1)
    *���һ��Ԫ�ز�������2����0
*/
long long DP[1001][7];
int main()
{
    cin>>N;
    counts[2]++;
    if(N<20){
        DFS(1);
        cout << ans << endl;
    }
    DP[0][1]=1;
    for(int i=1;i<N;++i){
        DP[i][1]=1;                 /** ȫ����2�������can remove*/
        DP[i][2]=(2*DP[i-1][2]+1)%MODS;        /** ֻ��0,2*/
        DP[i][3]=(DP[i-1][3]+1)%MODS;      /** ֻ��2,3*/
        DP[i][4]=(DP[i-1][4]*2+DP[i-1][2])%MODS;   /**ֻ��2,0,1*/
        DP[i][5]=(DP[i-1][5]*2+DP[i-1][2]+DP[i-1][3])%MODS; /**ֻ��2,3,0*/
        DP[i][6]=(DP[i-1][6]*2+DP[i-1][4]+DP[i-1][5])%MODS; /**ֻ��2,3,0,1*/
        cout << DP[i][6] << endl;
    }
    return 0;
}
