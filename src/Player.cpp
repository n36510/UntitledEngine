#include "globals.h"
#include <math.h>
Player::Player(physfsManager* manager,sf::RenderWindow *app)
{
    win = app;
    /*
    For when we have actual Sprites.
    */
    sprite = new AnimatedSprite(sf::seconds(0.2),true,true);
    walkUp = new Animation();
    walkDown = new Animation();
    walkLeft = new Animation();
    walkRight = new Animation();

    sf::Texture* spriteSheet = manager->loadPng("sprites/Player.png");
    walkUp->setSpriteSheet(*spriteSheet);
    walkDown->setSpriteSheet(*spriteSheet);
    walkLeft->setSpriteSheet(*spriteSheet);
    walkRight->setSpriteSheet(*spriteSheet);

    walkUp->addFrame(new sf::IntRect(0,0,32,32));
    walkUp->addFrame(new sf::IntRect(32,0,32,32));
    walkUp->addFrame(new sf::IntRect(0,0,32,32));
    walkUp->addFrame(new sf::IntRect(64,0,32,32));

    walkDown->addFrame(new sf::IntRect(0,32,32,32));
    walkDown->addFrame(new sf::IntRect(32,32,32,32));
    walkDown->addFrame(new sf::IntRect(0,32,32,32));
    walkDown->addFrame(new sf::IntRect(64,32,32,32));

    walkLeft->addFrame(new sf::IntRect(0,64,32,32));
    walkLeft->addFrame(new sf::IntRect(32,64,32,32));
    walkLeft->addFrame(new sf::IntRect(0,64,32,32));
    walkLeft->addFrame(new sf::IntRect(64,64,32,32));

    walkRight->addFrame(new sf::IntRect(0,96,32,32));
    walkRight->addFrame(new sf::IntRect(32,96,32,32));
    walkRight->addFrame(new sf::IntRect(0,96,32,32));
    walkRight->addFrame(new sf::IntRect(64,96,32,32));

    currentAnimation = walkDown;
}
void Player::Update(sf::Time dt) {

    // Move the player.

    sf::Vector2f movement(0.f, 0.f);

    bool noKeyWasPressed = true;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        currentAnimation = walkRight;
        movement.x += 80.f;
        noKeyWasPressed = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        currentAnimation = walkDown;
        movement.y += 80.f;
        noKeyWasPressed = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        currentAnimation = walkLeft;
        movement.x -= 80.f;
        noKeyWasPressed = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        currentAnimation = walkUp;
        movement.y -= 80.f;

        noKeyWasPressed = false;
    }

    sprite->play(*currentAnimation);

    sprite->move(movement * dt.asSeconds());

    if (noKeyWasPressed)
        {
            sprite->stop();
        }

    sprite->update(dt);
    // Update co-ordanates.


}
void Player::draw() const {

    win->draw(*sprite);

}
