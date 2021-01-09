#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int ans;
struct House {
   int x, y, z; 
}; 
  

int dfs(int src, int start[], int diam[]) {
    if(start[src] == 0)
        return src;
    if(diam[src] < ans) 
        ans = diam[src];
    return (dfs(start[src], start, diam));
}

int main()
 {
	//code
	int t  = 1;
	//cin >> t;
	while(t--) {
	    
	    int n, p;
	    cin >> n >> p;
	    int start[n+1], dest[n+1], diam[n+1];
	    for(int i = 1; i <= n; i++) {
	        start[i] = 0;
	        dest[i] = 0;
	        diam[i] = 10;
	    }
	    for(int i = 0; i < p; i++) {
	        int a, b, d;
	        cin >> a >> b >> d;
	        start[a] = b;
	        diam[a] = d;
	        dest[b] = a;
	    }
	    
	    vector<House> res;
	    
	    for(int j = 1; j <= n; j++) {
	        if(dest[j]== 0 && start[j]) {
	            ans = INT_MAX;
	            int des = dfs(j, start, diam);
	            res.push_back({j, des, ans});
	            
	        }
	    }
	    cout << res.size() << endl;
        for(auto &it : res) {
            cout << it.x << " "  << it.y << " " << it.z << endl;
        }
	}
	return 0;
}