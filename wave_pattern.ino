#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

const int lcdAddress = 0x27;

const int lcdColumns = 16;
const int lcdRows = 2;
LiquidCrystal_PCF8574 lcd(lcdAddress);

void drawPixel(int x, int y){
    
}

void drawPixel(byte byteArr[], int x, int y){
    byteArr[y] |= 1 << x;
}

void clearPixel(byte byteArr[], int x, int y){
    byteArr[y] &= ~(1 << x);
}

void clearAll(byte byteArr[]){
    for(int i = 0; i < 8; i++){
        byteArr[i] = 0;
    }
}

void line(byte byteArr[], int x1, int y1, int x2, int y2){
    // Serial.println(y1);
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while(true){
        drawPixel(byteArr, x1, y1);
        if(x1 == x2 && y1 == y2){
            break;
        }
        int e2 = 2 * err;
        if(e2 > -dy){
            err -= dy;
            x1 += sx;
        }
        if(e2 < dx){
            err += dx;
            y1 += sy;
        }
    }
}

void square(byte byteArr[], int x, int y, int size){
    line(byteArr, x, y, x + size, y);
    line(byteArr, x + size, y, x + size, y + size);
    line(byteArr, x + size, y + size, x, y + size);
    line(byteArr, x, y + size, x, y);
}

byte tileOne[] = {0,0,0,0,0,0,0,0};
byte tileTwo[] = {0,0,0,0,0,0,0,0};

void setup(){
    Serial.begin(115200);
    Serial.println("Starting...");

    lcd.begin(lcdColumns, lcdRows);
    lcd.setBacklight(1);

    square(tileOne, 0, 0, 4);
    lcd.createChar(0, tileOne);
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
}

void loop(){

}