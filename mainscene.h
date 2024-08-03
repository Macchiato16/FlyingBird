#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"bird.h"
#include<QTimer>
#include"ground.h"
#include "pipe.h"
#define MOVESPEED 3
class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    //小鸟
    Bird m_bird;
    //背景
     QPixmap m_backGround;
     //地面
     Ground m_ground;
     //定时器
     QTimer m_timer;
     //初始化场景
     void initScene();
     //启动游戏
     void playGame();
     //更新场景中所有元素位置
     void  updatePosition();
     //管子出现
     void  pipeToScene();
     //管子数组
     Pipe pipes[10];
     //记录出场间隔
     int m_recorder;
     //检测碰撞
     void  inspectCrash();
     //重写绘图事件
     void  paintEvent(QPaintEvent*);
     //重写鼠标按下事件，鼠标左键按下时时触发跳跃
     void mousePressEvent(QMouseEvent*ev);

    MainScene(QWidget *parent = nullptr);
    ~MainScene();
};
#endif // MAINSCENE_H
