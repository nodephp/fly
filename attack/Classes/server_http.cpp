//
//  server_http.cpp
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#include "server_http.h"
#include "SimpleAudioEngine.h"
#include "config.h"
#include "document.h"
#include "rapidjson.h"


using namespace rapidjson;
Document document;


using namespace cocos2d;
using namespace CocosDenshion;


server_http::server_http()
{
    
}


server_http::~server_http()
{
    curl_global_cleanup();
}



string server_http::init(char *http_url)
{
    if( !CCLayer::init() )
    {
        return 0;
    }
    
    CURL *curl;
    CURLcode res;
    std::string buffer;
    res = curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, http_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, server_http::writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L );
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == 0)
        {
            if(buffer.c_str() != NULL && !document.Parse<0>(buffer.c_str()).HasParseError())
            {
//                CCLog(document["result"].GetString());
                if(document["errno"].GetInt() == 0)
                {
//                    CCLOG("%s", buffer.c_str());
                    return buffer;
                }
            }
            else
            {
                CCLog(document.GetParseError());
            }
        }
    }
    
    return 0;
}




int server_http::read_json_int(string json, int key_num, char *key_1, char *key_2, char *key_3, char *key_4)
{
    if(json.c_str() != NULL && !document.Parse<0>(json.c_str()).HasParseError())
    {
        if(key_num == 1)
        {
            return document["result"][key_1].GetInt();
        }else if(key_num == 2)
        {
            return document["result"][key_1][key_2].GetInt();
        }else if(key_num == 3)
        {
            return document["result"][key_1][key_2][key_3].GetInt();
        }else if(key_num == 4)
        {
            return document["result"][key_1][key_2][key_3][key_4].GetInt();
        }
    }
    else
    {
        CCLog(document.GetParseError());
    }
    return 0;
}



string server_http::read_json_str(string json, int key_num, char *key_1, char *key_2, char *key_3, char *key_4)
{
    if(json.c_str() != NULL && !document.Parse<0>(json.c_str()).HasParseError())
    {
        if(key_num == 1)
        {
            return document["result"][key_1].GetString();
        }else if(key_num == 2)
        {
            return document["result"][key_1][key_2].GetString();
        }else if(key_num == 3)
        {
            return document["result"][key_1][key_2][key_3].GetString();
        }else if(key_num == 4)
        {
            return document["result"][key_1][key_2][key_3][key_4].GetString();
        }
    }
    else
    {
        CCLog(document.GetParseError());
    }
    return 0;
}





size_t server_http::writer(char *data, size_t size, size_t nmemb, std::string *writerData)
{
    size_t retValue = 0;
    if(writerData != NULL)
    {
        writerData->append(data, size * nmemb);
        retValue = size * nmemb;
    }
    return retValue;
}

















