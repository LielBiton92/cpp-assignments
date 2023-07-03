#include "string"
#include <iostream>
#include "mat.hpp"
#include "vector"
#include <stdexcept>
using namespace ariel;
using namespace std;
const int MAX = 126;
const int MIN = 33;
string resandprint(vector<vector<char> >&rug ,int rows , int colls );


string ariel::mat(int colls , int rows , char a ,char b){
    if(rows % 2 == 0 || colls % 2 ==0 ){
        throw std::invalid_argument("error : numbers cannot be even");
    }
        
    if(a < MIN || a>MAX || b < MIN || b > MAX){
        throw std::invalid_argument("error : incorrect char");
    }
    if(rows <= 0 || colls <=0 ){
        throw std::invalid_argument("error : the rows and columns must be a positive numbers ");
    }


    char temp = 0;
    int start_row = 0 ;
    int i = 0 ;
    int start_col = 0 ;
    int size_rows = rows ; 
    int size_colls = colls;
    string res;

    vector<vector<char>> rug (rows,vector<char>(colls));
    
    

    while(start_row<rows && start_col<colls){
        //feel the first+last row        
        for(i = start_col ;i<colls ; i++){
            rug[start_row][i]=a;
            rug[rows-1][i]=a;
        }
        start_row++;
        rows--;

        // fill the last+first col      
        for(i = start_row;i<rows; i++){
            rug[i][colls-1]=a;
            rug[i][start_col]=a;

        }
        colls--;
        start_col++;
           

        //flip char 
        if(a != b){
         temp = a;
         a = b ; 
         b = temp;     
     }
    }  
        res = resandprint(rug,size_rows,size_colls);

    return res;
}


string resandprint(vector<vector<char>>&rug ,int rows , int colls )
{
    string ans;
for(int i = 0;i < rows;i++){ 
        if(i>0){
            cout << endl;
        }
        for(int j = 0 ; j <colls; j++){
            cout << rug[i][j] << " ";
            ans+=rug[i][j];
        }
    }
    return ans;

}












    

    

