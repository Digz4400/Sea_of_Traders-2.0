#include "enemy.h"

Enemy::Enemy(sf::Texture &baza)
{
    setTexture(baza);
    vx=100;
    vy=100;
    kierunek = sf::Vector2f(0,1);
    setTextureRect(sf::IntRect(32,32,32,32));
}
void Enemy::Animate(sf::Time elapsed, std::vector<Obiekty> &a, sf::Clock &timer)
{
    move(kierunek.x*vx*elapsed.asSeconds(),kierunek.y*vy*elapsed.asSeconds());
    sf::IntRect Pozycja = sf::IntRect(this->getPosition().x,this->getPosition().y,32,32);
    sf::Vector2f T = sf::Vector2f(this->getPosition().x+this->getGlobalBounds().width/2,this->getPosition().y);
    sf::Vector2f L = sf::Vector2f(this->getPosition().x,this->getPosition().y+this->getGlobalBounds().height/2);
    sf::Vector2f R = sf::Vector2f(this->getPosition().x+this->getGlobalBounds().width,this->getPosition().y+this->getGlobalBounds().height/2);
    sf::Vector2f D = sf::Vector2f(this->getPosition().x+this->getGlobalBounds().width/2,this->getPosition().y+this->getGlobalBounds().height);
    sf::IntRect PozycjaEle;
    std::cout<<"T "<<T.x<<" "<<T.y<<std::endl;
    std::cout<<"L "<<L.x<<" "<<L.y<<std::endl;
    std::cout<<"R "<<R.x<<" "<<R.y<<std::endl;
    std::cout<<"D "<<D.x<<" "<<D.y<<std::endl;
    int q;
    if(rand()%2)
    {
        q=1;
    }
    else
    {
        q=-1;
    }
    for(auto &p:a)
    {
        if(p.getGlobalBounds().contains(T))
        {
            kierunek.x=q;
            kierunek.y=0;
        }
        if(p.getGlobalBounds().contains(L))
        {
            kierunek.x=0;
            kierunek.y=q;
        }
        if(p.getGlobalBounds().contains(R))
        {
            kierunek.x=0;
            kierunek.y=q;
        }
        if(p.getGlobalBounds().contains(D))
        {
            kierunek.x=q;
            kierunek.y=0;
        }
    }
    if(this->getPosition().x<0)
    {
        kierunek.x = 1;
    }
    if(this->getPosition().x>1000-32)
    {
        kierunek.x = -1;
    }
    if(this->getPosition().y<0)
    {
        kierunek.y = 1;
    }
    if(this->getPosition().y>600-32)
    {
        kierunek.y = -1;
    }

}
