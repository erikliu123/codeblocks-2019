#include "stdlib.h"
#include <string.h>
#include "time.h"
#include <u
#include <stdio.h>

#define N 10
/**
    ð������
**/
int main()
{
    int nums[N] = {4, 5, 2, 10, 7, 1, 8, 9, 6, 3};
    int i, j, temp, isSorted;
    char str[100]="���κ�@ipad";
    //gets(str);//better
    for(int i=0; i<strlen(str); ++i)
    {
        int k=(unsigned char)str[i];
        printf("%-3d ",k);
    }
     printf("\n");
//�Ż��㷨�������� n-1 �ֱȽ�
    for(i=0; i<N-1; i++)
    {
        isSorted = 1; //����ʣ�µ�Ԫ���Ѿ��������
        for(j=0; j<N-1-i; j++)
        {
            if(nums[j] > nums[j+1])//ǰ���Ԫ�ش󣬽��н���
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                isSorted = 0; //һ����Ҫ��������Ԫ�أ���˵��ʣ�µ�Ԫ��û�������
            }
        }

        if(isSorted)
            break; //���û�з���������˵��ʣ�µ�Ԫ���Ѿ��������

    }
    for(i=0; i<N; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;

}
/*
main()
{
  int i,num;
  num=2;
  for(i=0;i<3;i++)
  {
    printf("\40: The num equal %d \n",num);
    num++;
    {
      auto  num=1;
      printf("\40: The internal block num equal %d \n",num);
      num++;
    }
  }
  getch();
}*/
/*
//���������
int main()
{
    int i,j;
    int a[10][10];
    printf("\n");
    for(i=0; i<10; i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2; i<10; i++)
        for(j=1; j<i; j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    for(i=0; i<10; i++)
    {
        for(j=0; j<=i; j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
}
*/

//
//
////��ӡʱ��
//int main()
//{
//    time_t lt; /*define a longint time varible*/
//    lt=time(NULL);/*system time and date*/
//    printf(ctime(&lt)); /*english format output*/
//    printf(asctime(localtime(&lt)));/*tranfer to tm*/
//    printf(asctime(gmtime(&lt))); /*tranfer to Greenwich time*/
//}
/*
int main()
{
    char str[100]="�ͷ���";
    //gets(str);//better
    for(int i=0; i<strlen(str); ++i)
    {
        int k=(unsigned char)str[i];
        printf("%x ",k);
    }

    putchar('\n');
    fgets(str,80,stdin);
    for(int i=0; i<strlen(str); ++i)
        printf("%x ",str[i]);
}
*/

