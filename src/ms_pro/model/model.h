#pragma once

#include "circle.h"
#include "rectangle.h"
#include "utils/utils.h"
#include <vector>

#include <QDebug>
class  Model
{
    public:
    
    // class Object
    // {
    //     public:
    //     std::vector<std::vector<int>> matrix_;
    // }

 private:
    figure_t fig_;
    std::vector<std::vector<int>> matrix_;

 public:
    Model() {
        matrix_ = std::vector<std::vector<int>>(9, std::vector<int>(9));
//              for (auto el : matrix_) {
// //                 for (auto e : el) {
//                      qDebug() << el;
// //                 }
//              }

            }
    ~Model() {};
    void SetFigureType(int index) {fig_ = static_cast<figure_t>(index);}
    void GenerateCircle(float radius) {radius++;}
    void GenerateRectangle(float width, float height) {width++; ++height;}
    const std::vector<std::vector<int>>& GetMatrix() const {
        for (auto el : matrix_) {
                     qDebug() << el;
             }
//        const auto& res = std::vector<std::vector<int>>(9, std::vector<int>(9));
             return matrix_;}
};



