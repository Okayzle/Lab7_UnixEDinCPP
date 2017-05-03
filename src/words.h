//
// words.h: individual words from input, stored using the flyweight pattern
//
// do not change this file
//

#ifndef _word_h
#define _word_h

#include <string>
#include <unordered_map>

// A single, immutable word
class Word {
public:
   Word(std::string word) : _value{word} { }
   std::string value() const { return _value; }
private:
   std::string _value;
};

// a singleton pool of words: there is just one copy of each word
//   and that copy is retrieved using get()
class WordPool {
private:
   WordPool() { }
public:
   // return the single instance of WordPool, creating it when necessary
   static WordPool* instance() {
      if ( !_pool )
         _pool = new WordPool();
      return _pool;
   }

   // retrieve the Word containing string target
   Word* get(std::string target) {
      if ( _words[target] == nullptr )
         _words[target] = new Word(target);
      return _words[target];
   }

private:
   static WordPool* _pool;      // initialized in ed.cpp
   std::unordered_map<std::string, Word*> _words;
};

#endif
