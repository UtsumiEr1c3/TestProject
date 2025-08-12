#pragma once

#include "configs/models/LevelConfig.h"
#include "string"

class LevelConfigLoader
{
    /**
     * @brief �� JSON �ļ��м��� Level configuration
     * @param filePath JSON �ļ�·��.
     * @return ����һ�� LevelConfig ����
     */
	static LevelConfig loadLevelConfig(const std::string& filePath);
};

