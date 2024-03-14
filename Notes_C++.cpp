	anonymous objects on heap vs anonymous object on stack

in both cases constructor gets called but destrucotr gets calles immediately for stack object as it scope ends after that line.
But in case of heap bases there is no handle /pointer thruw hich we can call their destuctor explicitley
so those objects remains in memory till execution of the program ends.


stack based obj vs heap based obj
destructor called implicitly for stack based while we have to call explicitly for heap based objects by calling delete on that pointer.
	{
	MyClass m1(17);
	MyClass m2(11);
	MyClass *m3 = new MyClass(2611);
	delete m3;}
	
	O/p-- 2611 destructor
	
	11 destrucotr
	17 destrucotr
	
	-------------------------------------
	{
	MyClass m1(17);
	MyClass m2(11);
	MyClass* m3 = new MyClass[3]{ 10,20,30 };
	delete []m3;
	}
	
	o/p:-
	
	30 destrucotr
	20 destrucotr
	10 destrucotr
	11
	17
	
	----------------------------------------
	-----
	In brief, conceptually malloc and new allocate from different heaps, so can’t free or delete each other’s memory. They also operate at different levels – raw memory vs. constructed objects.
	
	New Vs Malloc 
	
	-- new is operator 
	-- malloc is a function which return void* pointer .
	--New calls default constructor implicitly
	--Malloc will not call constructor implicitly
	
	-------
	
	New and free
	free will not call destructor implicitly. it will lead to memory leak or heap corrupt or memory issue if we had assigned memory to the pointer which is memeber variable of our class.
	
	thats why alsway use delete with new and delete[] with new []
	
	--------
	malloc and delete
	mallco will not call constructor
	delete will call destructor implicitley
	
	------
	
	if we need realloc in c++ then to avoid that we can use vector
	vector expands as needed
	
--------------------------------------------------------------------------------------------------------------

Myclass *ptr=new MyClass[4];
diff betweeen delete ptr and delete[]ptr:=
---delete []ptr ensures that destructor will be invoked for all the objects which are allocated on heap.

--------------------------------------------------------------------------------------------------------------





























