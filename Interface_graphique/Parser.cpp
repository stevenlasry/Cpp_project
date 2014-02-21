#include <QFile>
#include <QString>
#include <QTextStream>
#include <QtWidgets/QApplication>
#include <QTextEdit>
#include "Parser.h"

// 1. Définition d'une fonction qui retourne le nombre de lignes d'un fichier
int Parser::Nombredeligne (QString nomdufichier)
{
    int resultat(0);
    QString texte;
    QFile fichier(nomdufichier);

    // Lecture du fichier
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {   QTextStream flux(&fichier);
        while (!flux.atEnd())
        {
            texte = flux.readLine();
            resultat++;
        }
        fichier.close();
    }
  return resultat;
}

// 2. Définition d'une fonction qui enregistre dans un vecteur les valeurs de la série données par le fichier source
QVector <double> Parser::Lecteur(QString nomdufichier)
{
 QFile fichier(nomdufichier);
 int lignes(0);
    // Nous récupérons le nombre de lignes
 lignes = Nombredeligne(nomdufichier);
    // Nous créons notre vecteur d'observations
 QVector <double> resultat(lignes);
 if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
 {   QTextStream flux(&fichier);
     // Nous récupérons les éléments du fichier au sein d'un vecteur
 for (int i(0) ; i < lignes ; i++)
 {flux >> resultat[i];
 }
 fichier.close();
 }
 return resultat;
}

//3. Définition of a function which returns the maximum of the series values given by the source folder
int Parser::MaxValue(QString foldername)
{
    int max(0);
    double number(0);
    QString text;
    QFile folder(foldername);
    if(folder.open(QIODevice::ReadOnly | QIODevice::Text))
    {   QTextStream flux(&folder);
        while (!flux.atEnd())
        {
            text = flux.readLine();
            number = text.split(" ")[0].toDouble();
            if (number > max) max = number;
        }
        folder.close();
    }
   return max;
}

//4. Définition of a function which returns the minimum of the series values given by the source folder
int Parser::MinValue(QString foldername)
{
    int min(0);
    double number(0);
    QString text;
    QFile folder(foldername);
    if(folder.open(QIODevice::ReadOnly | QIODevice::Text))
    {   QTextStream flux(&folder);
        while (!flux.atEnd())
        {
            text = flux.readLine();
            number = text.split(" ")[0].toDouble();
            if (number < min) min = number;
        }
        folder.close();
    }
   return min;
}
