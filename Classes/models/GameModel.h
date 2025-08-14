#pragma once

#include "models/CardModel.h"
#include <vector>
#include <map>

/**
 * @class GameModel
 * @brief ��Ϸ�ĺ�������ģ�͡�
 * @details �������������Ϸ����ʱ�����ж�̬���ݣ����������������ƶѺͱ����ƶ��е�
 * ���п��ơ����ṩ�ӿ������ʺ��޸���Щ���ݣ���������ҵ���߼���
 */
class GameModel
{
    GameModel() = default;
    ~GameModel();

    /**
     * @brief ���һ���Ƶ���Ϸģ����
     * @param card ָ��Ҫ��ӵ�CardModel��ָ�롣GameModel��ӵ��������Ȩ��
     */
    void addCard(CardModel* card);

    /**
     * @brief ����ID��ȡ����ģ��
     * @param cardId ���Ƶ�ΨһID
     * @return CardModel* ָ����ģ�͵�ָ�룬����Ҳ����򷵻�nullptr
     */
    CardModel* getCardById(int cardId) const;

    // --- ���ƶ����ݷ��� ---
    /// @brief ��������������������
    std::vector<int> playfieldCardIds;
    /// @brief �����ƶѣ��ɷ��ƣ�
    std::vector<int> stockCardIds;
    /// @brief ���ƶѣ�����ƥ�䣩
    std::vector<int> trayCardIds;

private:
    /// @brief �洢��Ϸ�����п���ģ�͵�ӳ�䣬��Ϊ����ID
    std::map<int, CardModel*> _allCards;
};

