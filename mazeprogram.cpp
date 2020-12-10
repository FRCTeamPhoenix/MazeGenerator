#include "mazeprogram.h"

#include <iostream>

using namespace std;

const int SMALL_SIZE = 5;
const int MEDIUM_SIZE = 10;
const int LARGE_SIZE = 25;

MazeProgram::MazeProgram(){

}

void MazeProgram::run(){
    string input = "";

    while(true){
        cout << "Type an algorithm name or type 'quit' to quit" << endl;
        //print algorithm names
        for(auto it = m_generators.begin(); it != m_generators.end(); it++){
            cout << it->first << endl;
        }

        //take input
        input = "";
        while(input != "quit" && m_generators.find(input) == m_generators.end()){
            cout << "> ";
            getline(cin, input);
        }

        //user has quit
        if(input == "quit") return;

        MazeGenerator* generator = m_generators.find(input)->second;

        input = "";

        //prompt user for size
        cout << "Give a size (small, medium, or large)" << endl;
        while(input != "small" && input != "medium" && input != "large"){
            cout << "> ";
            getline(cin, input);
        }

        if(input == "small"){
            generator->generateMaze(SMALL_SIZE, SMALL_SIZE);
        }else if(input == "medium"){
            generator->generateMaze(MEDIUM_SIZE, MEDIUM_SIZE);
        }else{
            generator->generateMaze(LARGE_SIZE, LARGE_SIZE);
        }

        generator->displayMaze();
    }
}

void MazeProgram::addGenerator(string name, MazeGenerator* gen){
    if(m_generators.find(name) == m_generators.end()){
        m_generators.insert(make_pair(name, gen));
    }else{
        throw "Generator "+name+" already exists";
    }
}