#ifndef PLUSPROCHESVOISINS_H
#define PLUSPROCHESVOISINS_H

#include "ModeleDePrevision.h"

class ModeleDePlusProchesVoisins : public ModeleDePrevision
{
     // Les méthodes :

    public:
   // ModeleDePlusProchesVoisins();

   // Fonction qui Isole les K dernières valeurs précédents T (dont T) pour les comparer aux autres suites de la série
   QVector<double> Isoleleskdernieres(QVector<double> const& x, int k, int t);

   // Fonction qui trie les matrices par ordre décroissant. Elle nous sera utile pour repérer les plus proches voisins
   QVector<QVector<double> > Trieurtableau(QVector<QVector<double> > tableau);

   // Fonction qui donne la moyenne des L plus proches voisins pour les H valeurs estimées
   QVector<double> Moyenne(QVector< QVector<double> > const& m, int h);

};

#endif // PLUSPROCHESVOISINS_H
