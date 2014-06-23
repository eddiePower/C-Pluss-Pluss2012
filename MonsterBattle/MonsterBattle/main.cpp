//
//  main.cpp
//  MonsterBattle
//
//  Created by Eddie Power on 8/04/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//
//  **********************
//  This solution is a little rough around the edges and due to 
//  bad time managment on my part not as refined as i would like it to be.
//  A lesson has been learned in better Time managment for Assignment 3. :)
//  **********************
//

#include "Monster.h"
#include "MagicMonster.h"

//Fowrard decleration of method functions not in the class's.
//Tryed to use refrences to vectors as much as possible to cut down on overhead.
//Methods used to: Run main game, Switch from p1 to p2 and vice versa,
// Run the attack round, Output the game stats ie: P1 health & P2 health,
//Make the monster pointer vectors, Display all elements in monster vector,
//Choose player's selected monster from vector, Create a vector of monster names
//for monster creation, Find the location of monster in vector for easy removal,
//Cast magic spells, Upcast or static cast a monster to a magic monster.

void runGame();
void switchPlayers(char &currentPlayer);
void launchAttackRound(Monster* monster1, Monster* monster2);
void getGameStats(Monster* monster1, Monster* monster2);
vector<Monster*> makeMonsterVector(vector<string>& vMonsterNames);
void readMonsters(const vector<Monster*>& vMyMonsterVector);
Monster* chooseMonster(vector<Monster*>& vMyMonsters);
vector<string> makeNamesVector();
int findVectorLocation(vector<Monster*>& vPlayerMonsters, int nMonsterHealth);
int MagicCast(MagicMonster* magicMonster);
MagicMonster* upCastMonster(Monster* chosenMonster);

int main()
{
    //seed the random number generator for use in this run.
    srand((unsigned)time(0));
    int nChoice = 0;

    cout << "****************Welcome to the monster Attack game.****************\n" << endl;    
    do 
    {
        //Inital game menu display
        cout << "Game Menu: " << endl;
        cout << "1: Start a new Game" << endl;
        cout << "2: Quit Program" << endl;
        cout << "Please enter a menu option: ";
        cin >> nChoice;
        
        switch(nChoice)
        {
            case 1:
                cout << "Beginning a Game!" << endl;
                //Run main game logic.
                runGame();
                break;
            case 2:
                //Quit game.
                cout << "\nThanks for playing Monster Battle, Good Bye" << endl;
                cout << "\nCopyright (c) 2012, Monash University, by student Eddie Power." << endl;
                break;
            default:
                cout << "Please enter a valid menu option!" << endl;
                break;
        }
    } while (nChoice != 2);
       
    //cin.get();
    //system("pause");
    return 0;
}

