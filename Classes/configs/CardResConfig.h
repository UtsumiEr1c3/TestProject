#pragma once

#include "models/LevelConfig.h"
#include <string>
#include <map>

/**
 * @class CardResConfig
 * @brief ������UI��Դ�����á�
 * @details �ṩ��̬���������ݿ��ƵĻ�ɫ�͵�����ȡ��Ӧ��ͼƬ��Դ·����
 * ����һ����״̬�ķ����ࡣ
 */
class CardResConfig
{
public:
    /**
     * @brief ��ȡ���������ͼƬ·��
     * @param face ���Ƶ���
     * @param suit ���ƻ�ɫ
     * @return std::string ��Դ·��
     */
    static std::string getCardFaceSpritePath(CardFaceType face, CardSuitType suit);

    /**
     * @brief ��ȡ���ƻ�ɫ��Сͼ��·��
     * @param suit ���ƻ�ɫ
     * @return std::string ��Դ·��
     */
    static std::string getCardSuitSpritePath(CardSuitType suit);

    /** @brief ��ȡ���Ʊ����ͼƬ·�� */
    static std::string getCardBackSpritePath();

private:
    /**
     * @brief ������ö��ת��Ϊ�ַ���
     * @param face ���Ƶ���
     * @return std::string �����ַ���
     */
    static std::string getFaceString(CardFaceType face);


};

