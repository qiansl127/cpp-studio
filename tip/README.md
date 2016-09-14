cpp-studio >> tip
=================

### How to create a vector from array?

​    int iArray[] = { 0, 4, 3, 0 };

​    vector<int> ivec(iArray, iArray + sizeof(iArray)/sizeof(int));
