#pragma once

#include "cocos2d.h"
#include "json/rapidjson.h"
#include "json/document.h"

namespace JsonUtils {
    /**
     * @brief ���ļ����ز�����JSON
     * @param filePath �ļ�·��
     * @param doc ���ڽ��ս��������rapidjson::Document����
     * @return bool �Ƿ�ɹ�����
     */
    static bool parseJsonFromFile(const std::string& filePath, rapidjson::Document& doc) {
        if (!cocos2d::FileUtils::getInstance()->isFileExist(filePath)) {
            cocos2d::log("JSON file not found: %s", filePath.c_str());
            return false;
        }
        std::string data = cocos2d::FileUtils::getInstance()->getStringFromFile(filePath);
        doc.Parse(data.c_str());
        if (doc.HasParseError()) {
            cocos2d::log("JSON parse error: %s", doc.GetParseError());
            return false;
        }
        return true;
    }
}
