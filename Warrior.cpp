#include "Warrior.h"

#include <QDebug>

TilePoint Warrior::move()
{
    _gui->addToLogger("Tura Wojownika:", true);
    TilePoint currentPosition = this->getPosition();
    TilePoint direction = this->_player->getDirection();

    currentPosition.x += direction.x;
    currentPosition.y += direction.y;

    return currentPosition;
}

void Warrior::attack(Charakter* enemy)
{
    _gui->addToLogger("Tura Wojownika", true);
    TilePoint enemyPosition = enemy->getPosition();

    bool bonus = false;

    QVector <QVector <Tile>> map = *_map->getMap();
    int attackRoll = _dices->diceRoll("d20");
    int dmg = _dices->diceRoll("d8");
    if(bonus)
    {
        int secondRoll = _dices->diceRoll("d20");
        if(secondRoll > attackRoll)
        {
            attackRoll = secondRoll;
        }
        dmg += _dices->diceRoll("d4");
    }

    enemy->attacked(attackRoll, dmg);
}

bool Warrior::isInMap(TilePoint tile)
{
    if(tile.x >= 0 && tile.x < _map->getWidth())
    {
        if(tile.y >= 0 && tile.y < _map->getHeight())
        {
            return true;
        }
    }
    return false;
}
