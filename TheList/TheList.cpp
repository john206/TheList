// TheList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List342.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*List342<int> list1;
	
	int *val1, *val2, *val3, *val4;
	int v1, v2, v3, v4;

	v1 = 8;
	v2 = 2;
	v3 = 6;
	v4 = 4;

	val1 = &v1;
	val2 = &v2;
	val3 = &v3;
	val4 = &v4;

	cout << "populating list1... " << endl << endl;

	list1.Insert(val1);
	list1.Insert(val2);
	list1.Insert(val3);
	list1.Insert(val4);	

	cout << "list1: " << list1 << endl << endl;

	cout << "attempting duplicates..." << endl << endl;
	
	int *dupVal1, *dupVal2, *dupVal3, *dupVal4;
	int dv1, dv2, dv3, dv4;

	dv1 = 2;
	dv2 = 4;
	dv3 = 6;
	dv4 = 8;
	
	dupVal1 = &dv1;
	dupVal2 = &dv2;
	dupVal3 = &dv3;
	dupVal4 = &dv4;

	list1.Insert(dupVal1);
	list1.Insert(dupVal2);
	list1.Insert(dupVal3);
	list1.Insert(dupVal4);

	cout << "list1: " << list1 << endl << endl;

	cout << "testing Remove..." << endl << endl;
	
	int removeVal;
	list1.Remove(4, removeVal);
	cout << "list1: " << list1 << endl;
	list1.Remove(2, removeVal);
	cout << "list1: " << list1 << endl;
	list1.Remove(8, removeVal);
	cout << "list1: " << list1 << endl;
	list1.Remove(6, removeVal);
	cout << "list1: " << list1 << endl << endl;

	cout << "repopulating list1..." << endl << endl;

	list1.Insert(val1);
	list1.Insert(val2);
	list1.Insert(val3);
	list1.Insert(val4);

	cout << "list1: " << list1 << endl << endl;
	
	List342<int> list2;

	int *val5, *val6, *val7, *val8, *val9;
	int v5, v6, v7, v8, v9;

	v5 = 9;
	v6 = 1;
	v7 = 7;
	v8 = 3;
	v9 = 5;

	val5 = &v5;
	val6 = &v6;
	val7 = &v7;
	val8 = &v8;
	val9 = &v9;

	cout << "populating list2..." << endl << endl;

	list2.Insert(val5);
	list2.Insert(val6);
	list2.Insert(val7);
	list2.Insert(val8);
	list2.Insert(val9);

	cout << "list2: " << list2 << endl << endl;	

	cout << "testing Peek with known inserted value..." << endl << endl;
	
	int peekVal;
	
	if (list2.Peek(1, peekVal))
		cout << "Peek result: " << peekVal << endl << endl;
	else
		cout << "Peek failed" << endl << endl;

	cout << "testing Peek with known uninserted value..." << endl << endl;

	if (!list2.Peek(4, peekVal))
		cout << "correctly rejected bad value" << endl << endl;
	else
		cout << "Peek failed" << endl << endl;

	List342<Child> childList1;
	List342<Bird> birdList1;

	cout << "testing BuildList on Child..." << endl << endl;
	
	childList1.BuildList("Child.txt");

	cout << "childList1: " << childList1 << endl << endl;

	cout << "testing BuildList on Bird..." << endl << endl;

	birdList1.BuildList("Bird.txt");

	cout << "birdList1: " << birdList1 << endl << endl;

	cout << "populating second child and bird lists..." << endl << endl;

	List342<Child> childList2;
	List342<Bird> birdList2;

	childList2.BuildList("Child2.txt");
	birdList2.BuildList("Bird2.txt");

	cout << "childList1: " << childList1 << endl;
	cout << "childList2: " << childList2 << endl << endl;

	cout << "birdList1: " << birdList1 << endl;
	cout << "birdList2: " << birdList2 << endl << endl;

	cout << "testing == and !=..." << endl << endl;

	if (childList1 != childList2)
		cout << "child lists not equal" << endl << endl;
	else
		cout << "comparison failed" << endl << endl;

	if (birdList1 != birdList2)
		cout << "comparison failed" << endl << endl;
	else
		cout << "bird lists are equal" << endl << endl;

	
	
	cout << "testing overloaded assignment operator on childList3 = childList1..." << endl << endl;
	
	List342<Child> childList3;
	childList3 = childList1;

	cout << "childList1: " << childList1 << endl;
	cout << "childList3: " << childList3 << endl << endl;

	cout << "inserting new value into childList3..." << endl << endl;

	Child assignmentTest("Indiana", "Jones", 50);
	Child *aTestPtr = &assignmentTest;

	childList3.Insert(aTestPtr);
	
	cout << "childList3 is now: " << childList3 << endl;
	cout << "childList1 is still: " << childList1 << endl << endl;
	
	cout << "testing overloaded copy constructor on birdList3 and birdList2..." << endl << endl;

	List342<Bird> birdList3 = birdList2;
	cout << "birdList2: " << birdList2 << endl;
	cout << "birdList3: " << birdList3 << endl << endl;

	cout << "inserting new value into birdList3..." << endl << endl;
	
	Bird copyConstructorTest("penguin", 6);
	Bird *cpyConstTest = &copyConstructorTest;

	birdList3.Insert(cpyConstTest);

	cout << "birdList3 is now: " << birdList3 << endl;
	cout << "birdList2 is still: " << birdList2 << endl << endl;
	
	cout << "populating birdList4..." << endl << endl;

	List342<Bird> birdList4;
	birdList4.BuildList("Bird3.txt");

	cout << "birdList1: " << birdList1 << endl;
	cout << "birdList2: " << birdList2 << endl << endl;

	cout << "testing overloaded + operator on birdList1 + birdList4" << endl;
	cout << "notice they contain duplicates..." << endl << endl;

	cout << birdList1 + birdList4 << endl << endl;

	cout << "testing += on birdList1 += birdList4..." << endl << endl;

	birdList1 += birdList4;

	cout << "birdList1 is now: " << birdList1 << endl;
	cout << "birdList4 is still: " << birdList4 << endl << endl;

	cout << "birdList2: " << birdList2 << endl;
	cout << "birdList4: " << birdList4 << endl << endl;

	cout << "testing birdList2 Merge birdList4..." << endl << endl;
	
	birdList2.Merge(birdList4);

	cout << "birdList2 is now: " << birdList2 << endl;
	cout << "birdList4 is now: " << birdList4 << endl << endl;

	Bird b1("eagle", 1);
	Bird b2("turkey", 2);
	Bird b3("eagle", 1);
	Bird b4("duck", 2);

	Bird *b1Ptr = &b1;
	Bird *b2Ptr = &b2;
	Bird *b3Ptr = &b3;
	Bird *b4Ptr = &b4;

	List342<Bird> b1List;
	b1List.Insert(b1Ptr);
	b1List.Insert(b2Ptr);

	List342<Bird> b3List;
	b3List.Insert(b3Ptr);
	b3List.Insert(b4Ptr);

	cout << "b1List: " << b1List << endl;
	cout << "b3List: " << b3List << endl << endl;

	cout << "testing b1List + b3List... " << endl;
	cout << b1List + b3List << endl << endl;

	cout << "b1List: " << b1List << endl;
	cout << "b3List: " << b3List << endl << endl;

	cout << "testing b1List Merge b3List..." << endl;
	b1List.Merge(b3List);

	cout << "b1List: " << b1List << endl;
	cout << "b3List: " << b3List << endl << endl;
	
	return 0;*/



	List342<Child> list1;
	Child c1("john", "walter", 35);
	Child c2("brody", "schulke", 18);
	Child result;

	list1.Insert(&c1);
	list1.Insert(&c2);

	cout << list1 << endl;
	cout << "c1" << c1 << endl;
	if (list1.Peek(c1, result))
	{
		cout << "true" << endl;
	}

	else
	{
		cout << "false" << endl;
	}
	return 0;



	
}

