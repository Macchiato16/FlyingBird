#include "ground.h"
#include"mainscene.h"
void Ground::groundPosition()
{
    //处理移动的位置
    m_x-=moveSpeed;
    //图片移动一段距离立即重置
    if(m_x<=-960)
     {
        m_x=0;
    }
}

Ground::Ground(QObject *parent) : QObject(parent)
{
//初始化图片资源
m_ground.load(":/image/ground.png");
//初始化坐标
m_x=0;
m_y=540;
//地面移动速度
moveSpeed=MOVESPEED;

}