//Used to run the game logic including monster creation, selection
//and calling battle functions and other game functions.
//Should probably have broken this into sub functions looking at the list of variables below.
void runGame()
{
   bool bRoundFinished = true;
   int nUserOption = 0;
   char cCurrentPlayer = '1';
   vector<Monster*> vP1MonsterVector;
   vector<Monster*> vP2MonsterVector;
   vector<string> vMonsterNames;
   MagicMonster* pP1ChosenMagicMon;
   MagicMonster* pP2ChosenMagicMon;
   Monster* pP1ChosenMonster;
   Monster* pP2ChosenMonster;
   int nDelMonsterIndex = 0;
   bool bTmpShowMenu = false;
   int nTmpP1MagicCast;
   int nTmpP2MagicCast;
   int nTmpSkillP1 = 0;
   int nTmpSkillP2 = 0;
 
   //create the list of monster names.
   vMonsterNames = makeNamesVector();
    
   //creation of player1's vector of monsters with random names.
   vP1MonsterVector = makeMonsterVector(vMonsterNames);
    
   //Runs as a static variable just to assist in the creation 
   //of one of each type of magic monsters, normally would not
   //use this level of vissibility ie public if possible!
   MagicMonster::m_nNumMagicMonsters = 0;
    
   vP2MonsterVector = makeMonsterVector(vMonsterNames);

   //User output to begin the game round.
   cout << "\n\n**********************************"<< endl;
   cout << "Beginning Game run: " << endl;
   cout << "**********************************"<< endl;
   do 
   {
     //User output to display list of player one monsters
     // from the vector of monster pointers.
     cout << "\n**********************************"<< endl;
     cout << "Player 1 Choose your monster: " << endl;
     cout << "**********************************"<< endl;
     //display monster list for player to choose from.
     readMonsters(vP1MonsterVector);
     //choose single monster from vector for each player to play with.
     pP1ChosenMonster = chooseMonster(vP1MonsterVector);
    
     //same as above but P2.
     cout << "\n**********************************"<< endl;
     cout << "Player 2 Choose your monster: " << endl;
     cout << "**********************************"<< endl;
     readMonsters(vP2MonsterVector);
     pP2ChosenMonster = chooseMonster(vP2MonsterVector);
       
     //display chosen monster's names for players to begin battle round.
     cout << "\nPlayer 1 chose " << pP1ChosenMonster->getMonsterName() << " the monster." << endl;
     cout << "Player 2 chose " << pP2ChosenMonster->getMonsterName() << " the monster.\n" << endl;   
    
     //While loop to check both player1 and player2 both have life above 0 and the round should run.
     while ((pP1ChosenMonster->checkMonsterHealth() != false && pP2ChosenMonster->checkMonsterHealth() != false) && bRoundFinished == true) 
     {
       do 
       {  
          //If selected player is P1
          if (cCurrentPlayer == '1') 
          {
               //If P1 chosen monster is a magic monster this process
               // was spoke about by Matt in our lecture and while its not
               // good Oo practice he said it was ok for this assignment.
               if (pP1ChosenMonster->getBoolMagicMonster() == true) 
               {
                   //set show cast magic option on user menu items to true or yes.
                   bTmpShowMenu = true;
                   
                   cout << "\n*******Player " << cCurrentPlayer << "'s Turn*******\nWould you like to: " << endl;
                   cout << "1)Attack Your Opponant. " << endl;
                   cout << "2)Check the current game status: " << endl;
                   cout << "3)Do magic stuff " << endl;
                   cout << "4)Quit the game: " << endl;
               }
               else
               {
                   //set show cast magic option on user menu items to false or no.
                   bTmpShowMenu = false;
                   
                   cout << "\n*******Player " << cCurrentPlayer << "'s Turn*******\nWould you like to: " << endl;
                   cout << "1)Attack Your Opponant. " << endl;
                   cout << "2)Check the current game status: " << endl;
                   cout << "4)Quit the game: " << endl;
               }
          }
          else
          {
               //If P2 chosen monster is a magic monster.
               if (pP2ChosenMonster->getBoolMagicMonster() == true) 
               {
                   //set show cast magic option on user menu items to true or yes.
                   bTmpShowMenu = true;
                   
                   cout << "\n*******Player " << cCurrentPlayer << "'s Turn*******\nWould you like to: " << endl;
                   cout << "1)Attack Your Opponant. " << endl;
                   cout << "2)Check the current game status: " << endl;
                   cout << "3)Do magic stuff " << endl;
                   cout << "4)Quit the game: " << endl;
               }
               else
               {
                   //set show cast magic option on user menu items to false or no.
                   bTmpShowMenu = false;
                   
                   cout << "\n*******Player " << cCurrentPlayer << "'s Turn*******\nWould you like to: " << endl;
                   cout << "1)Attack Your Opponant. " << endl;
                   cout << "2)Check the current game status: " << endl;
                   cout << "4)Quit the game: " << endl;
               }
          }
          cin >> nUserOption;
            
          switch (nUserOption) 
          {
             case 1: 
               //Run attack round logic.
               launchAttackRound(pP1ChosenMonster, pP2ChosenMonster);
               //Used to switch the player after each round so each player
               // takes turns attacking each other.
               bRoundFinished = true;
               //If old skill is stored after attack round swap
               //player skill back to origonal skill level.
               if (nTmpSkillP1 > 0) 
               {
                  //set P1 skill level back to the stored old skill level.
                  pP1ChosenMagicMon->setMonsterSkill(nTmpSkillP1);
                  cout << "P1's monster " << pP1ChosenMagicMon->getMonsterName() << "'s Skill is now back to " << pP1ChosenMagicMon->getMonsterSkill() << endl;
                   //return temp skill to 0 for next round with magic skill buff.
                   nTmpSkillP1 = 0;
               }
               else if(nTmpSkillP2 > 0)
               {
                  //set P2 skill level back to the stored old skill level.
                  pP2ChosenMagicMon->setMonsterSkill(nTmpSkillP2);
                  cout << "P2's monster " << pP2ChosenMagicMon->getMonsterName() << "'s Skill is now back to " << pP2ChosenMagicMon->getMonsterSkill() << endl;
                   //return temp skill to 0 for next round with magic skill buff.
                   nTmpSkillP2 = 0;
               }
               //Alternate player
               switchPlayers(cCurrentPlayer);                    
               break;
             case 2:
               //Show user game stats or p1 & p2 health.   
               cout << "\n*******GAME STATS:*******" << endl;
               getGameStats(pP1ChosenMonster, pP2ChosenMonster);
               break;
             case 3:
               //If magic menu options are available.   
               if (bTmpShowMenu == true) 
               {
                  //If player one upcast to magic monster since this menu
                  //is only available to monsters with magic flag set to true, 
                  //method mentioned by matt in lecture even tho it is not the best Oo 
                  //technique and I would normally try to find a better solution to this.
                  if (cCurrentPlayer == '1') 
                  {
                     //static cast from a normal monster to a magic monster.
                     pP1ChosenMagicMon = upCastMonster(pP1ChosenMonster);
                     //Store a temp int for this rounds magic cast.
                     nTmpP1MagicCast = MagicCast(pP1ChosenMagicMon);

                     //If P1 has magic amount left and did successfully cast magic.
                     if(pP1ChosenMagicMon->getMagicAmount() > 0 && nTmpP1MagicCast != -1)
                     {    //If monsters type of magic is skill or s.
                          if (pP1ChosenMagicMon->getMagicType() == 's') 
                          {
                              //Store a temp int for the old skill of P1 to return after this round.
                              nTmpSkillP1 = pP2ChosenMagicMon->getMonsterSkill();
                              
                              //Increase skill level by formula proposed in requirements.
                              pP1ChosenMagicMon->setMonsterSkill(pP1ChosenMagicMon->getMonsterSkill() + nTmpP1MagicCast);
                              
                              //Let the Player know their skill was increased and by how much.
                              cout << "P1's Magic Monster " << pP1ChosenMagicMon->getMonsterName() << "'s skill increased by: " << nTmpP1MagicCast << endl;
                          }
                         //Else p1 magic monster must have health buff magic.
                          else
                          {
                              //Set the new health level of p1 according to the requirements set out.
                              pP1ChosenMagicMon->setMonsterHealth(pP1ChosenMagicMon->getMonsterHealth() + nTmpP1MagicCast);
                              
                              //Alert P1 that their health has increased and by how much.
                              cout << "P1's Monster " << pP1ChosenMagicMon->getMonsterName() << "'s Health increased by: " << nTmpP1MagicCast << endl;
                          }

                        //deduct 1 amount of magic from the player both health magic or skill magic.
                        pP1ChosenMagicMon->setMagicAmount(pP1ChosenMagicMon->getMagicAmount() - 1);
                      }
                     //Else cast was not successfull.
                     else if(nTmpP1MagicCast == -1 && pP1ChosenMagicMon->getMagicAmount() > 0)
                     {
                          cout << "Magic cast was not successfull." << endl;
                          //deduct 1 amount of magic from the player.
                          pP1ChosenMagicMon->setMagicAmount(pP1ChosenMagicMon->getMagicAmount() - 1);                          
                     }
                     //Else P1 is out of magic amount.
                     else 
                     {
                          cout << "Your monster is out of magic P1 you can not cast!!" << endl;
                      }
                  }
                  //else if player 2 upcast to magic monster using static cast same as player 1 logic.
                  else
                  {
                     pP2ChosenMagicMon = upCastMonster(pP2ChosenMonster);
                     nTmpP2MagicCast = MagicCast(pP2ChosenMagicMon);
                      
                     if(pP2ChosenMagicMon->getMagicAmount() > 0 && nTmpP2MagicCast != -1)
                     {  
                        if (pP2ChosenMagicMon->getMagicType() == 's') 
                        {   
                           //Store a temp int for the old skill of P2 to return after this round.
                           nTmpSkillP2 = pP2ChosenMagicMon->getMonsterSkill();
                           
                           //Increase skill level by formula proposed in requirements.
                           pP2ChosenMagicMon->setMonsterSkill(pP2ChosenMagicMon->getMonsterSkill() + nTmpP2MagicCast);
                              
                           //Alert P2 that their Skill has increased and by how much.
                           cout << "P2's monster " << pP2ChosenMagicMon->getMonsterName() << "'s Skill increased by: " << nTmpP2MagicCast << endl;
                        }
                        else
                        {
                           //Set the new health level of p1 according to the requirements set out.
                           pP2ChosenMagicMon->setMonsterHealth(pP2ChosenMagicMon->getMonsterHealth() + nTmpP2MagicCast);
                              
                           //Alert P2 that their health has increased and by how much.
                           cout << "P2's monster " << pP2ChosenMagicMon->getMonsterName() << "'s health increased by " << nTmpP2MagicCast << endl;
                        }

                        //deduct 1 amount of magic from the player.
                        pP2ChosenMagicMon->setMagicAmount(pP2ChosenMagicMon->getMagicAmount() - 1);
                     }
                     //else out of magic else cast was not successfull.
                     else if(nTmpP2MagicCast == -1 && pP2ChosenMagicMon->getMagicAmount() > 0)
                     {
                        cout << "Magic cast was not successfull." << endl;
                        //deduct 1 amount of magic from the player.
                        pP2ChosenMagicMon->setMagicAmount(pP2ChosenMagicMon->getMagicAmount() - 1);                          
                     }
                     else 
                     {
                        cout << "Your monster is out of magic P2 you can not cast!!" << endl;
                     }
                  }
               }//end of if boolShowMenu is true for magic monsters only.
               //else: temp block out function of button 3 for normal monsters as 
               // the menu has changed to not let them see or try access magic they dont have.
               else
               {
                  cout << "Im sorry that option is not available at this time." << endl;
               }
               break;
              case 4:
                //force earlyy end of round's / game.
                bRoundFinished = false;         
                break;
              default:
                cout << "Please enter a valid menu number." << endl;
                break;
          } 
        } while (nUserOption != 4 && (pP1ChosenMonster->checkMonsterHealth() == true && pP2ChosenMonster->checkMonsterHealth() == true));         
     }//end of check health > 0 and round Finished while loop.
       
     //User output to show who won the round from the rounds played.
     cout << "\n*******END OF ROUND STATS:*******" << endl;
     getGameStats(pP1ChosenMonster, pP2ChosenMonster);

     //check to see if player 1 won battle or player 2 and search 
     // and delete that monster from the correct player's vector.
     if(pP2ChosenMonster->getMonsterHealth() > 0 && (bRoundFinished == true)) 
     {  
        //store the index number for the monster to be deleted by a custom find method.
        nDelMonsterIndex = findVectorLocation(vP1MonsterVector, pP1ChosenMonster->getMonsterHealth());
        
        //Using the number found above and the erase method in the 
        // vector class, we remove the dead monster from the vector.
        vP1MonsterVector.erase(vP1MonsterVector.begin() + nDelMonsterIndex);

        //delete chosen monsters after life = 0 or their dead.
        delete pP1ChosenMonster;
        pP1ChosenMonster = NULL;
     }
     else if(pP1ChosenMonster->getMonsterHealth() > 0 && (bRoundFinished == true))
     {
         //store the index number for the monster to be deleted by a custom find method.
         nDelMonsterIndex = findVectorLocation(vP2MonsterVector, pP2ChosenMonster->getMonsterHealth());
        
         //Using the number found above and the erase method in the 
         // vector class we remove the dead monster from the vector.
         vP2MonsterVector.erase(vP2MonsterVector.begin() + nDelMonsterIndex);

         //delete chosen monster from memory after life = 0 or they are dead.
         delete pP2ChosenMonster;
         pP2ChosenMonster = NULL;
      }               
    }while ((vP1MonsterVector.size() > 0 && vP2MonsterVector.size() > 0) && bRoundFinished == true);
    //User end game output heading.
    cout << "\n**********************************"<< endl;
    cout << "End Of Game Results: " << endl;
    cout << "**********************************"<< endl;
    //Test which player won the game and display a user message to the screen about their win.
    if(vP1MonsterVector.size() > 0 && (vP1MonsterVector.size() > vP2MonsterVector.size())) 
    {
        cout << "\nPlayer One Won the game by killing more or all of player 2's monsters." << endl;
        cout << "Well done Player 1 you still had " << vP1MonsterVector.size() << " monsters left to fight!\n\n" << endl;
    }
    else if(vP2MonsterVector.size() > 0 && (vP2MonsterVector.size() > vP1MonsterVector.size()))
    {
        cout << "\nPlayer Two Won The game by killing more or all of player 1's monsters." << endl;
        cout << "Well done Player 2 you still had " << vP2MonsterVector.size() << " monsters left to fight!\n\n" << endl;
    }
    else if(vP1MonsterVector.size() == vP2MonsterVector.size())
    {
        cout << "\nBoth players finished with " << vP1MonsterVector.size() << " monsters so its a DRAW!!!\n\n" << endl;
    }
    cout << "**********************************"<< endl;      
    //Used to loop through the P1 monster vector and delete 
    //each heap based object.
    
    //Destroy pointers to the chosen or copied monsters in game play.
    pP1ChosenMonster = NULL;
    pP2ChosenMonster = NULL;
    pP1ChosenMagicMon = NULL;
    pP2ChosenMagicMon = NULL;
    
    //Used to loop through the P1 monster vector and delete 
    //each heap based monster, this calls their destructor down the line of inherintance.
    for(int i = 0; i < vP1MonsterVector.size(); i++) 
    {
        delete vP1MonsterVector[i];
        vP1MonsterVector[i] = NULL;
    }   
    //Used to loop through the P2 monster vector and delete 
    //each heap based object.
    for(int i = 0; i < vP2MonsterVector.size(); i++) 
    {
        delete vP2MonsterVector[i];
        vP2MonsterVector[i] = NULL;
    } 
}

