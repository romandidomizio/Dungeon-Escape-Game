------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: 
    g++ -std=c++17 Game.cpp

Run:
    ./a.out

------------------------
DEPENDENCIES
------------------------
library.h, Player.h, Monster.h, Riddles.h, Map.h, Player.cpp, Monster.cpp, Riddles.cpp, Map.cpp must be in the same directory as the cpp files in order to compile.

------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2022 Project 3
Author: Roman Di Domizio
Recitation: 204 - Enora Rice
Date: Dec 1, 2022

------------------------
ABOUT THIS PROJECT
------------------------
For the Final Project you will implement a text-based adventure game in C++. The game takes inspiration from the tabletop roleplaying game "Dungeons and Dragons." In the original game, each session differs from the next, depending on the story made up by the dungeon master and the way the players react to that story. But most commonly, the game consists of a party of players making their way through a dungeon by fighting monsters, solving puzzles, and interacting with characters. Our game will use this general blueprint as inspiration. An evil Sorcerer has captured a group of players and trapped them in a monster-filled, labyrinthine dungeon for their own amusement. The goal of this game is to make it out of the dungeon with as many party members alive as possible. Each turn in the dungeon makes you hungrier (reduces fullness) and has risks such as monsters and traps. You can fight monsters, speak to NPCs, and explore, but you must make it through the dungeon before the Sorcerer runs out of patience and destroys the dungeon, along with the player and all the party members!