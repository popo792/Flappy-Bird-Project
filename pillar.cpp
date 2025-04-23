#include "pillar.h"
#include <QRandomGenerator>

QVector<QRect> Pillar::generateInitial(int count, int screenHeight) {
    QVector<QRect> pipes;
    int gapHeight = 215;
    int pipeWidth = 100;
    int spacing = 300; // space between pipe pairs

    for (int i = 0; i < count; ++i) {
        int gapY = QRandomGenerator::global()->bounded(100, screenHeight - gapHeight - 100);
        int xPos = 500 + (i * spacing);

        // Top pipe
        pipes.append(QRect(xPos, 0, pipeWidth, gapY));

        // Bottom pipe
        pipes.append(QRect(xPos, gapY + gapHeight, pipeWidth, screenHeight - (gapY + gapHeight)));
    }

    return pipes;
}

void Pillar::movePipes(QVector<QRect> &pipes, int screenWidth, int screenHeight) {
    int gapHeight = 200;
    int pipeWidth = 100;
    int spacing = 300; // same as generateInitial

    for (int i = 0; i < pipes.size(); ++i) {
        pipes[i].translate(-3, 0);
    }

    // Remove first pair if out of screen
    if (!pipes.isEmpty() && pipes.first().right() < 0) {
        pipes.removeFirst();
        pipes.removeFirst();

        // Add a new pipe pair
        int gapY = QRandomGenerator::global()->bounded(100, screenHeight - gapHeight - 100);
        int lastX = pipes[pipes.size() - 2].x(); // second last pipe's x (because last is bottom of pair)
        int newX = lastX + spacing;

        pipes.append(QRect(newX, 0, pipeWidth, gapY)); // top
        pipes.append(QRect(newX, gapY + gapHeight, pipeWidth, screenHeight - (gapY + gapHeight))); // bottom
    }
}

bool Pillar::checkCollision(const QRect &bird, const QVector<QRect> &pipes) {
    for (int i = 0; i < pipes.size(); ++i) {
        if (bird.intersects(pipes[i]))
            return true;
    }
   // for (const QRect &pipe : pipes) {
     //   if (bird.intersects(pipe))
      //      return true;
    //}
    return false;
}
