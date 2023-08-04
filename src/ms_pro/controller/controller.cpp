#include "controller.h"

    Controller::Controller(Model *model) : model_(model) { }

    void Controller::GenerateCirc(float radius) {
        model_->GenerateCircle(radius);
    }
    void Controller::GenerateRect(float width, float height) {
        model_->GenerateRectangle(width, height);
    };

    void Controller::SetFigType(int index) {
        model_->SetFigureType(index);
    }

    const std::vector<std::vector<int>>& Controller::GetMatr() const {
        model_->GetMatrix();
    }
