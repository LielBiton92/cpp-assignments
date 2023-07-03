#include "string"
#include <iostream>
#include "mat.hpp"
#include "vector"
#include <stdexcept>
using namespace ariel;
using namespace std;
const int MAX = 126;
const int MIN = 33;


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


    char n1 = a;
    char n2 = b;
    char temp = 0;
    int start_row = 0 ;
    int i = 0 ;
    int start_col = 0 ;
    int size_rows = rows ; 
    int size_colls = colls;
    string res;

    vector<vector<char>> rug (rows,vector<char>(colls,'$'));
    
    

    while(start_row<rows && start_col<colls){
        //feel the first row        
        for(i = start_col ;i<colls ; i++){
            rug[start_row][i]=n1;
        }
        start_row++;

        // fill the last col      
        for(i = start_row;i<rows; i++){
            rug[i][colls-1]=n1;
        }
        colls--;
        
        
        //fill the last row
        if(start_row<rows){
            for(i = colls-1; i>=start_col ; i--){
                rug[rows-1][i]=n1;
            }
            rows--;
            
        }
        //fill the first col
        if(start_col<colls)
        {
            for(i=rows-1; i>=start_row ; i--){
                rug[i][start_col]=n1;
            }
            start_col++;

        }
        //flip char 
        if(n1 != int(n2)){
         temp = n1;
         n1 = n2 ; 
         n2 = temp;     
     }
    }  
    for(int i = 0;i < size_rows;i++){ 
        if(i>0){
            cout << endl;
        }
        for(int j = 0 ; j <size_colls; j++){
            cout << rug[i][j] << " ";
            res += rug[i][j];
        }
    }
    return res;
}







    

    

