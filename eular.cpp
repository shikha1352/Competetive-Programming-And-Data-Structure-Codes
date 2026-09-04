#include<bits/stdc++.h>
using namespace std;

int main(){
    int graph[5][5]={{0, 1, 0, 0, 1},
                    {1, 0, 1, 1, 1},
                    {0, 1, 0, 1, 0},
                    {0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0}};

    vector<int> oddAdj;
    for(int i=0; i<5; i++){
        oddAdj.push_back(accumulate(graph[i], graph[i]+5, 0));
    }

    int start = 0;
    int oddcount = 0;
    for(int i=0; i<5; i++){
        if(oddAdj[i] % 2 == 1){
            oddcount++;
            start = i;
        }
    }

    if(oddcount > 2){
        cout << "Invalid Graph" << endl;
        return 0;
    }
    else{
        stack<int> st;
        vector<int> path;
        int current = start;

        while(!st.empty() || accumulate(graph[current], graph[current]+5, 0) != 0){
            if(accumulate(graph[current], graph[current]+5, 0) == 0){
                path.push_back(current);
                current = st.top();
                st.pop();
            }
            else{
                for(int i=0; i<5; i++){
                    if(graph[current][i] == 1){
                        st.push(current);
                        graph[current][i] = 0;
                        graph[i][current] = 0;
                        current = i;
                        break;
                    }
                }
            }
        }

        for(int i=0; i<path.size(); i++){
            cout << path[i] << " ";
        }
    }

    return 0;
}
