// line.h: used to store document lines
//
// do not change this file
//

#ifndef _line_h
#define _line_h

#include "object.h"
#include <string>
#include <vector>

// forward declaration - don't need full class since only use pointers here
class Word;

// a single line of words; assumes words are separated by single spaces
class Line : public CountedObject {
public:
   // break source into words and store each in contents
   Line(std::string source);

   // Note this class has no destructor - deleting the Word*
   //   objects in contents would create memory problems
   //   and the vector reclaimed automatically.

   // returns true if target is in contents
   bool contains(std::string target) const;

   // return words separated by a single space
   std::string to_string() const;

private:   
   std::vector<Word*> contents;
};

#endif
