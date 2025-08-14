#include "GameModel.h"

GameModel::~GameModel() {
    for (auto& pair : _allCards) 
    {
        delete pair.second;
    }
    _allCards.clear();
}

void GameModel::addCard(CardModel* card)
{
    if (card) 
    {
        _allCards[card->getId()] = card;
    }
}

CardModel* GameModel::getCardById(int cardId) const
{
    auto it = _allCards.find(cardId);
    if (it != _allCards.end()) 
    {
        return it->second;
    }
    return nullptr;
}
