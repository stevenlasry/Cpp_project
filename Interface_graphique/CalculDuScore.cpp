#include <iostream>
#include "CalculDuScore.h"

// 1. Définition de la fonction qui retourne la valeur absolue
double CalculDuScore::Valeurabsolue(double a)
{
    if (a < 0)
    {
         return -a;
    }
    else
    {
        return a;
    }
}

// 2. Définition d'une fonction dénominateur qui gère les cas de dénominateurs nuls

double CalculDuScore::Denominateur(double a)
{
    if (a != 0)
    {
         return a;
    }
    else
    {
        return a+0.1;
    }
}

// 3. Définition de la métrique du score
double CalculDuScore::NormeScore(QVector<double> const& a, QVector<double> const& b)
{
double resultat(0);
int const taille(a.size());
// Création du vecteur de différence entre a et b
QVector<double> difference(taille);
// Nous remplisons les cases du tableau différence par la métrique adoptée pour les différences
    for (int i(0) ; i < taille ; ++i)
      {   difference[i]= Valeurabsolue(a[i]-b[i])/Denominateur(Valeurabsolue(b[i]));
   }
    for(int i(0) ; i < taille ; ++i)
    {resultat += difference[i];
    }
resultat /= taille;
return resultat;
}

// 4. Définition de la fonction qui associe à chaque estimation le score de celle-ci
double CalculDuScore::Scoreestimation(QVector<double> const& estimation, QVector<double> const& donnees, int k, int l, int t, int h)
{
double resultat(0);
QVector<double> x(h);
// Nous récupérons le vecteur des H valeurs suivants T
for (int i(0) ; i < h ; ++i)
      {   x[i]=donnees[t+i] ;
   }
resultat=NormeScore(estimation, x);
return resultat;
}

// 5. Définition de la fonction qui associe à chaque estimation l'erreur moyenne de celle-ci
double CalculDuScore::Erreurmoyenne(QVector<double> const& estimation, QVector<double> const& donnees, int k, int l, int t, int h)
{
double resultat(0);
QVector<double> x(h);
// Nous récupérons le vecteur des H valeurs suivants T
for (int i(0) ; i < h ; ++i)
      {   x[i]=donnees[t+i] ;
   }
// Nous prenons la moyenne des erreurs
for(int i(0); i< h; ++i)
{
   resultat += Valeurabsolue(estimation[i]-x[i]);
}
resultat/=h;
return resultat;
}
