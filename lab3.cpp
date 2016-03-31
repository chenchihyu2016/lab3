#include<vector>
#include<iostream>
#include<fstream>
#include"stdlib.h"
using namespace std;
void insert_sort( vector<int>& v );
int get_size();
void input( vector<int>& v );
void add( vector<int>& v );

int main(){
  int size = get_size();                                                        //get the size
  vector<int> v( size );
  input( v );                                                                   //input data into vector v
  insert_sort( v );                                                             //implement insertion sort
  add( v );                                                                     //add top five big numbers and output
  return 0;
}

void insert_sort( vector<int>& v ){
  int insert;
  int moveItem;
  for( int next = 1; next < v.size(); next++ ){
    insert = v.at(next);
    moveItem = next;
    while( ( moveItem > 0 ) && ( v.at( moveItem-1 ) > insert ) ){
      v.at(moveItem) = v.at(moveItem-1);
      moveItem--;
    }
    v.at(moveItem) = insert;
  }
}
int get_size(){
  int size;
  ifstream inFile( "file.in",ios::in );
  if( !inFile ){
		cerr<<" Infile opening FAILED. " << endl;
		exit(1);
	}
  inFile >> size;

  inFile.close();
  return size;
}
void input( vector<int>& v ){
  int value;
  ifstream inFile( "file.in",ios::in );
  inFile >> value;
  for( int i = 0; i < v.size(); i++ ){
    inFile >> value;
    v.at(i) = value;
  }
  inFile.close();
}
void add( vector<int>& v ){
  int sum = 0;
  for( int i = v.size()-1; i > v.size()-6 ; i-- )
    sum = sum + v.at(i);
  cout << sum << endl;
}
