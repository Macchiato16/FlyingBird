#ifndef BRID_H
#define BRID_H

#include <QObject>
#include <QWidget>
#include<QPixmap>

class Bird : public QObject
{
    Q_OBJECT
public:
    //小鸟的图片
    QPixmap m_bird;
    //坐标
    int m_x;
    int m_y;
    //垂直方向运动速度
    int speed;
    //速度的变化量
    int dv;
    //碰撞箱
    QRect crashBox;
    explicit Bird(QObject *parent = nullptr);
    //更新位置的函数
    void  birdPosition();
    //跳跃的函数
    void  jump();

signals:

};

#endif // BRID_H
