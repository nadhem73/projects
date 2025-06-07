#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "oeuvre.h"

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
    void on_pb_acceuil_4_clicked();

    void on_boutton_artiste_clicked();

    void on_boutton_oeuvre_clicked();

    void on_boutton_evenement_clicked();

    void on_boutton_vente_clicked();

    void on_boutton_invite_clicked();

    void on_boutton_parametre_clicked();

    void on_boutton_deconnecte_clicked();

    void on_boutton_ajout_clicked();

    void on_boutton_modifier_clicked();

    void on_boutton_supp_clicked();

    void on_boutton_pdf_clicked();

    void on_boutton_recherche_clicked();

    void on_boutton_statistique_clicked();


    void on_comboBox_activated(const QString &arg1);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    oeuvre otmp;
};
#endif // MAINWINDOW_H
