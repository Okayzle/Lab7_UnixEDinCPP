
#include "object.h"

int CountedObject::object_count = 0;

CountedObject::CountedObject() {
   ++object_count;
}

CountedObject::~CountedObject() {
   --object_count;
}
