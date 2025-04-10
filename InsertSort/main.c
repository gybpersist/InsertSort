#include <stdio.h>
#include <stdbool.h>

//插入排序 是把无序序列依次插入到有序序列，一般是从尾部开始比较
bool InsertSort(int buf[],int bufsize)
{
    //备份元素
    int temp=0;

    //1 选择第一个元素作为已经排序过的，剩下的元素作为无序序列
    for (int i = 1; i < bufsize; ++i)
    {
        //备份待插入元素
        temp = buf[i];
        //备份待插入元素下标
        int subscript=i;

        //把当前待插入元素与有序序列中元素进行比较，从有序序列尾部开始
        for (int j = i-1 ; j >= 0 ; j--)
        {
            //当待插入元素 > 当待插入元素前面的值
            if(temp >= buf[j])
            {
                break;
            }

            //当待插入元素 < 当待插入元素前面的值
            if(temp < buf[j])
            {
                subscript=j;
                //把待插入元素前面的值向后移动
                buf[j + 1] = buf[j];
            }
        }
        //把待插入元素插入指定位置
        buf[subscript]=temp;
    }
}

//遍历元素
bool Prin(int buf[],int size)
{
    printf("Element:");
    for(int i= 0;i< size;i++)
    {
        printf("%d  ",buf[i]);
    }
    printf("\n");
    return true;
}

int main()
{
    //定义一个数组 10个整数
    int buf[10]={2,4,1,6,8,2,6,1,7,4};

    Prin(buf,sizeof(buf)/ sizeof(buf[1]));

    InsertSort(buf, sizeof(buf)/ sizeof(buf[1]));

    Prin(buf,sizeof(buf)/ sizeof(buf[1]));

    return 0;
}
