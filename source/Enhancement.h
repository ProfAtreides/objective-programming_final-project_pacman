//
// Created by paro on 7/11/23.
//

#ifndef PROGRAM_ENHANCEMENT_H
#include <SFML/Graphics.hpp>
#define PROGRAM_ENHANCEMENT_H

using namespace sf;

class Enhancement {
public:
    Enhancement(std::string filePath);
    void pickedUp();
    bool active();
    void decreaseExpiration();
private:
    static Texture sTexture;
    int mFramesTillExpired;
};


#endif //PROGRAM_ENHANCEMENT_H
