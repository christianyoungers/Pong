#ifndef PLAYER
#define PLAYER

class Player
{
public:
     Player(int x, int y);
     void setUp() { m_up = true; }
     void setDown() { m_down = true; }
     void unsetUp() { m_up = false; }    
     void unsetDown() { m_down = false; }     
     void move();
     void draw();
     const int x() { return m_x; }
     const int y() { return m_y; }
     const int width() { return m_width; }
     const int height() { return m_height; }
          
private:
     int m_x;
     int m_y;
     int m_width;
     int m_height;
     bool m_up;
     bool m_down;
};

#endif
