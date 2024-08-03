#include "pipe.h"
#include<QString>
#include"mainscene.h"
void Pipe::pipePosition()
{
    //空闲管子不计算坐标
    if(m_free)
    {
        return;
    }
    //非空闲管子则计算坐标
    m1_x-=moveSpeed;
    m2_x-=moveSpeed;
    crashBox1.moveTo(m1_x,m1_y);
    crashBox2.moveTo(m2_x,m2_y);
    if(m1_x<=-100)
    {
        m_free=true;
    }
}

Pipe::Pipe()
{
    //载入图片资源
     m_pipe1.load(downPipe);
     m_pipe2.load(upPipe);
     //初始化为闲置状态
     m_free=true;
     //初始化坐标
    m1_x=m1_y=m2_x=m2_y=0;
    //初始化碰撞箱
    crashBox1.setWidth(100);
    crashBox1.setHeight(500);
    crashBox2.setWidth(100);
    crashBox2.setHeight(500);
    crashBox1.moveTo(m1_x,m1_y);
    crashBox1.moveTo(m2_x,m2_y);
    //初始化速度
    moveSpeed=MOVESPEED;
}