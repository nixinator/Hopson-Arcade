#pragma once

#include "Invader.h"
#include "../DisplayInfo.h"

#include <vector>

/**
    Class to manage the drawing and updating of invaders
*/
class InvaderManager
{
    public:
        InvaderManager();

        //Moves all of the invaders to the left or right, if the clock has reached a certain time
        void tryStepInvaders();

        //Draws all of the alive invaders
        void drawInvaders(sf::RenderTarget& target);

    private:
        //Checks the invaders position to see if all the aliens should move down
        bool shouldMoveDown(const Invader& invader) const;

        std::vector<Invader> m_invaders;
        sf::Clock m_stepTimer;
        sf::Time m_stepGap;
        sf::RectangleShape m_invaderSprite;
        unsigned m_currFrame = 0;

        bool m_isMovingLeft = false;
        bool m_moveDown = false;
};