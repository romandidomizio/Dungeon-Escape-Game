#include "Player.h"

Player::Player()
{
    name = "Anonymous";
    gold = 100;
    ingredients = 0;
    armor = 0;
    numberOfCompanions = 4;
    fullness = 50;
    keys = 0;
    roomsCleared = 0;
    string array[] = {"Waldo", "Naruto", "Jhon", "Daldar"};
    for (string s : array)
    {
        companions.push_back(new Companion(s));
    }
    cookware[0] = new Cookware("Ceramic Pot", 2, 25, 'P');
    cookware[1] = new Cookware("Frying Pan", 10, 10, 'F');
    cookware[2] = new Cookware("Cauldron", 20, 2, 'C');
    weapons[0] = new Weapon("Stone Club", 0, 2, 'C');
    weapons[1] = new Weapon("Iron Spear", 0, 2, 'I');
    weapons[2] = new Weapon("Mythril Rapier", 1, 5, 'R');
    weapons[3] = new Weapon("Flaming Battle-Axe", 2, 15, 'B');
    weapons[4] = new Weapon("Vorpal Longsword", 3, 50, 'L');
    treasures[0] = new Treasure("Silver ring", 10, 'R');
    treasures[1] = new Treasure("Ruby necklace", 20, 'N');
    treasures[2] = new Treasure("Emerald bracelet", 30, 'B');
    treasures[3] = new Treasure("Diamond circlet", 40, 'C');
    treasures[4] = new Treasure("Gem-encrusted goblet", 50, 'G');
}

