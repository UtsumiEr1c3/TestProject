#pragma once

#include "cocos2d.h"
#include "models/CardModel.h"
#include "configs/CardResConfig.h"

/**
 * @class CardView
 * @brief ���Ƶ���ͼ���֡�
 * @details ������Ⱦһ�ſ��Ƶ���ۣ�������棩��������ÿ��ƵĴ����¼���
 * �����ж�ӦCardModel��constָ���Ի�ȡ���ݣ���ͨ���ص���Controllerͨ�š�
 */
class CardView : public cocos2d::Sprite {
public:
    /**
     * @brief ����CardViewʵ���ľ�̬����
     * @param cardModel �����ͼ�����Ŀ�������ģ�� (constָ��)
     * @return CardView* ������ʵ��
     */
    static CardView* create(const CardModel* cardModel);

    /**
     * @brief ��ʼ������
     * @param cardModel �����ͼ�����Ŀ�������ģ��
     * @return bool �Ƿ��ʼ���ɹ�
     */
    bool initWithModel(const CardModel* cardModel);

    /**
     * @brief ���ô����¼��Ļص�����
     * @param callback �����Ʊ����ʱ���õĺ���������Ϊ����ID
     */
    void setTouchCallback(const std::function<void(int)>& callback);

    /**
     * @brief ���¿�����ͼ״̬
     * @details ���ݹ�����CardModel���ݣ����¿��������泯�ϻ��Ǳ��泯�ϡ�
     */
    void updateView();

    /** @brief ��ȡ����ͼ�����Ŀ���ID */
    int getCardId() const { return _cardModel->getId(); }

private:
    /// @brief ָ���������ģ�͵�constָ��
    const CardModel* _cardModel = nullptr;
    /// @brief �����¼��ص�
    std::function<void(int)> _touchCallback;

    /// @brief ��������
    cocos2d::Sprite* _faceSprite = nullptr;
    /// @brief ���Ʊ���
    cocos2d::Sprite* _backSprite = nullptr;
};
