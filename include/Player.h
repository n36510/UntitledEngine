#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(physfsManager* manager, sf::RenderWindow*);
        virtual void draw() const;
        void Update(sf::Time dt);
    protected:

    private:

    float xvel = 0;
    float yvel = 0;
    float x = 0;
    float y = 0;
    Animation* walkUp;
    Animation* walkDown;
    Animation* walkLeft;
    Animation* walkRight;
    Animation* currentAnimation;
    AnimatedSprite* sprite;
    sf::RenderWindow *win;

    sf::RectangleShape* spr;
};

#endif // PLAYER_H
