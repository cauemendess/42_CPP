#include <iostream>
#include <cassert>
#include <string>
#include "Array.hpp"

void testCreationAndSize()
{
    Array<int> a;
    assert(a.size() == 0);

    Array<int> b(5);
    assert(b.size() == 5);

    std::cout << "testCreationAndSize passed\n";
}

void testElementAccessAndModification()
{
    Array<int> arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    assert(arr[0] == 10);
    assert(arr[1] == 20);
    assert(arr[2] == 30);

    arr[1] = 50;
    assert(arr[1] == 50);

    std::cout << "testElementAccessAndModification passed\n";
}

void testCopyConstructor()
{
    Array<std::string> a(2);
    a[0] = "Hello";
    a[1] = "World";

    Array<std::string> b = a;

    assert(b.size() == 2);
    assert(b[0] == "Hello");
    assert(b[1] == "World");

    a[0] = "Changed";
    assert(b[0] == "Hello");

    std::cout << "testCopyConstructor passed\n";
}

void testAssignmentOperator()
{
    Array<double> a(2);
    a[0] = 1.5;
    a[1] = 2.5;

    Array<double> b;
    b = a;

    assert(b.size() == 2);
    assert(b[0] == 1.5);
    assert(b[1] == 2.5);

    a[0] = 10.5;
    assert(b[0] == 1.5);

    std::cout << "testAssignmentOperator passed\n";
}

void testOutOfRangeAccess()
{
    Array<int> arr(2);
    arr[0] = 1;
    arr[1] = 2;

    bool exceptionThrown = false;
    try {
        int x = arr[2];
        (void)x;
    } catch (const std::out_of_range& e) {
        exceptionThrown = true;
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try {
        arr[100] = 42;
    } catch (const std::out_of_range& e) {
        exceptionThrown = true;
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }
    assert(exceptionThrown);

    std::cout << "testOutOfRangeAccess passed\n";
}

int main()
{
    testCreationAndSize();
    testElementAccessAndModification();
    testCopyConstructor();
    testAssignmentOperator();
    testOutOfRangeAccess();

    std::cout << "All tests passed successfully.\n";
    return 0;
}
