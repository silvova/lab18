#include "LRUcache.h"
using namespace std;


LRUcashe::LRUcashe(size_t size1) {
	size = size1;
	count = 0;

}

LRUcashe::~LRUcashe() {
	qmap.clear();
	qlist.clear();
}

void LRUcashe::add_to(const string& address) {
	qlist.push_front(address);
	qmap.insert(pair<string, int>(address, 1));
}

void LRUcashe::change_pos(const string& address) {
	list<string>::iterator it;
	for (it = qlist.begin(); it != qlist.end(); ++it) {
		if (*it == address) {
			qlist.erase(it);
			break;
		}
	}
	qlist.push_front(address);
}

void LRUcashe::delete_check() {
	if (count == size) {
		list<string>::iterator it = qlist.end();
		--it;
		qmap.erase(qmap.find(*it));
		qlist.pop_back();
		count--;
	}
}

bool LRUcashe::find_and_add1(const string& address) {

	auto result = this->qmap.find(address);

	if (result == this->qmap.end()) {
		this->delete_check();
		this->add_to(address);
		count++;
		return false;
	}
	else {
		this->change_pos(address);
	}

	return true;
}

ostream& operator << (ostream& os, LRUcashe& a) {
	for (string str : a.qlist) {
		os << str << '\n';
	}
	return os;
}