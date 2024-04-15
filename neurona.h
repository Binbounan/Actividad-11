#ifndef NEURONA_H
#define NEURONA_H

class Neurona
{
private:
    int id;
    float voltaje;
    int posX;
    int posY;
    int red;
    int green;
    int blue;
public:
    Neurona(int id, float voltaje, int posX, int postY, int red, int green, int blue);
    void print() const;
    int getId() const;
    float getVoltaje() const;
    int getPosX() const;
    int getPosY() const;
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
};

#endif // NEURONA_H
