#pragma once

#include "../model/model.h"
#include <vector>

class Controller
{
 public:
    explicit Controller(Model* model);
    void GenerateCirc(float radius);
    void GenerateRect(float width, float height);
    void SetFigType(int index);
    const std::vector<std::vector<int>>& GetMatr() const;

 private:
    Model* model_;
};
