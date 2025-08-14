#include "CardView.h"

CardView* CardView::create(const CardModel* cardModel) {
    CardView* pRet = new CardView();
    if (pRet && pRet->initWithModel(cardModel)) {
        pRet->autorelease();
        return pRet;
    }
    else {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool CardView::initWithModel(const CardModel* cardModel) {
    if (!Sprite::init()) {
        return false;
    }

    _cardModel = cardModel;

    // 创建卡牌背面 
    _backSprite = Sprite::create(CardResConfig::getCardBackSpritePath());
    _backSprite->setAnchorPoint(cocos2d::Vec2::ZERO);
    this->addChild(_backSprite);
    this->setContentSize(_backSprite->getContentSize());

    // 创建卡牌正面
    _faceSprite = Sprite::create();
    _faceSprite->setAnchorPoint(cocos2d::Vec2::ZERO);
    this->addChild(_faceSprite);

    auto faceImage = Sprite::create(CardResConfig::getCardFaceSpritePath(cardModel->getFace(), cardModel->getSuit()));
    faceImage->setPosition(_backSprite->getContentSize() / 2);
    _faceSprite->addChild(faceImage);

    auto suitImage = Sprite::create(CardResConfig::getCardSuitSpritePath(cardModel->getSuit()));
    suitImage->setPosition(cocos2d::Vec2(30, _backSprite->getContentSize().height - 30));
    _faceSprite->addChild(suitImage);

    // 添加监听
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        if (this->getBoundingBox().containsPoint(this->getParent()->convertTouchToNodeSpace(touch))) {
            // 只有正面朝上的牌才能被点击
            if (_cardModel && _cardModel->isFaceUp()) {
                return true;
            }
        }
        return false;
        };
    listener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        if (_touchCallback) {
            _touchCallback(_cardModel->getId());
        }
        };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    updateView();
    return true;
}

void CardView::setTouchCallback(const std::function<void(int)>& callback) {
    _touchCallback = callback;
}

void CardView::updateView() {
    if (!_cardModel) return;
    this->setPosition(_cardModel->getPosition());
    this->setLocalZOrder(_cardModel->getLocalZOrder());
    _faceSprite->setVisible(_cardModel->isFaceUp());
    _backSprite->setVisible(true); 
}