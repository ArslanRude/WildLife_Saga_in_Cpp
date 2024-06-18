#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void list_show(int, int, string[], int, int);
void regester();
void login();
void start_game();
void how_to_paly();
void game();
int round_select();
void buy_animals(int);
void game_list(int);
void buy_food(int);
void sell_animals(int);
void feed_animals(int);
void feed_phoenix(int);
void feed_titan(int);
void feed_yeti(int);
void feed_werewolf(int);
void feed_griffin(int);
void get_name(int);
void winner();
void loading(string);
void header();

class Game
{
public:
    void login_selection();
};
class Player
{
public:
    static string Players[4];
    static double money[4];
    static void initial_money();
};
class Store : public Player
{
public:
    virtual void buy_one(int) = 0;
};
class Animals : public Store
{
protected:
    int HP, price;
    int phoenix, griffin, yeti, titan, werewolf;

public:
    string name[5] = {
        "Phoenix",
        "Titan",
        "Yeti",
        "WereWolf",
        "Griffin",
    };
    Animals()
    {
        HP = 0;
        phoenix = 0;
        griffin = 0;
        yeti = 0;
        titan = 0;
        werewolf = 0;
    }
    void decrement_hp(int dec)
    {
        HP -= dec;
        if (HP < 1)
        {
            HP = 0;
        }
    }
    virtual void sell_one(int) = 0;
    virtual int get_count() = 0;
    virtual int get_hp() = 0;
};
class Food : public Store
{
protected:
    string name[5] = {
        "Flaming Crystal",
        "Ambrosia",
        "Purple Diamond",
        "Glowing Pearls",
        "Jade"};

public:
    int flaming_crystal, ambrosia, purple_diamond, glowing_pearls, jade;
    Food()
    {
        flaming_crystal = 0;
        ambrosia = 0;
        purple_diamond = 0;
        glowing_pearls = 0;
        jade = 0;
    }

    virtual int get_food() = 0;
};
class Phoenix : public Animals
{
public:
    void decrement_phoenix()
    {
        phoenix = 0;
    }
    void buy_one(int i)
    {
        phoenix++;
        HP += 100;
        money[i] -= 1000;
    }
    void sell_one(int i)
    {
        phoenix--;
        money[i] += (10 * HP);
        HP = 0;
    }
    int get_count()
    {
        return phoenix;
    }
    int get_hp()
    {
        return HP;
    }
    void feed_flaming()
    {
        HP += 10;
    }
    void feed_ambrosia()
    {
        HP += 7;
    }
    void feed_glowing()
    {
        HP += 3;
    }
};
class Titan : public Animals
{
public:
    void decrement_titan()
    {
        titan = 0;
    }
    void buy_one(int i)
    {
        titan++;
        HP += 100;
        money[i] -= 800;
    }
    void sell_one(int i)
    {
        titan--;
        money[i] += (8 * HP);
        HP = 0;
    }
    int get_count()
    {
        return titan;
    }
    int get_hp()
    {
        return HP;
    }
    void feed_ambrosia()
    {
        HP += 10;
    }
    void feed_flaming()
    {
        HP += 7;
    }
    void feed_purple()
    {
        HP += 5;
    }
};
class Yeti : public Animals
{
public:
    void decrement_yeti()
    {
        yeti = 0;
    }
    void buy_one(int i)
    {
        yeti++;
        HP += 100;
        money[i] -= 600;
    }
    void sell_one(int i)
    {
        yeti--;
        money[i] += (6 * HP);
        HP = 0;
    }
    int get_count()
    {
        return yeti;
    }
    int get_hp()
    {
        return HP;
    }
    void feed_purple()
    {
        HP += 10;
    }
    void feed_ambrosia()
    {
        HP += 7;
    }
    void feed_jade()
    {
        HP += 5;
    }
};
class WereWolf : public Animals
{
public:
    void decrement_werewolf()
    {
        werewolf = 0;
    }
    void buy_one(int i)
    {
        werewolf++;
        HP += 100;
        money[i] -= 400;
    }
    void sell_one(int i)
    {
        werewolf--;
        money[i] += (4 * HP);
        HP = 0;
    }
    int get_count()

    {
        return werewolf;
    }
    int get_hp()
    {
        return HP;
    }
    void feed_glowing()
    {
        HP += 10;
    }
    void feed_purple()
    {
        HP += 10;
    }
    void feed_jade()
    {
        HP += 6;
    }
};
class Griffin : public Animals
{
public:
    void decrement_griffin()
    {
        griffin = 0;
    }
    void buy_one(int i)
    {
        griffin++;
        HP += 100;
        money[i] -= 200;
    }
    void sell_one(int i)
    {
        griffin--;
        money[i] += (2 * HP);
        HP = 0;
    }
    int get_count()
    {
        return griffin;
    }
    int get_hp()
    {
        return HP;
    }
    void feed_jade()
    {
        HP += 10;
    }
    void feed_flaming()
    {
        HP += 12;
    }
    void feed_glowing()
    {
        HP += 8;
    }
};
class Flaming_Crystal : public Food
{
public:
    void buy_one(int i)
    {
        flaming_crystal++;
        money[i] -= 500;
    }
    int get_food()
    {
        return flaming_crystal;
    }
};
class Ambrosia : public Food
{
public:
    void buy_one(int i)
    {
        ambrosia++;
        money[i] -= 400;
    }
    int get_food()
    {
        return ambrosia;
    }
};
class Purple_Diamond : public Food
{
public:
    void buy_one(int i)
    {
        purple_diamond++;
        money[i] -= 300;
    }
    int get_food()
    {
        return purple_diamond;
    }
};
class Glowing_Pearls : public Food
{
public:
    void buy_one(int i)
    {
        glowing_pearls++;
        money[i] -= 200;
    }
    int get_food()
    {
        return glowing_pearls;
    }
};
class Jade : public Food
{
public:
    void buy_one(int i)
    {
        jade++;
        money[i] -= 100;
    }
    int get_food()
    {
        return jade;
    }
};

