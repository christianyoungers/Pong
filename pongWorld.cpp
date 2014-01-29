#include "headers.h"

PongWorld::PongWorld()
     : m_isRunning(true), m_p1Score(0), m_p2Score(0)  
{ 
     m_p1 = new Player(PLAYER1X, PLAYER1Y);
     m_p2 = new Player(PLAYER2X, PLAYER2Y);
     m_ball = new Ball((WIDTH/2) - SERVE_DISPLACE, rand() % (HEIGHT-BALLDIM), BALLVEL);
}

PongWorld::~PongWorld()
{
     delete m_p1;
     delete m_p2;
     delete m_ball;
}

void PongWorld::title()
{
     std::string titleA = "Welcome to my little game of pong...";
     std::string titleB = "must press space to begin muhahaha...";

     for ( int i = 0; i < 200; i++ )
     {
	  glClear(GL_COLOR_BUFFER_BIT);
	  glPushMatrix(); //start phase
	  glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix

	  glColor4ub(0, 255, 0, 255);
	  glRasterPos2f(190, 250);
	  for ( int i = 0; i < titleA.size(); i++ )
	       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, titleA[i]);

	  glPopMatrix();  //end phase
	  SDL_GL_SwapBuffers();
     }

     while ( true )
     {
     	  if ( SDL_PollEvent(&m_event) && m_event.type == SDL_KEYUP ) 
	  {	    
	       if ( m_event.key.keysym.sym == SDLK_ESCAPE )
		    exit(1);
	       if ( m_event.key.keysym.sym == SDLK_SPACE )
		    return;
	  }

	  //RENDERING to the screen
	  glClear(GL_COLOR_BUFFER_BIT);
	  glPushMatrix(); //start phase
	  glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix

	  glColor4ub(0, 255, 0, 255);
	  glRasterPos2f(190, 250);
	  for ( int i = 0; i < titleA.size(); i++ )
	       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, titleB[i]);

	  glPopMatrix();  //end phase
	  SDL_GL_SwapBuffers();
     }
}

void PongWorld::pause()
{
     std::string pause = "Paused";

     while ( true )
     {
     	  if ( SDL_PollEvent(&m_event) && 
	       m_event.type == SDL_KEYUP && 
	       m_event.key.keysym.sym == SDLK_p )
	       return;

	  //RENDERING to the screen
	  glClear(GL_COLOR_BUFFER_BIT);
	  glPushMatrix(); //start phase
	  glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix

	  glColor4ub(0, 255, 0, 255);
	  glRasterPos2f(350, 250);
	  for ( int i = 0; i < pause.size(); i++ )
	       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pause[i]);

	  glPopMatrix();  //end phase
	  SDL_GL_SwapBuffers();
     }
}

void PongWorld::p1Scored()
{
     std::string score = "Player 1 Scored! (Press Enter)";

     while ( true )
     {
     	  if ( SDL_PollEvent(&m_event) && 
	       m_event.type == SDL_KEYUP && 
	       m_event.key.keysym.sym == SDLK_RETURN )
	       return;

	  //RENDERING to the screen
	  glClear(GL_COLOR_BUFFER_BIT);
	  glPushMatrix(); //start phase
	  glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix

	  glColor4ub(0, 255, 0, 255);
	  glRasterPos2f(220, 250);
	  for ( int i = 0; i < score.size(); i++ )
	       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[i]);

	  glPopMatrix();  //end phase
	  SDL_GL_SwapBuffers();
     }
}

void PongWorld::p2Scored()
{
     std::string score = "Player 2 Scored! (Press Enter)";

     while ( true )
     {
     	  if ( SDL_PollEvent(&m_event) && 
	       m_event.type == SDL_KEYUP && 
	       m_event.key.keysym.sym == SDLK_RETURN )
	       return;

	  //RENDERING to the screen
	  glClear(GL_COLOR_BUFFER_BIT);
	  glPushMatrix(); //start phase
	  glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix

	  glColor4ub(0, 255, 0, 255);
	  glRasterPos2f(220, 250);
	  for ( int i = 0; i < score.size(); i++ )
	       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[i]);

	  glPopMatrix();  //end phase
	  SDL_GL_SwapBuffers();
     }
}

