#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
// Disjoint Set data structure 
// Union by Size
class UnionBySize{
    vector<int>parent,sz;
    public:
    UnionBySize(int size){
        parent.resize(size+1);
        sz.resize(size+1,1);
        for(int i=0 ; i<= size;i++){
            parent[i]=i;
        }
    }
    // For ultimate parent (Representative )
    int findUltimateParent(int u){
        if(parent[u]==u){
            return u;
        }
        else{
            return parent[u]=findUltimateParent(parent[u]);
        }
    }
    // Join two sets 
    void Union(int u , int v){
        int pu=findUltimateParent(u);
        int pv=findUltimateParent(v);
        if(pu==pv){
            return;
        }
        if(sz[pu]>sz[pv]){
            parent[pv]=pu;
            sz[pu]+=sz[pv];
        }
        else{
            parent[pu]=pv;
            sz[pv]+=sz[pu];  
        }
    }
};

// Minimum spanning Tree Kruskal Algorithm 
pair<int ,int> spanningTree(int V , vector<tuple<string, int, int, string, string>> Project){
    int number_of_projects=0;
    int mst=0;
    UnionBySize ds(V);
    sort(Project.begin(), Project.end(), [](const tuple<string,int, int, string,string> &a, const tuple<string,int, int, string,string> &b) {
        int priorityA = std::get<1>(a);  // priority
        int priorityB = std::get<1>(b);

        if (priorityA != priorityB) {
            return priorityA > priorityB;  // Sort by priority (descending)
        }

        int costA = std::get<2>(a);  // cost
        int costB = std::get<2>(b);

        return costA < costB;  // Sort by cost (ascending)
    });
    for (const auto &person : Project) {
        int node1= (get<3>(person)[1])-'0';
        int node2= (get<4>(person)[1])-'0';
        if(ds.findUltimateParent(node1)==ds.findUltimateParent(node2)){
            continue;
        }
        else{
            ds.Union(node1,node2);
            int a = get<2>(person);
            mst += a;
            number_of_projects++;// numbers of edges in MST 
        }
    }
    return {mst,number_of_projects};
}


void Search(unordered_map<string , int >mpp,string str){
    if(mpp.find(str)!=mpp.end()){
        cout << str<<" found"<<endl;
    }
    else{
        cout << str<<" not found"<<endl;
    }
}


int main() {
    // Define a vector of tuples
    vector<tuple<string, int, int, string, string>> Project;

    int n;
    cout << "Enter the number of tuples: ";
    cin >> n;

    cout << "Enter the tuples (string, int, int, string, string):\n";
    for (int i = 0; i < n; ++i) {
        string Road, city1, city2;
        int priority, cost;

        cin >> Road >> priority >> cost >> city1 >> city2;

        Project.emplace_back(Road, priority, cost, city1, city2);
    }

    sort(Project.begin(), Project.end(), [](const tuple<string,int, int, string,string> &a, const tuple<string,int, int, string,string> &b) {
        int priorityA = std::get<1>(a);  // Extract priority
        int priorityB = std::get<1>(b);

        if (priorityA != priorityB) {
            return priorityA > priorityB;  // Sort by priority (descending)
        }

        int costA = std::get<2>(a);  // Extract cost
        int costB = std::get<2>(b);

        return costA > costB;  // Sort by cost (ascending)
    });
    unordered_map<string, int>mpp;
    int i=0;
    for (const auto &person : Project) {
        mpp[get<0>(person)]=i++; 
    }


    string k;
    cout << "Enter the road Your are Searching: ";
    cin>>k;
    cout << "\nSearching ...."<<endl;
    Search(mpp, k);
    cout << "Seraching end ..."<<endl<<endl;;


    cout<<"Minimum number of roads : " <<spanningTree(n,Project).second<<endl;
    // sorted tuples


    cout << "\nSorted tuples:\n";
    for (const auto &person : Project) {
        cout << get<0>(person) << " "<< get<1>(person) << " "<< get<2>(person) << " "
             << get<3>(person) << " "<< get<4>(person) << "\n";
    }

    return 0;
}
