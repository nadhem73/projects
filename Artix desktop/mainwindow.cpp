#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QDate>
#include <QComboBox>
#include "oeuvre.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(otmp.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pb_acceuil_4_clicked()
{

}

void MainWindow::on_boutton_artiste_clicked()
{

}

void MainWindow::on_boutton_oeuvre_clicked()
{

}

void MainWindow::on_boutton_evenement_clicked()
{

}

void MainWindow::on_boutton_vente_clicked()
{

}

void MainWindow::on_boutton_invite_clicked()
{

}

void MainWindow::on_boutton_parametre_clicked()
{

}

void MainWindow::on_boutton_deconnecte_clicked()
{

}

void MainWindow::on_boutton_ajout_clicked()
{
    QString titre = ui->line_titre_ajout->text();
    if (titre.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Title cannot be empty."),
                              QMessageBox::Cancel);
        return;
    }

    QDate date_de_creation = ui->date_date_de_creation_ajout->date();

    QString dimension = ui->line_dimension_ajout->text();

    QString description = ui->line_description_ajout->text();

    QString status = ui->comboBox_status->currentText();

    QString prix = ui->line_prix_ajout->text();
    if (prix.isEmpty() || prix.toDouble() <= 0.0) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Invalid price. Please enter a valid positive number."),
                              QMessageBox::Cancel);
        return;
    }

    QString style = ui->line_style_ajout->text();

    QString reference = ui->line_reference_ajout->text();
    int id;

    // If all input is valid, proceed with adding the record
    oeuvre o(id,titre, date_de_creation, dimension, description, status, prix, style, reference);

    bool test = o.ajouter();
    if (test) {
        ui->tableView->setModel(otmp.afficher());


        ui->line_titre_ajout->clear();
        ui->date_date_de_creation_ajout->clear();
        ui->line_dimension_ajout->clear();
        ui->line_description_ajout->clear();
        ui->line_prix_ajout->clear();
        ui->line_style_ajout->clear();
        ui->line_reference_ajout->clear();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Addition not successful. Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
}


void MainWindow::on_boutton_modifier_clicked()
{
    // Récupérer l'ID de l'élément sélectionné dans le QTableView
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, tr("Aucune sélection"), tr("Veuillez sélectionner une ligne à modifier."));
        return;
    }
    int id = selectedRows.at(0).data().toInt();

    QString titre = ui->line_titre_ajout->text();
    QDate date_de_creation = ui->date_date_de_creation_ajout->date();
    QString dimension = ui->line_dimension_ajout->text();
    QString description = ui->line_description_ajout->text();
    QString status = ui->comboBox_status->currentText();
    QString prix = ui->line_prix_ajout->text();
    QString style = ui->line_style_ajout->text();
    QString reference = ui->line_reference_ajout->text();

    // Modifiez l'objet oeuvre avec les nouvelles valeurs
    oeuvre o(id, titre, date_de_creation, dimension, description, status, prix, style, reference);

    bool test = o.modifier(id);
    if(test)
    {
        ui->tableView->setModel(otmp.afficher());

        // Effacer les champs après la modification réussie
        ui->line_titre_ajout->clear();
        ui->date_date_de_creation_ajout->clear();
        ui->line_dimension_ajout->clear();
        ui->line_description_ajout->clear();
        ui->line_prix_ajout->clear();
        ui->line_style_ajout->clear();
        ui->line_reference_ajout->clear();
    }
    else {
        QMessageBox::critical(this, tr("Erreur"), tr("Modification non effectuée.\nCliquez sur Annuler pour quitter."));
    }
}

void MainWindow::on_boutton_supp_clicked()
{
    int id =ui->line_id_supp->text().toInt();
    bool test=otmp.supprimer(id);
    if(test){
        ui->tableView->setModel(otmp.afficher());
        ui->line_id_supp->clear();
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression non effectue\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_boutton_pdf_clicked()
{

}

void MainWindow::on_boutton_recherche_clicked()
{

}

void MainWindow::on_boutton_statistique_clicked()
{

}



void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

    // Récupérez l'index de la ligne sélectionnée
    if(index.isValid())
    {
        int row = index.row();
        // Obtenez les données de la ligne sélectionnée
        QVariant idVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 0));
        QVariant titreVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 1));
        QVariant dateVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 2));
        QVariant dimensionVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 3));
        QVariant descriptionVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 4));
        QVariant statusVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 5));
        QVariant prixVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 6));
        QVariant styleVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 7));
        QVariant referenceVariant = ui->tableView->model()->data(ui->tableView->model()->index(row, 8));

        // Affichez ces données dans les QLineEdit correspondants
        ui->line_titre_ajout->setText(titreVariant.toString());
        ui->date_date_de_creation_ajout->setDate(dateVariant.toDate());
        ui->line_dimension_ajout->setText(dimensionVariant.toString());
        ui->line_description_ajout->setText(descriptionVariant.toString());
        ui->comboBox_status->setCurrentText(statusVariant.toString());
        ui->line_prix_ajout->setText(prixVariant.toString());
        ui->line_style_ajout->setText(styleVariant.toString());
        ui->line_reference_ajout->setText(referenceVariant.toString());
    }
}