//A crude way to keep track of which number players turn it is
//mainly used for user output on screen ie Player (n)'s turn.
void switchPlayers(char &currentPlayer)
{
    //switches the current player
    if (currentPlayer == '1')
    {
        currentPlayer = '2';
    }
    else if(currentPlayer == '2')
    {
        currentPlayer = '1';
    }
}

//runs the attack round math to work out who is the winner of an attack
// leaves the current monsters fighting with updated health deduction on loss.
void launchAttackRound(Monster* monster1, Monster* monster2)
{
    //temp variables used to calculate the attack power of each monster.
    int nMonsterAttack1 = 0;
    int nMonsterAttack2 = 0;
    
    //Get the numbers for each monsters attack points.
    nMonsterAttack1 = monster1->getMonsterAttackTotal(monster1->getMonsterSkill());
    nMonsterAttack2 = monster2->getMonsterAttackTotal(monster2->getMonsterSkill());
    
    //INFO ON ATTACKS.
    cout << "\n**********************************"<< endl;
    cout << "Monster Attacks were: " << endl;
    cout << "**********************************"<< endl;
    cout << "Monster1 attack strength was " << nMonsterAttack1 << endl;
    cout << "Monster2 attack strength was " << nMonsterAttack2 << endl << endl;
    cout << "**********************************"<< endl;

    //Work out who won the attack by greater attack value.
    if (nMonsterAttack1 > nMonsterAttack2) 
    {
        //monster 1 wins this round user output.
        cout << "Player 1 with monster " << monster1->getMonsterName() << " won this round." << endl;
        monster2->setMonsterHealth(monster2->getMonsterHealth() - (nMonsterAttack1 - nMonsterAttack2));
        cout << "Player 2's health will now be " << monster2->getMonsterHealth() << endl;
    }   
    else if(nMonsterAttack2 > nMonsterAttack1)
    {
        //monster 2 wins this round user output.
        cout << "Player 2 with monster " << monster2->getMonsterName() << " won this round." << endl;
        monster1->setMonsterHealth(monster1->getMonsterHealth() - (nMonsterAttack2 - nMonsterAttack1));
        cout << "Player 1's health will now be " << monster1->getMonsterHealth() << endl;
    }
    else if(nMonsterAttack1 == nMonsterAttack2)
    {
        //both attack scores were the same or a draw so no change to life stats.
        cout << "Both monsters scored the same attack points this round," << endl;
        cout << "this round was a DRAW!, no life orbs lost." << endl;
        cout << "\n*******GAME STATS:*******" << endl;
        getGameStats(monster1, monster2);
    }
    //Check the monsters health is still above 0 
    //and if it has fallen bellow 0 this function call returns the life value to 0.
    monster1->checkMonsterHealth();
    monster2->checkMonsterHealth();
}

