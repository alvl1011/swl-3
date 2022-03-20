#include "String.h"
#include <string.h>

void testEmpty();
void testSingleChar();
void testCharPointer();
void testCount();
void testStringObject();
void successMessage();
void failMessage();
void testArray();
void testAssign();
void testConcat();

ostream& operator<< (ostream &out, String &s) {
    for(int i=0; i<s.size; i++) {
        out << s.str[i];
    }
    
    return out;
}

int main() {
    testEmpty();
    testSingleChar();
    testCharPointer();
    testCount();
    testStringObject();
    testArray();
    testAssign();
    testConcat();
}

/*
    --------------TESTS--------------
*/

void testEmpty() {
    cout << "Initialization testEmpty..." << endl << endl;

    String* s = new String();

    try {
        cout << "Check if created: " <<endl;
        if (s != NULL) {
            successMessage();
            cout << "Created String object" << endl << endl;
        } else {
            failMessage();
            cout << "Something went wrong: object is not created." << endl << endl;
        }
    } catch (const std::exception& e) {
        failMessage();
        cout << "Object is not created. Error message: " << e.what();
    }
}

void testSingleChar() {
    cout << "Initialization testSinglechar..." << endl;

    String str1('A');

    try {
        cout << "Check if one-character String is initialized correctly: " << endl << endl;
        cout << "Testing object: " << str1.getString() << endl << endl;

        if ((*str1.getString()) == 'A') {
            successMessage();
            cout << "Single char string created correctly." << endl;
        } else {
            failMessage();
            cout << "Something went wrong: object is not created." << endl;
        }
    } catch (const std::exception& e) {
        failMessage();
        cout << "Object is not created. Error message: " << e.what();
    }
}

void testCharPointer() {
    cout << "Initialization testCharPointer..." << endl;

    char c1[] = "Test";
    char c2[] = "like no one tested it!";
    char c3[] = "Test like no one tested it!";

    String str1(c1);
    String str2(c2);
    String str3(c3);
    try {
        // Test Strings
        cout << "Compare newly created String with original char-array: " << endl << endl;
        cout << "Testing objects: [ " << str1.getString() << ", " << str2.getString() << ", " << str3.getString() << " ]" << endl << endl;

        if (strcmp(str1.getString(), "Test") == 0) {
            successMessage();
            cout << str1.getString() << " and " << "Test" << " are the same." << endl; 
        } else {
            failMessage();
            cout << "Something went wrong: strings are not the same." << endl;
        }

        // Test space separated Strings
        cout << "Test space separated Strings" << endl;

        if (strcmp(str2.getString(), "like no one tested it!") == 0) {
            successMessage();
            cout << str2.getString() << " and " << "like no one tested it!" << " are the same." << endl; 
        } else {
            failMessage();
            cout << "Something went wrong: strings are not the same." << endl;
        }
    } catch (const std::exception& e) {
        failMessage();
        cout << "Object is not created. Error message: " << e.what();
    }

}

void testCount() {
    cout << "Initialization testCount..." << endl;

    String str1('C');
    char c2[] = "Hello";
    char c3[] = "World";
    String str2(c2);
    String str3(c3);

    try {
        cout << "Check String length (1 Character): " << endl << endl;
        cout << "Testing objects: [ " << str1.getString() << ", " << str2.getString() << ", " << str3.getString() << " ]" << endl << endl;

        if(str1.getSize() == 1) {
            successMessage();
            cout << " Size passed to comparing size." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: size pass not." << endl;
        }

        cout << "    Compare to different strings with same size: " << endl;

        if(str2.getSize() == str3.getSize()) {
            successMessage();
            cout << " Size passed to comparing size." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: size pass not." << endl;
        }
        
    } catch (const std::exception& e) {
        failMessage();
        cout << " Object is not created. Error message: " << e.what();
    }

}

void testStringObject() {
    cout << "Initialization testStringObject..." << endl;

    char c[] = "Hello World";
    String str1(c);
    String str2(str1);

    try {
        cout << "Check if copied String has the same size as the original one: " << endl << endl;
        cout << "Testing objects: [ " << str1.getString() << ", " << str2.getString() << " ]" << endl << endl;

        if (str2.getSize() == str1.getSize()) {
            successMessage();
            cout << " Size passed to comparing size." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: size pass not." << endl;
        }

        cout << "Check if the string was copied corretly: " << endl << endl;
        cout << "Testing objects: [ " << str1.getString() << ", " << str2.getString() << " ]" << endl << endl;

        if (strcmp(str2.getString(), str1.getString()) == 0) {
            successMessage();
            cout << " String was copied correctly." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: copy was not correctly." << endl;
        }

        cout << "Check, if the two Strings are different, by checking their adresses: " << endl << endl;
        cout << "Testing objects: [ " << str1.getString() << ", " << str2.getString() << " ]" << endl << endl;

        if (str2.getString() != str1.getString()) {
            successMessage();
            cout << " String have different addresses." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: addresses are not different or another problem occured." << endl;
        }

    } catch (const std::exception& e) {
        failMessage();
        cout << "Object is not created. Error message: " << e.what();
    }

}

