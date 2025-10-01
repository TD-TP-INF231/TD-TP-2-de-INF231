Rapport Personnel : Exercice INF 231 – Points 1 et 5
Nom : MUSA SAIDU
Matricule : 24G2172
Cours : INF 231
Date : 1er octobre 2025
Enseignant : Pr Melatagia  

Mon travail

J’ai travaillé sur les points 1 et 5 de l’exercice INF 231. Le point 1 consistait à supprimer toutes les occurrences d’un élément dans une liste simplement chaînée, et le point 5 à insérer des éléments en tête et en queue d’une liste doublement chaînée circulaire, en C. J’ai conçu, implémenté et testé les programmes pour ces deux parties.

Point 1 : Suppression de toutes les occurrences dans une liste simplement chaînée

Ce que j’ai fait :
J’ai créé une fonction qui lit un élément et supprime toutes ses occurrences dans une liste simplement chaînée. J’ai géré la suppression en tête séparément pour éviter des erreurs, puis parcouru la liste pour supprimer les autres occurrences. J’ai ajouté une fonction d’affichage pour vérifier les résultats.  

Problèmes rencontrés :
Gérer la suppression en tête était délicat, car il fallait mettre à jour le pointeur de tête. J’ai aussi dû éviter les erreurs de pointeurs nuls.  

Solutions :
J’ai testé la fonction avec des cas comme une liste vide ou un élément absent. J’ai vérifié chaque suppression pour m’assurer que la liste restait cohérente.  

Résultat :
La fonction supprime correctement toutes les occurrences de l’élément, et la liste reste bien formée.

Point 5 : Insertion en tête et en queue dans une liste doublement chaînée circulaire

Ce que j’ai fait :
J’ai défini une structure de nœud avec des pointeurs prev et next. J’ai écrit deux fonctions : une pour insérer en tête et une pour insérer en queue, en maintenant la circularité. J’ai ajouté une fonction d’affichage pour vérifier que la liste reste circulaire. J’ai testé avec une liste vide et des listes avec plusieurs éléments.  

Problèmes rencontrés :
Connecter les pointeurs prev et next pour garder la liste circulaire était complexe. Le cas de la liste vide demandait un traitement spécial.  

Solutions :
J’ai testé chaque insertion étape par étape et utilisé l’affichage pour confirmer que les pointeurs étaient corrects. J’ai géré le cas de la liste vide en faisant pointer le nœud sur lui-même.  

Résultat :
Les insertions en tête et en queue fonctionnent, et la liste reste circulaire, avec un affichage clair des éléments.

Conclusion
Ces deux parties m’ont permis de mieux comprendre la gestion des listes chaînées en C. Pour le point 1, j’ai appris à manipuler les pointeurs dans une liste simplement chaînée. Pour le point 5, j’ai maîtrisé les listes doublement chaînées circulaires, en particulier la gestion des pointeurs dans les deux directions. Mes programmes sont simples et fonctionnent correctement après des tests rigoureux.