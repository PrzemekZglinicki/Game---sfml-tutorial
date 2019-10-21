//
//  player.h
//  InstallingSFML
//
//  Created by Blank Blank on 2015-08-11.
//  Copyright (c) 2015 Blank Blank. All rights reserved.
//

#ifndef __InstallingSFML__player__
#define __InstallingSFML__player__

#include "entity.h"

class player: public entity
{
public:
    int movementSpeed = 2;
    int attackDamage = 5;
    int counterWalking = 0;
    
    player();
    void update();
    void updateMovement();
};

#endif /* defined(__InstallingSFML__player__) */
