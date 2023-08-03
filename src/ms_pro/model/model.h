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


// * определим матрицу 300х300, когда рисуем частицу с центром и радиусом,
// * ставим значение unum::pixel (=2),
// * заранее отмечаем enum::back (=1) для окружности или прямоугольника
// * (обновляя каждый раз при изменении размера)
// * после считаем отношение (pixel/ (pixel+back))*100 = actual_percent

