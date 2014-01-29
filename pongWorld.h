#ifndef PONG_WORLD
#define PONG_WORLD

#include "headers.h"

class PongWorld
{
public:
     PongWorld();
     ~PongWorld();
     void title();
     void pause();
     void p1Scored();
     void p2Scored();
     void events();
     void logic();
     void render();
     const bool isRunning() { return m_isRunning; }
     void drawLine();
     void gameOver(std::string playerNum);
               
private:
     bool m_isRunning;
     Player* m_p1;
     Player* m_p2;
     Ball* m_ball;
     int m_p1Score;
     int m_p2Score;
     SDL_Event m_event;
     bool m_p1Scored;
     bool m_p2Scored;
          
};

#endif
