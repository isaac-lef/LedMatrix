# LedMatrix

Ce projet a été fait lors du cours IoT du Master 2 IWOCS de l'Université du Havre, année 2022-2023, avec comme professeur Thomas SELLE, et Ghita EL-HACHAMI comme binôme.

## Présentation

Ceci est un driver pour les matrices de LEDs 8x8 de certains kits Arduino, avec une approche orientée objet. Il met en place une technique de clignotement rapide pour afficher tout ce que l'utilisateur veut.

## Utilité

Ces matrices de LEDs ont un problème fondamental. Elles fonctionnent en activant des lignes et colonnes, pour que les LEDs à leur intersection s'allument.

Naïvement, on peut essayer d'allumer 3 coins de la matrice. On remarque que le 4ème s'allume aussi, puisqu'on a activé sa colonne et sa ligne.

Ce problème était prévisible, puisqu'on a 2<sup>(8x8)</sup> images possibles mais seulement 2<sup>(8+8)</sup> combinaisons lignes/colonnes possibles.

Mais alors, il est impossible d'afficher les images 8x8 qu'on veut ? Effectivement, à moins de changer de technique.

À noter qu'il existe des solutions matérielles (circuit MAX7219). Ce projet a pour but de résoudre le problème de façon purement logicielle. 

## Fonctionnement

Ce problème ne se pose pas à l'échelle d'une seule ligne. On active la ligne, puis la colonne de chaque pixel qu'on veut allumer. D'où une solution : afficher notre image une ligne à la fois. Comme un radio-réveil, le clignotement est imperceptible s'il est suffisament rapide, et l'image entière se forme.

Ce programme se charge d'implémenter cette technique, pendant que l'utilisateur manipule une abstraction plus simple d'utilisation.

La mise en place se fait d'abord en instanciant l'objet LedMatrix, qui représente notre matrice de LEDs :
```Arduino
int rowPins[]    = {10, A4, 2, 13, 9,  3,  8,  5};
int columnPins[] = {A5,  7, 6, 11, 4, 12, A3, A2};
LedMatrix matrix = LedMatrix(rowPins, columnPins);
```
Où rowPins représente les ports de lignes et columnPins les ports de colonnes (voir le manuel de votre matrice de LEDs, et votre branchement).

Puis il faut mettre `matrix.update()` dans la fonction `loop()` du programme Arduino, nécessaire pour l'affichage ligne par ligne de l'image. La fréquence de changement de ligne sera directement la fréquence de `loop()`.

Enfin, vous pouvez afficher ce que vous voulez à l'aide des méthodes de la classe :
* `setAllOn()` : allumer toutes les LEDs.
* `setAllOff()` : éteindre toutes les LEDs.
* `setPixelOn(int rowId, int columnId)` : allumer le pixel de coordonnées (rowId,columnId).
* `setPixelOff(int rowId, int columnId)` : éteindre le pixel de coordonnées (rowId,columnId).
* `setPixel(int rowId, int columnId, bool status)` : appliquer `status` au pixel de coordonnées (rowId,columnId).
* `display(bool image[8][8])` : affiche une image représentée par une matrice booléenne 8x8, où `false` (0) vaut éteint et `true` (1) vaut allumé.
* `displayFromText(char* text, int length)` : affiche une image représentée par un texte, où 0 vaut éteint, 1 vaut allumé, les sauts de lignes sont nécessaires et les espaces sont ignorés.

Le code principal du projet sert d'exemple, il utilise cette classe pour afficher tour à tour les différents tétrominos du jeu Tetris. À vous de jouer.