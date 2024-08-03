#include "bird.h"

Bird::Bird(QObject *parent) : QObject(parent)
{
   //载入图片资源
    m_bird.load(":/image/Bird.png");
    //初始化坐标
   m_x=120;
   m_y=100;
   //初始化碰撞箱,碰撞箱要比图片窄一些，一侧窄7个像素差不多
   crashBox.setWidth(41);
   crashBox.setHeight(40);
   crashBox.moveTo(m_x+7,m_y);
   //初始化速度和速度变化量
   speed=0;
   dv=2;

}
void  Bird::birdPosition()
{
    //每过一帧都要调整速度
    speed+=dv;
    //根据速度算出垂直坐标
    m_y+=speed;
    //如果小鸟位置低于地面，则将小鸟与地面水平（防止无限下落）
    if(m_y>=500)
    {
        m_y=500;
    }
    //如果小鸟位置高于天空，则将小鸟与天空水平（防止升天）
    if(m_y<=0)
    {
        m_y=0;
    }
    crashBox.moveTo(m_x+7,m_y);
}

void Bird::jump()
{
    //跳跃时，给予一个固定的向上速度
    speed=-18;
}