void PongWorld::events()
{
     //EVENTS
     while ( SDL_PollEvent(&m_event) )
     { 
	  //if the window was closed
	  if ( m_event.type == SDL_QUIT )
	       m_isRunning = false;

	  if ( m_event.type == SDL_KEYDOWN )
	  {
	       if ( m_event.key.keysym.sym == SDLK_w )
		    m_p1->setUp();
	       if ( m_event.key.keysym.sym == SDLK_s )
		    m_p1->setDown();
	       if ( m_event.key.keysym.sym == SDLK_UP )
		    m_p2->setUp();
	       if ( m_event.key.keysym.sym == SDLK_DOWN )
		    m_p2->setDown();
	  }

	  if ( m_event.type == SDL_KEYUP )
	  {
	       switch ( m_event.key.keysym.sym )
	       {
	       case SDLK_ESCAPE:
		    m_isRunning = false;
		    break;
	       case SDLK_p:
		    pause();
		    break;
		  
		    //insert here
	       }

	       if ( m_event.key.keysym.sym == SDLK_w )
		    m_p1->unsetUp();
	       if ( m_event.key.keysym.sym == SDLK_s )
		    m_p1->unsetDown();
	       if ( m_event.key.keysym.sym == SDLK_UP )
		    m_p2->unsetUp();
	       if ( m_event.key.keysym.sym == SDLK_DOWN )
		    m_p2->unsetDown();
		      
	  }
     }
}

void PongWorld::logic()
{
     //LOGIC
     if ( m_p1Score == 9 )
	  gameOver("1");
     if ( m_p2Score == 9 )
	  gameOver("2");	  

     m_p1->move();
     m_p2->move();
     if ( m_ball->checkCollision(m_p1, m_p2) )
	  if ( m_ball->checkIfX(m_p1, m_p2) )
	       m_ball->changeVelX();
	  else
	       m_ball->changeVelY();
     m_ball->move();

     if ( m_ball->x() < 0 )
     {
	  m_p2Score++;
	  delete m_p1;
	  delete m_p2;
	  delete m_ball;
 
	  p2Scored();

	  m_p1 = new Player(PLAYER1X, PLAYER1Y);
	  m_p2 = new Player(PLAYER2X, PLAYER2Y);
	  m_ball = new Ball((WIDTH/2) - SERVE_DISPLACE, rand() % (HEIGHT-BALLDIM), BALLVEL);
	  return;
     }

     if ( m_ball->x() > WIDTH )
     {
	  m_p1Score++;
	  delete m_p1;
	  delete m_p2;
	  delete m_ball;

	  p1Scored();

	  m_p1 = new Player(PLAYER1X, PLAYER1Y);
	  m_p2 = new Player(PLAYER2X, PLAYER2Y);
	  m_ball = new Ball((WIDTH/2) + SERVE_DISPLACE, rand() % (HEIGHT-BALLDIM), -BALLVEL);
	  return;
     }
}

void PongWorld::render()
{
     //RENDERING to the screen
     glClear(GL_COLOR_BUFFER_BIT);

     glPushMatrix(); //start phase

     glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix

     drawLine();
     m_p1->draw();
     m_p2->draw();
     m_ball->draw();

     glRasterPos2f(WIDTH / 2 - 30, 50);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + m_p1Score);

     glRasterPos2f(WIDTH / 2 + 15, 50);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + m_p2Score);

     glPopMatrix();  //end phase

     SDL_GL_SwapBuffers();
}

void PongWorld::drawLine()
{
     glColor4ub(255, 255, 255, 255);

     glBegin(GL_LINES);
     glVertex2f(WIDTH / 2, 0);
     glVertex2f(WIDTH / 2, HEIGHT);
     glEnd();
}
 
void PongWorld::gameOver(std::string playerNum)
{
     std::string over = "Game Over. Player " + playerNum + " Wins! (Press Esc)";

     while ( true )
     {
     	  if ( SDL_PollEvent(&m_event) && 
	       m_event.type == SDL_KEYUP && 
	       m_event.key.keysym.sym == SDLK_ESCAPE )
	       exit(1);

	  //RENDERING to the screen
	  glClear(GL_COLOR_BUFFER_BIT);
	  glPushMatrix(); //start phase
	  glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix

	  glColor4ub(0, 255, 0, 255);
	  glRasterPos2f(150, 250);
	  for ( int i = 0; i < over.size(); i++ )
	       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, over[i]);

	  glPopMatrix();  //end phase
	  SDL_GL_SwapBuffers();
     }
}
