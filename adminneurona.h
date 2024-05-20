#ifndef ADMINNEURONA_H
#define ADMINNEURONA_H
#include <Qlist>
#include "neurona.h"
#include <QMap>  //clase contenedor que usé para la adyacencia


class AdminNeurona
{
private:
    QList<Neurona> listaNeuronas;
    QMap<int, QList<int>> listaDeAdyacencia;

public:
    void agregarInicio(const Neurona &neurona);
    void agregarFinal(const Neurona &neurona);
    void mostrar();
    QString obtenerInformacionNeuronas() const;
    void guardarNeuronasEnArchivo(const QString &filePath);
    void recuperarNeuronasDesdeArchivo(const QString &filePath);
    Neurona buscarNeuronaPorId(int id) const;
    const QList<Neurona>& getListaNeuronas() const {
        return listaNeuronas;
    }
    void generarListaDeAdyacencia();
    QMap<int, QList<int>> getListaDeAdyacencia() const;
     QList<int> busquedaEnProfundidad(int nodoInicial) const;
};

#endif // ADMINNEURONA_H
