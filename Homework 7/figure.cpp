//
//  figure.cpp
//  1
//
//  Created by Vincent Yu on 3/6/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//

#include "figure.h"
#include <iostream>

void Figure::draw(){
    std::cout<< "Figure::draw() called." <<std::endl;
}

void Figure::erase(){
    std::cout<< "Figure::erase() called" <<std::endl;
}

void Figure::center(){
    std::cout<< "Figure::center() called." <<std::endl;
    erase();
    draw();
}
