#ifndef BIRD_H
#define BIRD_H

#include <QPixmap>
#include <QRect>

class Bird {
public:
    Bird(const QPixmap &sprite, const QPoint &startPos = QPoint(100, 250));
    void update();
    void jump();
    QRect getRect() const;
    void reset();

private:
    QPixmap sprite;
    QRect rect;
    int velocity;

    friend class MainWindow; 
};

#endif 

