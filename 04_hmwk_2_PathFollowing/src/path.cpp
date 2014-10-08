//
//  path.cpp
//  04_hmwk_2_PathFollowing
//
//  Created by Regina Flores on 9/23/14.
//
//

#include "path.h"

void Path:: dispay(){

    strokeWeight(radius*2);
    stroke(0,100);
    line(start.x,start.y,end.x,end.y);
    strokeWeight(1);
    stroke(0);
    line(start.x,start.y,end.x,end.y);
    

}
