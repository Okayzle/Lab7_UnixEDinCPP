//
// doc.h
// Author: [TODO: YOUR NAME HERE]
// SE 2040, Spring 2017
//

#ifndef _doc_h
#define _doc_h

#include "object.h"
#include <string>
#include <list>
#include <map>

// Line declaration - this file does not need the details of Line, just that
//    it is a valid class name
class Line;

// maintains the list of lines making up a document to be edited
class Document : public CountedObject {
public:
   Document();

   // destroy the document
   virtual ~Document();
   
   // read lines from specified file
   void read(std::string source_file);

   // add single line to end of current document
   void append(std::string new_line);

   // insert line just before specified line number
   void insert(int before, std::string new_line);
   
   // delete specified line
   void remove(int num);
   
   // delete lines between start and end, inclusive
   void remove(int start, int end);

   // list contents of document to cout
   void list();

   // return map of line numbers to lines containing target_text, starting from
   //    specified line
   std::map<int, Line*> find(std::string target_text, int start);

   // total number of lines in document
   int  line_count() const { return text.size(); }

private:
   std::list<Line*> text;
   // TODO: add private methods, data as needed


};

#endif
