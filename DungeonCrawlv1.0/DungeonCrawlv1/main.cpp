//
//  main.cpp
//  DungeonCrawlv1
//
//  Created by Eddie Power on 10/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//
//  Extra content noted in the readMe.txt file included with my submission
//   of this assignment 3.
//

#include "GameItem.h"
#include "Player.h"
#include "Monster.h"
#include "BossMonster.h"
#include "Treasure.h"
#include "Potion.h"
#include "Room.h"

//Pre defined program methods for dungeon crawl.
void runMainGame();
void populateRoom(char direction, Player* p, BossMonster* b, Monster* m1, Monster* m2, Monster* m3, Treasure* t1, Treasure* t2, Treasure* t3, Potion* pt1, Potion* pt2, Room* curRoom, GameItem* map, bool& bMapFound);
void checkPlayerLocation(Player* p, BossMonster* b, Monster* m1, Monster* m2, Monster* m3, Treasure* t1, Treasure* t2, Treasure* t3, Potion* pt1, Potion* pt2, Room* curRoom, GameItem* map, bool& bMapFound);
void battleMonster(Player* p, Monster* m);
void battleBoss(Player* p, BossMonster* b);
int getHighScore(string& sHighScorePlayer);
void setHighScore(Player* p);
void readInstructions();
void cleanUpObjs(BossMonster* b, Monster* m1, Monster* m2, Monster* m3, Treasure* t1, Treasure* t2, Treasure* t3, Potion* pt1, Potion* pt2, GameItem* map);

int main()
{
    //seed random number generators when main is run.
    srand(unsigned(time(0)));       
    int nChoice = 0;
    string sHighScorePlayer;
    
    do 
    {
        cout << "\nDungeon Crawl Adventure Game.\n" << endl;
        cout << "1: Read Instructions." << endl;       
        cout << "2: Begin new Game." << endl;
        cout << "3: Check High Score." << endl;
        cout << "0: Quit" << endl;
        cout << "Please enter a menu option: ";
        cin >> nChoice;
        
        switch(nChoice)
        {
            case 0:
                cout << "\nThanks for Playing, Try Master the dungeon again soon\nGood Bye" << endl;
                cout << "Copyright (c) 2012, Monash University, by student Eddie Power." << endl;
                break;
            case 1:
                readInstructions();
                break;
            case 2:
                runMainGame();                 
                break;
            case 3:
                //EXTRA*CONTENT*******
                //High score display with Crude player name display.
                cout << "\nDUNGEON CRAWL HIGH SCORE:" << endl;
                cout << getHighScore(sHighScorePlayer) << " was achieved by " << sHighScorePlayer << endl; 
                //END*EXTRA*CONTENT******
                break;
            default:
                cout << "Please enter a valid menu option!" << endl;
                break;
        }
    } while (nChoice != 0);

    //cin.get();
    //system("PAUSE");
    return 0;
}

