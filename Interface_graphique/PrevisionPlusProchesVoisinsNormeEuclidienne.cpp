#include <iostream>
#include "PrevisionPlusProchesVoisinsNormeEuclidienne.h"
#include <QVector>

// 1. Définition d'une fonction qui retourne la norme euclidienne entre deux vecteurs
double PrevisionPlusProchesVoisinsNormeEuclidienne::Normeeuclidienne(QVector<double> const& a, QVector<double> const& b)
{
    double resultat(0);
    int const taille(a.size());
    // Création du vecteur de différence entre a et b
    QVector<double> difference(taille);
    for (int i(0) ; i < taille ; ++i)
      {   difference[i]= (a[i]-b[i])*(a[i]-b[i]);
   }
    for(int i(0) ; i < taille ; ++i)
    {resultat += difference[i];
    }
    return resultat;
}

// 2. Fonction qui rasssemble dans un vecteur les L plus proches voisins
        // Le vecteur contientdans cet ordre 1) La distance euclidienne 2) L'observation
        // 3) Les h observations suivantes
QVector< QVector<double> > PrevisionPlusProchesVoisinsNormeEuclidienne::Lplusprochesvoisins(QVector<double> const& donnees, int k, int l, int t, int h)
{  QVector<double> kdernieres(k);
    // Nous isolons les K dernières observations (dont T)
   kdernieres=Isoleleskdernieres(donnees, k, t);
   QVector< QVector<double> > resultat(l, QVector<double>(2+h));
   // Nous construisons une matrice contenant les L plus proches voisins,
   // c'est à dire dans chaque colonne 1) La distance euclidienne 2) L'observation 3) h observations suivantes
    for (int g(0) ; g < l ; ++g)
       {resultat[g][0]=100000;
       }
       for (int i(k-1) ; i < t-h ; ++i)
       {QVector<double> x(h+2);
        x[1]=donnees[i]; // On rentre l'observation
       for (int g(2) ; g < h+2 ; ++g)
       {x[g]=donnees[i+g-1];
       }
        QVector<double> kvaleursprecedantsi(k);
    // Pour chaque i, nous créons le vecteur contenant i et les k-1 observations précédants i
        kvaleursprecedantsi=Isoleleskdernieres(donnees, k, i+1);
    // La première ligne de la matrice contient les distances euclidiennes
        x[0]=Normeeuclidienne(kdernieres,kvaleursprecedantsi);
            if (x[0]<resultat[l-1][0])
            {
            resultat[l-1][0]=x[0];
             resultat[l-1][1]=x[1];
             for (int g(2) ; g < h+2 ; ++g)
       {
           resultat[l-1][g]=x[g];
       }
             resultat=Trieurtableau(resultat);
            }
       }
return resultat;
}

// 3. Définition d'une fonction qui retourne la prévision pour K et L fixés
QVector<double> PrevisionPlusProchesVoisinsNormeEuclidienne::EstimationKL(QVector<double> const& donnees, int k, int l, int t, int h)
{
QVector<double> resultat(h);
QVector< QVector<double> > y(l, QVector<double>(h+2));
 y=Lplusprochesvoisins(donnees, k, l, t, h);
 resultat=Moyenne(y, h);
 return resultat;
}

// 4. Fontion qui retourne le couple (K,L) qui donne les meilleurs prévisions sur l'historique
QVector<double> PrevisionPlusProchesVoisinsNormeEuclidienne::KLmax(QVector<double> const& donnees, int t, int h)
{
   QVector<double> resultat(3, 100000);
   double kmax(0);
   kmax=qMin(11, t-h+1);
    // Nous fixons d'abord un entier K
for(int k(2) ; k < kmax; ++k)
{
    // Création d'un vecteur qui contiendra la valeur de L qui maximise l'estimation KL à K fixé ainsi que son score
    QVector<double> x(3);
    x[0]=1000000;
    x[1]=k;
    x[2]=1;
    double lmax(0);
    lmax=qMin(11,t-k+2-h);
    for(int l(1) ; l < lmax; ++l)
    {
    double scoreKL(0);
    // Nous cherchons à calculer le score de cette technique d'estimation
    //  en calculant la moyenne des scores sur tous les points du passé de T
        for(int j(k+l) ; j < t-h+1 ; ++j)
        {
            QVector<double> estimationKLJ(h);
            estimationKLJ=EstimationKL(donnees, k, l, j, h);
            scoreKL += Scoreestimation(estimationKLJ, donnees, k, l, j, h);
        }
    scoreKL/=(t-k-h-l+1);
    if (scoreKL < x[0])
    {
        x[0]=scoreKL;
        x[2]=l;
    }
    }
    if (x[0]<resultat[0])
    {
resultat[0]=x[0];
resultat[1]=x[1];
resultat[2]=x[2];
    }
}
return resultat;
}

// 5. Fonction qui donne l'estimation optimisée
QVector<double> PrevisionPlusProchesVoisinsNormeEuclidienne::Estimation(QVector<double> const& donnees, int t, int h)
{
QVector<double> resultat(h);
QVector<double> x(3);
x=KLmax(donnees, t, h);
resultat=EstimationKL(donnees, x[1], x[2], t, h);
return resultat;
}
