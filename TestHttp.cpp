//
//  TestHttp.cpp
//  
//
//  Created by Asif Ali on 11/20/17.
//

#include "crow_all.hpp"


//============================================================================
// Name        : HTTP21.cpp
// Author      : AA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/*
 * testserver.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: asifali
 */



#include "crow_all.hpp"

int main()
{
    
    crow::SimpleApp app;
    
    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });
    
    CROW_ROUTE(app,"/hello/<int>")
    ([](int count){
        if (count > 100)
            return crow::response(400);
        std::ostringstream os;
        os << count << " bottles of beer!";
        
        return crow::response(os.str());
    });
    
    CROW_ROUTE(app,"/app/<int>")
    ([](int count){
        std::ostringstream os;

        for (int u=2;u<=30000;u++)
                  {  os << " <h1> this is valid html"; }
                return crow::response(os.str());
              });
    
              
    
    app.port(18080).multithreaded().run();
}