//Outputs the current game standings and also the end game
//results depending on the players life on time of call.
void getGameStats(Monster* monster1, Monster* monster2)
{
    //if statement to state winner of either p1 or p2  or current health state of both players.
    if (monster1->getMonsterHealth() == 0 && monster2->getMonsterHealth() > monster1->getMonsterHealth()) 
    {
        cout << "Monster 2 " << monster2->displayMonster();
        cout << "WINNER!!" << endl;
    
        cout << "MONSTER 1 " << monster1->displayMonster();
        cout << "LOOSER!!" << endl;
        cout << "*************************\n" << endl;
    }
    else if(monster2->getMonsterHealth() == 0 && monster1->getMonsterHealth() > monster2->getMonsterHealth())
    {
        cout << "Monster 1 " << monster1->displayMonster();
        cout << "WINNER!!" << endl;
        
        cout << "MONSTER 2 " << monster2->displayMonster();
        cout << "LOOSER!!" << endl;
        cout << "*************************\n" << endl;
    }
    //else game is still playing so output the players health.
    else
    {    
       cout << "Player 1's monster " << monster1->getMonsterName() << " has " << monster1->getMonsterHealth() << " life orbs left." << endl;
       cout << "Player 2's monster " << monster2->getMonsterName() << " has " << monster2->getMonsterHealth() << " life orbs left." << endl;
       cout << "*************************\n" << endl;
    }
}

