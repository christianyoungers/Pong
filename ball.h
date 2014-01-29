#ifndef BALL
#define BALL

#include "headers.h"

class Ball
{
public:
     Ball(int x, int y, int vel);
     void move();
     void draw();
     bool checkCollision(Player* p1, Player* p2);
     bool checkIfX(Player* p1, Player* p2);
     void changeVelX() { m_velX = -m_velX; }     
     void changeVelY() { m_velY = -m_velY; }
     int x() { return m_x; }     
     int y() { return m_y; }
     int dim() { return m_dim; }
     
private:
     int m_x;
     int m_y;
     int m_dim;
     int m_velX;
     int m_velY;
     
};

#endif
