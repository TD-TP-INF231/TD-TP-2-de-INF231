#include <stdio.h>
#include <stdlib.h>


typedef struct Maillon {
    int info;
    struct Maillon *apres;
    struct Maillon *avant;
} Maillon;

Maillon* inserer_element_trie(Maillon *debut, int element) {
    // Allocation du nouveau maillon
    Maillon *neuf = (Maillon*)malloc(sizeof(Maillon));
    if (neuf == NULL) {
        printf("Erreur: Mémoire insuffisante\n");
        return debut;
    }
    
    neuf->info = element;
    neuf->apres = NULL;
    neuf->avant = NULL;
    
    // Cas 1 : liste vide
    if (debut == NULL) {
        return neuf;
    }
    
    // Cas 2 : insertion en tête
    if (element <= debut->info) {
        neuf->apres = debut;
        debut->avant = neuf;
        return neuf;
    }
    
    // Cas 3: insertion au milieu ou à la fin
    Maillon *explorateur = debut;
    while (explorateur->apres != NULL && explorateur->apres->info < element) {
        explorateur = explorateur->apres;
    }
    
    neuf->apres = explorateur->apres;
    neuf->avant = explorateur;
    
    if (explorateur->apres != NULL) {
        explorateur->apres->avant = neuf;
    }
    explorateur->apres = neuf;
    
    return debut;
}

void visualiser_liste(Maillon *debut) {
    if (debut == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    printf("Sens croissant: ");
    Maillon *pointeur = debut;
    while (pointeur != NULL) {
        printf("%d ", pointeur->info);
        pointeur = pointeur->apres;
    }
    printf("\n");
    
    
    pointeur = debut;
    while (pointeur->apres != NULL) {
        pointeur = pointeur->apres;
    }
    
    printf("Sens décroissant: ");
    while (pointeur != NULL) {
        printf("%d ", pointeur->info);
        pointeur = pointeur->avant;
    }
    printf("\n");
}

void liberer_liste(Maillon *debut) {
    Maillon *actuel = debut;
    Maillon *suivant;
    
    while (actuel != NULL) {
        suivant = actuel->apres;
        free(actuel);
        actuel = suivant;
    }
}

int main() {
    Maillon *ma_liste = NULL;
    int n, valeur;

    printf("=== Insertion dans une liste doublement chaînée triée ===\n\n");

    
    printf("Combien de valeurs voulez-vous insérer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d: ", i + 1);
        scanf("%d", &valeur);

        ma_liste = inserer_element_trie(ma_liste, valeur);

        printf("Après insertion de %d:\n", valeur);
        visualiser_liste(ma_liste);
        printf("\n");
    }

    
    liberer_liste(ma_liste);

    return 0;
}
