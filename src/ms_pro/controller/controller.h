#pragma once

#include "../model/model.h"
#include <vector>

class Controller
{
 public:
    explicit Controller(Model* model);
    void GenerateCirc(int radius);
    void GenerateRect(int width, int height);
    void GeneratePix(int radius);
    void SetFigType(int index);
    const std::vector<std::vector<int>>& GetMatr() const;

    void SetPixelRad(int radius_pixel_);
    void SetCircleRad(int radius_);
    void SetRectSize(int width_, int height_);
    void ChangePixSize(int radius);


 private:
    Model* model_;
};