//Main game logic for moving through the dungeon, fighting, drinking potions and getting treasures.
void runMainGame()
{
    Room* curRoom = new Room;
    BossMonster* b = new BossMonster("Kurgan", "boss_monster");
    Monster* m1 = new Monster("Charmander", "monster");
    Monster* m2 = new Monster("Carchaser", "monster");
    Monster* m3 = new Monster("Firebreather", "monster");
    Treasure* t1 = new Treasure("LostGold", "treasure");
    Treasure* t2 = new Treasure("AncientGems", "treasure");
    Treasure* t3 = new Treasure("newIphone6", "treasure");
    Potion* pt1 = new Potion;
    Potion* pt2 = new Potion;
    GameItem* map =  new GameItem("hiddenMap", "map");
    char cUserInput = 'z';
    bool bMapFound = false;
    int nFairnessCount = 0;
    string sPlayerName;
    
    cout << "Please Enter your name player: ";
    cin >> sPlayerName;
    Player* p = new Player(sPlayerName, "player");

    //add random items and player to new room.
    populateRoom('s', p, b, m1, m2, m3, t1, t2, t3, pt1, pt2, curRoom, map, bMapFound);  
//
//    if (bMapFound == true) 
//    {
//        cout << "\n\n\nRoom Layout:" << endl;
//        cout << curRoom->printRoom() << endl;
//    }
//    
    //while player has health and user has not entered quit key then.
    while (p->getHealth() > 0 && cUserInput != 'q') 
    {
        //get user input on which direction to move in.
        do 
        {
            cout << "What direction would you like to move in?(n,e,s,w or q to quit.): ";
            cin >> cUserInput;
            //convert all entries to lower case just in case.
            cUserInput = tolower(cUserInput);
        } while (cUserInput != 'n' && cUserInput != 'e' && cUserInput != 's' && cUserInput != 'w' && cUserInput != 'q');
        
        //cover up the current location of the player for the display map.
        //Part of my Extra content to make game play a little easier.
        curRoom->setLocation("+  ", p->getXlocation(), p->getYlocation());
        
        //If move was not into a new room print user output else create new 
        // room object and populate room with items, monsters, etc.
        if (p->movePlayer(cUserInput, p) == 2) 
        {
            //genetic user output for successfull move attempt.
            cout << "\n*******************************************************************" << endl;
            cout << "Left foot, right foot you hear the echo of your heavy feet on the cold wet ";
            cout << " floor you feel paralized by the drakness all around you but this time ";
            cout << " you moved yourself successfully.\n 0\n-|-\n/ \\" << endl;
            //*******EXTRA*CONTENT**BELOW********************
            //if the fairness counter is at 7 and the map picture has been found then 
            // run logic below.
            if (nFairnessCount == 7 && bMapFound == true) 
            {
                //hide the map picture from the player again
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
                cout << "*******************************************************************" << endl;
                cout << "The vision of the room picture or map has faded ";
                cout << "from your memory(knew you shouldnt have eaten all that clag in grade 1,";
                cout << " the number of MEMORY LEAKS you have now are a lot) your back ";
                cout << "in the dark for now.\n\n" << endl;
                //reset both the bool flag for map found and the fairness counter.
                bMapFound = false;
                nFairnessCount = 0;
            }
            //else if map pic has been found the add 1 to the fairness counter.
            else if(bMapFound == true)
            {
                nFairnessCount++;
            }
            //********END*EXTRA*CONTENT*********************
        }
        else if (p->movePlayer(cUserInput, p) == -1)
        {
            cout << "\n\n******************************************************" << endl;
            cout << "Moved into a new room!!" << endl;
            delete curRoom;
            curRoom = new Room;
            //reset map pic and fairness counter, in case map was showing when leaving last room.
            bMapFound = false;
            nFairnessCount = 0;
            //add items randomly and player in correct doorway to new room.
            populateRoom(cUserInput, p, b, m1, m2, m3, t1, t2, t3, pt1, pt2, curRoom, map, bMapFound);			

        }
        
        //check to see if tile player is on has a monster, treasure or potion and run correct method
        // from each object type.
        checkPlayerLocation(p, b, m1, m2, m3, t1, t2, t3, pt1, pt2, curRoom, map, bMapFound);
        
        //Update player location and extra content visual map display
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
        
        //display visual map locations if player is still alive,
        // and the map drawing has been found (bool flag set to true).
        if (p->getHealth() > 0 && bMapFound == true) 
        {
            cout << "\n\n\nRoom Layout:" << endl;
            cout << curRoom->printRoom() << endl;
        }
    }
    
    //End game user output, if life is 0 you died else player quits.
    if(p->getHealth() <= 0)
    {
        cout << "\n*******************************************************************" << endl;
        cout << "GAME OVER!" << endl;
        cout << "You died with " << p->display() << endl;
        if(getHighScore(sPlayerName) < p->getScore())
        {
            setHighScore(p);
            cout << "WELL DONE YOU GOT A NEW HIGH SCORE!!!" << endl;
        }
        cout << "Please Play Again Soon!!!" << endl;
        cout << "*******************************************************************\n" << endl;
    }
    else if(cUserInput == 'q')
    {
        cout << "\n*******************************************************************" << endl;
        cout << "GAME OVER!" << endl;
        cout << "You quit with " << p->display() << endl;
        if(getHighScore(sPlayerName) < p->getScore())
        {
            setHighScore(p);
            cout << "WELL DONE YOU GOT A NEW HIGH SCORE!!!" << endl;
        }
        cout << "\nPlease Play Again Soon :)!!!" << endl; 
        cout << "*******************************************************************\n" << endl;
    }
    
    //free up memory of stored items and prevent any memory leaks 
    // by deleating all heap based objects. No need to null the pointers
    // as this is the game end point for this run.
    cleanUpObjs(b, m1, m2, m3, t1, t2, t3, pt1, pt2, map);
	curRoom = NULL;
	delete curRoom;
	p = NULL;
    delete p;

}

