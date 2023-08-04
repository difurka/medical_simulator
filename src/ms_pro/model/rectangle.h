#pragma once

#include "figure.h"

class Rectangle : public Figure
{
 private:
    double height_;
    double width_;
 public:
    Rectangle() {}
    ~Rectangle() = default;
    void SetRectangle(double height, double width) 
    {
        height_ = height;
        width_= width;
    }

    void Draw() override {};
    double GetPixelPercent() override {return 0;};
};
