#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "obiekty.h"

class Enemy : public sf::Sprite
{
public:
    Enemy(sf::Texture &);
    void Animate(sf::Time,std::vector<Obiekty> &,sf::Clock &);
private:
    int vx;
    int vy;
    sf::Vector2f kierunek;
};

#endif // ENEMY_H
