#include "table.h"

int main(int argc, char* argv[]){
	HashTable theTable;
	ifstream ifs(argv[1], ifstream::in);
	string temp;
	string line;
	try{
		while(getline(ifs, line)){
			stringstream ss(line);
			string id;
			string name;
			getline(ss, id, '|');
			getline(ss, name, '|');
			getline(ss, temp, '\n');
			TableItemType newItem(id, name);
			theTable.tableInsert(newItem);
		}
	}catch(TableException e){
		cout << e.getMessage() << endl;
	}
	theTable.check();

	ifstream ifb(argv[1], ifstream::in);
	try{
		while(getline(ifb, line)){
			stringstream ss(line);
			string id;
			getline(ss, id, '|');
			getline(ss, temp, '\n');
			theTable.tableDelete(id);
		}
	}catch(TableException e){
		cout << e.getMessage() << endl;
	}
	theTable.check();
	return 0;
}