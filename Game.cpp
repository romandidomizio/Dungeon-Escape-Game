#include "library.h"

class Game
{
public:
    Player player;
    Map map;
    MonsterList monsterlist;
    RiddleList riddlelist;
    int angerLevel = 0;
    int monster = 0;
    bool gaveUp = false;
    void buyIngredients()
    {
        int amount;
        cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)\n";
        cin >> amount;
        if (amount != 0)
            player.buyIngredients(amount);
    }
    void buyCookware()
    {
        int amount, choice;
        cout << "I have a several types of cookware, which one would you like?\nEach type has a different probability of breaking when used, marked with (XX%).\n";
        cout << "Choose one of the following:\n1. (25%) Ceramic Pot [2 Gold]\n2. (10%) Frying Pan [10 Gold]\n3. ( 2%) Cauldron [20 Gold]\n4. Cancel\n";
        cin >> choice;
        if (choice != 4)
        {
            cout << "How many would you like? (Enter a positive integer)\n";
            cin >> amount;
            player.buyCookware(choice-1, amount);
        }
    }
    void buyWeapon()
    {
        int amount, choice;
        cout << "I have a plentiful collection of weapons to choose from, what would you like?\nNote that some of them provide you a special bonus in combat, marked by a (+X).\n";
        cout << "Choose one of the following:\n1. Stone Club [2 Gold]\n2. Iron Spear [2 Gold]\n3. (+1) Mythril Rapier [5 Gold]\n4. (+2) Flaming Battle-Axe [15 Gold]\n5. (+3) Vorpal Longsword [50 Gold]\n6. Cancel\n";
        cin >> choice;
        if (choice != 6)
        {
            cout << "How many would you like? (Enter a positive integer)\n";
            cin >> amount;
            player.buyWeapon(choice-1, amount);
        }
    }
    void buyArmor()
    {
        int amount;
        cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel)\n";
        cin >> amount;
        if (amount != 0)
            player.buyArmor(amount);
    }
    void sellTreasures()
    {
        player.sellTreasure();
    }
    void merchantMenu()
    {
        int choice;
        cout << "If you're looking to get supplies, you've come to the right place.\nI would be happy to part with some of my wares...for the proper price!\n";
        do
        {
            player.inventory();
            cout << "Choose one of the following:\n1. Ingredients: To make food, you have to cook raw ingredients.\n2. Cookware: You will need something to cook those ingredients.\n";
            cout << "3. Weapons: It's dangerous to go alone, take this!\n4. Armor: If you want to survive monster attacks, you will need some armor.\n5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.\n";
            cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                buyIngredients();
                break;
            case 2:
                buyCookware();
                break;
            case 3:
                buyWeapon();
                break;
            case 4:
                buyArmor();
                break;
            case 5:
                sellTreasures();
                break;
            }
        } while (choice != 6);
    }
    void status()
    {
        cout << "+-------------+\n| STATUS      |\n+-------------+\n";
        cout << "| Rooms Cleare| " << player.roomsCleared << endl;
        cout << "|     Keys    | " << player.getKey() << endl;
        cout << "| Anger Level | " << angerLevel << endl;
        cout << "+-------------+\n";
        player.inventory();
        player.companionStatus();
    }
    void generateMap()
    {
        map.addRoom(2, 3);
        map.addRoom(8, 11);
        map.addRoom(2, 7);
        map.addRoom(8, 2);
        map.addRoom(5, 7);
        map.addNPC(4, 4);
        map.addNPC(1, 2);
        map.addNPC(7, 2);
        map.addNPC(10, 4);
        map.addNPC(9, 0);
    }
    void freeSpace()
    {
        int choice;
        char direction;
        cout << "Select one:\n1. Move\n2. Investigate\n3. Pick a Fight\n4. Cook and Eat\n5. Give up\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Use wasd for up,left,down,right respectively:\n";
            cin >> direction;
            map.move(direction);
            player.move();
            break;
        case 2:
            if (map.isExplored(map.getPlayerRow(), map.getPlayerCol()))
            {
                cout << "This part of the map has already been explored.\n";
            }
            else
            {
                int r1 = (rand() % 100) + 1;
                if (r1 <= 10)
                {
                    player.addKey();
                    player.hunger();
                }
                if (r1 > 10 && r1 < 31)
                {
                    player.addTreasure();
                    player.hunger();
                }
                if (r1 > 30 && r1 < 51)
                {
                    if (player.attackEnemy(monsterlist.monsters.at(0)->level))
                    {
                        monster++;
                    }
                }
            }
            break;
        case 3:
            if (player.attackEnemy(monsterlist.monsters.at(0)->level))
            {
                monsterlist.monsters.erase(monsterlist.monsters.begin());
            }
            break;
        case 4:
            player.cookMeal();
            break;
        case 5:
            gaveUp = true;
            cout << "Its unfortunate, you were unable to get out of the dungeon.\nGAME OVER\n";
        }
    }
    void roomSpace()
    {
        int choice;
        char direction;
        bool flag, cantEnter = true;
        int rps, pc;
        cout << "Select one:\n1. Move\n2. Open the door\n3. Give Up\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Use wasd for up,left,down,right respectively:\n";
            cin >> direction;
            map.move(direction);
            player.move();
            break;
        case 2:
            do
            {
                if (player.getKey() == 0)
                {
                    cout << "Unfortunately you dont have a key\nYou would have to engage in a boulder/paper/shears puzzle\n";
                    for (int i = 0; i < 3; i++)
                    {
                        cout << "Choose:\n1. Rock\n2. Paper\n3. Shears\n";
                        cin >> rps;
                        pc = (rand() % 3) + 1;
                        if (pc == rps)
                        {
                            cout << "Its a tie\n";
                        }
                        else if (rps == 1 && pc == 3)
                        {
                            cout << "You won!!!\n";
                            cantEnter = false;
                            break;
                        }
                        else if (rps == 2 && pc == 1)
                        {
                            cout << "You won!!!\n";
                            cantEnter = false;
                            break;
                        }
                        else if (rps == 3 && pc == 2)
                        {
                            cout << "You won!!!\n";
                            cantEnter = false;
                            break;
                        }
                        else
                        {
                            cout << "You lost this round" << endl;
                        }
                        cantEnter = true;
                    }
                    if (!cantEnter)
                    {
                        int r1;
                        for (int i = 0; i < monsterlist.monsters.size(); i++)
                        {
                            if ((monsterlist.monsters.at(i)->level) + 2 == player.roomsCleared)
                            {
                                flag = player.attackEnemy(monsterlist.monsters.at(i)->level);
                                if (flag)
                                {
                                    monsterlist.monsters.erase(monsterlist.monsters.begin() + i);
                                    r1 = (rand() % 10) + 1;
                                    if (r1 < 7)
                                        player.misfortune();
                                    player.roomCleared();
                                    map.removeRoom(map.getPlayerRow(), map.getPlayerCol());
                                }
                                else
                                {
                                    r1 = (rand() % 10) + 1;
                                    if (r1 < 5)
                                        player.misfortune();
                                    player.useKey();
                                }
                                break;
                            }
                        }
                        if (flag)
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << "You lost the puzzle.\n";
                        player.killCompanion();
                        break;
                    }
                }
                else
                {
                    int r1;
                    for (int i = 0; i < monsterlist.monsters.size(); i++)
                    {
                        if ((monsterlist.monsters.at(i)->level) + 2 == player.roomsCleared)
                        {
                            flag = player.attackEnemy(monsterlist.monsters.at(i)->level);
                            if (flag)
                            {
                                monsterlist.monsters.erase(monsterlist.monsters.begin() + i);
                                r1 = (rand() % 10) + 1;
                                if (r1 < 7)
                                    player.misfortune();
                                player.roomCleared();
                                map.removeRoom(map.getPlayerRow(), map.getPlayerCol());
                            }
                            else
                            {
                                r1 = (rand() % 10) + 1;
                                if (r1 < 5)
                                    player.misfortune();
                                player.useKey();
                            }
                            break;
                        }
                    }
                    if (flag)
                    {
                        break;
                    }
                }
            } while (true);
            break;
        case 3:
            gaveUp = true;
            cout << "Its unfortunate, you were unable to get out of the dungeon.\nGAME OVER\n";
            break;
        }
    }
    void npcSpace()
    {
        int choice;
        int r1;
        char direction;
        string ans;
        bool flag, cantEnter = true;
        int rps, pc;
        cout << "Select one:\n1. Move\n2. Speak to NPC\n3. Give Up\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Use wasd for up,left,down,right respectively:\n";
            cin >> direction;
            map.move(direction);
            player.move();
            break;
        case 2:
            cout << "Yo! if you want me to sell you stuff answer a riddle for me.\n";
            r1 = (rand() % 20);
            cout << riddlelist.riddles.at(r1)->riddle << endl;
            cin >> ans;
            if (ans == riddlelist.riddles.at(r1)->ans)
            {
                cout << "Noice! Would you want to buy/sell stuff? (y/n)" << endl;
                cin >> direction;
                if (direction == 'y' || direction == 'Y')
                {
                    merchantMenu();
                }
            }
            else
            {
                cout << "You failed my test now you must face me wrath!!!!\n";
                for (int i = 0; i < monsterlist.monsters.size(); i++)
                {
                    if (monsterlist.monsters.at(i)->level == player.getRooms())
                    {
                        player.attackEnemy(monsterlist.monsters.at(i)->level);
                    }
                }
            }
            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
            break;
        case 3:
            gaveUp = true;
            cout << "Its unfortunate, you were unable to get out of the dungeon.\nGAME OVER\n";
            break;
        }
    }
    void move()
    {
        char direction;
        cout << "Use wasd for up,left,down,right respectively:\n";
        cin >> direction;
        map.move(direction);
        player.move();
    }
};

