#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsTextItem>
#include <QMainWindow>
#include "adminneurona.h"
#include <QPlainTextEdit>
#include <QGraphicsScene>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_btnAgregarInicio_clicked();

    void on_btnAgregarFinal_clicked();

    void on_btnVerNeuronas_clicked();

    void on_GuardarN_clicked();

    void on_RecuperarN_clicked();

    void on_BotonBuscar_clicked();

    void on_grafica_clicked();

    void on_clasi_clicked();

    void on_Mpuntos_clicked();

    void on_Draw_clicked();

    void on_clasV_clicked();

    void on_adyacencia_clicked();

    void on_recorP_clicked();

private:
    Ui::MainWindow *ui;
    AdminNeurona administrador;
    QPlainTextEdit *neuronasTextEdit;
    QGraphicsScene scene;



};
#endif // MAINWINDOW_H
