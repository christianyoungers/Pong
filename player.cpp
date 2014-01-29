#include "headers.h"

Player::Player(int x, int y)
     : m_x(x), m_y(y), m_width(PLAYERW), m_height(PLAYERH), m_up(false), m_down(false)
{}

void Player::move()
{
     if ( m_up )
     {
	  m_y -= PLAYERVEL;
	  if ( m_y < 0 )
	       m_y = 0; 
     }
     if ( m_down )
     {
	  m_y += PLAYERVEL;
	  if ( m_y + PLAYERH > HEIGHT )
	       m_y = HEIGHT - PLAYERH;
     }
}

void Player::draw()
{
     glColor4ub(255, 255, 255, 255);

     glBegin(GL_QUADS);
     glVertex2f(m_x, m_y);
     glVertex2f(m_x + m_width, m_y);
     glVertex2f(m_x + m_width, m_y + m_height);
     glVertex2f(m_x, m_y + m_height);
     glEnd();
}