Phoenix phoenix[4];
Titan titan[4];
Yeti yeti[4];
WereWolf werewolf[4];
Griffin griffin[4];
Flaming_Crystal flaming_crystal[4];
Ambrosia ambrosia[4];
Purple_Diamond purple_diamond[4];
Glowing_Pearls glowing_pearls[4];
Jade jade[4];

double Player::money[4] = {0, 0, 0, 0};
string Player::Players[4];
int main()
{
    Game obj;
    obj.login_selection();
    return 0;
}

void list_show(int choice, int size, string menu[], int print = 0, int player_no = 0)
{
    system("CLS");
    header();
    if (print)
    {
        SetConsoleTextAttribute(h, 12);
        cout << "Player : ";
        SetConsoleTextAttribute(h, 10);
        cout << Player::Players[player_no];
        SetConsoleTextAttribute(h, 12);
        cout << "\t\tYour Money is : ";
        SetConsoleTextAttribute(h, 10);
        cout << Player::money[player_no] << endl;
        SetConsoleTextAttribute(h, 12);
        cout << "Animals\t Count\t HP" << endl;
        cout << "\nPhoenix : ";
        SetConsoleTextAttribute(h, 10);
        cout << phoenix[player_no].get_count() << "\t " << phoenix[player_no].get_hp() << "%" << endl;
        SetConsoleTextAttribute(h, 12);
        cout << "Titan   : ";
        SetConsoleTextAttribute(h, 10);
        cout << titan[player_no].get_count() << "\t " << titan[player_no].get_hp() << "%" << endl;
        SetConsoleTextAttribute(h, 12);
        cout << "Yeti    : ";
        SetConsoleTextAttribute(h, 10);
        cout << yeti[player_no].get_count() << "\t " << yeti[player_no].get_hp() << "%" << endl;
        SetConsoleTextAttribute(h, 12);
        cout << "WereWolf: ";
        SetConsoleTextAttribute(h, 10);
        cout << werewolf[player_no].get_count() << "\t " << werewolf[player_no].get_hp() << "%" << endl;
        SetConsoleTextAttribute(h, 12);
        cout << "Griffin : ";
        SetConsoleTextAttribute(h, 10);
        cout << griffin[player_no].get_count() << "\t " << griffin[player_no].get_hp() << "%" << endl;
        SetConsoleTextAttribute(h, 12);
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
        SetConsoleTextAttribute(h, 7);
    }
    int i = 0;
    while (i < size)
    {
        if (choice == i + 1)
        {
            cout << "\n";
            SetConsoleTextAttribute(h, 12);
            cout << "\t\t\t\t\t\t" << menu[i];
            SetConsoleTextAttribute(h, 7);
        }
        else
        {
            cout << "\n";
            cout << "\t\t\t\t\t\t" << menu[i];
        }
        i++;
    }
}
void Game::login_selection()
{
    int i = 1, a = 0;
    string str[] = {"Registration", "Login", "Exit"};
    int size = sizeof(str) / sizeof(str[0]);
    int ch;
    while (a < 1)
    {
        list_show(i, size, str);
        switch (ch = getch())
        {
        case 72:
            if (i != 1)
            {
                i--;
            }
            else
            {
                i = 3;
            }
            list_show(i, size, str);
            break;
        case 80:
            if (i != 3)
            {
                i++;
            }
            else
            {
                i = 1;
            }
            list_show(i, size, str);
            break;
        case 13:
            system("CLS");
            switch (i)
            {
            case 1:
                regester();
                break;
            case 2:
                login();
                break;
            case 3:
                exit(0);
                break;
            }
            a++;
            break;

        default:
            break;
        }
    }
    game();
}
void regester()
{
    // -------------------------------------------Username---------------------------------
    string name, is_name_same, pass;
    char words;
    bool is_name_same_bool = false, is_word_match_bool;

    ifstream checkname("username.txt");

    do
    {
        system("CLS");
        header();
        SetConsoleTextAttribute(h, 12);
        cout<<"\n\t\t\t\t\t Enter your Username : ";
        SetConsoleTextAttribute(h, 7);
        getline(cin, name);
        is_name_same_bool = false;
        checkname.clear();
        checkname.seekg(0, ios::beg);
        while (checkname.eof() == 0)
        {
            getline(checkname, is_name_same);
            if (name == is_name_same)
            {
                is_name_same_bool = true;
                system("CLS");
                header();
                SetConsoleTextAttribute(h, 12);
                cout<<"\n\t\t\t\t\t This Username is already Taken ";
                SetConsoleTextAttribute(h, 7);
                Sleep(1000);
                break;
            }
        }
    } while (is_name_same_bool == 1);
    checkname.close();
    ofstream savename("username.txt", ios::app);
    savename << name << endl;
    savename.close();
    // ---------------------------------------Password---------------------------------------------------

    ifstream checkpassword("possible_word.txt");
B:
    system("CLS");
    header();
    SetConsoleTextAttribute(h, 12);
    cout << "\n\t\t\t\t\tUsable Words: A-Z, a-z, !, @, #, $, %, ^, &, *";
    cout << "\n\t\t\t\t\t\tCreat a Password : ";
    SetConsoleTextAttribute(h, 7);
    getline(cin, pass);
    for (int i = 0; i < pass.length(); i++)
    {
        is_word_match_bool = false;
        checkpassword.clear();
        checkpassword.seekg(0, ios::beg);
        while (checkpassword.eof() == 0)
        {

            checkpassword >> words;
            if (pass.at(i) == words)
            {
                is_word_match_bool = true;
                break;
            }
        }
        if (!(is_word_match_bool))
        {
            system("CLS");
            header();
            SetConsoleTextAttribute(h, 12);
            cout << "\n\t\t\t\t  These Words Are Not Usable For Password . ";
            SetConsoleTextAttribute(h, 7);
            Sleep(1000);
            goto B;
        }
    }
    checkpassword.close();
    ofstream savepassword("password.txt", ios::app);
    savepassword << pass << endl;
    savepassword.close();
    loading("Registering : ");
}
void login()
{
    string name, check_name;
    bool is_name_same_bool = false;
    ifstream checkusername("username.txt");
    do
    {
        system("CLS");
        header();
        SetConsoleTextAttribute(h, 12);
        cout << "\n\t\t\t\t\t\tEnter Your Username:";
        SetConsoleTextAttribute(h, 7);
        getline(cin, name);
        checkusername.clear();
        checkusername.seekg(0, ios::beg);
        while (checkusername.eof() == 0)
        {
            getline(checkusername, check_name);
            if (check_name == name)
            {
                is_name_same_bool = true;
                break;
            }
        }
        if (!(is_name_same_bool))
        {
            system("CLS");
            header();
            SetConsoleTextAttribute(h, 12);
            cout << "\n\t\t\t\t\t\tWronge Username. Try Again";
            SetConsoleTextAttribute(h, 7);
            Sleep(1000);
        }

    } while (!(is_name_same_bool));
    checkusername.close();

    string pass, check_pass;
    bool is_pass_same_bool = false;
    ifstream checkuserpass("password.txt");
    do
    {
        system("CLS");
        header();
        SetConsoleTextAttribute(h, 12);

        cout << "\n\t\t\t\t\t\tEnter Your Password:";
        SetConsoleTextAttribute(h, 7);
        getline(cin, pass);
        checkuserpass.clear();
        checkuserpass.seekg(0, ios::beg);
        while (checkuserpass.eof() == 0)
        {
            getline(checkuserpass, check_pass);
            if (check_pass == pass)
            {
                is_pass_same_bool = true;
                break;
            }
        }
        if (!(is_pass_same_bool))
        {
            system("CLS");
            header();
            SetConsoleTextAttribute(h, 12);
            cout << "\n\t\t\t\t\t\tWronge Password. Try Again";
            SetConsoleTextAttribute(h, 7);
            Sleep(1000);
        }

    } while (!(is_pass_same_bool));
    checkuserpass.close();
    loading("Logging In : ");
}
void game()
{
    Game obj;
    string str[] = {"How To Play", "Start Game", "Log Out"};
    int size = sizeof(str) / sizeof(str[0]);
    int ch, a = 0, i = 1;
    while (a < 1)
    {
        list_show(i, size, str);
        switch (ch = getch())
        {
        case 72:
            if (i != 1)
            {
                i--;
            }
            else
            {
                i = 3;
            }
            list_show(i, size, str);
            break;
        case 80:
            if (i != 3)
            {
                i++;
            }
            else
            {
                i = 1;
            }
            list_show(i, size, str);
            break;
        case 13:
            system("CLS");
            switch (i)
            {
            case 1:
                how_to_paly();
                break;
            case 2:
                start_game();
                break;
            case 3:
                obj.login_selection();
                break;
            }
            a++;
            break;

        default:
            break;
        }
    }
}
void how_to_paly()
{
    header();
    cout << "\n\n";
    SetConsoleTextAttribute(h, 10);
    cout << "Following shows how to play the game.\n\n";
    cout << "->When the game starts a random player is asked 2 questions\n";
    cout << "->Slect the number of players \n";
    cout << "->Select the number of rounds\n";
    cout << "->A total of 4 players can play this game of 5-30 rounds  \n";
    cout << "->All the players will be provided with the same amount of cash \n";
    cout << "->The amount of cash will also be decided by the first player \n";
    cout << "->In every round each player will be given four options out of which they can only select one every round \n";
    cout << "->In the first round it is compulosry to buy animals \n";
    cout << "->After first round 10% HP will decrease for all animals \n";
    cout << "->After each round their would be a 2% increase in the initial percentile of 10% HP decreasing \n for example (10,12,14,16) \n";
    cout << "->If the HP of your animal becomes 0% it will die\n";
    cout << "->For each animal their ia a specific food and 2 common food which increase its HP my 10% , 7% and 5%-3% respectively \n";
    cout << "->You have to find out which food is specific for your animal yourself \n";
    cout << "->After all the rounds have been played the animals will be converted into cash acoundring to their HP% \n";
    cout << "->The cash will be summed up and the player with the most amount of cash will win \n";
    cout << "->BEST OF LUCK";
    SetConsoleTextAttribute(h, 7);
    getch();
    game();
}
void start_game()
{
    header();
    SetConsoleTextAttribute(h, 12);
    cout << "\n\t\t\t\t\t Select How Many Players Will Play\n";
    SetConsoleTextAttribute(h, 7);
    Sleep(1000);
    string str[3] = {"  TWO   (2)", "  THREE (3)", "  FOUR  (4)"};
    int players;
    int i = 1, a = 0, ch;
    while (a < 1)
    {
        list_show(i, 3, str);
        switch (ch = getch())
        {
        case 72:
            if (i != 1)
            {
                i--;
            }
            else
            {
                i = 3;
            }
            list_show(i, 3, str);
            break;
        case 80:
            if (i != 3)
            {
                i++;
            }
            else
            {
                i = 1;
            }
            list_show(i, 3, str);
            break;
        case 13:
            system("CLS");
            switch (i)
            {
            case 1:
                players = 2;
                break;
            case 2:
                players = 3;
                break;
            case 3:
                players = 4;
                break;
            }
            a++;
            break;

        default:
            break;
        }
    }
    Player player[players];
    get_name(players);
    int rounds = round_select(), inc = 0, dec = 10;
    player[1].initial_money();
    for (int r = 0; r < rounds; r++)
    {
        header();
        cout << "\n\t\t\t\t\t\tRound " << r + 1;
        SetConsoleTextAttribute(h, 7);
        Sleep(1000);
        for (int player_no = 0; player_no < players; player_no++)
        {
            system("CLS");
            header();
            SetConsoleTextAttribute(h, 12);

            cout << "\n\t\t\t\t\t\tPlayer : " << player_no + 1;
            Sleep(1000);
            //        	-----------------------------------
            if (phoenix[player_no].get_hp() < 1)
            {
                phoenix[player_no].decrement_phoenix();
            }
            if (titan[player_no].get_hp() < 1)
            {
                titan[player_no].decrement_titan();
            }
            if (yeti[player_no].get_hp() < 1)
            {
                yeti[player_no].decrement_yeti();
            }
            if (werewolf[player_no].get_hp() < 1)
            {
                werewolf[player_no].decrement_werewolf();
            }
            if (griffin[player_no].get_hp() < 1)
            {
                griffin[player_no].decrement_griffin();
            }

            game_list(player_no);
            Player::money[player_no] += 500 + inc;
            
            if (phoenix[player_no].get_hp() > 0)
            {
                phoenix[player_no].decrement_hp(dec * phoenix[player_no].get_count());
            }
            if (titan[player_no].get_hp() > 0)
            {
                titan[player_no].decrement_hp(dec * titan[player_no].get_count());
            }

            if (yeti[player_no].get_hp() > 0)
            {
                yeti[player_no].decrement_hp(dec * yeti[player_no].get_count());
            }

            if (werewolf[player_no].get_hp() > 0)
            {
                werewolf[player_no].decrement_hp(dec * werewolf[player_no].get_count());
            }
            if (griffin[player_no].get_hp() > 0)
            {
                griffin[player_no].decrement_hp(dec * griffin[player_no].get_count());
            }
        }
        inc += 50;
        dec += 2;
    }
    winner();
}
void Player ::initial_money()
{
    header();
    SetConsoleTextAttribute(h, 12);
    cout << "\n\t\t\t\t\tSelect Your Initial Money.";
    SetConsoleTextAttribute(h, 7);
    Sleep(1000);
    string str[] = {"-> 600", "-> 1000", "-> 1500", "-> 2000", "-> 2500"};
    int i = 1, a = 0, ch;
    while (a < 1)
    {
        list_show(i, 5, str);
        switch (ch = getch())
        {
        case 72:
            if (i != 1)
            {
                i--;
            }
            else
            {
                i = 5;
            }
            break;
        case 80:
            if (i != 5)
            {
                i++;
            }
            else
            {
                i = 1;
            }
            break;
        case 13:
            system("CLS");
            switch (i)
            {
            case 1:
                for (int i = 0; i < 4; i++)
                {
                    money[i] = 600;
                }
                break;
            case 2:
                for (int i = 0; i < 4; i++)
                {
                    money[i] = 1000;
                }

                break;
            case 3:
                for (int i = 0; i < 4; i++)
                {
                    Player::money[i] = 1500;
                }

                break;
            case 4:
                for (int i = 0; i < 4; i++)
                {
                    money[i] = 2000;
                }

                break;
            case 5:
                for (int i = 0; i < 4; i++)
                {
                    money[i] = 2500;
                }
                break;
            }
            a++;
            break;
        default:
            break;
        }
    }
}
int round_select()
{
    header();
    SetConsoleTextAttribute(h, 12);

    cout << "\n\t\t\t\t   Select How Many Rounds Will You Play\n";
    SetConsoleTextAttribute(h, 7);
    Sleep(1000);
    string str[] = {"  -> 10", "  -> 15", "  -> 20", "  -> 25", "  -> 30"};
    int players;
    int i = 1, a = 0, ch;
    while (true)
    {
        list_show(i, 5, str);
        switch (ch = getch())
        {
        case 72:
            if (i != 1)
            {
                i--;
            }
            else
            {
                i = 5;
            }
            list_show(i, 5, str);
            break;
        case 80:
            if (i != 5)
            {
                i++;
            }
            else
            {
                i = 1;
            }
            list_show(i, 5, str);
            break;
        case 13:
            system("CLS");
            switch (i)
            {
            case 1:
                return 10;

            case 2:
                return 15;

            case 3:
                return 20;

            case 4:
                return 25;

            case 5:
                return 30;
            }

            break;

        default:
            break;
        }
    }
}
void game_list(int player_no)
{
    string str[] = {"Buy Max Animals", "Buy Max Food", "Feed Animals", "Sell Animals"};
    int i = 1, a = 0, ch;
    while (a < 1)
    {
        list_show(i, 4, str, 1, player_no);
        switch (ch = getch())
        {
        case 72:
            if (i != 1)
            {
                i--;
            }
            else
            {
                i = 4;
            }
            list_show(i, 4, str, 1, player_no);
            break;
        case 80:
            if (i != 4)
            {
                i++;
            }
            else
            {
                i = 1;
            }
            list_show(i, 4, str, 1, player_no);
            break;
        case 13:
            system("CLS");
            switch (i)
            {
            case 1:
                buy_animals(player_no);
                a++;
                break;
            case 2:
                buy_food(player_no);
                a++;
                break;
            case 3:
                feed_animals(player_no);
                a++;
                break;
            case 4:
                sell_animals(player_no);
                a++;
                break;
            }

            break;

        default:
            break;
        }
    }
}
void buy_animals(int player_no)
{
    string str[] = {"Phoenix  (1000)", "Titan    (800)", "Yeti     (600)", "WereWolf (400)", "Griffin  (200)"};
    int i = 1, a = 0, ch;
    while (Player::money[player_no] >= 200)
    {
        list_show(i, 5, str, 1, player_no);
        switch (ch = getch())
        {
        case 72:
            if (i != 1)
            {
                i--;
            }
            else
            {
                i = 5;
            }
            list_show(i, 5, str, 1, player_no);
            break;
        case 80:
            if (i != 5)
            {
                i++;
            }
            else
            {
                i = 1;
            }
            list_show(i, 4, str, 1, player_no);
            break;
        case 13:
            system("CLS");
            switch (i)
            {
            case 1:
                if (Player::money[player_no] >= 1000)
                {
                    phoenix[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 2:
                if (Player::money[player_no] >= 800)
                {
                    titan[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 3:
                if (Player::money[player_no] >= 600)
                {
                    yeti[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 4:
                if (Player::money[player_no] >= 400)
                {
                    werewolf[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 5:
                if (Player::money[player_no] >= 200)
                {
                    griffin[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 0:
            A:
                system("CLS");
                header();
                SetConsoleTextAttribute(h, 12);
                cout << "\n\t\t\t\t\t\tYour Money Is Not Enough .";
                SetConsoleTextAttribute(h, 7);
                Sleep(1000);
                break;
            }
            break;
        default:
            break;
        }
    }
}
void buy_food(int player_no)
{
    string str[] = {"Flaming Crystal (500)", "Ambrosia        (400)", "Purple Diamond  (300)", "Glowing Pearl   (200)", "Jade            (100)"};
    int i = 1, a = 0, ch;
    while (Player::money[player_no] >= 100)
    {
        list_show(i, 5, str, 1, player_no);
        switch (ch = getch())
        {
        case 72:
            if (i != 1)
            {
                i--;
            }
            else
            {
                i = 5;
            }
            list_show(i, 5, str, 1, player_no);
            break;
        case 80:
            if (i != 5)
            {
                i++;
            }
            else
            {
                i = 1;
            }
            list_show(i, 4, str, 1, player_no);
            break;
        case 13:
            system("CLS");
            switch (i)
            {
            case 1:
                if (Player::money[player_no] >= 500)
                {
                    flaming_crystal[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 2:
                if (Player::money[player_no] >= 400)
                {
                    ambrosia[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 3:
                if (Player::money[player_no] >= 300)
                {
                    purple_diamond[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 4:
                if (Player::money[player_no] >= 200)
                {
                    glowing_pearls[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 5:
                if (Player::money[player_no] >= 100)
                {
                    jade[player_no].buy_one(player_no);
                }
                else
                {
                    goto A;
                }
                break;
            case 0:
            A:
                system("CLS");
                header();
                SetConsoleTextAttribute(h, 12);

                cout << "\n\t\t\t\t\t\tYour Money Is Not Enough .";
                SetConsoleTextAttribute(h, 7);
                Sleep(1000);
                break;
            }
            break;

        default:
            break;
        }
    }
}
void sell_animals(int player_no)
{
    string str[] = {"Phoenix  " + to_string(phoenix[player_no].get_count()), "Titan    " + to_string(titan[player_no].get_count()), "Yeti     " + to_string(yeti[player_no].get_count()), "WereWolf " + to_string(werewolf[player_no].get_count()), "Griffin  " + to_string(griffin[player_no].get_count())};
    if (phoenix[player_no].get_count() > 0 || titan[player_no].get_count() > 0 || yeti[player_no].get_count() > 0 || werewolf[player_no].get_count() > 0 || griffin[player_no].get_count() > 0)
    {
        int i = 1, a = 0, ch;
        while (a < 1)
        {
            list_show(i, 5, str, 1, player_no);
            switch (ch = getch())
            {
            case 72:
                if (i != 1)
                {
                    i--;
                }
                else
                {
                    i = 5;
                }
                list_show(i, 5, str, 1, player_no);
                break;
            case 80:
                if (i != 5)
                {
                    i++;
                }
                else
                {
                    i = 1;
                }
                list_show(i, 4, str, 1, player_no);
                break;
            case 13:
                system("CLS");
                switch (i)
                {
                case 1:
                    if (phoenix[player_no].get_count() > 0)
                    {
                        phoenix[player_no].sell_one(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 2:
                    if (titan[player_no].get_count() > 0)
                    {
                        titan[player_no].sell_one(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 3:
                    if (yeti[player_no].get_count() > 0)
                    {
                        yeti[player_no].sell_one(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 4:
                    if (werewolf[player_no].get_count() > 0)
                    {
                        werewolf[player_no].sell_one(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 5:
                    if (griffin[player_no].get_count() > 0)
                    {
                        griffin[player_no].sell_one(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 0:
                A:
                    system("CLS");
                    header();
                    SetConsoleTextAttribute(h, 12);

                    cout << "\n\t\t\t\t\t\tYou Dont Have Any Animal .";
                    SetConsoleTextAttribute(h, 7);
                    Sleep(1000);
                    break;
                }
                break;

            default:
                break;
            }
        }
    }
    else
    {
        header();
        SetConsoleTextAttribute(h, 12);

        cout << "\t\t\t\t\t You Dont Have Any Animal" << endl;
        SetConsoleTextAttribute(h, 7);
        Sleep(500);
        game_list(player_no);
    }
}
void feed_animals(int player_no)
{
    string str[] = {"Phoenix  " + to_string(phoenix[player_no].get_count()), "Titan    " + to_string(titan[player_no].get_count()), "Yeti     " + to_string(yeti[player_no].get_count()), "WereWolf " + to_string(werewolf[player_no].get_count()), "Griffin  " + to_string(griffin[player_no].get_count())};
    int i = 1, a = 0, ch;
    if (phoenix[player_no].get_count() > 0 || titan[player_no].get_count() > 0 || yeti[player_no].get_count() > 0 || werewolf[player_no].get_count() > 0 || griffin[player_no].get_count() > 0)
    {
        while (a < 1)
        {
            list_show(i, 5, str);
            switch (ch = getch())
            {
            case 72:
                if (i != 1)
                {
                    i--;
                }
                else
                {
                    i = 5;
                }
                list_show(i, 5, str);
                break;
            case 80:
                if (i != 5)
                {
                    i++;
                }
                else
                {
                    i = 1;
                }
                list_show(i, 4, str);
                break;
            case 13:
                system("CLS");
                switch (i)
                {
                case 1:
                    if (phoenix[player_no].get_count())
                    {
                        feed_phoenix(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 2:
                    if (titan[player_no].get_count())
                    {
                        feed_titan(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 3:
                    if (yeti[player_no].get_count())
                    {

                        feed_yeti(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 4:
                    if (werewolf[player_no].get_count())
                    {

                        feed_werewolf(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 5:
                    if (griffin[player_no].get_count())
                    {
                        feed_griffin(player_no);
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 0:
                A:
                    system("CLS");
                    header();
                    SetConsoleTextAttribute(h, 12);

                    cout << "\n\t\t\t\t\t\tYou Dont Have This Animal.";
                    SetConsoleTextAttribute(h, 7);
                    Sleep(1000);
                    break;
                }
                break;

            default:
                break;
            }
        }
    }
    else
    {
        header();
        SetConsoleTextAttribute(h, 12);

        cout << "\t\t\t\t\t You Dont Have Any Animal" << endl;
        SetConsoleTextAttribute(h, 7);
        Sleep(500);
        game_list(player_no);
    }
}
void feed_phoenix(int player_no)
{
    if (flaming_crystal[player_no].flaming_crystal > 0 || ambrosia[player_no].ambrosia > 0 || glowing_pearls[player_no].glowing_pearls > 0)
    {

        string str[] = {"Flaming Crystal " + to_string(flaming_crystal[player_no].get_food()), "Amborisa        " + to_string(ambrosia[player_no].get_food()), "Glowing Pearls  " + to_string(glowing_pearls[player_no].get_food())};
        int i = 1, a = 0, ch;
        while (a < 1)
        {
            list_show(i, 3, str);
            switch (ch = getch())
            {
            case 72:
                if (i != 1)
                {
                    i--;
                }
                else
                {
                    i = 3;
                }
                list_show(i, 3, str);
                break;
            case 80:
                if (i != 3)
                {
                    i++;
                }
                else
                {
                    i = 1;
                }
                list_show(i, 3, str);
                break;
            case 13:
                system("CLS");
                switch (i)
                {
                case 1:
                    if (flaming_crystal[player_no].flaming_crystal > 0)
                    {
                        phoenix[player_no].feed_flaming();
                        flaming_crystal[player_no].flaming_crystal = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 2:
                    if (ambrosia[player_no].ambrosia > 0)
                    {
                        phoenix[player_no].feed_ambrosia();
                        ambrosia[player_no].ambrosia = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 3:
                    if (glowing_pearls[player_no].glowing_pearls > 0)
                    {
                        phoenix[player_no].feed_glowing();
                        glowing_pearls[player_no].glowing_pearls = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 0:
                A:
                    system("CLS");
                    header();
                    SetConsoleTextAttribute(h, 12);

                    cout << "\n\t\t\t\t\t\tYou Dont Have This Food .";
                    SetConsoleTextAttribute(h, 7);
                    Sleep(1000);
                    break;
                }

                break;

            default:
                break;
            }
        }
    }
    else
    {
        header();
        SetConsoleTextAttribute(h, 12);

        cout << "\t\t\t\t\t You Dont Have Any Food Of This Animal" << endl;
        SetConsoleTextAttribute(h, 7);
        Sleep(500);
        game_list(player_no);
    }
}
void feed_titan(int player_no)
{
    if (purple_diamond[player_no].purple_diamond > 0 || ambrosia[player_no].ambrosia > 0 || flaming_crystal[player_no].flaming_crystal > 0)
    {
        string str[] = {"Amborisa        " + to_string(ambrosia[player_no].get_food()), "Purple Diamond  " + to_string(purple_diamond[player_no].get_food()), "Flaming Crystal " + to_string(flaming_crystal[player_no].get_food())};
        int i = 1, a = 0, ch;
        while (a < 1)
        {
            list_show(i, 3, str);
            switch (ch = getch())
            {
            case 72:
                if (i != 1)
                {
                    i--;
                }
                else
                {
                    i = 3;
                }
                list_show(i, 3, str);
                break;
            case 80:
                if (i != 3)
                {
                    i++;
                }
                else
                {
                    i = 1;
                }
                list_show(i, 3, str);
                break;
            case 13:
                system("CLS");
                switch (i)
                {
                case 1:
                    if (ambrosia[player_no].ambrosia > 0)
                    {

                        titan[player_no].feed_ambrosia();
                        ambrosia[player_no].ambrosia = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 2:
                    if (purple_diamond[player_no].purple_diamond > 0)
                    {
                        titan[player_no].feed_purple();
                        purple_diamond[player_no].purple_diamond = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 3:
                    if (flaming_crystal[player_no].flaming_crystal > 0)
                    {

                        titan[player_no].feed_flaming();
                        flaming_crystal[player_no].flaming_crystal = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 0:
                A:
                    system("CLS");
                    header();
                    SetConsoleTextAttribute(h, 12);

                    cout << "\n\t\t\t\t\t\tYou Dont Have This Food .";
                    SetConsoleTextAttribute(h, 7);
                    Sleep(1000);
                    break;
                }
                break;

            default:
                break;
            }
        }
    }
    else
    {
        header();
        SetConsoleTextAttribute(h, 12);

        cout << "\t\t\t\t\t You Dont Have Any Food Of This Animal" << endl;
        SetConsoleTextAttribute(h, 7);
        Sleep(500);
        game_list(player_no);
    }
}
void feed_yeti(int player_no)
{
    if (purple_diamond[player_no].purple_diamond > 0 || ambrosia[player_no].ambrosia > 0 || jade[player_no].jade > 0)
    {

        string str[] = {"Purple Diamond " + to_string(purple_diamond[player_no].get_food()), "Amborisa       " + to_string(ambrosia[player_no].get_food()), "Jade           " + to_string(jade[player_no].get_food())};
        int i = 1, a = 0, ch;
        while (a < 1)
        {
            list_show(i, 3, str);
            switch (ch = getch())
            {
            case 72:
                if (i != 1)
                {
                    i--;
                }
                else
                {
                    i = 3;
                }
                list_show(i, 3, str);
                break;
            case 80:
                if (i != 3)
                {
                    i++;
                }
                else
                {
                    i = 1;
                }
                list_show(i, 3, str);
                break;
            case 13:
                switch (i)
                {
                case 1:
                    if (purple_diamond[player_no].purple_diamond > 0)
                    {
                        yeti[player_no].feed_purple();
                        purple_diamond[player_no].purple_diamond = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }

                    break;
                case 2:
                    if (ambrosia[player_no].ambrosia > 0)
                    {
                        yeti[player_no].feed_ambrosia();
                        ambrosia[player_no].ambrosia = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }

                    break;
                case 3:
                    if (jade[player_no].jade > 0)
                    {

                        yeti[player_no].feed_jade();
                        jade[player_no].jade = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }

                    break;
                case 0:
                A:
                    system("CLS");
                    header();
                    SetConsoleTextAttribute(h, 12);

                    cout << "\n\t\t\t\t\t\tYou Dont Have This Food .";
                    SetConsoleTextAttribute(h, 7);
                    Sleep(1000);
                    break;
                }
                break;

            default:
                break;
            }
        }
    }
    else
    {
        header();
        SetConsoleTextAttribute(h, 12);

        cout << "\t\t\t\t\t You Dont Have Any Food Of This Animal" << endl;
        SetConsoleTextAttribute(h, 7);
        Sleep(500);
        game_list(player_no);
    }
}
void feed_werewolf(int player_no)
{
    if (jade[player_no].jade > 0 || purple_diamond[player_no].purple_diamond > 0 || glowing_pearls[player_no].glowing_pearls > 0)
    {

        string str[] = {"Glowing Pearls " + to_string(glowing_pearls[player_no].get_food()), "Purple Diamond " + to_string(purple_diamond[player_no].get_food()), "Jade           " + to_string(jade[player_no].get_food())};
        int i = 1, a = 0, ch;
        while (a < 1)
        {
            list_show(i, 3, str);
            switch (ch = getch())
            {
            case 72:
                if (i != 1)
                {
                    i--;
                }
                else
                {
                    i = 3;
                }
                list_show(i, 3, str);
                break;
            case 80:
                if (i != 3)
                {
                    i++;
                }
                else
                {
                    i = 1;
                }
                list_show(i, 3, str);
                break;
            case 13:
                system("CLS");
                switch (i)
                {
                case 1:
                    if (glowing_pearls[player_no].glowing_pearls > 0)
                    {
                        werewolf[player_no].feed_glowing();
                        glowing_pearls[player_no].glowing_pearls = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 2:
                    if (purple_diamond[player_no].purple_diamond > 0)
                    {
                        werewolf[player_no].feed_purple();
                        purple_diamond[player_no].purple_diamond = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 3:
                    if (jade[player_no].jade > 0)
                    {
                        werewolf[player_no].feed_jade();
                        jade[player_no].jade = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 0:
                A:
                    system("CLS");
                    header();
                    SetConsoleTextAttribute(h, 12);

                    cout << "\n\t\t\t\t\t\tYou Dont Have This Food .";
                    SetConsoleTextAttribute(h, 7);
                    Sleep(1000);
                    break;
                }
                break;

            default:
                break;
            }
        }
    }
    else
    {
        header();
        SetConsoleTextAttribute(h, 12);

        cout << "\t\t\t\t\t You Dont Have Any Food Of This Animal" << endl;
        SetConsoleTextAttribute(h, 7);
        Sleep(500);
        game_list(player_no);
    }
}
void feed_griffin(int player_no)
{
    if (flaming_crystal[player_no].flaming_crystal > 0 || jade[player_no].jade > 0 || glowing_pearls[player_no].glowing_pearls > 0)
    {

        string str[] = {"Jade           " + to_string(jade[player_no].get_food()), "Glowing pearls  " + to_string(glowing_pearls[player_no].get_food()), "Flaming Crystal " + to_string(flaming_crystal[player_no].get_food())};
        int i = 1, a = 0, ch;
        while (a < 1)
        {
            list_show(i, 3, str);
            switch (ch = getch())
            {
            case 72:
                if (i != 1)
                {
                    i--;
                }
                else
                {
                    i = 3;
                }
                list_show(i, 3, str);
                break;
            case 80:
                if (i != 3)
                {
                    i++;
                }
                else
                {
                    i = 1;
                }
                list_show(i, 3, str);
                break;
            case 13:
                system("CLS");
                switch (i)
                {
                case 1:

                    if (!(jade[player_no].jade = 0))
                    {
                        griffin[player_no].feed_jade();
                        jade[player_no].jade = 0;
                        a++;
                    }

                    else
                    {
                        goto A;
                    }
                    break;
                case 2:

                    if (glowing_pearls[player_no].glowing_pearls > 0)
                    {
                        griffin[player_no].feed_glowing();
                        glowing_pearls[player_no].glowing_pearls = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }

                    break;
                case 3:
                    if (flaming_crystal[player_no].flaming_crystal > 0)
                    {
                        griffin[player_no].feed_flaming();
                        flaming_crystal[player_no].flaming_crystal = 0;
                        a++;
                    }
                    else
                    {
                        goto A;
                    }
                    break;
                case 0:
                A:
                    system("CLS");
                    header();
                    SetConsoleTextAttribute(h, 12);

                    cout << "\n\t\t\t\t\t\tYou Dont Have This Food .";
                    SetConsoleTextAttribute(h, 7);
                    Sleep(1000);
                    break;
                }
                break;

            default:
                break;
            }
        }
    }
    else
    {
        header();
        SetConsoleTextAttribute(h, 12);

        cout << "\t\t\t\t\t You Dont Have Any Food Of This Animal" << endl;
        SetConsoleTextAttribute(h, 7);
        Sleep(500);
        game_list(player_no);
    }
}
void get_name(int player_no)
{
    header();
    for (int i = 0; i < player_no; i++)
    {
        SetConsoleTextAttribute(h, 12);
        cout << "\t\t\t\t\tEnter Player " << i + 1 << " Name : ";
        SetConsoleTextAttribute(h, 7);
        getline(cin, Player::Players[i]);
    }
    system("CLS");
}
void winner()
{
    for (int k = 0; k < 4; k++)
    {
        phoenix[k].sell_one(k);
        titan[k].sell_one(k);
        yeti[k].sell_one(k);
        werewolf[k].sell_one(k);
        griffin[k].sell_one(k);
    }
    int j = 0;
    for (int i = 1; i < 4; i++)
    {
        if (Player::money[j] < Player::money[i])
        {
            j = i;
        }
    }
    SetConsoleTextAttribute(h, 12);
    cout << "\n\n\n\n----------------------------------------------------------------------------------------------------------------------" << endl
         << "                                              Congratulation!                                                       " << endl
         << "                                              " << Player::Players[j] << "                                              " << endl
         << "----------------------------------------------------------------------------------------------------------------------" << endl;
    Sleep(2000);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl
         << "|                                               Winner Winner                                                        |" << endl
         << "|                                               Chicken Dinner                                                       |" << endl
         << "----------------------------------------------------------------------------------------------------------------------" << endl;
    getch();
    SetConsoleTextAttribute(h, 7);
}
void loading(string str)
{
    system("CLS");
    char x = 219;
    header();
    SetConsoleTextAttribute(h, 12);

    cout << "\n\t\t\t\t\t " << str;
    SetConsoleTextAttribute(h, 10);
    for (int i = 0; i < 25; i++)
    {
        cout << x;
        Sleep(50);
    }
    SetConsoleTextAttribute(h, 7);
}
void header()
{
    SetConsoleTextAttribute(h, 12);
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl
         << "|                                               WildLife Saga                                                        |" << endl
         << "----------------------------------------------------------------------------------------------------------------------" << endl;
    SetConsoleTextAttribute(h, 7);
}
