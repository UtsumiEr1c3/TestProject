#pragma once

#include "configs/models/LevelConfig.h"
#include "cocos2d.h"

/**
 * @class CardModel
 * @brief ���Ƶ�����ģ���ࡣ
 * @details �洢���Ƶ�ΨһID����ɫ��������λ�á��㼶���Ƿ�ɼ�������ʱ״̬��
 * ���಻�����κ�ҵ���߼�������Ϊ���������������
 */
class CardModel
{
public:
	/**
	 * @brief CardModel�Ĺ��캯��
	 * @param id ���Ƶ�Ψһ��ʶ��
	 * @param face ���Ƶĵ���
	 * @param suit ���ƵĻ�ɫ
	 * @param position �����ڳ����е�λ��
	 */
	CardModel(int id, CardFaceType face, CardSuitType suit, const cocos2d::Vec2& position)
		: _id(id), _face(face), _suit(suit), _position(position), _isFaceUp(false), _localZOrder(0)
	{}

    // --- Getters ---
    /** @brief ��ȡ����ID */
    int getId() const { return _id; }
    /** @brief ��ȡ���Ƶ��� */
    CardFaceType getFace() const { return _face; }
    /** @brief ��ȡ���ƻ�ɫ */
    CardSuitType getSuit() const { return _suit; }
    /** @brief ��ȡ����λ�� */
    const cocos2d::Vec2& getPosition() const { return _position; }
    /** @brief ��ȡ�����Ƿ����泯�� */
    bool isFaceUp() const { return _isFaceUp; }
    /** @brief ��ȡ���Ƶ�Z�� */
    int getLocalZOrder() const { return _localZOrder; }

    // --- Setters ---
    /** @brief ���ÿ���λ�� */
    void setPosition(const cocos2d::Vec2& pos) { _position = pos; }
    /** @brief ���ÿ����Ƿ����泯�� */
    void setFaceUp(bool isUp) { _isFaceUp = isUp; }
    /** @brief ���ÿ��Ƶ�Z�� */
    void setLocalZOrder(int zOrder) { _localZOrder = zOrder; }

private:
    // @brief ���Ƶ�ΨһID
    int _id;
    // @brief ���Ƶ���
    CardFaceType _face;
    // @brief ���ƻ�ɫ
    CardSuitType _suit;
    // @brief ����λ��
    cocos2d::Vec2 _position;
    // @brief �Ƿ����泯��
    bool _isFaceUp;
    // @brief ��Ⱦ�㼶
    int _localZOrder;
};

