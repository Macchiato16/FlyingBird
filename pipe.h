#ifndef PIPE_H
#define PIPE_H
#define upPipe ":/image/Pipeline1.png"
#define downPipe ":/image/Pipeline2.png"
#include<QPixmap>
#include<QString>
#include<QRect>
class Pipe
{
public:
    //管子的图片
    QPixmap m_pipe1;
    QPixmap m_pipe2;
    //坐标
    int m1_x,m1_y;
    int m2_x,m2_y;
    //管子是否闲置
    bool m_free;
    //管子移动速度
    int moveSpeed;
    //管子的碰撞箱
    QRect crashBox1;
    QRect crashBox2;
    //计算坐标
    void  pipePosition();
    Pipe();


};

#endif // PIPE_H
