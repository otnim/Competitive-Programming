

int n, weight[LIM];
vector<LL> eachSetSum;
bool checkBit(int val, int pos) {return (val & (1<<pos));}

void allComb(){
    for(int i = 1; i <= (1<<n); i++){
        LL sum = 0;
        for(int j = 0; j < n; j++){
            if(checkBit(i, j)) sum += weight[n-j];
        }
        eachSetSum.push_back(sum);
    }
}
