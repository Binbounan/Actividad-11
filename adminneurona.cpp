#include "adminneurona.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>

void AdminNeurona::agregarInicio(const Neurona &neurona) {
    listaNeuronas.prepend(neurona);
}

void AdminNeurona::agregarFinal(const Neurona &neurona) {
    listaNeuronas.append(neurona);
}
void AdminNeurona::mostrar( ){
    for (const Neurona &neurona : listaNeuronas) {
        neurona.print();
    }
}


QString AdminNeurona::obtenerInformacionNeuronas() const {
    QString informacion;
    for (const Neurona neurona : listaNeuronas) {
        informacion += "ID: " + QString::number(neurona.getId()) + ", Voltaje: " + QString::number(neurona.getVoltaje(), 'f', 2) + ", Posicion: (" + QString::number(neurona.getPosX()) + ", " + QString::number(neurona.getPosY()) + "), RGB: (" + QString::number(neurona.getRed()) + ", " + QString::number(neurona.getGreen()) + " , " + QString::number(neurona.getBlue()) + ") \n\n";
    }
    return informacion;
}

void AdminNeurona::guardarNeuronasEnArchivo(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo para escribir:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    for (const Neurona &neurona : listaNeuronas) {
        out << neurona.getId() << ":" << neurona.getVoltaje() << ":"
            << neurona.getPosX() << ":" << neurona.getPosY() << ":"
            << neurona.getRed() << ":" << neurona.getGreen() << ":"
            << neurona.getBlue() << "\n";
    }

    file.close();
}

Neurona AdminNeurona::buscarNeuronaPorId(int id) const {
    for (const Neurona &neurona : listaNeuronas) {
        if (neurona.getId() == id) {

            return neurona;
        }
    }
    return Neurona(0, 0.0, 0, 0, 0, 0, 0);
}


void AdminNeurona::recuperarNeuronasDesdeArchivo(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo para leer:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList tokens = linea.split(":");

        if (tokens.size() == 7) {
            int id = tokens[0].toInt();
            float voltaje = tokens[1].toFloat();
            int posX = tokens[2].toInt();
            int posY = tokens[3].toInt();
            int red = tokens[4].toInt();
            int green = tokens[5].toInt();
            int blue = tokens[6].toInt();


            Neurona neurona(id, voltaje, posX, posY, red, green, blue);


            listaNeuronas.append(neurona);
        }
    }

    file.close();
}


