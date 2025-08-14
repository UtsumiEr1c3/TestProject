#pragma once

#include "configs/models/LevelConfig.h"
#include "cocos2d.h"

/**
 * @class CardModel
 * @brief 卡牌的数据模型类。
 * @details 存储卡牌的唯一ID、花色、点数、位置、层级和是否可见等运行时状态。
 * 该类不包含任何业务逻辑，仅作为纯粹的数据容器。
 */
class CardModel
{
public:
	/**
	 * @brief CardModel的构造函数
	 * @param id 卡牌的唯一标识符
	 * @param face 卡牌的点数
	 * @param suit 卡牌的花色
	 * @param position 卡牌在场景中的位置
	 */
	CardModel(int id, CardFaceType face, CardSuitType suit, const cocos2d::Vec2& position)
		: _id(id), _face(face), _suit(suit), _position(position), _isFaceUp(false), _localZOrder(0)
	{}

    // --- Getters ---
    /** @brief 获取卡牌ID */
    int getId() const { return _id; }
    /** @brief 获取卡牌点数 */
    CardFaceType getFace() const { return _face; }
    /** @brief 获取卡牌花色 */
    CardSuitType getSuit() const { return _suit; }
    /** @brief 获取卡牌位置 */
    const cocos2d::Vec2& getPosition() const { return _position; }
    /** @brief 获取卡牌是否正面朝上 */
    bool isFaceUp() const { return _isFaceUp; }
    /** @brief 获取卡牌的Z序 */
    int getLocalZOrder() const { return _localZOrder; }

    // --- Setters ---
    /** @brief 设置卡牌位置 */
    void setPosition(const cocos2d::Vec2& pos) { _position = pos; }
    /** @brief 设置卡牌是否正面朝上 */
    void setFaceUp(bool isUp) { _isFaceUp = isUp; }
    /** @brief 设置卡牌的Z序 */
    void setLocalZOrder(int zOrder) { _localZOrder = zOrder; }

private:
    // @brief 卡牌的唯一ID
    int _id;
    // @brief 卡牌点数
    CardFaceType _face;
    // @brief 卡牌花色
    CardSuitType _suit;
    // @brief 卡牌位置
    cocos2d::Vec2 _position;
    // @brief 是否正面朝上
    bool _isFaceUp;
    // @brief 渲染层级
    int _localZOrder;
};

