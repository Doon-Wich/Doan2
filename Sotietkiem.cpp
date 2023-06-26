#pragma once
#include "Player.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class Team
{
    string name, location, coach,id_team;
    vector<Player> list_player;

public:
    Team(){};
    Team(string _id,string _name, string _location, string _coach) : id_team(_id),name(_name), location(_location), coach(_coach){};
    void addPlayer(Player player);
    void insert_inf();
    void show_inf();
    void insert_player_from_file();
    void find_player_of_id_team(string id);
    string get_name();
    string get_id();
    void insert_team_to_file();
    string get_coach();
    string get_location();
    void savefilecsv();
    bool operator==(const Team& other)const;
    void SavefileCsvPlayerOfTeam(string id);
};
void Team::SavefileCsvPlayerOfTeam(string id){
    insert_player_from_file();
    for (Player &player : list_player){
        if (player.get_idteam()==id)
        {
            player.savefilecsv(id);
            player.show_inf();
        }
    }
}

void Team::savefilecsv(){
    insert_player_from_file();
    ofstream MyFile("info/team.csv",ios::app);
    MyFile<<id_team<<";"<<name<<";"<<location<<";"<<coach<<endl;
    MyFile.close();
}
bool Team::operator==(const Team& other)const{
    return name == other.name&&location==other.location&&coach == other.coach&&id_team==other.id_team;
}
void Team::insert_player_from_file(){
    ifstream read_player("info/player.txt"); // mở file để đọc
    string input;                            // đọc từng dòng rồi cho vào input
    vector<string> all_lines;                // 1 mảng gồm nhiều input   
    while (getline(read_player, input))
    {
        all_lines.push_back(input); // thêm input vào mảng
    }
    
    string item;
    for (const string &line : all_lines)
    {
        vector<string> elements;        
        stringstream ss(line);
        while (getline(ss, item, ';'))
        {
            elements.push_back(item);
        }
        Player player(elements[0], elements[1], elements[2], elements[3], elements[4], elements[5], elements[6],elements[7]);
        list_player.push_back(player);
    }
}

void Team::find_player_of_id_team(string id){
    Team::insert_player_from_file();
    for (Player &player : list_player){
        if (player.get_idteam()==id)
        {
            player.show_inf();
        }
    }
}

string Team::get_location(){
    return location;
}
string Team::get_coach(){
    return coach;
}
void Team::insert_team_to_file(){
    ofstream MyFile("info/Team.txt",ios::app);
    MyFile<<id_team<<";"<<name<<";"<<location<<";"<<coach<<endl;
    MyFile.close();
}

string Team::get_id(){
    return id_team;
}
string Team::get_name(){
    return name;
}
void Team::addPlayer(Player player)
{
    list_player.push_back(player);
}
void Team::insert_inf()
{
    cout<<"Nhập id team : ";
    fflush(stdin);
    getline(cin,id_team);
    cout << "Nhập tên đội bóng : ";
    fflush(stdin);
    getline(cin, name);
    cout << "Nhập địa phương : ";
    fflush(stdin);
    getline(cin, location);
    cout << "Nhập tên huấn luyện viên : ";
    fflush(stdin);
    getline(cin, coach);
}
void Team::show_inf()
{   

    cout << setw(8) << id_team << setw(15) << name << setw(17) << location << setw(20) << coach << endl;

}
