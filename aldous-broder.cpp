#include<random>
#include<string>
#include"aldous-broder.h"

using namespace std;

AldousBroder::AldousBroder(){

}

void AldousBroder::generateMaze(int rows, int columns){
    MazeGenerator::createEmpty(rows, columns);
    int x = rand() % rows;
    int y = rand() % columns;
    vector<int> unvisited = x * y - 1;

    while true {
        //breaks the loop if everything is visited
        //this code is complete and utter bs and does not work
        //please dear god actually make this correct code
        if(unvisited == 0) {
            break;
        }
        int n = rand() % 4;
        //1 = up
        if(n == 1){

        }
        //2 = right
        else if(n == 2){

        }
        //3 = down
        else if(n == 3){

        }
        //4 = left
        else if(n == 4){

        }
        
    }
}