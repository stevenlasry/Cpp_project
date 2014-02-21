#include "ModeleDePlusProchesVoisins.h"

// 1. Définition d'une fonction qui isole les k dernières valeurs de la série. Ces valeurs
// sont celles qui précédent le moment T de la prédiction (dont T)

QVector<double> ModeleDePlusProchesVoisins::Isoleleskdernieres(QVector<double> const& x, int k, int t)
{
 QVector<double> resultat(k);
 // Nous remplissons les cases du vecteur par les k dernières données du tableau de départ

 for (int i(0) ; i < k ; ++i)
      {   resultat[i]= x[t-k+i];
   }
    return resultat;
}

// 2. Définition d'une fonction qui trie les tableaux par ordre décroissant
QVector< QVector<double> > ModeleDePlusProchesVoisins::Trieurtableau(QVector< QVector<double> > matrice)
{
 int taille(matrice.size());
 int taillevecteursecondaire(matrice[0].size());
 QVector<double> t(taillevecteursecondaire);
    for(int i(1) ; i < taille ; ++i)
    {
        // Nous comparons les valeurs adjacentes

    for(int j(taille-1) ; j >=i ; --j)
    {
        if(matrice[j - 1][0] > matrice[j][0]) {
        t = matrice[j - 1]; // Echange les valeurs si nécéssaire
        matrice[j - 1]= matrice[j];
        matrice[j] = t; // Il faut échanger la totalité du vecteur secondaire
      }
    }
}
    return matrice;
}

// 3. Définition d'une fonction qui renvoie la moyenne entre plusieurs vecteurs
QVector<double> ModeleDePlusProchesVoisins::Moyenne(QVector< QVector<double> > const& m, int h)
{
QVector<double> resultat(h);
for(int j(0); j<h; ++j)
{
double previsionj(0);
for(int i(0); i<m.size(); ++i)
{
   previsionj += m[i][j+2];
}
previsionj/=m.size();
resultat[j]=previsionj;
}
return resultat;
}
