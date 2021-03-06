// lift.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "lift.h"

using namespace std;

void myTimerProc(myLift* l)
{
    l->Nowtime = l->Nowtime + 1;
    //电梯组行动
    for (int i = 0; i < 5; i++)
    {
        l->G[i]->action();
    }
    // 乘客活动
    for (int i = 0; i < l->N; i++)
    {
        l->P[i]->action();
    }
}

/*初始化电梯系统*/
myLift::myLift()
{
    QTime current_time =QTime::currentTime();

    srand(current_time.msec());
    //GuideInput();
    SYSTEMTIME NowTime;
    GetLocalTime(&NowTime);
    Nowtime.set(NowTime.wHour, NowTime.wMinute, NowTime.wSecond);
    cout<<NowTime.wMinute<<':'<<NowTime.wSecond<<endl;
    E[0] = new ElevatorLift(S, K, T, &Nowtime);
    E[1] = new ElevatorLift(S, K, T, &Nowtime);
    E[2] = new E1(S, K, T, &Nowtime);
    E[3] = new E1(S, K, T, &Nowtime);
    E[4] = new E2(S, K, T, &Nowtime);
    E[5] = new E2(S, K, T, &Nowtime);
    E[6] = new E3(S, K, T, &Nowtime);
    E[7] = new E3(S, K, T, &Nowtime);
    E[8] = new E4(S, K, T, &Nowtime);
    E[9] = new E4(S, K, T, &Nowtime);

    for (int i = 0; i < 5; i++)
    {
        G[i] = new Group(E[2*i], E[2*i + 1]); //初始化电梯分组
    }
    for (int i = 0; i < N; i++)
    {
        P[i] = new Passenger(M, L, E, &Nowtime);//初始化乘客
    }

}
