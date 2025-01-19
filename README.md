# The_Incredibles

Notre code permet de simuler, modifier et ajouter des spirographes de tailles, couleurs, et nombres de sommets (variant de trois à cinq) différents dans le dossier /code.
Il permet aussi de tester notre code via doctest.h dans le dossier /code/test. Un diagramme UML représentant toutes les classes crées est aussi fourni. 

Nous sommes parti du principe que le spirographe était représenté par un cercle roulant sur les bords à l'intérieur d'un grand cercle. Un segment fixé sur le centre du cercle intérieur trace le spirographe.

Bibliothèque requise: 
- SFML 

Configuration: 
- changer les paths pour SFML dans les makefile selon la machine (windows,linux, macos) dans le bon dossier (/code ou /code/test)
- make dans code pour la simulation : spirograph ou
- make dans test pour executer les testcases : test_unitaire
- executer (./spirograph ou ./test_unitaire) dans le bon dossier

Dans la simulation :

  Dans la premiere page :
  
- le bouton Nouvelle_Figure permet d'ajouter un spirographe
- le bouton Clear enleve les spirographes

  Dans la deuxieme page :
  
- les boutons pour le nombre de sommets permet de faire varier le nombre de sommets de 3 a 5 du spirographe à modifier
- les boutons (x+) et(x-) (resp. (y+) et (y-)) permet de déplacer le spirographe à modifier
- les boutons pour la taille du crayon modifie le rapport entre la taille du crayon et le cercle interieur
- le bouton OK permet de valider les modifications
