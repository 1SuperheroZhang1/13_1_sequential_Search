#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 【顺序查找原理解析】
 *      顺序查找又称为线性查找，它对于顺序表和链表都是适用的。
 *      对于顺序表，可以通过数组下标递增来顺序扫描每个元素；
 *      对于链表，则通过指针next来依次扫描每个元素。
 * 【顺序查找的时间复杂度】：O(n)
 * */
typedef int ElemType;
typedef struct {
    ElemType* elem;//整型指针
    int TableLen;//存储动态数组中元素的个数
}SSTable;
//初始化顺序表
void ST_Init(SSTable &ST,int len){//init进行了随机数生成
    //多申请了一个位置，为了存哨兵
    ST.TableLen=len+1;
    ST.elem=(ElemType*) malloc(sizeof(ElemType)*ST.TableLen);
    int i;
    srand(time(NULL));//随机数生成
    //向顺序表中存入数据
    for(i=1;i<ST.TableLen;i++){//因为第0个是哨兵，所以从1随机
        ST.elem[i]=rand()%100;//为了生成0-99的数字
    }
}
//打印顺序表
void ST_print(SSTable ST){
    int i;
    for(i=1;i<ST.TableLen;i++){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}
int search_seq(SSTable ST,ElemType key){
    ST.elem[0]=key;//让0号元素作为哨兵，有了这个，在循环时，可以少写一个i>=0的判断
    int i;
    for(i=ST.TableLen-1;ST.elem[i]!=key;i--);
    return i;
}
//顺序查找
int main() {
    SSTable ST;
    ST_Init(ST,10);
    ST_print(ST);
    int pos;//存储查询元素的位置
    ElemType key;
    printf("please input search key:\n");
    scanf("%d",&key);
    pos=search_seq(ST,key);
    if(pos){
        printf("find key,pos=%d\n",pos);
    }else{
        printf("not find\n");
    }
    return 0;
}
