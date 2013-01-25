//
//  server_http.h
//  attack
//
//  Created by gerry on 13-1-17.
//
//

#ifndef __attack__server_http__
#define __attack__server_http__

#include <iostream>
#include "cocos2d.h"
//#include <curl/curl.h>
#include "curl.h"
#include "HttpClient.h"

using namespace std;



class server_http : public cocos2d::CCLayer
{
public:
    server_http();
    virtual ~server_http();
    virtual string init(char *http_url);
    virtual int read_json_int(string json, int key_num, char *key_1, char *key_2, char *key_3, char *key_4);
    virtual string read_json_str(string json, int key_num, char *key_1, char *key_2, char *key_3, char *key_4);
    
    static size_t writer(char *data, size_t size, size_t nmemb, std::string *writerData);
    
};




#endif /* defined(__attack__server_http__) */
