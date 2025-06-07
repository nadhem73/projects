#include "oeuvre.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStandardItem>
#include <QDebug>


oeuvre::oeuvre(int id,QString titre ,QDate date_de_creation ,QString dimension ,QString description ,QString status ,QString prix ,QString style ,QString reference )
{
    this->id=id;
    this->titre=titre;
    this->date_de_creation=date_de_creation;
    this->dimension=dimension;
    this->description=description;
    this->status=status;
    this->prix=prix;
    this->style=style;
    this->reference=reference;
}
bool oeuvre::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("INSERT INTO oeuvre (titre, date_de_creation, dimension, description, status, prix, style, reference)"
                  "VALUES (:titre, :date_de_creation, :dimension, :description, :status, :prix, :style, :reference)");

    query.bindValue(":id", res);
    query.bindValue(":titre", titre);
    query.bindValue(":date_de_creation", date_de_creation);
    query.bindValue(":dimension", dimension);
    query.bindValue(":description", description);
    query.bindValue(":status", status);
    query.bindValue(":prix", prix);
    query.bindValue(":style", style);
    query.bindValue(":reference", reference);

     return query.exec();
}

QSqlQueryModel * oeuvre::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from oeuvre order by id");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TITRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE DE CREATION"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DIMENSION"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("STATUS"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("STYLE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("REFERENCE"));

    return model;
}

bool oeuvre::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from oeuvre where ID= :id");
    query.bindValue(":id",res);

    return  query.exec();
}
bool oeuvre::modifier(int id){

  /*  qDebug() <<id;
    QSqlQuery query;
    query.prepare("UPDATE oeuvre set titre = :titre, date_de_creation = :date_de_creation,"
                  "dimension = :dimension, description = :description,"
                  "status = :status, prix = :prix, style = :style, reference = :reference"
                  "WHERE id=:id");

    query.bindValue(":titre",titre);
    query.bindValue(":date_de_creation",date_de_creation);
    query.bindValue(":dimension",dimension);
    query.bindValue(":description",description);
    query.bindValue(":status",status);
    query.bindValue(":prix",prix);
    query.bindValue(":style",style);
    query.bindValue(":reference",reference);


    query.exec();
*/





    QSqlQuery query;
    query.prepare("UPDATE oeuvre SET titre = :titre,"
                  "date_de_creation = :date_de_creation,"
                  "dimension = :dimension, description = :description,"
                  "status = :status, prix = :prix, style = :style,"
                  "reference = :reference "
                  "WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":titre", titre);
    query.bindValue(":date_de_creation", date_de_creation);
    query.bindValue(":dimension", dimension);
    query.bindValue(":description", description);
    query.bindValue(":status", status);
    query.bindValue(":prix", prix);
    query.bindValue(":style", style);
    query.bindValue(":reference", reference);
    return query.exec();


}