void Player::buyCookware(int cw, int amount)
{
    if (amount * cookware[cw]->getPrice() > gold)
    {
        cout << "You dont have enough gold to purchase " << amount << " " << cookware[cw]->getName() << "(s)!\n";
        return;
    }
    cout << "You want to buy " << amount << " " << cookware[cw]->getName() << "(s) for " << amount * cookware[cw]->getPrice() << " Gold? (y/n)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        cookware[cw]->count += amount;
        gold -= amount * cookware[cw]->getPrice();
        cout << "Thank you for your patronage! What else can I get for you?\n";
    }
}
void Player::buyArmor(int amount)
{
    if (amount * 5 > gold)
    {
        cout << "You dont have enough gold to purchase " << amount << " suits of armor->\n";
        return;
    }
    cout << "You want to buy " << amount << " suit(s) of armor for " << amount * 5 << " Gold? (y/n)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        armor += amount;
        gold -= amount * 5;
        cout << "Thank you for your patronage! What else can I get for you?\n";
    }
}
void Player::buyIngredients(int amount)
{
    if (amount > gold)
    {
        cout << "You dont have enough gold to purchase " << amount << "kgs of ingredients->\n";
        return;
    }
    cout << "You want to buy " << amount << " kgs of ingredients-> " << amount << " Gold? (y/n)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        ingredients += amount;
        gold -= amount;
        cout << "Thank you for your patronage! What else can I get for you?\n";
    }
}
void Player::buyWeapon(int w, int amount)
{
    if (amount * weapons[w]->getPrice() > gold)
    {
        cout << "You dont have enough gold to purchase " << amount << " " << weapons[w]->getName() << "(s)!\n";
        return;
    }
    cout << "You want to buy " << amount << " " << weapons[w]->getName() << "(s) for " << amount * weapons[w]->getPrice() << " Gold? (y/n)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        weapons[w]->count += amount;
        gold -= amount * weapons[w]->getPrice();
        cout << "Thank you for your patronage! What else can I get for you?\n";
    }
}
void Player::sellTreasure()
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        count += treasures[i]->count;
    }
    if (count == 0)
    {
        cout << "You dont have any treasures in your inventory!\n";
        return;
    }
    int i = 1;
    int choice;
    cout << "Treasures in your inventory:\n";
    for (Treasure *t : treasures)
    {
        cout << i << "-> " << t->count << " " << t->toString() << endl;
        i++;
    }
    cin >> choice;
    i = choice - 1;
    cout << "How much " << treasures[i]->getName() << " would u want to sell? (1 - " << treasures[i]->count << ")\n";
    cin >> choice;
    cout << "Sell " << treasures[i]->getName() << " for " << choice * treasures[i]->getPrice() << " Gold? (y/n)\n";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        treasures[i]->count -= choice;
        gold += choice * treasures[i]->getPrice();
        cout << "Thank you for your patronage! What else can I get for you?\n";
    }
}
int Player::getKey()
{
    return keys;
}
void Player::addKey()
{
    cout << "Superb you found a key!!\n";
    keys++;
}
void Player::addTreasure()
{
    cout << "Noice you found a " << treasures[roomsCleared - 1]->getName() << "\n";
    treasures[roomsCleared - 1]->count++;
}
bool Player::attackEnemy(int challengeRating)
{
    srand(time(0));
    int w = 0, a, r1, r2;
    for (int i = 0; i < 5; i++)
    {
        w += weapons[i]->count;
        if (i > 1)
        {
            if (weapons[i]->count != 0)
            {
                w += weapons[i]->getSpecialBonus();
            }
        }
    }
    if (w == 0)
    {
        cout << "You need atleast 1 weapon to fight a monster!\n";
        return false;
    }
    a = armor;
    r1 = (rand() % (6 - 1 + 1)) + 1;
    r2 = (rand() % (6 - 1 + 1)) + 1;
    int result = (r1 * w + 4) - ((r2 * challengeRating) / a);
    if (result > 0)
    {
        cout << "Hooray! you have won the battle againts the monster\n You get " << 10 * challengeRating << " Gold and " << 5 * challengeRating << "kgs of ingredients\n";
        gold += 10 * challengeRating;
        ingredients += 5 * challengeRating;
        r1 = (rand() % 10) + 1;
        if (r1 == 1)
        {
            cout << "Superb the monster droped a key!!\n";
            keys++;
        }
        hunger();
        return true;
    }
    else
    {
        int temp = gold / 4;
        gold -= temp;
        ingredients -= 30;
        if (ingredients < 0)
            ingredients *= -1;
        cout << "You lost the battle againts the monster\n You lost " << temp << " Gold and 30 kgs of ingredients\n";
        for (int i = 0; i < companions.size(); i++)
        {
            r1 = (rand() % 10) + 1;
            if (r1 == 1)
            {
                cout << "Ooohh NO !!! " << companions.at(i)->name << " was slain by the monster. poor fella\n";
                companions.erase(companions.begin() + i);
                continue;
            }
        }
        hunger();
        return false;
    }
}
int Player::getFullness()
{
    return fullness;
}
void Player::useKey()
{
    keys--;
}
void Player::killCompanion()
{
    cout << "Ooohh NO !!! " << companions.at(companions.size() - 1)->name << " was lost. poor fella\n";
    companions.pop_back();
}
void Player::hunger()
{
    int r1;
    for (int i = 0; i < companions.size(); i++)
    {
        r1 = (rand() % 2) + 1;
        if (r1 == 1)
        {
            companions.at(i)->fullness -= 1;
        }
    }
    r1 = (rand() % 2) + 1;
    if (r1 == 1)
    {
        fullness -= 1;
    }
}
void Player::cookMeal()
{
    if (ingredients <= 0)
    {
        cout << "Your out of ingredients to cook with\n";
        return;
    }
    int choice, ingre;
    do
    {
        cout << "Select a cookware item to cook with:\n";
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << cookware[i]->count << " of " << cookware[i]->getName() << endl;
        }
        cin >> choice;
        choice--;
        if (cookware[choice]->count == 0)
        {
            cout << "You dont this item\n";
            continue;
        }
    } while (cookware[choice]->count == 0);
    do
    {
        cout << "How many kgs of ingredients you want to cook? (ingredients = " << ingredients << "):\n";
        cin >> ingre;
        if (ingre > ingredients)
        {
            cout << "You dont have enough ingredients\n";
            continue;
        }
    } while (ingre > ingredients);
    int limit = (rand() % 100) + 1;
    bool flag = false;
    if (limit <= cookware[choice]->getbreakProbability())
    {
        cout << "Oops! looks like your trusty cookware broke.\n";
        cookware[choice]->count--;
    }
    else
    {
        cout << "The meal was created succesfully.\n";
        for (int i = 0; i < companions.size(); i++)
        {
            companions.at(i)->fullness += ingre / 5;
        }
        fullness += ingre / 5;
    }
}
void Player::surrender()
{
    cout << "Ooohh NO !!! " << companions.at(companions.size() - 1)->name << " was held captive by the monster. poor fella\n";
    companions.pop_back();
    int r1;
    for (int i = 0; i < companions.size(); i++)
    {
        r1 = (rand() % 2) + 1;
        if (r1 == 1)
        {
            companions.at(i)->fullness -= 1;
        }
    }
    r1 = (rand() % 2) + 1;
    if (r1 == 1)
    {
        fullness -= 1;
    }
}
void Player::move()
{
    int r1;
    for (int i = 0; i < companions.size(); i++)
    {
        r1 = (rand() % 100) + 1;
        if (r1 < 21)
        {
            companions.at(i)->fullness -= 1;
            if (companions.at(i)->fullness < 2)
            {
                cout << "Warning: " << companions.at(i)->name << " is on the brink of starvation!\nYou should cook and eat some food!\n";
            }
            if (companions.at(i)->fullness == 0)
            {
                cout << "OH NO! " << companions.at(i)->name << " died of starvation.\n";
                companions.erase(companions.begin() + i);
            }
        }
    }
    r1 = (rand() % 2) + 1;
    if (r1 < 21)
    {
        fullness -= 1;
    }
}
void Player::inventory()
{
    cout << "+-------------+\n| INVENTORY   |\n+-------------+\n| Gold        | " << gold << "\n| Ingredients | " << ingredients << " kg\n";
    cout << "| Cookware    | P: " << cookware[0]->count << " | F: " << cookware[1]->count << " | C: " << cookware[2]->count << endl;
    cout << "| Weapons     | C: " << weapons[0]->count << " | S: " << weapons[1]->count << " | R: " << weapons[2]->count << " | B: " << weapons[3]->count << " | L: " << weapons[4]->count << endl;
    cout << "| Armor       | " << armor << endl;
    cout << "| Treasures   | R: " << treasures[0]->count << " | N: " << treasures[1]->count << " | B: " << treasures[2]->count << " | C: " << treasures[3]->count << " | G: " << treasures[4]->count << endl;
    cout << "+-------------+\n";
}
void Player::companionStatus()
{
    cout << "+-------------+\n|    PARTY    |\n+-------------+\n";
    cout << "| " << name << "| Fullness: " << fullness << endl;
    for (int i = 0; i < companions.size(); i++)
    {
        cout << "| " << companions.at(i)->name << "| Fullness: " << companions.at(0)->fullness << endl;
    }
    cout << "+-------------+\n";
}

