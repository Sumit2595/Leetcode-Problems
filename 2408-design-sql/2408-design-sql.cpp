class SQL {
public:
    unordered_map<string,vector<vector<string>>>database;
    unordered_map<string,int>tableColumns;
    SQL(vector<string>& names, vector<int>& columns) {
        int n=names.size();
        for(int i=0;i<n;i++)
            tableColumns[names[i]]=columns[i];
    }
    
    void insertRow(string name, vector<string> row) {
        database[name].push_back(row);
    }
    
    void deleteRow(string name, int rowId) {
        database[name][rowId-1].erase(database[name][rowId-1].begin());
    }
    
    string selectCell(string name, int rowId, int columnId) {
        return database[name][rowId-1][columnId-1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */