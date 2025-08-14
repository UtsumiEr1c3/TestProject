#pragma once

#include "models/LevelConfig.h"
#include <string>
#include <map>

/**
 * @class CardResConfig
 * @brief 管理卡牌UI资源的配置。
 * @details 提供静态方法，根据卡牌的花色和点数获取对应的图片资源路径。
 * 这是一个无状态的服务类。
 */
class CardResConfig
{
public:
    /**
     * @brief 获取卡牌正面的图片路径
     * @param face 卡牌点数
     * @param suit 卡牌花色
     * @return std::string 资源路径
     */
    static std::string getCardFaceSpritePath(CardFaceType face, CardSuitType suit);

    /**
     * @brief 获取卡牌花色的小图标路径
     * @param suit 卡牌花色
     * @return std::string 资源路径
     */
    static std::string getCardSuitSpritePath(CardSuitType suit);

    /** @brief 获取卡牌背面的图片路径 */
    static std::string getCardBackSpritePath();

private:
    /**
     * @brief 将点数枚举转换为字符串
     * @param face 卡牌点数
     * @return std::string 点数字符串
     */
    static std::string getFaceString(CardFaceType face);


};

