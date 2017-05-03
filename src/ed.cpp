// ed.cpp: main code for editor project

#include "words.h"
#include "line.h"
#include "doc.h"
#include "object.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

WordPool* WordPool::_pool = nullptr;

constexpr bool DEBUG = true;
static const int NO_POSITION = -1;

// main class for program: takes input commands and processes them
class EditorManager {
public:

   // process edit commands until eof
   void process_edit_commands();   

private:
   Document doc;

   // parse input line into a command; not all commands use line numbers,
   //    but they are accepted anyways
   void parse_command(string command_line, int &first_line, int &last_line,
                      char &cmd, string &text);

   // execute the given command
   void do_command(int start_line, int last_line, char cmd, string text);
};

// set cin to refer to the appropriate input stream
void setup_input_stream(int argc, char *argv[], ifstream &alternative_input);

int main(int argc, char *argv[]) {
   ifstream alternative_input; // used if specify filename on command line
   try {
      setup_input_stream(argc, argv, alternative_input);
      {
         EditorManager edman;
         edman.process_edit_commands();
      }
      cout << "[Processed all commands.]" << endl;
      if ( CountedObject::objectCount() > 0 ) 
         cout << "**** Error: " << CountedObject::objectCount() 
              << " line and/or document objects left." << endl;
      cout.flush();
   } catch (string& msg) {
      cout << "Abnormal termination: " << msg << endl;
   } catch (const char* msg) {
      cout << "Abnormal termination: " << msg << endl;
   } catch (range_error& err) {
      cout << "Abnormal termination (range error): " << err.what() << endl;
   }
   return 0;
}

void setup_input_stream(int argc, char *argv[], ifstream &alternative_input) {
   if (argc > 0 && argv[1] != nullptr && argv[1][0] != 0) {
      alternative_input.open(argv[1]);
      if (!alternative_input)
         throw string("Could not open ") + argv[1] + " for input.";
      // this magic sets the read buffer for cin to the read buffer for
      //   the input stream (redirecting input from the named file)
      cin.rdbuf(alternative_input.rdbuf());
   }
}

void EditorManager::process_edit_commands() {
   string cmd_line;
   getline(cin, cmd_line);
   while ( cin.good() ) {
      int first_line, last_line;
      char comma, command;
      string rest_of_line;
      parse_command(cmd_line, first_line, last_line, command, rest_of_line);
      if ( command != ' ' && command != '#' )
         do_command(first_line, last_line, command, rest_of_line);
      getline(cin, cmd_line);
   }
}

void EditorManager::parse_command(string cmd_line, 
                                  int &first_line, int &last_line, 
                                  char &command, string &rest_of_line) {
   // try to parse with different formats, setting unspecified line numbers to
   //   NO_POSITION
   char comma;
   istringstream try1(cmd_line);
   try1 >> first_line >> comma >> last_line >> command;
   if ( try1.good() && comma == ',' ) {
      getline(try1, rest_of_line);
   } else {
      istringstream try2(cmd_line);
      try2 >> first_line >> command;
      if ( try2.good() ) {
         last_line = NO_POSITION;
         getline(try2, rest_of_line);
      } else {
         istringstream try3(cmd_line);
         try3 >> command;
         if ( try3.good() ) {
            first_line = last_line = NO_POSITION;
            getline(try3, rest_of_line);
         } else
            cout << ">>> Malformed command line: " << cmd_line << endl;
      }
   }
}

void EditorManager::do_command(int start_line, int end_line, char cmd, string text) {
   // erase leading spaces from text
   while ( text.size() > 0 && text[0] == ' ' )
      text.erase(0, 1);
   // echo command when debugging
   if ( DEBUG )
      cout << "------ " << cmd << "(" << start_line << "," << end_line << "): "
           << text << endl;
   // process command; if command doesn't use line numbers, the line number is
   //   silently ignored
   switch ( cmd ) {
   case 'r':
      doc.read(text);
      break;
   case 'a':
      doc.append(text);
      break;
   case 'i':
      doc.insert(start_line, text);
      break;
   case 'd':
      cout << "Removing " << start_line << " to " << end_line << endl;
      if ( start_line < 0 )
         doc.remove(0, doc.line_count() - 1);
      else if ( end_line == NO_POSITION )
         doc.remove(start_line);
      else
         doc.remove(start_line, end_line);
      break;
   case 'p':
      doc.list();               // start, end ignored
      break;
   case 'f':
   {
      if ( start_line == NO_POSITION )
         start_line = 0;
      map<int, Line*> found_lines = doc.find(text, start_line);
      cout << "Found locations:" << endl;
      for(auto line : found_lines)
         cout << setw(6) << line.first << ": " << line.second->to_string() << endl;
      break;
   }
   default:
      cout << ">>> Unrecognized command: '" << cmd << "' (" 
           << start_line << "," << end_line << "): "
           << text << endl;
   }
}
