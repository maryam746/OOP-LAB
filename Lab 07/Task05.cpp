#include <iostream>
#include <string>

using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon = "")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks with " << weaponType << endl;
    }

    virtual void defend() {
        cout << name << " defends with a shield!" << endl;
    }

    virtual void displayStats() const {
        cout << "Character ID: " << characterID << "\nName: " << name << "\nLevel: " << level
             << "\nHealth: " << healthPoints << "\nWeapon: " << (weaponType.empty() ? "None" : weaponType) << endl;
    }

    virtual ~Character() {}
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " swings sword with " << meleeDamage << " damage!" << endl;
    }

    void displayStats() const override {
        Character::displayStats();
        cout << "Armor Strength: " << armorStrength << "\nMelee Damage: " << meleeDamage << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, string weapon, int mana, int power)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}

    void defend() override {
        cout << name << " casts a magical barrier with " << manaPoints << " mana!" << endl;
    }

    void displayStats() const override {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints << "\nSpell Power: " << spellPower << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, int accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        cout << name << " shoots an arrow with " << rangedAccuracy << "% accuracy!" << endl;
    }

    void displayStats() const override {
        Character::displayStats();
        cout << "Arrow Count: " << arrowCount << "\nRanged Accuracy: " << rangedAccuracy << "%" << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, string weapon, int stealth, int agi)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}

    void displayStats() const override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << endl;
    }
};

int main() {
    Warrior w1(1, "Thor", 10, 150, "Hammer", 80, 120);
    Mage m1(2, "Gandalf", 12, 100, "Staff", 150, 200);
    Archer a1(3, "Legolas", 15, 90, "Bow", 50, 85);
    Rogue r1(4, "Loki", 13, 80, "Daggers", 95, 110);

    cout << "--- Warrior Stats ---\n";
    w1.attack();
    w1.displayStats();

    cout << "\n--- Mage Stats ---\n";
    m1.defend();
    m1.displayStats();

    cout << "\n--- Archer Stats ---\n";
    a1.attack();
    a1.displayStats();

    cout << "\n--- Rogue Stats ---\n";
    r1.displayStats();

    return 0;
}
