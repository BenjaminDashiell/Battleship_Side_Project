#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
//
struct ShipStatus{
    bool YouSunkMyBattleship = false;
    string ShipID = "SHIPTYPENUMBER";
    string Coordinate1 = "HIT";
    bool Coordinate1Hit = false;
    string Coordinate2 = "HIT";
    bool Coordinate2Hit = false;
    string Coordinate3 = "HIT";
    bool Coordinate3Hit = false;
    string Coordinate4 = "HIT";
    bool Coordinate4Hit = false;
    string Coordinate5 = "HIT";
    bool Coordinate5Hit = false;
    ShipStatus *next = nullptr;

    ShipStatus(){} // default constructor

    // Parametrized constructor
    ShipStatus(bool sunk, string id, string c_one, bool c_one_hit,
                string c_two, bool c_two_hit, string c_three, bool c_three_hit,
                string c_four, bool c_four_hit, string c_five, bool c_five_hit) : YouSunkMyBattleship(sunk), ShipID(id),
      Coordinate1(c_one), Coordinate1Hit(c_one_hit),
      Coordinate2(c_two), Coordinate2Hit(c_two_hit),
      Coordinate3(c_three), Coordinate3Hit(c_three_hit),
      Coordinate4(c_four), Coordinate4Hit(c_four_hit),
      Coordinate5(c_five), Coordinate5Hit(c_five_hit), next(NULL) {}
};
//
class BattleshipGame{
    private:
        ShipStatus* head;
        string battlefield[10][10];
    public:
        BattleshipGame();
        ShipStatus* addShip(string shipID, string coordinate1, string coordinate2, string coordinate3, string coordinate4, string coordinate5);
        string autofill(string coordinate, string vertical_or_horizontal);
        void placeBattleshipsHelper(string boatType, int start, int shipMax);
        void setDefaultBattlefield();
        void fillBattlefield();
        void placeBattleships();
        void printBattlefield();
        void checkHitorMiss(string guess);
        bool remainingShips();
        void checkShipStatus();
        void updateShipStatus(string guess);
        bool collisionCheck(string coordinate);
        void printShipStatus();
};
//
class Player : public BattleshipGame{
  public:
    string playerName;
    void setPlayerName(string name){
      playerName = name;
    }
    string getPlayerName(){
      return playerName;
    }
};
////
BattleshipGame::BattleshipGame(){
  head = nullptr;
};
//
ShipStatus* BattleshipGame::addShip(string shipID, string coordinate1, string coordinate2, string coordinate3, string coordinate4, string coordinate5){
    ShipStatus* insert = new ShipStatus(false, shipID, coordinate1, false, coordinate2, false, coordinate3, false, coordinate4, false, coordinate5, false);
    if(insert->Coordinate1 == "HIT"){
        insert->Coordinate1Hit = true;
    }
    if(insert->Coordinate2 == "HIT"){
        insert->Coordinate2Hit = true;
    }
    if(insert->Coordinate3 == "HIT"){
        insert->Coordinate3Hit = true;
    }
    if(insert->Coordinate4 == "HIT"){
        insert->Coordinate4Hit = true;
    }
    if(insert->Coordinate5 == "HIT"){
        insert->Coordinate5Hit = true;
    }
    //
    if(head == NULL){
      head = insert;
      //cout << "Ship successfully added" << endl;
      return head;
    }
    else{
        ShipStatus* traverse = head;
        while(traverse->next != NULL){
          traverse = traverse->next;
        }
        traverse->next = insert;
    }
    //cout << "Ship successfully added" << endl;
    return head;
};
//
void BattleshipGame::setDefaultBattlefield(){
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      battlefield[i][j] = " ";
    }
  }
};
//
void BattleshipGame::fillBattlefield(){
  ShipStatus* traverse = head;
  while(traverse != NULL){
    string coordinate;
    char A_coordinate;
    string B_coordinate = "";
    int ascii;
    int xCoordinate;
    int yCoordinate;
    //
    if(traverse->Coordinate1 != "HIT"){
      coordinate = traverse->Coordinate1;
      A_coordinate = coordinate[0];
      for(int i = 1; i < coordinate.length(); i++)
      {
        B_coordinate = B_coordinate + coordinate[i];
        //cout << B_coordinate << endl;
      }
      ascii = int(A_coordinate);
      ascii = ascii - 65;
      //cout << ascii << endl;
      xCoordinate = ascii;
      yCoordinate = stoi(B_coordinate) - 1;
      //cout << "xCoordinate: " << xCoordinate << endl;
      //cout << "yCoordinate: " << yCoordinate << endl;
      battlefield[xCoordinate][yCoordinate] = "S";
    }
    B_coordinate = "";
    if(traverse->Coordinate2 != "HIT"){
      coordinate = traverse->Coordinate2;
      A_coordinate = coordinate[0];
      for(int i = 1; i < coordinate.length(); i++)
      {
        B_coordinate = B_coordinate + coordinate[i];
        //cout << B_coordinate << endl;
      }
      ascii = int(A_coordinate);
      ascii = ascii - 65;
      //cout << ascii << endl;
      xCoordinate = ascii;
      yCoordinate = stoi(B_coordinate) - 1;
      //cout << "xCoordinate: " << xCoordinate << endl;
      //cout << "yCoordinate: " << yCoordinate << endl;
      battlefield[xCoordinate][yCoordinate] = "S";
    }
    B_coordinate = "";
    if(traverse->Coordinate3 != "HIT"){
      coordinate = traverse->Coordinate3;
      A_coordinate = coordinate[0];
      for(int i = 1; i < coordinate.length(); i++)
      {
        B_coordinate = B_coordinate + coordinate[i];
        //cout << B_coordinate << endl;
      }
      ascii = int(A_coordinate);
      ascii = ascii - 65;
      //cout << ascii << endl;
      xCoordinate = ascii;
      yCoordinate = stoi(B_coordinate) - 1;
      //cout << "xCoordinate: " << xCoordinate << endl;
      //cout << "yCoordinate: " << yCoordinate << endl;
      battlefield[xCoordinate][yCoordinate] = "S";
    }
    B_coordinate = "";
    if(traverse->Coordinate4 != "HIT"){
      coordinate = traverse->Coordinate4;
      A_coordinate = coordinate[0];
      for(int i = 1; i < coordinate.length(); i++)
      {
        B_coordinate = B_coordinate + coordinate[i];
      }
      ascii = int(A_coordinate);
      ascii = ascii - 65;
      //cout << ascii << endl;
      xCoordinate = ascii;
      yCoordinate = stoi(B_coordinate) - 1;
      battlefield[xCoordinate][yCoordinate] = "S";
      //cout << "xCoordinate: " << xCoordinate << endl;
      //cout << "yCoordinate: " << yCoordinate << endl;
    }
    B_coordinate = "";
    if(traverse->Coordinate5 != "HIT"){
      coordinate = traverse->Coordinate5;
      A_coordinate = coordinate[0];
      for(int i = 1; i < coordinate.length(); i++)
      {
        B_coordinate = B_coordinate + coordinate[i];
      }
      ascii = int(A_coordinate);
      ascii = ascii - 65;
      //cout << ascii << endl;
      xCoordinate = ascii;
      yCoordinate = stoi(B_coordinate) - 1;
      battlefield[xCoordinate][yCoordinate] = "S";
      //cout << "xCoordinate: " << xCoordinate << endl;
      //cout << "yCoordinate: " << yCoordinate << endl;
    }
    B_coordinate = "";
    //
    traverse = traverse->next;
  }
};
//
void BattleshipGame::printBattlefield(){
  int ascii = 65;
  cout << endl;
  cout << "   |1 2 3 4 5 6 7 8 9 10" << endl;
  cout << "   ---------------------" << endl;
  for(int i = 0; i < 10; i++){
      cout << "  " << (char)ascii << "|";
      for (int j = 0; j < 10; j++){
          cout << battlefield[i][j];  //this will be where it checks for space status
          cout << "|";
      }
      cout << endl << "   ---------------------" << endl << endl;
      ascii++;
  }
};
//
string BattleshipGame::autofill(string coordinate, string vertical_or_horizontal){
    char A_coordinate;
    char B_coordinate;
    int ascii;
    string autofill;
    if(vertical_or_horizontal == "V" || vertical_or_horizontal == "v"){
        A_coordinate = coordinate[0];
        B_coordinate = coordinate[1];   //this remains the same
        //cout << A_coordinate << endl;
        //cout << B_coordinate << endl;
        ascii = int(A_coordinate) + 1;
        A_coordinate = (char)ascii;
        //cout << A_coordinate << endl;
        //cout << B_coordinate << endl;
        string a(1, A_coordinate);
        string b(1, B_coordinate);
        autofill = a + b;
        //cout << autofill << endl;
    }
    else{
      A_coordinate = coordinate[0];   //this remains the same
      B_coordinate = coordinate[1];
      //cout << A_coordinate << endl;
      //cout << B_coordinate << endl;
      ascii = int(B_coordinate) + 1;
      B_coordinate = (char)ascii;
      //cout << A_coordinate << endl;
      //cout << B_coordinate << endl;
      string a(1, A_coordinate);
      string b(1, B_coordinate);
      autofill = a + b;
      //cout << autofill << endl;
    }
    return autofill;
};
//
bool BattleshipGame::collisionCheck(string coordinate){
    ShipStatus* traverse = head;
    if(traverse == NULL){
      return true;
    }
    while(traverse != NULL){
      if(traverse->Coordinate1 == coordinate || traverse->Coordinate2 == coordinate || traverse->Coordinate3 == coordinate || traverse->Coordinate4 == coordinate || traverse->Coordinate5  == coordinate){
            return false;   //there is not a collision
      }
      traverse = traverse->next;
    }
    return true;  //there is a collision
};
//
void BattleshipGame::placeBattleshipsHelper(string boatType, int start, int shipMax){
    string shipID = "";
    string coordinate = "";
    string vertical_or_horizontal = "V";
    bool v_h = false;
    ShipStatus* ptr = NULL;
    string autofill_one = "HIT";
    string autofill_two = "HIT";
    string autofill_three = "HIT";
    string autofill_four = "HIT";
    string xCoordinate = "";
    bool validInput = false;
    bool validInsert = false;
    //
    if(shipMax > 1){
      cout << "There are " << shipMax << " " << boatType << "s." << endl;
    }
    else{
      cout << "There is one " << boatType << "." << endl;
    }
    cout << "Enter where you would like to place them." << endl;
    while(start < shipMax){
      start++;
      while(validInsert == false){
        while(validInput == false){
          cout << boatType << " " << start << " Starting Coordinate: ";
          cin >> coordinate;
          if(coordinate.length() > 1 && coordinate.length() < 4){
            for(int i = 1; i < coordinate.length(); i++){
              xCoordinate = xCoordinate + coordinate[i];
            }
            if(stoi(xCoordinate) < 11 && stoi(xCoordinate) > 0 && coordinate[0] >= 'A' && coordinate[0] < 'K' && collisionCheck(coordinate) == true){
              //As long as the X Coordinate is within 1-10 and the Y coordinate is within A-J
              validInput = true;
            }
            else{
              cout << "Invalid Input. Please enter something else." << endl;
            }
            xCoordinate = "";
          }
          else{
            cout << "Invalid Input. Please enter something else." << endl;
          }
        }
        if(boatType != "Tug Boat"){
          while(v_h == false)
          {
            cout << "Would you like to place it vertically or horizontally" << endl;
            cout << "Type V for vertically or H for horizontally" << endl;
            cin >> vertical_or_horizontal;
            if(vertical_or_horizontal == "V" || vertical_or_horizontal == "v" || vertical_or_horizontal == "H" || vertical_or_horizontal == "h")
            {
              v_h = true;
            }
            else
            {
              cout << "Invalid Input. Please enter something else." << endl;
            }
          }
        }
        shipID = boatType + " " + to_string(start);
        if(boatType == "Tug Boat"){
          addShip(shipID, coordinate, "HIT", "HIT", "HIT", "HIT");
        }
        else if(boatType == "Destroyer"){
          autofill_one = autofill(coordinate, vertical_or_horizontal);
          addShip(shipID, coordinate, autofill_one, "HIT", "HIT", "HIT");
        }
        else if(boatType == "Submarine"){
          autofill_one = autofill(coordinate, vertical_or_horizontal);
          autofill_two = autofill(autofill_one, vertical_or_horizontal);
          addShip(shipID, coordinate, autofill_one, autofill_two, "HIT", "HIT");
        }
        else if(boatType == "Cruiser"){
          autofill_one = autofill(coordinate, vertical_or_horizontal);
          autofill_two = autofill(autofill_one, vertical_or_horizontal);
          autofill_three = autofill(autofill_two, vertical_or_horizontal);
          addShip(shipID, coordinate, autofill_one, autofill_two, autofill_three, "HIT");
        }
        else{
          autofill_one = autofill(coordinate, vertical_or_horizontal);
          autofill_two = autofill(autofill_one, vertical_or_horizontal);
          autofill_three = autofill(autofill_two, vertical_or_horizontal);
          autofill_four = autofill(autofill_three, vertical_or_horizontal);
          addShip(shipID, coordinate, autofill_one, autofill_two, autofill_three, autofill_four);
        }
        validInsert = true;
      }
      validInput = false;  //reset
      validInsert = false;  //reset
      v_h = false;  //reset
    }
};
//
void BattleshipGame::placeBattleships(){
    placeBattleshipsHelper("Tug Boat", 0, 4);
    cout << "For the rest of the ships, you will be asked where the starting coordinate will be (one end) and how to place it (horizontally or vertically)" << endl;
    placeBattleshipsHelper("Destroyer", 0, 2);
    placeBattleshipsHelper("Submarine", 0, 2);
    placeBattleshipsHelper("Cruiser", 0, 1);
    placeBattleshipsHelper("Carrier", 0, 1);
};
//
void BattleshipGame::checkHitorMiss(string guess){
    char A_coordinate;
    string B_coordinate = "";
    int ascii;
    int xCoordinate;
    int yCoordinate;
    string autofill;
    //
    A_coordinate = guess[0];
    for(int i = 1; i < guess.length(); i++){
      B_coordinate = B_coordinate + guess[i];
    }
    ascii = int(A_coordinate);
    ascii = ascii - 65;
    //cout << ascii << endl;
    xCoordinate = ascii;
    yCoordinate = stoi(B_coordinate) - 1;
    if(battlefield[xCoordinate][yCoordinate] == "S"){
      cout << "Direct Hit!" << endl;
      battlefield[xCoordinate][yCoordinate] = "H";
      updateShipStatus(guess);
    }
    else if(battlefield[xCoordinate][yCoordinate] == "H" || battlefield[xCoordinate][yCoordinate] == "M"){
      cout << "You Already Tried This Coordinate!" << endl;
    }
    else{
      cout << "You Missed!" << endl;
      battlefield[xCoordinate][yCoordinate] = "M";
    }
    //cout << "xCoordinate: " << xCoordinate << endl;
    //cout << "yCoordinate: " << yCoordinate << endl;
};
//
bool BattleshipGame::remainingShips(){
    int remaining = 10;
    ShipStatus* traverse = head;
    while(traverse != NULL){
      if(traverse->YouSunkMyBattleship == true){
          remaining--;
      }
      traverse = traverse->next;
    }
    if(remaining == 0)
    {
      return true;
    }
    return false;
};
//
void BattleshipGame::checkShipStatus(){
    ShipStatus* traverse = head;
    while(traverse != NULL){
      if(traverse->YouSunkMyBattleship == false){
          if(traverse->Coordinate1Hit == true && traverse->Coordinate2Hit == true && traverse->Coordinate3Hit == true && traverse->Coordinate4Hit == true && traverse->Coordinate5Hit == true){
              cout << "Congrats. You sunk " << traverse->ShipID << endl;
              traverse->YouSunkMyBattleship = true;
          }
      }
      traverse = traverse->next;
    }
};
//
void BattleshipGame::printShipStatus(){
    ShipStatus* traverse = head;
    cout << "|--------------------------------|" << endl;
    while(traverse != NULL){
      cout << traverse->ShipID << " Status: ";
      if(traverse->YouSunkMyBattleship == true){
        cout << "Destroyed"<< endl;
      }
      else{
        cout << "Active"<< endl;
      }
      traverse = traverse->next;
    }
    cout << "|--------------------------------|" << endl << endl;
};
//
void BattleshipGame::updateShipStatus(string guess){
    cout << guess << endl;
    ShipStatus* traverse = head;
    while(traverse != NULL){
      if(traverse->Coordinate1 == guess){
        traverse->Coordinate1Hit = true;
      }
      else if(traverse->Coordinate2 == guess){
        traverse->Coordinate2Hit = true;
      }
      else if(traverse->Coordinate3 == guess){
        traverse->Coordinate3Hit = true;
      }
      else if(traverse->Coordinate4 == guess){
        traverse->Coordinate4Hit = true;
      }
      else if(traverse->Coordinate5 == guess){
        traverse->Coordinate5Hit = true;
      }
      traverse = traverse->next;
    }
};
//
void welcomescreen(){
    cout << "|--------------------------------|" << endl;
    cout << "|                                |" << endl;
    cout << "|                    ----        |" << endl;
    cout << "|        ---         --------    |" << endl;
    cout << "| ---------------------------    |" << endl;
    cout << "| ------------------------------ |" << endl;
    cout << "|    --------------------------- |" << endl;
    cout << "|       ------------------------ |" << endl;
    cout << "|                                |" << endl;
    cout << "|           BATTLESHIP           |" << endl;
    cout << "| ------------------------------ |" << endl;
};
//
int main(){
    Player player_one;
    Player player_two;
    string name;
    welcomescreen();
    cout << "Enter Your Names:" << endl;
    cout << "Player 1: ";
    cin >> name;
    player_one.setPlayerName(name);
    cout << "Player 2: ";
    cin >> name;
    player_two.setPlayerName(name);
    //
    player_one.setDefaultBattlefield();
    cout << "Player 1: Place Your Battleships" << endl;
    player_one.placeBattleships();
    player_one.fillBattlefield();
    //
    player_two.setDefaultBattlefield();
    cout << "Player 2: Place Your Battleships" << endl;
    player_two.placeBattleships();
    player_two.fillBattlefield();
    //
    player_one.printBattlefield();  //DEBUG ONLY
    player_two.printBattlefield();  //DEBUG ONLY
    cout << player_one.getPlayerName() << endl;
    player_one.printShipStatus();
    cout << player_two.getPlayerName() << endl;
    player_two.printShipStatus();
    //
    string guess;
    bool player_one_check = false;
    bool player_two_check = false;
    while(player_one_check == false && player_two_check == false){
      cout << "Player One Guess: ";
      cin >> guess;
      player_two.checkHitorMiss(guess);
      player_two.checkShipStatus();
      player_one_check = player_two.remainingShips();
      if(player_one_check != true){
        cout << "Player Two Guess: ";
        cin >> guess;
        player_one.checkHitorMiss(guess);
        player_one.checkShipStatus();
        player_two_check = player_one.remainingShips();
      }
    }
    if(player_one_check == true){
      cout << player_one.getPlayerName() << "is the winner!" << endl;
    }
    else{
      cout << player_two.getPlayerName() << "is the winner!" << endl;
    }

};
//
