#ifndef PrevisionPlusProchesVoisinsNORMEUN_H
#define PrevisionPlusProchesVoisinsNORMEUN_H

#include "ModeleDePlusProchesVoisins.h"
#include <QVector>

class PrevisionPlusProchesVoisinsNormeUn : public ModeleDePlusProchesVoisins
{
      // Méthodes :

    public :

    // Renvoie la norme un entre deux vecteurs

    double Normeun(QVector<double> const& a, QVector<double> const& b);

    // Renvoie les L plus proches voisins pour un entier K fixé.
    // Chaque sous vecteur est composé de la distance avec les K dernières valeurs, de
    // l'observation et les H observations suivantes qui permettront la prédiction

    QVector<QVector<double> > Lplusprochesvoisins(QVector<double> const& donnees, int k, int l, int t, int h);

    // Renvoie l'estimation pour K et L fixés

    QVector<double> EstimationKL(QVector<double> const& donnees, int k, int l, int t, int h);

    // Renvoie le couple (K,L) qui donne la prévision optimal sur l'historique

    QVector<double> KLmax(QVector<double> const& donnees,int t, int h);

    // On renvoie enfin l'estimation que donne le meilleur couple K,L

    QVector<double> Estimation(QVector<double> const& donnees, int t, int h);
};

#endif // PrevisionPlusProchesVoisinsNORMEUN_H
