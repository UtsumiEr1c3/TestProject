#include "CardResConfig.h"

std::string CardResConfig::getCardFaceSpritePath(CardFaceType face, CardSuitType suit)
{
	std::string color = (suit == CardSuitType::CST_DIAMONDS || suit == CardSuitType::CST_HEARTS) ? "red" : "black";
	return "number/big_" + color + "_" + getFaceString(face) + ".png";
}

std::string CardResConfig::getCardSuitSpritePath(CardSuitType suit)
{
    switch (suit) {
    case CardSuitType::CST_CLUBS: return "suits/club.png";
    case CardSuitType::CST_DIAMONDS: return "suits/diamond.png";
    case CardSuitType::CST_HEARTS: return "suits/heart.png";
    case CardSuitType::CST_SPADES: return "suits/spade.png";
    default: return "";
    }
}

std::string CardResConfig::getCardBackSpritePath()
{
    return "card_general.png";
}

std::string CardResConfig::getFaceString(CardFaceType face)
{
    const static std::map<CardFaceType, std::string> faceMap = {
            {CardFaceType::CFT_ACE, "A"}, {CardFaceType::CFT_TWO, "2"}, {CardFaceType::CFT_THREE, "3"},
            {CardFaceType::CFT_FOUR, "4"}, {CardFaceType::CFT_FIVE, "5"}, {CardFaceType::CFT_SIX, "6"},
            {CardFaceType::CFT_SEVEN, "7"}, {CardFaceType::CFT_EIGHT, "8"}, {CardFaceType::CFT_NINE, "9"},
            {CardFaceType::CFT_TEN, "10"}, {CardFaceType::CFT_JACK, "J"}, {CardFaceType::CFT_QUEEN, "Q"},
            {CardFaceType::CFT_KING, "K"}
    };
    auto it = faceMap.find(face);
    return it != faceMap.end() ? it->second : "";
}

