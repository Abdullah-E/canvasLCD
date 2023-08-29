#ifndef Canvas_h
#define Canvas_h

class Canvas
{
private:
    
    const int blocks_width = 16;
    const int blocks_height = 2;

    const int block_width = 5;
    const int block_height = 8;

    const int canvas_width = blocks_width * block_width;
    const int canvas_height = blocks_height * block_height;
    byte* canvas_chars[16][2];
    

public:
    Canvas();
    ~Canvas();
    
    void drawPixel(int x, int y);
    byte* getBlock(int x, int y);
};

#endif
