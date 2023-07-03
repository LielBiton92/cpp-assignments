#include "string"
#include <iostream>
#include "mat.hpp"
#include <stdexcept>
#include <vector>
using namespace ariel;
using namespace std;

  

    int rand_range(int min, int max){
    int range = max - min + 1;
    int random = (rand() % range + min);
    if (random % 2 == 0 ){
        random +=1;
        return (random);
    }
    else{
        return random;
    }
    
}

int main(){
    bool flag = true ;
    int colls ; 
    int rows;
    char a;
    char b;
    char x ; 


    while(flag){
        cout << endl;
        cout <<"•"<< "To insert numbers, type A" << endl;
        cout <<"•"<<"for random variables , type B"<< endl;
        cout <<"•"<< " to quit , type Q"<< endl;
        cin >> x ; 
        

        //input numbers
        if (x =='A'){
            cout << "Insert column size" << endl;
            cin >> colls ;
            cout << "Insert a row  size" << endl;
            cin >> rows ;
            cout << "enter a char" << endl;
            cin >> a ;
            cout << "enter a second char" << endl;
            cin >> b ;
            cout << endl ; 
        try {
        ariel::mat(colls , rows , a , b);
        }
        catch(exception& e){
            cout << e.what() << endl;
        }
        }
        //random rows and colls
        else if (x=='B'){

            colls= rand_range(1, 40); 
            cout << colls<<endl;
            rows = rand_range(1, 40); 
            cout << rows<<endl;
            a = '$'; 
            cout << a << endl;
            b = '@';
            cout << b << endl;
            ariel::mat(colls , rows , a , b);
        }
        // quit
        else if (x =='Q'){
            flag = false;
            cout <<"Bye Bye"<< endl;
        }
        else if (x!=char('A') or x!=char('B') or x!=char('Q')){
            cout << "char "<< x <<" "<< "is not in the list"<<" "<<
             "Please select a value from the list " << endl ;
        }


}
}