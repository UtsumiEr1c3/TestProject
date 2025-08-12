#pragma once

#include "configs/models/LevelConfig.h"
#include "string"

class LevelConfigLoader
{
    /**
     * @brief 从 JSON 文件中加载 Level configuration
     * @param filePath JSON 文件路径.
     * @return 返回一个 LevelConfig 对象
     */
	static LevelConfig loadLevelConfig(const std::string& filePath);
};

