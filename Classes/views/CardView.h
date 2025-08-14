#pragma once

#include "cocos2d.h"
#include "models/CardModel.h"
#include "configs/CardResConfig.h"

/**
 * @class CardView
 * @brief 卡牌的视图表现。
 * @details 负责渲染一张卡牌的外观（正面或背面），并处理该卡牌的触摸事件。
 * 它持有对应CardModel的const指针以获取数据，并通过回调与Controller通信。
 */
class CardView : public cocos2d::Sprite {
public:
    /**
     * @brief 创建CardView实例的静态方法
     * @param cardModel 与此视图关联的卡牌数据模型 (const指针)
     * @return CardView* 创建的实例
     */
    static CardView* create(const CardModel* cardModel);

    /**
     * @brief 初始化方法
     * @param cardModel 与此视图关联的卡牌数据模型
     * @return bool 是否初始化成功
     */
    bool initWithModel(const CardModel* cardModel);

    /**
     * @brief 设置触摸事件的回调函数
     * @param callback 当卡牌被点击时调用的函数，参数为卡牌ID
     */
    void setTouchCallback(const std::function<void(int)>& callback);

    /**
     * @brief 更新卡牌视图状态
     * @details 根据关联的CardModel数据，更新卡牌是正面朝上还是背面朝上。
     */
    void updateView();

    /** @brief 获取该视图关联的卡牌ID */
    int getCardId() const { return _cardModel->getId(); }

private:
    /// @brief 指向关联数据模型的const指针
    const CardModel* _cardModel = nullptr;
    /// @brief 触摸事件回调
    std::function<void(int)> _touchCallback;

    /// @brief 卡牌正面
    cocos2d::Sprite* _faceSprite = nullptr;
    /// @brief 卡牌背面
    cocos2d::Sprite* _backSprite = nullptr;
};
