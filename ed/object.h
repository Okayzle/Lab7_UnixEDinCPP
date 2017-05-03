// object.h: a simple reference-counted object; used to ensure no memory leaks
// Make no changes to this file.

#ifndef _object_h
#define _object_h

class CountedObject {
   static int object_count;
public:
   CountedObject();
   virtual ~CountedObject();
   static int objectCount() { return object_count; }
   // disallow copy, assignment, move
   CountedObject(const CountedObject&) =delete;
   const CountedObject& operator=(const CountedObject&) =delete;
   CountedObject(CountedObject&&) =delete;
   void operator=(CountedObject&&) =delete;   
};

#endif
