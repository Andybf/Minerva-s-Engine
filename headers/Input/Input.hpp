//
//  Input.hpp
//  Minerva's Engine
//
//  Created by Anderson on 18/02/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

class Input {
    
private:
    
public:
    virtual void respondInputPress(int buttonPressed, int actionPerformed) = 0;
};