void testArray() {
    cout << "Initialization testArray..." << endl;

    char c[] = "Test";
    String str1(c);

    try {
        cout << "Simply check for the first symbol:  " << endl << endl;
        cout << "Testing object: " << str1.getString() << endl << endl;

        if ((char) str1[0] == (char) 'T') {
            successMessage();
            cout << " First symbol passed." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: symbols are different or do not match." << endl;
        }

        cout << "Check all letters in the testword:  " << endl << endl;
        cout << "Testing object: " << str1.getString() << endl << endl;

        for (int i = 0; i < str1.getSize(); i++) {
            if ((char) str1[i] == (char) c[i]) {
                successMessage();
                cout << " Symbol passed." << endl; 
            } else {
                failMessage();
                cout << " Something went wrong: symbol is different or does not match." << endl;
                break;
            }
        }

        cout << "Test negative input:  " << endl << endl;
        cout << "Testing object: " << str1.getString() << endl << endl;

        if ((char) str1[-1] == (char) '\0') {
            successMessage();
            cout << " Negative input brings end of line." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: negative input does not work." << endl;
        }

        cout << "Test obvious out of bounds: " << endl << endl;
        cout << "Testing object: " << str1.getString() << endl << endl;

        if ((char) str1[20] == (char) '\0') {
            successMessage();
            cout << " Out of bounds correctly handled." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: Out of bounds incorrectly handled." << endl;
        }

        cout << "Test for null-terminator input:  " << endl << endl;
        cout << "Testing object: " << str1.getString() << endl << endl;

        if ((char) str1[5] == (char) '\0') {
            successMessage();
            cout << " Null-terminator detected." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: Null-terminator does not detected." << endl;
        }
    } catch (const std::exception& e) {
        failMessage();
        cout << "Object is not created. Error message: " << e.what();
    }

}

void testAssign() {
    cout << "Initialization testAssign..." << endl;

    char c[] = "Test"; 
    String str1(c);
    String str2;

    try {
        str2 = str1;

        cout << "     Str2: " << str2 << endl;
        cout << "     Str1: " << str1 << endl;

        cout << "Compare string size: " << endl << endl;
        cout << "Testing objects: [ " << str2.getString() << ", " << str1.getString() << " ]" << endl << endl;

        if (str1.getSize() == str2.getSize()) {
            successMessage();
            cout << " Sizes match." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: Sizes do not match." << endl;
        }

        cout << "Compare String contents, letter by letter: " << endl << endl;
        cout << "Testing objects: [ " << str2.getString() << ", " << str1.getString() << " ]" << endl << endl;

        for (int i = 0; i < str1.getSize(); i++) {
            if (str1.getSize() == str2.getSize()) {
                successMessage();
                cout << " Letter matches." << endl; 
            } else {
                failMessage();
                cout << " Something went wrong: Letters does not match." << endl;
                break;
            }
        }

    } catch (const std::exception& e) {
        failMessage();
        cout << "Object is not created. Error message: " << e.what();
    }

}

void testConcat() {
    cout << "Initialization testConcat..." << endl;

    char c1[] = "Hello";
    char c2[] = "World";
    char c3[] = "HelloWorld";
    String str1(c1);
    String str2(c2);

    try {
        cout << "Compare String contents, letter by letter: " << endl << endl;
        cout << "Testing objects: [ " << str1.getString() << ", " << str2.getString() << " ]" << endl << endl;

        bool isCorrect = true;
        int i = 0;

        while (isCorrect) {
            if(i >= str1.getSize()) {
                break;
            }
            if((char)str1[i] != c3[i]) {
                isCorrect = false;
                break;
            }
            i++;
        }

        if (isCorrect) {
            successMessage();
            cout << " Concat matches." << endl; 
        } else {
            failMessage();
            cout << " Something went wrong: concat does not match." << endl;
        }

    } catch (const std::exception& e) {
        failMessage();
        cout << "Object is not created. Error message: " << e.what();
    }

}

void successMessage() {
    cout << "    SUCCESS: ";
}

void failMessage() {
    cout << "    FAILED: ";
}

