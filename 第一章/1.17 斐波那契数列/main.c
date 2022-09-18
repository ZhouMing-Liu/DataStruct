#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,m;
    printf("���������:");
    scanf("%d", &k);
    printf("\n����������:");
    scanf("%d", &m);
    int k_m = demo_1_17(k,m);

    printf(k_m<0 ? "���벻�Ϸ���Ҫ��k>1 �� m>=0\n" : "��%d��쳲��������е�%d���ֵ��%d\n", k,m,k_m);
    return 0;
}

int demo_1_17(int k, int m)
{
    /*  ����k��쳲��������е�m���ֵ��
        k��쳲��������У� ǰk-1��ȫΪ0����k��Ϊ1������ÿ����һ���ǰ��k�����͡�
        ����
            k=0 : ���в�����
            k=1 : 1 1 1 1 1 1 .......
            k=2 : 0 1 1 2 3 5 .......
            k=3 : 0 0 1 1 2 4 .......
            .
            .
            .
    */

    // �ڸ��㷨�У�����k=0��k=1�ļ���
    if(k<=1 || m<0){
        return -1;
    }
    int k_m=0;
    if(m >= k){
        for(int i=1; i<=k; i++){
            k_m += demo_1_17(k, m-i);
        }
        return k_m;
    }
    else if(m == k-1){
        return 1;
    }
    else{
        return 0;
    }
}
