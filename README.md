# Filler

![filler](resources/filler.gif)

My player is the white one ;)

## About

Filler is a game, where two players / algorithm are fighting on a map.

A virtual machine organizes the game :

calls the players alternatively
give each a random piece
On each turn, the current player have to put his piece on the map, and try to bother the ennemy. To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin).

The game appears on the standard input.

The aim of the game is to put more pieces on the map than the ennemy.

## Usage
Basic usage
```
make
./resources/filler_vm -f resources/maps/map02 -p1 ./name_of_p1 -p2 ./name_of_p2
```

Visualisator usage
```
make arena
./resources/filler_vm -f resources/maps/map02 -p1 ./name_of_p1 -p2 ./name_of_p2 | ./filler_arena
```

[Project subject](resources/lem-in.en.pdf)

[Norme](resources/norme.en.pdf)

### Marks. 125/100
