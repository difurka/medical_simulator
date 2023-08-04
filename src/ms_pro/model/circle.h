#pragma once

#include "figure.h"

class Circle: public Figure
{
 private:
    double radius_;

 public:
    Circle() {}
    ~Circle() = default;
    
    void SetCircle(double radius)
    {
        radius_ = radius;
    }
    

    void Draw() override { };
    double GetPixelPercent() override { return 0;};
};
