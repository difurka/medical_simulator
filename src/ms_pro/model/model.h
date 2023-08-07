#pragma once

#include "circle.h"
#include "rectangle.h"
#include "utils/utils.h"
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <cmath>

#include <QDebug>


class  Model
{
 private:
    figure_t fig_ {figure_t::CIRCLE};
    std::vector<std::vector<int>> matrix_;
    int pixel_number_;
    std::vector<std::tuple<int, int>> pixels_;
    int height_{1};
    int width_{1};
    int radius_{1};
    int pixel_radius_{1};

 public:
    Model() {
        matrix_ = std::vector<std::vector<int>>(kMaxSize, std::vector<int>(kMaxSize));
    }

    ~Model() {};
    void SetFigureType(int index) {fig_ = static_cast<figure_t>(index);}
    void GenerateCircle(int radius) {
        matrix_ = std::vector<std::vector<int>>(kMaxSize, std::vector<int>(kMaxSize));
        radius_ = radius;
        int i_center = kMaxSize / 2;
        int j_center = kMaxSize / 2;

        for (int i = 0; i < kMaxSize; ++i) {
            for (int j = 0; j < kMaxSize; ++j) {
                if ((i-i_center)*(i-i_center) + (j-j_center)*(j-j_center) < radius_*radius_) {
                    matrix_[i][j] = 1;
                }
            }
        }

    }
    void GenerateRectangle(int width, int height) {
        matrix_ = std::vector<std::vector<int>>(kMaxSize, std::vector<int>(kMaxSize));
        width_ = width;
        height_ = height;

        int i_center = kMaxSize / 2;
        int j_center = kMaxSize / 2;

        for (int i = 0; i < kMaxSize; ++i) {
            for (int j = 0; j < kMaxSize; ++j) {
                if (std::abs(i-i_center) < width_/2 && std::abs(j-j_center) < height_/2) {
                    matrix_[i][j] = 1;
                }
            }
        }
    }

    const std::vector<std::vector<int>>& GetMatrix() const { return matrix_;}

    void GeneratePixel(int radius) {
        pixels_.clear();
        srand((unsigned) time(NULL));

            if (fig_ == figure_t::CIRCLE) {
                auto rate = (int)(radius_*radius_/(pixel_radius_*pixel_radius_));
                if (rate > 1) {
                    pixel_number_ = rand() % rate;
                } else {
                    pixel_number_ = 0;
                }


            } else {
                auto rate = (int)(width_*height_/(4*pixel_radius_*pixel_radius_));
                if (rate > 1) {
                    pixel_number_ = rand() % (width_*height_/(3*pixel_radius_*pixel_radius_));
                } else {
                    pixel_number_ = 0;
                }

            }


        for (int n = 0; n < pixel_number_; ++n) {
            int random_x, random_y;
            if (fig_ == figure_t::CIRCLE) {
                random_x = kMaxSize/2 - radius_ +(rand() % (2*radius_ + 1));
//                int limit_y = kMaxSize/2 - sqrt(radius_*radius_ - (random_x- kMaxSize/2)*(random_x- kMaxSize/2));
//                random_y = limit_y + (rand() % (2*(radius_ - limit_y )+ 1));
                random_y = kMaxSize/2 - radius_ +(rand() % (2*radius_ + 1));
            } else {
                random_x = kMaxSize/2 - width_/2 +(rand() % (width_ + 1));
                random_y = kMaxSize/2 - height_/2 +(rand() % (height_ + 1));
            }

            pixels_.push_back({random_x, random_y});
            for (int i = 0; i < kMaxSize; ++i) {
                for (int j = 0; j < kMaxSize; ++j) {
                    if ((i-random_x)*(i-random_x) + (j-random_y)*(j-random_y) < radius*radius
                            && matrix_[i][j] == 1
                            ) {
                        matrix_[i][j] = 2;
                    }
                }
            }
        }

    }

    void ChangeSizePixel(int radius) {
        for (auto el : pixels_) {
            for (int i = 0; i < kMaxSize; ++i) {
                for (int j = 0; j < kMaxSize; ++j) {
                    if ((i-std::get<0>(el))*(i-std::get<0>(el)) + (j-std::get<1>(el))*(j-std::get<1>(el)) < radius*radius
                            && matrix_[i][j] == 1
                            ) {
                        matrix_[i][j] = 2;
                    }

                }
            }
        }
    }


    void SetPixelRadius(int pixel_radius)
    {
        pixel_radius_ = pixel_radius;
    }

    void SetCircleRadius(int radius) {
        radius_ = radius;
    }

    void SetRectangleSize(int width, int height) {
        width_ = width;
        height_ = height;
    }

    float GetPercents() {
        int all_number = 0;
        int pixel_number = 0;
        for (int i = 0; i < kMaxSize; ++i) {
            for (int j = 0; j < kMaxSize; ++j) {
                if (matrix_[i][j] >0) {
                    ++all_number;
                    if (matrix_[i][j] == 2) {
                        ++pixel_number;
                    }
                }
            }
        }
        auto answer = static_cast<float>(pixel_number) / all_number * 100;
        return std::round(answer);
    }

};
