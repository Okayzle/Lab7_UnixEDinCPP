/*
 * doc.cpp
 *
 *  Created on: May 3, 2017
 *      Author: thaokaye
 */

#include "object.h"
#include "doc.h"
#include "line.h"
#include <string>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Document::Document(){

}

Document::~Document(){
    delete this;
}

/**
 * loops through the string of the source_file
 */
void Document::read(std::string source_file){
    std::string tempLine;
    std::ifstream in(source_file);
    cout << "about to read" << endl;
    // TODO: add correct functionality that allows proper storage
    while(getline(in, tempLine)){
        Line line(tempLine);    // create a line pointer
        Line* lnptr = &line;    // set a pointer to that temp line

        text.push_front(lnptr);
        cout << tempLine << endl;
    }

    in.close();
    cout << "done reading!" << endl;
}

void Document::append(std::string new_line){
    cout << "about to append" << endl;
}

void Document::insert(int before, std::string new_line){
    cout << "about to insert" << endl;
}

void Document::remove(int num){
    cout << "about to remove a number" << endl;
}

void Document::remove(int start, int end){
    cout << "about to remove between two point" << endl;
}

void Document::list(){
    auto text_itr = text.begin();
    cout << "lmao";

    while (text_itr != text.end()){
        // TODO: start here!
        cout << (*text_itr)->to_string() << endl;
        cout << "Ayy";
    }

    cout << "about to list" << endl;
}

std::map<int, Line*> Document::find(std::string target_text, int start){

}
