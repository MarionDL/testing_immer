# HPC - Projet 2 : Analyse de l'outil immer

Auteur : Marion Dutu Launay

Date : 12 juin 2020

## Description du logiciel

Immer est une bibliothèque écrite en C++ qui propose des structures de données persistantes, c'est à dire qui préserve ses versions précédentes lorsqu'elle est modifiée. Une telle structure est immuable, en d'autre termes son état ne peut pas être modifié après sa création. ; en effet, ses opérations ne la modifient pas de manière visible mais renvoient de nouvelles structures.

Cette librairie tire parti des fonctionnalités du standard C++ récent pour fournir une API efficace et naturele pour un développeur lambda. Elle implémente des structures de données "de pointe" en utilisant efficacement le cache et inclut des améliorations particulières par rapport à celles qui sont possibles en raison de la capacité du C++ à abstraire l'organisation de la mémoire. Immer exploite des modèles et un design basés sur des politiques permettant de créer des structures de données qui peuvent être adaptées pour fonctionner efficacement à diverses fins et architectures.

## Motivations

La conférence du créateur de Immer explique ses réflexions quant aux limites et problèmes des structures de données basiques et du modèle de programmation standard (7 premières minutes) : https://www.youtube.com/watch?v=sPhpelUfu8Q

Au cours des dernières années, un intérêt croissant pour les structures de données immuables est apparu, motivé par l'échelle horizontale de notre puissance de traitement et l'omniprésence des systèmes hautement interactifs.

Ce type de structures permet d'obtenir d'innovants types d'architecture pour des programmes interactifs et concurrents d'une simplicité, exactitude et performance remarquables.

Le passage par valeur des structures de données immuables n'a pas besoin de copier des données. En l'absence de mutation, les données peuvent être lues sans risque depuis plusieurs processus simultanés et activer des modèles de concurrence comme le partage, avec une communication efficace.

## Procédure d'installation

Immer est une librairie contenue dans fichier header uniquement. Pour l'utiliser, il faut télécharger le dossier `immer` du dépôt GitHub (lien dans les sources) et effectuer la procédure standard d'inclusion d'une librairie externe.

Dans mon cas, j'ai mis le dossier `immer` dans un dossier `include` et compilé mes fichiers source avec l'option `-I../include/`.

## Etude d'un use case

## Conclusion

## Matériel de référence

## Sources

Documentation officielle : https://sinusoid.es/immer/

Code source : https://github.com/arximboldi/immer
