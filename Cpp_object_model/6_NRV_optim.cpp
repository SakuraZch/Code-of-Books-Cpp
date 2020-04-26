
// 2020/4/26 //

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <time.h>

class Test
{
    private:
        double arr[100];
    public:
        Test()
        {
            memset(arr, 0, 100 * sizeof(double));
        }
        Test(const Test& item) // write this to activite NRV optimization
        {
            memcpy(this, &item, sizeof(Test));
        }
        friend Test foo(double);
};

Test foo(double val)
{
    Test local;
    local.arr[0] = val;
    local.arr[99] = val;

    return local;
}

void PrintLocalTime()
{
    struct tm* timePtr;
    time_t secsNow;
    time(&secsNow);
    timePtr = localtime(&secsNow);
    printf("The date is %d-%d-%02d\n", timePtr->tm_mon + 1, timePtr->tm_mday, timePtr->tm_year);
    printf("Local time is %02d:%02d:%02d\n", timePtr->tm_hour, timePtr->tm_min, timePtr->tm_sec);
}

int main()
{
    PrintLocalTime();
    const int ITER_TIMES = 1000000000;
    for(int i = 0; i < ITER_TIMES; i++)
    {
        Test temp = foo(double(i));
    }
    PrintLocalTime();

    system("pause");
    return 0;
}