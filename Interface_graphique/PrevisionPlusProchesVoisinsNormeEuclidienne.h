#ifndef PrevisionPlusProchesVoisinsNORMEEUCLIDIENNE_H
#define PrevisionPlusProchesVoisinsNORMEEUCLIDIENNE_H

#include "ModeleDePlusProchesVoisins.h"
#include <QVector>
#include <QtGui>

class PrevisionPlusProchesVoisinsNormeEuclidienne : public ModeleDePlusProchesVoisins
{
     // Méthodes :
    public :
    //Constructeur
    //PrevisionPlusProchesVoisinsNormeEuclidienne();

    // Renvoie la norme euclidienne entre deux vecteurs
    double Normeeuclidienne(QVector<double> const& a, QVector<double> const& b);

    // Renvoie les L plus proches voisins pour un entier K fixé.
    // Chaque sous vecteur est composé de la distance avec les K dernières valeurs, de
    // l'observation et des H observations suivantes qui permettront la prédiction
    QVector<QVector<double> > Lplusprochesvoisins(QVector<double> const& donnees, int k, int l, int t, int h);

    // Renvoie la prevision du modèle pour K et L fixés
    QVector<double> EstimationKL(QVector<double> const& donnees, int k, int l, int t, int h);

    // Renvoie le couple (K,L) qui donne la prévision optimale sur l'historique
    QVector<double> KLmax(QVector<double> const& donnees,int t, int h);

    // Renvoie l'estimation que donne le meilleur couple (K,L)
    QVector<double> Estimation(QVector<double> const& donnees, int t, int h);

};

#endif // PrevisionPlusProchesVoisinsNORMEEUCLIDIENNE_H
