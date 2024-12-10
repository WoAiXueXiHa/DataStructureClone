#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//时间复杂度的引入
void Func1(int N)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            ++count;
        }
    }

    for (int k = 0; k < 2 * N; ++k)
    {
        ++count;
    }

    int M = 10;
    while (M--)
    {
        ++count;
    }
    printf("%d\n", count);
}

//常数阶O(1)
/*常数阶的操作数量与输入数据大小n无关，即不随着n的变化而变化
在CountSize(int n)中，尽管操作数量size很大，但由于其与输入数据大小n无关，因此时间复杂度仍为O(1)*/
int CountSize(int n) {
    int size = 100000;
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        count++;
    }
    return count;
}

//线性阶O(n)
/*操作数量相对于输入数据大小n以线性级别增长,通常出现在单层循环中*/
//遍历数组和遍历链表等操作,O(n),n是数组或者链表的长度
int Test1(int n) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        count++;
    }
    return count;
}
int Test2(int m) {
    int count = 0;
    while (count < m)
    {
        count++;
    }
    return count;
}

//平方阶O(n^2)
/*平方阶的操作数量相对于输入数据大小𝑛以平方级别增长
平方阶通常出现在嵌套循环中，外层和内层都为O(𝑛)，因此总体为O(n^2)*/

void BubbleSort(int* arr, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)//两两排序，有size个元素，则有size - 1趟
    {
        bool flag = 1;//假设这一趟已经有序
        for (size_t j = 0; j < size - 1 - i; j++)//排序完成的元素无需作比较，逐次往后比较
        {
            if (arr[j] > arr[j + 1])//顺序，如果降序则改为<
            {
                flag = 0;//发生了交换，说明无序
                int tmp = arr[j];//创建第三个变量方便排序
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;//升序完成
            }
        }
        if (flag) break;//未交换说明有序，直接跳出循环！
    }
}

//对数阶O(logn)
//二分查找是典型的对数阶，每次减少到原来的一般半个

int BinarySearch(int* arr, int size, int x) {
    asseert(arr);

    int end = size - 1;//我们找的是索引
    int start = 0;

    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if (arr[mid] > x)
            end = mid - 1;
        else if (arr[mid] < x)
            start = mid + 1;
        else
            return mid;
    }
  
}

//指数阶O(2^n)
// 计算斐波那契递归Fib的时间复杂度？
long long Fib(size_t N)
{
    if (N < 3)
        return 1;

    return Fib(N - 1) + Fib(N - 2);
}

/******************************************************************************************************************************/
//空间复杂度

void BubbleSort(int* arr, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)//两两排序，有size个元素，则有size - 1趟
    {
        bool flag = 1;//假设这一趟已经有序
        for (size_t j = 0; j < size - 1 - i; j++)//排序完成的元素无需作比较，逐次往后比较
        {
            if (arr[j] > arr[j + 1])//顺序，如果降序则改为<
            {
                flag = 0;//发生了交换，说明无序
                int tmp = arr[j];//创建第三个变量方便排序
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;//升序完成
            }
        }
        if (flag) break;//未交换说明有序，直接跳出循环！
    }
}

// 计算阶乘递归Fac的空间复杂度？
long long Fac(size_t N)
{
    if (N == 0)
        return 1;
    return Fac(N - 1) * N;
}