//Creates a group of monsters from a passed vector of monster names.
vector<Monster*> makeMonsterVector(vector<string>& vMonsterNames)
{
    vector<Monster*> vMyMonsters;
    string sMonsterName;
    int nMonsterSkill = 0;
    int nMonsterHealth = 0;
    int nRandNameIndex = 0;
    
    for (int i = 0; i < 5; i++) 
    {
        nRandNameIndex = (rand() % int(vMonsterNames.size()));
        //assign monster a random name from a vector of strings or names.
        sMonsterName = vMonsterNames[nRandNameIndex];
        
        //set the random numbers for skill level and health level
        nMonsterSkill = (rand() % 6) + 3;
        nMonsterHealth  = (rand() % 9) + 7;
        
        //Add 3 normal monsters.
        if (i <= 2) 
        {
            //create a monster with above collected data.
            Monster* monster = new Monster(sMonsterName, nMonsterSkill, nMonsterHealth);
            vMyMonsters.push_back(monster);
        }
        //Add magic monsters X 2.
        else if(i > 2)
        {
            //create a magic monster using polymorphism with above collected data.
            Monster* monster = new MagicMonster(sMonsterName, nMonsterSkill, nMonsterHealth);
            vMyMonsters.push_back(monster);   
        }           
    }
 
    return vMyMonsters;
}

