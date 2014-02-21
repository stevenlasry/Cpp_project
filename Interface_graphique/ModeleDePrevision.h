#ifndef MODELEDEPREVISION_H
#define MODELEDEPREVISION_H

#include "CalculDuScore.h"

class ModeleDePrevision
{
     // Les méthodes :
    public:
   // ModeleDePrevision();

   // Fonction qui renvoie la valeur absolue
   double Valeurabsolue(double a);

   // Fonction qui donne le score associé à une estimation
   double Scoreestimation(QVector<double> const& estimation, QVector<double> const& donnees, int k, int l, int t, int h);

   // Déclaration des getters
   QVector<double> Get_donnees();
   int Get_h();
   int Get_t();

   // Déclaration des setters
   void Set_donnees(QVector<double>);
   void Set_h(int);
   void Set_t(int);

       // Les champs :
   private :

   // Un objet de la classe CalculDuScore
    CalculDuScore m_calculduscore;

   // Les données
    QVector <double> _donnees;

    // L'horizon de prédiction
    int _h;

    // Le moment à partir duquel a lieu la prédiction
    int _t;
};

#endif // MODELEDEPREVISION_H
