#include "headers.h"

Ball::Ball(int x, int y, int vel)
     : m_x(x), m_y(y), m_dim(BALLDIM), m_velX(vel), m_velY(vel)
{}
 
void Ball::move()
{
     if ( m_y < 0 || m_y + m_dim > HEIGHT )
	  m_velY = -m_velY;
     m_x += m_velX;
     m_y += m_velY;
}

void Ball::draw() 
{
     glColor4ub(0, 255, 0, 255);

     glBegin(GL_QUADS);
     glVertex2f(m_x, m_y);
     glVertex2f(m_x + m_dim, m_y);
     glVertex2f(m_x + m_dim, m_y + m_dim);
     glVertex2f(m_x, m_y + m_dim);
     glEnd();
}

bool Ball::checkCollision(Player* p1, Player* p2)
{
     if ( p1->x() + p1->width() < m_x && p2->x() > m_x + m_dim )
	  return false;

     if ( m_velX < 0 && p1->y() > m_y + m_dim )
	  return false;
     if ( m_velX < 0 && p1->y() + p1->height() < m_y )
	  return false;

     if ( m_velX > 0 && p2->y() > m_y + m_dim )
	  return false;
     if ( m_velX > 0 && p2->y() + p2->height() < m_y )
	  return false; 

     return true;
}

bool Ball::checkIfX(Player* p1, Player* p2)
{
     if ( m_velX < 0 && p1->x() + p1->width() <= m_x - m_velX )
	  return true;
     if ( m_velX > 0 && p2->x() + m_velX >= m_x + m_dim )
	  return true;

     return false;
}

