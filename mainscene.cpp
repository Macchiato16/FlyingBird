#include "mainscene.h"
#include<QPainter>
#include<QIcon>
#include<QTimer>
#include<QMouseEvent>
#include<ctime>
#include<QMessageBox>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
{
     initScene();
     playGame();
}

MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    //设置窗口固定尺寸
    setFixedSize(960,660);
    //设置游戏标题
    setWindowTitle("FlyBird");
    //设置图标
    setWindowIcon(QIcon(":/image/Bird.png"));
    //导入背景图片
    m_backGround.load(":/image/background.png");
    //设置定时器
    m_timer.setInterval(20);
    //时间间隔初始化为0
    m_recorder=0;
    //调整随机种子
    srand((unsigned int)time(NULL));
}

void MainScene::playGame()
{
    //启动定时器
    m_timer.start();
    //监听定时器信号，每次执行命令
    connect(&m_timer,&QTimer::timeout,[=]()
    {
        //生成管子
       pipeToScene();
    //更新界面中元素位置
      updatePosition();
      //检测是否发生碰撞
      inspectCrash();
      //调用绘图事件
      update();
    }
    );
}

void MainScene::updatePosition()
{
    //更新地面坐标
    m_ground.groundPosition();
    //更新小鸟坐标
    m_bird.birdPosition();
    //更新管子坐标
    for(int i=0;i<10;i++)
    {
        if(!pipes[i].m_free)
        {
            pipes[i].pipePosition();
        }
    }
}

void MainScene::pipeToScene()
{
    //未达到出场间隔
   if(m_recorder<100)
   {
       m_recorder++;
       return;
   }
   m_recorder=0;
   for(int i=0;i<10;i++)
   {
       if(pipes[i].m_free)
       {
           pipes[i].m_free=false;
           //坐标
           pipes[i].m1_x= pipes[i].m2_x=960;
           pipes[i].m1_y=-500+rand()%500;
           pipes[i].m2_y=pipes[i].m1_y+650+rand()%50;
           pipes[i].crashBox1.moveTo(pipes[i].m1_x,pipes[i].m1_y);
           pipes[i].crashBox1.moveTo(pipes[i].m2_x,pipes[i].m2_y);
           break;
       }
   }

}

void MainScene::inspectCrash()
{

    for(int i=0;i<10;i++)
    {
        if(!pipes[i].m_free)
        {
            //检测是否发生碰撞
           if(pipes[i].crashBox1.intersects(m_bird.crashBox)||pipes[i].crashBox2.intersects(m_bird.crashBox))
           {
               //发生碰撞则停止定时器，游戏结束
               m_timer.stop();
               QMessageBox::about(this,"游戏结束","点击退出");
                exit(0);
           }
        }
    }
}

void  MainScene::paintEvent(QPaintEvent*)
{
   QPainter painter(this);
   //绘制背景
   painter.drawPixmap(0,0,960,660,m_backGround);
   //绘制管道
   for(int i=0;i<10;i++)
   {
       if(!pipes[i].m_free)
       {
           painter.drawPixmap(pipes[i].m1_x,pipes[i].m1_y,100,500,pipes[i].m_pipe1);
           painter.drawPixmap(pipes[i].m2_x,pipes[i].m2_y,100,500,pipes[i].m_pipe2);
       }
   }
   //绘制地面
   painter.drawPixmap(m_ground.m_x,m_ground.m_y,1920,330,m_ground.m_ground);
   //绘制小鸟
   painter.drawPixmap(m_bird.m_x,m_bird.m_y,55,40,m_bird.m_bird);
}

void MainScene::mousePressEvent(QMouseEvent * ev)
{
    if(ev->button()==Qt::LeftButton)
    {
        m_bird.jump();
    }
}
