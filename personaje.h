#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>


using namespace sf;



class personaje{
	
private:
	
	int y;
	int vely;
	int ancho;
	int alto;
	Sprite sflappy;
	
	
public:
	personaje(Texture *tex , int y);
	
	void subir();
	
	void dibujar(RenderWindow *w);
	
	void bajar();
	
	
	
	
};
#endif //PERSONAJE_H
