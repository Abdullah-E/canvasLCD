#include "Canvas.h"

Canvas::Canvas(){
    for(int i = 0; i < blocks_height; i++){
        for(int j = 0; j < blocks_width; j++){
            canvas_chars[j][i] = new byte[8];
            for(int k = 0 ; k < 8; k++){
                canvas_chars[j][i][k] = 0;
            }
        }
    }
}

Canvas::~Canvas(){
    for(int i = 0; i < blocks_height; i++){
        for(int j = 0; j < blocks_width; j++){
            delete[] canvas_chars[j][i];
        }
    }
}

byte* Canvas::getBlock(int x, int y){

}

void Canvas::drawPixel(int x, int y){

}