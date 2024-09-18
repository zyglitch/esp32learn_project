#include <Arduino.h>

int system_time_count = 0;
int system_time_second = 0;
int system_time_minute = 0;
int system_time_hour = 0;
int system_time_day = 0;

void system_time_add(){
  system_time_count++;

  if (system_time_count == 60 )
  {
    system_time_count = 0;
    system_time_second++;
  }
  if(system_time_second == 60 )
  {
    system_time_second = 0;
    system_time_minute++;
  }
  if(system_time_minute == 60 )
  {
    system_time_minute = 0;
    system_time_hour++;
  }
  if(system_time_hour == 24 )
  {
    system_time_hour = 0;
    system_time_day++;
  }


}



void setup() {

hw_timer_t *timer_alreadyTime  = NULL;


    //	函数名称：timerBegin()
    //	函数功能：Timer初始化，分别有三个参数
    //	函数输入：1. 定时器编号（0到3，对应全部4个硬件定时器）
    //			 2. 预分频器数值（ESP32计数器基频为80M，80分频单位是微秒）
    //			 3. 计数器向上（true）或向下（false）计数的标志
    //	函数返回：一个指向 hw_timer_t 结构类型的指针

timer_alreadyTime = timerBegin(0, 40000, true);//实现每秒中断 (将定时器1(timer0)与timer_alreadyTime绑定)


    //	函数名称：timerAttachInterrupt()
    //	函数功能：绑定定时器的中断处理函数，分别有三个参数
    //	函数输入：1. 指向已初始化定时器的指针（本例子：timer）
    //			 2. 中断服务函数的函数指针
    //			 3. 表示中断触发类型是边沿（true）还是电平（false）的标志
    //	函数返回：无

timerAttachInterrupt(timer_alreadyTime, &system_time_add, true);//绑定中断函数



    //	函数名称：timerAlarmWrite()
    //	函数功能：指定触发定时器中断的计数器值，分别有三个参数
    //	函数输入：1. 指向已初始化定时器的指针（本例子：timer）
    //			 2. 第二个参数是触发中断的计数器值，单位为us
    //			 3. 定时器在产生中断时是否重新加载的标志
    //	函数返回：无

timerAlarmWrite(timer_alreadyTime, 2000, true);//设置定时器的计数器值，80000000/40000=2000 ,即每秒中断一次
timerAlarmEnable(timer_alreadyTime);//使能定时器的中断



}




void loop() {




}





