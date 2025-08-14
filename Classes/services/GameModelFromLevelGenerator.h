#pragma once

#include "models/GameModel.h"
#include "json/document.h"

/**
 * @class GameModelFromLevelGenerator
 * @brief ��Ϸ����ģ������������
 * @details ����һ����״̬�ķ����࣬���𽫽�����Ĺؿ�����JSON���ݣ�
 * ת��Ϊ����ʱ��GameModel���������ƵĴ����ͳ�ʼ���䡣
 */
class GameModelFromLevelGenerator
{
    /**
     * @brief ��JSON��������GameModel
     * @param levelConfigData �������rapidjson::Document����
     * @return GameModel* �´�������Ϸģ��ʵ���������߸����ͷ��ڴ档
     */
    static GameModel* generateGameModel(const rapidjson::Document& levelConfigData);
};

