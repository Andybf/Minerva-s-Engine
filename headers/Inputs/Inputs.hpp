//
//  Input.hpp
//  Minerva's Engine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

class Inputs {
    
private:
    
public:
    virtual void respondKeyPress(int buttonPressed, int actionPerformed) = 0;
    virtual void respondClickPress(int buttonPressed, int actionPerformed) = 0;
    virtual void respondMovement(double xpos, double ypos) =0;
};
