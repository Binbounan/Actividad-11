#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "adminneurona.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixmap("cat.png");
    ui->image->setPixmap(pixmap);

    QString tabStyle = "QTabBar::tab { background-color: #FA7FF4; }"
                       "QTabBar::tab:selected { background-color: #FA7FF4 ; color: green; }";
    ui->tabWidget->setStyleSheet(tabStyle);

    ui->RecuperarN->setStyleSheet("background-color: #9FC131; color: black;");
    ui->btnAgregarInicio->setStyleSheet("background-color: #E62794; color: black;");
    ui->btnAgregarFinal->setStyleSheet("background-color: #E327E6; color: black;");
    ui->btnVerNeuronas->setStyleSheet("background-color: #C7E600; color: black;");
    ui->GuardarN->setStyleSheet("background-color: #BFA7F2; color: black;");
    ui->BotonBuscar->setStyleSheet("background-color: #D3C4F2; color: black;");
    ui->grafica->setStyleSheet("background-color: #EE98FA   ; color: black;");
    ui->clasi->setStyleSheet("background-color: #ED57FA ; color: black;");
    ui->clasV->setStyleSheet("background-color: #ED57FA ; color: black;");
    ui->Mpuntos->setStyleSheet("background-color: #C57FFA ; color: black;");
    ui->Draw->setStyleSheet("background-color: #FAF07F ; color: black;");
    ui->recorP->setStyleSheet("background-color: #FFE3B0; color: black");
    ui->adyacencia->setStyleSheet("background-color: #E327E6; color: black;");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_widget_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_btnAgregarInicio_clicked()
{
    bool ok;

    QString idTexto = ui->campoId->text();
    int id = idTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString voltajeTexto = ui->campoVoltaje->text();
    float voltaje = voltajeTexto.toFloat(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }


    QString posXTexto = ui->campoPosX->text();
    int posX = posXTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString posYTexto = ui->campoPosY->text();
    int posY = posYTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString redTexto = ui->campoRed->text();
    int red = redTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString greenTexto = ui->campoGreen->text();
    int green = greenTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString blueTexto = ui->campoBlue->text();
    int blue = blueTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    administrador.agregarInicio(Neurona(id, voltaje, posX, posY, red, green, blue));
    qDebug() << "Nueva neurona agregada";

    ui->neuronasInfo->setPlainText("Neurona agregada al inicio");
}



void MainWindow::on_btnAgregarFinal_clicked()
{
    bool ok;

    QString idTexto = ui->campoId->text();
    int id = idTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString voltajeTexto = ui->campoVoltaje->text();
    float voltaje = voltajeTexto.toFloat(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }


    QString posXTexto = ui->campoPosX->text();
    int posX = posXTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString posYTexto = ui->campoPosY->text();
    int posY = posYTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString redTexto = ui->campoRed->text();
    int red = redTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString greenTexto = ui->campoGreen->text();
    int green = greenTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    QString blueTexto = ui->campoBlue->text();
    int blue = blueTexto.toInt(&ok);

    if (!ok) {
        qDebug() << "El texto ingresado no es un número entero válido";
        return;
    }

    administrador.agregarFinal(Neurona(id, voltaje, posX, posY, red, green, blue));
    qDebug() << "Nueva neurona agregada";

    ui->neuronasInfo->setPlainText("Neurona agregada al final");
}


void MainWindow::on_btnVerNeuronas_clicked()
{
    QString informacionNeuronas = administrador.obtenerInformacionNeuronas();
    ui->neuronasInfo->setPlainText(informacionNeuronas);
}


void MainWindow::on_GuardarN_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar Neuronas"), "", tr("Archivos de Texto (*.txt)"));
    if (!fileName.isEmpty()) {
        // Llamar al método de la clase AdminNeurona para guardar las neuronas en el archivo
        administrador.guardarNeuronasEnArchivo(fileName);
    }
}


void MainWindow::on_RecuperarN_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Recuperar Neuronas", "", "Archivos de Texto (*.txt);;Todos los Archivos (*.*)");
    if (!filePath.isEmpty()) {
        administrador.recuperarNeuronasDesdeArchivo(filePath);
    }


}


void MainWindow::on_BotonBuscar_clicked()
{

    QString idTexto = ui->aidi1->text();
    int id = idTexto.toInt();


    Neurona neuronaEncontrada = administrador.buscarNeuronaPorId(id);


    if (neuronaEncontrada.getId() != -1) {

        QString informacionNeurona = "ID: " + QString::number(neuronaEncontrada.getId()) +
                                     "\nVoltaje: " + QString::number(neuronaEncontrada.getVoltaje()) +
                                     "\nPosición: (" + QString::number(neuronaEncontrada.getPosX()) + ", " +
                                     QString::number(neuronaEncontrada.getPosY()) + ")" +
                                     "\nRGB: (" + QString::number(neuronaEncontrada.getRed()) + ", " +
                                     QString::number(neuronaEncontrada.getGreen()) + ", " +
                                     QString::number(neuronaEncontrada.getBlue()) + ")";
        ui->aidi->setPlainText(informacionNeurona);
    } else {
        ui->aidi->setPlainText("No se encontró ninguna neurona con el ID especificado.");
    }
}


void MainWindow::on_grafica_clicked()
{


    // Obtener la lista de neuronas desde el administrador
    const QList<Neurona>& neuronas = administrador.getListaNeuronas();

    scene.clear();

    for (const Neurona &N : neuronas) {


        QColor c(N.getRed(), N.getGreen(), N.getBlue());
        QPen pen(c);
        QBrush brush(c, Qt::CrossPattern);

        // Dibujar la neurona como un elipse en la escena
        scene.addEllipse(N.getPosX(), N.getPosY(), N.getVoltaje(), N.getVoltaje(), pen, brush);
    }


    ui->dibujo->setScene(&scene);


}


