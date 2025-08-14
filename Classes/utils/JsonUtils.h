#pragma once

#include "cocos2d.h"
#include "json/rapidjson.h"
#include "json/document.h"

namespace JsonUtils {
    /**
     * @brief 从文件加载并解析JSON
     * @param filePath 文件路径
     * @param doc 用于接收解析结果的rapidjson::Document对象
     * @return bool 是否成功解析
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
