
class Solution{
    
private: 

    bool isSafe(int i, int color[], int node, bool graph[101][101], int n){
        
        for (int k=0;k<n;k++){
            if (k!=node && graph[k][node]==1 && color[k]==i){
                return false;
            }
        }
        return true;
    }
    bool solve(int node, bool graph[101][101], int color[], int m, int n){
        
        if (node==n){
            return true;
        }
        
        for (int i=1;i<=m;i++){
            
            if (isSafe(i,color,node,graph,n)){
                color[node]=i;
                
                if (solve(node+1,graph,color,m,n)==true){
                    return true;
                }
                
                color[node]=0;
            }
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        
        if (solve(0,graph,color,m,n)){
            return true;
        }
        else{
            return false;
        }
    }
};