int Player::getRooms()
{
    return roomsCleared;
}

void Player::roomCleared()
{
    roomsCleared++;
}

void Player::misfortune()
{
    int r1 = (rand() % 100) + 1;
    int r2, count = 0;
    if (r1 <= 10)
    {
        for (int i = 0; i < 5; i++)
        {
            if (weapons[i]->count > 0)
            {
                count = 1;
                break;
            }
        }
        if (count == 0)
            return;
        do
        {
            r2 = (rand() % 5);
            if (weapons[r2]->count > 0)
            {
                weapons[r2]->count--;
                cout << "OH NO! Your " << weapons[r2]->getName() << " broke" << endl;
                break;
            }
        } while (true);
    }
    else if (r1 > 10 && r1 < 41)
    {
        cout << "OH NO! Your team was robbed by dungeon bandits!\n";
        r2 = (rand() % 3) + 1;
        switch (r2)
        {
        case 1:
            cout << "You lost 10kg ingredients.\n";
            ingredients -= 10;
            if (ingredients < 0)
                ingredients *= -1;
            break;
        case 2:
            r2 = (rand() % 3);
            if (cookware[r2]->count > 0)
                cookware[r2]->count -= 1;
            cout << "You lost 1 " << cookware[r2]->getName() << endl;
            break;
        case 3:
            if (armor > 0)
            {
                armor -= 1;
                cout << "You lost 1 armor\n";
            }
            break;
        }
    }
    else if (r1 > 40 && r1 < 71)
    {
        r2 = (rand() % 4);
        companions.at(r2)->fullness -= 10;
        cout << "OH NO! " << companions.at(r2)->name << " got food poisoning.\n";
        if (companions.at(r2)->fullness <= 0)
        {
            cout << "Unfortunately " << companions.at(r2)->name << " died of food poisoning.\n";
            companions.erase(companions.begin() + r2);
        }
    }
    else
    {
    }
}