#include "controller.h"

    Controller::Controller(Model *model) : model_(model) { }

    void Controller::GenerateCirc(int radius) {
        model_->GenerateCircle(radius);
    }
    
    void Controller::GenerateRect(int width, int height) {
        model_->GenerateRectangle(width, height);
    }

    void Controller::GeneratePix(int radius) {
        model_->GeneratePixel(radius);
    }

    void Controller::SetFigType(int index) {
        model_->SetFigureType(index);
    }

    const std::vector<std::vector<int>>& Controller::GetMatr() const {
        return model_->GetMatrix();
    }

    void Controller::SetPixelRad(int radius_pixel) {
        model_->SetPixelRadius(radius_pixel);
    }
    void Controller::SetCircleRad(int radius) {
        model_->SetCircleRadius(radius);
    }

    void Controller::SetRectSize(int width, int height) {
        model_->SetRectangleSize(width, height);
    }

    void Controller::ChangePixSize(int radius) {
        model_->ChangeSizePixel(radius);
    }
