//
//  LightSource.hpp
//  MinervaEngine
//
//  Created by Anderson on 25/03/22.
//  Copyright © 2022 Anderson Bucchianico. All rights reserved.
//

#pragma once

#include "../World/Entity.hpp"

class LightSource : public Entity {
    
private:
       
public:
    bool isSourceObjectVisible;
    glm::vec3 color;
    
    LightSource();
};