//Populate the dungeon Room with the randomly placed objects i.e. monsters, potions, treasures etc.
void populateRoom(char direction, Player* p, BossMonster* b, Monster* m1, Monster* m2, Monster* m3, Treasure* t1, Treasure* t2, Treasure* t3, Potion* pt1, Potion* pt2, Room* curRoom, GameItem* map, bool& bMapFound)
{    
	//Delete and null old objects for new room population.
	cleanUpObjs(b, m1, m2, m3, t1, t2, t3, pt1, pt2, map);
    b = new BossMonster("Kurgan","boss_monster");
    m1 = new Monster("Charmander","monster");    
    m2 = new Monster("Carchaser","monster");
    m3 = new Monster("Firebreather","monster");
    t1 = new Treasure("LostGold", "treasure");
    t2 = new Treasure("AncientGems", "treasure");
    t3 = new Treasure("newIphone6", "treasure");
    pt1 = new Potion;
    pt2 = new Potion;
    map = new GameItem("hiddenMap", "map");
	//USED FOR DEBUG ONLY TO MAKE SURE EACH ROOM HAS FRESH/NEW OBJECTS
	//cout << "***************************************" << endl;
	//cout << p->display() << endl;
	//cout << "BOSS: " << b->display() << endl;
	//cout << "M1: " << m1->display() << endl;
	//cout << "M2: " << m2->display() << endl;
	//cout << "M3: " << m3->display() << endl;
	//cout << "T1: " << t1->display() << endl;
	//cout << "T2: " << t2->display() << endl;
	//cout << "T3: " << t3->display() << endl;
	//cout << "PT1: " << pt1->display() << endl;
	//cout << "PT2: " << pt2->display() << endl;
	//cout << "***************************************" << endl;  

	//Work out the player start point depending on what door or direction he travels in.
    if (direction == 's') 
    {
        //set players start location.
        p->setXlocation(0);
        p->setYlocation(4);      
    }
    else if(direction == 'e')
    {
        //set players start location.
        p->setXlocation(4);
        p->setYlocation(0);         
    }
    else if(direction == 'n')
    {
        //set players start location.
        p->setXlocation(9);
        p->setYlocation(4);
    }
    else
    {
        //set players start location.
        p->setXlocation(4);
        p->setYlocation(9);       
    }
    
    //set map set locations. x & y come from constructors.
    curRoom->setLocation("m1 ", m1->getXlocation(), m1->getYlocation());
    curRoom->setLocation("m2 ", m2->getXlocation(), m2->getYlocation());
    curRoom->setLocation("m3 ", m3->getXlocation(), m3->getYlocation());
    curRoom->setLocation("p1 ", pt1->getXlocation(), pt1->getYlocation());
    curRoom->setLocation("p2 ", pt2->getXlocation(), pt2->getYlocation());
    curRoom->setLocation("t1 ", t1->getXlocation(), t1->getYlocation());
    curRoom->setLocation("t2 ", t2->getXlocation(), t2->getYlocation());
    curRoom->setLocation("t3 ", t3->getXlocation(), t3->getYlocation());
    curRoom->setLocation("b  ", b->getXlocation(), b->getYlocation());
    curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
    //Set hidden location of the map or picture of the room layout for users to find for a leg up.
    curRoom->setLocation("MP ", map->getXlocation(), map->getYlocation());

    //Check the player is not on an actionable tile i.e monster, boss, treasure etc.
    checkPlayerLocation(p, b, m1, m2, m3, t1, t2, t3, pt1, pt2, curRoom, map, bMapFound);
}

