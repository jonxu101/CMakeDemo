#include "include/MyClass.h"

MyClass::MyClass() : a(0) {

}

MyClass::MyClass(int b) : a(b) {
    
}

MyClass::~MyClass() {
    
}

int MyClass::get() {
    return a;
}