#ifndef GROUND_H
#define GROUND_H

#include <QObject>
#include<QPixmap>
class Ground : public QObject
{
    Q_OBJECT
public:
    //地面的图片
    QPixmap m_ground;
    //坐标
    int m_x;
    int m_y;
    //地面移动速度
    int moveSpeed;
    //计算坐标
    void  groundPosition();

    explicit Ground(QObject *parent = nullptr);

signals:

};

#endif // GROUND_H
