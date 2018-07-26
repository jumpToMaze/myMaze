#ifndef Game_h
#define Game_h
#include "Interface.h"

class Game : public Interface
{
public:
	Game();
	void start();
	~Game();
private:
	bool gameOver();
};

#endif // !Game_h

