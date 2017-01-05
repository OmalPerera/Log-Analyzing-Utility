//
//  main.cpp
//  json_parser_xcode
//
//  Created by Omal Perera on 1/4/17.
//  Copyright © 2017 omalperera.com. All rights reserved.
//

#include <iostream>
#include "json.hpp"
#include <fstream>
#include <string>

using nlohmann::json;

int main(int argc, const char * argv[]) {
    
    std::string filePath = "/Users/Omal/Desktop/json_parser_xcode/json_parser_xcode/data.txt";
    
    std::string line;
    std::ifstream jsonfile (filePath);
    
    char c;
    
    //read from file
    if (jsonfile.is_open()) {
        while (! jsonfile.eof()) {
            //getline(jsonfile, line);
            //std::cout << line << std::endl;
            c = '\0';
            jsonfile.get(c);
            
            if(c != '\\')
                line += c;
        }
        jsonfile.close();
    }
    else std::cout << "Unable to open file" << '\n';
    
    
    
    
    // create JSON values
    //json jsonObject = {{"one", 1}, {"two", 2}};
    
    //json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    //auto j3 = json::parse("{\"storedindb\":true,\"outTradeNo\":{\"transactionId\":[{\"transactionId\":\"210010014607\",\"transactionId\":\"0100146022439963\"}]},\"payment\":\"182.00\",\"status\":7,\"remarks\":\"\",\"ecommercePaymentTime\":\"2016-11-23 09:39:43\",\"tmallId\":2341253197662637,\"tmallPaymentDate\":\"2016-11-23 09:39:43\"}");
    //std::string line2 = "{\"happy\":true,\"pi\":3.141}";
    
    //std::cout << line << '\n' << '\n';
    
    //std::ofstream o("/Users/Omal/Desktop/json_parser_xcode/json_parser_xcode/output.json");
    //o << std::setw(4) << line << std::endl;
    
    auto j4 = json::parse(line);
    // print values
    std::cout << j4.dump(4) << std::endl << '\n';
    
    return 0;
}
