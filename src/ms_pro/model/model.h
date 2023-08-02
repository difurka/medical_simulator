#pragma once

#include "circle.h"
#include "rectangle.h"

class  Model
{
private:
    Circle circle_;
    Rectangle rectangle_;

public:
    enum class Type
    {
        kCircle,
        kRectangle
    };

    Model() {}
    ~Model() = default;
};