int main()
{
    Game game;
    game.generateMap();
    cout << "Welcome to Dungeons and Dragons\n";
    cout << "Between the 5 of you, you have 100 gold pieces.\n";
    cout << "You will need to spend the some of your money on the following items:\n";
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients.\n- COOKWARE. If you want to cook, you have to have cookware first.\n";
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters.\n- ARMOR. Armor increases the chances of surviving a monster attack.\n";
    game.merchantMenu();
    do
    {
        game.status();
        game.map.displayMap();
        game.angerLevel++;
        if (game.map.isFreeSpace(game.map.getPlayerRow(), game.map.getPlayerCol()))
        {
            game.freeSpace();
        }
        else if (game.map.isRoomLocation(game.map.getPlayerRow(), game.map.getPlayerCol()))
        {
            game.roomSpace();
        }
        else if (game.map.isNPCLocation(game.map.getPlayerRow(), game.map.getPlayerCol()))
        {
            game.npcSpace();
        }
        else if (game.map.isFreeSpace(game.map.getPlayerRow(), game.map.getPlayerCol()))
        {
            game.angerLevel--;
            cout<<"Location already explored.\n";
            game.move();
        }
        else
        {
            if(game.player.getRooms() == 5)
            {
                if(game.player.companions.size() > 0)
                {
                    cout<<"Congratulations!!! You clear the dungeon and came out alive.\n";
                    break;
                }
            }
        }
        if(game.player.companions.size() == 0)
        {
            cout<<"You have no companions left.\nGAME OVER\n";
            break;
        }
        if(game.player.getFullness() == 0)
        {
            cout<<"You died of startvation.\nGAME OVER\n";
            break;
        }
        if(game.angerLevel == 100)
        {
            cout<<"OH NOOOO!!! The sorcerors anger level has reached its peak. They unleashed thier wrath crushing the dungeon.\nGAME OVER\n";
            break;
        }
        if(game.gaveUp)
        {
            break;
        }
    } while (true);
    return 0;
}