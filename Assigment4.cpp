#include<bits/stdc++.h>

using namespace std;


int main() {
    int M,N,T,H,*xcoord,*ycoord,*score,*health,*destroy;
    cin >> M >> N >> T >> H;

    health=(int*)malloc(T * sizeof (int));
    destroy=(int*)malloc(T * sizeof (int));
    xcoord=(int*)malloc(T * sizeof (int));  // X coordinate of each tank
    ycoord=(int*)malloc(T * sizeof (int));  // Y coordinate of each tank
    score=(int*)malloc(T * sizeof (int));  // Score of each tank (ensure that at the end you have copied back the score calculations on the GPU back to this allocation)
    
    // Input tank coordinates
    for (int i = 0; i < T; ++i) {
        cin >> xcoord[i] >> ycoord[i];
    }

    //Initial Values
    for(int i = 0;i < T; i++){
	    health[i] = H;
	    destroy[i] = 0;
        score[i] = 0;
    }
  

    // Simulate the game
    // gameSimulation(M, N, T, H, xcoord, ycoord, score, health, destroy);

    // Output scores
    for (int i = 0; i < T; ++i) {
        cout << score[i] << endl;
    }


    return 0;
}
