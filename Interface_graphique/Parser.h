#ifndef PARSER_H
#define PARSER_H
#include<limits>
#include<iostream>
#include<QVector>
#include <QFile>
#include <QTextStream>
#include <QtWidgets/QApplication>
#include <QTextEdit>
#include <vector>
#include <QString>

class Parser
{
     // Les méthodes :

public :

    // Renvoie le nombre de ligne d'un fichier (donc le nombre d'observations de la série)
    int Nombredeligne (QString nomdufichier);

    // Lit un fichier source et enregistre les valeurs de la série dans un vecteur
    QVector <double> Lecteur (QString nomdufichier);

    int MaxValue(QString foldername);

    int MinValue(QString foldername);
};

#endif // PARSER_H
