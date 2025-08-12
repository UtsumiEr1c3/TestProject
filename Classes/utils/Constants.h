#pragma once

#include "cocos2d.h"

namespace Constants {
    // Z-order values
    const int kZOrderPlayfield = 10;
    const int kZOrderStack = 20;
    const int kZOrderMovingCard = 100;

    // Animation duration
    const float kCardMoveDuration = 0.2f;

    // Card dimensions
    const float kCardWidth = 150.0f;
    const float kCardHeight = 220.0f;

    // 区域尺寸 (Area Dimensions)

    const cocos2d::Size kPlayfieldSize = cocos2d::Size(1080, 1500);

    const cocos2d::Size kStackAreaSize = cocos2d::Size(1080, 580);


    // 示例：这些尺寸可以用来定位区域

    // 假设堆牌区在底部

    const cocos2d::Vec2 kStackAreaPosition = cocos2d::Vec2(0, 0);

    // 假设主牌区在堆牌区上方

    const cocos2d::Vec2 kPlayfieldPosition = cocos2d::Vec2(0, kStackAreaSize.height);
}