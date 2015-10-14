#include "globals.h"
#include <math.h>
Player::Player(physfsManager* manager,sf::RenderWindow *app)
{
    win = app;
    /*

    For when we have actual Sprites.

    sprite = new AnimatedSprite();
    walk = new Animation();
    jump = new Animation();
    attack = new Animation();

    sf::Texture* tex = new sf::Texture();
    void* spriteSheet = manager->loadFile("sprites/Player.png");
    tex->loadFromMemory((void*)spriteSheet,sizeof(spriteSheet));
    walk->setSpriteSheet(*tex);
    jump->setSpriteSheet(*tex);
    attack->setSpriteSheet(*tex);
    */

    // For now draw a rectangle.
    spr = new  sf::RectangleShape(sf::Vector2f(32,32));
    spr->setPosition(0,0);
    spr->setFillColor(sf::Color::Red);
}
void Player::Update(int dt) {

    x = x + xvel;
    y = y + yvel;

    // Move the player.

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && xvel < 0.2) {
        xvel = xvel + 0.02;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && yvel < 0.2) {
        yvel = yvel + 0.02;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && xvel > -0.2) {
        xvel = xvel - 0.02;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && yvel > -0.2) {
        yvel = yvel - 0.02;
    }

    // Stop actions if keys are released.
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        xvel = 0;
    }

    if ( !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&
    !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        yvel = 0;
    }

    // Update co-ordanates.
    spr->setPosition(x,y);
}
void Player::draw() const {

    win->draw(*spr);

}