//Check the player is not on an actionable tile i.e monster, boss, treasure etc.
void checkPlayerLocation(Player* p, BossMonster* b, Monster* m1, Monster* m2, Monster* m3, Treasure* t1, Treasure* t2, Treasure* t3, Potion* pt1, Potion* pt2, Room* curRoom, GameItem* map, bool& bMapFound)
{
    char cUserChoice;
    
    //check to see if tile player is on has a monster, treasure or potion and run correct method
    // from each object type.
    if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "m1 ")
    {
        cout << "\n\n*******************************************************************" << endl;          
        cout << "You see a shape rush out of the darkness towards you howling its a rabid monster M1 you begin to fight via a well known fight method." << endl;  
        battleMonster(p, m1);
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());

    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "m2 ")
    {
        cout << "\n\n*******************************************************************" << endl;
        cout << "You see a shape rush out of the darkness towards you howling its a rabid monster M2 you begin to fight via a well known fight method." << endl; 
        battleMonster(p, m2);
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());

    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "m3 ")
    {
        cout << "\n\n*******************************************************************" << endl;
        cout << "You see a shape rush out of the darkness towards you howling its a rabid monster M3 you begin to fight via a well known fight method." << endl;
        battleMonster(p, m3);
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());

    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "b  ")
    {
        cout << "\n\n*******************************************************************" << endl;
        cout << "You hit what feels like a tree trunk in the darkness when you look up you soon realize its a leg" << endl;
        cout << "of a massive crazed Boss Monster you hold your breath and begin with a kung fu pose via a well known fight method." << endl;  
        battleBoss(p, b);
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "p1 ")
    { 
        do 
        {
            cout << "\n\n*******************************************************************" << endl;
            cout << "You have found a potion P1 labeled drink me (yes/no)." << endl;
            cout << "Will your drink the black smoking fluid in your hand?";
            cin >> cUserChoice;
        } while (cUserChoice != 'y' && cUserChoice != 'n');
        
        switch (cUserChoice) 
        {
            case 'y':
                if(pt1->getType() == "health_potion")
                {
                    p->setHealth(pt1->getValue());
                    cout << "\nHealth is now " << p->getHealth() << endl;
                    //Add 1 to the number of potions found.
                    p->addPotionsDrank();
                    curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
                }
                else
                {
                    p->setSkill(pt1->getValue());
                    cout << "\nSkill is now " << p->getSkill() << endl;
                    //Add 1 to the number of potions found.
                    p->addPotionsDrank();
                    curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
                }
                break;
            case 'n':
                cout << "\n\n*******************************************************************" << endl;
                cout << "You leave the concoction where it is for someone else to drink." << endl;
                curRoom->setLocation("p1 ", p->getXlocation(), p->getYlocation());
                cout << "You slowly back away from the concoction to the east....Pheww it didnt blow up." << endl;                    
                p->movePlayer('e', p);
                break;
            default:
                cout << "Please choose a correct option either y for yes or n for no." << endl;
                break;
        }
    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "p2 ")
    {
        cout << "\nYou have found a potion P2 labeled drink me (yes/no)." << endl; 
        cout << "Will your drink the black smoking fluid in your hand?";
        cin >> cUserChoice;
        
        switch (cUserChoice) 
        {
            case 'y':
                if(pt2->getType() == "health_potion")
                {
                    p->setHealth(pt2->getValue());
                    cout << "\nHealth is now " << p->getHealth() << endl;
                    //Add 1 to the number of potions found.
                    p->addPotionsDrank();
                    curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
                }
                else
                {
                    p->setSkill(pt2->getValue());
                    cout << "\nSkill is now " << p->getSkill() << endl;
                    //Add 1 to the number of potions found.
                    p->addPotionsDrank();
                    curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
                }
                break;
            case 'n':
                cout << "\nYou leave the concoction where it is for someone else to drink." << endl;
                curRoom->setLocation("p1 ", p->getXlocation(), p->getYlocation());
                cout << "You slowly back away from the concoction to the east....Pheww it didnt blow up." << endl;                    
                p->movePlayer('e', p);
                break;
            default:
                cout << "Please choose a correct option either y for yes or n for no." << endl;
                break;
        }         
    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "t1 ")
    {
        cout << "\nYou have found a chest full of gold $2 coins you scream treasure!!~! in excitement." << endl; 
        p->setScore(t1->getValue());
        cout << "Player score is now " << p->getScore() << endl;
        //Add 1 to the number of treasures found.
        p->addTreasureFound();
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "t2 ")
    {
        cout << "\nYou have found a brand new iPhone6 in the box!!~!\n You do ";
        cout << "your treasure dance." << endl; 
        p->setScore(t2->getValue());
        cout << "Player score is now " << p->getScore() << endl;
        //Add 1 to the number of treasures found.
        p->addTreasureFound();
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "t3 ")
    {
        cout << "\nYou have found a diamond the size of your head, you quickly ";
        cout << "add the treasure to your Mary Poppins like bag." << endl;             
        p->setScore(t3->getValue());
        cout << "Player score is now " << p->getScore() << endl; 
        //Add 1 to the number of treasures found.
        p->addTreasureFound();
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
    }
    else if(curRoom->getItem(p->getXlocation(), p->getYlocation()) == "MP ")
    {
        cout << "\n\n*******************************************************************" << endl;
        cout << "You find a strange drawing on the floor written in blood it seems";
        cout << " to be a picture of the room your standing in with a strange pictures";
        cout << " of objects scattered around the room in the picture.  Could this be the room";
        cout << " you are standing in the symbol @ seems to represent right where your standing";
        cout << " you take a mental note of the picture for use later on, who knows it ";
        cout << "may come in handy! Of course you wont remember this for long so make";
        cout << " good use of it while you can!!\n" << endl;
        bMapFound = true;
        curRoom->setLocation("@  ", p->getXlocation(), p->getYlocation());
    }
}

