#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,m;
    printf("请输入阶数:");
    scanf("%d", &k);
    printf("\n请输入项数:");
    scanf("%d", &m);
    int k_m = demo_1_17(k,m);

    printf(k_m<0 ? "输入不合法，要求：k>1 且 m>=0\n" : "第%d阶斐波那契数列第%d项的值是%d\n", k,m,k_m);
    return 0;
}

int demo_1_17(int k, int m)
{
    /*  计算k阶斐波那契数列第m项的值。
        k阶斐波那契数列： 前k-1项全为0，第k项为1，往后每计算一项都是前面k项的求和。
        当：
            k=0 : 数列不存在
            k=1 : 1 1 1 1 1 1 .......
            k=2 : 0 1 1 2 3 5 .......
            k=3 : 0 0 1 1 2 4 .......
            .
            .
            .
    */

    // 在该算法中，忽略k=0与k=1的计算
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
