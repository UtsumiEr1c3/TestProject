#pragma once

#include "models/GameModel.h"
#include "json/document.h"

/**
 * @class GameModelFromLevelGenerator
 * @brief 游戏数据模型生成器服务。
 * @details 这是一个无状态的服务类，负责将解析后的关卡配置JSON数据，
 * 转换为运行时的GameModel。它处理卡牌的创建和初始分配。
 */
class GameModelFromLevelGenerator
{
    /**
     * @brief 从JSON配置生成GameModel
     * @param levelConfigData 解析后的rapidjson::Document对象
     * @return GameModel* 新创建的游戏模型实例。调用者负责释放内存。
     */
    static GameModel* generateGameModel(const rapidjson::Document& levelConfigData);
};