//Battle rounds logic for fighting monsters.
void battleMonster(Player* p, Monster* m)
{
    int nPlayerBattleValue;
    int nMonsterBattleValue;
    
    while (p->getHealth() > 0 && m->getHealth() > 0) 
    {
        //generate rand in range 2-12.
        nPlayerBattleValue = rand() % 11 + 2;
        nMonsterBattleValue = rand() % 11 + 2;
        
        nPlayerBattleValue += p->getSkill();
        nMonsterBattleValue += m->getSkill();
        
        //check who won the round of fighting.
        if(nPlayerBattleValue > nMonsterBattleValue)
        {
            cout << "\nPlayer won this round!!!" << endl;
            m->beHit(nPlayerBattleValue - nMonsterBattleValue);
            cout << "Monster health is now " << m->getHealth() << endl;
        }
        else if(nPlayerBattleValue < nMonsterBattleValue)
        {
            cout << "\nMonster won this round!!!" << endl;
            p->beHit(nMonsterBattleValue - nPlayerBattleValue);
            cout << "Player health is now " << p->getHealth() << endl;
        }
        else
        {
            cout << "\nDRAW no One won!!!" << endl;
        }
        
        cout << "\nHit enter to continue the battle: ";
        cin.get();
    }
    
    //Check who won Battle, if player has health above 0 print user won message and score else print user loss message
    //And add boss monster kill points onto player score total.
    if (p->getHealth() > 0) 
    {
        cout << "\n\n******************************************************" << endl;
        cout << "As the monster gasp's its dying breath you see some treasure sticking out of the monsters bag!" << endl;
        cout << "You grab the treasure and add it to you inventory of treasure, its worth " << m->getScore() << " points.\n" << endl;
        p->setScore(m->getScore());
        //add 1 to the number of monsters killed!
        p->addMonsterKills();
    }
    else
    {
        //Output the player death user output to screen.
        cout << "\n\n******************************************************" << endl;
        cout << "As you fall wounded with blood spilling from the place your hand used to be you think to your self" << endl;
        cout << "if only I had taken the blue pill. Not knowing why this thought troubles you, you gasp and the world goes black" << endl;
        cout << "You Died. The monster rips your bag off your lifeless body and storms off into the dark room beyond." << endl;
    }
}

