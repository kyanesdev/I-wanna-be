#ifndef PRESSENTER_H
#define PRESSENTER_H

#include <SFML/Graphics.hpp>

using namespace sf;


class pressEnter {
private:
	int x;
	int y;
	int ancho;
	int alto;
	Sprite spt;
	
public:
	pressEnter(Texture *tex, int x, int y);

	
};


#endif //pressEnter.h 

	
