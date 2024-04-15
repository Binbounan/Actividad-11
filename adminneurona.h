#ifndef ADMINNEURONA_H
#define ADMINNEURONA_H
#include <Qlist>
#include "neurona.h"



class AdminNeurona
{
private:
    QList<Neurona> listaNeuronas;
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

};

#endif // ADMINNEURONA_H
