#include <stdio.h>
#include <stdlib.h>


typedef struct Element {
    int valeur;
    struct Element *vers;
} Element;

/**
 * Insertion en tête d'une liste simplement chaînée circulaire
 */
Element* ajouter_au_debut(Element *tete, int valeur) {
    Element *nouveau = (Element*)malloc(sizeof(Element));
    if (nouveau == NULL) {
        printf("Erreur: allocation impossible\n");
        return tete;
    }
    
    nouveau->valeur = valeur;
    
    // Cas d'une liste vide
    if (tete == NULL) {
        nouveau->vers = nouveau;  // Pointe vers lui-même
        return nouveau;
    }
    
    // Localiser le dernier élément (celui qui boucle vers la tête)
    Element *queue = tete;
    while (queue->vers != tete) {
        queue = queue->vers;
    }
    
    // Insertion du nouveau en tête
    nouveau->vers = tete;
    queue->vers = nouveau;
    
    return nouveau; // Le nouveau devient la tête
}

/**
 * Insertion en queue d'une liste simplement chaînée circulaire
 */
Element* ajouter_a_la_fin(Element *tete, int valeur) {
    Element *nouveau = (Element*)malloc(sizeof(Element));
    if (nouveau == NULL) {
        printf("Erreur: allocation impossible\n");
        return tete;
    }
    
    nouveau->valeur = valeur;
    
    
    if (tete == NULL) {
        nouveau->vers = nouveau;  // Pointe vers lui-même
        return nouveau;
    }
    
    // Trouver le dernier élément
    Element *dernier = tete;
    while (dernier->vers != tete) {
        dernier = dernier->vers;
    }
    
    // Insertion à la fin
    dernier->vers = nouveau;
    nouveau->vers = tete;  // Boucle vers la tête
    
    return tete;  // La tête ne change pas
}

// Fonction d'affichage de la liste circulaire
void montrer_liste(Element *tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    Element *current = tete;
    printf("[ ");
    do {
        printf("%d ", current->valeur);
        current = current->vers;
    } while (current != tete);
    printf("] -> retour à %d\n", tete->valeur);
}


int compter_elements(Element *tete) {
    if (tete == NULL) return 0;
    
    int compteur = 1;
    Element *temp = tete->vers;
    
    while (temp != tete) {
        compteur++;
        temp = temp->vers;
    }
    
    return compteur;
}


void detruire_liste(Element *tete) {
    if (tete == NULL) return;
    
    Element *actuel = tete;
    Element *suivant;
    
    do {
        suivant = actuel->vers;
        free(actuel);
        actuel = suivant;
    } while (actuel != tete);
}


int main() {
    Element *liste = NULL;
    int n, valeur, choix;

    printf("==== Liste simplement chaînée circulaire ====\n\n");

    printf("Combien de valeurs voulez-vous insérer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEntrez la valeur %d: ", i + 1);
        scanf("%d", &valeur);

        printf("Où insérer ? (1 = Tête, 2 = Queue) : ");
        scanf("%d", &choix);

        if (choix == 1) {
            liste = ajouter_au_debut(liste, valeur);
        } else {
            liste = ajouter_a_la_fin(liste, valeur);
        }

        printf("Liste après insertion de %d :\n", valeur);
        montrer_liste(liste);
    }

    printf("\nNombre total d'éléments: %d\n", compter_elements(liste));

    
    detruire_liste(liste);

    return 0;
}