//Allows for easy printing of monsters in a vector.
void readMonsters(const vector<Monster*>& vMyMonsterVector)
{
    for (int i = 0; i < vMyMonsterVector.size(); i++) 
    {
        cout << i + 1 << ".)" << vMyMonsterVector[i]->displayMonster() << endl;
    }
    cout << endl;
}

//This function allows the user to choose their current 
// monster to do battle with
Monster* chooseMonster(vector<Monster*>& vMyMonsters)
{
    int nMonsterChoice = 0;
    Monster* chosenMonster;
    
    //get player input on which monster to choose from thier vector
    // has validation on it to prevent incorrect index choices.
    do 
    {
        cout << "Please choose a monster number: " << endl;
        cin >> nMonsterChoice;
        
    } while(nMonsterChoice < 1 || nMonsterChoice > vMyMonsters.size());
    
    //prep user input variable to line up with vector index's
    nMonsterChoice = nMonsterChoice - 1;
    chosenMonster = vMyMonsters[nMonsterChoice];
    
    return chosenMonster;
}

//This function creates a vector of monster names for random 
// creation of monsters later.
vector<string> makeNamesVector()
{
    vector<string> vMonsterNames;
    
    //Used to get random names for each monster in the vector.
    vMonsterNames.push_back("Pokermon");
    vMonsterNames.push_back("FireFly");
    vMonsterNames.push_back("Batty");
    vMonsterNames.push_back("IceQueen");
    vMonsterNames.push_back("DarkAngel");
    vMonsterNames.push_back("Death Lord");
    vMonsterNames.push_back("GrimReeper");
    vMonsterNames.push_back("Freddy");  
    vMonsterNames.push_back("Pokeachew");
    vMonsterNames.push_back("Charmanda");
    vMonsterNames.push_back("Godzilla");
    vMonsterNames.push_back("Deathwing");
    vMonsterNames.push_back("Gremlin");
    vMonsterNames.push_back("Shrek");
    vMonsterNames.push_back("Chucky");
    
    return vMonsterNames;
}

