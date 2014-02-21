#ifndef CALCULDUSCORE_H
#define CALCULDUSCORE_H

#include <QVector>

class CalculDuScore
{
        // Les méthodes :
    public :

    // Renvoie la valeur absolue d'un réel
    double Valeurabsolue(double a);

    // Gére les cas de dénominateur nul
    double Denominateur(double a);

    // Définit une métrique que nous utiliserons pour calculer les scores
    double NormeScore(QVector<double> const& a, QVector<double> const& b);

    // Fonction qui donne le score associé à une estimation
    double Scoreestimation(QVector<double> const& estimation, QVector<double> const& donnees, int k, int l, int t, int h);

    // Renvoie l'erreur moyenne de la prévision
    double Erreurmoyenne(QVector<double> const& estimation, QVector<double> const& donnees, int k, int l, int t, int h);
};

#endif // CALCULDUSCORE_H
