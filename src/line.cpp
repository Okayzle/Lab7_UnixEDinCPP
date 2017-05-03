// line.cpp
// Author: [TODO: YOUR NAME HERE]
// SE 2040, Spring 2016
//

#include "line.h"
#include "words.h"
#include <sstream>

using namespace std;

Line::Line(string source) {
   stringstream iss(source);
   string next;
   iss >> next;
   while ( iss ) {
      Word* word_from_pool = WordPool::instance()->get(next);

      // TODO: store word at end of contents
      

      iss >> next;
   }
}

bool Line::contains(string target) const {
   // TODO: implement body of this method


}

string Line::to_string() const {
   string result = "";
   for(auto wp : contents) {
      if ( !result.empty() )
         result += ' ';
      result += wp->value();
   }
   return result;
}

