//
// Created by paro on 7/11/23.
//

#include "Enhancement.h"

Enhancement::Enhancement(std::string filePath) {
    if(sTexture.getSize() == Vector2u(0,0)) sTexture.loadFromFile(filePath);
}

void Enhancement::pickedUp() {
    mFramesTillExpired = 5;
}

void Enhancement::decreaseExpiration() {
    mFramesTillExpired--;
}