//Battle rounds logic for fighting Boss Monsters.
void battleBoss(Player* p, BossMonster* b)
{
    int nPlayerBattleValue;
    int nMonsterBattleValue;
    
    while (p->getHealth() > 0 && b->getHealth() > 0) 
    {
        //generate rand in range 2-12.
        nPlayerBattleValue = rand() % 11 + 2;
        nMonsterBattleValue = rand() % 11 + 2;
        
        nPlayerBattleValue += p->getSkill();
        nMonsterBattleValue += b->getSkill();
        
        //cout << "Player battle value is " << nPlayerBattleValue << endl;
        //cout << "BossMonster battle value is " << nMonsterBattleValue << endl;    
        
        //check who won the round of fighting.
        if(nPlayerBattleValue > nMonsterBattleValue)
        {
            cout << "\nPlayer won this round!!!" << endl;
            b->beHit(nPlayerBattleValue - nMonsterBattleValue);
            cout << "Boss Monster's health is now " << b->getHealth() << endl;
        }
        else if(nPlayerBattleValue < nMonsterBattleValue)
        {
            cout << "\nBoss Monster won this round!!!" << endl;
            p->beHit(nMonsterBattleValue - nPlayerBattleValue);
            cout << "Player health is now " << p->getHealth() << endl;
        }
        else
        {
            cout << "\nDRAW no One won!!!" << endl;
        }
        cout << "Hit enter to continue the battle: ";
        cin.get();
    }
    
    //Check who won Battle, if player has health above 0 print user won message and score else print user loss message
    //And add monster kill points onto player score total.
    if (p->getHealth() > 0) 
    {
        cout << "\n\n******************************************************" << endl;
        cout << "As the Boss Monster gasp's its dying breath you see some treasure sticking out of the monsters bag!" << endl;
        cout << "You grab the treasure and add it to you inventory of treasure, its worth " << b->getScore() << " points.\n" << endl;
        p->setScore(b->getScore());
        //add 1 to the number of monsters killed!
        p->addMonsterKills();
    }
    else
    {
        cout << "\n\n******************************************************" << endl;
        cout << "As you fall wounded with blood spilling from the place your hand used to be you think to your self" << endl;
        cout << "if only I had taken the blue pill. Not knowing why this thought troubles you, you gasp and the world goes black" << endl;
        cout << "You Died. The Boss Monster rips your bag off your lifeless body and storms off into the dark room beyond." << endl;
    }
}

//Return the high score and set the player name to the refrence
//to the player name variable in main()
int getHighScore(string& sHighScorePlayer)
{
    int nHighScore;
    ifstream fsHighScore;
    
    fsHighScore.open("HighScore.txt");
    //Check the file is open corectly.
    if (fsHighScore.is_open()) 
    {
        fsHighScore >> nHighScore;
        fsHighScore >> sHighScorePlayer;
        fsHighScore.close();
    }
    else
    {
        cout << "Could not open file for High Scores" << endl;
        cout << "Please ensure exsists and is located in the ";
        cout << "right directory i.e: the one the game runs from." << endl;
    }
    
    return nHighScore;
}

//Save the high score to a text file for next game run.
void setHighScore(Player* p)
{
    fstream fsHighScore;
    
    fsHighScore.open("HighScore.txt");
    //Check the file is open corectly.
    if (fsHighScore.is_open()) 
    {
      fsHighScore << p->getScore() << "\n";
      fsHighScore << p->getName();
      fsHighScore.close();
    }
    else
    {
        cout << "Could not open file for High Scores" << endl;
        cout << "Please ensure exsists and is located in the ";
        cout << "right directory i.e: the one the game runs from." << endl;
    }
}

