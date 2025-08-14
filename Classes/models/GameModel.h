#pragma once

#include "models/CardModel.h"
#include <vector>
#include <map>

/**
 * @class GameModel
 * @brief 游戏的核心数据模型。
 * @details 负责管理整个游戏运行时的所有动态数据，包括主牌区、底牌堆和备用牌堆中的
 * 所有卡牌。它提供接口来访问和修改这些数据，但不包含业务逻辑。
 */
class GameModel
{
    GameModel() = default;
    ~GameModel();

    /**
     * @brief 添加一张牌到游戏模型中
     * @param card 指向要添加的CardModel的指针。GameModel将拥有其所有权。
     */
    void addCard(CardModel* card);

    /**
     * @brief 根据ID获取卡牌模型
     * @param cardId 卡牌的唯一ID
     * @return CardModel* 指向卡牌模型的指针，如果找不到则返回nullptr
     */
    CardModel* getCardById(int cardId) const;

    // --- 各牌堆数据访问 ---
    /// @brief 主牌区（待消除）的牌
    std::vector<int> playfieldCardIds;
    /// @brief 备用牌堆（可翻牌）
    std::vector<int> stockCardIds;
    /// @brief 底牌堆（用于匹配）
    std::vector<int> trayCardIds;

private:
    /// @brief 存储游戏中所有卡牌模型的映射，键为卡牌ID
    std::map<int, CardModel*> _allCards;
};

