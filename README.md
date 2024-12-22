# Rapport 
https://docs.google.com/document/d/1v6DojOyck1JiW-xOi7uJPf6Dva5Fpj3pH-NnuBG6dqI/edit?usp=sharing

# The_Incredibles

Idee de base :

- simulation de spirographe qui aurait des contraintes pour former certaines figures
- ajout : pouvoir dessiner des figures simples
- ajout : créer une autre classe spirographe avec une base en ellipse et plusieurs cercles ou ellipse a l'interieur ou a l'exterieur

Autre idées:
-Choisir les paramètres selon des touches spécifiques sur le clavier et les modifier avec les mouvements de la souris

https://github.com/Beatzoid/sfml-macos/blob/master/Makefile


Commandes utilisées pour sfml :
 
g++ -Wall Ellipse.cc -c Ellipse.o -lsfml-graphics -lsfml-window -lsfml-system Ellipse.hh Figure.hh Point.hh
g++ -Wall -c main.o  main.cc -lsfml-graphics -lsfml-window -lsfml-system Figure/Ellipse.hh
g++ -Wall -o main.out  main.o -lsfml-graphics -lsfml-window -lsfml-system Figure/Ellipse.o Figure/Ellipse.hh Figure/Point.hh Figure/Figure.hh
./main.out 