void MainWindow::on_clasi_clicked()
{
    // Obtiene la lista de neuronas desde el administrador
    QList<Neurona> listaNeuronas = administrador.getListaNeuronas();


    for (int i = 0; i < listaNeuronas.size() - 1; ++i) {
        for (int j = 0; j < listaNeuronas.size() - i - 1; ++j) {                 //metodo burbuja ;D bucle for recorre la lista y compara elementos y hace intrcambio de ser
            //necesario
            if (listaNeuronas[j].getId() > listaNeuronas[j + 1].getId()) {

                std::swap(listaNeuronas[j], listaNeuronas[j + 1]);
            }
        }
    }

    // Muestra las neuronas ordenadas en el QPlainTextEdit o en otro lugar según tu implementación
    QString textoNeuronas;
    for (const Neurona& neurona : listaNeuronas) {
        textoNeuronas += QString("ID: %1, Voltaje: %2\n").arg(neurona.getId()).arg(neurona.getVoltaje());
    }
    ui->neuronasInfo->setPlainText(textoNeuronas);
}


void MainWindow::on_Mpuntos_clicked()
{

    scene.clear();


    const QList<Neurona>& neuronas = administrador.getListaNeuronas();


    for (const Neurona& neurona : neuronas) {
        scene.addEllipse(neurona.getPosX(), neurona.getPosY(), 5, 5, QPen(), QBrush(Qt::black));


        // Mostrar el ID de la neurona como texto
        QGraphicsTextItem *text = scene.addText(QString::number(neurona.getId()));
        text->setPos(neurona.getPosX() + 10, neurona.getPosY() + 10);


    }


    ui->dibujo->setScene(&scene);
}


void MainWindow::on_Draw_clicked()
{
    const QList<Neurona>& neuronas = administrador.getListaNeuronas();


    scene.clear();


    for (int i = 0; i < neuronas.size(); ++i) {
        double distanciaMinima = std::numeric_limits<double>::max();
        QPoint puntoMasCercano;
        for (int j = 0; j < neuronas.size(); ++j) {
            if (i != j) {
                double distancia = std::sqrt(std::pow(neuronas[j].getPosX() - neuronas[i].getPosX(), 2) +
                                             std::pow(neuronas[j].getPosY() - neuronas[i].getPosY(), 2));
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    puntoMasCercano = QPoint(neuronas[j].getPosX(), neuronas[j].getPosY());
                }
            }
        }

        for (const Neurona& neurona : neuronas) {
            scene.addEllipse(neurona.getPosX(), neurona.getPosY(), 5, 5, QPen(), QBrush(Qt::black));


            // Mostrar el ID de la neurona como texto
            QGraphicsTextItem *text = scene.addText(QString::number(neurona.getId()));
            text->setPos(neurona.getPosX() + 10, neurona.getPosY() + 10);


        }

        scene.addLine(neuronas[i].getPosX(), neuronas[i].getPosY(), puntoMasCercano.x(), puntoMasCercano.y(), QPen(Qt::red));
    }


    ui->dibujo->setScene(&scene);

}



void MainWindow::on_clasV_clicked()
{

    QList<Neurona> listaNeuronas = administrador.getListaNeuronas();


    for (int i = 0; i < listaNeuronas.size() - 1; ++i) {
        for (int j = 0; j < listaNeuronas.size() - i - 1; ++j) {                 //metodo burbuja ;D bucle for recorre la lista y compara elementos y hace intrcambio de ser
            //necesario
            if (listaNeuronas[j].getVoltaje() > listaNeuronas[j + 1].getVoltaje()) {

                std::swap(listaNeuronas[j], listaNeuronas[j + 1]);
            }
        }
    }


    QString textoNeuronas;
    for (const Neurona& neurona : listaNeuronas) {
        textoNeuronas += QString("ID: %1, Voltaje: %2\n").arg(neurona.getId()).arg(neurona.getVoltaje());
    }
    ui->neuronasInfo->setPlainText(textoNeuronas);
}




void MainWindow::on_adyacencia_clicked()    //funcion para el boton de la adyacencia
{

    administrador.generarListaDeAdyacencia();


    QMap<int, QList<int>> listaDeAdyacencia = administrador.getListaDeAdyacencia(); //obtenemos lista de adyacencia


    ui->ADYA->clear();


    for (auto it = listaDeAdyacencia.begin(); it != listaDeAdyacencia.end(); ++it) {
        int neuronaId = it.key();
        QList<int> adyacentes = it.value();

        QString info = "Neurona ID: " + QString::number(neuronaId) + " es adyacente a las neuronas con IDs: ";
        for (int adyacente : adyacentes) {
            info += QString::number(adyacente) + ", ";
        }
        info.chop(2); // Eliminar la coma y el espacio extra al final
        info += "\n";

        ui->ADYA->insertPlainText(info);
    }

}


void MainWindow::on_recorP_clicked()
{
    // Obtener el nodo inicial desde la interfaz de usuario
    QString nodoInicialStr = ui->lineEditNodoInicial->text();
    bool ok;
    int nodoInicial = nodoInicialStr.toInt(&ok);

    if (!ok) {

        qDebug() << "El nodo inicial ingresado no es un numero valido";
        return;
    }

    // Realizar la búsqueda en profundidad
    QList<int> resultado = administrador.busquedaEnProfundidad(nodoInicial);


    QString resultadoStr = "Resultado de la busqueda en profundidad:\n";
    for (int nodo : resultado) {
        resultadoStr += QString::number(nodo) + "\n";
    }
    ui->recorr->setPlainText(resultadoStr);
}

