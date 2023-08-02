#pragma once

#include "../model/model.h"

class Controller
{
 public:
    Controller();
    void Generate();
 private:
    Model* model_;
};
