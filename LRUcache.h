#ifndef _LRUcache_h_
#define _LRUcache_h_

#include<iostream>
#include<map>
#include<list>
#include<string>

using namespace std;

class LRUcashe {
private:
	size_t size;
	size_t count;
	list <string> qlist;
	map <string, int> qmap;
public:
	LRUcashe(size_t size1);
	~LRUcashe();
	void delete_check();
	void add_to(const string& address);
	void change_pos(const string& address);
	bool find_and_add1(const string& address);
	friend ostream& operator << (ostream& os, LRUcashe& a);
};

#endif