//This function is used to help delete the correct monster when its health is at 0
// or the monster is dead and needed to be removed from the vector and deleted from the heap.
int findVectorLocation(vector<Monster*>& vPlayerMonsters, int nMonsterHealth)
{
    //Search through the players vector untill a monster with the provided health is found
    // as this is always 0 it will only return the monster that died.
    for (int i = 0; i < vPlayerMonsters.size(); i++) 
    {
        if (nMonsterHealth == vPlayerMonsters[i]->getMonsterHealth()) 
        {
            return i;
        }
    }
    
    return -1;
}

//This function is used to cast magic for the magic monsters, it returns 
//an int for the amount of magic cast or a -1 for no magic.
int MagicCast(MagicMonster* magicMonster)
{
    int nTmpMagicPower = magicMonster->getMagicPower();
    //tmpMagic cast will either be a -1 if unsuccessfull or a higher int if successfull
    int nTmpMagicCast = magicMonster->didUseMagic(nTmpMagicPower);
    
    
    return nTmpMagicCast;
}

//This function is used to check the monster passed in has the does have magic flag set to true
// it then static casts the monster to a magic monster.(Matt spoke of this method in his lecture 
//in week8, not the best Object orientated way but passable on this assignment I believe he said).
MagicMonster* upCastMonster(Monster* chosenMonster)
{
    MagicMonster* pPchosenMagicMon;
    
    if(chosenMonster->getBoolMagicMonster() == true) 
    {
        //Static cast to magic monster both p1 & p2 monsters.
        pPchosenMagicMon = static_cast<MagicMonster*>(chosenMonster);

        //Show the player the returning magic monsters stats.
        cout << pPchosenMagicMon->displayMonster() << endl;
    }
    
    return pPchosenMagicMon;
}

