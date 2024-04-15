#include "neurona.h"
#include <iostream>

Neurona::Neurona(int id, float voltaje, int posX, int posY, int red, int green, int blue)
    : id(id), voltaje(voltaje), posX(posX), posY(posY), red(red), green(green), blue(blue) {}


void Neurona::print() const {
    std::cout << "ID: " << id << "\n";
    std::cout << "Voltaje: " << voltaje << "\n";
    std::cout << "Posicion: (" << posX << ", " << posY << ")\n";
    std::cout << "Color: " << "(" << red << ", " << green << ", " << blue << ")\n";
    std::cout << "----------------------------------------\n";
}

int Neurona::getId() const { return id; }
float Neurona::getVoltaje() const { return voltaje; }
int Neurona::getPosX() const { return posX; }
int Neurona::getPosY() const { return posY; }
int Neurona::getRed() const { return red; }
int Neurona::getGreen() const { return green; }
int Neurona::getBlue() const { return blue; }
