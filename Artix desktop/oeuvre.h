#ifndef OEUVRE_H
#define OEUVRE_H

#include "QSqlQueryModel"
#include <QSqlQuery>
#include <QComboBox>
#include <QString>
#include <string>
#include "QDate"

class oeuvre
{
    int id;
    QString titre, dimension, description, prix, style, reference, status;
    QDate date_de_creation;

public:
    oeuvre(){}
    oeuvre(int,QString  ,QDate  ,QString  ,QString  ,QString  ,QString  ,QString  ,QString  );
    //oeuvre(QString  ,QDate  ,QString  ,QString  ,QString  ,QString  ,QString  ,QString);
    QString gettitre(){return titre;}
    QDate getdate_de_creation(){return date_de_creation;}
    QString getdimension(){return dimension;}
    QString getdescription(){return description;}
    QString getstatus(){return status;}
    QString getprix(){return prix;}
    QString getstyle(){return style;}
    QString getreference(){return reference;}

    void settitre(QString t){titre=t;}
    void setdate_de_creation(QDate da){date_de_creation=da;}
    void setdimension(QString di){dimension=di;}
    void setdescription(QString de){description=de;}
    void setstatus(QString s){status=s;}
    void setprix(QString p){prix=p;}
    void setstyle(QString st){style=st;}
    void setreference(QString r){reference=r;}
    void setid(int id){this->id=id;}

    bool ajouter() ;
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);


};
#endif // OEUVRE_H
