#pragma once

#include "cocos2d.h"
#include <vector>
#include <string>

// 设计分辨率
static const cocos2d::Size kDesignResolutionSize = cocos2d::Size(1080, 2080);

// 花色类型
enum CardSuitType
{
    CST_NONE = -1,
    CST_CLUBS,      // 梅花
    CST_DIAMONDS,   // 方块
    CST_HEARTS,     // 红桃
    CST_SPADES,     // 黑桃
    CST_NUM_CARD_SUIT_TYPES
};

// 正面类型
enum CardFaceType
{
    CFT_NONE = -1,
    CFT_ACE,
    CFT_TWO,
    CFT_THREE,
    CFT_FOUR,
    CFT_FIVE,
    CFT_SIX,
    CFT_SEVEN,
    CFT_EIGHT,
    CFT_NINE,
    CFT_TEN,
    CFT_JACK,
    CFT_QUEEN,
    CFT_KING,
    CFT_NUM_CARD_FACE_TYPES
};

struct CardConfig
{
    CardFaceType face;
    CardSuitType suit;
    cocos2d::Vec2 position;
};

struct LevelConfig {
    std::vector<CardConfig> playfieldCards;
    std::vector<CardConfig> stackCards;
};
