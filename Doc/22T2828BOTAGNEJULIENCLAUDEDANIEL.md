# Rapport sur mes exercices de structures chaînées en C

**Nom :** BOTAGNE JULIEN CLAUDE DANIEL  
**Matricule :** 22T2828  

##**Écriture du contenu du fichier readme.md**

## Exercice 3 : Liste doublement chaînée triée

### Méthodologie
- J’ai créé une structure `Maillon` avec trois champs :  
  - `info` pour stocker la valeur,  
  - `apres` pour pointer vers le suivant,  
  - `avant` pour pointer vers le précédent.  
- J’ai écrit une fonction d’insertion qui place les éléments de façon triée (ordre croissant).  
- J’ai ajouté une fonction d’affichage dans les deux sens :  
  - du début vers la fin (croissant),  
  - puis de la fin vers le début (décroissant).  
- J’ai modifié le code pour **entrer moi-même les valeurs au clavier** au lieu d’utiliser un tableau fixe.  

### Problèmes rencontrés
- Gestion des cas particuliers (liste vide, insertion en tête).  
- Mauvaise initialisation des pointeurs qui pouvait causer des erreurs d’exécution.  

### Solutions
- J’ai ajouté des conditions pour traiter séparément la liste vide et l’insertion en tête.  
- J’ai fait attention à bien initialiser les pointeurs `avant` et `apres` à `NULL` au moment de l’allocation.  



## Exercice 4 : Liste simplement chaînée circulaire

### Méthodologie
- J’ai défini une structure `Element` avec :  
  - `valeur` pour stocker l’entier,  
  - `vers` pour pointer vers le suivant.  
- J’ai implémenté deux fonctions d’insertion :  
  - en **tête**, où le nouvel élément devient la nouvelle tête,  
  - en **queue**, où le nouvel élément est ajouté juste avant de revenir à la tête.  
- J’ai fait une fonction d’affichage qui parcourt la liste circulaire avec une boucle `do...while`.  
- J’ai modifié le code pour **entrer moi-même les valeurs** et choisir **où insérer** (tête ou queue) pour chaque valeur.  

### Problèmes rencontrés
- Risque de boucle infinie à l’affichage si la condition n’était pas bien écrite.  
- Confusion entre l’insertion en tête et en queue quand la liste était vide.  

### Solutions
- J’ai utilisé la boucle `do...while` pour garantir un parcours complet tout en arrêtant quand je reviens à la tête.  
- J’ai traité le cas particulier de la liste vide en faisant pointer le premier élément vers lui-même.

 ## **création de la branche TD_TP2_suggestions**

## Modifications apportées à l'exercice 2

- Correction du code pour rendre la liste triée interactive :  
  ```c
  // Suppression des valeurs codées en dur
  // Ajout de la saisie utilisateur pour créer la liste initiale
  int n, valeur;
  printf("Combien d'éléments voulez-vous insérer dans la liste ? ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
      printf("Entrez l'élément %d : ", i + 1);
      scanf("%d", &valeur);
      insererDansListeTriee(&tete, valeur);
  }

## proposition Exercice  5 : Liste doublement chaînée circulaire

### Proposition
Créer une liste doublement chaînée circulaire permettant :
- l’insertion d’éléments en tête et en queue,  
- l’affichage de la liste complète.

### Solution
```c
int n, data;
printf("Combien d'éléments voulez-vous insérer dans la liste initiale ? ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
    printf("Entrez l'élément %d : ", i + 1);
    scanf("%d", &data);
    head = insertTail(head, data);
}