//Output Instructions to the user if needed.
void readInstructions()
{
    int nInstructionChoice = 0;
    
    do 
    {
        cout << "\nDungeon Crawl Instructions.\n******************************\n" << endl;
        cout << "Below are the game instructions, to get to know how to move around and";
        cout << " fight the monsters you will come across this is the one stop place";
        cout << " for information. To return to the game menu enter 0 as shown below\n" << endl;
        cout << "1. The game objectives and dungeon layout.\n" << endl;
        cout << "2. How to move around the dungeon rooms\n" << endl;
        cout << "3. Fighting monsters.\n" << endl;
        cout << "4. Drinking potions.\n" << endl;
        cout << "0: Return To Main Menu.\n" << endl;
        cout << "Please enter a menu option: ";
        cin >> nInstructionChoice;
        
        switch(nInstructionChoice)
        {
            case 0:
                cout << "Returning you back to the main game menu." << endl;
                break;
            case 1:
                cout << "\n1. The game objectives and dungeon layout." << endl;
                cout << "   The main objective of the game is to collect treasure items or points while fighting off the ";
                cout << "monsters in the game, to achieve this you can pick up potions to help you in the fighting.";
                cout << " When you win a fight you also gain points in the form of treasure that the monster holds, there ";
                cout << " is also a boss monster in each room you visit it is up to you to find this monster and battle him to gain" << endl;
                cout << "a bigger treasure / points reward if you can beat them! There is a massive dungeon for you to explore that ";
                cout << "spans many many rooms similar to the one you start in.  The game will continue until your health reaches 0" << endl;
                cout << "then your points are totaled at the end of the game to show your score for that run.  " << endl;
                cout << "\nHit enter to continue: ";
                cin.get();
                cin.get();
                break;
            case 2:
                cout << "\n2. How to move around the dungeon rooms" << endl;
                cout << "   The dungeon rooms are spaced in a 10 x 10 layout, this means";
                cout << " that it is 10 rows of 10 tiles with a door located in the middle of " << endl;
                cout << "each wall, When you begin the game you start at the north doorway. ";
                cout << " To move around the dungeon rooms you use the keys n to move north " << endl;
                cout << "or up, e to move east or right, s to move south or down and finally w to";
                cout << " move west or left. You can do this until you encounter a monster, " << endl;
                cout << "treasure, potion, boss monster, wall, door or other hidden object.  The";
                cout << " dungeon rooms are not lit at all and you can not see more then a few" << endl;
                cout << "feet in front of you so keep your eyes out for hints on whats in";
                cout << "the room your in, Finally to move into a new room you must go through" << endl;
                cout << "a door which will take you to a new fresh room to explore. Good luck.";
                cout << "\nHit enter to continue: ";
                cin.get();
                cin.get();
                break;
            case 3:
                cout << "\n3. Fighting monsters." << endl;
                cout << "   The fighting process is quite simple in this version of dungeon crawl";
                cout << "The Battles are split into fight rounds which are automated so when" << endl;
                cout << "a player hits a monster they must fight it and will be told round by round";
                cout << " who won that round and then at the end the player is told if he won " << endl;
                cout << "the fight or if he lost of course if he lost he is dead and the game is over.";
                cout << "  The boss monster fight follows these same rules, each room in the" << endl;
                cout << "dungeon has a boss monster and they also hold the most valuable treasure.";
                cout << "\nHit enter to continue: ";
                cin.get();
                cin.get();
                break;
            case 4:
                cout << "\n4. Drinking potions." << endl;
                cout << "   To drink a potion you will be presented with the question: ";
                cout << " Do you want to drink this potion? (y/n).  And to answer that the " << endl;
                cout << "Player must enter either a y or n and hit enter, of course a y means the";
                cout << " player drank the potion and moved onto the space where the potion" << endl;
                cout << "was or if the player uses the n key and states no he doesnt want the potion";
                cout << " the player will move to the left of the " << endl;
                cout << "found the potion, leaving the potion there to be collected another time";
                cout << " or left alone and not used at all." << endl;
                cout << "\nHit enter to continue: ";
                cin.get();
                cin.get();
                break;
            default:
                cout << "Please enter a valid menu option!" << endl;
                break;
        }
    } while (nInstructionChoice != 0);   
}

//Used to delete most of the objects created for the game since the room and the player are used for longer then 
// these objects they are deleted and pointers nulled seperatly.
void cleanUpObjs(BossMonster* b, Monster* m1, Monster* m2, Monster* m3, Treasure* t1, Treasure* t2, Treasure* t3, Potion* pt1, Potion* pt2, GameItem* map)
{
	b = NULL;
	delete b;
 	m1 = NULL;
	delete m1;
	m2 = NULL;
    delete m2;
    m3 = NULL;
	delete m3;
	t1 = NULL;
    delete t1;
	t2 = NULL;
    delete t2;
	t3 = NULL;
    delete t3;
	pt1 = NULL;
    delete pt1;
	pt2 = NULL;
    delete pt2;
	map = NULL;
    delete map;	
}